.186
.model small

.stack 100h

.data 
    command_line    db 125
    programm_pass   db "main.exe",0 

    EPB             dw 0000h
                    dw offset command_line, 0
                    dw 005Ch, 0
                    dw 006Ch, 0

    ds_size = $ - command_line

.code

start:
    mov ah, 4Ah
    mov bx, (cs_size / 16 + 1) + (ds_size / 16 + 1) + (256 / 16) + (256 / 16) 
    int 21h
    jc exit

    mov ax, @data
    mov ds, ax

    mov ax, ds
    mov word ptr [EPB + 4], ax
    mov ax, cs
    mov word ptr [EPB + 8], ax
    mov word ptr [EPB + 12], ax

    mov ax, 4B00h
    mov dx, offset programm_pass
    mov bx, offset EPB
    int 21h
    jc exit

exit:
    mov ax, 4C00h
    int 21h    
    cs_size = $ - start
end start