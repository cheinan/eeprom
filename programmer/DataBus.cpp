#include <iostream>
#include <array>

#include <unistd.h>

#include "SimpleGPIO.h"
#include "DataBus.h"

const std::array<unsigned char, 8> DataBus::m_data_gpio =
	{{69, 68, 45, 44, 23, 26, 47, 46}};


DataBus::DataBus()
{
	for (const auto gpio : m_data_gpio) {
		gpio_export(gpio);
		gpio_set_dir(gpio, OUTPUT_PIN);
	}
}


DataBus::~DataBus()
{
	for (const auto gpio : m_data_gpio) {
		gpio_unexport(gpio);
	}
}


void DataBus::Set(unsigned char the_data)
{
	for (unsigned char i = 0; i < m_data_gpio.size(); i++) {
		if ((the_data & 1) == 1) {
            gpio_set_value(m_data_gpio[i], HIGH);
		} else {
            gpio_set_value(m_data_gpio[i], LOW);
		}
		
		the_data >>= 1;
	}
}
