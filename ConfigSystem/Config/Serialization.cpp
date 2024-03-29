#include "pch.h"
#include "Serialization.h"

/* Our default file path for saving/loading */
std::string Serialization::FilePath = "Save.json";

void Serialization::LoadExample()
{
	Serialization serialize;
	/* Initiliaze the wanted variables */

	int& health = serialize.CreateInt("Health", 100);
	float& speed = serialize.CreateFloat("Speed", 184.54f);
	bool& rememberMe = serialize.CreateBool("Remember me", true);
	std::string& name = serialize.CreateString("Username", "Johnnyyyyy");
	Custom& customType = serialize.CreateCustom("CustomTypeExample", { 76.7f, 436.3f, 8677.3f });
	ConfigVector<std::string>& Phrases = serialize.CreateVector<std::string>("Phrases", { "Hello there", "I see you", "Yes" });

	/* Loads the saved data from our storage */
	serialize.Load();

	/* Modify variables after the Serialization::Load(); */
	health = 9898;
	speed = 848.4f;
	Phrases.PushBackOnce("Pushed back once"); /* Pushes an element back once into the vector. */

	/* Example of a cast */
	ConfigString& castedName = serialize.Get<ConfigString>("Username");
	castedName = "Max";

	for (const std::string& player : (std::vector<std::string>&)Phrases) {
		/* Loop through the ConfigVector */
	}

	/* Call save whenever you want to save the data */
	serialize.Save();

	std::cout << serialize.GetJson().dump(1) << "\n";
}

/* Saves our save file into local machine storage */
void Serialization::Save(const std::string& path)
{
	/* Loops through our data collection and calls Write on every created ConfigInterface */
	for (const auto& index : m_DataSave) {
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
	for (const auto& index : m_DataSave) {
		index.second->Read(m_Json);
	}

}
/* A simple Json getter */
const nlohmann::json Serialization::GetJson() const
{
	return m_Json;
}

/* Creates a ConfigInteger variable */
ConfigInteger& Serialization::CreateInt(const std::string& name, int value)
{
	return *new ConfigInteger(this->m_DataSave, name, value);
}

ConfigFloat& Serialization::CreateFloat(const std::string& name, float value)
{
	return *new ConfigFloat(this->m_DataSave, name, value);
}

ConfigBool& Serialization::CreateBool(const std::string& name, bool value)
{
	return *new ConfigBool(this->m_DataSave, name, value);

}

ConfigString& Serialization::CreateString(const std::string& name, const std::string& value)
{
	return *new ConfigString(this->m_DataSave, name, value);
}

ConfigCustom& Serialization::CreateCustom(const std::string& name, Custom value)
{
	return *new ConfigCustom(this->m_DataSave, name, value);
}