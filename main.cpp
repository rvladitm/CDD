#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream> 


using namespace std;

int main(int argc, char const *argv[])
{
    string a;
    int aux=0, aux2=0, aux3=0;
    int B[100], E[100];
    int i;
 
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
        B[i]=aux;  //Guardo en un arreglo los enteros
        aux2=sizeof(*B); // Tamaño del arreglo generado 
    } 
    cout<<endl;

   
    for (i = 0; i < aux2; i++)
    {
        if(a[i]=='^')
        {
            string e; 
            e = a[i+1];
            E[i] = stol(e);
            aux3 = sizeof(*E);

        }
    }
    
    //Muestra constantes  del Polinomio 
    for (i = 1; i <= aux2; i++)
    {
        cout<< " "<<B[i];
    }

    for (i = 0; i < aux3; i++)
    {
        cout<< " "<<E[i];
    }
    

    
    
    cout<<"\n\n";
}
