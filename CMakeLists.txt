cmake_minimum_required(VERSION 3.29)
project(Proyecto2_Esteganografia)

set(CMAKE_CXX_STANDARD 20)

# Encuentra OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Agregar el ejecutable principal
add_executable(Proyecto2_Esteganografia
        src/ImagenPNG.cpp
        src/TextoABits.cpp
        include/Decodificador.h
        src/Decodificador.cpp
        include/Codificador.h
        src/Codificador.cpp
        include/Esteganografia.h
        src/Esteganografia.cpp
        src/main.cpp
)

# Crear un ejecutable para las pruebas
add_executable(Tests
        test/Test.cpp
        src/ImagenPNG.cpp   # Incluye la implementación de ImagenPNG
        src/TextoABits.cpp  # Incluye la implementación de TextoABits si es necesario
        src/Decodificador.cpp
        src/Codificador.cpp
        src/Esteganografia.cpp
)

# Añade Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Enlaza Google Test, OpenCV y pthread al ejecutable de tests
target_link_libraries(Tests ${GTEST_LIBRARIES} ${OpenCV_LIBS} pthread)

# Si deseas enlazar OpenCV al ejecutable principal también
target_link_libraries(Proyecto2_Esteganografia ${OpenCV_LIBS})
