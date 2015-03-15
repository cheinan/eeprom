#pragma once

#include <vector>

#include "ControlLines.h"
#include "AddressBus.h"
#include "DataBus.h"

class Read
{
public:
	Read();
	~Read();
	
	unsigned char ReadByte(unsigned short address);
	std::vector<unsigned char> ReadBlock(unsigned short address, unsigned short length);

private:
	ControlLines m_control;
	AddressBus	m_address;
	DataBus	m_data;
};
