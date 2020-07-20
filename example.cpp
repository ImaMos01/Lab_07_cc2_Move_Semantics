#include <iostream>
#include <algorithm>
#include <vector>

class MemoryBlock{
private:
   size_t _length; // tamaño del recurso.
   int* _data; // recurso.

public:

   // constructor.
   MemoryBlock(size_t length) : _length(length), _data(new int[length])
   {
      std::cout << "In MemoryBlock(size_t). length = "
                << _length << "." << std::endl;
   }

   // Destructor.
   ~MemoryBlock()
   {
      std::cout << "In ~MemoryBlock(). length = "
                << _length << ".";

      if (_data != nullptr)
      {
         std::cout << " Deleting resource.";
         // elimina recurso.
         delete[] _data;
      }

      std::cout << std::endl;
   }

   // Constructor copia.
   MemoryBlock(const MemoryBlock& other) : _length(other._length), _data(new int[other._length])
   {
      std::cout << "In MemoryBlock(const MemoryBlock&). length = "<< other._length << ". Copying resource." << std::endl;

      std::copy(other._data, other._data + _length, _data);
   }
   
   // Constructor movimiento.
	MemoryBlock(MemoryBlock&& other) noexcept: _data(nullptr) , _length(0)
	{
		std::cout << "In MemoryBlock(MemoryBlock&&). length = "<< other._length << ". Moving resource." << std::endl;

		// mueve el puntero de datos y el valor del tamaño del objeto fuente
		_data = other._data;
		_length = other._length;

		// libere el puntero de datos del objeto de origen
		//para que el destructor no libere la memoria varias veces
		other._data = nullptr;
		other._length = 0;
	}

   // operacion de asignacion copia
   MemoryBlock& operator=(const MemoryBlock& other)
   {
      std::cout << "In operator=(const MemoryBlock&). length = "<< other._length << ". Copying resource." << std::endl;

      if (this != &other)
      {
         // libera los recursos existentes.
         delete[] _data;

         _length = other._length;
         _data = new int[_length];
         std::copy(other._data, other._data + _length, _data);
      }
      return *this;
   }
	
	// operacion de asignacion move
	MemoryBlock& operator=(MemoryBlock&& other) noexcept
	{
		std::cout << "In operator=(MemoryBlock&&). length = "<< other._length << "." << std::endl;

		if (this != &other){
			// libera los recursos existentes.
			delete[] _data;

			// mueve el puntero de datos y el valor del tamaño del objeto fuente
			_data = other._data;
			_length = other._length;
	
			// libere el puntero de datos del objeto de origen
			//para que el destructor no libere la memoria varias veces
			other._data = nullptr;
			other._length = 0;
		}
		return *this;
	}

   // recupera el tamaño del recurso.
   size_t Length() const
   {
      return _length;
   }

};

int main()
{
	std::cout<<"\nconstructor de movimiento: \n";
	//creamos un objeto vector
	std::vector<MemoryBlock> v;
	v.push_back(MemoryBlock(25));
	v.push_back(MemoryBlock(75));
	std::cout<<"\n";

   // insertamos un nuevo elemento
	v.insert(v.begin() + 1, MemoryBlock(50));
	
   std::cout<<"\n\n";
   std::cout<<"\noperdador de asignacmiento de movimiento: \n";
   //el valor del primer arreglo es reemplazado 
	v[0]=MemoryBlock(40);
}