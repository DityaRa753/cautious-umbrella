%include "stud_io.inc"

global _start

section .bss
array resb 256

section .text
; ...
    mov ecx, 256    ; number of item per counter
    mov edi, array  ; array addres in EDI
    mov esi, array
    mov ebp, 0
    mov al, '@'     ; required code in bytes AL
again: mov [edi], al; enter code into next element
    inc edi         ; incremet addres
    dec ecx         ; decrement counter ecx
    jnz again       ; if there not null, then repeat loop
frloop: PUTCHAR [esi]
    inc esi
    inc ebp
    cmp ebp, 256
    jl frloop
    PUTCHAR 10
    FINISH
    
