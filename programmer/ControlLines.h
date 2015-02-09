#pragma once

#include "ControlLines.h"

class ControlLines
{
public:
	ControlLines();
	~ControlLines();

	void SetChipEnable(PIN_VALUE is_high) { gpio_set_value(m_ce_gpio, is_high); }
	void SetWriteEnable(PIN_VALUE is_high) { gpio_set_value(m_we_gpio, is_high); }
	void SetOutputEnable(PIN_VALUE is_high) { gpio_set_value(m_oe_gpio, is_high); }

private:
	const unsigned short m_ce_gpio = 27;
	const unsigned short m_we_gpio = 65;
	const unsigned short m_oe_gpio = 22;
};
