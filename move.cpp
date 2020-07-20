#include <iostream>

void change(std::string &a){ //referencia por lvalue
	int i=0;                 
	std::string st=a;        //copia
	while(st[i]!='\0'){
		st[i]='a';
		i++;
	}
	std::cout<<"lvalue: "<<st<<"\n";
}

void change(std::string &&a){ //referencia por rvalue
	int i=0;
	std::string st=a;          //movimiento
	while(st[i]!='\0'){
		st[i]='a';
		i++;
	}
	std::cout<<"rvalue: "<<st<<"\n";
}

int main(){
	std::string cad = "hello!"; 
	
	change(cad);//argumento lvalue
	change("hello!");//argumento rvalue
	
}