#include <iostream>
using namespace std;

class ATM
{
private:
	string name; //������ �̸�
	int pw; //���� ��й�ȣ
	int money;  //���� �ܾ�
	int checkPW;

public:
	ATM();  //������
	void deposit();  //�Ա�
	void withdraw();  //����
	void send(string receiver, int sendMon);  //��ü - ����
	void receive(int receiveMon);  //��ü - ����
	int getMoney(); //���ִ��� ���
	string getName(); //�̸� �ҷ�����
	void bankname();  //������ �̸� �Է� �Լ�
	void PW(); //���� ��й�ȣ ����
	void bankbalance(); //�ܾ� 
	void pwcheck();  // ��й�ȣ ��Ȯ��
	void pwcheck2();
};


ATM::ATM()
{};

void ATM::deposit() //�Ա�
{
	int plus;  //�ԱݵǴ� �ݾ�
	cin >> plus;
	money += plus;
}

void ATM::withdraw() //����
{
	int minus; // ����Ǵ� �ݾ�
	cin >> minus;
	money -= minus;
}

void ATM::send(string reciever, int sendMon)
{
	money -= sendMon;
}

void ATM::receive(int receiveMon)
{
	money += receiveMon;
}

int ATM::getMoney()
{
	return money;
}

string ATM::getName()
{
	return name;
}

void ATM::bankname()
{
	cin >> name;
}

void ATM::PW()
{
	cin >> pw;
}

void ATM::bankbalance()
{
	cin >> money;
}

void ATM::pwcheck()
{
	cin >> checkPW;

	if (checkPW != pw)
	{
		while (checkPW != pw) 
		{
			cout << "��й�ȣ�� ���� �ٸ��ϴ�." << endl << endl;
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> checkPW;
		}
	}
}

void ATM::pwcheck2()
{
	cin >> checkPW;

	if (checkPW != pw)
	{
		while (checkPW != pw) 
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			cout << "��й�ȣ�� �Է����ּ��� >> ";
			cin >> checkPW;
		}
	}
}

int main()
{
	int number; // ���࿡ ������ �ο� �� �Է¹ޱ�
	int i, k, l = 999, m = 999;
	string Name = "none";
	string receiver = "none";
	int choosenum;
	int sendMoney;

	cout << "���࿡ ������ �ο� ���� �Է����ּ��� >> ";
	cin >> number;
	ATM* account = new ATM[number];

	for (i = 0; i < number; i++)
	{
		cout << endl << i + 1 << "��° �մ�" << endl << endl;
		cout << "������ �����ּ��� >> ";
		(account + i)->bankname();
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		(account + i)->PW();
		cout << "��й�ȣ�� �ѹ� �� �Է����ּ��� >> ";
		(account + i)->pwcheck();
		cout << "�Ա��� �ݾ��� �����ּ��� >> ";
		(account + i)->bankbalance();
		cout << endl;
	}

	for(;;)
	{
		for (;;)
		{
			cout << endl << "-------SWING ATM-------" << endl;
			cout << "������ �Է����ּ���. (������ x�� �Է����ּ���.) >> ";
			cin >> Name;

			if (Name == "x")
				break;
			l = 999;
			for (k = 0; k < number; k++)
			{
				if (Name == (account + k)->getName())
					l = k;  // name�� �������̸� �� -> ������ l�� ����
			}
			//�Ӱ� �״�θ� ������ ���� x ���

			if (l == 999 && Name != "x")
				cout << "�������� �ʴ� �������Դϴ�." << endl;
			else
				break;
		}
		if (Name == "x")
			break;
		
		choosenum = 0;

		while (choosenum != 5)
		{
			cout << endl << "-------SWING ATM " << (account + l)->getName() << "��-------" << endl;
			cout << "1. �Ա�" << endl;
			cout << "2. ����" << endl;
			cout << "3. ��ü" << endl;
			cout << "4. �ܾ� Ȯ��" << endl;
			cout << "5. ����" << endl << endl;
			cout << "��ȣ�� �������ּ��� >> ";
			cin >> choosenum;

			switch (choosenum)
			{
			case 1:
				{
					cout << "�Ա��� �ݾ��� �Է����ּ��� >> ";
					(account + l)->deposit();
					cout << endl << "���� " << (account + l)->getName() << "���� �ܾ��� " << (account +l)->getMoney() << "�� �Դϴ�." << endl;
					break;
				}
			case 2:
				{
					cout << "�󸶸� �����Ͻðڽ��ϱ�? >> ";
					(account + l)->withdraw();
					cout << "��й�ȣ�� �Է����ּ��� >> ";
					(account + l)->pwcheck2();
					cout << endl << "���� " << (account + l)->getName() << "���� �ܾ��� " << (account + l)->getMoney() << "�� �Դϴ�." << endl;
					break;
				}
			case 3:
				{
					cout << "�������� �����ڽ��ϱ�? >> ";
					cin >> receiver;

					m = 999;

					for (k = 0; k < number; k++)
					{
						if (receiver == (account + k)->getName())
							m = k;
					}
					if (m == 999) 
						break;

					cout << "�󸶸� �����ڽ��ϱ�? >> ";
					cin >> sendMoney;
					(account + l)->send((account + m)->getName(), sendMoney);
					cout << "��й�ȣ�� �Է����ּ��� >> ";
					(account + l)->pwcheck2();
					cout << endl << (account + m)->getName() << "�Բ� " << sendMoney << "���� ���½��ϴ�." << endl;
					(account + m)->receive(sendMoney);
					cout << endl << "���� " << (account + l)->getName() << "���� �ܾ��� " << (account + l)->getMoney() << "�� �Դϴ�." << endl;
					break;
				}
			case 4:
				cout << (account + l)->getName() << "���� ���� �ܾ��� " << (account + l)->getMoney() << "�� �Դϴ�." << endl; break;
			case 5:
				break;

			}
		}
	}
	cout << "ATM�� �����մϴ�." << endl;

	return 0;
}