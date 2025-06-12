#include <iostream>
#include <gtest/gtest.h> // Asegúrate de instalar GTest: sudo apt-get install libgtest-dev
#include <vector>
#include <bitset>
#include <fstream>

#include "../include/Codificador.h"
#include "../include/Decodificador.h"
#include "../include/ImagenPNG.h"
#include "../include/TextoABits.h"

TEST(FormatoCorrecto_TestImagenPNG, PNGFormatoValido) {
    std::string fileName = "test_imagen.png";
    EXPECT_TRUE(ImagenPNG::esFormatoImagenSoportado(fileName));
}

TEST(FormatoCorrecto_TestImagenPNG, FormatoInvalidoRT) {
    std::string fileName = "test_imagen.rt";
    EXPECT_FALSE(ImagenPNG::esFormatoImagenSoportado(fileName));
}

TEST(FormatoCorrecto_TestImagenPNG, FormatoInvalidoTTT) {
    std::string fileName = "test_imagen.ttt";
    EXPECT_FALSE(ImagenPNG::esFormatoImagenSoportado(fileName));
}

TEST(FormatoCorrecto_TestImagenPNG, FormatoInvalidoTSST) {
    std::string fileName = "test_imagen.tsst";
    EXPECT_FALSE(ImagenPNG::esFormatoImagenSoportado(fileName));
}

TEST(FormatoCorrecto_TestImagenPNG, FormatoDobleExtensionValida) {
    std::string fileName = "test_imagen.txt.text";
    EXPECT_FALSE(ImagenPNG::esFormatoImagenSoportado(fileName));
}

TEST(FormatoCorrecto_TestImagenPNG, FormatoSinExtension) {
    std::string fileName = "test_imagen.";
    EXPECT_FALSE(ImagenPNG::esFormatoImagenSoportado(fileName));
}

TEST(Extension_TestImagenPNG, ExtensionMPM) {
    std::string fileName = "test_imagen.mpm";
    EXPECT_EQ(ImagenPNG::obtenerExtension(fileName), "mpm");
}

TEST(Extension_TestImagenPNG, ExtensionTEXT) {
    std::string fileName = "test_imagen.txt";
    EXPECT_EQ(ImagenPNG::obtenerExtension(fileName), "txt");
}

TEST(Extension_TestImagenPNG, SinExtension) {
    std::string fileName = "test_imagen";
    EXPECT_EQ(ImagenPNG::obtenerExtension(fileName), "");
}

TEST(Extension_TestImagenPNG, ExtensionFT) {
    std::string fileName = "test_imagen.ft";
    EXPECT_EQ(ImagenPNG::obtenerExtension(fileName), "ft");
}

TEST(Extension_TestImagenPNG, ExtensionLargaNKNoMoMo) {
    std::string fileName = "test_imagen.nknomomo";
    EXPECT_EQ(ImagenPNG::obtenerExtension(fileName), "nknomomo");
}

TEST(Extension_TestImagenPNG, ExtensionSMOSO) {
    std::string fileName = "test_imagen.smoso";
    EXPECT_EQ(ImagenPNG::obtenerExtension(fileName), "smoso");
}

TEST(TestImagenPNG, Archivo1) {
    std::string fileName = "../test/File_test/test4.png";
    ImagenPNG imagen_png(fileName);
    EXPECT_TRUE(imagen_png.isRGBA());
    EXPECT_EQ(imagen_png.getAltura(), 16);
    EXPECT_EQ(imagen_png.getAnchura(), 16);
    EXPECT_EQ(imagen_png.getPixeles(), 256);
    EXPECT_EQ(imagen_png.getBytes(), 1024);
    EXPECT_EQ(imagen_png.getBit(), 8192);
}

TEST(TestImagenPNG, Archivo2) {
    std::string fileName = "../test/File_test/test3.jpeg";
    ImagenPNG imagen_png(fileName);
    EXPECT_TRUE(imagen_png.isRGBA());
    EXPECT_EQ(imagen_png.getAltura(), 552);
    EXPECT_EQ(imagen_png.getAnchura(), 736);
    EXPECT_EQ(imagen_png.getPixeles(), 406272);
    EXPECT_EQ(imagen_png.getBytes(), 1625088);
    EXPECT_EQ(imagen_png.getBit(), 13000704);
}

