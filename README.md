# Enmascarar imágenes

## Descripción
Este proyecto consiste en el desarrollo de una aplicación de línea de comandos que combine dos imágenes usando una máscara de selección. El mismo tiene como objetivo comparar la performance de las instrucciones SIMD con las instrucciones aritméticas y lógicas de la ALU.  
Para esto, se implementó dos versiones de la misma operación: en **lenguaje C** y usando **instrucciones SIMD en lenguaje ensamblador**. 

La aplicación debe recibir los siguientes parámetros: _img1.rgb_ _img2.rgb_ _mascara.rgb_ _ancho alto_.

## Instalación
Clonar este repositorio y acceder a la carpeta en Linux o en Virtual Box:
```
git clone https://github.com/micaelavera/instrucciones-SIMD-tp1.git
cd instrucciones-SIMD-tp1
```

./compile.sh  

Ejecuta el archivo main y escriba a continuación los nombres, ancho y alto de los archivos correspondientes:

```
$ ./main "lago.rgb" "arbol.rgb" "mascara.rgb" 900 600`
```
## Tips
En Linux o Virtual Box para convertir un archivo rgb a jpg y viceversa, colocar en la terminal:  
```
$ gm convert -size 900x600 -depth 8 imagen1.rgb imagen2.jpg`
```

En la consola de Windows para convertir un archivo jpg a rgb:
```
> gm convert imagen1.jpg imagen2.rgb`
```

## Autora
Micaela Vera.

