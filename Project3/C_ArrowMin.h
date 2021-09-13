#pragma once
#include "C_ArowsMeth.h"
class C_ArrowMin :
    public C_ArowsMeth
{
public:
	C_ArrowMin(int x, int y, int width, int lenth): C_ArowsMeth(x, y, width, lenth){ this->setFillColor(sf::Color::Green); }

	virtual void rotation() override {
		int now = this->minutes * 6;
		this->setRotation(180 + now);
		std::this_thread::sleep_for(std::chrono::seconds(60 - this->seconds));

		while (this->is_work) {
			now += 6;
			this->setRotation(180 + now);
			std::this_thread::sleep_for(std::chrono::minutes(1));
		}
	}
};

