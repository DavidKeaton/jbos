include 'common.inc'

; FAT short file name (8.3 file name)
if ~ defined shortname_t
struc shortname_t name*, ext=NULL, attr, cts, ct, cd, ad, hi, mt, md, lo, size
{
	; @0x00		(11)	- file name in 8.3 format, 8 = name, 3 = extension
	.name						name8_3 name, ext
	; @0x0B		(1)		- file attribute:
	;		READ_ONLY:	0x01
	;		HIDDEN:			0x02
	;		SYSTEM:			0x04
	;		VOLUME_ID:	0x08
	;		DIRECTORY:	0x10
	;		ARCHIVE:		0x20
	;		LFN:				READ_ONLY|HIDDEN|SYSTEM|VOLUME_ID
	;			(entry is a Long File Name)
	.attr						db attr
	; @0x0C		(1)		- reserved for winNT
	.nt_reserved		db 0
	; @0x0D		(1)		- creation time in tenths of a second, range: [0-199]
	.creation_dsecs	???
	; @0x0E		(2)		- time file was created, multiply seconds by 2
	;		Hour:			5 bits
	;		Minutes:	6 bits
	;		Seconds:	5 bits
	.creation_time	???
	; @0x10		(2)		- date file was created
	;		Year:			7 bits
	;		Month:		4 bits
	;		Day:			5 bits
	.creation_date	???
	; @0x12		(2)		- last access date (see @0x10)
	.access_date		???
	; @0x14		(2)		- high 16 bits of entry's first cluster
	;		(always 0 for fat12/16)
	.cluster_hi			dw hi
	; @0x16		(2)		- last modification time (see @0x0E)
	.modify_time		???
	; @0x18		(2)		- last modification date (see @0x10)
	.modify_date		???
	; @0x1A		(2)		- low 16 bits of entry's first cluster
	.cluster_lo			dw lo
	; @0x1C		(4)		- size of the file in bytes
	.size						dd size
}
end if
; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

