#include <iostream>
#include <unistd.h>

#include "Read.h"

void TestRead()
{
	std::cout << "Beginning read test";
	
	Read	reader;
	
	for (unsigned short address = 0; address < 0x7FFF; address++) {
		::usleep(1);
		std::cout << std::hex << address << ": "
			<< static_cast<unsigned short>(reader.ReadByte(address)) << " ";
		
		if (address% 16 == 0) {
			std::cout << "\n";
		}
	}
		
	std::cout << "Read test complete\n";
}


int main()
{
	TestRead();
	
	return 0;
}