TEST(TestImagenPNG, Archivo3) {
    std::string fileName = "../test/File_test/test5.png";
    ImagenPNG imagen_png(fileName);
    EXPECT_TRUE(imagen_png.isRGBA());
    EXPECT_EQ(imagen_png.getAltura(), 16);
    EXPECT_EQ(imagen_png.getAnchura(), 16);
    EXPECT_EQ(imagen_png.getPixeles(), 256);
    EXPECT_EQ(imagen_png.getBytes(), 1024);
    EXPECT_EQ(imagen_png.getBit(), 8192);
}

TEST(Excepcion_ImagenPNG, Excepcion) {
    EXPECT_THROW({
        ImagenPNG::verificacion("no existe");
    },std::runtime_error);
}

TEST(TestAtributos_Texto, Tamaño1) {
    Texto texto("../test/File_test/test1.txt");
    EXPECT_EQ(texto.getTam(), 17);
}

TEST(TestAtributos_Texto, Tamaño2) {
    Texto texto("../test/File_test/test2.txt");
    EXPECT_EQ(texto.getTam(), 10);
}

TEST(TestAtributos_Texto, Tamaño3) {
    Texto texto("../test/File_test/test3.txt");
    EXPECT_EQ(texto.getTam(), 23);
}

TEST(TestAtributos_Texto, Tamaño4) {
    EXPECT_THROW({
        Texto texto("../test/File_test/test4.txt");
    }, std::runtime_error);
}

TEST(TestAtributos_Texto, Tamaño5) {
    Texto texto("../test/File_test/test5.txt");
    EXPECT_EQ(texto.getTam(), 8);
}

TEST(contenidoTxt_Texto, Vacio1) {
    EXPECT_FALSE(Texto::estaVacio("../test/File_test/test1.txt"));
}

TEST(contenidoTxt_Texto, Vacio2) {
    EXPECT_FALSE(Texto::estaVacio("../test/File_test/test2.txt"));
}

TEST(contenidoTxt_Texto, Vacio3) {
    EXPECT_FALSE(Texto::estaVacio("../test/File_test/test3.txt"));
}

TEST(contenidoTxt_Texto, Vacio4) {
    EXPECT_TRUE(Texto::estaVacio("../test/File_test/test4.txt"));
}

TEST(contenidoTxt_Texto, Vacio5) {
    EXPECT_FALSE(Texto::estaVacio("../test/File_test/test5.txt"));
}

TEST(mensaje_tam, prop1) {
    Texto texto("../test/File_test/test6.txt");
    EXPECT_EQ(texto.getTam(), 14);
}

TEST(mensaje_Texto, mansaje1) {
    Texto texto("../test/File_test/test1.txt");
    EXPECT_EQ(texto.getMensaje(), "Este es el Test 1");
}

TEST(mensaje_Texto, mensaje2) {
    Texto texto("../test/File_test/test2.txt");
    EXPECT_EQ(texto.getMensaje(), "Hola Mundo");
}

TEST(mensaje_Texto, mensaje3) {
    Texto texto("../test/File_test/test3.txt");
    EXPECT_EQ(texto.getMensaje(), "abcdefghijklmnopqtyiyck");
}

TEST(mensaje_Texto, mensaje4) {
    EXPECT_THROW({
        Texto texto("../test/File_test/test4.txt");
    }, std::runtime_error);
}

TEST(mensaje_Texto, mensaje5) {
    Texto texto("../test/File_test/test5.txt");
    EXPECT_EQ(texto.getMensaje(), "Prueba 5");
}

TEST(bytes_Text, prueba1) {
    Texto texto("../test/File_test/test1.txt");
    const std::vector<std::bitset<8>> bytes = texto.convierteABytes();
    EXPECT_EQ(bytes[1].to_ulong(), 115);
}

