#include "SimpleGPIO.h"
#include "ControlLines.h"


ControlLines::ControlLines()
{
	gpio_export(m_ce_gpio);
	gpio_set_dir(m_ce_gpio, OUTPUT_PIN);

	gpio_export(m_we_gpio);
	gpio_set_dir(m_we_gpio, OUTPUT_PIN);

	gpio_export(m_oe_gpio);
	gpio_set_dir(m_oe_gpio, OUTPUT_PIN);
}


ControlLines::~ControlLines()
{
	gpio_unexport(m_ce_gpio);
	gpio_unexport(m_we_gpio);
	gpio_unexport(m_oe_gpio);
}
