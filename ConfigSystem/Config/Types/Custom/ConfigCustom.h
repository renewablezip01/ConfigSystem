#pragma once
#include "Config/ConfigInterface.h"
/// <summary>
/// This is an example of how a custom data type can be done.
/// </summary>

struct Custom {
	float x, y, z;
};

class ConfigCustom : virtual public ConfigInterface
{

public:
	ConfigCustom(ConfigCollection& configCollection, const std::string& name, Custom data);

public:
	/* Our operator overloads so that our config value can act as the desired data type */
	operator Custom& ();
	operator Custom* ();
	void operator=(Custom value);
	Custom& operator()();

protected:
	/* Defines the way to write into our json */
	void Write(nlohmann::json& json) override;
	/* Defines the way to read from our json */
	void Read(const nlohmann::json& json) override;
private:
	Custom m_Data;
	std::string m_Name;
};

