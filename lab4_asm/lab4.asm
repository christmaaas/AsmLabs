.8086
.model small

.STACK 100h

.DATA
    ;map
    map_wigth   equ 40
    map_height  equ 25

    wall    equ 2120h
    grnd    equ 0020h

    game_map dw map_wigth dup(wall)
             dw wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall
             dw wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall
             dw wall,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,wall
             dw wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall
             dw wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall
             dw wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall
             dw wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall
             dw wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,wall,wall,grnd,wall,grnd,grnd,wall,grnd,wall,wall,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall
             dw wall,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,wall
             dw wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall
             dw wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall
             dw wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,wall,grnd,grnd,wall,grnd,wall,wall,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall
             dw wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall
             dw wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,wall,wall,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall
             dw wall,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,wall
             dw wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall
             dw wall,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,wall,grnd,grnd,grnd,wall
             dw wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall,grnd,wall,grnd,wall,grnd,wall,wall,wall,grnd,wall
             dw wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall
             dw wall,grnd,wall,wall,wall,wall,wall,grnd,wall,grnd,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,wall,grnd,grnd,grnd,grnd,grnd,wall,grnd,grnd,grnd,wall,grnd,wall,wall,wall,wall,wall,grnd,wall
             dw wall,grnd,wall,wall,wall,wall,wall,grnd,wall,wall,grnd,wall,wall,wall,grnd,wall,wall,grnd,wall,grnd,grnd,wall,grnd,wall,wall,grnd,wall,wall,wall,grnd,wall,wall,grnd,wall,wall,wall,wall,wall,grnd,wall
             dw wall,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,grnd,wall
             dw map_wigth dup (wall)

    ;score
    score_message       dw 0F53h, 0F63h, 0F6Fh, 0F72h, 0F65h, 0F3Ah, 0F20h, 0F30h, 32 dup(0F20h)
    score               dw 0
    score_digit         dw 3 dup(?)
    score_line_position equ 1920
    score_position      equ 1934

    ;player
    player_position   dw 1762 
    player_direction  db ?
    player            dw 0E43h

    ;randomizing variables
    random_number     dw  0

    forward  equ 800
    left     equ 550
    back     equ 300

    ;ghosts
    first_ghost_position   dw 86
    second_ghost_position  dw 156
    third_ghost_position   dw 1836
    old_ghost_position     dw 0
    ghost                  dw 0F02h
    
    ;apple
    apple_position  dw 1768
    apple           dw 8404h

    ;control
    w_key_scan_code equ 11h
    a_key_scan_code equ 1Eh
    s_key_scan_code equ 1Fh
    d_key_scan_code equ 20h

.CODE

draw_map proc
    mov di, 0
    mov si, offset game_map

    mov cx, map_height
    draw_field_on_strings:
        push cx
        mov cx, map_wigth
        draw_field_on_columns:  
            movsw
        loop draw_field_on_columns
        pop cx
    loop draw_field_on_strings
    ret
draw_map endp

draw_score_line proc
    push cx

    mov si, offset score_message
    mov di, score_line_position

    mov cx, map_wigth
    draw_score_line_loop:
        movsw
    loop draw_score_line_loop

    pop cx
    ret
draw_score_line endp

draw_game_objects proc
    push cx

    mov si, offset player
    mov di, player_position
    movsw

    mov si, offset ghost
    mov di, first_ghost_position
    movsw

    mov si, offset ghost
    mov di, second_ghost_position
    movsw

    mov si, offset ghost
    mov di, third_ghost_position
    movsw

    mov si, offset apple
    mov di, apple_position
    movsw

    pop cx
    ret
draw_game_objects endp

clear_place_player proc 
    push cx

    mov si, 0120h
    mov di, player_position
    movsw 
    
    pop cx
    ret
clear_place_player endp

clear_place_ghost proc 
    push cx

    mov si, 0120h
    mov di, old_ghost_position
    movsw 
    
    pop cx
    ret
clear_place_ghost endp

randomize_number proc
    ;mov ax, 25173 ; fix value
    ;mul random_number       

    ;add ax, 13849 ; can be different          
    
    ;mov random_number, ax    

    ;xor dx, dx
    ;mov cx, 1000
    ;div cx

    ;ret

    mov ah, 0
    int 1Ah

    mov ax, dx

    mov bx, 12345 ; initial number (can be different)
    mov cx, 25173 ; LCG Multiplier (can be different)

    mul cx
    add ax, bx ; LCG operation

    xor dx, dx
    mov bx, 1001
    div bx

    ret
randomize_number endp


apple_randomize proc
    push cx

    mov cx, 0
    mov apple_position, 0

    repeat_randomization:
        call randomize_number

        mov bx, dx

        mov ax, game_map[bx]
        cmp ax, grnd
        je good_randomize
        jmp repeat_randomization
    
    good_randomize:
        mov apple_position, bx
    
    pop cx
    ret
apple_randomize endp

increase_score  proc
inc score
ret
increase_score endp

draw_score proc
    push cx

    mov bx, 10
    mov di, 0
    mov ax, score
    mov si, 0
    
    coonvert_loop:
    cmp al, 0
    je end_coonvert_loop
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
            mov ah, 0Fh
            add al, '0'
            mov score_digit[si], ax
            add si, 2
            loop pop_loop
    
    mov cx, di
    mov si, offset score_digit
    mov di, score_position
    draw_scoreee:
        movsw
    loop draw_scoreee

    pop cx
    ret
draw_score endp

