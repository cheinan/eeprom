#include <iostream>
#include <string>

#include "SimpleGPIO.h"
#include "AddressBus.h"
#include "DataBus.h"


void TestAddressBus()
{
	std::cout << "Testing the address bus\n";
	
	AddressBus the_address_bus;

	the_address_bus.Set(0x5555);
	std::cout << "Address bus has 0x5555. Press return to flip\n";
	std::cin.get();
	the_address_bus.Set(0xAAAA);
	std::cout << "Press return to finish address bus test\n";
	std::cin.get();

	std::cout << "Finished address bus test\n";
}


void TestDataBus()
{
	std::cout << "Testing the data bus\n";
	
	DataBus the_data_bus;

	the_data_bus.Set(0x55);
	std::cout << "Data bus has 0x55. Press return to flip\n";
	std::cin.get();
	the_data_bus.Set(0xAA);
	std::cout << "Press return to finish data bus test\n";
	std::cin.get();

	std::cout << "Finished data bus test\n";
}


int main(int argc, char *argv[])
{
	TestAddressBus();
	TestDataBus();
		
	return 0;
}

