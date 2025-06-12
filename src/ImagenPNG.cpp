#include "../include/ImagenPNG.h"
#include <stdexcept>
#include <filesystem>
using namespace std;

ImagenPNG::ImagenPNG(const string& ruta) : PNG(imagen_PNG(ruta)) {
    anchura = PNG.cols;
    altura = PNG.rows;
    pixeles = anchura * altura;
    bytes = pixeles * (isRGBA() ? 4 : 3);
    bit = bytes * 8;
}

ImagenPNG::ImagenPNG(): anchura(0), altura(0), pixeles(0), bytes(0), bit(0) {
    PNG = cv::Mat();
}

cv::Mat ImagenPNG::imagen_PNG(const string& rutaImagen) {
    cv::Mat imagenOriginal = verificacion(rutaImagen);
    cv::Mat imagenPNG;
    if (imagenOriginal.channels() == 1) {
        cvtColor(imagenOriginal, imagenPNG, cv::COLOR_GRAY2BGRA);
    } else if (imagenOriginal.channels() == 3) {
        cvtColor(imagenOriginal, imagenPNG, cv::COLOR_BGR2BGRA);
    } else if (imagenOriginal.channels() == 4) {
        imagenPNG = imagenOriginal.clone();
    } else {
        throw std::runtime_error("Formato de imagen no compatible. Por favor, selecciona una imagen en BGR, BGRA o en escala de grises.");
    }
    return imagenPNG;
}


cv::Mat ImagenPNG::verificacion(const std::string& rutaImagen) {
    try {
        if (!std::filesystem::exists(rutaImagen)) {
            throw std::runtime_error("El archivo de imagen no existe. Por favor, verifica la ruta.");
        }
        cv::Mat imagenOriginal = cv::imread(rutaImagen, cv::IMREAD_UNCHANGED);
        if (imagenOriginal.empty()) {
            throw std::runtime_error("La imagen proporcionada no contiene ningún dato. Por favor, selecciona una imagen válida.");
        }
        return imagenOriginal;
    } catch (const std::exception& e) {
        throw std::runtime_error(std::string("Ocurrió un error al cargar la imagen: ") + e.what());
    }
}

bool ImagenPNG::esFormatoImagenSoportado(const string& extension) {
    string formatosSoportados[] = {"png", "jpg", "jpeg", "bmp", "gif"};
    for (const string& formato : formatosSoportados) {
        if (formato == obtenerExtension(extension)) {
            return true;
        }
    }
    return false;
}

string ImagenPNG::obtenerExtension(const string& rutaArchivo) {
    size_t indicePunto = rutaArchivo.find_last_of('.');
    if (indicePunto != string::npos) {
        return rutaArchivo.substr(indicePunto + 1);
    }
    return "";
}

void ImagenPNG::guardarImagen(const string& nombre) {
    std::string validos = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";
    if (nombre.find_first_not_of(validos) != std::string::npos) {
        throw std::runtime_error("El nombre del archivo contiene caracteres no permitidos.");
    }
    std::filesystem::create_directories("../resultados/");
    imwrite("../resultados/"+nombre+".png", PNG);
}

bool ImagenPNG::isRGBA() const {
    return PNG.channels() == 4; // Verifica si tiene un canal alpha
}

const cv::Mat& ImagenPNG::getPNG() const {
    return PNG;
}

int ImagenPNG::getPixeles() const {
    return pixeles;
}

int ImagenPNG::getAnchura() const {
    return anchura;
}

int ImagenPNG::getAltura() const {
    return altura;
}

int ImagenPNG::getBytes() const {
    return bytes;
}

int ImagenPNG::getBit() const {
    return bit;
}
