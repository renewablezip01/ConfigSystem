#pragma once
#include "Config/Types/Integer/ConfigInteger.h"
#include "Config/Types/Float/ConfigFloat.h"
#include "Config/Types/String/ConfigString.h"
#include "Config/Types/Custom/ConfigCustom.h"
#include "Config/Types/Bool/ConfigBool.h"

/// <summary>
/// Serializes our variables into a local file
/// </summary>

class Serialization
{
public:
	/* Example of how to use the serializer */
	static void LoadExample();
	/* Saves the data into a file */
	void Save(const std::string& path = FilePath);
	/* Loads data from the file into our m_Json */
	void Load(const std::string& path = FilePath);
	/* Getter for our json file */
	const nlohmann::json GetJson() const;

	template<typename Type>
	Type& Get(const std::string& name) {
		Type* result = dynamic_cast<Type*>(m_DataSave[name]);
		if (result == nullptr) {
			std::cout << "Attemping to grab: " << name << " resulted in nullptr" << "\n";
		}
		return *result;
	}

public:
	/* Creates a Config Integer variable */
	ConfigInteger& CreateInt(const std::string& name, int value);
	ConfigFloat& CreateFloat(const std::string& name, float value);
	ConfigBool& CreateBool(const std::string& name, bool value);
	ConfigString& CreateString(const std::string& name, const std::string& value);
	ConfigCustom& CreateCustom(const std::string& name, Custom value);


private:

	/* Our default saving/loading path */
	static std::string FilePath;
	/* Used for writes/reads in our m_DataSave loop */
	nlohmann::json m_Json;
	/* All our creates variables goes into this collection. Will be used to loop through it for Saving/Loading */
	std::unordered_map<std::string, ConfigInterface*> m_DataSave = std::unordered_map<std::string, ConfigInterface*>();
};

