#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/TextoABits.h"

#include <algorithm>

Texto::Texto(const std::string& rutaTXT) : mensaje(A_string(rutaTXT)){
    tamaño = mensaje.length();
    mensajeBits = convierteABytes();
}

Texto::Texto(): tamaño(0), mensajeBits(std::vector<std::bitset<8>>()){
}

std::string Texto::A_string(const std::string& rutaTXT) {
    if(rutaTXT.empty()) {
        return "";
    }
    if (open_txt(rutaTXT)
        && esFormatoTXT(Texto::obtenerExtension(rutaTXT))) {
        std::ifstream archivo(rutaTXT);
        std::stringstream buffer;
        buffer << archivo.rdbuf();
        return buffer.str();
    }
    return "";
}

bool Texto::open_txt(const std::string& rutaTXT) {
    std::ifstream txt(rutaTXT);
    if (!txt.is_open()) {
        std::cerr << "Hubo un problema: no se pudo abrir el archivo " << rutaTXT << "." << std::endl;
        return false;
    }
    return true;
}

bool Texto::esFormatoTXT(const std::string& extension) {
    std::string ext = extension;
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return ext == "txt";
}

std::string Texto::obtenerExtension(const std::string& rutaArchivo) {
    size_t pos = rutaArchivo.find_last_of('.');
    if (pos != std::string::npos) {
        return rutaArchivo.substr(pos + 1);
    }
    return ""; // Retorna cadena vacía si no se encuentra una extensión
}

std::vector<std::bitset<8>> Texto::convierteABytes() {
    std::vector<std::bitset<8>> bytes;
    if (mensaje.empty()) {
        throw std::runtime_error("El mensaje está vacío o el .txt no existe. Por favor, selecciona un .txt válido.");
    }
    if (!mensaje.empty()) {
        for (char c : mensaje) {
            bytes.emplace_back(c);
        }
    }
    return bytes;
}


bool Texto::estaVacio(const std::string& rutaArchivo) {
    if (open_txt(rutaArchivo)) {
        std::ifstream archivo(rutaArchivo);
        std::stringstream buffer;
        buffer << archivo.rdbuf();
        return buffer.str().empty();
    }
    return true;
}


int Texto::getTam() const {
    return tamaño;
}

int Texto::getTamBits() const {
    return getTam()*8;
}

std::string Texto::getMensaje() {
    return mensaje;
}



