#include <iostream>
using namespace std;

class ATM
{
private:
	string name; //계좌주 이름
	int pw; //계좌 비밀번호
	int money;  //계좌 잔액
	int checkPW;

public:
	ATM();  //생성자
	void deposit();  //입금
	void withdraw();  //인출
	void send(string receiver, int sendMon);  //이체 - 받음
	void receive(int receiveMon);  //이체 - 보냄
	int getMoney(); //얼마있는지 출력
	string getName(); //이름 불러오기
	void bankname();  //계좌주 이름 입력 함수
	void PW(); //계좌 비밀번호 설정
	void bankbalance(); //잔액 
	void pwcheck();  // 비밀번호 재확인
	void pwcheck2();
};


ATM::ATM()
{};

void ATM::deposit() //입금
{
	int plus;  //입금되는 금액
	cin >> plus;
	money += plus;
}

void ATM::withdraw() //인출
{
	int minus; // 인출되는 금액
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
			cout << "비밀번호가 서로 다릅니다." << endl << endl;
			cout << "비밀번호를 입력해주세요 >> ";
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
			cout << "비밀번호가 틀렸습니다." << endl;
			cout << "비밀번호를 입력해주세요 >> ";
			cin >> checkPW;
		}
	}
}

int main()
{
	int number; // 은행에 가입할 인원 수 입력받기
	int i, k, l = 999, m = 999;
	string Name = "none";
	string receiver = "none";
	int choosenum;
	int sendMoney;

	cout << "은행에 가입할 인원 수를 입력해주세요 >> ";
	cin >> number;
	ATM* account = new ATM[number];

	for (i = 0; i < number; i++)
	{
		cout << endl << i + 1 << "번째 손님" << endl << endl;
		cout << "성명을 적어주세요 >> ";
		(account + i)->bankname();
		cout << "비밀번호를 입력해주세요 >> ";
		(account + i)->PW();
		cout << "비밀번호를 한번 더 입력해주세요 >> ";
		(account + i)->pwcheck();
		cout << "입금할 금액을 적어주세요 >> ";
		(account + i)->bankbalance();
		cout << endl;
	}

	for(;;)
	{
		for (;;)
		{
			cout << endl << "-------SWING ATM-------" << endl;
			cout << "성함을 입력해주세요. (종료라면 x를 입력해주세요.) >> ";
			cin >> Name;

			if (Name == "x")
				break;
			l = 999;
			for (k = 0; k < number; k++)
			{
				if (Name == (account + k)->getName())
					l = k;  // name과 계좌주이름 비교 -> 같으면 l에 대입
			}
			//ㅣ값 그대로면 계좌주 존재 x 출력

			if (l == 999 && Name != "x")
				cout << "존재하지 않는 계좌주입니다." << endl;
			else
				break;
		}
		if (Name == "x")
			break;
		
		choosenum = 0;

		while (choosenum != 5)
		{
			cout << endl << "-------SWING ATM " << (account + l)->getName() << "님-------" << endl;
			cout << "1. 입금" << endl;
			cout << "2. 인출" << endl;
			cout << "3. 이체" << endl;
			cout << "4. 잔액 확인" << endl;
			cout << "5. 종료" << endl << endl;
			cout << "번호를 선택해주세요 >> ";
			cin >> choosenum;

			switch (choosenum)
			{
			case 1:
				{
					cout << "입금할 금액을 입력해주세요 >> ";
					(account + l)->deposit();
					cout << endl << "현재 " << (account + l)->getName() << "님의 잔액은 " << (account +l)->getMoney() << "원 입니다." << endl;
					break;
				}
			case 2:
				{
					cout << "얼마를 인출하시겠습니까? >> ";
					(account + l)->withdraw();
					cout << "비밀번호를 입력해주세요 >> ";
					(account + l)->pwcheck2();
					cout << endl << "현재 " << (account + l)->getName() << "님의 잔액은 " << (account + l)->getMoney() << "원 입니다." << endl;
					break;
				}
			case 3:
				{
					cout << "누구에게 보내겠습니까? >> ";
					cin >> receiver;

					m = 999;

					for (k = 0; k < number; k++)
					{
						if (receiver == (account + k)->getName())
							m = k;
					}
					if (m == 999) 
						break;

					cout << "얼마를 보내겠습니까? >> ";
					cin >> sendMoney;
					(account + l)->send((account + m)->getName(), sendMoney);
					cout << "비밀번호를 입력해주세요 >> ";
					(account + l)->pwcheck2();
					cout << endl << (account + m)->getName() << "님께 " << sendMoney << "원을 보냈습니다." << endl;
					(account + m)->receive(sendMoney);
					cout << endl << "현재 " << (account + l)->getName() << "님의 잔액은 " << (account + l)->getMoney() << "원 입니다." << endl;
					break;
				}
			case 4:
				cout << (account + l)->getName() << "님의 현재 잔액은 " << (account + l)->getMoney() << "원 입니다." << endl; break;
			case 5:
				break;

			}
		}
	}
	cout << "ATM을 종료합니다." << endl;

	return 0;
}