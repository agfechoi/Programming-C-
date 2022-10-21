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
			cout << "������ �ִ� ��ŭ�� �縸 ���Ⱑ�� �մϴ�." << endl;
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
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "1 ~ 5 ����: ";
}
void MakeAccount()
{
	string name;
	int number;
	int money;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> number;
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;

	account[accountCount].setInfo(number, name, money);
	accountCount++;
}
void DepositMoney()
{
	int accountID;
	int money;
	cout << "[�� �� â]" << endl;
	cout << "����ID: "; cin >> accountID;
	cout << "�Ա��� �ݾ���? "; cin >> money;

	for (int i = 0; i < 100; i++)
	{
		if (account[i].getAccountNum() == accountID)
		{
			account[i].inputMoney(money);
			cout << "-----�ԱݿϷ�-----" << endl;
			cout << "���� �ܾ�: " << account[i].getAccountBalance() << endl;
		}
	}
}
void WithdrawMoney()
{
	int accountID;
	int money;
	cout << "[�� �� â]" << endl;
	cout << "����ID: "; cin >> accountID;
	cout << "����� �ݾ���? "; cin >> money;

	for (int i = 0; i < 100; i++)
	{
		if (account[i].getAccountNum() == accountID)
		{
			account[i].outputMoney(money);
			cout << "-----��ݿϷ�-----" << endl;
			cout << "���� �ܾ�: " << account[i].getAccountBalance() << endl;
		}
	}
}
void ShowList()
{
	for (int i = 0; i < accountCount; i++)
	{
		cout << i << "�� �� ����" << endl;
		cout << "����ID: " << account[i].getAccountNum() << endl;
		cout << "�� �̸�: " << account[i].getAccountOwnerName() << endl;
		cout << "���� �ܾ�: " << account[i].getAccountBalance() << endl;
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