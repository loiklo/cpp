#include <iostream>
#include <fstream>
#include <boost/crc.hpp>

int GetCrc32(const std::string& my_string) {
	boost::crc_32_type result;
	result.process_bytes(my_string.data(), my_string.length());
	return result.checksum();
}

void printCrcOfFile(const char *filename) {
	std::ifstream lfile("data", std::ios::in | std::ios::binary | std::ios::ate);
	std::cout << " " << std::endl;
	boost::crc_32_type result;
	std::cout << "filesize: " << lfile.tellg() << std::endl;
//	result.process_bytes(&lfile, lfile.tellg());
	
	//convert ifstream to byte[]
	std::ifstream::pos_type size;
	size = lfile.tellg();
	char* oData;
	oData = new char[size];
	lfile.read(oData, size);
	
	result.process_bytes(oData, size);
	std::cout << result.checksum() << std::endl;
	lfile.close();
}

int main(){
	std::cout << GetCrc32("alexandre") << std::endl;
	std::cout << GetCrc32("Alexandre") << std::endl;
	printCrcOfFile("hello");
}