directing_ghosts proc
    directing_first_ghost:
        call randomize_number
        mov bx, first_ghost_position
        mov old_ghost_position, bx

        cmp dx, forward
        jae going_first_w

        cmp dx, left
        jae going_first_a

        cmp dx, back
        jae going_first_s

        add bx, 2
        cmp game_map[bx], wall
        je directing_first_ghost
        jmp set_direction_first

        going_first_w:
            sub bx, 80
            cmp game_map[bx], wall
            je directing_first_ghost
            jmp set_direction_first
        going_first_a:
            sub bx, 2
            cmp game_map[bx], wall
            je directing_first_ghost
            jmp set_direction_first
        going_first_s:
            add bx, 80
            cmp game_map[bx], wall
            je directing_first_ghost
            jmp set_direction_first
        set_direction_first:
            call clear_place_ghost
            mov first_ghost_position, bx

    directing_second_ghost:
        call randomize_number
        mov bx, second_ghost_position
        mov old_ghost_position, bx

        cmp dx, forward
        jae going_second_w

        cmp dx, left
        jae going_second_a

        cmp dx, back
        jae going_second_s

        add bx, 2
        cmp game_map[bx], wall
        je directing_second_ghost
        jmp set_direction_second

        going_second_w:
            sub bx, 80
            cmp game_map[bx], wall
            je directing_second_ghost
            jmp set_direction_second
        going_second_a:
            sub bx, 2
            cmp game_map[bx], wall
            je directing_second_ghost
            jmp set_direction_second
        going_second_s:
            add bx, 80
            cmp game_map[bx], wall
            je directing_second_ghost
            jmp set_direction_second
        set_direction_second:
            call clear_place_ghost
            mov second_ghost_position, bx
           
    directing_third_ghost:
        call randomize_number
        mov bx, third_ghost_position
        mov old_ghost_position, bx

        cmp dx, forward
        jae going_third_w

        cmp dx, left
        jae going_third_a

        cmp dx, back
        jae going_third_s

        add bx, 2
        cmp game_map[bx], wall
        je directing_third_ghost
        jmp set_direction_third

        going_third_w:
            sub bx, 80
            cmp game_map[bx], wall
            je directing_third_ghost
            jmp set_direction_third
        going_third_a:
            sub bx, 2
            cmp game_map[bx], wall
            je directing_third_ghost
            jmp set_direction_third
        going_third_s:
            add bx, 80
            cmp game_map[bx], wall
            je directing_third_ghost
            jmp set_direction_third
        set_direction_third:
            call clear_place_ghost
            mov third_ghost_position, bx
    ret
directing_ghosts endp

game_over:
    mov ax, 4C00h
    int 21h

start:
    mov ax, @data
    mov ds, ax

    mov ah, 00h
    mov al, 01h
    int 10h

    mov ah, 01h
    mov cx, 2607h
    int 10h

    mov ax, 0B800h
    mov es, ax

    call draw_map
    call draw_score_line
    call draw_game_objects
    
game_cycle:
        mov cx,0
        mov ah,86h
        mov dx,65535
        int 15h
        int 15h
        int 15h 
        
        mov dx, first_ghost_position
        cmp player_position, dx
        je game_over

        mov dx, second_ghost_position
        cmp player_position, dx
        je game_over

        mov dx, third_ghost_position
        cmp player_position, dx
        je game_over

        mov dx, apple_position
        cmp player_position, dx
        jne dont_random_apple
        call apple_randomize
        call increase_score
        call draw_game_objects
        call draw_score

        dont_random_apple:
            call directing_ghosts
            call draw_game_objects

            mov ah, 01h
            int 16h
            jz dont_press
        
            mov ah, 00h
            int 16h

            cmp ah, w_key_scan_code
            jne not_w
            mov player_direction, 'w'
            jmp dont_press
        not_w:
            cmp ah, a_key_scan_code
            jne not_a
            mov player_direction, 'a'
            jmp dont_press
        not_a:
            cmp ah, s_key_scan_code
            jne not_s
            mov player_direction, 's'
            jmp dont_press
        not_s:
            cmp ah, d_key_scan_code
            jne not_d
            mov player_direction, 'd'
            jmp dont_press
        not_d:

        dont_press:
            cmp player_direction, 'w'
            je w_pressed
            cmp player_direction, 'a'
            je a_pressed
            cmp player_direction, 's'
            je s_pressed
            cmp player_direction, 'd'
            je d_pressed

            jmp game_cycle

        w_pressed:
            mov si, player_position
            sub si, 80
            cmp game_map[si], wall
            je w_dont_go
            call clear_place_player
            sub player_position, 80

            w_dont_go:
                call draw_game_objects
                jmp game_cycle

        a_pressed:
            mov si, player_position
            sub si, 2
            cmp game_map[si], wall
            je a_dont_go
            call clear_place_player
            sub player_position, 2

            a_dont_go:
                call draw_game_objects
                jmp game_cycle   

        s_pressed:
            mov si, player_position
            add si, 80
            cmp game_map[si], wall
            je s_dont_go
            call clear_place_player
            add player_position, 80

            s_dont_go:
                call draw_game_objects
                jmp game_cycle

        d_pressed:
            mov si, player_position
            add si, 2
            cmp game_map[si], wall
            je d_dont_go
            call clear_place_player
            add player_position, 2

            d_dont_go:
                call draw_game_objects
                jmp game_cycle

    mov ax, 4C00h
    int 21h
end start    
