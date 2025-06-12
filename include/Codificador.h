//
// Created by Said on 28/10/24.
//

#ifndef CODIFICADOR_H
#define CODIFICADOR_H
#include <bitset>

#include "ImagenPNG.h"
#include "TextoABits.h"

//.h
/**
 * @class Codificador
 * @brief Metodo que codifica el mensaje dentro de una imagen con el metodo LSB de esteganografia
 */
class Codificador {
 public:

 /**
  * @brief Codifica un mensaje dentro de una imagen.
  * @param imagen Objeto de clase ImagenPNG donde se codificará el mensaje.
  * @param mensaje Objeto de clase Texto que contiene el mensaje a encriptar.
  * @param nombrePNG Nombre que se asignara a la imagen png modificada
  */
 static void encode(ImagenPNG &imagen, Texto &mensaje,  const std::string& nombrePNG);

 /** @brief Convierte un mensaje de string a un vector de bytes.
  * @param mensaje Objeto de clase texto que convertirá
  * @return Vector de bytes que representan el mensaje.
 **/
 static std::vector<std::bitset<8>> mensajeaBytes(Texto &mensaje);

 /**
 * @brief Inserta un byte en los bits menos significativos de la imagen.
 * @param byte Byte que representa el carácter a codificar.
 * @param i Posición que itera en los datos de la imagen.
 * @param PNG Matriz de la imagen PNG.
 */
 static void insertaByte(const std::bitset<8> &byte, int &i, cv::Mat &PNG);

 /**
  * @brief Verifica si el mensaje cabe en la imagen, basado en el número de píxeles y el tamaño del mensaje.
  * @param imagen Objeto de clase ImagenPNG donde se intentará codificar el mensaje.
  * @param texto Objeto de clase Texto que contiene el mensaje a verificar.
  * @return True si el mensaje cabe en la imagen; de lo contrario, false.
  */
 static bool verificaEspacio(ImagenPNG &imagen, Texto &texto);

};
#endif //CODIFICADOR_H
