#include <iostream>
#include <string>
#include <array>
#include <type_traits>
#include <cassert>

#include <unistd.h>

#include "SimpleGPIO.h"

class AddressBus
{
public:
	AddressBus();
	~AddressBus();

	void SetAddress(unsigned short the_address);

private:
	static const std::array<unsigned char, 16> m_address_gpio;
};


const std::array<unsigned char, 16> AddressBus::m_address_gpio =
	{{30, 60, 31, 50, 48, 51, 5, 4, 3, 2, 49, 15, 14, 115, 66, 67}};


AddressBus::AddressBus()
{
	for (const auto gpio : m_address_gpio) {
		gpio_export(gpio);
		gpio_set_dir(gpio, OUTPUT_PIN);
	}
}


AddressBus::~AddressBus()
{
	for (const auto gpio : m_address_gpio) {
		gpio_unexport(gpio);
	}
}


void AddressBus::SetAddress(unsigned short the_address)
{
	for (unsigned char i = 0; i < m_address_gpio.size(); i++) {
		if ((the_address & 1) == 1) {
            gpio_set_value(m_address_gpio[i], HIGH);
		} else {
            gpio_set_value(m_address_gpio[i], LOW);
		}
		
		the_address >>= 1;
	}
}


int main(int argc, char *argv[])
{
	std::cout << "Testing the address bus" << std::endl;
	
	AddressBus the_address_bus;

	for(unsigned short i = 0; i < 4 ; i++) {
		the_address_bus.SetAddress(i);
		::usleep(200000);
	}

	the_address_bus.SetAddress(0x5555);
	std::cout << "Type something to flip\n";
	std::string wait;
	std::cin >> wait;
	the_address_bus.SetAddress(0xAAAA);
	std::cout << "Type something to finish\n";
	std::cin >> wait;

	std::cout << "Finished" << std::endl;
	

	return 0;
}

