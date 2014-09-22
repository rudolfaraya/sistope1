#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

void Tokenize(const string& str, vector <string>& tokens, const string& delimiters);

#endif
