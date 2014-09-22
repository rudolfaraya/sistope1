#ifndef VECTORES_H
#define VECTORES_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector <string> buscarRepetidas (vector <string> vector_palabras);
vector <string> buscarRepetidasDos (vector <string> vector_palabras_1, vector <string> vector_palabras_2);
void imprimeVector (vector <string> vector_palabras);
void Tokenize(const string& str, vector <string>& tokens, const string& delimiters);

#endif
