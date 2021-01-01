#include "pch.h"
#include "Config/Serialization.h"

int main() {
	Serialization serialize;
	/* Initiliaze the wanted variables */

	ConfigInteger& health = serialize.CreateInt("Health", 100);
	ConfigFloat& speed = serialize.CreateFloat("Speed", 184.54f);
	ConfigString& name = serialize.CreateString("Username", "Johnnyyyyy");
	ConfigCustom& customType = serialize.CreateCustom("CustomTypeExample", { 76.7,436.3,8677.3f });
	ConfigBool& rememberMe = serialize.CreateBool("Remember me", true);
	
	/* Loads the saved data from our storage */
	serialize.Load();

	/* Modify variables after the Serialization::Load(); */
	health = 54;
	speed = 848.4f;

	/* Example of a cast */
	ConfigString* castedName = dynamic_cast<ConfigString*>(serialize["Username"]);
	if (castedName != nullptr)
		*castedName = "Max";

	std::cout << "-----------------------------------------------------" << "\n";

	/* Call save whenever you want to save the data */
	serialize.Save();

	std::cout << serialize.GetJson().dump(1) << "\n";

	return 0;
}