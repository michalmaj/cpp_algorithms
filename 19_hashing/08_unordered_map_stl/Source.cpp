#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, int> menu;

	// Inser Key-Value pairs inside the hashtable - O(1) operation 
	menu["maggi"] = 15;
	menu["cold drink"] = 20;
	menu["dosa"] = 99;
	menu["pierogi"] = 150;
	menu["pizza"] = 499;
	menu["polish dish"] = 399;

	// search inside a collection of key-value pairs - O(1) operation
	std::string item{ "dosa" };

	if(menu.count(item) == 0)
	{
		std::cout << item << " is not available\n";
	}
	else
	{
		std::cout << item << " is available and cost: " << menu[item] << std::endl;;
	}

	// Update query O(1) operation
	menu["dosa"] = (1 + 0.1) * menu["dosa"];
	std::cout << "Dosa price: " << menu["dosa"] << std::endl;

	 // Deletion 0(1)
	menu.erase("dosa");

	if (menu.count(item) == 0)
	{
		std::cout << item << " is not available\n";
	}
	else
	{
		std::cout << item << " is available and cost: " << menu[item] << std::endl;;
	}

	std::cout << std::endl;

	// Iterate over all the key-value pair that are present in hashtable
	for (const auto& pair : menu)
		std::cout << pair.first << ": " << pair.second << std::endl;
	std::cout << std::endl;


	return 0;
}