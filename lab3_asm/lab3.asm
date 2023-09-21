.8086
.MODEL small

.DATA
    array db 30 dup(0)
    mes1 db "Enter num: $"
    mes2 db "Enter left limit: $"
    mes3 db "Enter right limit: $"
    mes4 db "Count of elements: $"
    mes5 db 0Ah, 0Dh, "-----Enter 30 elements of array-----", 0Ah, 0Dh, '$'
    mul_for_convert db 10 ; needs to mul intermediate res
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

start:
    mov ax, @data
    mov ds, ax

    mov dx, offset mes5
    push dx
    call output_str

    mov ah, 02h
    mov dx, 0Ah
    int 21h

    mov ah, 02h
    mov dx, 0Dh
    int 21h

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

    cmp di, 0
    je end_prog

    mov ax, di
    mov bx, 10
    mov di, 0

coonvert_loop:
    cmp al, 0
    je end_coonvert_loop
    continue:
        div bl
        mov dl, ah
        xor ah, ah
        push dx
        inc di
        jmp coonvert_loop

end_coonvert_loop:
    mov cx, di
    pop_loop:
        pop ax
        mov ah, 02h
        mov dx, ax
        add dx, '0'
        int 21h
        loop pop_loop

output_result:
    mov ah, 02h
    mov dx, 0Ah
    int 21h

    mov ah, 02h
    mov dx, 0Dh
    int 21h

    mov ax, 4C00h
    int 21h

end_prog:
        mov ah, 02h
        mov dx, di
        add dx, '0'
        int 21h
        jmp output_result

.STACK 100h

end start
