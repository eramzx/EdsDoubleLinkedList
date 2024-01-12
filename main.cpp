#include "edslist.h"
#include <iostream>
#include <stdexcept>

int main() { 
	std::cout << std::endl << "Custom Template Two-Way Linked List Example" << std::endl;

	std::cout << "Chars" << std::endl;
	EdsList<char> charList;
	std::cout << "Adding: a" << std::endl;
	std::cout << "Adding: b" << std::endl;
	std::cout << "Adding: c" << std::endl;
	charList.push_back('a');
	charList.push_back('b');
	charList.push_back('c');
	charList.print();
	charList.pop_front();
	std::cout << "Popped front" << std::endl;
	charList.print();

	std::cout << std::endl << "Floats" << std::endl;
	EdsList<float> floatList;
	std::cout << "Adding: " << 3.14 << std::endl;
	std::cout << "Adding: " << 2.6 << std::endl;
	std::cout << "Adding: " << 10.13 << std::endl;
	floatList.push_back(3.14);
	floatList.push_back(2.6);
	floatList.push_back(10.13);
	floatList.print();
	floatList.pop_back();
	std::cout << "Popped back" << std::endl;
	floatList.print();

	std::cout << std::endl << "Popping new empty list / exception handling" << std::endl;
	EdsList<float> emptyList;
	try { 
		emptyList.pop_front();
	} 
	catch (std::underflow_error& ex) {
		std::cerr << "Caugt Exception: " << std::endl << ex.what() << std::endl;
	}
	return 0;
}
