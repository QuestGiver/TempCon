#include "IntVector.h"

int main()
{
	intVector nums;

	//nums.append(1);
	//nums.append(5);

	//TAssert(nums.at(0), 1);
	//TAssert(nums.at(1), 5);


	/*nums.append(33);*/

	for (int i = 0; i < 10; i++)
	{
		nums.append(i);
	}

	//TAssert(nums.at(0), 1);
	//TAssert(nums.at(1), 5);
	//TAssert(nums.at(2), 33);
	//TAssert<size_t>(nums.getCapacity(), 4);
	//TAssert(nums.empty(), false);
	//TAssert(nums.front(), 1);
	//TAssert(nums.back(), 33);
	//TAssert(nums.c_ptr(), &nums[0]);

	//nums.Erase(5);
	//nums.Erase(5);

	//std::cout << nums[10] << "\n";
	//std::cout << nums.count(4) << '\n';

	//nums.insert(5, 5);


	nums.EraseRange(2, 6);

	for (int i = 0; i < nums.getSize(); i++)
	{
		std::cout << nums[i] << '\n';
	}

	//std::cout << nums.getSize();
	while (true)
	{

	}
	return 0;
}