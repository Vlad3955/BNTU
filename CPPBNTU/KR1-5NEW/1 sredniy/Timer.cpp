#include "Timer.h"
#include <iostream>
#include <ctime>
//реализация
Timer::Timer() : start_time(0.), end_time(0.)
{
}
void Timer::start()
{
	start_time = (double)clock() / 1000.;
}
void Timer::stop()
{
	end_time = (double)clock() / 1000.;
}
void Timer::printElapsedTime()
{
	std::cout << end_time - start_time << "s" << std::endl;
}