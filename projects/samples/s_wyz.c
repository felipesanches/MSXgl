// __________________________
// ██▀█▀██▀▀▀█▀▀█▀█  ▄▄▄ ▄▄  │   ▄▄▄                ▄▄      
// █  ▄ █▄ ▀██▄ ▀▄█ ██   ██  │  ▀█▄  ▄▀██ ▄█▄█ ██▀▄ ██  ▄███
// █  █ █▀▀ ▄█  █ █ ▀█▄█ ██▄▄│  ▄▄█▀ ▀▄██ ██ █ ██▀  ▀█▄ ▀█▄▄
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀──────────┘                 ▀▀
//  VGM format sample
//─────────────────────────────────────────────────────────────────────────────
#include "msxgl.h"
#include "psg.h"
#include "wyz\wyz_player.h"

//=============================================================================
// DEFINES
//=============================================================================

extern u16 WYZ_songs;
extern u16 WYZ_instruments;
extern u16 WYZ_FXs;
extern u16 WYZ_notes;

extern u16 RA_PSG_Song;
extern u16 RA_PSG_Inst;
extern u16 RA_PSG_FX;
extern u16 RA_PSG_Freq;

extern u16 jinj_med_Song;
extern u16 jinj_med_Inst;
extern u16 jinj_med_FX;
extern u16 jinj_med_Freq;

// Library's logo
#define MSX_GL "\x02\x03\x04\x05"

// VGM music entry
struct MusicEntry
{
	const c8* Name;
	u16       Song;
	u16       Inst;
	u16       FX;
	u16       Freq;
};

// Player button entry
struct ButtonEntry
{
	u8        Char;
	callback  Func;
};

// Button callbacks
void ButtonPlay();
void ButtonPause();
void ButtonStop();
void ButtonPrev();
void ButtonNext();
void ButtonLoop();

//=============================================================================
// READ-ONLY DATA
//=============================================================================

// Fonts
#include "font\font_mgl_sample8.h"

// Animation characters
const u8 g_ChrAnim[] = { '|', '\\', '-', '/' };

// Music list
const struct MusicEntry g_MusicEntry[] =
{
	{ "Jinj Med ", (u16)&jinj_med_Song, (u16)&jinj_med_Inst, (u16)&jinj_med_FX, (u16)&jinj_med_Freq },
	{ "RA_PSG   ", (u16)&RA_PSG_Song, (u16)&RA_PSG_Inst, (u16)&RA_PSG_FX, (u16)&RA_PSG_Freq },
	{ "Nayade   ", (u16)&WYZ_songs, (u16)&WYZ_instruments, (u16)&WYZ_FXs, (u16)&WYZ_notes },
};

// Player button list
const struct ButtonEntry g_ButtonEntry[] =
{
	{ 0x80, ButtonPlay },
	{ 0xB8, ButtonPause },
	{ 0xB9, ButtonStop },
	{ 0xBB, ButtonPrev },
	{ 0xBA, ButtonNext },
	{ 0xBE, ButtonLoop },
};

// Color shade
const u8 g_ColorBlink[4] = { COLOR_LIGHT_RED, COLOR_MEDIUM_RED, COLOR_DARK_RED, COLOR_MEDIUM_RED };

//=============================================================================
// MEMORY DATA
//=============================================================================

u8   g_CurrentMusic = 0;
u8   g_CurrentButton;
bool g_Freq60Hz = true;


//=============================================================================
// HELPER FUNCTIONS
//=============================================================================

//-----------------------------------------------------------------------------
//
void SetMusic(u8 idx)
{
	g_CurrentMusic = idx;
	const struct MusicEntry* entry = &g_MusicEntry[idx];

	WYZ_Initialize(entry->Song, entry->Inst, entry->FX, entry->Freq);
	WYZ_PlaySong(0, true); 
	
	Print_SetPosition(0, 2);
	Print_DrawFormat("%i/%i %s", 1 + idx, numberof(g_MusicEntry), entry->Name);
}

//-----------------------------------------------------------------------------
//
void ButtonPlay()
{
	// ayVGM_Resume();
}

//-----------------------------------------------------------------------------
//
void ButtonPause()
{
	// ayVGM_Pause();
}

//-----------------------------------------------------------------------------
//
void ButtonStop()
{
	// ayVGM_Stop();	
}

