#!/bin/bash

# Verifica si cmake está instalado
if ! command -v cmake &> /dev/null; then
    echo "cmake no está instalado. Por favor, instálalo primero."
    exit 1
fi

# Verifica si pkg-config está instalado
if ! command -v pkg-config &> /dev/null; then
    echo "pkg-config no está instalado. Por favor, instálalo primero."
    exit 1
fi

# Función para instalar OpenCV
install_opencv() {
    echo "Instalando OpenCV..."

    if [ -f /etc/debian_version ]; then
        sudo apt-get update
        sudo apt-get install -y libopencv-dev build-essential
    elif [ -f /etc/fedora-release ]; then
        sudo dnf install -y opencv-devel
    elif [ -f /etc/arch-release ]; then
        sudo pacman -S opencv
    elif [ -f /etc/SuSE-release ]; then
        sudo zypper install opencv-devel
    else
        echo "Distribución no soportada para la instalación de OpenCV."
        exit 1
    fi
}

# Función para instalar Google Test
install_gtest() {
    echo "Instalando Google Test..."

    if [ -f /etc/debian_version ]; then
        sudo apt-get update
        sudo apt-get install -y libgtest-dev
        mkdir -p ~/gtest_build
        cd ~/gtest_build
        sudo cmake /usr/src/gtest
        sudo make
        sudo cp *.a /usr/lib
        cd -
        rm -rf ~/gtest_build
    elif [ -f /etc/fedora-release ]; then
        sudo dnf install -y gtest-devel
    elif [ -f /etc/arch-release ]; then
        sudo pacman -S googletest
    elif [ -f /etc/SuSE-release ]; then
        sudo zypper install gtest-devel
    else
        echo "Distribución no soportada para la instalación de Google Test."
        exit 1
    fi
}

# Verificar si OpenCV está instalado
if ! pkg-config --exists opencv4; then
    install_opencv
fi

# Verificar si Google Test está instalado
if [ -f /etc/debian_version ]; then
    if ! dpkg -l | grep -q libgtest-dev; then
        install_gtest
    fi
elif [ -f /etc/fedora-release ]; then
    if ! rpm -q gtest-devel &> /dev/null; then
        install_gtest
    fi
elif [ -f /etc/arch-release ]; then
    if ! pacman -Qq | grep -q googletest; then
        install_gtest
    fi
elif [ -f /etc/SuSE-release ]; then
    if ! zypper se -i gtest-devel &> /dev/null; then
        install_gtest
    fi
fi

# Crear el directorio de resultados si no existe
if [ ! -d resultados ]; then
    mkdir resultados
fi

# Verificar si el directorio build existe
if [ -d build ]; then
    read -p "El directorio 'build' ya existe. ¿Deseas recompilar? (s/n): " recompilar
    if [ "$recompilar" == "s" ]; then
        rm -rf build
        mkdir build
        cd build || exit 1
        cmake ..
        make
    else
        echo "Usando la compilación existente en 'build'."
        cd build || exit 1
    fi
else
    mkdir build
    cd build || exit 1
    cmake ..
    make
fi

# Pregunta al usuario qué desea hacer
echo "¿Qué deseas ejecutar?"
echo "1) Correr los tests"
echo "2) Ejecutar el programa principal"
read -p "Elige una opción (1 o 2): " opcion

# Ejecuta la opción seleccionada
case $opcion in
    1)
        echo "Ejecutando los tests..."
        ./Tests
        ;;
    2)
        echo "Ejecutando el programa principal..."
        ./Proyecto2_Esteganografia
        ;;
    *)
        echo "Opción no válida. Por favor, elige 1 o 2."
        ;;
esac
