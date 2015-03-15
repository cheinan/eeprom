#include <unistd.h>
#include <iostream>

#include "Exception.h"
#include "Write.h"

Write::Write() : m_control(LOW, HIGH, HIGH), m_data(true)
{
}


Write::~Write()
{
	m_control.DisableAll();
}


void	Write::WriteByte(unsigned short address, unsigned char data)
{
	m_control.SetWriteEnable(HIGH);
	m_address.Set(address);
	m_data.Set(data);
	//std::cout << "Ready to write " << address << ": " << static_cast<unsigned short>(data) << "\n";
	//std::cin.get();
	m_control.SetWriteEnable(LOW);

	::usleep(1);
	m_control.SetWriteEnable(HIGH);
	::usleep(10000);
}


void	Write::WritePage(unsigned short address, const std::array<unsigned char, 64>& page)
{
	throw EEPROMException("Write::WritePage is not yet implemented");
}


void	Write::BulkWrite(unsigned short address, const std::vector<unsigned char>& block)
{
	throw EEPROMException("Write::BulkWrite is not yet implemented");
}


void	Write::DisableDataProtection()
{
	WriteByte(0x5555, 0xAA);
	WriteByte(0x2AAA, 0x55);
	WriteByte(0x5555, 0x80);
	WriteByte(0x5555, 0xAA);
	WriteByte(0x2AAA, 0x55);
	WriteByte(0x5555, 0x20);
}


void	Write::EnableDataProtection()
{
	WriteByte(0x5555, 0xAA);
	WriteByte(0x2AAA, 0x55);
	WriteByte(0x5555, 0xA0);
}
