format binary
use16

org 0x0
_boot:
    ; set code segment
    push 0x7c0
    pop cs
    jmp _start
_start:
    ; now @ 0x7c0:0000




; fill null bytes until sig
repeat 510 - ($ - $$)
    db 0
end repeat
; floppy signature at bytes 510 & 511
db 0x55, 0xAA
; vim: set ft=fasm ts=4 sts=4 sw=4 si :
