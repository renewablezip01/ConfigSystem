#pragma once
#include "Config/Types/ConfigInterface.h"

class ConfigBool : virtual public ConfigInterface
{
public:
	friend class Serialization;
	/* Our operator overloads so that our config value can act as the desired data type */
	operator bool& ();
	operator bool* ();
	void operator=(bool value);
	bool& operator()();

private:
	ConfigBool(ConfigCollection& configCollection, const std::string& name, bool data);
	/* Defines the way to write into our json */
	void Write(nlohmann::json& json) override;
	/* Defines the way to read from our json */
	void Read(const nlohmann::json& json) override;
private:
	bool m_Data;
};

