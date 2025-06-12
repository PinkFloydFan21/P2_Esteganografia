#!/bin/bash

# Función para desinstalar OpenCV
uninstall_opencv() {
    echo "Desinstalando OpenCV..."

    if [ -f /etc/debian_version ]; then
        sudo apt-get remove --purge -y libopencv-dev
    elif [ -f /etc/fedora-release ]; then
        sudo dnf remove -y opencv-devel
    elif [ -f /etc/arch-release ]; then
        sudo pacman -Rns opencv
    elif [ -f /etc/SuSE-release ]; then
        sudo zypper remove -y opencv-devel
    else
        echo "Distribución no soportada para la desinstalación de OpenCV."
        exit 1
    fi
}

# Función para desinstalar Google Test
uninstall_gtest() {
    echo "Desinstalando Google Test..."

    if [ -f /etc/debian_version ]; then
        sudo apt-get remove --purge -y libgtest-dev
    elif [ -f /etc/fedora-release ]; then
        sudo dnf remove -y gtest-devel
    elif [ -f /etc/arch-release ]; then
        sudo pacman -Rns googletest
    elif [ -f /etc/SuSE-release ]; then
        sudo zypper remove -y gtest-devel
    else
        echo "Distribución no soportada para la desinstalación de Google Test."
        exit 1
    fi
}

# Desinstala OpenCV si está instalado
if pkg-config --exists opencv4; then
    uninstall_opencv
else
    echo "OpenCV no está instalado."
fi

# Desinstala Google Test si está instalado
if [ -f /etc/debian_version ]; then
    if dpkg -l | grep -q libgtest-dev; then
        uninstall_gtest
    else
        echo "Google Test no está instalado."
    fi
elif [ -f /etc/fedora-release ]; then
    if rpm -q gtest-devel &> /dev/null; then
        uninstall_gtest
    else
        echo "Google Test no está instalado."
    fi
elif [ -f /etc/arch-release ]; then
    if pacman -Qq | grep -q googletest; then
        uninstall_gtest
    else
        echo "Google Test no está instalado."
    fi
elif [ -f /etc/SuSE-release ]; then
    if zypper se -i gtest-devel &> /dev/null; then
        uninstall_gtest
    else
        echo "Google Test no está instalado."
    fi
fi

echo "Desinstalación completa."
