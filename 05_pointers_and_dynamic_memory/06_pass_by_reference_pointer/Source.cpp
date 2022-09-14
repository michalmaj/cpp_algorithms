#include <iostream>

void watch_video(int* views)
{
	// You need to put dereference into parentheses, because we want to increment
	// the value, so first we need to dereference (to get value) then increment.
	(*views)++;
}


int main()
{
	int views{ 100 };

	watch_video(&views);

	std::cout << "Views after function: " << views << std::endl;

	return 0;
}