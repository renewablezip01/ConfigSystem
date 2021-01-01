#pragma once
#include "Config/ConfigInterface.h"

class ConfigFloat : virtual public ConfigInterface
{
public:
	ConfigFloat(ConfigCollection& configCollection, const std::string& name, float data);

public:
	/* Our operator overloads so that our config value can act as the desired data type */
	operator float& ();
	operator float* ();
	void operator=(float value);
	float& operator()();

protected:
	/* Defines the way to write into our json */
	void Write(nlohmann::json& json) override;
	/* Defines the way to read from our json */
	void Read(const nlohmann::json& json) override;
private:
	float m_Data;
	std::string m_Name;

};

