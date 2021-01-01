#include "pch.h"
#include <iostream>
#include "Config/Serialization.h"


int main() {
	Serialization serialize;
	ConfigInteger health = serialize.CreateInt("Health", 100);
	ConfigInteger health2 = serialize.CreateInt("Health2", 99);
	ConfigFloat speed = serialize.CreateFloat("Speed",84.54f);
	ConfigString name = serialize.CreateString("Username", "Donkey");

	serialize.Load();
	name = "ass";
	std::cout << serialize.GetJson().dump(1) << "\n";
	std::cout << "-----------------------------------------------------" << "\n";
	serialize.Save();

	std::cout << serialize.GetJson().dump(1) << "\n";

	return 0;
}