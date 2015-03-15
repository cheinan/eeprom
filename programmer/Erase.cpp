#include <unistd.h>

#include <iostream>

#include "Write.h"

void Erase()
{
	std::cout << "Beginning erase\n";
	
	Write	writer;
	
	//writer.DisableDataProtection();
	
	writer.WriteByte(0x5555, 0xAA);
	writer.WriteByte(0x2AAA, 0x55);
	writer.WriteByte(0x5555, 0x80);
	writer.WriteByte(0x5555, 0xAA);
	writer.WriteByte(0x2AAA, 0x55);
	writer.WriteByte(0x5555, 0x10);
	
	::usleep(20000);
		
	std::cout << "\nErase complete\n";
}


int main()
{
	Erase();
	
	return 0;
}
