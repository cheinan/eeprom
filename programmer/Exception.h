#pragma once

#include <exception>
#include <string>


class EEPROMException : public std::exception
{
public:
	EEPROMException(const std::string& message) : m_message(message) {}
	
	virtual const char* what() const throw() { return m_message.c_str(); }

private:
	std::string m_message;
};
