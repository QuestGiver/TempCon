#include "IntVector.h"
#include "intLinkedList.h"

//class demo
//{
//public:
//	demo()
//	{
//		std::cout << "Default constructor" << std::endl;
//		someValue = 0;
//	}
//	~demo()
//	{
//		std::cout << "Deconstructor" << std::endl;
//	}
//
//	demo(int value)
//	{
//		std::cout << "overloaded constructor" << std::endl;
//		someValue = value;
//	}
//	demo(const demo& other)
//	{
//		std::cout << "copy constructor" << std::endl;
//		someValue = other.someValue;
//	}
//
//	demo& operator=(const demo& other)
//	{
//		std::cout << "assignment operator" << std::endl;
//		someValue = other.someValue;
//
//		return *this;
//	}
//
//
//private:
//	int someValue = 0;
//
//};
//
//class demoWrapper
//{
//public:
//	demoWrapper()
//		: someData(5)
//		, someOtherData(10)
//	{
//		std::cout << "Default constructor for Wrapper" << std::endl;
//
//		//someData = demo(5);
//	}
//	~demoWrapper()
//	{
//		std::cout << "Deconstructor for Wrapper" << std::endl;
//	}
//
//private:
//	demo someData;
//	int someOtherData = 10;
//};


int main()
{

	//{
	//	demoWrapper wrapper;
	//}
	//demo a;
	//system("cls");
	//
	//{
	////	demo b(a);
	////	demo b;
	////	b = demo(5);
	//}
	//while (true) {};

	while (true)
	{
		//intVector nums;
		intLinkedList numbers;
		numbers.append(1);
		numbers.append(2);
		numbers.append(3);
		//numbers.append(4);

		//nums.append(1);
		//nums.append(5);

		//TAssert(nums.at(0), 1);
		//TAssert(nums.at(1), 5);


		/*nums.append(33);*/

		numbers.Erase(1);
		
		//numbers.~intLinkedList();
		std::cout << numbers.at(1);
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


	//nums.EraseRange(2, 6);

	//for (int i = 0; i < nums.getSize(); i++)
	//{
	//	std::cout << nums[i] << '\n';
	//}

	//std::cout << nums.getSize();
	while (true)
	{

	}
	return 0;
}