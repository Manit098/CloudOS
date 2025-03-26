[BITS 16]  ; Real mode
[ORG 0x7C00]

start:
    cli                     ; Disable interrupts
    xor ax, ax              ; Zero out segment registers
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00          ; Set stack

    ; Load kernel (assume it's at 0x1000)
    mov bx, 0x1000
    call load_kernel

    ; Switch to 32-bit protected mode
    call enable_protected_mode

    jmp $

load_kernel:
    ; Stub function: Normally loads kernel from disk
    ret

enable_protected_mode:
    mov eax, cr0
    or eax, 1               ; Set PE (Protection Enable) bit
    mov cr0, eax
    jmp 0x08:protected_mode ; Jump to 32-bit mode

[BITS 32]
protected_mode:
    mov ax, 0x10            ; Set data segment
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov esp, 0x90000        ; Set up stack

    call kernel_main        ; Jump to kernel

    hlt                     ; Halt if kernel returns

times 510-($-$$) db 0       ; Pad to 512 bytes
dw 0xAA55                   ; Boot sector signature
