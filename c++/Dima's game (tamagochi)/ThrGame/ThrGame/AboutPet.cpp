//#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <msclr\marshal_cppstd.h>
	using namespace std;

	class MyAnimal
	{
	public:string superstati[7];

		int /*health,*/ caress, slumber, boried, hunger, drain, /*weariness,*/curiosity, necessity,money;
		
	public: int stati[8]; string mood;
	public:
		MyAnimal(const MyAnimal &currentanimal)
		{

			this->boried = currentanimal.boried;
			this->caress = currentanimal.caress;
			this->hunger = currentanimal.hunger;
			this->drain = currentanimal.drain;
			this->necessity = currentanimal.necessity;
			this->curiosity = currentanimal.curiosity;
			this->mood = currentanimal.mood;
			this->slumber = currentanimal.slumber;
			this->money = currentanimal.money;
			for (int i = 0; i < 8; i++)
			{
				this->stati[i] = currentanimal.stati[i];
			}
		};
		MyAnimal()
		{
			boried = 120;
			necessity = 120;
			hunger = 120;
			drain = 120;
			caress = 120;
			curiosity = 120;
			slumber = 120;
			money = 15;

			stati[0] = -1;
			stati[1] = boried;
			stati[2] = hunger;
			stati[3] = drain;
			stati[4] = caress;
			stati[5] = necessity;
			stati[6] = slumber;
			stati[7] = curiosity;
			mood = "";
			string s= ChekMood();
			mood = s;
		};
		void reset_stati() 
		{
			boried = 120;
			necessity = 120;
			hunger = 120;
			drain = 120;
			caress = 120;
			curiosity = 120;
			slumber = 120;
			money = 21;

			stati[0] = -1;
			stati[1] = boried;
			stati[2] = hunger;
			stati[3] = drain;
			stati[4] = caress;
			stati[5] = necessity;
			stati[6] = slumber;
			stati[7] = curiosity;
			mood = "";
			string s = ChekMood();
			mood = s;
		}
		MyAnimal operator =(const MyAnimal &other)
		{

			MyAnimal temp;
			temp.boried = other.boried;
			temp.caress = other.caress;
			temp.hunger = other.hunger;
			temp.drain = other.drain;
			temp.necessity = other.necessity;
			temp.curiosity = other.curiosity;
			temp.slumber = other.slumber;
			temp.money = other.money;
			temp.mood = other.mood;
			for (int i = 0; i < 8; i++)
			{
				temp.stati[i] = other.stati[i];
			}
			return temp;

		} // = 
		MyAnimal & operator --()
		{
			this->stati[1]--;
			this->stati[2]--;
			this->stati[3]--;
			this->stati[4]--;
			// this->stati[5]--;
			this->stati[6]--;
		//	this->stati[7]--;

			
			boried = this->stati[1];
			hunger = this->stati[2];
			drain = this->stati[3];
			caress = this->stati[4];
			necessity = this->stati[5];
			slumber = this->stati[6];
			curiosity = this->stati[7];

			mood = "";
			string s = ChekMood();
			mood = s;

			if (this->mood == "MistakeInDetermination") 
			{
				this->boried++;
				this->caress++;
				this->hunger++;
				this->drain++;
				//this->necessity;
				//this->curiosity;
				this->slumber++;
				this->stati[0] = -1;
				this->stati[1] = boried;
				this->stati[2] = hunger;
				this->stati[3] = drain;
				this->stati[4] = caress;
				this->stati[5] = necessity;
				this->stati[6] = slumber;
				this->stati[7] = curiosity;
			}
			return *this;
		}
		friend bool SaveToFile(MyAnimal &curranimal);
		friend bool LoadFromFile(MyAnimal &other);
		string ChekMood()
		{
			int pos = 0;
			int min = 361;
			for (int i=1;i<7;i++) 
			{
				if (min > this -> stati[i]) { min = this -> stati[i]; }
				if (this->stati[i] <= 0) { this->superstati[i] = "dead"; return "dead"; }
				else if ((this -> stati[i] > 0) && (this -> stati[i] <= 24)) { this -> superstati[i] = "critical"; }
				else if ((this -> stati[i] > 24) && (this -> stati[i] <= 60)) { this -> superstati[i] = "bad"; }
				else if ((this -> stati[i] > 60) && (this -> stati[i] < 102)) { this -> superstati[i] = "normal"; }
				else if ((this -> stati[i] >= 102) && (this -> stati[i] <= 120)) { this -> superstati[i] = "happy"; }
			}
			string s = "";
			int n_bad = 0, n_normal = 0, n_happy=0, n_crit = 0;
			for (int i = 1; i < 7; i++)
			{
				if (this->superstati[i] == "normal") n_normal++;
				else if (this->superstati[i] == "happy") n_happy++;
				else if (this->superstati[i] == "bad") n_bad++;
				else if (this->superstati[i] == "critical") n_crit++;
			}
			{
				if (n_crit != 0) 
				{
					if (n_crit == 1)
					{
						for (int i = 1; i < 7; i++)
						{
							if (this->superstati[i] == "critical")
							{
								if (i == 1) s = "crit_boried";
								else if (i == 2) s = "crit_hunger";
								else if (i == 3) s = "crit_drain";
								else if (i == 4) s = "crit_carees";
								else if (i == 5) s = "crit_ness";
								else if (i == 6) s = "crit_slumb";
								return s;
							}
						}
					}
					else if (n_crit > 1) { s = "critical"; return s; }
				}
				else if (n_bad != 0) 
				{
					s = "bad";
					return s;
				}
				else if (n_normal != 0)
				{
					s = "normal";
					return s;
				}
				else if (n_happy != 0) 
				{
					s = "happy";
					return s;
				}
				else 
				{
					s = "MistakeInDetermination";
					return s;
				}
				
			}
			return "MistakeInDetermination";
			/*if (min >= 102) s= "happy";
			else if (min > 60) s= "normal";
			else if (min > 24) s= "bad";
			else if ((min <= 24) && (min > 0)) s= "critical";
			else if (min <= 0) s= "dead";
			else s= "MistakeInDetermination";*/
		}
	};

	
	void ExtraChange(MyAnimal &other)
	{

		other.boried = other.stati[1];
		other.hunger= other.stati[2];
		other.drain= other.stati[3];
		other.caress= other.stati[4];
		other.necessity= other.stati[5];
		other.slumber= other.stati[6];
		other.curiosity= other.stati[7];

		other.mood = other.ChekMood();
	};
	bool SaveToFile(MyAnimal &curranimal, const std::string &name)
	{
		ofstream file;
		string directory =/*"SavedFiles\\" +*/name+".txt";
		file.open(directory);
		bool open1 = false;
		if (!file.is_open()) { file.close(); open1 = false; }
		else
		{
			file.write((char*)&curranimal, sizeof(MyAnimal));
			file.close();
			open1 =  true;
		};
		file.open("SavedFile.txt");
			if (file.is_open())
			{
				file.write((char*)&curranimal, sizeof(MyAnimal));		
			}
		file.close();
		return open1;
	}

	bool LoadFromFile(MyAnimal &other)
	{
		ifstream file;
		string directory = "SavedFile.txt";
		file.open(directory);
		if (!file.is_open()) { file.close(); return false; }
		
		else
		{
			while (file.read((char*)&other, sizeof(other))) {}
			file.close();
			return true;			
		}
			
	}

	bool LoadFromFile(MyAnimal &other, const std::string &name)
	{
		ifstream file;
		string directory = name + ".txt";
		file.open(directory);
		if (!file.is_open()) { file.close(); return false; }

		else
		{
			while (file.read((char*)&other, sizeof(other))) {}
			file.close();
			return true;
		}

	}

	string CheckKill(const MyAnimal &pet)
	{
		string s = "���������� ��� ������� ����(. ";
		int n = 0;
		for (int i = 1; i < 7; i++)
		{
			if (pet.stati[i] == 0) n++;
		}
		if (n == 1) 
		{
			int i = 1;
			for (;;i++)
			{
				if (pet.stati[i] == 0) break;
			}
			
			//if (i == 1) s = "��� �� ����������, �� ��� ������� ���� �� �����";
			if (i == 1) s = "�� ����� ��� �������� � ����� ������ ����� � ������ ����...";
			else if (i == 2) s = "������� �� ����� ��� ���������� � ��� ����, � �������� ��� ���� ������ ���. ��� �����, ����� �� �� ���-�� ������...";
			else if (i == 3) s = "����� ���������� ���������� �����. ������� - ��� ���. ��� ������� �� ����� �� ��������� :( ";
			else if (i == 4) s = "������� ������ ������. ���� ������� - ��� ��� ��� ����� ����? � ������ ������� ����� �� ����, � �� �� �������� � ����� �����(";
			else if (i == 5) s = "������ ������� ���� ���� ����� � ������, �� �� ��� �� �������. � ���� �������� ��������� ������� ������, ��� �� ���� �� �����(";
			else if (i == 6) s = "�� �� �������� � ��-���� ������. ��� ����, ��� ��������... :(";
		}
		else if (n < 6) 
		{
			s += "����� ��: ";
			for (int i = 1; i < 7; i++)
			{
				if (pet.stati[i] == 0)
				{
					n--;
				//	if (i == 1) s += "�����";
					if (i == 1) {
						s = "��-������, ������� ���� ������� ����� �� ���. ��-������, ������� ����(. "; if (n > 2) s += "����� ��: "; else if (n == 2) s += "��";	}
					if (i == 2) s += "������";
					else if (i == 3) s += "�������������";
					else if (i == 4) s += "����������_�����";
					else if (i == 5) s += "�����?";
					else if (i == 6) s += "��������";

					if ((n > 0) && (i!=1)) s += ", ";
					else if (n == 0) 
					{
						s += "."; 	
						break;
					}

				};
				
			}
		}
		else if (n >= 6) s= "���� �� ����� �����. �� ��� ��� ���� �������, �� �� ��������� ��������... ��� ���, ��� ����� ��� ����� �� �����... ���������� �������� �����";
		return s;
	}

	namespace Space_HSVtoRGB 
	{
		void HSVintoRGB(int H, const int S, const int V, int &R, int&G, int &B, const int DrawIndex)
		{
			if (DrawIndex != 0) { H = 360 - H; }
			int Hi = (int)(H / 60);
				Hi = (int)fmod(Hi,6) ;
				double Vmin = ((100 - S)*V) / (100);
				double a = (V - Vmin)*(fmod(H,60))/60;
				double Vinc = Vmin + a;
				double Vdec = V - a;

				if (Hi == 0) { R = (int)(255 * V / 100); G = (int)(255 * Vinc / 100); B = (int)(255 * Vmin / 100); }
				else if (Hi == 1) { R = (int)(255 * Vdec / 100); G = (int)(255 * V / 100); B = (int)(255 * Vmin / 100); }
				else if (Hi == 2) { R = (int)(255 * Vmin / 100); G = (int)(255 * V / 100); B = (int)(255 * Vinc / 100); }
				else if (Hi == 3) { R = (int)(255 * Vmin / 100); G = (int)(255 * Vdec / 100); B = (int)(255 * V / 100); }
				else if (Hi == 4) { R = (int)(255 * Vinc / 100); G = (int)(255 * Vmin / 100); B = (int)(255 * V / 100); }
				else if (Hi == 5) { R = (int)(255 * V / 100); G = (int)(255 * Vmin / 100); B = (int)(255 * Vdec / 100); }
		}
	}