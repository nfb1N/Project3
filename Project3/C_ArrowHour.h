#pragma once
#include "C_ArowsMeth.h"
class C_ArrowHour :
    public C_ArowsMeth
{
public:
	C_ArrowHour(int x, int y, int width, int lenth) : C_ArowsMeth(x, y, width, lenth) { this->setFillColor(sf::Color::Black); }
	
	virtual void rotation() override {

		int now = this->hours * 30;
		this->setRotation(180 + now);
		std::this_thread::sleep_for(std::chrono::minutes(60 - this->minutes));

		while (this->is_work) {
			now += 30;
			this->setRotation(180 + now);
			std::this_thread::sleep_for(std::chrono::hours(1));
		}
	}
};

