.8086
.MODEl small

.DATA
    string1 db 200 dup('$')
    string2 db 200 dup('$')
    mes1 db "Enter first string: $" 
    mes2 db "Enter second string: $"
    mes3 db "Enter num of string: $"
    mes4 db "New string: $"
    mes5 db "NO ENTERED WORD YET$"
    number_k db 0

.CODE

input_str proc
    push bp
    mov bp, sp
    
    mov ah, 0Ah
    mov dx, [bp + 4]
    int 21h

    mov ah, 02h
    mov dx, 0Ah
    int 21h

    ; needs to replace carriege return to $
    xor ax, ax
    mov bx, [bp + 4]
    mov al, [bx + 1]
    add bx, 2
    add bx, ax
    mov al, '$'
    mov byte [bx - 1], al

    pop bp
    ret 2
input_str endp

input_num proc
    mov ah, 1
    int 21h
    sub al, '0'     
    mov number_k, al

    mov ah, 02h
    mov dx, 0Ah
    int 21h

    mov ah, 02h
    mov dx, 0Dh
    int 21h

    ret
input_num endp

output_str proc
    push bp
    mov bp, sp

    mov ah, 9h
    mov dx, [bp + 4]
    int 21h

    pop bp
    ret 2
output_str endp

if_letter proc
    cmp al, 'A'
    jl not_letter
    cmp al, 'Z'
    jbe its_letter

    cmp al, 'a'
    jl not_letter
    cmp al, 'z'
    jbe its_letter

not_letter: 
        mov al, 0
        ret
its_letter:
        mov al, 1
        ret 
if_letter endp

find_k_word proc
    push bp
    mov bp, sp

    mov ch, number_k ; number of string to find 
    mov si, [bp + 4] ; entered string 
    mov bx, 0 ; index
    mov ah, 0 ; counter of words
    mov dh, 0 ; flag 

    find_loop:
        mov al, [si + bx] 
        mov dl, al 

        call if_letter

        cmp al, 1
        je word_start

        mov dh, 0

    continue:
            cmp ah, ch
            jne not_k_word

            mov di, bx
            pop bp
            ret 2

    not_word_start:
            mov dh, 1
            inc ah
            jmp continue

    word_start:
            cmp dh, 0
            je not_word_start

    not_k_word:
            inc bx

            cmp dl, '$'
            jne find_loop

            mov di, 65h
            pop bp
            ret 2
find_k_word endp

reverse_str proc
    push bp
    mov bp, sp

    mov cx, 198 ; counter of main loop
    mov ax, 0 ; counter for second loop
   
    mov si, [bp + 4] ; string
    mov bx, [bp + 6] ; index of start reverse
    
    mov dl, [si + bx] ; character
    mov dh, 00h 

    push_in_stack_loop:
        cmp dl, '$'
        je pop_stack_loop

        push dx

        inc bx
        inc ax

        mov dx, [si + bx]
        loop push_in_stack_loop
        pop_stack_loop:
            mov cx, ax
            mov si, [bp + 4]
            mov bx, [bp + 6]
        pop_loop:
                pop dx

                mov [si + bx], dl
                inc bx
                loop pop_loop

        pop bp
        ret 2
reverse_str endp

index_of_last_word proc
    push bp 
    mov bp, sp

    mov si, bx
    dec si ; index of last word

    mov bx, [bp + 4]
    mov ax, [bx + si]

    last_word_loop:
        call if_letter
        cmp al, 1
        jne end_last_word_loop
        dec si
        mov ax, [bx + si]
        jmp last_word_loop
    end_last_word_loop:
        inc si
        pop bp
        ret
index_of_last_word endp

insert_word_from_index proc
    mov di, 0
    mov al, [string2 + 2 + di]

    insert_loop:
        cmp al, '$'
        je end_insert_loop

        mov al, [string2 + 2 + di]
        mov [string1 + 2 + si], al

        inc di
        inc si

        jmp insert_loop
    end_insert_loop:
            ret
insert_word_from_index endp

start:
    mov ax, @data
    mov ds, ax

    mov dx, offset mes1
    push dx
    call output_str

    mov dx, offset string1
    push dx
    call input_str

    mov dx, offset mes2
    push dx
    call output_str

    mov dx, offset string2
    push dx
    call input_str

    mov dx, offset mes3
    push dx
    call output_str

    call input_num

    mov dx, offset string1 + 2
    push dx
    call find_k_word

    cmp di, 65h ; check number of word to change
    je end_prog

    mov dx, offset string1 + 2
    push di
    push dx
    call reverse_str
    pop di

    mov ax, 0 ; to reverse all second str
    mov dx, offset string2 + 2
    push ax
    push dx
    call reverse_str
    pop ax

    xor bx, bx
    mov dx, offset string1 + 2
    mov si, offset string1 + 1
    mov bl, [si] ; string1 length
    push dx
    call index_of_last_word

    mov cx, di
    call insert_word_from_index

    mov di, cx
    mov dx, offset string1 + 2
    push di
    push dx
    call reverse_str
    pop di

    mov dx, offset mes4
    push dx
    call output_str

    mov dx, offset string1 + 2
    push dx
    call output_str

    mov ah, 02h
    mov dx, 0Ah
    int 21h

    mov ah, 02h
    mov dx, 0Dh
    int 21h

    mov ax, 4C00h
    int 21h

end_prog:
    mov dx, offset mes5
    push dx
    call output_str
    
    mov ah, 02h
    mov dx, 0Ah
    int 21h

    mov ah, 02h
    mov dx, 0Dh
    int 21h

    mov ax, 4C00h
    int 21h

.STACk 100h

end start
