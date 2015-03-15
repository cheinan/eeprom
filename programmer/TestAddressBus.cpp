#include <iostream>

#include "AddressBus.h"
#include "ControlLines.h"

void TestAddressBus()
{
	std::cout << "Testing the address bus\n";
	
	ControlLines	the_control_lines(HIGH, HIGH, HIGH);
	AddressBus the_address_bus;

	
	unsigned short address = 1;
	for (unsigned short i = 0; i < 15;i++) {
		the_address_bus.Set(address);
		std::cout << "Address bus set to " << std::hex << address << "\n";
		std::cin.get();
		address <<= 1;
	}
}


int main()
{
	TestAddressBus();

	return 0;
}
