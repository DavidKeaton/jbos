include 'common.inc'

; FAT - BIOS Parameter Block
if ~ defined bpb_t
struc bpb_t oem, bps, spc, rs, t, de, spv, mt, spf, spt, h, hs, ls
{
	; @0x03 (8)	- OEM identifier
	.OEM						string_n 8,oem
	; @0x08 (2)	- number of bytes per sector
	.bytes_per_sec	dw bps
	; 0x0D	(1)	- number of sectors per cluster
	.sec_per_clus		db spc 
	; 0x0E	(2)	- number of reserved sectors (include boot sectors here)
	.reserved_sec		dw rs 
	; 0x10	(1)	- number of FATs on storage media (often value is 2)
	.tables					db t
	; 0x11	(2) - number of dir entries
	;	(must be set so root dir occupies entire sectors)
	.dir_entries		dw de 
	; 0x13	(2) - total sectors in logical volume
	;		if 0, 65535 sectors in volume, and actual count is partially
	;		stored in Large Sector Count @ 0x20, as well (combine for total value)
	.sec_per_vol		dw spv 
	; 0x15	(1)	- media descriptor type
	;			TODO: add table
	.media_type			db mt
	; 0x16	(2)	- number of sectors per FAT (fat12/fat16 only)
	.sec_per_fat		dw spf
	; 0x18	(2)	- number of sectors per track
	.sec_per_track	dw spt
	; 0x1A	(2)	- number of heads or sides on storage media
	.heads					dw h
	; 0x1C	(4)	- number of hidden sectors (the LBA of the start of partition)
	.hidden_sec			dd hs
	; 0x20	(4)	- large sector count, set if volume sectors > 65535 (see 0x13)
	.large_sec			dd ls
}
end if
; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

