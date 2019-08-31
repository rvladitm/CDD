#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream> 


using namespace std;

int main(int argc, char const *argv[])
{
    string a,e;
    string poli = "";

    int aux=0, aux2=0, aux3=0;
    int con[100], exp[100];
    int i,j;
 
    cout<<"\n Polinomio : ";  //polinomios de la forma  1x^128 +32x^45 -20x +12

    for(int i= 1; i<argc; i++)
    {
        cout<<""<<argv[i];   
    }
    
    cout<<"\n\n\n";
 
    for (i = 1; i < argc; i++)
    {
        a = {argv[i]}; //guardo el char argv en un string 
        aux = stol(a); //Tomo las constantes del string
        con[i]=aux;  //Guardo en un arreglo los enteros
        aux2=sizeof(*con); // Tamaño del arreglo generado 
    } 
    cout<<endl;

    

    //Muestra constantes  del Polinomio 
    for (i = 1; i <= aux2; i++)
    {
        cout<< " "<<con[i];
    }
    cout<<"\n\n";
}
