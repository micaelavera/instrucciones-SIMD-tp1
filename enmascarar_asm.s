%include "io.inc"

section .text
global enmascarar_asm

enmascarar_asm:
    push ebp ;apunta a la base de la pila
    mov ebp, esp 
    
    ciclo:
    
    ;imagen1
    ;imagen2
    ;mascara
    
    mov esp, ebp ;restaura la pila
    pop ebp
    ret
    
    
    ;write your code here
    xor eax, eax
    ret