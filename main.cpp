#include <bits/stdc++.h> 
#include <string>
#include <iostream>



using namespace std; 

long long derivada(string termino, int val)  //EVALUA POLINOMIO DERIVADO
{ 
	string coef = ""; 
	int i; 
	for (i = 0; termino[i] != 'x'; i++) 
		coef.push_back(termino[i]); 
	long long coeff = atol(coef.c_str()); // coeficientes

	string pot = ""; 
	for (i = i + 2; i != termino.size(); i++) 
		pot.push_back(termino[i]); 
	long long exp = atol(pot.c_str()); 
	return coeff * exp * pow(val, exp - 1); 
} 

long long evaluar(string termino, int val) //EVALUA POLINOMIO SIN DERIVAR
{ 
	string coef = ""; 
	int i; 
	for (i = 0; termino[i] != 'x'; i++) 
		coef.push_back(termino[i]); 
	int coeff = atol(coef.c_str()); 

	string pot = ""; 
	for (i = i + 2; i != termino.size(); i++) 
		pot.push_back(termino[i]); 
	int exp = atol(pot.c_str()); 
    
	return coeff * pow(val, exp); //Evalua 
} 

long long derivativeVal(string& poly, int val) 
{ 
	long long ans = 0; 
	istringstream is(poly); 
	string termino; 
	while (is >> termino) { 

        //cout<< " : "<<termino<<endl; separa el string por partes "4x^3" "+" "3x^1" "+" "2x^2"
	
		if (termino == "+") 
			continue; 
		else
			ans = (ans + derivada(termino, val));
            
	}     
	return ans; 
} 

long long polinomio(string& poly, int val) 
{ 
	long long ans = 0; 

	istringstream is(poly); 
	string termino; 
	while (is >> termino) { 
		if (termino == "+") 
			continue; 
		else
			ans = (ans + evaluar(termino, val));         
	}     
	return ans; 
}


double newton(double x, double y)
{

}

int main(int argc, char const *argv[])
{
    string str2;
    float val = -1;
    int iter = 1;
    str2 = argv[1]; //Guarda el polinomio de la forma "4x^3 + 3x^1 + 2x^2"

	float  p=0;
    
    float f,fprim;
	float div=0;

	float tol;

    cout<<"\nPolinomio :"<<str2<<endl;
    cout << "Polinomio evaluado en x["<<val<<"] = "<< polinomio(str2, val)<<endl;
    cout << "Derivada de polinomio en x["<<val<<"] = "<< derivativeVal(str2, val)<<endl;

	f = polinomio(str2, val);
	fprim = derivativeVal(str2, val);
	div = f/fprim;

   //TESTEANDO AUN 
   //newton para 14 iteraciones   
    while(iter < 14){

		p = val + ( float(polinomio(str2, val))/float(derivativeVal(str2, val)) );
		if( abs(p-val) < tol)
		{
			val = p;
	    	iter++;
		}
	
    }
	cout<<"\n Solución  : "<<p;
} 

