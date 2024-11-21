#pragma once
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class MyBaseException: public std::exception {
public:
	virtual const char* what() const noexcept override;
};

class ChoiceError: public MyBaseException {
public:
	virtual const char* what() const noexcept override;
};

class ListException: public MyBaseException {
public:
	virtual const char* what() const noexcept override;
};


#endif