//-----------------------------------------------------------------------------
//
void ButtonPrev()
{
	if(g_CurrentMusic > 0)
		SetMusic(g_CurrentMusic - 1);
}

//-----------------------------------------------------------------------------
//
void ButtonNext()
{
	if(g_CurrentMusic < numberof(g_MusicEntry) - 1)
		SetMusic(g_CurrentMusic + 1);
}

//-----------------------------------------------------------------------------
//
void ButtonLoop()
{
	// if(g_ayVGM_State & AYVGM_STATE_LOOP)
		// g_ayVGM_State &= ~AYVGM_STATE_LOOP;
	// else
		// g_ayVGM_State |= AYVGM_STATE_LOOP;
}

//-----------------------------------------------------------------------------
//
void SetCursor(u8 id)
{
	g_CurrentButton = id % 6;
	VDP_SetSpriteSM1(0, 8 + 16*g_CurrentButton, 128-1, g_ButtonEntry[g_CurrentButton].Char, COLOR_LIGHT_RED);
}


//=============================================================================
// MAIN LOOP
//=============================================================================

//-----------------------------------------------------------------------------
// Program entry point
void main()
{
	// Initialize screen
	VDP_SetMode(VDP_MODE_SCREEN1);
	VDP_ClearVRAM();
	VDP_EnableVBlank(true);

	// Initialize font
	Print_SetTextFont(g_Font_MGL_Sample8, 1); // Initialize font
	Print_DrawText(MSX_GL " WYZ Sample");
	Print_DrawLineH(0, 1, 32);

	Print_SetPosition(20, 10);
	Print_DrawText("Main-ROM:");
	Print_SetPosition(20, 11);
	Print_DrawFormat("\x07" "Freq  %s", (g_ROMVersion.VSF) ? "50Hz" : "60Hz");

	// Decode VGM header
	SetMusic(0);
	Print_DrawBox(0, 15, numberof(g_ButtonEntry) * 2 + 1, 3);
	for(u8 i = 0; i < numberof(g_ButtonEntry); ++i)
	{
		Print_SetPosition(1 + 2 * i, 16);
		Print_DrawChar(g_ButtonEntry[i].Char);
		
	}

	// Footer
	Print_DrawLineH(0, 22, 32);
	Print_SetPosition(0, 23);
	Print_DrawText("\x8D:Button \x83:Action");

	//-------------------------------------------------------------------------
	// Sprite
	
	VDP_SetSpriteFlag(VDP_SPRITE_SIZE_8 + VDP_SPRITE_SCALE_1);
	VDP_LoadSpritePattern(g_Font_MGL_Sample8 + 4, 0, g_Font_MGL_Sample8[3] - g_Font_MGL_Sample8[2]);

	SetCursor(4);

	u8 prevRow8 = 0xFF;
	u8 count = 0;
	while(1)
	{
		Halt();
		if(!g_Freq60Hz || (count % 6 != 0))
		{
			WYZ_Decode();
			WYZ_PlayAY();
		}
		// ayVGM_Decode();
		// #if (PSG_ACCESS == PSG_INDIRECT)
		// PSG_Apply();
		// #endif
		VDP_SetSpriteColorSM1(0, g_ColorBlink[(count >> 2) & 0x03]);
		
		Print_SetPosition(31, 0);
		u8 chr = count++ & 0x03;
		Print_DrawChar(g_ChrAnim[chr]);
		
		// Handle input
		u8 row8 = Keyboard_Read(8);

		// Change button
		if(IS_KEY_PRESSED(row8, KEY_RIGHT) && !IS_KEY_PRESSED(prevRow8, KEY_RIGHT))
		{
			SetCursor(g_CurrentButton + 1);
		}
		else if(IS_KEY_PRESSED(row8, KEY_LEFT) && !IS_KEY_PRESSED(prevRow8, KEY_LEFT))
		{
			SetCursor(g_CurrentButton - 1);
		}
		// Activate button
		if(IS_KEY_PRESSED(row8, KEY_SPACE) && !IS_KEY_PRESSED(prevRow8, KEY_SPACE))
		{
			g_ButtonEntry[g_CurrentButton].Func();
		}
		
		prevRow8 = row8;
	}
}