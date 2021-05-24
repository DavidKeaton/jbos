; --------------------------------
; 	String and filename macros
; --------------------------------

include 'util/constants.inc'

; create a string
if ~ defined string
macro string [data]
{
	common
		. db data
		.size = $ - .
}
end if

; create a string of maximum 'n' length
if ~ defined string_n
macro string_n n*,[data]
{
	common
		. db data
		.size = $ - .
	; throw error if size constraint not met
	assert size <= n
}
end if

; create a space-padded string up to length 'n'
if ~ defined string_p
macro string_p n*,[data]
{
	common
		. db data
		.size = $ - .
	; make sure string isn't past maximum
	assert size <= n
	; pad the rest of the string
	count = n - size
		.pad 
	repeat count
		db " "
	end repeat
}
end if

; file name in 8.3 format
if ~ defined name8_3
name8_3 name*, ext=NULL
{
	common
		.
		.name		string_p
	; if no extension given, pad EXT field
	if ext = NULL
		.ext		string "   "
	; if it was, make sure it's properly padded
	else
		.ext		string_p 3,ext
	end if
}
end if

; vim: set ft=fasm ts=2 sts=0 sw=2 si ci :

