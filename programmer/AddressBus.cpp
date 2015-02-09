#include <string>
#include <array>

#include "SimpleGPIO.h"
#include "AddressBus.h"

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
