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

#include "h\NES\NESEditor\NESEditor.h"

static const wchar_t DECODE_STR_ALPHANUMERIC[] =
{
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z', ' ',
};

CNesGameEngineHack::CNesGameEngineHack( CNESFile & file, CNesPointers & eptr )
	: m_file( file ), m_eptr( eptr )
{

}

VOID CNesGameEngineHack::DecodeString(NES_EPOINTERS ptr)
{
	DecodeString(ptr, 0);
}

VOID CNesGameEngineHack::DecodeString(NES_EPOINTERS ptr, size_t length)
{
	USHORT uPatchPtr = m_eptr[ptr].ptr;

	if (length == 0)
		length = m_file.Data<BYTE>(uPatchPtr++);

	CString str;

	for (size_t i = 0; i < length; i++)
	{
		BYTE data = m_file.Data<BYTE>(uPatchPtr + i);
		wchar_t character = ' ';

		if (data < 0x25) // Alphanumeric
			character = DECODE_STR_ALPHANUMERIC[data];
		else if (data == 0x28) // -
			character = '-';
		else if (data == 0x2B) // !
			character = '!';
		else if (data == 0x76) // “
			character = L'“';
		else if (data == 0x75) // ”
			character = L'”';
		else if (data == 0xAF) // .
			character = '.';
		else if (data == 0xCF) // Copyright
			character = L'\u00A9';
		else if (data == 0xF2) // '
			character = '\'';
		else
			printf("Unknown character: 0x%02x found in NES string!\n", data);

		str.AppendChar(character);
	}

	m_data.strings[ptr] = str.Trim();
	m_data.stringLengths[ptr] = length;
}

VOID CNesGameEngineHack::EncodeString(NES_EPOINTERS ptr)
{
	EncodeString(ptr, 0);
}

VOID CNesGameEngineHack::EncodeString(NES_EPOINTERS ptr, size_t length)
{
	USHORT uPatchPtr = m_eptr[ptr].ptr;

	if (length == 0)
		length = m_file.Data<BYTE>(uPatchPtr++);

	CString str = m_data.strings[ptr];
	size_t quoteCount = 0;

	for (size_t i = 0; i < length; i++)
	{
		BYTE data = 0x24; // Space
		wchar_t character = ' ';

		if (i < str.GetLength())
			character = str.GetAt(i);

		if (character == 0x21) // !
		{
			data = 0x2B;
		}
		else if (character == 0x22) // "
		{
			if ((quoteCount++ % 2) == 0)
				data = 0x76;
			else
				data = 0x75;
		}
		else if (character == 0x27) // '
		{
			data = 0xF2;
		}
		else if (character == 0x2D) // -
		{
			data = 0x28;
		}
		else if (character == 0x2E) // .
		{
			data = 0xAF;
		}
		else if (character >= 0x30 && character <= 0x39) // Number
		{
			data = character - 0x30;
		}
		else if (character >= 0x41 && character <= 0x5A) // Letter
		{
			data = (character - 0x41) + 0x0A;
		}
		else if (character == 0x20) // Space
		{
			data = 0x24;
		}
		else if (character == L'\u201C') // “
		{
			data = 0x76;
			quoteCount = 1;
		}
		else if (character == L'\u201D') // ”
		{
			data = 0x75;
			quoteCount = 0;
		}
		else if (character == L'\u00A9') // Copyright
		{
			data = 0xCF;
		}
		else
		{
			printf("Unknown character: 0x%02x encoding NES string!\n", character);
		}

		printf("Encoded: %lc, 0x%02x\n", character, data);

		m_file.Data<BYTE>(uPatchPtr + i) = data;
	}
}

VOID CNesGameEngineHack::LoadStrings()
{
	m_file.BeginSnapshot();

	m_file.SelectFile(5);
	DecodeString(eStrTitleCopyright);
	DecodeString(eStrTitleMarioGame);
	DecodeString(eStrTitleLuigiGame);
	DecodeString(eStrTitleTop);
	DecodeString(eStrTitleTopEnding);

	DecodeString(eStrUIMario, 5);
	DecodeString(eStrUILuigi, 5);
	DecodeString(eStrUIWorld, 5);
	DecodeString(eStrUITime, 4);

	DecodeString(eStrLevelWorld, 5);

	DecodeString(eStrGameOver);
	DecodeString(eStrGameOverContinue);
	DecodeString(eStrGameOverRetry);

	DecodeString(eStrToadThankYouMessage);
	DecodeString(eStrToadOurPrincessMessage);
	DecodeString(eStrToadAnotherCastleMessage);

	m_file.SelectFile(48);
	DecodeString(eStrLevelFantasyWorld);
	DecodeString(eStrLevelLetsTry);
	DecodeString(eStrLevelOneGame);

	DecodeString(eStrPeachPeaceMessage);
	DecodeString(eStrPeachKingdomMessage);
	DecodeString(eStrPeachHurrahMessage);
	DecodeString(eStrPeachOnlyHeroMessage);
	DecodeString(eStrPeachTripMessage);
	DecodeString(eStrPeachFriendshipMessage);
	DecodeString(eStrPeach100000PtsMessage);
	DecodeString(eStrPeachEachPlayerMessage);
	DecodeString(eStrPeachThankYouMessage);

	DecodeString(eStrEndSuperPlayer);
	DecodeString(eStrEndWeHope);
	DecodeString(eStrEndSeeYou);
	DecodeString(eStrEndMarioStaff);

	DecodeString(eStrDialogueMarioMessage, 5);
	DecodeString(eStrDialogueLuigiMessage, 5);

	m_file.EndSnapshot();
}

