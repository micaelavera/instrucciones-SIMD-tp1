# Enmascarar imágenes

## Descripción
Este proyecto consiste en el desarrollo de una aplicación de línea de comandos que combine dos imágenes usando una máscara de selección. El mismo tiene como objetivo comparar la performance de las instrucciones SIMD con las instrucciones aritméticas y lógicas de la ALU.  
Para esto, se implementó dos versiones de la misma operación: en **lenguaje C** y usando **instrucciones SIMD en lenguaje ensamblador**. 

La aplicación debe recibir los siguientes parámetros: _img1.rgb_ _img2.rgb_ _mascara.rgb_ _ancho alto_.

./compile.sh
./main "lago.rgb" "arbol.rgb" "mascara.rgb" 900 600

En la virtual para convertir de rgb a jpg y viceversa:
gm convert -size 900x600 -depth 8 salida_c.rgb salida_c.jpg


En la consola de windows para convertir jpg a rgb:
gm convert imagen1.jpg imagen2_a_renombrar.rgb
