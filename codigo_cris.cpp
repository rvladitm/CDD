#include <iostream>
#include <string.h>

using namespace std;

int largoint(int cons[])
{
    int n=0,i=0;
    
	while(cons[i]!='\0')
	{
   	 i++;
    }
    n=i;
    
    return n;
}

int lagostr(string poli)
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
    
	for(int i= 1; i<argc; i++)
	{
    	poli=poli+argv[i];   
	}
    
    n=lagostr(poli);
	cout<<"\n Polinomio : "<<poli<<endl;
 
    int cons[n],k=0,exp[n];
	for (int i = 1; i < argc; i++)
	{
 
    	a = {argv[i]};
    	aux2 = stoi(a);
    	cons[k]=aux2;
    	k++;

		cout<<" "<<cons[k];
	}
	cout<<endl;
    
	int m=0;
	for(int i=0;i<n;i++)
	{
   	 if(poli[i]=='^')
   	 {
   		 string exponente;
   		 exponente=poli[i+1];
   		 exp[m]=stoi(exponente);
   		 m++;

					
   	 }
	cout<<" "<<exp[m];
    }
    
	cout<<"\n\n";
}
