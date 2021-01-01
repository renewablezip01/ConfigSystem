#include "pch.h"
#include "Disk.h"

bool Disk::SaveStringToFile(const std::string& path, const std::string& data)
{
	std::ofstream file(path);
	if (file.bad() || !file.is_open()) return false;
	file << data;
	file.close();
}

std::string Disk::ReadFileToString(const std::string& path)
{
	std::ifstream file(path);
	if (file.bad() || !file.is_open()) return "";
	std::stringstream ss;
	std::string line;

	while (std::getline(file, line)) {
		ss << line;
	}

	file.close();

	return ss.str();
}
