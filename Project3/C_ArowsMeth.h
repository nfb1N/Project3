#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<SFML/Graphics.hpp>
#include<thread>
#include<chrono>
#include <ctime>
class C_ArowsMeth : public sf::RectangleShape
{
protected:
	bool is_work;
	int seconds;
	int minutes;
	int hours;
	std::thread* thread_arow;
public:
	C_ArowsMeth(int x, int y, int width, int lenth)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		this->seconds = ltm->tm_sec;
		this->minutes = ltm->tm_min;
		this->hours = ltm->tm_hour;

		this->thread_arow = new std::thread([&]() {rotation(); });
		this->thread_arow->detach();
		this->setPosition(x, y);
		this->setSize(sf::Vector2f(width, lenth));

		this->is_work = true;
	}

	virtual void rotation() = 0;

	virtual ~C_ArowsMeth()
	{
		this->is_work = false;
		delete this->thread_arow;
	}
};

