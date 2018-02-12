#pragma once
#ifndef GAMESETUPEXCEPTION_H
#define GAMESETUPEXCEPTION_H
#include <exception>
#include <string>

struct GameSetupException : public std::exception {
	string message;
	GameSetupException(string message) { this->message = message; }

	const char* what() const throw () {
		return message.c_str();
	}
};
#endif