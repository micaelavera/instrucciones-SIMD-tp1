#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);


void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant)
{
    for(int i=0;i<cant;i++){
        if(mask[i]!=0){ //0 si es negro - 255 si es blanco
	        a[i] = b[i];
	    }
    }
}

void abrirArchivo(char *nombreArchivo, int cantidad, unsigned char *buffer)
{
    FILE *fp;
    fp = fopen(nombreArchivo,"rb"); //r+
    if (fp == NULL){
        printf("\nError al abrir el archivo");
    }else{
    	fread(buffer,cantidad, 1, fp);   	
    }
    fclose(fp);
}

void guardarArchivo(char *nombreArchivo, int cantidad, unsigned char *buffer)
{
    FILE *fp;
    fp = fopen(nombreArchivo,"wb"); //rb
    fwrite(buffer,cantidad, 1, fp);
    fclose(fp);
}

// Main
int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        printf("Error al ingresar los parametros\n");
        return 1;
    }
    
    //Parametros
    //argv[0] =  Ejecutable
    char *imagen1 = argv[1]; //imagen1
    char *imagen2 = argv[2]; //imagen2
    char *mask = argv[3]; //mascara
    int ancho = atoi(argv[4]); //para pasar el argumento a int 
    int alto = atoi(argv[5]); //para pasar el argumento a int
    
    int cantidadxPixel = 3; //RGB 3 bytes por pixel
    int cant = ancho * alto * cantidadxPixel;

    clock_t inicio_c, fin_c , inicio_asm, fin_asm;
    
    //Inicializamos los buffers
    unsigned char *a = malloc(cant);
    unsigned char *a_asm = malloc(cant);
    unsigned char *b = malloc(cant);
    unsigned char *mascara = malloc(cant);

    //Abrimos las imagenes
    abrirArchivo(imagen1, cant, a);
    abrirArchivo(imagen1, cant, a_asm);
    abrirArchivo(imagen2, cant, b);
    abrirArchivo(mask, cant, mascara);
    
    inicio_c = clock();
    enmascarar_c(a, b, mascara, cant);
    fin_c = clock();
    guardarArchivo("salida_c.rgb", cant, a);
    
    inicio_asm = clock();
    enmascarar_asm(a_asm, b, mascara, cant);
    fin_asm = clock();
    guardarArchivo("salida_asm.rgb", cant, a_asm);

    double tiempoFinal_c = (double) (fin_c - inicio_c)/CLOCKS_PER_SEC;
    double tiempoFinal_asm = (double) (fin_asm - inicio_asm)/CLOCKS_PER_SEC;
    
    printf("Cantidad:%d , Tiempo en C:%f , Tiempo en Assembler:%f\n",cant, tiempoFinal_c, tiempoFinal_asm);

    free(a);
    free(b);
	free(mascara);

    return 0;
}
