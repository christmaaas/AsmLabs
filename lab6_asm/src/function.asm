.model flat, c

.code

sum_of_elements proc
	push ebp
	mov ebp, esp

	array	equ [ebp + 8]
	sum	equ [ebp + 12]

	mov ebx, array
	mov edx, sum

	mov ecx, 10

	finit

sum_loop:
	fld dword ptr [ebx]
	fadd dword ptr [edx]
	fstp dword ptr [edx]
	add ebx, 4
	loop sum_loop
	
	pop ebp
	ret
sum_of_elements endp

end
