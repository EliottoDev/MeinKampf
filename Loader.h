#pragma once

#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <vector>
#include <map>
#include <json/value.h>
#include <fstream>
#include "nlohmann/json.hpp"

namespace utils {

	struct File {
		std::string name;
		std::string path;
		FileType type;
	};

	class Loader
	{

	private:
		
		std::vector<File> yml;
		std::vector<File> json;
		std::vector<File> xml;
		std::map<std::string, std::string> archivos;

	public:
		Loader();
		void load(std::string name, std::string path, std::string type);
		std::map<std::string, std::vector<File>> getFiles();
		void addFile(File);
	};

	enum FileType{
		JSON = 0, XML = 1, YAML = 2
	};
}

#endif LOADER_H