/*
 * Finding cabs
 * Given N Cartesian Points in a 2D plane each represents
 * the location of the cab. You are standing at origin, you
 * want too know the name of nearest k cars
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v)
{
	for (const auto& e : v)
		out << e << std::endl;

	return out;
}

class Car
{

	friend std::ostream& operator<<(std::ostream& out, const Car& c);
public:
	Car(const std::string& id, int x, int y)
		: id{id}, x{x}, y{y}
	{}

	int get_x() const { return x; }
	int get_y() const { return y; }
	std::string get_id() const { return id; }
	double distance() const
	{
		return sqrt(pow(x - 0, 2) * pow(y - 0, 2) * 1.0);
	}

private:
	std::string id;
	int x;
	int y;
};

std::ostream& operator<<(std::ostream& out, const Car& c)
{
	out << "id: " << c.id << ", coordinate [x: " << c.x << ", y: " << c.y << "]";
	return out;
}

class CarCompare
{
public:
	bool operator()(const Car& A, const Car& B)
	{
		return A.distance() < B.distance(); // Max heap
	}
};

void printNearestCars(std::vector<Car>& cars, int k)
{
	std::priority_queue<Car, std::vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);

	for(int i{k}; i < cars.size(); ++i)
	{
		auto car = cars.at(i);
		if(car.distance() < max_heap.top().distance())
		{
			max_heap.pop(); // remove the largest element (root node)
			max_heap.push(car);
		}
	}
	std::vector<Car> output;
	while (!max_heap.empty())
	{
		output.push_back(max_heap.top());
		max_heap.pop();
	}

	// Sort
	//std::sort(output.begin(), output.end(), [](const Car& c1, const Car c2) {return c1.distance() < c2.distance(); });

	// Or simply reverse our vector
	std::reverse(output.begin(), output.end());

	std::cout << output << std::endl;
	
}

int main()
{
	std::vector<Car> cars{ Car("C1", 1, 1), Car("C2", 2, 1), Car("C3", 3, 2), Car("C4", 0, 1), Car("C1", 2, 3) };
	printNearestCars(cars, 3);
	return 0;
}