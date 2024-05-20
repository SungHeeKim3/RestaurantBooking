#include <iostream>
#include "pch.h"
#include "../../Project31/mailSender.cpp"

class TestableMailSender : public MailSender
{
public:
	void sendMail(Schedule* schedule) override
	{
		countSendMailMethodIsCalled++;
	}
	int getCountSendMailMethodIsCalled()
	{
		return countSendMailMethodIsCalled;
	}
private:
	int countSendMailMethodIsCalled = 0;
};