#include "../../Project31/BookingScheduler.cpp"

class ModaydayBookingScheduler : public BookingScheduler
{
public:
	ModaydayBookingScheduler(int capacityPerHour) :
		BookingScheduler{ capacityPerHour }
	{}

	time_t getNow() override
	{
		return getTime(2024, 6, 3, 17, 0);
	}
private:
	time_t getTime(int year, int mon, int day, int hour, int min)
	{
		tm result = { 0,min, year, day, mon - 1, year - 1900,0,0,-1 };
		return mktime(&result);
	}
};