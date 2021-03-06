## -----------------------------------------------------------------------------
## Estructura de Datos
## Práctica Final: Letras
##
## Makefile
## Genera los tres programas de la práctica y la documentación correspondiente
## a cada uno de los TDA creados
##
## Jose Luis Gallego Peña - A1
## -----------------------------------------------------------------------------

SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -std=c++11
CPPFLAGS = -Wall -g  -I$(INC) -c


all: documentacion $(BIN)/testdiccionario $(BIN)/letras $(BIN)/cantidad_letras
# ************ Generación de documentación ******************

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************

# Programa testdiccionario
$(BIN)/testdiccionario : $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/Diccionario.o

$(OBJ)/testdiccionario.o : $(SRC)/testdiccionario.cpp $(INC)/Diccionario.h
	$(CXX) -c -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp -I$(INC)

# Programa letras
$(BIN)/letras : $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o $(OBJ)/Bolsa_Letras.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o $(OBJ)/Bolsa_Letras.o

$(OBJ)/letras.o : $(SRC)/letras.cpp $(INC)/Diccionario.h $(INC)/Letra.h $(INC)/Bolsa_Letras.h
	$(CXX) -c -o $(OBJ)/letras.o $(SRC)/letras.cpp -I$(INC)

# Programa cantidad_letras
$(BIN)/cantidad_letras : $(OBJ)/cantidad_letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/Diccionario.o $(OBJ)/Letra.o

$(OBJ)/cantidad_letras.o : $(SRC)/letras.cpp $(INC)/Diccionario.h $(INC)/Letra.h
	$(CXX) -c -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp -I$(INC)

# TDA
$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp
	$(CXX) -c -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INC)

$(OBJ)/Letra.o : $(SRC)/Letra.cpp $(INC)/Diccionario.h
	$(CXX) -c -o $(OBJ)/Letra.o $(SRC)/Letra.cpp -I$(INC)

$(OBJ)/Bolsa_Letras.o : $(SRC)/Bolsa_Letras.cpp $(INC)/Letra.h $(INC)/Diccionario.h
	$(CXX) -c -o $(OBJ)/Bolsa_Letras.o $(SRC)/Bolsa_Letras.cpp -I$(INC)

# ************ Limpieza ************

clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm -r $(BIN)/* doc/html/*
