#include "pch.h"
#include "ConfigBool.h"

ConfigBool::operator bool& ()
{
	return this->m_Data;
}

ConfigBool::operator bool* ()
{
	return &this->m_Data;
}

void ConfigBool::operator=(bool value)
{
	this->m_Data = value;
}

bool& ConfigBool::operator()()
{
	return this->m_Data;
}

ConfigBool::ConfigBool(ConfigCollection& configCollection, const std::string& name, bool data)
{
	this->m_Name = name;
	this->m_Data = data;
	configCollection.insert({ name,(ConfigInterface*)this });
}

void ConfigBool::Write(nlohmann::json& json)
{
	json[this->m_Name] = m_Data;
}

void ConfigBool::Read(const nlohmann::json& json)
{
	if (json[this->m_Name].is_boolean())
		m_Data = json[this->m_Name];
}