VOID CNesGameEngineHack::DumpStrings()
{
	m_file.BeginSnapshot();

	m_file.SelectFile(5);
	EncodeString(eStrTitleCopyright);
	EncodeString(eStrTitleMarioGame);
	EncodeString(eStrTitleLuigiGame);
	EncodeString(eStrTitleTop);
	EncodeString(eStrTitleTopEnding);

	EncodeString(eStrUIMario, 5);
	EncodeString(eStrUILuigi, 5);
	EncodeString(eStrUIWorld, 5);
	EncodeString(eStrUITime, 4);

	EncodeString(eStrLevelWorld, 5);

	EncodeString(eStrGameOver);
	EncodeString(eStrGameOverContinue);
	EncodeString(eStrGameOverRetry);

	EncodeString(eStrToadThankYouMessage);
	EncodeString(eStrToadOurPrincessMessage);
	EncodeString(eStrToadAnotherCastleMessage);
	m_file.StoreSnapshot();

	m_file.SelectFile(48);
	EncodeString(eStrLevelFantasyWorld);
	EncodeString(eStrLevelLetsTry);
	EncodeString(eStrLevelOneGame);

	EncodeString(eStrPeachPeaceMessage);
	EncodeString(eStrPeachKingdomMessage);
	EncodeString(eStrPeachHurrahMessage);
	EncodeString(eStrPeachOnlyHeroMessage);
	EncodeString(eStrPeachTripMessage);
	EncodeString(eStrPeachFriendshipMessage);
	EncodeString(eStrPeach100000PtsMessage);
	EncodeString(eStrPeachEachPlayerMessage);
	EncodeString(eStrPeachThankYouMessage);

	EncodeString(eStrEndSuperPlayer);
	EncodeString(eStrEndWeHope);
	EncodeString(eStrEndSeeYou);
	EncodeString(eStrEndMarioStaff);

	EncodeString(eStrDialogueMarioMessage, 5);
	EncodeString(eStrDialogueLuigiMessage, 5);
	m_file.StoreSnapshot();

	m_file.EndSnapshot();
}

VOID CNesGameEngineHack::LoadData()
{
	m_data.coins = m_file.Data<NES_COINS_1UP_WORLD>( m_eptr[ eCoinsFor1Up ].ptr );
	m_data.warp = m_file.Data<NES_WARP_WORLD>( m_eptr.Pointer( eWarpWorlds ) );
	m_data.rotateCols = m_file.Data<NES_COIN_PAL_ROTATE_COLOR>( m_eptr.Pointer( ePalRotateColors ) );

	m_eptr.Select( eHardModeWorld );
	m_data.hardMode.bWorld = m_file.Data<BYTE>( m_eptr[ eHardModeWorld ].ptr );
	m_data.hardMode.bLevel = m_file.Data<BYTE>( m_eptr[ eHardModeLevel ].ptr );

	m_eptr.Select( eBowserHammersWorld );
	m_data.bowserHammers = m_file.Data< NES_BOWSER_HAMMERS_WORLD>( m_eptr[ eBowserHammersWorld ].ptr );

	m_data.defaultEggBehavior = !IsSpinyEggPatched();
	m_data.infiniteLives = IsInfiniteLivesPatched();

	LoadStrings();
}

