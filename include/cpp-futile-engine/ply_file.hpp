#ifndef PLY_FILE_HPP
#define PLY_FILE_HPP

#include <boost/iostreams/device/mapped_file.hpp>	// for mmap
#include <boost/iostreams/stream.hpp>				// for stream
#include <boost/algorithm/string.hpp>				// for trim
#include <iostream>									// for std::cout
#include <cstdint>									// for uintmax_t
#include <string>

#include "parse_exception.hpp"
#include "model.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	
/// 			A simple file type for the description of objects that are a collection of polygons.
/// 			PLY files are:
///					ASCII or binary
///					3D
///					No compression
///					1 image
/// </summary>
///
/// <remarks>	Falven, 2/11/2017. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
class ply_file
{
public:
	void read_seq(const std::string & ply_file_path)
	{

	}

	void read_mmap(const std::string & ply_file_path)
	{
		using boost::iostreams::mapped_file_source;
		using boost::iostreams::stream;

		mapped_file_source mmap(ply_file_path);
		stream<mapped_file_source> is(mmap, std::ios::binary);

		uintmax_t cur_line = 0;

		if (!parse_header(is, cur_line))
		{
			throw parse_exception(ply_file_path, cur_line);
		}

		std::cout << "num_lines = " << cur_line << "\n";
	}

	void write(const std::string & ply_file_path)
	{

	}

private:
	static const std::string MAGIC_NUMBER;
	model ply_model_;

	bool parse_header(
		boost::iostreams::stream<boost::iostreams::mapped_file_source> & is,
		uintmax_t & cur_line)
	{
		std::string line;
		std::getline(is, line);
		cur_line++;

		boost::trim(line);
		return line == MAGIC_NUMBER;
	}

	bool parse_format()
	{

		return true;
	}
};

const std::string ply_file::MAGIC_NUMBER = "ply";

#endif