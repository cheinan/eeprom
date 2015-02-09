#pragma once

#include <array>

class DataBus
{
public:
	DataBus();
	~DataBus();

	void Set(unsigned char the_data);

private:
	static const std::array<unsigned char, 8> m_data_gpio;
};
