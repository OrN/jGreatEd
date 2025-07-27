/*
	A FDA Super Mario Bros 2 [J] [public version]
	Copyright (C) 2020 ALXR aka loginsin
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "NES/FDSFile/CFDSFile.h"

CFDSDiskSide::CFDSDiskSide()
	: m_uSelected( -1 )
{
}

VOID CFDSDiskSide::SkipNESBank(CFDSStream& stream, USHORT size)
{
	LARGE_INTEGER ptr = stream.CurrentPointer();
	ptr.QuadPart += size;
	stream.Seek(ptr, SEEK_SET);
}

VOID CFDSDiskSide::LoadNESBank(CFDSStream& stream, FDS_FILE_TYPE type, BYTE ID, USHORT ptr, USHORT size)
{
	CFDSDiskFile bankFile;
	FDS_FILE_HEADER_BLOCK bankHeader;
	bankHeader.uFileId = ID;
	bankHeader.uFileNumber = ID;
	bankHeader.fft = type;
	bankHeader.uFileSize = size;
	bankHeader.uTargetPtr = ptr;
	bankFile.LoadNESFile(stream, bankHeader, size);
	m_vFile.push_back(bankFile);
}

VOID CFDSDiskSide::LoadNESFiles(CFDSStream& stream)
{
	m_nesHeader = stream.Read<NES_HEADER>();

	DWORD mapper = (m_nesHeader.FLAGS_7.HI_MAPPER << 4) | m_nesHeader.FLAGS_6.LO_MAPPER;

	// Check mapper supported
	if (mapper != 3) // Check if MMC3
		throw std::exception("Only MMC3 version of the NES rom is supported");

	// Check if NES 2.0
	if (m_nesHeader.FLAGS_7.NES2 == 2)
		throw std::exception("incompatible NES rom is using NES 2.0 format");

	LARGE_INTEGER p15;
	LARGE_INTEGER p16;
	LARGE_INTEGER p32;
	LARGE_INTEGER p48;
	LARGE_INTEGER p64;

	// Map PRG-ROM
	LoadNESBank(stream, PRG, 6, 0x6000, 0x2000); // 6000 (0)
	LoadNESBank(stream, PRG, 8, 0xA000, 0x2000); // 6000 (2)

	p15 = stream.CurrentPointer(); p15.QuadPart += 0x129F; // CORRECT
	LoadNESBank(stream, PRG, 5, 0xC000, 0x2000); // bank0

	p32 = stream.CurrentPointer(); p32.QuadPart += 0x470; // CORRECT
	SkipNESBank(stream, 0x2000); // bank1

	p48 = stream.CurrentPointer(); p48.QuadPart += 0x5D0; // CORRECT
	SkipNESBank(stream, 0x2000); // bank2

	p64 = stream.CurrentPointer(); p64.QuadPart += 0x2B4; // CORRECT
	SkipNESBank(stream, 0x2000); // bank3

	LoadNESBank(stream, PRG, 7, 0x8000, 0x2000); // 6000 (1)
	LoadNESBank(stream, PRG, 9, 0xE000, 0x2000); // e000

	// Map CHR-ROM
	LoadNESBank(stream, CHR, 1, 0x0000, 0x2000); // Bank 0

	p16 = stream.CurrentPointer(); p16.QuadPart += 0x760;
	SkipNESBank(stream, 0x2000); // Bank 1

	// ROM Data
	stream.Seek(p15, SEEK_SET); LoadNESBank(stream, PRG, 15, 0xD29F, 0x1);
	stream.Seek(p16, SEEK_SET); LoadNESBank(stream, CHR, 16, 0x760, 0x40);
	stream.Seek(p32, SEEK_SET); LoadNESBank(stream, PRG, 32, 0xC470, 0xE2F);
	stream.Seek(p48, SEEK_SET); LoadNESBank(stream, PRG, 48, 0xC5D0, 0xCCF);
	stream.Seek(p64, SEEK_SET); LoadNESBank(stream, PRG, 64, 0xC2B4, 0xF4C);

	FDS_DISK_INFO_BLOCK diskInfo;
	diskInfo.uBootCode = 15;
	m_fdsInfo = diskInfo;
}

VOID CFDSDiskSide::LoadFiles( CFDSStream & stream )
{
	if ( DiskInfoBlock != stream.Read<FDS_BLOCK_TYPE>() )
	{
		throw std::exception( "Not a valid disk header" );
	}

	m_fdsInfo = stream.Read<FDS_DISK_INFO_BLOCK>();
	if ( memcmp( m_fdsInfo.strDiskVerification, FDS_DISK_SIGNATURE, sizeof( m_fdsInfo.strDiskVerification ) ) )
	{
		throw std::exception( "Not a valid disk signature" );
	}

	if ( FileAmountBlock != stream.Read<FDS_BLOCK_TYPE>() )
	{
		throw std::exception( "Not a valid file amount block" );
	}

	FDS_FILE_AMOUNT_BLOCK fdsAmount = stream.Read<FDS_FILE_AMOUNT_BLOCK>();

	if ( !fdsAmount.uFileAmount )
	{
		throw std::exception( "Can't load empty disk" );
	}

	// load files
	for ( size_t u = 0; u < fdsAmount.uFileAmount; ++u )
	{
		CFDSDiskFile file;
		file.LoadFile( stream );
		m_vFile.push_back( file );
	}
}

VOID CFDSDiskSide::DumpNESFiles(CFDSStream& stream)
{
	// Write Header
	stream.Write(m_nesHeader);

	// PRG
	DumpNESFile(stream, 6, 0, 0x0000);
	DumpNESFile(stream, 8, 0, 0x0000);
	DumpNESFile(stream, 5, 0, 0x0000);
	DumpNESFile(stream, 32, 5, 0x470);
	DumpNESFile(stream, 48, 5, 0x5D0);
	DumpNESFile(stream, 64, 5, 0x2B4);
	DumpNESFile(stream, 7, 0, 0x0000);
	DumpNESFile(stream, 9, 0, 0x0000);

	// CHR
	DumpNESFile(stream, 1, 0, 0x0000);
	DumpNESFile(stream, 16, 1, 0x760);
}

VOID CFDSDiskSide::DumpNESFile(CFDSStream& stream, BYTE id, BYTE parentID, size_t offset)
{
	BYTE fileData[0x2000];

	// Clear data
	for (size_t i = 0; i < 0x2000; i++)
		fileData[i] = 0x00;

	// Write parent
	for (auto& file : m_vFile)
	{
		if (file.GetFileId() != parentID)
			continue;

		for (size_t i = 0; i < file.GetFileData().uFileSize; i++)
			fileData[i] = file[i];
	}

	// Write file data
	for (auto& file : m_vFile)
	{
		if (file.GetFileId() != id)
			continue;

		for (size_t i = 0; i < file.GetFileData().uFileSize; i++)
			fileData[offset + i] = file[i];
	}

	// Write final data to file
	stream.Write(fileData, 0x2000);
}

VOID CFDSDiskSide::DumpFiles( CFDSStream & stream )
{
	stream.Write( DiskInfoBlock );
	stream.Write( m_fdsInfo );
	stream.Write( FileAmountBlock );
	stream.Write( LOBYTE( m_vFile.size() ) );

	for ( auto & file : m_vFile )
	{
		file.DumpFile( stream );
	}
}

FDS_DISK_SIDE CFDSDiskSide::Side()
{
	return static_cast<FDS_DISK_SIDE>( m_fdsInfo.uSideNumber );
}

CFDSDiskFile & CFDSDiskSide::SelectFile( BYTE uId )
{
	size_t uSelected = 0;
	for ( auto & fl : m_vFile )
	{
		if ( fl.GetFileId() == uId )
		{
			m_uSelected = uSelected;
			return fl;
		}

		uSelected++;
	}

	throw std::exception( "Can't find file specified" );
}

CFDSDiskFile & CFDSDiskSide::File()
{
	if ( m_uSelected < m_vFile.size() )
	{
		return m_vFile[ m_uSelected ];
	}

	throw std::exception( "No file selected" );
}

VOID CFDSDiskSide::EnumFiles( std::vector<FDS_FILE_HEADER_BLOCK>& vFiles )
{
	vFiles.clear();
	for ( auto file : m_vFile )
	{
		vFiles.push_back( file.GetFileData() );
	}
}

FDS_DISK_INFO_BLOCK CFDSDiskSide::GetSideInfo()
{
	return m_fdsInfo;
}