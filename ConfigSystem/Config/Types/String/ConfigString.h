#pragma once
#include "Config/Types/ConfigInterface.h"

class ConfigString : virtual public ConfigInterface
{
public:
	friend class Serialization;
	/* Our operator overloads so that our config value can act as the desired data type */
	operator std::string& ();
	operator std::string* ();
	void operator=(const std::string& value);
	std::string& operator()();
private:
	ConfigString(ConfigCollection& configCollection, const std::string& name, const std::string& data);
	/* Defines the way to write into our json */
	void Write(nlohmann::json& json) override;
	/* Defines the way to read from our json */
	void Read(const nlohmann::json& json) override;
private:
	std::string m_Data;
};

