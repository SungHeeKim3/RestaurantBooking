#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "pch.h"
#include "../../Project31/BookingScheduler.cpp"
using namespace std;
class BookingItem : public testing::Test
{
public:
	tm getTime(int year, int mon, int day, int hour, int min)
	{
		tm result = { 0,min,hour,day,mon - 1,year - 1900,0,0,-1 };
		mktime(&result);
		return result;
	}
};


TEST_F(BookingItem, ������_���ÿ���_�����ϴ�_���ð�_�ƴѰ��_����Ұ�) {

	tm notOnTheHour = getTime(2021,3,26,9,5);
	Customer customer{ "Fake name", "010-1234-5678" };
	Schedule* schedule = new Schedule{ notOnTheHour,1,customer };
	BookingScheduler bookingScheduler{ 3 };

	// act
	EXPECT_THROW({ bookingScheduler.addSchedule(schedule); }, runtime_error);
}

TEST_F(BookingItem, ������_���ÿ���_�����ϴ�_������_���_���డ��) {
	tm onTheHour = getTime(2021, 3, 26, 9, 0);
	Customer customer{ "Fake name", "010-1234-5678" };
	Schedule* schedule = new Schedule{ onTheHour,1,customer };
	BookingScheduler bookingScheduler{ 3 };

	bookingScheduler.addSchedule(schedule);
	// act
	EXPECT_EQ(true, bookingScheduler.hasSchedule(schedule));
}

TEST(BookingSchedulerTest, �ð��뺰_�ο�������_�ִ�_����_�ð��뿡_Capacity_�ʰ���_���_���ܹ߻�) {

}

TEST(BookingSchedulerTest, �ð��뺰_�ο�������_�ִ�_����_�ð��밡_�ٸ���_Capacity_���־_������_�߰�_����) {

}

TEST(BookingSchedulerTest, ����Ϸ��_SMS��_������_�߼�) {

}

TEST(BookingSchedulerTest, �̸�����_����_��쿡��_�̸���_�̹߼�) {

}

TEST(BookingSchedulerTest, �̸�����_�ִ�_��쿡��_�̸���_�߼�) {

}

TEST(BookingSchedulerTest, ���糯¥��_�Ͽ�����_���_����Ұ�_����ó��) {

}

TEST(BookingSchedulerTest, ���糯¥��_�Ͽ�����_�ƴѰ��_���డ��) {

}