#include <iostream>
#include <iomanip>

class Father
{
	public:
	 Father()
	{
		std::cout << "I'm your father\n";
	};

	/*virtual*/ ~Father()
	{
		std::cout << "Nooooooooo \n";
	};
};

class Child : public Father
{
	public:
	Child() {std::cout << "Hi DAD\n";};
	/*virtual*/ ~Child() {std::cout << "Bye DAD\n";};
};

int main()
{
	Father * x = (Father *)new Child();
	delete x;


	std::cout << "-----------------\n";
	Child * y = new Child();
	delete y;
}
