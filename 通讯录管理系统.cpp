#include<iostream>
#include<string.h>
#include"showMenue.h"
#include"quit.h"
#define MAX 1000
using namespace std;
//�����ϵ�˽ṹ��
struct Person {
	//����
	string m_Name;
	//�Ա� 1�� 2Ů
	int m_Sex;
	//����
	int m_Age;
	//סַ
	string m_Addr;
	//�绰
	string m_Phone;
};
//���ͨѶ¼�ṹ��
struct Addressbook {
	struct Person personArry[MAX];
	int m_Size;
};
//�����ϵ�˺���
void addPerson(Addressbook* abs) {
	if (abs->m_Size == MAX) {
		std::cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		//����
		cout << "������������  " << endl;
		string name;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name=name;
		//�Ա�
		cout << "�������Ա�  " << endl;
		cout << "1�����У�2����Ů" << endl;
		int sex=0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArry[abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "������ĸ�ʽ������,����������"<<endl;
		}
		
		//����
		cout << "���������䣺  " << endl;
		int age=0;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;
		//סַ
		cout << "������סַ��  " << endl;
		string addr;
		cin >> addr;
		abs->personArry[abs->m_Size].m_Addr = addr;
		//�绰
		cout << "������绰��  " << endl;
		string phone;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
	}
	abs->m_Size++;
	cout << "����ӳɹ���" << endl;
	system("pause");
	system("cls");

}
//��ʾ��ϵ�˺���
void showPerson(Addressbook* abs) {
	if (abs->m_Size == 0)
		cout << "ͨѶ¼�ǿյ�"<<endl;
	else {
		int i;
		for (i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArry[i].m_Name<<"\t";
			if (abs->personArry[i].m_Sex==1)//��������Ŀ�����
			{
				cout << "�Ա���" << "\t";
			}
			else {
				cout << "�Ա�Ů" << "\t";
			}
			cout << "���䣺" << abs->personArry[i].m_Age<< "\t";
			cout << "סַ��" << abs->personArry[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ���ڣ�������ڷ�����ϵ�˵ľ���λ�ã������ڷ���-1
int isExist(Addressbook* abs, string name) {
	int i;
	//������ϵ�����֣�ƥ�����򷵻�����λ��
	for (i = 0; i < abs->m_Size; i++) {
		if (name == abs->personArry[i].m_Name)
			return i;
	}
	//������������û�ҵ�������-1
	return -1;
}
//ɾ��ָ����ϵ��
void deletePerson(Addressbook* abs) {
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	//�鵽��
	else {
		int i;
		for (i = ret; ret < abs->m_Size; i++) {
			Person t;
			t=abs->personArry[i];
			abs->personArry[i] = abs->personArry[i + 1];
			abs->personArry[i + 1] = t;
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//����ָ����ϵ��
void findPerson(Addressbook* abs) {
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж��Ƿ����
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	//�鵽��
	else {
		cout << "������" << abs->personArry[ret].m_Name << "\t";
		if (abs->personArry[ret].m_Sex == 1)//��������Ŀ�����
		{
			cout << "�Ա���" << "\t";
		}
		else {
			cout << "�Ա�Ů" << "\t";
		}
		cout << "���䣺" << abs->personArry[ret].m_Age << "\t";
		cout << "סַ��" << abs->personArry[ret].m_Addr << endl;
	}
}
//�޸���ϵ��
void modifyPerson(Addressbook* abs) {
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "���ҵ���ϵ�ˣ�������������Ϣ" << endl;
		//����
		cout << "������������  " << endl;
		string name;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�  " << endl;
		cout << "1�����У�2����Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArry[abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "������ĸ�ʽ������,����������" << endl;
		}

		//����
		cout << "���������䣺  " << endl;
		int age = 0;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;
		//סַ
		cout << "������סַ��  " << endl;
		string addr;
		cin >> addr;
		abs->personArry[abs->m_Size].m_Addr = addr;
		//�绰
		cout << "������绰��  " << endl;
		string phone;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");

}
//�����ϵ��
void cleanPerson(Addressbook* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�ѿ�"<<endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbook abs;
	abs.m_Size = 0;
	while (true)
	{
		showMenue();
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs); break;//�����ϵ��
		case 2:
			showPerson(&abs); break;//��ʾ��ϵ��
		case 3: 
			deletePerson(&abs);
		/*{
			string name;
			cout << "��������ϵ��������" << endl;
			cin >> name;
			if(isExist(&abs, name)==-1){
				cout << "���޴���" << endl;
			}
		}	break; */
		//ɾ����ϵ��
		case 4:findPerson(&abs); break;// ������ϵ��
		case 5:modifyPerson(&abs); break;//�޸���ϵ��
		case 6:cleanPerson(&abs); break;//���ͨѶ¼
		case 0:quit();//�˳�ͨѶ¼
			system("pause");
			return 0;//�ҵ�������
		}
	}
}