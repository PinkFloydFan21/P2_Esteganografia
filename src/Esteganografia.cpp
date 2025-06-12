#include <iostream>
#include <string>
#include <stdexcept>
#include "../include/Esteganografia.h"
#include "../include/Codificador.h"
#include "../include/Decodificador.h"
#include "../include/TextoABits.h"

const int tamañoMaxRuta = 255;

ImagenPNG Esteganografia::cargarImagen(std::string &ruta){
  try{
    ImagenPNG imagen(ruta);
      std::cout << std::endl;
      std::cout << "\033[32mImagen cargada desde\033[0m: " << ruta << std::endl;
      std::cout << std::endl;
    return imagen;
  } catch (const std::exception &e){
    throw std::runtime_error("\033[31mError al cargar la imagen desde " + ruta + ", " + e.what() + "\033[0m");
  }
}

Texto Esteganografia::cargarTexto(std::string &ruta){
  try{
    Texto texto(ruta);
    std::cout << "Texto cargado desde " << ruta << std::endl;
    return texto;
  }catch (const std::exception &e){
    throw std::runtime_error("\033[31mError al cargar el texto desde " + ruta + ", " + e.what()+ "\033[0m");
  }
}

bool verifica(int &opcion) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Entrada no válida. Por favor, introduce un número.\n";
        std::cout << std::endl;
        return false;
    }
    return true;
}

void Esteganografia::menu() {
    Texto texto;
    ImagenPNG imagen;
    int opcion = 0;

    std::string rutaImagen;
    std::string rutaTexto;
    std::string rutaImagenDecodificar;
    std::string nombretxt;
    std::string nombrePNG;

    while(opcion !=3) {
        std::cout << std::endl;
        std::cout << "\033[33m===== Programa de Esteganografía por el método LSB =====\n";
        std::cout << "1. Codificar Mensaje en Imagen\n";
        std::cout << "2. Decodificar Mensaje de Imagen\n";
        std::cout << "3. Salir\n";
        std::cout << "Selecciona una opción:\n\033[0m";
        std::cout << std::endl;

        std::cin >> opcion;
        if (!verifica(opcion)) {
            continue;
        }

        switch (opcion) {
            case 1:
                std::cout << std::endl;
                std::cout << "Ingresa la ruta de la imagen: ";
                std::cin >> rutaImagen;
                if (rutaImagen.size() > tamañoMaxRuta) {
                    std::cerr << "Error: La ruta de la imagen es demasiado larga." << std::endl;
                    break;
                }
                std::cout << "Ingresa la ruta del archivo .txt con el texto a encriptar: ";
                std::cin >> rutaTexto;
                if (rutaTexto.size() > tamañoMaxRuta) {
                    std::cerr << "Error: La ruta del archivo txt es demasiado larga." << std::endl;
                    break;
                }

                try {
                    imagen = cargarImagen(rutaImagen);
                    texto = cargarTexto(rutaTexto);
                    std::cout << std::endl;
                    std::cout << "Ingresa el nombre que deseas que tenga tu imagen codificada: ";
                    std::cin >> nombrePNG;
                    if (nombrePNG.size() > tamañoMaxRuta) {
                        std::cerr << "Error: EL nombre de la imagen es demasiado largo" << std::endl;
                        break;
                    }

                    Codificador::encode(imagen, texto, nombrePNG);
                    std::cout << std::endl;
                    std::cout << "\033[32mMensaje codificado. Imagen guardada como\033[0m " << nombrePNG << ".png\n";
                    std::cout << "\033 Visita la ruta ../resultados/" << nombrePNG <<
                            ".png para recuperar la imagen con el texto encriptado\033[0m" << std::endl;
                } catch (const std::exception &e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case 2:
                std::cout << std::endl;
                std::cout << "Ingresa la ruta de la imagen de la cual decodificar el mensaje: ";
                std::cin >> rutaImagenDecodificar;
                if (rutaImagenDecodificar.size() > tamañoMaxRuta) {
                    std::cerr << "Error: La ruta de la imagen es demasiado larga." << std::endl;
                    break;
                }

                std::cout << "Ingresa el nombre del archivo .txt para guardar la frase decodificada: ";
                std::cin >> nombretxt;
                if (rutaImagenDecodificar.size() > tamañoMaxRuta) {
                    std::cerr << "Error: el nombre del archivo es demasiado largo" << std::endl;
                    break;
                }

                try {
                    imagen = cargarImagen(rutaImagenDecodificar);  // Cargar imagen

                    std::vector<std::bitset<8>> bytes = Decodificador::decode(imagen);
                    std::string mensajeDecodificado = Decodificador::generaMensaje(bytes);
                    Decodificador::guardatxt(nombretxt, mensajeDecodificado);
                    std::cout << "Mensaje decodificado. Mensaje guardado como " << nombretxt << ".txt\n" ;
                    std::cout << "\033[33mVisita la ruta ../resultados/" << nombretxt << ".txt para recuperar tu txt con el mensaje decodificado.\033[0m" << std::endl;

                } catch (const std::exception &e) {
                    std::cerr << e.what() << std::endl;  // Manejar excepciones
                }
                break;

            case 3:
                std::cout << "Saliendo del programa...\n";
                break;

            default:
                std::cout << "\033[31mOpción no válida, intenta de nuevo.\n\033[0m";
                break;
        }
    }

}