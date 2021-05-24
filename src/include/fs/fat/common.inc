include 'util/string.inc'

; FAT tenths/sec
if ~ defined fat_dsec_t
struc fat_dsec_t dsec*
{
	; range: [0-199]
	assert (dsec >= 0 & dsec <= 199)

	common
		. db dsec
}
end if

; FAT time
if ~ defined fat_time_t
struc fat_time_t hour*, min*, sec*
{
	; validate hour
	assert (hour >= 0 & hour < 24)
	; validate minutes
	assert (min >= 0 & min < 60)
	; validate seconds
	assert (sec >= 0 & sec < 60)

	; calculate parts from arguments
	local
		; [hour]		bits: 5, shift: 11
		h		= ((hour & 0b11111) << 11)
		; [minutes]	bits: 6, shift: 5
		m		= ((min & 0b111111) << 5)
		; [seconds]	bits: 5, shift: 0, divide by 2
		s		= ((sec / 2) & 0b11111)

	; calculate parts from value
	common
		; word packed time
		.time			dw (h|m|s))
		;	Hour:			top 5 bits
		.hour			= ((.time >> 11) & 0b11111)
		;	Minutes:	middle 6 bits
		.minutes	= ((.time >> 5) & 0b111111)
		;	Seconds:	bottom 5 bits	(multiply seconds by 2)
		.seconds	= ((.time & 0b11111) * 2)
}
end if

; FAT date
if ~ defined fat_date_t
struc fat_date_t year*, month*, day*
{
	; validate month
	assert (month >= 0 & month < 12)
	; validate day
	assert (day >= 0 & day <= 31)

	local 
		; [year]		bits: 7, shift: 9
		y		= ((year & 0b1111111) << 9)
		; [month]		bits: 4, shift: 5
		m		= ((month & 0b1111) << 5)
		; [day]			bits: 5, shift: 0
		d		= (day & 0b11111)
	common
		; word packed date
		.date		dw (y|m|d)
		;	Year:		top 7 bits
		.year		= ((.date >> 9) & 0b1111111)
		;	Month:	middle 4 bits
		.month	= ((.date >> 5) & 0b1111)
		;	Day:		bottom 5 bits
		.day		= (.date & 0b11111)
}
end if

; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

