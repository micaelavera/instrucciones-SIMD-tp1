;%include "io.inc"

section .text
global enmascarar_asm

enmascarar_asm:
    push ebp ;apunta a la base de la pila
    mov ebp, esp 
    
    
    
    ciclo:
    ;void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
    
    mov eax,[ebp+8]  ;puntero a imagen a
  
    mov eax,[ebp+12]  ;puntero a imagen b
    
    mov eax,[ebp+16] ;puntero a mask
   
    mov edx,[ebp+20]  ;puntero a cant
   
    mov esp, ebp ;restaura la pila
    pop ebp 
    ret
    
    
    