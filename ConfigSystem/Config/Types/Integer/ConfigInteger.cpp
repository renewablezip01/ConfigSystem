#include "pch.h"
#include "ConfigInteger.h"

ConfigInteger::ConfigInteger(ConfigCollection& configCollection, const std::string& name, int data)
{
	this->m_Name = name;
	this->m_Data = data;

	/* Inserts our variable into the Config Collection */
	configCollection.insert({ name,(ConfigInterface*)(this) });
}

ConfigInteger::operator int& ()
{
	return m_Data;
}

ConfigInteger::operator int* ()
{
	return &m_Data;
}

void ConfigInteger::operator=(int value)
{
	this->m_Data = value;
}

int& ConfigInteger::operator()()
{
	return this->m_Data;
}

void ConfigInteger::Write(nlohmann::json& json)
{
	json[m_Name] = m_Data;
}

void ConfigInteger::Read(const nlohmann::json& json)
{
	if (json[m_Name].is_number_integer())
		m_Data = json[m_Name];
}

