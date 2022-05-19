// ____________________________
// ██▀▀█▀▀██▀▀▀▀▀▀▀█▀▀█        │  ▄▄▄▄ ▄▄ ▄  ▄▄ 
// ██  ▀  █▄  ▀██▄ ▀ ▄█ ▄▀▀ █  │   ▄█▀ ▀█▄▀ █ ██
// █  █ █  ▀▀  ▄█  █  █ ▀▄█ █▄ │  ██▄▄ ██ █ ▀▄█▀
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀────────┘  
//  by Guillaume 'Aoineko' Blanchard under CC-BY-AS license
//─────────────────────────────────────────────────────────────────────────────
// ZX0 decoder by Einar Saukas & Urusergi
//  "Standard" version (68 bytes only)
//  https://github.com/einar-saukas/ZX0/blob/main/z80/dzx0_standard.asm
//─────────────────────────────────────────────────────────────────────────────
#include "core.h"

//-----------------------------------------------------------------------------
// Unpack ZX0 compressed data to a RAM buffer
void ZX0_Unpack(u16 source, u16 dest)
{
	source;	// HL
	dest;	// DE

__asm
; Parameters:
;   HL: source address (compressed data)
;   DE: destination address (decompressing)
dzx0_standard:
	ld      bc, #0xFFFF             ; preserve default offset 1
	push    bc
	inc     bc
	ld      a, #0x80
dzx0s_literals:
	call    dzx0s_elias             ; obtain length
	ldir                            ; copy literals
	add     a, a                    ; copy from last offset or new offset?
	jr      c, dzx0s_new_offset
	call    dzx0s_elias             ; obtain length
dzx0s_copy:
	ex      (sp), hl                ; preserve source, restore offset
	push    hl                      ; preserve offset
	add     hl, de                  ; calculate destination - offset
	ldir                            ; copy from offset
	pop     hl                      ; restore offset
	ex      (sp), hl                ; preserve offset, restore source
	add     a, a                    ; copy from literals or new offset?
	jr      nc, dzx0s_literals
dzx0s_new_offset:
	pop     bc                      ; discard last offset
	ld      c, #0xFE                ; prepare negative offset
	call    dzx0s_elias_loop        ; obtain offset MSB
	inc     c
	ret     z                       ; check end marker
	ld      b, c
	ld      c, (hl)                 ; obtain offset LSB
	inc     hl
	rr      b                       ; last offset bit becomes first length bit
	rr      c
	push    bc                      ; preserve new offset
	ld      bc, #1                  ; obtain length
	call    nc, dzx0s_elias_backtrack
	inc     bc
	jr      dzx0s_copy
dzx0s_elias:
	inc     c                       ; interlaced Elias gamma coding
dzx0s_elias_loop:
	add     a, a
	jr      nz, dzx0s_elias_skip
	ld      a, (hl)                 ; load another group of 8 bits
	inc     hl
	rla
dzx0s_elias_skip:
	ret     c
dzx0s_elias_backtrack:
	add     a, a
	rl      c
	rl      b
	jr      dzx0s_elias_loop
; -----------------------------------------------------------------------------
__endasm;
}
