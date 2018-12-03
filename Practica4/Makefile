SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -std=c++11
CPPFLAGS = -Wall -g  -I$(INC) -c


all: documentacion $(BIN)/pruebadiccionario
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario : $(OBJ)/pruebadiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Termino.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/Diccionario.o $(OBJ)/Termino.o

$(OBJ)/pruebadiccionario.o : $(SRC)/pruebadiccionario.cpp $(INC)/Diccionario.h
	$(CXX) -c -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp -I$(INC)

$(OBJ)/Diccionario.o : $(SRC)/Diccionario.cpp $(INC)/Termino.h
	$(CXX) -c -o $(OBJ)/Diccionario.o $(SRC)/Diccionario.cpp -I$(INC)

$(OBJ)/Termino.o : $(SRC)/Termino.cpp $(INC)/Termino.h
	$(CXX) -c -o $(OBJ)/Termino.o $(SRC)/Termino.cpp -I$(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm -r $(BIN)/* doc/html/*
