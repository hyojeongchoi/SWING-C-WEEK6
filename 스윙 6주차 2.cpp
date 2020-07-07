#include<iostream>
using namespace std;

class PhoneBook {
private:
	string name; // ��ȭ��ȣ
	string number; //�̸�

public:
	PhoneBook();   //������
	void setPnum(string number); //��ȭ��ȣ ����
	void setName(string name); //�̸� ����
	void addPhone(string name, string number); //�̸��� ��ȭ��ȣ ����
	string getPnum(); //��ȭ��ȣ ��������
	string getName(); //�̸� ��������
	void changePnum (string number);  //��ȣ�� �����ϱ� ���ؼ� �߰�����
};

class PhoneBookManager {
private:
	PhoneBook* phoneB; // ��ü �迭 ������ ���� ����
	int size; // ��ü �迭�� ũ��

public:
	PhoneBookManager(int num);  //������- PhoneBook���� ��ü �迭 ����
	void showAll();  // ��ȭ��ȣ�� ��� ����
	void searchPnum(); //��ȭ��ȣ ã��
	void addPnum(); // ��ȭ��ȣ ��ü �߰� ���� (�迭�� ���� ������ +1�� �Ǿ�� ��)
	void editPnum(); //��ȭ��ȣ ����
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
		cout << n + 1 << "��° ����� �̸��� �Է����ּ��� >> ";
		cin >> name1;
		phoneB[n].setName(name1);
		cout << n + 1 << "��° ����� ��ȭ��ȣ�� �Է����ּ��� >> ";
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
	cout << endl << endl << "������ ��ȣ�� �˻��ϰڽ��ϱ�? >> ";
	cin >> search;
	for (i = 0; i < size; i++)
	{
		if (search == phoneB[i].getName())
			k = i;
	}
	if (k < size)
		cout << phoneB[k].getName() << "���� ��ȭ��ȣ�� : " << phoneB[k].getPnum() << endl;
	if (k == 100)
		cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}
void PhoneBookManager::addPnum()
{
	string newname, newnumber;
	int i;
	
	cout << endl << endl << "�̸��� �Է����ּ��� >> ";
	cin >> newname;
	cout << "��ȭ��ȣ�� �Է����ּ��� >> ";
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

	cout << "��ȭ��ȣ�� �߰��Ǿ����ϴ�." << endl;
}

void PhoneBookManager::editPnum()
{
	int i, k = 0;
	string editname, editnumber;
	cout << endl << endl << "������ ��ȣ�� �����ϰڽ��ϱ�? >> ";
	cin >> editname;
	for (i = 0; i < size; i++)
	{
		if (editname == phoneB[i].getName())
			k = i;
	}
	if (k < size) // m�� size���� ���� ���->�ش��ϴ� �ε��� �� ����->��ȭ��ȣ ���� ����
	{
		cout << "������ ��ȣ�� �Է����ּ��� >> ";
		cin >> editnumber;
		phoneB[k].changePnum(editnumber);
		cout << "��ȭ��ȣ�� ����Ǿ����ϴ�." << endl;
	}
	if (k == 100)
		cout << "����ó�� �������� �ʽ��ϴ�." << endl;
}
int main()
{
	int numberofPnum; 
	int menu = 0;

	cout << "------------ swing ��ȭ��ȣ�� ------------" << endl;
	cout << "������ ��ȭ��ȣ�� ���� �Է����ּ��� >> ";
	cin >> numberofPnum;
	PhoneBookManager manager(numberofPnum);
	while (menu != 5)
	{
		cout << endl << " --- SWING ��ȭ��ȣ�� --- " << endl;
		cout << "1. ��ȭ��ȣ�� ����" << endl;
		cout << "2. ��ȭ��ȣ �˻�" << endl;
		cout << "3. ��ȭ��ȣ �߰��ϱ�" << endl;
		cout << "4. ��ȭ��ȣ �����ϱ�" << endl;
		cout << "5. ����" << endl;

		cout << "��ȣ�� �Է����ּ��� >> ";
		cin >> menu;

		switch (menu)
		{
		case 1: manager.showAll(); break;
		case 2: manager.searchPnum(); break;
		case 3: manager.addPnum(); break;
		case 4: manager.editPnum(); break;
		case 5: cout << endl << endl << "���α׷��� �����մϴ�." << endl; break;
		default: cout << endl << endl << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
	}
}