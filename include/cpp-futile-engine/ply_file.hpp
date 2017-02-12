#ifndef PLY_FILE_HPP
#define PLY_FILE_HPP

#include <boost/iostreams/device/mapped_file.hpp>
#include <algorithm>  // for std::find
#include <iostream>   // for std::cout
#include <string>
#include <cstring>

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
	ply_file()
	{
	}

	~ply_file()
	{
	}

	void read(const std::string ply_file_path)
	{
		boost::iostreams::mapped_file mapf(ply_file_path, boost::iostreams::mapped_file::readonly);
		std::cout << "" << std::endl;
	}

	void write(const std::string ply_file_path)
	{

	}

private:
	model ply_model;
};

#endif