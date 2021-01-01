#pragma once

class Disk {

public:
	/* Saves our string into a file */
	static bool SaveStringToFile(const std::string& path, const std::string& data);

	/* Reads our file data into a std::string */
	static std::string ReadFileToString(const std::string& path);
};


