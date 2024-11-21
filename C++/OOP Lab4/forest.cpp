#include "forest.h"
#include <fstream>

Forest::~Forest() {
	for (auto mushroom : mushrooms) {
		delete mushroom;
	}
}

std::vector<Mushroom*> Forest::getMushrooms() {
	return mushrooms;
}
void Forest::addMushroom(Mushroom*& mushroom) {
	this->mushrooms.push_back(mushroom);
}
void Forest::clearMushrooms()
{
	this->mushrooms.clear();
}

ForestRepository::ForestRepository(std::string fname) : filename(fname) {};
void ForestRepository::addMushroomToForest(std::string name, bool eatable, int treatment, Forest& forest) {
	std::fstream file(filename, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Can't open file: " << filename << std::endl;
		system("pause");
		exit(0);
	}
	file << name << " " << eatable << " " << treatment << "\n";
	file.close();
	loadMushroomsList(forest);
}
void ForestRepository::loadMushroomsList(Forest& forest) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Can't open file: " << filename << std::endl;
		system("pause");
		exit(0);
	}
	std::string name;
	bool eatable;
	int treatment;

	while (file >> name >> eatable >> treatment) {
		MushroomContext context(name, eatable, treatment);
		Mushroom* mushroom = MushroomFactory::createMushroom(context);
		forest.addMushroom(mushroom);
	}

	file.close();
}