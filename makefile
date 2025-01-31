#Instruccion que indica el compilador
CXX = g++

#CXXFLAGS: Indica los includes a utilizar en la compilacion del programa
#Instruccion -Wall: Indica que queremos mostrar los warning 
#Instruccion -std=c++17: La version de C++ que estamos usando
#Instruccion -I include: Indica que estemos usando la carpeta Include dentro del proyecto
#Instruccion -I"C:/...": Indica la biblioteca externa que se esta usando 
CXXFLAGS = -Wall -std=c++20 -Iinclude -I"C:/SDL2-2.24.2/include"

#LDFLAGS Indica las librerias para compilar los header de los include de las bibliotecas externas
#Instruccion -L"C:/": Indica la ruta donde se encuentra las librerias
#Instruccion -l...: Son los linkers para vincular las librerias
LDFLAGS = -L"C:/SDL2-2.24.2/lib/x64" -lSDL2main -lSDL2

#SRC: Indica los .cpp que estamos utilizando en el programa
SRC = main.cpp src/snake.cpp src/food.cpp src/vector2.cpp

#OBJ: Convierte todos los .cpp que encuentre en archivos .o
OBJ = $(SRC:.cpp=.o)

#TARGET: El nombre que se le asiganara a nuestro ejecutable 
TARGET = main

#all: Seleccionar el TARGET 
all:$(TARGET)

#Instruccion de compilacion con el comando: make
# main main.o rectangle.o
#	g++ main.o rectangle.o -o main -L(libs)
$(TARGET) : $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#Limpiar el proyecto con el comando: make clean
clean:
	del /F /Q *.o $(TARGET)

# Regla por defecto para ejecutar el Makefile
.PHONY: all clean

#Ejecutar el proyecto con el comando: make run
run:
	./main