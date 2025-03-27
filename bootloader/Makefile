[BITS 16]
[ORG 0x7C00] 

; Set Video Mode (80x25 Text Mode)
mov ah, 0x00
mov al, 0x03
int 0x10

; Centered text (QTMOS)
mov si, msg_qtmos
call print_centered

; Move cursor to (row 15, col 30)
mov dh, 15
mov dl, 30
call move_cursor

; Print "Booting QTMOS For You..."
mov si, msg_booting
call print_string

; Infinite Loop (Halt Execution)
jmp $

; Print centered text function
print_centered:
    push si
    call str_length
    mov cx, 40
    sub cx, ax
    shr cx, 1
    mov dh, 10
    mov dl, cl
    call move_cursor
    pop si
    call print_string
    ret

; Print string function
print_string:
    mov ah, 0x0E
.loop:
    lodsb
    or al, al
    jz .done
    int 0x10
    jmp .loop
.done:
    ret

; Move cursor function
move_cursor:
    mov ah, 0x02
    mov bh, 0x00
    int 0x10
    ret

; String length function
str_length:
    mov ax, 0
.loop:
    cmp byte [si+ax], 0
    je .done
    inc ax
    jmp .loop
.done:
    ret

msg_qtmos db "QTMOS", 0
msg_booting db "Booting QTMOS For You...", 0

times 510-($-$$) db 0 
dw 0xAA55
