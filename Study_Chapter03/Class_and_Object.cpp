#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 객체의 생성과정
/*
1 - 메모리 공간의 할당
2 - 이니셜라이저를 이용한 멤버변수(객체)의 초기화
3 - 생성자의 몸체부분 실행
*/
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
		ACC_STEP = 10, BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char* ID, int fuel);	// char *ID == char ID[0] 같은말
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel)  // strcpy(A, B)  
{												 // : A에다가 복사해야할 문자열 B는 변경돼선 안되기 때문에,
	strcpy(gamerID, ID);						 //  인수로부터 값을 받을 인자 ID 를 선언할 때 const 가 필요!
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::ACC_STEP;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarState();
	run99.Break();
	run99.ShowCarState();
	return 0;

}

