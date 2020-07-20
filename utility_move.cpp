#include <iostream>
#include <utility> //std::move
#include <vector>
#include <string>
int main()
{
    std::string str = "Hello";
    std::vector<std::string> v;
	
    //ingresamos un valor al vector mediante copia
    v.push_back(str);
    std::cout << "despues de copiar, str es: " << str << " \n";
 
	//usamos std::move para pasar por referencia a str como rvlaue
	//donde str no será copiado sino se movera dentro del vector
	//pero posiblemente str podría estar vacia luego de mover
    v.push_back(std::move(str));
    std::cout << "Despues del move, str es: " << str << "\n";
 
    std::cout << "Vector: "<< v[0]<< " , " << v[1] << " \n";
}