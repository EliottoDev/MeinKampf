#include "Loader.h"

using json = nlohmann::json;


void utils::Loader::addFile(utils::File file) {
	
	if (file.type == utils::FileType::JSON) {
		this->json.push_back(file);
		std::ifstream archivo(file.path, std::ifstream::binary);
		Json::Reader reader();

	}
	if (file.type == utils::FileType::XML) {
		this->xml.push_back(file);
		// TODO cargar el archivo
	}
	if (file.type == utils::FileType::YAML) {
		this->yml.push_back(file);
		// TODO cargar el archivo
	}
};
