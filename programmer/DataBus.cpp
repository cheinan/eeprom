#include <iostream>
#include <array>
#include <string>

#include <unistd.h>

#include "SimpleGPIO.h"
#include "DataBus.h"
#include "Exception.h"

const std::array<unsigned char, 8> DataBus::m_data_gpio =
	{{69, 68, 45, 44, 23, 26, 47, 46}};


DataBus::DataBus(bool is_data_out) : m_is_data_out(is_data_out)
{
	for (const auto gpio : m_data_gpio) {
		gpio_export(gpio);
		gpio_set_dir(gpio, is_data_out ? OUTPUT_PIN : INPUT_PIN);
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
	if (! m_is_data_out) {
		throw EEPROMException("Tried to write to data bus that is configured for reading");
	}
	
	//std::cout << std::hex << static_cast<unsigned short>(the_data);
	
	for (unsigned char i = 0; i < m_data_gpio.size(); i++) {
		if ((the_data & 1) == 1) {
            gpio_set_value(m_data_gpio[i], HIGH);
		} else {
            gpio_set_value(m_data_gpio[i], LOW);
		}
		//std::cout << " " << (the_data & 1);
		
		the_data >>= 1;
	}
	//std::cout << "\n";
}


unsigned char DataBus::Get()
{
	if (m_is_data_out) {
		throw EEPROMException("Tried to read from a data bus that is configured for writing");
	}
	
	unsigned char data = 0;
	unsigned int gpio_value;
	for (unsigned char i = 0; i < m_data_gpio.size(); i++) {
		int ret = gpio_get_value(m_data_gpio[i], &gpio_value);
		if (ret) {
			throw EEPROMException("DataBus::Read> gpio_get_value failed");
		}
		data += gpio_value << i;
	}
	
	return data;
}
