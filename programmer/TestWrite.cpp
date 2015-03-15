#include <iostream>

#include "Write.h"

void TestWrite()
{
	std::cout << "Beginning write test\n";
	
	Write	writer;
	
	//writer.DisableDataProtection();
	
	for (unsigned short address = 0; address < 0x7FFF; address++) {
		writer.WriteByte(address, static_cast<unsigned char>(0));
		//std::cout << std::hex << address << ": "
		//	<< ((~address) & 0xFF) << " ";
		if ((address % 16) == 0) {
			//std::cout << "\n";
		}
	}
		
	std::cout << "\nWrite test complete\n";
}


int main()
{
	TestWrite();
	
	return 0;
}
