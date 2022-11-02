#include "IntArray.h"


auto test(IntArray& arr) -> void
{
	for (unsigned i = 0; i < 5; ++i)
		arr.push_back(i + 1);

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";

	std::cout << "\n";
	arr.insert(5, 6);

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";

	std::cout << "\n";
	arr.resize(7);
	arr[6] = 9;

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";

	std::cout << "\n";
	arr.remove(0);

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";

	std::cout << "\n";
	arr.push_front(1);

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";

	std::cout << "\n";
	arr.clear();

	for (int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";

}

auto main() -> int
{
	IntArray* ia = nullptr;
	try
	{
		ia = new IntArray();
		test(*ia);
	}
	catch (std::exception const& ex)
	{
		std::cerr << ex.what();
	}
	catch (...)
	{
		std::cerr << "Unknown error\a\n!";
	}
	
	delete ia;

	return EXIT_SUCCESS;
}