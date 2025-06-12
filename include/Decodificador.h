//
// Created by yahir on 26/10/24.
//

#ifndef DECODIFICADOR_H
#define DECODIFICADOR_H

#include <bitset>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>
#include "ImagenPNG.h"

/**
 * @class Decodificador
 * @brief Metodo que decodifica el mensaje dentro de una imagen modificada con el metodo LSB de esteganografia
 */
class Decodificador {
    public:

    /**
     * @brief Guarda el mansaje en un archivo .txt
     * @param nombreFile El nombre del archivo txt
     * @param mensaje Texto que se guardara
     */
    static void guardatxt(std::string &nombreFile, std::string mensaje);

    /**
     * @brief Genera un mensaje en string después de convertirlo de bytes a string
     * @param bytes bytes que representan caracteres.
     * @return Mensaje decodificado de bytes a string.
     */
    static std::string generaMensaje(std::vector<std::bitset<8> > &bytes);

    /**
     * @brief genera un caracter a partir de un byte
     * @param byte conjunto de bit que representan el btes de un carcter
     * @return bytes transformado en caracter
     */
    static char bytesCaracter(const std::bitset<8>& byte);

    /**
     * @brief Decodifica el mensaje de una imagen manipulada con Esteganografia
     * @param imagen Objeto imagen de clase ImagenPNG
     * @return Vector de bytes que representan un mensaje
     */
    static std::vector<std::bitset<8>> decode(const ImagenPNG &imagen);

    /**
     * @brief Verifica que el byte recibido no es el caracter nulo
     * @param byte Byte a verificar
     * @return True si el byte recibido en el caracter nulo representado como "00000000"
     */
    static bool verificaFinal(std::bitset<8>& byte);

    /**
     * @brief Genera un bytes a partir de
     * @param i Posición que itera en los datos de la imagen
     * @param PNG Matriz de la imagen png
     * @return Caracter representado como byte
     */
    static std::bitset<8> generaByte(int i, cv::Mat &PNG);
};
#endif //DECODIFICADOR_H
