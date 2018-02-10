#pragma once
#ifndef ILLEGALMOVEEXCEPTION_H
#define ILLEGALMOVEEXCEPTION_H
#include <exception>

struct IllegalMoveException : public std::exception {
	const char* what() const throw () {
		return "The move that was requested cannot be made!";
	}
};
#endif