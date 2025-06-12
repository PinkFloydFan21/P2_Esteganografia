#ifndef ESTEGANOGRAFIA_H
#define ESTEGANOGRAFIA_H

#include <string>
#include <bitset>
#include <opencv2/opencv.hpp>
#include "ImagenPNG.h"
#include "TextoABits.h"

class Esteganografia {
public:

  ImagenPNG cargarImagen(std::string &ruta);

  Texto cargarTexto(std::string &ruta);

  void menu();

};

#endif // ESTEGANOGRAFIA_H
