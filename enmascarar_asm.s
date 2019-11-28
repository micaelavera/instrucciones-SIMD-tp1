;%include "io.inc"

section .data
    cantidad dd 0
    
section .text
    global enmascarar_asm
   
enmascarar_asm:
    push ebp ;apunta a la base de la pila
    mov ebp, esp 
    
    ;void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
    mov ecx, 0 ;contador
  
    mov edx,[ebp+20] ;apunta a cant
    mov [cantidad],edx
    
  ciclo:
    cmp ecx, [cantidad]  
    je salir
    
    ;parametros
    mov eax,[ebp+8]  ;imagen a
    movq mm0,[eax+ecx] 
   
    mov eax,[ebp+12]  ;imagen b
    movq mm1,[eax+ecx]
    
    mov eax,[ebp+16] ;mascara
    movq mm2,[eax+ecx]

   
    pand mm1, mm2 ;mantiene la imagen b cuando el pixel es negro 
    pandn mm2, mm0 ;mantiene la imagen a cuando el pixel es distinto de FFFFFF
    por mm1, mm2
       
    ;debe devolver la imagen a - combinada con a y b 
    mov eax,[ebp+8]
    movq [eax+ecx], mm1
 
    add ecx, 8 ; manejamos registros de mmx , se desplaza de a 64 bits
    jmp ciclo
    
   salir:
    mov esp, ebp ;restaura la pila
    pop ebp 
    ret