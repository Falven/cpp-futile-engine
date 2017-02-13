#ifndef PARSE_EXCEPTION_HPP
#define PARSE_EXCEPTION_HPP

#include <stdexcept>	// for runtime_error
#include <cstdint>		// for uintmax_t

class parse_exception : public std::runtime_error
{
public:
	explicit parse_exception(const std::string & file_name, const uintmax_t & line)
		: std::runtime_error("Error parsing file " + file_name + ":" + std::to_string(line))
		, file_name_(file_name)
		, line_(line)
	{}

private:
	std::string file_name_;
	uintmax_t line_;
};

#endif