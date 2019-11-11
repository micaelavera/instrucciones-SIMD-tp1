#include <stdio.h>


void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);
void enmascarar_asm(unsigned char *a, unsigned char *b, unsigned char *mask, int cant);


void enmascarar_c(unsigned char *a, unsigned char *b, unsigned char *mask, int cant){
}


void cargarArchivo(char *nombreArchivo){
    FILE *fp;
    fp = fopen(nombreArchivo,"r+"); //rb
    
    fclose(fp);

}

void guardarArchivo(char *nombreArchivo,){

}

// Main
int main(int argc, char *argv[]){

    if (argc != 4){
        printf("Error al ingresar los parametros\n");
        return 1;
    }

    char *imagen1 = argv[1];
    char *imagen2 = argv[2];
    char *mask = argv[3];
    //int ancho = 
    //int alto =
    //int cant = ancho * alto

    //FILE *fpA = fopen(archivo_a,"r+");
    //FILE *fpB = fopen(archivo_b,"r+");
    //FILE *mask = fopen(mask,"r+");
    cargarArchivo(imagen1); //cambiar 
    cargarArchivo(imagen2);
    cargarArchivo(mask);

    //VER

    //fread Lee datos desde fichero.
    //fread(void *datos, size_t tamaño, size_t cantidad, FILE *fichero);
   
    
    //enmascarar_c(a,b,mask,cant);


}
