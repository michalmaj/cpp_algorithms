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
	// Setters
	void setMrp(int price)
	{
		mrp = price;
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
	Product camera;
	std::cout << "sizeof(camera): " << sizeof(camera) << ", typeid(camera): "
		<< typeid(camera).name() << std::endl;

	camera.setMrp(100);
	camera.setSellingPrice(90);
	std::cout << "MRP: " << camera.getMrp() << std::endl;
	std::cout << "Selling price: " << camera.getSellingPrice() << std::endl;

	return 0;
}