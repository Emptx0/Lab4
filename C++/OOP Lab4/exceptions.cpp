#include "exceptions.h"

const char* MyBaseException::what() const noexcept {
	return "MyBaseException occured";
}

const char* ChoiceError::what() const noexcept {
	return "Invalid choice";
}

const char* ListException::what() const noexcept {
	return "Mushroom list is empty";
}