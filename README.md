./compile.sh
./main "lago.rgb" "arbol.rgb" "mascara.rgb" 900 600

En la virtual para convertir de rgb a jpg y viceversa:
gm convert -size 900x600 -depth 8 salida_c.rgb salida_c.jpg


En la consola de windows para convertir jpg a rgb:
gm convert imagen1.jpg imagen2_a_renombrar.rgb
