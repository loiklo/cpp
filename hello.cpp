#include <iostream>
#include <boost/filesystem.hpp>
namespace bf = boost::filesystem;

// if filename is a regular file, print file name and file size
void printsize(const bf::directory_entry& filename) {
	if ( bf::is_regular_file(filename) ) {
		std::cout << filename << " : " << bf::file_size(filename) << std::endl;
	}
}


int main(int argc, char* argv[]) {
	std::cout << "Begin" << std::endl; //program start

	// lpath is current directory if no directory specified
	const std::string lpath = argc == 2?argv[1]: "./";

	// Recursion from current directory
	for(bf::recursive_directory_iterator end, dir(lpath); dir != end; ++dir ) {
		printsize(*dir);
	}

	std::cout << "End" << std::endl; //program end
	return 0;
}
