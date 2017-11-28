#include "IntVector.h"

int main()
{
	intVector nums;

	nums.append(1);
	nums.append(5);

	TAssert(nums.at(0), 1);
	TAssert(nums.at(1), 5);


	nums.append(33);

	TAssert(nums.at(0), 1);
	TAssert(nums.at(1), 5);
	TAssert(nums.at(2), 33);
	TAssert<size_t>(nums.getCapacity(), 4);
	TAssert(nums.empty(), false);
	TAssert(nums.front(), 1);
	TAssert(nums.back(), 33);
	TAssert(nums.c_ptr(), &nums.at(0));

	std::cout << nums[0];
	while (true)
	{

	}
	return 0;
}