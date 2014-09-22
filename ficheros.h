#ifndef FICHEROS_H
#define FICHEROS_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "tokenizer.h"

using namespace std;

vector <string> limpiarVector(vector <string> vector_palabras);
vector <string> leerFichero(char * nombre_archivo);
void mostrarFichero (char * nombre_archivo);
void escribirFichero (char * nombre_archivo_entrada, char * nombre_archivo_salida);
int esTextoPlano(char * nombre_archivo);
string mostrarTipo (char * nombre_archivo);
void escribirResultado(char * ovalue, int oflag, char * o_value, int o_flag, char * nombre_archivo, char * nHebras, char * nProcesos, vector <string> vector_palabras);
void mostrarResultado(char * ovalue, int oflag, char * o_value, int o_flag, char * nHebras, char * nProcesos, vector <string> vector_palabras);

#endif
