#include <stdio.h>
#include <stdlib.h>

void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);


void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant)
{
    for(int i=0;i<cant;i++){
	//printf("Pixel:%d",mask[i]); //0 si es negro - 255 si es blanco
        if(mask[i]!=0){
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

//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

void guardarArchivo(char *nombreArchivo,int cantidad, unsigned char *buffer)
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

    //Inicializamos los buffers
    unsigned char *a = malloc(cant);
    unsigned char *b = malloc(cant);
    unsigned char *mascara = malloc(cant);

    //Abrimos las imagenes
    abrirArchivo(imagen1, cant, a);
    abrirArchivo(imagen2, cant, b);
    abrirArchivo(mask, cant, mascara);
    
    enmascarar_c(a, b, mascara, cant);
    guardarArchivo("salida_c.rgb", cant, a);

    return 0;
}
