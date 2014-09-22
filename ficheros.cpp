#include "ficheros.h"

string limpiarPalabra(string palabra){
 
  for(int i = 0; i < palabra.size(); i++){
    if(palabra[i] == 32){
      cout << "el char es: " << i << "pos: " << palabra[i] << " fin" << endl;
      palabra.erase(i,1);
    }
  }
  return palabra;
}

vector <string> limpiarVector(vector <string> vector_palabras){
  
    for(int i = 0; i < vector_palabras.size(); i++){
      vector_palabras[i] = limpiarPalabra(vector_palabras[i]);
    }   
    return vector_palabras;
}

vector <string> leerFichero(char * nombre_archivo){
/////////// LECTURA DEL ARCHIVO DE ENTRADA ////////////////////////

  ifstream archivo_entrada; //objeto de flujo de archivo de entrada
  vector <string> vector_palabras; //string que guarda cada palabra del texto de entrada en forma de vector de palabras
  string linea;

  archivo_entrada.open(nombre_archivo);

  if (archivo_entrada.fail()){ //si el archivo no se pudo abrir
    cout << "\n\nEl archivo de entrada no se abrio correctamente\n\n" << endl;
    exit(0);
  }

  while(getline(archivo_entrada,linea, ' ')){
    //Tokenize (linea, vector_palabras," "); //partir cada linea en tokens, delimitador " "
    vector_palabras.push_back(linea);  
  }
  archivo_entrada.close();
  //vector_palabras = limpiarVector(vector_palabras);
  
  return vector_palabras;
}

void mostrarFichero (char * nombre_archivo){

  ifstream archivo_entrada;
  string linea;  
  archivo_entrada.open(nombre_archivo); 
  
  if (archivo_entrada.fail()){ //si el archivo no se pudo abrir
    cout << "\n\nEl archivo de entrada no se abrio correctamente\n\n" << endl;
    exit(0);
  }

  while (getline(archivo_entrada, linea))
    cout << linea << endl;

  archivo_entrada.close();

  return;
} 

void escribirFichero (char * nombre_archivo_entrada, ofstream & archivo_salida){

  ifstream archivo_entrada;
  string linea;
  
  archivo_entrada.open(nombre_archivo_entrada); 
    
  if (archivo_entrada.fail()){ //si el archivo no se pudo abrir
    cout << "\n\nEl archivo de entrada no se abrio correctamente\n\n" << endl;
    exit(0);
  }
  if (archivo_salida.fail()){ //si el archivo no se pudo abrir
    cout << "\n\nEl archivo de salida no se abrio correctamente\n\n" << endl;
    exit(0);
  }

  while (getline(archivo_entrada, linea))
    archivo_salida << linea << endl;

  archivo_entrada.close();
  
  return;
}

int esTextoPlano (char * nombre_archivo){

  ////////////////////////   ES TEXTO PLANO? //////////////////////////////////////
    // Recibe como parametro de entrada la cadena de caracteres, correspondiente al nombre archivo analizado
    // Si no es texto plano retorna 0, si lo es retorna 1
       int es_textplain;
       ifstream archivo_entrada_temporal; //objeto de flujo de archivo de entrada
       ofstream archivo_salida_temporal; //objeto de flujo de archivo de salida
       
       string linea_temporal;
       string nombre_archivo_temporal = "temporal.txt";

       string comando_file;
       string comando_file2;

       comando_file = "file -i ";
       comando_file2 = " >> temporal.txt";
       //esta string será enviado a la terminal para ejecutar el comando file para
       //obtener el tipo de archivo y verificar si es texto plano
       comando_file = comando_file + nombre_archivo + comando_file2; 
    
       archivo_salida_temporal.open(nombre_archivo_temporal.c_str());
       system(comando_file.c_str());
       
       archivo_entrada_temporal.open("temporal.txt");

       if (archivo_entrada_temporal.fail()){
           cout << "El archivo no se abrio correctamente" << endl;
           exit(0);
       }
       
       getline(archivo_entrada_temporal, linea_temporal);

       es_textplain = string(linea_temporal).find("text/plain"); //retorna >= 0 si se se encuentra el substring "text/plain" y -1 si no fue encontrado
       if(es_textplain < 0){
          archivo_entrada_temporal.close();
          archivo_salida_temporal.close();

          return 0;
       }
       archivo_entrada_temporal.close();
       archivo_salida_temporal.close();
       remove ("temporal.txt");

       return 1;
       /////////////////////////////////////////////////////////////////////////////////

} 




