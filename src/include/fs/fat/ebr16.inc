include 'common.inc'

; Extended Boot Record (fat12/fat16)
if ~ defined ebr16_t
struc ebr16_t dn, nt, sig, vid, vl, sid
{
	; @0x024	(1)		- drive number: this number should be identical to BIOS
	;		interrupt 0x13, or passed in DL (0x00 = floppy, 0x80 = hdd),
	;		can be useless though...
	.drive				db dn
	; @0x025	(1)		- flags in winNT, or reserved
	.nt_flags			db nt
	; @0x026	(1) 	- signature (must be 0x28 or 0x29)
	.signature		db sig
	; @0x027	(4)		- volume id 'serial' number, used to track volumes
	.volume_id		dd vid
	; @0x02B	(11)	- volume label string, pad field with spaces
	.volume_label	string_p 11,vl
	; @0x036	(8)		- system identifier string, space padded
	;		represents the FAT file system type ("FAT12   " / "FAT16   ")
	.system_id		string_p 8,sid
	; @0x03E	(448)	- boot code
	; @0x1FE	(2)		- boot signature 0xAA55
}
end if
; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

