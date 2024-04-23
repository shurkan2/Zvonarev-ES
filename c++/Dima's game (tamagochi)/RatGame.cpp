#include <SFML/Graphics.hpp>
#include <Clocale>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <fstream>

std::string fu1nc();

using namespace sf; // подключаем пространство имён sf

const int H = 400;
const int W = 900;
int frame = 1;
int nmish = 0;
double speed = 0;
double timer = 0;
double gtime = 0;
double delay0 = 50;
bool GameOver = false;
std::string DIRECTION = fu1nc();


std::string fu1nc()
{
	setlocale(LC_ALL, "rus");
	char Name[MAX_PATH];
	GetModuleFileNameA(NULL, Name, MAX_PATH);
	std::string s = Name;
	int deb = s.rfind("Debug"); int rel = s.rfind("Release");
	if (deb != -1)
	{
		s.erase(s.rfind("Debug"), s.length() - s.rfind("Debug"));
	}
	else if (rel != -1) { s.erase(s.rfind("Release"), s.length() - s.rfind("Release")); }
	else
	{
		s.erase(s.rfind("\\"), s.length() - s.rfind("\\"));
		s += "\\";
	}
	return s;
}

class mouse
{
public:
	FloatRect rect; int ndorozh, currframe;
	Sprite spr;
	double timer, delay, velosity;
	bool isshown;
	int lifetime;
	mouse()
	{
		rect.height = 12;
		rect.width = 50;
		rect.left = 20;
		rect.top = 0;
		currframe = 0;
		ndorozh = 0;
		isshown = false;
		int randnumber;
		if (4000 - nmish * 37 <= 0) { randnumber = 700; }
		else randnumber = rand() % (4000 - nmish * 37);
		delay = (randnumber + 1);
		lifetime = 0;
		velosity = delay0;
		timer = 0;
	}
	mouse(const int npos, const Texture *texture)
	{
		ndorozh = npos;
		rect.height = 12;
		rect.width = 50;
		rect.left = 24;
		rect.top = ((npos - 1) * 100) + 45;
		currframe = 0;
		isshown = false;
		int randnumber;
		if (4000 - nmish * 37 <= 0) { randnumber = 700; }
		else randnumber = rand() % (4000 - nmish * 37);
		delay = (randnumber + 1);
		lifetime = 0;
		velosity = delay0;
		timer = 0;
	}
	~mouse()
	{

	}
	bool IsKilled(const int X, const int Y)
	{
		bool IsY = false, IsX = false;
		if ((Y > this->rect.top) && (Y < (this->rect.top + this->rect.height))) IsY = true;
		else IsY = false;
		if ((X > this->rect.left) && (X < (this->rect.left + this->rect.width))) IsX = true;
		else IsX = false;

		if (IsX && IsY) return true;
		else return false;
	}
	void Kill()
	{
		this->currframe = 0;
		this->isshown = false;
		speed += 1;
		nmish++;
		this->velosity = delay0 - (log(speed) / log(1.093755548000));
		int randnumber;
		if (4000 - nmish * 37 <= 0) { randnumber = 700; }
		else randnumber = rand() % (4000 - nmish * 37);
		delay = (randnumber + 1);
		rect.left = 24;
		rect.top = ((this->ndorozh - 1) * 100) + 45;
		lifetime = 0;
		timer = 0;
	}
};

void Hide()
{
	HWND Hide;
	AllocConsole();
	Hide = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Hide, 0);
}

int RatGame()
{
	Hide();
	srand(time(0));
	// Устанавливаем 8-ой уровень сглаживания
	ContextSettings settings;
	settings.antialiasingLevel = 8;


	RenderWindow window(VideoMode(900, 500), "Catch me, if you can!!", Style::Default, settings);
	mouse pet[6];
	Texture t;
	t.loadFromFile(DIRECTION + "Images\\ForGameRats\\Rats.jpg");
	Texture Backgroundfontexture;
	Backgroundfontexture.loadFromFile(DIRECTION + "Images\\ForGameRats\\Фон.png");
	Sprite Backgroundfonsprite1;
	Backgroundfonsprite1.setTexture(Backgroundfontexture);
	Backgroundfonsprite1.setPosition(0, 0);
	for (int i = 0; i < 6; i++)
	{
		pet[i].ndorozh = i;
		pet[i].spr.setTexture(t);
		pet[i].rect.top = ((i - 1) * 100) + 45;
	}


	Clock clock;
	while (window.isOpen())
	{
		double time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		gtime += time;
		timer += time;
		// Обрабатываем очередь событий в цикле
		Event event;

		while (window.pollEvent(event))
		{
			Vector2i pos = Mouse::getPosition(window);
			int x = pos.x;
			int y = pos.y;
			if (event.type == Event::Closed)
				window.close();
			if ((event.type == Event::MouseButtonPressed) && (!GameOver))
			{

				for (int i = 0; i < 6; i++)
				{
					if (pet[i].IsKilled(x, y))
					{
						pet[i].Kill();
						break;
					}
				}
			}
			else if ((event.type == Event::MouseButtonPressed) && (GameOver))
			{
				using namespace std;
				std::ofstream file;
				file.open("Result.txt");
				if (file.is_open())
				{
					file << "Количество очков: " + to_string(nmish);
				}
				file.close();
				window.close();
			}

		}
		if (!GameOver) {
			for (int i = 0; i < 6; i++)
			{
				pet[i].lifetime += time;
				pet[i].timer += time;
			}

			for (int i = 1; i < 6; i++)
			{
				if (pet[i].timer > 1 * pet[i].velosity)
				{
					if (pet[i].delay <= pet[i].lifetime) pet[i].isshown = true;
					else continue;
					pet[i].rect.left += 2;
					pet[i].currframe++;
					if (pet[i].currframe == 5) pet[i].currframe = 0;
					pet[i].spr.setTextureRect(IntRect(pet[i].currframe * 50, 0, 50, 12));
					if (pet[i].currframe == 0) pet[i].rect.left += 12;
					pet[i].spr.setPosition(pet[i].rect.left, pet[i].rect.top);
					pet[i].timer = 0;
				}
			};
		}
		for (int i = 1; i < 6; i++)
		{
			if (pet[i].rect.left > 780) { GameOver = true;; }
		}

		window.draw(Backgroundfonsprite1);
		if (!GameOver)
		{
			for (int i = 1; i < 6; i++)
			{
				if (pet[i].isshown) window.draw(pet[i].spr);
				else continue;
			}
		}




		if (GameOver)
		{
			window.clear(Color(255, 0, 0, 0));
			Font font;//шрифт 
			font.loadFromFile(DIRECTION + "Images\\ForGameRats\\Шрифты\\CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
			std::string s; s = "Убито мышей (+$): " + std::to_string(nmish);
			Text text(s, font, 20);

			//text.setString(std::string(s));
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);
			Texture GOver;
			GOver.loadFromFile(DIRECTION + "Images\\ForGameRats\\GameOver.png");
			Sprite GOverSprite;
			GOverSprite.setTexture(GOver);
			GOverSprite.setPosition(0, 0);
			window.draw(GOverSprite);
			text.setPosition(340, 430);
			text.setFillColor(Color::Blue);
			window.draw(text);
		};
		window.display();
	}

	return nmish;
}