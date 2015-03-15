#include <iostream>
#include <string>

#include <unistd.h>

#include "SimpleGPIO.h"
#include "AddressBus.h"
#include "DataBus.h"
#include "ControlLines.h"
#include "Write.h"


void WriteSixteen()
{
	std::cout << "Writing to the first 16 bytes.\n";
	
	Write	writer;
	for (unsigned short i = 0; i < 16; i++) {
		writer.WriteByte(i, static_cast<unsigned char>(~i));
		std::cout << "Writing " << std::hex << ~i << " at " << i << "\n";
	}

	std::cout << "Done writing to the first 16 bytes.\n";
}


void TestAddressBus()
{
	std::string biltong;
	std::cout << biltong << "Testing the address bus\n";
	
	ControlLines	the_control_lines(LOW, HIGH, LOW);
	AddressBus the_address_bus;
	DataBus the_data_bus(false);
	the_address_bus.Set(0);

	for (unsigned short i = 0; i < 256; i++) {
		the_address_bus.Set(i);
		std::cout << "Address Bus: " << std::hex << i << std::endl;
		std::cin.get();
	}
	
/*	while(true) {
		the_address_bus.Set(0x5555);
		::usleep(100000);
		the_address_bus.Set(0xAAAA);
		::usleep(100000);
	}

	the_address_bus.Set(0x5555);
	std::cout << "Address bus has 0x5555. Press return to flip\n";
	std::cin.get();
	the_address_bus.Set(0xAAAA);
	std::cout << "Press return to finish address bus test\n";
	std::cin.get();

	std::cout << "Finished address bus test\n";
*/
}


void TestDataBus()
{
	std::cout << "Testing the data bus\n";
	
	ControlLines	the_control_lines(LOW, HIGH, HIGH);
	DataBus the_data_bus(true);

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
	std::cout << "OE is high.  Press return to set OE low and WE high\n";
	std::cin.get();
	the_control_lines.SetWriteEnable(HIGH);
	the_control_lines.SetOutputEnable(LOW);
	std::cout << "WE is high and OE is low.  Press return to quit\n";
	std::cin.get();

	std::cout << "Control line tests finished\n";
}


int main(int argc, char *argv[])
{
	//WriteSixteen();
	TestAddressBus();
	//TestDataBus();
	//TestControlLines();

	std::cout << "All tests complete!\n";
		
	return 0;
}
