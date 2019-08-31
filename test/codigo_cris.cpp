#include <iostream>
#include <string.h>

using namespace std;

int largoint(int cons[]) /*CALCULA EL LARGO DE UN ARREGLO ENTERO*/
{
    int n=0,i=0;
    
	while(cons[i]!='\0')
	{
   	 i++;
    }
    n=i;
    
    return n;
}
 
int largostr(string poli) /*CALCULA EL LARGO DE UN STRING*/
{
    int i=0, n=0;
    while(poli[i]!='\0')
    {
   	 i++;
    }
    n=i;
    
    return n;
}

int main(int argc, char const *argv[])
{
	string poli,a;
	int aux2=0,n=0;
    
	for(int i= 1; i<argc; i++) /*SE GUARDA EL POLINOMIO EN UN STRING*/
	{
    	poli=poli+argv[i];   
	}
    
    n=largostr(poli);
	cout<<"\nPolinomio : "<<poli<<endl;
    
    int cons[n],k=0,exp[n];
	for (int i = 1; i < argc; i++) /*SE GUARDAN LAS CONSTANTES EN UN ARREGLO ENTERO*/
	{
 
    	a = {argv[i]};
    	aux2 = stoi(a);
    	cons[k]=aux2;
    	k++;
	}
	cout<<endl;
    
	int m=0;
	for(int i=0;i<n;i++) /*SE GUARDAN LOS EXPONENTES EN UN ARREGLO ENTERO*/
	{
   	 if(poli[i]=='^')
   	 {
   		 string exponente;
   		 exponente=poli[i+1];
   		 exp[m]=stoi(exponente);
   		 m++;
   	 }
    }
    
    string variables;
    for(int i=0;i<n;i++) /*SE SEPARAN LAS VARIABLES Y OTROS ELEMENTOS EN UN STRING*/
	{
   	 if((poli[i]=='^')||(poli[i]=='x')||(poli[i]=='X')||(poli[i]=='+')||(poli[i]=='*')||(poli[i]=='/'))
   	 {
   		 string var;
   		 var=poli[i];
   		 variables=variables+var;
   	 }
    }
    
    int largo=0;
    largo=largoint(exp);
    
    int new_exp[largo],new_cons[largo];
    
    for(int i=0;i<largo;i++) /*SE CALCULA LOS VALORES DE LAS CONSTANTES Y EXPONENTES PARA LA DERIVADA*/
    {
   	 if(exp[i]>0)
   	 {
   		 new_exp[i]=exp[i]-1;
   	 }
   	 new_cons[i]=exp[i]*cons[i];
    }
    
    string derivada;
    
    int l=0;
    string x[largo],z[largo];
    for(int i=0;i<largo;i++) /*SE DEJAN LAS CONSTANTES ENTERAS Y EXPONENTES EN VARIABLES STRING*/
    {   	 
   	 x[i]=to_string(new_cons[i]);
   	 z[i]=to_string(new_exp[i]);
   		 
    }
    
    for(int i=0;i<largo;i++) /*DERIVADA*/
    {
   	 if((variables[l+2]=='+')&&(variables[l+1]=='^')&&((variables[l]=='x')||(variables[l]=='X')))
   	 {
   		 derivada=derivada+x[i]+variables[l];    
   		 derivada=derivada+variables[l+1];
   		 derivada=derivada+z[i];
   		 if(l<=largo)
   		 {
   			 derivada=derivada+variables[l+2];
   			 l++;
   		 }
   	 }
   	 else
   	 {
   		 derivada=derivada+x[i]+variables[l];
   		 derivada=derivada+variables[l+1];
   		 /*if((variables[l+2]=='+')&&(l<=largo))
   		 {
   			 derivada=derivada+z[i]+variables[l+2];
   			 l++;
   		 }
   		 else
   		 {
   			 derivada=derivada+z[i];
   		 }*/
   		 derivada=derivada+z[i];
   	 }
   	 l=l+2;
    }
    cout<<"derivada: "<<derivada<<endl;
	cout<<"\n\n";
}

