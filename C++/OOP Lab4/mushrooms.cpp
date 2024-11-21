#include "mushrooms.h"

Mushroom::Mushroom(std::string name) : name(name) {};
std::string Mushroom::getName() {
	return name;
}
std::ostream& operator << (std::ostream& out, Mushroom& mushroom) {
	return mushroom.output(out, mushroom);
}

EatableMushroom::EatableMushroom(std::string name) : Mushroom(name), eatable(true) {};
std::ostream& EatableMushroom::output(std::ostream& out, Mushroom& mushroom) {
	return out << mushroom.getName() << ", " << mushroom.isEatable() << ", 0 minutes";
}
bool EatableMushroom::isEatable() {
	return eatable;
}
int EatableMushroom::getTreatment() {
	return 0;
}


PoisonousMushroom::PoisonousMushroom(std::string name, int treatment) : Mushroom(name), eatable(false), treatment(treatment) {};
std::ostream& PoisonousMushroom::output(std::ostream& out, Mushroom& mushroom) {
	return out << mushroom.getName() << ", " << mushroom.isEatable() << ", " << mushroom.getTreatment() << " minutes";
}
int PoisonousMushroom::getTreatment() {
	return treatment;
}
bool PoisonousMushroom::isEatable() {
	return eatable;
}

MushroomContext::MushroomContext(std::string nname, bool eatable, int ttreatment) : name(nname), treatment(ttreatment) {
	if (eatable) mushroomType = Eatable; else mushroomType = Poisonous;
}
MushroomType MushroomContext::getMushroomType() {
	return mushroomType;
}
std::string MushroomContext::getName() {
	return name;
}
int MushroomContext::getTreatment() {
	return treatment;
}

Mushroom* MushroomFactory::createMushroom(MushroomContext context) {
	switch (context.getMushroomType())
	{
	case Eatable:
		return new EatableMushroom(context.getName());
	case Poisonous:
		return new PoisonousMushroom(context.getName(), context.getTreatment());
	default:
		std::cerr << "Unknown mushroom type: " << context.getMushroomType() << "!" << std::endl;
		system("pause");
		exit(0);
	}
}
