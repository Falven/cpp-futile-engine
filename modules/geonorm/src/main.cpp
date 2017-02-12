#include "ply_file.hpp"

using namespace std;

int main(int argc, char * argv[])
{
	ply_file pfile;
	pfile.read("C:\\Users\\falven\\Desktop\\Ply\\cube.ply");
	return 0;
}