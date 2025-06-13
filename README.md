# Proyecto 02, Esteganografia

Repositorio para el Proyecto 02 de Modelado y Programación.

Prof. José Galaviz Casas.

Este proyecto consiste en un encriptador/desencriptador de texto escondido en imágenes (Esteganografia), por el metodo
LSB (Least Significant Bit).

## Integrantes

+ Oscar Yahir Hernandez Garcia 
+ Said Apis Lorenzana 
+ Gerardo Gael Sandoval Sandoval 

## Descripción

Proyecto 2, programa desarrollado en C++ que implementa la esteganografía por el metodo LSB.

## Instalacion del Proyecto

Para configurar el entorno de desarrollo, sigue estos pasos:

1. **Clona el repositorio:**

   ```Bash
   git clone https://github.com/PinkFloydFan21/P2_Esteganografia.git
   cd P2_Esteganografia/
   ```
2. **Instala las dependencias:**
   
   Las dependencias usadas para el desarrollo de este programa, fueron:
    +  **opencv4** para poder trabajar con imagenes como bits.
    +  **gtest** para implementar pruebas del codigo.
    
    Estas dependencias se instalan automáticamente cuando se corra el siguiente comando:
   
    **IMPORTANTE: Se debe de tener instalada la última versión de [cMake](https://cmake.org/download/) antes de correr el comando**
    ```bash
    chmod +x run.sh
    ./run.sh
    ```
    este comando ejecuta la opción de correr test o el programa principal.
    
    Si se desea desinstalar las dependencias instaladas para este programa, solo hace falta ejecutar el 
    siguiente comando:
    ```bash
    chmod +x uninstall.sh
    ./uninstall.sh
    ```
    Este comando desinstalará las dependencias antes mencionadas.

## Uso correcto del programa
Para que el programa trabaje correctamente con los archivos que se manipularán, se debe de
ingresar la ruta absouluta del archivo a manipular, ejemplo,
si se quiere modificar el archivo *imagen.png*, se debe de ingresar la ruta absoluta del archivo
de la siguiente manera:
```bash
/home/usuario/documentos/imagen.png
```
Si las imágenes proporcionadas se encuentran dentro de la carpeta **Proyecto2_Eteganografia**,
sólo hace falta proporcionar la ruta de la siguiente manera:
```bash
../<carpeta del proyecto donde se encuentra la imagen>/imagen.png
```