string mostrarTipo (char * nombre_archivo){

  ////////////////////////   MOSTRAR TIPO DE ARCHIVO PARA BANDERA -0 //////////////////////////////////////
    // Recibe como parametro de entrada la cadena de caracteres, correspondiente al nombre archivo analizado
    // Retorna el string con el tipo de archivo en su interior
       
       ifstream archivo_entrada_temporal; //objeto de flujo de archivo de entrada
       ofstream archivo_salida_temporal; //objeto de flujo de archivo de salida
       
       string tipo_archivo;
       string linea_temporal;
       string nombre_archivo_temporal = "tipo_archivo.txt";

       string comando_file;
       string comando_file2;

       comando_file = "file -i ";
       comando_file2 = " >> tipo_archivo.txt";
       //esta string será enviado a la terminal para ejecutar el comando file para
       //obtener el tipo de archivo y verificar si es texto plano
       comando_file = comando_file + nombre_archivo + comando_file2; 
    
       archivo_salida_temporal.open(nombre_archivo_temporal.c_str());
       system(comando_file.c_str());
       
       archivo_entrada_temporal.open("tipo_archivo.txt");

       if (archivo_entrada_temporal.fail()){
           cout << "El archivo no se abrio correctamente" << endl;
           exit(0);
       }
       
       getline(archivo_entrada_temporal, linea_temporal);

       tipo_archivo = linea_temporal; 
       
       archivo_entrada_temporal.close();
       archivo_salida_temporal.close();
       remove ("tipo_archivo.txt");

       return tipo_archivo;
       /////////////////////////////////////////////////////////////////////////////////

} 


////////////////////////////////////////////////////////////////////

void escribirResultado(char * ovalue, int oflag, char * o_value, int o_flag, char * nombre_archivo, char * nHebras, char * nProcesos, vector <string> vector_palabras){
////////// ESCRITURA DEL ARCHIVO DE SALIDA ////////////////////////
  ofstream archivo_salida(nombre_archivo);
  string tipo_archivo;
    
  if(oflag == 1){
    tipo_archivo = mostrarTipo(ovalue);
    archivo_salida << tipo_archivo << endl;
  }
  if(o_flag == 1){
    int es_textplain = esTextoPlano(o_value);
    if (es_textplain == 1){
      escribirFichero(o_value,archivo_salida);
    }
  }

  archivo_salida << "nHebras = " << nHebras << "\n" << "nProcesos = " << nProcesos << endl;

  for(int i = 0; i < vector_palabras.size();i ++){
    archivo_salida << vector_palabras[i] << endl;
  }    
  archivo_salida.close();
}

void mostrarResultado(char * ovalue, int oflag, char * o_value, int o_flag, char * nHebras, char * nProcesos, vector <string> vector_palabras){
/////////// MOSTRAR RESULTADO ////////////////////////
  string tipo_archivo;
  
  int i; //contadores

  if(oflag == 1){
    tipo_archivo = mostrarTipo(ovalue);
    cout << tipo_archivo << endl;
  }
  if(o_flag == 1){
    int es_textplain = esTextoPlano(o_value);
    if (es_textplain == 1){
      mostrarFichero(o_value);
    }
  }

  cout << "nHebras = " << nHebras << "\n" << "nProcesos = " << nProcesos << endl;

  for(i = 0; i < vector_palabras.size();i ++){
    cout << vector_palabras[i] << endl;
  }
    
}
