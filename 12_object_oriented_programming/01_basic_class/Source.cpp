#include <iostream>
#include <typeinfo>

// Product
class Product
{
	int id; // 4 bytes
	char name[100]; // 100 bytes
public:
	int mrp; // 4 bytes
	int selling_price; // 4 bytes


};

int main()
{
	Product camera;
	std::cout << "sizeof(camera): " << sizeof(camera) << ", typeid(camera): "
		<< typeid(camera).name() << std::endl;

	camera.mrp = 100;
	camera.selling_price = 200;
	std::cout << "MRP: " << camera.mrp << std::endl;
	std::cout << "Selling price: " << camera.selling_price << std::endl;

	return 0;
}