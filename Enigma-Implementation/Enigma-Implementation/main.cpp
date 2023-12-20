#include <Enigma.h>

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	ENIGMA_MACHINE machine{};
	bool bUseDefaultSettings = true;
	int customSettingsLoc = -1;

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-c") == 0)
		{
			bUseDefaultSettings = false;
			customSettingsLoc = i;
			break;
		}
	}

	machine.SetRotorDataPath("RotorModules");
	if (bUseDefaultSettings)
	{
		machine.GenNewRotorsModules(1, 2, 3);
	}
	else
	{
		machine.GenNewRotorsModules(
			static_cast<Enigma::Enigma_Short>(std::stoi(argv[customSettingsLoc + 1])),
			static_cast<Enigma::Enigma_Short>(std::stoi(argv[customSettingsLoc + 2])),
			static_cast<Enigma::Enigma_Short>(std::stoi(argv[customSettingsLoc + 3]))
		);
	}
	machine.GenNewPairModule();

	std::string word = "hello";
	std::cout << machine.Encrypt(word) << std::endl;

	system("pause");

	return 0;
}