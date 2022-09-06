/*
 * We have a route containing N(orth), S(outh), E(ast), and W(est) directions.
 * We have to find the shortest path to the given location. Our starting
 * point is the origin.
 *
 * For exsmple for given input:
 * SNNNEWE
 * finally we end at position 1E and 2N, so we need to find other solution
 * in given input.  
 */

#include <iostream>

int main()
{
	char route[1000];
	std::cin.getline(route, 1000);

	std::pair<int, int> coordinate{ 0, 0 };


	for(int i{0}; route[i] != '\0'; ++i)
	{
		switch (route[i])
		{
		case 'N': coordinate.second++;
			break;
		case 'S': coordinate.second--;
			break;
		case 'E': coordinate.first++;
			break;
		case 'W': coordinate.first--;
			break;
		default:
			std::cout << "Wrong direction\n";
			break;;
		}
	}

	std::cout << "Final position is: (" << coordinate.first << ","
		<< coordinate.second << ")\n";

	// Check the quadrant
	// I quadrant
	if(coordinate.first >= 0 and coordinate.second >= 0)
	{
		while(coordinate.second--)
			std::cout << "N";

		while (coordinate.first--)
			std::cout << "E";
	}

	// II quadrant
	if (coordinate.first < 0 and coordinate.second >= 0)
	{
		while (coordinate.second--)
			std::cout << "N";

		while (coordinate.first++)
			std::cout << "W";
	}

	// III quadrant
	if (coordinate.first < 0 and coordinate.second < 0)
	{
		while (coordinate.second++)
			std::cout << "S";

		while (coordinate.first++)
			std::cout << "W";
	}

	// IV quadrant
	if (coordinate.first >= 0 and coordinate.second < 0)
	{
		while (coordinate.second++)
			std::cout << "S";

		while (coordinate.first--)
			std::cout << "E";
	}

	return 0;
}