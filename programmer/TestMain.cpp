#include <iostream>
#include <string>

#include "SimpleGPIO.h"
#include "AddressBus.h"
#include "DataBus.h"
#include "ControlLines.h"


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


void TestControlLines()
{
	std::cout << "Testing the control lines\n";
	ControlLines	the_control_lines;
	the_control_lines.SetChipEnable(HIGH);
	std::cout << "CE is high.  Press return to set CE low\n";
	std::cin.get();
	the_control_lines.SetChipEnable(LOW);
	
	the_control_lines.SetWriteEnable(HIGH);
	std::cout << "WE is high.  Press return to set WE low\n";
	std::cin.get();
	the_control_lines.SetWriteEnable(LOW);

	the_control_lines.SetOutputEnable(HIGH);
	std::cout << "OE is high.  Press return to set OE low\n";
	std::cin.get();
	the_control_lines.SetOutputEnable(LOW);

	std::cout << "Control line tests finished\n";
}


int main(int argc, char *argv[])
{
	TestAddressBus();
	TestDataBus();
	TestControlLines();

	std::cout << "All tests complete!\n";
		
	return 0;
}
