#include "logger.h"
#include <iostream>



void logger(std::string log) 
{
	std::cout << "[logged]" << log << std::endl;
};
void logger(logLevel logLevel, std::string log)
{
	std::cout << "[logged at " << logLevel << " lavel]" << log << std::endl;
}
int IputLogInt(std::string query)
{
	std::cout << query <<"\n NOTICE: please enter an intger"<<std::endl;
	int answer;
	std::cin >> answer;
	return answer;
}

