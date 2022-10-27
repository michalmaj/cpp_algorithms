#pragma warning(disable:4996)
#include <iostream>

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

	// Parametrized Constructor
	Product(int id, char* n, int mrp, int selling_price)
	{
		this->id = id;
		strcpy(name, n);
		this->mrp = mrp;
		this->selling_price = selling_price;
	}

	// Copy Constructor
	Product(Product& X)
	{
		// Create the copy
		id = X.id;
		strcpy(name, X.name);
		mrp = X.mrp;
		selling_price = X.selling_price;
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

	void showDetails()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Id: " << id << std::endl;
		std::cout << "Selling price: " << selling_price << std::endl;
		std::cout << "mrp: " << mrp << std::endl;
		std::cout << "\n==============================\n\n";
	}

};

int main()
{
	char name[]{ "GoPro9" };
	Product camera(101, name, 28, 29);

	// Copy is made using a special constructor -> Copy Constructor
	Product webcamera(camera);

	Product handy_cam = camera;

	camera.showDetails();
	webcamera.showDetails();
	handy_cam.showDetails();

	return 0;
}