#pragma once
#include "Account.h"
#include "AccountArray.h"

class AccountHandler	// ��Ʈ�� Ŭ����
{
private:
	BoundCheckAccountPtrArray accArr;	// ����� ����
	int accNum;				// ����� account�� ��
public:
	AccountHandler();
	void Menu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAccount(void) const;
	~AccountHandler();
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};