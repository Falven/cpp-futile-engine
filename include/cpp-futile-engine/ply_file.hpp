#include <iostream>
#include <string>
#include <boost/iostreams/device/mapped_file.hpp>

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

};
