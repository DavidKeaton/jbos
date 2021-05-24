include 'common.inc'

; FS Info (fat32 only)
if ~ defined fsinfo_t
struc fsinfo_t lfc, sc
{
	; @0x000	(4)		- lead signature (0x41615252)
	.lead_sig						dd 0x41615252
	; @0x004	(480)	- reserved, never use these bytes
	.reserved						db 480 dup(0)
	; @0x1E4	(4)		- another signature (0x61417272)
	.mid_sig						dd 0x61417272
	; @0x1E8	(4)		- contains the last known free cluster count on the volume
	;		if the value is -1 (0xFFFFFFFF), then the free count is unknown and must
	;		be computed, however this value may be incorrect and be range checked
	;		(<= volume cluster count)
	.last_free_cluster	dd lfc
	; @0x1EC	(4)		- indicates custer number where the fs driver should start
	;		looking for available clusters, if -1 (0xFFFFFFFF) then there is no hint
	;		and the driver should start searching @ 2
	;		normally this is set to the last allocated cluster number, but should
	;		also should be range checked, like @0x1E8
	.start_cluster			dd sc
	; @0x1F0	(4)		- trail signature (0xAA550000)
}
end if
; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

