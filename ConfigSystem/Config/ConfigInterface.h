#pragma once
#include "pch.h"


class ConfigInterface
{
public:
	virtual void Write(nlohmann::json& json) = 0;
	virtual void Read(const nlohmann::json& json) = 0;
protected:
	using ConfigCollection = std::unordered_map<std::string, ConfigInterface*>;
};

