#pragma once
#include "Config/Types/ConfigInterface.h"
template<typename Type>
class ConfigVector : virtual public ConfigInterface
{
public:
	friend class Serialization;
	/* Our operator overloads so that our config value can act as the desired data type */
	operator std::vector<Type>& () {
		return this->m_Data;
	}
	operator std::vector<Type>* () {

		return &this->m_Data;
	}

	void operator=(const std::vector<Type>& value) {
		this->m_Data = value;
	}
	std::vector<Type>& operator()() {
		return this->m_Data;
	}

	/* A simple function that checks if an element doesn't exist in the vector then add it once */
	void PushBackOnce(const Type& value) {
		if (std::find(this->m_Data.begin(), this->m_Data.end(), value) == this->m_Data.end()) {
			this->m_Data.push_back(value);
		}
	}

private:
	ConfigVector(ConfigCollection& configCollection, const std::string& name, const std::vector<Type>& data)
		: m_Name(name), m_Data(data)
	{
		configCollection.insert({ name,(ConfigInterface*)this });
	}

	/* Defines the way to write into our json */
	void Write(nlohmann::json& json) override {
		json[m_Name] = m_Data;
	}

	/* Defines the way to read from our json */
	void Read(const nlohmann::json& json) override {
		if (json[m_Name].is_array()) {
			m_Data.resize(json[m_Name].size());
			for (size_t i = 0; i < json[m_Name].size(); i++)
			{

				m_Data[i] = json[m_Name][i];
			}
		}
	}

private:
	std::vector<Type> m_Data;
};
