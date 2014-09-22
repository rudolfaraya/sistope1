#include "vectores.h"


////////////////// FUNCIÓN QUE BUSCA PALABRAS REPETIDAS EN UN VECTOR DE PALABRAS /////////////////////////////////////////
vector <string> buscarRepetidas (vector <string> vector_palabras){
	int i,j,k; // iniciar contadores
	vector <string> palabras_repetidas; // vector de string que guardará cada palabra encontrada en el vector de palabras


	for(i = 0; i < vector_palabras.size(); i++){ // Se inicia el recorrido del vector de palabras
          for(j = i+1; j < vector_palabras.size(); j++){ // Se busca cada palabra repetida en el mismo vector, recorriendose a sí mismo
            if(vector_palabras[i]==vector_palabras[j]){ // Si la palabra actual es igual a la seleccionada
              
                if(!palabras_repetidas.empty()){
                int validaAgregar = 0;           // valida si encontro palabra repetida que mostrar
                int encontroPalabraRepetida = 0; // valida si la palabra encontrada ya estaba en las palabras a mostrar
                
                for(k=0;k<palabras_repetidas.size();k++){
                  
                  if(palabras_repetidas[k] == vector_palabras[j]){
                    encontroPalabraRepetida=2;
                  }
                  if(palabras_repetidas.size()-1==k && encontroPalabraRepetida!=2){
                    validaAgregar++;
                  }
                }
                if (validaAgregar == 1 ){
                  palabras_repetidas.push_back(vector_palabras[i]);
                }
                }else{
                  palabras_repetidas.push_back(vector_palabras[i]);  
                }
              
            }
          }
          
  }

    return palabras_repetidas;
}


///////////////// FUNCIÓN QUE BUSCA PALABRAS REPETIDAS ENTRE DOS VECTORES DE PALABRAS /////////////////////////////////////////
vector <string> buscarRepetidasDos (vector <string> vector_palabras_1, vector <string> vector_palabras_2){
	int i = 0,j = 0, k = 0; // iniciar contadores
	vector <string> palabras_repetidas; // vector de string que guardará cada palabra encontrada en el vector de palabras

	for(i = 0; i < vector_palabras_1.size();i ++){
          for(j = 0; j < vector_palabras_2.size();j ++){
            if(vector_palabras_1[i]== vector_palabras_2[j]){
              
              if(!palabras_repetidas.empty()){
                int validaAgregar = 0;           // valida si encontro palabra repetida que mostrar
                int encontroPalabraRepetida = 0; // valida si la palabra encontrada ya estaba en las palabras a mostrar
                
                for(k=0;k<palabras_repetidas.size();k++){
                  
                  if(palabras_repetidas[k] == vector_palabras_2[j]){
                    encontroPalabraRepetida=2;
                  }
                  if(palabras_repetidas.size()-1==k && encontroPalabraRepetida!=2){
                    validaAgregar++;
                  }
                }
                if (validaAgregar == 1 ){
                  palabras_repetidas.push_back(vector_palabras_1[i]);
                }
              }else{
                  palabras_repetidas.push_back(vector_palabras_1[i]);  
              }
              
            }
          }
          
       }

    return palabras_repetidas;
}

////////////////// FUNCIÓN QUE IMPRIME VECTOR DE PALABRAS POR PANTALLA /////////////////////////////////////////
void imprimeVector (vector <string> vector_palabras){
	int i;
	
	for(i = 0; i < vector_palabras.size();i ++){
          cout << vector_palabras[i] << endl;

  }

}