TEST(bytes_Text, prueba2) {
    Texto texto("../test/File_test/test2.txt");
    const std::vector<std::bitset<8>> bytes = texto.convierteABytes();
    EXPECT_EQ(bytes[4].to_ulong(), 32);
}

TEST(bytes_Text, prueba3) {
    Texto texto("../test/File_test/test3.txt");
    const std::vector<std::bitset<8>> bytes = texto.convierteABytes();
    EXPECT_EQ(bytes[6].to_ulong(), 103);
}

TEST(Bytes_Text, Prueba4Excepcion) {
    EXPECT_THROW({
        Texto texto("../test/File_test/test4.txt");
    }, std::runtime_error);
}

TEST(MensajeCorrecto_Decodificador, mensaje1) {
    std::string texto = "hola";
    std::vector<std::bitset<8>> msgEncript;
    for (char c : texto) {
        msgEncript.emplace_back(c);
    }

    EXPECT_EQ(Decodificador::generaMensaje(msgEncript), "hola");
}

TEST(MensajeCorrecto_Decodificador, mensaje2) {
    std::string texto = "śśśś";
    std::vector<std::bitset<8>> msgEncript;

    for (char c : texto) {
        msgEncript.emplace_back(c);
    }

    EXPECT_EQ(Decodificador::generaMensaje(msgEncript), "śśśś");
}

TEST(MensajeCorrecto_Decodificador, mensaje3) {
    std::string texto = "«««««";
    std::vector<std::bitset<8>> msgEncript;

    for (char c : texto) {
        msgEncript.emplace_back(c);
    }

    EXPECT_EQ(Decodificador::generaMensaje(msgEncript), "«««««");
}


TEST(MensajeCorrecto_Decodificador, mensaje4) {
    std::string texto = "«««««";
    std::vector<std::bitset<8>> msgEncript;

    for (char c : texto) {
        msgEncript.emplace_back(c);
    }

    EXPECT_EQ(Decodificador::generaMensaje(msgEncript), "«««««");
}


TEST(MensajeCorrecto_Decodificador, mensaje5) {
    std::string mensaje = Texto::A_string("../test/File_test/test2.txt");
    std::vector<std::bitset<8>> msgEncript;
    for (char c : mensaje) {
        msgEncript.emplace_back(c);
    }
    EXPECT_EQ(Decodificador::generaMensaje(msgEncript), "Hola Mundo");
}


TEST(MensajeCorrecto_Decodificador, mensaje6) {
    std::string mensaje = Texto::A_string("../test/File_test/test3.txt");
    std::vector<std::bitset<8>> msgEncript;
    for (char c : mensaje) {
        msgEncript.emplace_back(c);
    }
    EXPECT_EQ(Decodificador::generaMensaje(msgEncript), "abcdefghijklmnopqtyiyck");
}