VOID CNesGameEngineHack::DumpData()
{
	m_file.Data<NES_COINS_1UP_WORLD>( m_eptr[ eCoinsFor1Up ].ptr ) = m_data.coins;
	m_file.Data<NES_WARP_WORLD>( m_eptr.Pointer( eWarpWorlds ) ) = m_data.warp;
	m_file.Data<NES_COIN_PAL_ROTATE_COLOR>( m_eptr.Pointer( ePalRotateColors ) ) = m_data.rotateCols;

	m_eptr.Select( eHardModeWorld );
	m_file.Data<BYTE>( m_eptr[ eHardModeWorld ].ptr ) = m_data.hardMode.bWorld;
	m_file.Data<BYTE>( m_eptr[ eHardModeLevel ].ptr ) = m_data.hardMode.bLevel;

	m_eptr.Select( eBowserHammersWorld );
	m_file.Data< NES_BOWSER_HAMMERS_WORLD>( m_eptr[ eBowserHammersWorld ].ptr ) = m_data.bowserHammers;
	SetSpinyEggPatch( !m_data.defaultEggBehavior );
	SetInfiniteLivesPatch( m_data.infiniteLives );

	DumpStrings();
}

BOOL CNesGameEngineHack::IsSpinyEggPatched()
{
	return !(
		0x20 == m_file.Data<BYTE>( m_eptr[ eSpinyEggPatchPlace ].ptr ) &&		// JSR SmallBBox on its own place at original
		m_eptr[ eSmallBBox ].ptr == m_file.Data<USHORT>( m_eptr[ eSpinyEggPatchPlace ].ptr + 1 )
		);
}

BOOL CNesGameEngineHack::IsInfiniteLivesPatched()
{
	return ( 0xEA == m_file.Data<BYTE>(m_eptr[eInfiniteLivesPatchPlace].ptr) );
}

VOID CNesGameEngineHack::SetInfiniteLivesPatch(BOOL fPatch)
{
	USHORT uPatchPtr = m_eptr[eInfiniteLivesPatchPlace].ptr;

	if (fPatch)
	{
		m_file.Data<BYTE>(uPatchPtr++) = 0xEA; // NOP
		m_file.Data<BYTE>(uPatchPtr++) = 0xEA; // NOP
		m_file.Data<BYTE>(uPatchPtr++) = 0x4C; // JMP
		m_file.Data<USHORT>(uPatchPtr) = 0x702B;
	}
	else
	{
		m_file.Data<BYTE>(uPatchPtr++) = 0xCE; // dec $75a
		m_file.Data<USHORT>(uPatchPtr) = 0x075A;
		uPatchPtr += 2;
		m_file.Data<BYTE>(uPatchPtr++) = 0x10; // BPL
		m_file.Data<BYTE>(uPatchPtr) = 0x0B;
	}
}

VOID CNesGameEngineHack::SetSpinyEggPatch( BOOL fPatch )
{
	USHORT uPatchPtr = m_eptr[ eSpinyEggPatchPlace ].ptr;

	if ( fPatch )
	{
		m_file.Data<USHORT>( uPatchPtr ) = 0x02A0;							// LDY #02
		uPatchPtr += 2;
		m_file.Data<USHORT>( uPatchPtr ) = 0x5895;							// STA     vExplosionGfxCounter,X
		uPatchPtr += 2;
		m_file.Data<USHORT>( uPatchPtr ) = 0x00C9;							// CMP     #00
		uPatchPtr += 2;
		m_file.Data<USHORT>( uPatchPtr ) = 0x0130;							// BMI     lbSpinyRte
		uPatchPtr += 2;
		m_file.Data<BYTE>( uPatchPtr++ ) = 0x88;							// DEY
		m_file.Data<BYTE>( uPatchPtr++ ) = 0x20;							// JSR ...
		m_file.Data<USHORT>( uPatchPtr ) = m_eptr[ eSmallBBox ].ptr;		// ... SmallBBox
	}
	else
	{
		m_file.Data<BYTE>( uPatchPtr++ ) = 0x20;							// JSR ...
		m_file.Data<USHORT>( uPatchPtr ) = m_eptr[ eSmallBBox ].ptr;		// ... SmallBBox
		uPatchPtr += 2;
		m_file.Data<USHORT>( uPatchPtr ) = 0x02A0;							// LDY #02
		uPatchPtr += 2;
		m_file.Data<USHORT>( uPatchPtr ) = 0x5895;							// STA     vExplosionGfxCounter,X
		uPatchPtr += 2;
		m_file.Data<USHORT>( uPatchPtr ) = 0x00C9;							// CMP     #00
		uPatchPtr += 2;
		m_file.Data<USHORT>( uPatchPtr ) = 0x0130;							// BMI     lbSpinyRte
		uPatchPtr += 2;
		m_file.Data<BYTE>( uPatchPtr++ ) = 0x88;							// DEY
	}
}

const NES_ENGINE_HACK & CNesGameEngineHack::Read() const
{
	return m_data;
}

VOID CNesGameEngineHack::Write( const NES_ENGINE_HACK & hack )
{
	m_data = hack;
}