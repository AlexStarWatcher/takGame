#pragma once
#include <iostream>
#include <string>



enum logLevel {
	normal,
	warning,
	critical
};

void logger(std::string);
void logger(std::string log, int intger);
void logger(logLevel, std::string);
int IputLogInt(std::string);
