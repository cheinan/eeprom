#pragma once

#include "SimpleGPIO.h"
#include "ControlLines.h"

class ControlLines
{
public:
	ControlLines();
	ControlLines(PIN_VALUE chip_enable, PIN_VALUE write_enable, PIN_VALUE output_enable);
	~ControlLines();

	void SetChipEnable(PIN_VALUE chip_enable_value);
	void SetWriteEnable(PIN_VALUE write_enable_value);
	void SetOutputEnable(PIN_VALUE output_enable_value);
	void DisableAll();

private:
	const unsigned short m_ce_gpio = 22;
	const unsigned short m_we_gpio = 65;
	const unsigned short m_oe_gpio = 27;
	
	PIN_VALUE m_chip_enable = HIGH;
	PIN_VALUE m_write_enable = HIGH;
	PIN_VALUE m_output_enable = HIGH;
	
	void	InitializePins();
};
