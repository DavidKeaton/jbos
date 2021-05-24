include 'common.inc'

; Extended Boot Record (fat32)
if ~ defined ebr32_t
struc ebr32_t	spf, \
							f, \
							v, r, fsi, b, d, nt, sig, vid, vl, sid="FAT32"
{
	; @0x024	(4)		- sectors per fat, the size of the fat in sectors
	.sectors_per_fat	dd spf
	; @0x028	(2)		- flags
	.flags						dw f
	; @0x02A	(2)		- fat version number, high byte = major, low byte = minor
	.version					dw v
	; @0x02C	(4)		- cluster number of root dir, often set to 2
	.root							dd r
	; @0x030	(2)		- sector number of FSInfo structure
	.fsinfo						dw fsi
	; @0x032	(2)		- sector number of backup boot sector
	.backup						dw b
	; @0x034	(12)	- reserved, should be formatted to 0
	.reserved					db 12 dup(0)
	; @0x040	(1)		- drive number, values are identical BIOS interrupt 0x13
	;		0x00 - floppy, 0x80 - hdd
	.drive						db d
	; @0x041	(1)		- flags in winNT, or reserved
	.nt_flags					db nt
	; @0x042	(1)		- signature (must be 0x28 or 0x29)
	.signature				db sig
	; @0x043	(4)		- volume id 'serial' number, used to track volumes
	.volume_id				dd vid
	; @0x047	(11)	- volume label string, pad field with spaces
	.volume_label			string_p 11,vl
	; @0x052	(8)		- system identifier string, space padded
	;		represents the FAT file system type ("FAT32   ")
	;.system_id				string_p 8,sid
	.system_id				string_p 8, sid
	; @0x05A	(420)	- boot code
	; @0x1FE	(2)		- boot signature 0xAA55
}
end if
; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

