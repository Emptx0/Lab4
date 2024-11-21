#pragma once
#ifndef MUSHROOMS_H
#define MUSHROOMS_H

#include <iostream>
#include <memory>
#include <string>

class Mushroom {
private:
	std::string name;
public:
	Mushroom(std::string);
	virtual ~Mushroom() = default;
	std::string getName();
	virtual bool isEatable() = 0;
	virtual int getTreatment() = 0;
	friend std::ostream& operator << (std::ostream&, Mushroom&);
	virtual std::ostream& output(std::ostream&, Mushroom&) = 0;
};

class EatableMushroom : public Mushroom {
private:
	bool eatable;
public:
	EatableMushroom(std::string);

	virtual std::ostream& output(std::ostream&, Mushroom&);
	virtual bool isEatable();
	virtual int getTreatment();
};
class PoisonousMushroom : public Mushroom {
private:
	bool eatable;
	int treatment;
public:
	PoisonousMushroom(std::string, int);

	virtual std::ostream& output(std::ostream&, Mushroom&);
	virtual int getTreatment();
	virtual bool isEatable();
};

enum MushroomType { Eatable, Poisonous };

class MushroomContext {
private:
	MushroomType mushroomType;
	std::string name;
	int treatment;
public:
	MushroomContext(std::string, bool, int);
	MushroomType getMushroomType();
	std::string getName();
	int getTreatment();
};

class MushroomFactory {
public:
	static Mushroom* createMushroom(MushroomContext context);
};

#endif

