#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	int accountNum;
	string customerName;
	int balance;
public:
	int getAccountNum() { return this->accountNum; }
	int getAccountBalance() { return this->balance; }
	string getAccountOwnerName() { return this->customerName; }
	void setInfo(int number, string name, int money) { this->accountNum = number; this->customerName = customerName; this->balance = money; }
	void inputMoney(int money) { this->balance += money; }
	void outputMoney(int money)
	{
		if (this->balance - money < 0)
		{
			cout << "가지고 있는 만큼의 양만 인출가능 합니다." << endl;
			return;
		}
		else this->balance -= money;
	}
};

Account account[100];
int accountCount = 0;

void Menu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowList();

void Menu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "1 ~ 5 선택: ";
}
void MakeAccount()
{
	string name;
	int number;
	int money;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> number;
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> money;

	account[accountCount].setInfo(number, name, money);
	accountCount++;
}
void DepositMoney()
{
	int accountID;
	int money;
	cout << "[입 금 창]" << endl;
	cout << "계좌ID: "; cin >> accountID;
	cout << "입금할 금액은? "; cin >> money;

	for (int i = 0; i < 100; i++)
	{
		if (account[i].getAccountNum() == accountID)
		{
			account[i].inputMoney(money);
			cout << "-----입금완료-----" << endl;
			cout << "현재 잔액: " << account[i].getAccountBalance() << endl;
		}
	}
}
void WithdrawMoney()
{
	int accountID;
	int money;
	cout << "[출 금 창]" << endl;
	cout << "계좌ID: "; cin >> accountID;
	cout << "출금할 금액은? "; cin >> money;

	for (int i = 0; i < 100; i++)
	{
		if (account[i].getAccountNum() == accountID)
		{
			account[i].outputMoney(money);
			cout << "-----출금완료-----" << endl;
			cout << "현재 잔액: " << account[i].getAccountBalance() << endl;
		}
	}
}
void ShowList()
{
	for (int i = 0; i < accountCount; i++)
	{
		cout << i << "번 고객 정보" << endl;
		cout << "계좌ID: " << account[i].getAccountNum() << endl;
		cout << "고객 이름: " << account[i].getAccountOwnerName() << endl;
		cout << "현재 잔액: " << account[i].getAccountBalance() << endl;
	}
}
enum {Make = 1, Deposit, Withdraw, List, Quit};

int main()
{
	int chosenNumber;
	
	while (1)
	{
		Menu();
		cin >> chosenNumber;

		switch (chosenNumber)
		{
		case Make:
			MakeAccount();
			break;
		case Deposit:
			DepositMoney();
			break;
		case Withdraw:
			WithdrawMoney();
			break;
		case List:
			ShowList();
			break;
		case Quit:
			return 0;
		}
	}	
	return 0;
}