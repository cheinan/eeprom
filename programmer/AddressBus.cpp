#include <string>
#include <array>

#include "SimpleGPIO.h"
#include "AddressBus.h"

const std::array<unsigned char, 16> AddressBus::m_address_gpio =
	{{2, 3, 4, 5, 51, 48, 50, 31, 49, 15, 115, 14, 60, 66, 30, 67}};


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


void AddressBus::Set(unsigned short the_address)
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
