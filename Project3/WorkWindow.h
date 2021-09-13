#pragma once
#include"C_ArrowHour.h"
#include"C_ArrowMin.h"
#include"C_ArrowSec.h"
using namespace sf;
class WorkWindow
{
private:
	bool isWork;
	std::thread* workThread;
public:

	WorkWindow()
	{
		this->workThread = new std::thread([&]() {work(); });
		this->isWork = true;
	}

	void work() {
		while (isWork) {
			RenderWindow window(VideoMode(900, 500), "pong!");


			CircleShape circle(100);
			circle.setPosition(330, 150);
			circle.setFillColor(Color::Blue);

			C_ArrowSec sec(430, 250, 5, 100);
			C_ArrowMin min(430, 250, 5, 75);
			C_ArrowHour hour(430, 250, 5, 50);
			while (window.isOpen())
			{

				std::this_thread::sleep_for(std::chrono::seconds(1));
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
						window.close();
				}


				window.clear();

				window.draw(circle);
				window.draw(sec);
				window.draw(min);
				window.draw(hour);

				window.display();
			}
		}
	}

	~WorkWindow()
	{
		delete this->workThread;
		this->isWork = false;
	}
};

