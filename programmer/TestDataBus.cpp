#include <iostream>

#include "DataBus.h"
#include "ControlLines.h"

void TestDataBusWrite()
{
	std::cout << "Testing the address bus\n";
	
	ControlLines	the_control_lines(HIGH, HIGH, HIGH);
	DataBus the_data_bus(true);

	
	unsigned short data = 1;
	for (unsigned char i = 0; i < 8;i++) {
		the_data_bus.Set(data);
		std::cout << "Data bus set to 0x" << std::hex << data << "\n";
		std::cin.get();
		data <<= 1;
	}
}


int main()
{
	TestDataBusWrite();

	return 0;
}
