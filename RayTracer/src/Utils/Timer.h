#pragma once
#include <chrono>


class Timer
{
private:
	double& m_diff;
	double& m_FPS;

	std::chrono::steady_clock::time_point start;

public:
	Timer(double& diff, double& FPS);
	~Timer();

};