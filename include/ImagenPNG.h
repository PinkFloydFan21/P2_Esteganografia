#ifndef IMAGENPNG_H
#define IMAGENPNG_H

#include <opencv4/opencv2/opencv.hpp> // Dependencia instalada con <sudo apt install libopencv-dev>
#include <string>

/**
 * @class ImagenPNG
 * @brief Representa una imagen en formato PNG (RGBA) con sus respectivos atributos.
 */
class ImagenPNG {
private:
    cv::Mat PNG;   ///< Imagen representada como una matriz de píxeles
    int pixeles;   ///< Cantidad de píxeles en la imagen
    int anchura;   ///< Anchura de la imagen
    int altura;    ///< Altura de la imagen
    int bytes;     ///< Cantidad de bytes que contiene la imagen
    int bit;       ///< Cantidad de bits por canal en la imagen

public:
    /**
     * @brief Constructor de la clase ImagenPNG.
     * @param ruta Ruta de almacenamiento de la imagen.
     */
    ImagenPNG(const std::string& ruta);

     /**
     * @brief Constructor default de la clase.
     */
    ImagenPNG();

    /**
     * @brief Crea un buffer de la imagen a partir de una ruta.
     * @param rutaImagen Ruta de almacenamiento de la imagen.
     * @return Imagen PNG como una matriz de píxeles.
     */
    cv::Mat imagen_PNG(const std::string& rutaImagen);

    /**
     * @brief Verifica si la ruta dada es válida y si existe la imagen.
     * @param rutaImagen Ruta de almacenamiento de la imagen.
     * @return Buffer de la imagen si la ruta es válida y existe, en cualquier formato soportado.
     */
    static cv::Mat verificacion(const std::string& rutaImagen);

    /**
     * @brief Verifica si el formato de la imagen es soportado por el programa.
     * @param extension Extensión del tipo de imagen (por ejemplo, .jpeg).
     * @return True si el formato es soportado; de lo contrario, false.
     */
    static bool esFormatoImagenSoportado(const std::string& extension);

    /**
     * @brief Obtiene la extensión del formato de la imagen.
     * @param rutaArchivo Ruta de almacenamiento de la imagen.
     * @return Extensión del formato de la imagen como un string.
     */
    static std::string obtenerExtension(const std::string& rutaArchivo);

     /**
     * @brief Guarda la imagen en formato PNG en la ruta especificada.
     * @param nombre Nombre del archivo sin extensión donde se guardará la imagen.
     * @throw std::runtime_error Si ocurre un error al intentar guardar la imagen.
     */
    void guardarImagen(const std::string& nombre);

     /**
     * @brief Verifica si la imagen contiene un canal alpha (RGBA).
     * @return true si la imagen contiene canal alpha; de lo contrario, false.
     */
    bool isRGBA() const;

    /**
     * @brief Obtiene la matriz de píxeles de la imagen PNG.
     * @return Matriz de la imagen PNG.
     */
    const cv::Mat& getPNG() const;

    /**
     * @brief Obtiene la cantidad total de píxeles de la imagen.
     * @return Cantidad de píxeles.
     */
    int getPixeles() const;

    /**
     * @brief Obtiene el ancho de la imagen.
     * @return Anchura de la imagen.
     */
    int getAnchura() const;

    /**
     * @brief Obtiene la altura de la imagen.
     * @return Altura de la imagen.
     */
    int getAltura() const;

    /**
     * @brief Obtiene la cantidad total de bytes de la imagen.
     * @return Cantidad de bytes de la imagen.
     */
    int getBytes() const;

    /**
     * @brief Obtiene la cantidad de bits por canal de la imagen.
     * @return Cantidad de bits por canal.
     */
    int getBit() const;
};

#endif // IMAGENPNG_H