TEST(GuardarTxt_Decodificador, Txt1) {
    std::string nombre = "prueba1";
    std::string msg = "Esta es la prueba 1 de guadado de archivo .txt";
    Decodificador::guardatxt(nombre, msg);
    std::ifstream archivo("../resultados/prueba1.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(GuardarTxt_Decodificador, Txt2) {
    std::string nombre = "prueba2";
    std::string msg = "abcdefghijklmnopqtyiyck";
    Decodificador::guardatxt(nombre, msg);
    std::ifstream archivo("../resultados/prueba1.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(GuardarTxt_Decodificador, Txt3) {
    std::string nombre = "prueba3";
    std::string msg = "abcdefghijklmnopqtyiyck";
    Decodificador::guardatxt(nombre, msg);
    std::ifstream archivo("../resultados/prueba1.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(Integración, Test_imagen_text1) {
    Texto texto("../test/File_test/test6.txt");
    ImagenPNG png("../test/File_test/test4.png");
    Codificador::encode(png, texto, "prep3");
    ImagenPNG png2("../resultados/prep3.png");
    std::vector<std::bitset<8>> bytes = Decodificador::decode(png2);
    std::string nombre = "prep3";
    Decodificador::guardatxt(nombre, Decodificador::generaMensaje(bytes));
    std::ifstream archivo("../resultados/prep3.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(Integración, Test_imagen_text2) {
    Texto texto("../resultados/prep3.txt");
    EXPECT_EQ(texto.getMensaje(), "ÓÓÓÓÓÓÓ");
}
TEST(Integración, Test_imagen_text3 ) {
    Texto texto("../test/File_test/test7.txt");
    ImagenPNG png("../test/File_test/test5.png");
    Codificador::encode(png, texto, "codificado");
    ImagenPNG png2("../resultados/codificado.png");
    std::vector<std::bitset<8>> bytes = Decodificador::decode(png2);
    std::string nombre = "codificado";
    Decodificador::guardatxt(nombre, Decodificador::generaMensaje(bytes));
    std::ifstream archivo("../resultados/codificado.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(Integración, Test_imagen_text4) {
    Texto texto("../resultados/codificado.txt");
    EXPECT_EQ(texto.getMensaje(), "Esta es una prueba de integración entres clases: }72msq9ZṕbK LNik S JS LJA DI3|1op1|m");
}

TEST(Integración, Test_imagen_text5 ) {
    Texto texto("../test/File_test/test8.txt");
    ImagenPNG png("../test/File_test/test3.jpeg");
    Codificador::encode(png, texto, "codificado2");
    ImagenPNG png2("../resultados/codificado2.png");
    std::vector<std::bitset<8>> bytes = Decodificador::decode(png2);
    std::string nombre = "codificado2";
    Decodificador::guardatxt(nombre, Decodificador::generaMensaje(bytes));
    std::ifstream archivo("../resultados/codificado2.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(Integración, Test_imagen_text6) {
    Texto texto("../resultados/codificado2.txt");
    EXPECT_EQ(texto.getMensaje(), "1823h1ZZ<<>XZXXZZA•ẞ×•ß••×ẞßſſſ€@··¬|¬@|@·~·~½ſßðæ\n·@~·~@½ð¢ @·@~~½·~¬~½¶ŧ←{¬↓→→{[↓→{[½¬←½~¬~←¬½~¬½←~←¬~");
}

TEST(Integración, Test_imagen_text7 ) {
    Texto texto("../test/File_test/test9.txt");
    ImagenPNG png("../test/File_test/test3.jpeg");
    Codificador::encode(png, texto, "codificado3");
    ImagenPNG png2("../resultados/codificado3.png");
    std::vector<std::bitset<8>> bytes = Decodificador::decode(png2);
    std::string nombre = "codificado3";
    Decodificador::guardatxt(nombre, Decodificador::generaMensaje(bytes));
    std::ifstream archivo("../resultados/codificado3.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(Integración, Test_imagen_text8) {
    Texto texto("../resultados/codificado3.txt");
    EXPECT_EQ(texto.getMensaje(), "¡¡||@·~½¬{[]}ẞÐĐŊĦÆẞÐĐŊĦŁ~«»¢„“¢„“”•Łĸ→↓←Ŧ¶€S@<»đŋ←↓→øĸµ”“„¢»ßæß€ð¶đŧŋ←ħ↓“„¢»ß");
}

TEST(Integración, Test_imagen_text9 ) {
    Texto texto("../test/File_test/test10.txt");
    ImagenPNG png("../test/File_test/test4.png");
    Codificador::encode(png, texto, "codificado4");
    ImagenPNG png2("../resultados/codificado4.png");
    std::vector<std::bitset<8>> bytes = Decodificador::decode(png2);
    std::string nombre = "codificado4";
    Decodificador::guardatxt(nombre, Decodificador::generaMensaje(bytes));
    std::ifstream archivo("../resultados/codificado4.txt");
    EXPECT_TRUE(archivo.good());
}

TEST(Integración, Test_imagen_text10) {
    Texto texto("../resultados/codificado4.txt");
    EXPECT_EQ(texto.getTam(), 57);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}