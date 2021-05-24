include 'common.inc'

; FAT long file name
if ~ defined longname_t
struc longname_t
{
	; @0x00		(1)		- order of entry in sequence of long filename entries
	;		helps one to know where in the file's name of characters this entry
	;		should be placed
	; @0x01		(10)	- first 5, 2-byte characters of entry
	; @0x0B		(1)		- attribute, always set to 0x0F (LFN)
	; @0x0C		(1)		- long entry type, 0 for name entries
	; @0x0D		(1)		- checksum generated of short filename when file was created
	;		short file name can change without changing the long filename in the
	;		event the system only handles short filenames
	; @0x0E		(12)	- next 6, 2-byte characters of entry
	; @0x1A		(2)		- reserved, always zero
	; @0x1C		(4)		- final 2, 2-byte characters of entry
}
end if
; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

