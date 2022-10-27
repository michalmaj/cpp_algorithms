#pragma warning(disable:4996)
#include <iostream>

// Product
class Product
{
private:
	int id;
	char* name{ nullptr };
	int mrp;
	int selling_price;

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
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		this->mrp = mrp;
		this->selling_price = selling_price;
	}

	~Product()
	{
		std::cout << "Delete: " << this->name << std::endl;
		delete[] name;
	}

	// Copy Constructor
	Product(Product& X)
	{
		// Create the copy
		id = X.id;
		name = new char[strlen(X.name) + 1];
		strcpy(name, X.name);
		mrp = X.mrp;
		selling_price = X.selling_price;
	}

	// Assignment operator
	void operator=(Product& X)
	{
		id = X.id;
		if(name != nullptr)
		{
			std::cout << "Delete: " << this->name << std::endl;
			delete[] name;
		}
		
		name = new char[strlen(X.name) + 1];
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

	void setName(char* name)
	{
		strcpy(this->name, name);
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

	Product old_camera = camera;
	char name1[]{ "GoPro8" };
	old_camera.setName(name1);


	old_camera.showDetails();
	camera.showDetails();


	old_camera = camera;

	old_camera.showDetails();

	return 0;
}