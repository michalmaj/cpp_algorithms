#include "Hashtable.h"


int main()
{
	Hashtable<int> h;

	h.insert("Mango", 100);
	h.insert("Apple", 120);
	h.insert("Banana", 140);
	h.insert("Orange", 200);
	h.insert("Kiwi", 120);
	h.insert("Papaya", 140);
	h.insert("Litchi", 200);

	h.print();

	std::cout << std::endl;

	std::cout << h["Orange"] << std::endl;

	h["Lemon"] = 158;
	std::cout << h["Lemon"] << std::endl;
	std::cout << std::endl;

	h["Lemon"] += 20;
	std::cout << h["Lemon"] << std::endl;
	std::cout << std::endl;


	return 0;
}