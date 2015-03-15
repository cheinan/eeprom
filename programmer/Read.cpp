#include <unistd.h>

#include "Read.h"

Read::Read() : m_control(LOW, HIGH, HIGH), m_data(false)
{
}


Read::~Read()
{
}
	

unsigned char Read::ReadByte(unsigned short address)
{
	m_control.SetOutputEnable(HIGH);
	::usleep(1);
	m_address.Set(address);
	::usleep(1);
	m_control.SetOutputEnable(LOW);
	::usleep(1);
	unsigned char data = m_data.Get();
	::usleep(1);
	m_control.SetOutputEnable(HIGH);
	
	return data;
}


std::vector<unsigned char> Read::ReadBlock(unsigned short address, unsigned short length)
{
	std::vector<unsigned char> block;
	
	return block;
}
