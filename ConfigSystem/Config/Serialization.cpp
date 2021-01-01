#include "pch.h"
#include "Serialization.h"

/* Our default file path for saving/loading */
std::string Serialization::FilePath = "Save.txt";

/* Saves our save file into local machine storage */
void Serialization::Save(const std::string& path)
{
	/* Loops through our data collection and calls Write on every created ConfigInterface */
	for (auto& index : m_DataSave) {
		index.second->Write(m_Json);
	}
	/* Calls the function to write to file */
	Disk::SaveStringToFile(path, m_Json.dump(1));
}

/* Loads data from our saved file in our local machine. */
void Serialization::Load(const std::string& path)
{
	/* Reads our local file and saves it into fromDisk */
	std::string fromDisk = Disk::ReadFileToString(path);
	if (fromDisk.empty()) return;
	/* Parses fromDisk into JSON */
	m_Json = nlohmann::json::parse(fromDisk);
	/* Loops through our created variables and calls Read for ConfigInterface */
	for (auto& index : m_DataSave) {
		index.second->Read(m_Json);
	}

}
/* A simple Json getter */
const nlohmann::json Serialization::GetJson() const
{
	return m_Json;
}
/* Creates a ConfigInteger variable */
ConfigInteger Serialization::CreateInt(const std::string& name, int value)
{
	return ConfigInteger(this->m_DataSave, name, value);
}

ConfigFloat Serialization::CreateFloat(const std::string& name, float value)
{
	return ConfigFloat(this->m_DataSave, name, value);

}

ConfigString Serialization::CreateString(const std::string& name, const std::string& value)
{
	return ConfigString(this->m_DataSave,name,value);
}
