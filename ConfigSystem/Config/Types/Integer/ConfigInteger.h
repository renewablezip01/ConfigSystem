#pragma once
#include "Config/ConfigInterface.h"


class ConfigInteger : virtual public ConfigInterface
{
public:
	ConfigInteger(ConfigCollection& configCollection, const std::string& name, int data);

public:
	/* Our operator overloads so that our config value can act as the desired data type */
	operator int&();
	operator int*();
	void operator=(int value);
	int& operator()();
protected:
	/* Defines the way to write into our json */
	void Write(nlohmann::json& json) override;
	/* Defines the way to read from our json */
	void Read(const nlohmann::json& json) override;
private:
	int m_Data;
	std::string m_Name;
};
