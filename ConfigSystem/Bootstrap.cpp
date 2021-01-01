#include "pch.h"
#include <iostream>
#include "Config/Serialization.h"

int main() {
	Serialization serialize;
	ConfigInteger health = serialize.CreateInt("Health", 100);
	ConfigInteger health2 = serialize.CreateInt("Health2", 99);
	ConfigFloat speed = serialize.CreateFloat("Speed", 84.54f);
	ConfigString name = serialize.CreateString("Username", "Donkey");
	ConfigCustom customType = serialize.CreateCustom("Fatty", { 76.7,436.3,8677.3f });

	serialize.Load();
	std::cout << serialize.GetJson().dump(1) << "\n";
	std::cout << "-----------------------------------------------------" << "\n";
	serialize.Save();

	std::cout << serialize.GetJson().dump(1) << "\n";

	return 0;
}