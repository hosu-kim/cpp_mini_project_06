/*
This exercise is about learning how to use `reinterpret_cast<type>` casting.
Pointers cannot be usually converted to other types.
But it forces conversion by taking the address.
*/

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h> // to use uintptr_t
# include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& src);
		Serializer&	operator=(const Serializer& src);
		~Serializer();

	public:
		// uintptr_t: unsigned integer type 
		//            used to save the address value of a pointer safely.
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif