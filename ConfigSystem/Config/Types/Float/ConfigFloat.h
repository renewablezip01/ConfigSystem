#pragma once
#include "Config/Types/ConfigInterface.h"

class ConfigFloat : virtual public ConfigInterface
{
public:
	friend class Serialization;
	/* Our operator overloads so that our config value can act as the desired data type */
	operator float& ();
	operator float* ();
	void operator=(float value);
	float& operator()();
private:
	ConfigFloat(ConfigCollection& configCollection, const std::string& name, float data);
	/* Defines the way to write into our json */
	void Write(nlohmann::json& json) override;
	/* Defines the way to read from our json */
	void Read(const nlohmann::json& json) override;
private:
	float m_Data;
};

