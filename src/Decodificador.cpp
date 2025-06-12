#include "../include/Decodificador.h"
#include "../include/ImagenPNG.h"
#include <filesystem>
#include <fstream>   // Para manejar archivos
#include <string>

std::string Decodificador::generaMensaje(std::vector<std::bitset<8>> &bytes) {
    std::vector<std::bitset<8>> mensajeCode = bytes;
    std::string mensaje;
    mensaje.reserve(bytes.size());

    for (std::bitset<8> &byte : bytes) {
        mensaje.push_back(bytesCaracter(byte));
    }

    return mensaje;
}

char Decodificador::bytesCaracter(const std::bitset<8> &byte) {
    return static_cast<char> (byte.to_ulong());
}

std::vector<std::bitset<8> > Decodificador::decode(const ImagenPNG &imagen) {
    std::vector<std::bitset<8>> bytes;
    cv::Mat PNG = imagen.getPNG();

    if (!imagen.isRGBA()) {
        throw std::runtime_error("La imagen debe ser en formato RGBA.");
    }
    int length = imagen.getBytes();

    for (int i = 0; i < length; i+=8) {
        if (i + 7 >= (PNG.total() * PNG.elemSize())) {
            break;
        }
        std::bitset<8> byte = generaByte(i, PNG);
        if (verificaFinal(byte)) {
            break;
        }
        bytes.push_back(byte);
    }
    return bytes;
}

std::bitset<8> Decodificador::generaByte(int i, cv::Mat &PNG) {
    std::bitset<8> byte;
    for (int j = 0; j < 8; j++) {
        byte.set(j, (PNG.data[i + j] & 1) != 0);
    }
    return byte;
}

bool Decodificador::verificaFinal(std::bitset<8> &byte) {
    if (byte.to_ulong() == 0) {
        return true;
    }
    return false;
}

void Decodificador::guardatxt(std::string &nombreFile, std::string mensaje) {
    std::string validos = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";
    if (nombreFile.find_first_not_of(validos) != std::string::npos) {
        throw std::runtime_error("El nombre del archivo contiene caracteres no permitidos.");
    }
    std::string rutaTxt = "../resultados/" + nombreFile + ".txt";
    std::filesystem::create_directories("../resultados/");
    std::ofstream archivo(rutaTxt);
    if (archivo.is_open()) {
        archivo << mensaje;
        archivo.close();
    } else {
        throw std::runtime_error("Error al guardar archivo");
    }
}




