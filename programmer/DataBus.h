#pragma once

#include <array>

class DataBus
{
public:
	// Set is_data_out to true when BBB is writing data from BBB to data bus.
	// False means reading data from bus to BBB.
	DataBus(bool is_data_out);
	~DataBus();

	void Set(unsigned char the_data);
	unsigned char Get();

private:
	static const std::array<unsigned char, 8> m_data_gpio;
	bool m_is_data_out;
};
