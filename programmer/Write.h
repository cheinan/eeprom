#pragma once

#include <array>
#include <vector>

#include "ControlLines.h"
#include "AddressBus.h"
#include "DataBus.h"

class Write
{
public:
	Write();
	~Write();

	void	WriteByte(unsigned short address, unsigned char byte);
	void	WritePage(unsigned short address, const std::array<unsigned char, 64>& page);
	void	BulkWrite(unsigned short address, const std::vector<unsigned char>& block);

	void	DisableDataProtection();
	void	EnableDataProtection();

private:
	ControlLines m_control;
	AddressBus	m_address;
	DataBus	m_data;
};
