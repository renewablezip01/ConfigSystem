#include "pch.h"
#include "ConfigFloat.h"


ConfigFloat::ConfigFloat(ConfigCollection& configCollection, const std::string& name, float data)
{
	this->m_Name = name;
	this->m_Data = data;

	/* Inserts our variable into the Config Collection */
	configCollection.insert({ name,(ConfigInterface*)(this) });
}

ConfigFloat::operator float& ()
{
	return m_Data;
}

ConfigFloat::operator float* ()
{
	return &m_Data;
}

void ConfigFloat::operator=(float value)
{
	this->m_Data = value;
}

float& ConfigFloat::operator()()
{
	return this->m_Data;
}

void ConfigFloat::Write(nlohmann::json& json)
{
	json[m_Name] = m_Data;
}

void ConfigFloat::Read(const nlohmann::json& json)
{
	if (json[m_Name].is_number_float())
		m_Data = json[m_Name];
}

