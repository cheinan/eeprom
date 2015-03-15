#include "SimpleGPIO.h"
#include "ControlLines.h"
#include "Exception.h"


ControlLines::ControlLines()
{
	InitializePins();
	
	DisableAll();
}


ControlLines::ControlLines(PIN_VALUE chip_enable,
	PIN_VALUE write_enable, PIN_VALUE output_enable)
{
	InitializePins();
	
	SetWriteEnable(write_enable);
	SetOutputEnable(output_enable);
	SetChipEnable(chip_enable);
}


ControlLines::~ControlLines()
{
	gpio_unexport(m_ce_gpio);
	gpio_unexport(m_we_gpio);
	gpio_unexport(m_oe_gpio);
}


void	ControlLines::InitializePins()
{
	gpio_export(m_ce_gpio);
	gpio_set_dir(m_ce_gpio, OUTPUT_PIN);

	gpio_export(m_we_gpio);
	gpio_set_dir(m_we_gpio, OUTPUT_PIN);

	gpio_export(m_oe_gpio);
	gpio_set_dir(m_oe_gpio, OUTPUT_PIN);

	gpio_set_value(m_ce_gpio, HIGH);
	gpio_set_value(m_we_gpio, HIGH);
	gpio_set_value(m_oe_gpio, HIGH);
}


void ControlLines::SetChipEnable(PIN_VALUE chip_enable_value)
{
	if (m_chip_enable != chip_enable_value) {
		gpio_set_value(m_ce_gpio, chip_enable_value);
		m_chip_enable = chip_enable_value;
	}
}


void ControlLines::SetWriteEnable(PIN_VALUE write_enable_value)
{
	if ((m_output_enable == LOW) && (write_enable_value == LOW)) {
		throw EEPROMException("Tried to set write enable low when output enable is already low");
	}

	if (m_write_enable != write_enable_value) {
		gpio_set_value(m_we_gpio, write_enable_value);
		m_write_enable = write_enable_value;
	}
}


void ControlLines::SetOutputEnable(PIN_VALUE output_enable_value)
{
	if ((m_write_enable == LOW) && (output_enable_value == LOW)) {
		throw EEPROMException("Tried to set output enable low when write enable is already low");
	}

	if (m_output_enable != output_enable_value) {
		gpio_set_value(m_oe_gpio, output_enable_value);
		m_output_enable = output_enable_value;
	}
}


void ControlLines::DisableAll()
{
	SetWriteEnable(HIGH);
	SetOutputEnable(HIGH);
	SetChipEnable(HIGH);
}
