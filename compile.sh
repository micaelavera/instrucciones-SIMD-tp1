nasm -f elf32 enmascarar_c.s -o enmascarar_c.o;
gcc -m32 -o main enmascarar_c.o enmascarar_c.c;
