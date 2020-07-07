#include<iostream>
using namespace std;

class PhoneBook {
private:
	string name; // 전화번호
	string number; //이름

public:
	PhoneBook();   //생성자
	void setPnum(string number); //전화번호 저장
	void setName(string name); //이름 저장
	void addPhone(string name, string number); //이름과 전화번호 저장
	string getPnum(); //전화번호 가져오기
	string getName(); //이름 가져오기
	void changePnum (string number);  //번호를 수정하기 위해서 추가했음
};

class PhoneBookManager {
private:
	PhoneBook* phoneB; // 객체 배열 생성을 위한 선언
	int size; // 객체 배열의 크기

public:
	PhoneBookManager(int num);  //생성자- PhoneBook으로 객체 배열 생성
	void showAll();  // 전화번호부 목록 보기
	void searchPnum(); //전화번호 찾기
	void addPnum(); // 전화번호 객체 추가 생성 (배열의 원소 개수가 +1이 되어야 함)
	void editPnum(); //전화번호 수정
};

PhoneBook::PhoneBook()
{}

void PhoneBook::setName(string name)
{
	this->name = name;
}
void PhoneBook::setPnum(string number)
{
	this->number = number;
}
void PhoneBook::addPhone(string name, string number)
{
	this->number = number;
	this->name = name;
}
string PhoneBook::getPnum()
{
	return number;
}
string PhoneBook::getName()
{
	return name;
}
void PhoneBook::changePnum(string number)
{
	this->number.replace(0, 13, number);
}
PhoneBookManager::PhoneBookManager(int num)
{
	int n;
	string name1, num1;
	size = num;
	phoneB = new PhoneBook[size];

	for (n = 0; n < num; n++)
	{
		cout << n + 1 << "번째 사람의 이름을 입력해주세요 >> ";
		cin >> name1;
		phoneB[n].setName(name1);
		cout << n + 1 << "번째 사람의 전화번호를 입력해주세요 >> ";
		cin >> num1;
		phoneB[n].setPnum(num1);
		cout << endl;
	}
}
void PhoneBookManager::showAll()
{
	cout << endl << endl;
	int k=0;
	for (k = 0; k < size; k++)
	{
		cout << k + 1 << ". " << phoneB[k].getName()<<" :: " << phoneB[k].getPnum() << endl;
	}
}
void PhoneBookManager::searchPnum()
{
	int i, k = 100;
	string search;
	cout << endl << endl << "누구의 번호를 검색하겠습니까? >> ";
	cin >> search;
	for (i = 0; i < size; i++)
	{
		if (search == phoneB[i].getName())
			k = i;
	}
	if (k < size)
		cout << phoneB[k].getName() << "님의 전화번호는 : " << phoneB[k].getPnum() << endl;
	if (k == 100)
		cout << "연락처가 존재하지 않습니다." << endl;
}
void PhoneBookManager::addPnum()
{
	string newname, newnumber;
	int i;
	
	cout << endl << endl << "이름을 입력해주세요 >> ";
	cin >> newname;
	cout << "전화번호를 입력해주세요 >> ";
	cin >> newnumber;

	PhoneBook* tmp = new PhoneBook[size + 1];
	for (i = 0; i < size; i++)
		tmp[i] = phoneB[i];
	delete[] phoneB;
	size++;

	phoneB = new PhoneBook[size];
	for (i = 0; i < size; i++)
		phoneB[i] = tmp[i];

	phoneB[size - 1].addPhone(newname, newnumber);

	cout << "전화번호가 추가되었습니다." << endl;
}

void PhoneBookManager::editPnum()
{
	int i, k = 0;
	string editname, editnumber;
	cout << endl << endl << "누구의 번호를 수정하겠습니까? >> ";
	cin >> editname;
	for (i = 0; i < size; i++)
	{
		if (editname == phoneB[i].getName())
			k = i;
	}
	if (k < size) // m이 size보다 작은 경우->해당하는 인덱스 값 있음->전화번호 변경 진행
	{
		cout << "변경할 번호를 입력해주세요 >> ";
		cin >> editnumber;
		phoneB[k].changePnum(editnumber);
		cout << "전화번호가 변경되었습니다." << endl;
	}
	if (k == 100)
		cout << "연락처가 존재하지 않습니다." << endl;
}
int main()
{
	int numberofPnum; 
	int menu = 0;

	cout << "------------ swing 전화번호부 ------------" << endl;
	cout << "저장할 전화번호의 수를 입력해주세요 >> ";
	cin >> numberofPnum;
	PhoneBookManager manager(numberofPnum);
	while (menu != 5)
	{
		cout << endl << " --- SWING 전화번호부 --- " << endl;
		cout << "1. 전화번호부 보기" << endl;
		cout << "2. 전화번호 검색" << endl;
		cout << "3. 전화번호 추가하기" << endl;
		cout << "4. 전화번호 수정하기" << endl;
		cout << "5. 종료" << endl;

		cout << "번호를 입력해주세요 >> ";
		cin >> menu;

		switch (menu)
		{
		case 1: manager.showAll(); break;
		case 2: manager.searchPnum(); break;
		case 3: manager.addPnum(); break;
		case 4: manager.editPnum(); break;
		case 5: cout << endl << endl << "프로그램을 종료합니다." << endl; break;
		default: cout << endl << endl << "잘못 입력하셨습니다." << endl;
		}
	}
}