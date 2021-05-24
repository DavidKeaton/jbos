format binary
use16


org 0
_boot:
	; set code segment
	push 0
	push 0x07c0
	pop cs
	ret
; size of [org 0] chunk
s1 = ($ - $$)
org 0x07C0
_start:
	; now @ 0x7c0:0000

; 


; size of [org 0x07c0] chunk
s2		= ($ - $$)
fill	= (510 - s1 - s2)
; if negative, there is a problem
assert (fill >= 0)
; fill null bytes until sig
times (fill) : db 0
; floppy signature at bytes 510 & 511
db 0x55, 0xAA

; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :
