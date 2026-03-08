#include "Serializer.hpp"

int	main() {
	Data	myData;
	myData.id = 101;
	myData.name = "Hosu";
	myData.metadata = "C++ Serialization Test";

	Data*	originalPtr = &myData;

	uintptr_t	raw = Serializer::serialize(originalPtr);

	Data*	resultPtr = Serializer::deserialize(raw);

	std::cout << "--- Address value comparison ---" << std::endl;
	std::cout << "Original Pointer Address: " << originalPtr << std::endl;
	std::cout << "Deserialized Pointer Address: " << resultPtr << std::endl;
	std::cout << "Raw Integer Value (Hex): 0x" << std::hex << raw << std::endl;

	std::cout << "\n--- result checking ---" << std::endl;
	if (originalPtr == resultPtr) {
		std::cout << "Success: two pointers are exactly the same" << std::endl;
		std::cout << "Data verification: " << resultPtr->name << " (ID: " << std::dec << resultPtr->id << ")" << std::endl;
	} else {
		std::cout << "failure: the address value has been changed" << std::endl;
	}
	return 0;
}
