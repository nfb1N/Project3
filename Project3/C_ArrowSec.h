#pragma once
#include "C_ArowsMeth.h"
class C_ArrowSec :
    public C_ArowsMeth
{
public:
	C_ArrowSec(int x, int y, int width, int lenth) : C_ArowsMeth(x, y, width, lenth) { this->setFillColor(sf::Color::Red); }

	virtual void rotation() override {
		int now = this->seconds * 6;
		while (this->is_work) {
			this->setRotation(180 + now);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			now += 6;
		}
	}
};

