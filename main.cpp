  #include <ctype.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <iostream>
  #include <fstream>
  #include <string>
  #include "tokenizer.h"
  #include "vectores.h"
  #include "ficheros.h"

  using namespace std;
     
     int main (int argc, char **argv){
    
      vector <string> vector_palabras; //string que guarda cada palabra del texto de entrada1 en forma de vector de palabras
      vector <string> palabras_repetidas; //string que guarda palabras repetidas
      vector <string> vector_palabras2; //string que guarda cada palabra del texto de entrada2 en forma de vector de palabras
      vector <string> palabras_repetidas2; //string que guarda palabras repetidas entre entrada1 y entrada2
              
       ////////////////////////   INICIO GETOPT   ////////////////////////////////////////////
       
       //------------------------- BANDERAS --------------------------------------------------
       int oflag = 0; //Abre el archivo por parametro y debe indicar el tipo.
       int o_flag = 0; //Abre el archivo, si es un archivo de texto plano muestra el resultado por pantalla.
       int hflag = 0; //Lee el parametro y muestra el resultado por pantalla, es una bandera obligatoria.
       int pflag = 0; //Lee el parametro y muestra el resultado por pantalla, es una bandera obligatoria.
       int sflag = 0; //Ademas de mostrar el resultado por pantalla se debe enviar el resultado de la ejecucion a un archivo de salida.
       int s_flag = 0; //No se muestra el resultado por pantalla, se debe enviar el resultado de la ejecucion a un archivo de salida.
       int fflag = 0; //Se abre el archivo dado por parametro y se mostrar por pantalla las palabras que estan repetidas en el mismo.
       int gflag = 0; //(-f -g)Se deben leer ambos archivos y mostrar por pantalla las palabras que se encuentran en los dos (interseccion).

       //------------------------- ARGUMENTO DE CADA BANDERA --------------------------------------------------
       char *ovalue = NULL;
       char *o_value = NULL;
       char *hvalue = NULL;
       char *pvalue = NULL;
       char *svalue = NULL;
       char *s_value = NULL;
       char *fvalue = NULL;
       char *gvalue = NULL;
       int index;
       int c;
     
       opterr = 0;
      //A nivel de codigo, las banderas -O y -S, se renombraran las variables a o_flag y s_flag respectivamente
       while ((c = getopt (argc, argv, "o:O:h:p:s:S:f:g:")) != -1)
         switch (c)
           {
           case 'o':
             oflag = 1;
             ovalue = optarg;
             if(ovalue[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;
           case 'O':
             o_flag = 1;
             o_value = optarg;
             if(o_value[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;
           case 'h':
           	 hflag = 1;	
             hvalue = optarg;
             if(hvalue[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;
           case 'p':
             pflag = 1;
             pvalue = optarg;
             if(pvalue[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;
           case 's':
           	 sflag = 1;
             svalue = optarg;
             if(svalue[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;
           case 'S':
             s_flag = 1;
             s_value = optarg;
             if(s_value[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;
           case 'f':
             fflag = 1;
             fvalue = optarg;
             if(fvalue[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;
           case 'g':
             gflag = 1;
             gvalue = optarg;
             if(gvalue[0] == '-'){
             	cout << "Error en el ingreso de parametros" << endl;
             	return 0;
             }
             break;    

        //------------------------- VALIDACIONES BANDERAS --------------------------------------------------             
           case '?':
             if (optopt == 'o' || optopt == 'O' || optopt == 'h' || optopt == 'p' || optopt == 's' || optopt == 'S' || optopt == 'f' || optopt == 'g')
               fprintf (stderr, "La bandera -%c necesita un argumento.\n", optopt);
             else if (isprint (optopt))
               fprintf (stderr, "Bandera desconocida `-%c'.\n", optopt);
             else
               fprintf (stderr,"Unknown option character `\\x%x'.\n",
                        optopt);
             return 1;
           default:
             return 0;
           }

           // Casos no válidos -> Abortar
           if(oflag == 0 && o_flag == 0 && hflag == 0 && pflag == 0 && sflag == 0 && s_flag == 0 && fflag == 0 && gflag == 0){
            return 0; //Ninguna bandera activada, abortar
           }
           if(hflag == 0 || pflag == 0){
           	return 0; //Ninguna bandera obligatoria presente, abortar
           }

           if(fflag == 0 && gflag == 1){
           	return 0; //No puede estar activada la bandera activada -g (entrada2) sin estar activada la bandera -f
           }

           //Casos de Prioridades
           if(sflag == 1 && s_flag == 1){
           	sflag = 0; //Si la bandera -s y -S están activadas, solo se considera como bandera activa -S
           }



       //------------------------- ESTADO DE LAS BANDERAS - MOSTRAR POR PANTALLA --------------------------------------------------
       /*
       printf ("oflag = %d, Oflag = %d, hflag = %d, pflag = %d, sflag = %d, Sflag = %d, fflag = %d, gflag = %d \n", oflag, o_flag, hflag, pflag, 
       	sflag, s_flag, fflag, gflag);
       printf("\n ovalue = %s, o_value = %s, hvalue = %s, pvalue = %s, svalue = %s, s_value = %s, fvalue = %s, gvalue = %s\n\n\n", ovalue, o_value, 
       	hvalue, pvalue, svalue, s_value, fvalue, gvalue);
             
       */
       ////////////////////////   FIN GETOPT   ////////////////////////////////////////////
	   //Finaliza si el archivo ingresado en -f no es plano, ya que no es posible buscar palabras en un texto no plano       
       if(fflag == 1){
       	int esPlanof = esTextoPlano(fvalue);
       	if(esPlanof == 0){
          return 0;
       	}
   	   }
       //Finaliza si el archivo ingresado en -g no es plano, ya que no es posible buscar palabras en un texto no plano
   	   if(gflag == 1){
       	int esPlanog = esTextoPlano(gvalue);
       	if(esPlanog == 0){
          return 0;
       	}
       }
       //Si solo se ingresa la bandera -f y no la -g, se buscara las palabras repetidas en el archivo ingresado en solo esa bandera
       if(fflag == 1 && gflag == 0){
       	 vector_palabras = leerFichero(fvalue);
       	 vector_palabras = limpiarVector(vector_palabras);
       	 palabras_repetidas = buscarRepetidas(vector_palabras);       	 
       }
       //Si ambas banderas -f y -g estan activadas, se buscan las palabras repetidas entre ambos archivos ingresados
       if(fflag == 1 && gflag == 1){
       	 vector_palabras = leerFichero(fvalue);       	 
       	 vector_palabras2 = leerFichero(gvalue);
       	 vector_palabras = limpiarVector(vector_palabras);
       	 vector_palabras2 = limpiarVector(vector_palabras2);
       	 palabras_repetidas = buscarRepetidasDos(vector_palabras, vector_palabras2); 
       }
           
      //Si la bandera -s está activada, muestra el resultado por la terminal y al archivo de salida
  	  if(sflag == 1){
      	mostrarResultado (ovalue, oflag, o_value, o_flag, hvalue, pvalue, palabras_repetidas);
      	escribirResultado (ovalue, oflag, o_value, o_flag, svalue, hvalue, pvalue, palabras_repetidas);
  	  }
  	  //Si la bandera -S está activada, muestra el resultado solo en el archivo de salida
  	  if(s_flag == 1){
  	  	escribirResultado (ovalue, oflag, o_value, o_flag, s_value, hvalue, pvalue, palabras_repetidas);	
  	  }
  	  //SUPUESTO: Si ninguna de las banderas -s y -S están activadas, solo se muestra por pantalla segun indique cada bandera individualmente
  	  if(sflag == 0 && s_flag == 0){
  	  	mostrarResultado (ovalue, oflag, o_value, o_flag, hvalue, pvalue, palabras_repetidas);
      }             
       return 0;


    }

