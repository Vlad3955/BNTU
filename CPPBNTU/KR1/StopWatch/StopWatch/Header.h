#pragma once
class StopWatch
{
public:
	StopWatch();
	~StopWatch();
	void Start();
	void Stop();
	void Show();
private:
	clock_t start;
	clock_t create;
	double value;
	bool started;
};