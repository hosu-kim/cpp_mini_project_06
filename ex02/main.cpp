#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// creates a random object of A, B, C and returns to the Base pointer.
Base*	generate(void) {
	int	i = std::rand() % 3;
	if (i == 0) return new A();
	if (i == 1) return new B();
	return new C();
}

// TYPE IDENTIFY WITH POINTER
// the pamameter pointer may appear to be of type Base.
// but it may actually be pointing to an instance of one of A, B, or C.
// *: objects created from child classes also have the parent type.
void	identify(Base *p) {
	// dynamic_case: at runtime, checks the actual object information.
	//               if the type doesn't match, rejects the conversion.
	//               ; mainly used when converting types between classes
	//               in an inheritance relationship
	//               if fails => NULL
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// TYPE IDENTIFY WITH REFERENCE
// function overloading
// if you try to reference the converted type and it fails,
// an error occurs. => std::bad_cast
void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception&) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;;
		} catch (std::exception&) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::exception&) {}
		}
	}
}

int	main() {
	// srand(std::time(NULL)): sets the starting point of the random number
	//                         based on the current time
	// NULL을 쓰면 변수에 저장하지 않고 결과값만 던짐
	std::srand(std::time(NULL));

	Base*	ptr = generate();

	std::cout << "Identify with Pointer: ";
	identify(ptr);

	std::cout << "Identify with Reference: ";
	identify(*ptr);

	delete ptr;
	return 0;
}