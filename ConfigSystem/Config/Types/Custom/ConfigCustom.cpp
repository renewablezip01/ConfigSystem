#include "pch.h"
#include "ConfigCustom.h"

ConfigCustom::ConfigCustom(ConfigCollection& configCollection, const std::string& name, Custom data)
{
	this->m_Name = name;
	this->m_Data = data;
	configCollection.insert({ name, (ConfigInterface*)this });
}

ConfigCustom::operator Custom& ()
{
	return this->m_Data;
}

ConfigCustom::operator Custom* ()
{
	return &this->m_Data;
}

void ConfigCustom::operator=(Custom value)
{
	this->m_Data = value;
}

Custom& ConfigCustom::operator()()
{
	return m_Data;
}

void ConfigCustom::Write(nlohmann::json& json)
{
	json[this->m_Name]["x"] = m_Data.x;
	json[this->m_Name]["y"] = m_Data.y;
	json[this->m_Name]["z"] = m_Data.z;
}

void ConfigCustom::Read(const nlohmann::json& json)
{
	if (json[m_Name].is_object())
	{
	m_Data.x = json[this->m_Name]["x"];
	m_Data.y = json[this->m_Name]["y"];
	m_Data.z = json[this->m_Name]["z"];
	}
}
