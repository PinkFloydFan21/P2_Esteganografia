//
// Created by yahir on 26/10/24.
//

#ifndef TEXTOABITS_H
#define TEXTOABITS_H
#include <bitset>
#include <string>
#include <vector>

class Texto {
private:
    int tamaño; ///< Tamaño del mansaje
    std::string mensaje; ///< Mensaje que contiene el texto
    std::vector<std::bitset<8>> mensajeBits; ///< Mensaje convertido a Bytes

public:
    /**
    * @brief Constructor de la clase Texto
    * @param rutaTXT Dirección de guardado del archivo txt a leer
    */
    Texto(const std::string& rutaTXT);

    /**
    * @brief Constructor default de la clase.
    */
    Texto();

    /**
    *  @brief Convierte el texto del archivo txt en un mensaje string
    *  @param rutaTXT Dirección de guardado del archivo txt a leer
    *  @return Mensaje del archivo txt en un string
    */
    static std::string A_string(const std::string& rutaTXT);

    /**
    * @brief Convierte el mensaje string en un vector de bytes
    * @return Mensaje del archivo txt en un vector de bytes
    */
    std::vector<std::bitset<8>> convierteABytes();

    /**
    *  @brief Regresa el tamaño del mensaje String
    *  @return Tamaño del mensaje String
    */
    int getTam() const;

    /**
    * @brief Obtiene el tamaño del mensaje en bits.
    * @return Tamaño del mensaje en bits.
    */
    int getTamBits() const;

    /**
    * @brief Retorna el mensaje string
    * @return Mensaje string
    */
    std::string getMensaje();

    /**
    * @brief Verifica si el ruta del archivo txt es correcta
    * @param rutaTXT Dirección de guardado del archivo txt a leer
    * @return True si el archivo si se pudo abrir
    */
    static bool open_txt(const std::string& rutaTXT);

    /**
    * @brief Verífica la extension del archivo dado es formato txtue
    * @param extension Del formato de archivo
    * @return True si el archivo es fomato .txt
    */
    static bool esFormatoTXT(const std::string& extension);

    /**
    * @brief Obtiene la extension del archivo en la ruta especificada
    * @param rutaArchivo Direccion del archivo txt
    * @return String con la extension del archivo
    */
    static std::string obtenerExtension(const std::string& rutaArchivo);

    /**
    * @brief Revisa si el archivo txt no contiene ningun mensaje
    * @param rutaArchivo Direccion del archivo txt
    * @return True si el archivo txt no contiene ningun texto
    */
    static bool estaVacio(const std::string& rutaArchivo);
};
#endif //TEXTOABITS_H
