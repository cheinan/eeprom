#include <iostream>

#include "ControlLines.h"

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


int main()
{
	TestControlLines();
	
	return 0;
}
