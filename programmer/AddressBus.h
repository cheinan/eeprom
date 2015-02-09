#pragma once

#include <array>

class AddressBus
{
public:
	AddressBus();
	~AddressBus();

	void Set(unsigned short the_address);

private:
	static const std::array<unsigned char, 16> m_address_gpio;
};
