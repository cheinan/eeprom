#include <unistd.h>
#include <iostream>

int main()
{
	for (unsigned i = 0; i < 100000; i++) {
		::usleep(1);
		::usleep(1);
		::usleep(1);
	}
	
	return 0;
}
