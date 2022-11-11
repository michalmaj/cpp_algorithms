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

	return 0;
}