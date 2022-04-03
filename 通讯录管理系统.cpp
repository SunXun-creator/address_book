#include<iostream>
#include<string.h>
#include"showMenue.h"
#include"quit.h"
#define MAX 1000
using namespace std;
//设计联系人结构体
struct Person {
	//姓名
	string m_Name;
	//性别 1男 2女
	int m_Sex;
	//年龄
	int m_Age;
	//住址
	string m_Addr;
	//电话
	string m_Phone;
};
//设计通讯录结构体
struct Addressbook {
	struct Person personArry[MAX];
	int m_Size;
};
//添加联系人函数
void addPerson(Addressbook* abs) {
	if (abs->m_Size == MAX) {
		std::cout << "通讯录已满" << endl;
		return;
	}
	else {
		//姓名
		cout << "请输入姓名：  " << endl;
		string name;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name=name;
		//性别
		cout << "请输入性别：  " << endl;
		cout << "1——男，2——女" << endl;
		int sex=0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArry[abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "您输入的格式有问题,请重新输入"<<endl;
		}
		
		//年龄
		cout << "请输入年龄：  " << endl;
		int age=0;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;
		//住址
		cout << "请输入住址：  " << endl;
		string addr;
		cin >> addr;
		abs->personArry[abs->m_Size].m_Addr = addr;
		//电话
		cout << "请输入电话：  " << endl;
		string phone;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
	}
	abs->m_Size++;
	cout << "您添加成功了" << endl;
	system("pause");
	system("cls");

}
//显示联系人函数
void showPerson(Addressbook* abs) {
	if (abs->m_Size == 0)
		cout << "通讯录是空的"<<endl;
	else {
		int i;
		for (i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArry[i].m_Name<<"\t";
			if (abs->personArry[i].m_Sex==1)//可以用三目运算符
			{
				cout << "性别：男" << "\t";
			}
			else {
				cout << "性别：女" << "\t";
			}
			cout << "年龄：" << abs->personArry[i].m_Age<< "\t";
			cout << "住址：" << abs->personArry[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在，如果存在返回联系人的具体位置，不存在返回-1
int isExist(Addressbook* abs, string name) {
	int i;
	//遍历联系人名字，匹配上则返回所在位置
	for (i = 0; i < abs->m_Size; i++) {
		if (name == abs->personArry[i].m_Name)
			return i;
	}
	//如果遍历完成仍没找到，返回-1
	return -1;
}
//删除指定联系人
void deletePerson(Addressbook* abs) {
	cout << "请输入要删除的联系人" << endl;
	string name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	//查到了
	else {
		int i;
		for (i = ret; ret < abs->m_Size; i++) {
			Person t;
			t=abs->personArry[i];
			abs->personArry[i] = abs->personArry[i + 1];
			abs->personArry[i + 1] = t;
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//查找指定联系人
void findPerson(Addressbook* abs) {
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断是否存在
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	//查到了
	else {
		cout << "姓名：" << abs->personArry[ret].m_Name << "\t";
		if (abs->personArry[ret].m_Sex == 1)//可以用三目运算符
		{
			cout << "性别：男" << "\t";
		}
		else {
			cout << "性别：女" << "\t";
		}
		cout << "年龄：" << abs->personArry[ret].m_Age << "\t";
		cout << "住址：" << abs->personArry[ret].m_Addr << endl;
	}
}
//修改联系人
void modifyPerson(Addressbook* abs) {
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "已找到联系人，请重新输入信息" << endl;
		//姓名
		cout << "请输入姓名：  " << endl;
		string name;
		cin >> name;
		abs->personArry[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：  " << endl;
		cout << "1——男，2——女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArry[abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "您输入的格式有问题,请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：  " << endl;
		int age = 0;
		cin >> age;
		abs->personArry[abs->m_Size].m_Age = age;
		//住址
		cout << "请输入住址：  " << endl;
		string addr;
		cin >> addr;
		abs->personArry[abs->m_Size].m_Addr = addr;
		//电话
		cout << "请输入电话：  " << endl;
		string phone;
		cin >> phone;
		abs->personArry[abs->m_Size].m_Phone = phone;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");

}
//清空联系人
void cleanPerson(Addressbook* abs) {
	abs->m_Size = 0;
	cout << "通讯录已空"<<endl;
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
			addPerson(&abs); break;//添加联系人
		case 2:
			showPerson(&abs); break;//显示联系人
		case 3: 
			deletePerson(&abs);
		/*{
			string name;
			cout << "请输入联系人姓名：" << endl;
			cin >> name;
			if(isExist(&abs, name)==-1){
				cout << "查无此人" << endl;
			}
		}	break; */
		//删除联系人
		case 4:findPerson(&abs); break;// 查找联系人
		case 5:modifyPerson(&abs); break;//修改联系人
		case 6:cleanPerson(&abs); break;//清空通讯录
		case 0:quit();//退出通讯录
			system("pause");
			return 0;//找到出口了
		}
	}
}