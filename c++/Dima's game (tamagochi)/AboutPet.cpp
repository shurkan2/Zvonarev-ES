#include <iostream>
#include <string>
#include <fstream>
#include "MyForm.h"

	using namespace std;

	class MyAnimal
	{
	protected:


		int health, caress, boried, hunger, drain, weariness, necessity;
	public:
		MyAnimal(const MyAnimal &currentanimal)
		{

			this->boried = currentanimal.boried;
			this->caress = currentanimal.caress;
			this->health = currentanimal.health;
			this->hunger = currentanimal.hunger;
			this->drain = currentanimal.drain;
			this->weariness = currentanimal.weariness;
			this->necessity = currentanimal.necessity;
		};

		MyAnimal()
		{
			health = 100;
			boried = 100;
			weariness = 100;
			necessity = 100;
			hunger = 100;
			drain = 100;
			caress = 80;
		};
		friend bool SaveToFile(MyAnimal curranimal);

	};

	bool SaveToFile(MyAnimal curranimal)
	{
		ofstream file;
		string directory = "SavedFile.txt";
		file.open(directory);
		if (!file.is_open()) { return false; }
		else
		{
			file.write((char*)&(curranimal), sizeof(MyAnimal));
			return true;
		};
		file.close();
	}