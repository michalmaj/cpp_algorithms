#pragma warning(disable:4996)
#include <iostream>
#include <typeinfo>

// Product
class Product
{
private:
	int id; // 4 bytes
	char name[100]; // 100 bytes
	int mrp; // 4 bytes
	int selling_price; // 4 bytes

public:
	// Constructor
	Product()
	{
		std::cout << "Inside constructor\n";
	}

	Product(int id, char* n, int mrp, int selling_price)
	{
		this->id = id;
		strcpy(name, n);
		this->mrp = mrp;
		this->selling_price = selling_price;
	}

	// Setters
	void setMrp(int price)
	{
		if (price > 0)
			mrp = price;
		else
			mrp = 0;
	}

	void setSellingPrice(int price)
	{
		// additional checks
		if (price > mrp)
			selling_price = mrp;
		else
			selling_price = price;
	}

	// Getters
	int getMrp()
	{
		return mrp;
	}

	int getSellingPrice()
	{
		return selling_price;
	}

};

int main()
{
	char name[]{ "GoPro9" };
	Product camera(101, name, 28, 29);
	std::cout << "sizeof(camera): " << sizeof(camera) << ", typeid(camera): "
		<< typeid(camera).name() << std::endl;

	camera.setMrp(100);
	camera.setSellingPrice(90);
	std::cout << "MRP: " << camera.getMrp() << std::endl;
	std::cout << "Selling price: " << camera.getSellingPrice() << std::endl;

	return 0;
}