#include <string>
#include <chrono>
#include <vector>
#include <fstream>
#include <iostream>

bool LoadFileByVector(const std::string& filename, std::string* result) {
	std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open()) {
		size_t size = file.tellg();
		std::vector<char> buffer(size);
		file.seekg (0, std::ios::beg);
		file.read(buffer.data(), size);
		file.close();
		if (!file) return false;  // file reading error (failbit or badbit).
		result->assign(buffer.begin(), buffer.end());
		return true;
	}
	return false;
}

bool LoadFileByString(const std::string& filename, std::string* result) {
	std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open()) {
		size_t size = file.tellg();
		//result->reserve(size);
		// without using resize, even after reading in the file
		// the string had a length of zero because walking the 
		// pointer didn't change the string's internal state for
		// length
		result->resize(size);
		file.seekg (0, std::ios::beg);
		file.read(&(*result)[0], size);
		file.close();
		if (!file) return false;  // file reading error (failbit or badbit).
		return true;
	}
	return false;
}

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "file please...." << std::endl;
	}
	std::string filename = argv[1];

	// warm-up so as not to skew results
	{
		std::string junk1;
		auto result = LoadFileByString(filename, &junk1);
		std::cerr << result << std::endl;

		std::string junk2;
		LoadFileByVector(filename, &junk2);

		// figuring out that string::reserve and string::resize
		// needed to be used differently
		std::cout << (junk1.compare(junk2)) << std::endl;
		//std::cout << junk1 << std::endl;
		//std::cout << "----" << std::endl;
		//std::cout << junk2 << std::endl;
	}

	std::chrono::duration<double> elapsed1(0);
	std::chrono::duration<double> elapsed2(0);

	for( int x = 0; x < 200000; x++)
	{
		std::string result1;
		{	
			auto start1 = std::chrono::high_resolution_clock::now();
			LoadFileByString(filename, &result1);
			auto finish1 = std::chrono::high_resolution_clock::now();
			elapsed1 += finish1 - start1;
		}
		std::string result2;
		{
			auto start2 = std::chrono::high_resolution_clock::now();
			LoadFileByVector(filename, &result2);
			auto finish2 = std::chrono::high_resolution_clock::now();
			elapsed2 += finish2 - start2;
		}
	}
	std::cout << "time in seconds for ByString: " << elapsed1.count() << std::endl;
	std::cout << "time in seconds for ByVector: " << elapsed2.count() << std::endl;
}

