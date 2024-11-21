#include "basket.h"
#include "exceptions.h"

Basket::~Basket() {
	for (auto item : items) {
		delete item;
	}
}

void Basket::addItem(Mushroom* item) {
	items.push_back(item);
}
void Basket::calculateResult() {
	if (items.empty()) {
		throw ListException();
	}

	int eatableCount = 0;
	int treatmentTime = 0;
	for (auto item : items) {
		if (item->isEatable()) {
			eatableCount++;
		}
		else {
			treatmentTime += item->getTreatment();
		}
	}
	std::cout << "Eatable percent: " << (int)(((float)eatableCount / (float)items.size()) * 100) << "%" << std::endl;
	std::cout << "Treatment time: " << treatmentTime << " minutes" << std::endl;
	system("pause");
	items.clear();
}