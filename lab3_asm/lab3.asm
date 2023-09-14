.8086
.MODEL small

.DATA
    array db 30 dup(0)
    mes1 db "Enter num: $"
    mes2 db "Enter left limit: $"
    mes3 db "Enter right limit: $"
    mes4 db "Count of elements: $"
    mul_for_convert db 0
    left_limit db 0
    right_limit db 0

.CODE

output_str proc
    push bp
    mov bp, sp

    mov ah, 9h
    mov dx, [bp + 4]
    int 21h

    pop bp
    ret 2
output_str endp

input_limit proc
    push bp
    mov bp, sp

    mov mul_for_convert, 10 ; needs to mul intermediate res
    mov di, [bp + 4] ; left border
    mov bl, 0 ; for fisrt mul on zero
    xor ax, ax ; можно не делать из-за 43 строки
    xor bx, bx

    input_loop:
        mov ah, 01h
        int 21h

        cmp al, 13
        je end_input_loop

        mov ah, 0
        sub al, '0'

        mov cl, al
        mov al, bl

        mul mul_for_convert

        add al, cl
        mov bl, al

        mov [di], ax

        jmp input_loop
    
    end_input_loop:
        pop bp
        ret 2
input_limit endp

fill_array proc
    mov si, offset array
    mov cx, 30 ; counter of loop
    mov mul_for_convert, 10 ; needs to mul intermediate res

    fill_array_loop:
        mov dx, offset mes1
        push dx
        call output_str
        
        mov bl, 0 ; for fisrt mul on zero

        xor ax, ax ; можно не делать из-за 71 строки
        xor bx, bx

        convert_loop:
            mov ah, 01h
            int 21h

            cmp al, 13 ; check if end number (13 = carriege return)
            je end_convert_loop

            mov ah, 0
            sub al, '0'

            mov dl, al
            mov al, bl

            mul mul_for_convert

            add al, dl
            mov bl, al

            mov [si], ax

            jmp convert_loop

            end_convert_loop:
                inc si

            loop fill_array_loop
    ret
fill_array endp

count_elements_in_limits proc
    mov si, 0 ; index of array
    mov di, 0 ; counter of numbers in limits
    xor ax, ax
    mov bl, left_limit
    mov dl, right_limit
    mov cx, 30

    count_loop:
        mov al, [array + si]

        cmp al, bl
        jl not_in_limits

        cmp al, dl
        jbe in_limits

        not_in_limits:
            inc si
            loop count_loop

            cmp cx, 0
            je end_count_loop
        in_limits:
            inc si
            inc di
            loop count_loop

    end_count_loop:
    ret
count_elements_in_limits endp

convert_num proc
    push bp
    mov bp, sp

    mov ax, [bp + 4]
    mov bx, 10
    div bl

    mov bx, [bp + 4]
    sub bx, [bp + 6]

    add ax, '0'
    add bx, '0'

    mov ah, 02h
    mov dx, ax
    int 21h

    mov ah, 02h
    mov dx, bx
    int 21h

    pop bp
    ret 4
convert_num endp

start:
    mov ax, @data
    mov ds, ax

    call fill_array

    mov dx, offset mes2
    push dx
    call output_str

    mov dx, offset left_limit
    push dx
    call input_limit

    mov dx, offset mes3
    push dx
    call output_str

    mov dx, offset right_limit
    push dx
    call input_limit

    call count_elements_in_limits

    mov dx, offset mes4
    push dx
    call output_str

    mov ax, di
    cmp ax, 30
    jge more_than_thirty
    cmp ax, 20
    jge more_than_twenty
    cmp ax, 10
    jge more_than_ten
    add ax, '0'
    jmp less_the_ten

    more_than_thirty:
        mov bx, 30
        push bx
        push ax
        call convert_num
        jmp output_result
    more_than_twenty:
        mov bx, 20
        push bx
        push ax
        call convert_num
        jmp output_result
    more_than_ten:
        mov bx, 10
        push bx
        push ax
        call convert_num
        jmp output_result
    less_the_ten:
        mov ah, 02h
        mov dx, ax
        int 21h
output_result:
    mov ah, 02h
    mov dx, 0Ah
    int 21h

    mov ah, 02h
    mov dx, 0Dh
    int 21h

    mov ax, 4C00h
    int 21h

.STACK 100h

end start