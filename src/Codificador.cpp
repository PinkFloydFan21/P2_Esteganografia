//
// Created by Said on 29/10/24.
//

#include "../include/Codificador.h"
#include <iostream>
#include <stdexcept>

void Codificador::encode(ImagenPNG &imagen, Texto &texto, const std::string& nombrePNG) {
    if(!verificaEspacio(imagen, texto)) {
        throw std::invalid_argument("El mensaje proporcionado no cabe en la imagen dada.");
    }
    cv::Mat PNG = imagen.getPNG();
    std::vector<std::bitset<8>> mensajeBytes = mensajeaBytes(texto);
    int index = 0;
    for(const std::bitset<8> &byte: mensajeBytes) {
        insertaByte(byte,index,PNG);
        index+= 8;
    }
    std::bitset<8> byteNulo(0);
    insertaByte(byteNulo,index,PNG);
    imagen.guardarImagen(nombrePNG);
}

std::vector<std::bitset<8>> Codificador::mensajeaBytes(Texto &texto) {
    return texto.convierteABytes();
}

void Codificador::insertaByte(const std::bitset<8> &byte, int &i, cv::Mat &PNG) {
    for(int j=0; j<8; j++ ) {
        int numByte = i+j;
        PNG.data[numByte] = (PNG.data[numByte] & 0xFE) | byte[j];
    }
}

bool Codificador::verificaEspacio(ImagenPNG &imagen, Texto &texto) {
    int espacioRequerido = texto.getTamBits();
    int disponible = imagen.getBytes();
    if(espacioRequerido > (disponible - 8)) {
        return false;
    }
    return true;
}


