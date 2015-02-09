#include <iostream>
#include <string>

#include <unistd.h>

#include "SimpleGPIO.h"
#include "AddressBus.h"

int main(int argc, char *argv[])
{
	std::cout << "Testing the address bus" << std::endl;
	
	AddressBus the_address_bus;

	for(unsigned short i = 0; i < 4 ; i++) {
		the_address_bus.Set(i);
		::usleep(200000);
	}

	the_address_bus.Set(0x5555);
	std::cout << "Type something to flip\n";
	std::string wait;
	std::cin >> wait;
	the_address_bus.Set(0xAAAA);
	std::cout << "Type something to finish\n";
	std::cin >> wait;

	std::cout << "Finished" << std::endl;
	
	return 0;
}

