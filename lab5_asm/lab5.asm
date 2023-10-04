.8086
.model small

.stack 100h

.DATA
    input_file_name         db "lab5_inp.txt",0
    output_file_name        db "lab5_out.txt",0
    
    message                 db "Enter a sequence of symbols: $"
    
    input_file_descriptor   dw 0
    output_file_descriptor  dw 0
    
    read_size               equ 1024
    
    buffer_for_file         db 1024 dup('$')
    input_string            db 200  dup('$')
    input_string_len        db 0
    string_for_check        db 200  dup('$')
    formatted_output_string db 0Dh, 0Ah

.CODE

open_file_read proc
    push bp
    mov bp, sp

    mov dx, [bp + 4]
    mov ah, 3Dh
    mov al, 00h
    int 21h
    jc close_input_file

    pop bp
    ret 2
close_input_file:
    mov ah, 3Eh
    int 21h

    pop bp
    ret 2
open_file_read endp

open_file_write proc
    push bp
    mov bp, sp

    mov dx, [bp + 4]
    mov ah, 3Dh
    mov al, 01h
    int 21h
    jc close_output_file

    pop bp
    ret 2
close_output_file:
    mov ah, 3Eh
    int 21h

    pop bp
    ret 2
open_file_write endp

read_from_file proc
    push bp
    mov bp, sp
    
    mov bx, [bp + 4]
    mov cx, read_size
    mov dx, offset buffer_for_file
    mov ah, 3Fh
    int 21h
    
    pop bp
    ret 2
read_from_file endp

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
    mov byte [bx], al

    pop bp
    ret 2
input_str endp

output_str proc
    push bp
    mov bp, sp

    mov ah, 9h
    mov dx, [bp + 4]
    int 21h

    pop bp
    ret 2
output_str endp

write_in_file proc
    push bp
    mov bp, sp

    mov ah, 40h
    mov bx, output_file_descriptor
    mov dx, [bp + 4]
    mov cx, [bp + 6]
    int 21h
    
    mov ah, 40h
    mov bx, output_file_descriptor
    mov dx, offset formatted_output_string
    mov cx, 2
    int 21h

    pop bp
    ret 4
write_in_file endp

check_sequence proc
    push di
    push si
    push bp
    mov bp, sp

    mov bx, [bp + 8]
    xor cx, cx
    xor di, di
    xor si, si
    check_sequence_loop:
        mov al, [bx + di]
        cmp al, '$'
        je check_writed_sequence
        cmp al, [input_string + si + 2]
        je letter_fits
        inc di
        jmp check_sequence_loop
        letter_fits:
            xor di, di
            inc cx
            inc si
            jmp check_sequence_loop
        check_writed_sequence:
            cmp cl, input_string_len
            je write_string
            jmp end_check_sequence_loop
    
    write_string:
        mov dx, [bp + 10]
        push dx
        mov dx, [bp + 8]
        push dx
        call write_in_file
    end_check_sequence_loop:
    pop bp
    pop si
    pop di
    ret 4
check_sequence endp

start:
    mov ax, @data
    mov ds, ax

    mov dx, offset message
    push dx
    call output_str

    mov dx, offset input_string
    push dx
    call input_str 

    mov bx, offset input_string
    mov al, byte [bx + 1]
    mov input_string_len, al

    mov dx, offset input_file_name
    push dx
    call open_file_read
    mov input_file_descriptor, ax
    
    mov dx, offset output_file_name
    push dx
    call open_file_write
    mov output_file_descriptor, ax
    
    mov dx, input_file_descriptor
    push dx
    call read_from_file
    
    xor di, di
    xor si, si
    xor cx, cx
    find_sequence_loop:
        xor cx, cx
        take_word:
            mov al, [buffer_for_file + di]
            cmp al, '$'
            je end
            cmp al, 0Dh
            je end_find_sequence_loop
            cmp al, 0
            je end_find_sequence_loop
            mov [string_for_check + si], al
            inc di
            inc si
            inc cx
            jmp take_word
            end_find_sequence_loop:
                mov [string_for_check + si], '$'
                xor si, si
                add di, 2
                mov dx, offset string_for_check
                push cx
                push dx
                call check_sequence
                jmp find_sequence_loop
    end:        

    mov bx, input_file_descriptor
    mov ah, 3Eh
    int 21h
    
    mov bx, output_file_descriptor
    mov ah, 3Eh
    int 21h

    mov ax, 4C00h
    int 21h
end start