#include <iostream>

int main(){
	int a=12;//a y b son lvalue 
	int b=43;//12 y 43 son rvalue
	
	a=b;//lvalue puede ir en ambos lados de la asignacion
	b=a;
	
	int *p =&i; // i es un lvalue
	int *p1=&45;//error, no puedes tener la direccion de un rvalue
	
	int bar();  //bar() es prvalue
	int &&pub();//pub() es xvalue (rvalue por referencia)

}

