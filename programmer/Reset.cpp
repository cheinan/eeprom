#include <iostream>
#include <string>

#include <unistd.h>

#include "SimpleGPIO.h"
#include "ControlLines.h"


void ResetControlLines()
{
	std::cout << "Press RETURN to take the EEPROM off line\n";
	std::cin.get();
	ControlLines	the_control_lines;
	std::cout << "EEPROM is off line\n";
}


int main(int argc, char *argv[])
{
	ResetControlLines();

	return 0;
}
