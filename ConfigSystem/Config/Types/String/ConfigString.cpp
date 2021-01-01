#include "pch.h"
#include "ConfigString.h"

ConfigString::ConfigString(ConfigCollection& configCollection, const std::string& name, const std::string& data)
{
	this->m_Name = name;
	this->m_Data = data;
	configCollection.insert({ name,(ConfigInterface*)this});
}

ConfigString::operator std::string& ()
{
	return this->m_Data;
}

ConfigString::operator std::string* ()
{
	return &this->m_Data;

}

void ConfigString::operator=(const std::string& value)
{
	this->m_Data = value;
}

std::string& ConfigString::operator()()
{
	return this->m_Data;
}

void ConfigString::Write(nlohmann::json& json)
{
	json[m_Name] = m_Data;

}

void ConfigString::Read(const nlohmann::json& json)
{
	if (json[m_Name].is_string())
		m_Data = json[m_Name];
}
