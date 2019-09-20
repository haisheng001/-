//封装函数显示界面   如void showMenu()
//在main函数中调用封装好的函数

#include<iostream>
#include<string>  //string文件头
#define MAX 2000 //通讯录最大储存人数
using namespace std;

//设计联系人的结构体
struct  Person
{
	//姓名
	string m_Name;
	//性别   1、男   2、女
	int m_sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//通讯录的结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person PersonArray[MAX];

	//通讯录总当前记录联系人个数
	int m_Size;
};

//1、添加联系人
void AddPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，如果已满则不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入1或者2可以退出循环     输入有误，需重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入号码：" << endl;
		string Phone;
		cin >> Phone;
		abs->PersonArray[abs->m_Size].m_Phone = Phone;

		//住址
		cout << "请输入家庭住址：" << endl;
		string Address;
		cin >> Address;
		abs->PersonArray[abs->m_Size].m_Addr = Address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//2、显示联系人
void showPerson(Addressbooks * abs)
{
	//判断通讯录中人数是否为0，如果是0，提示为空
	//如果不是0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->PersonArray[i].m_Name << "\t";
			cout << "性别：" << (abs->PersonArray[i].m_sex ==1?"男":"女") << "\t";
			cout << "年龄：" << abs->PersonArray[i].m_Age << "\t";
			cout << "电话：" << abs->PersonArray[i].m_Phone << "\t";
			cout << "住址:  " << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//菜单界面
void showMenu()
{
	cout << "\t*****欢迎使用通讯录*****" << endl;
	cout << "\t***请输入你需要的选项***" << endl;
	cout << "\t************************" << endl;
	cout << "\t******1、添加联系人*****" << endl;
	cout << "\t******2、显示联系人*****" << endl;
	cout << "\t******3、删除联系人*****" << endl;
	cout << "\t******4、查找联系人*****" << endl;
	cout << "\t******5、修改联系人*****" << endl;
	cout << "\t******6、清空联系人*****" << endl;
	cout << "\t******0、退出通讯录*****" << endl;
	cout << "\t************************" << endl;
}

int main()
{
	//创建通讯录的结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;//创建用户选择的变量

	while (true)
	{
		//菜单的调用
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  //1、添加联系人
			AddPerson(&abs);
			break;
		case 2:  //2、显示联系人
			showPerson(&abs);
			break;
		case 3:  //3、删除联系人
			break;
		case 4:  //4、查找联系人
			break;
		case 5:  //5、修改联系人
			break;
		case 6:  //6、清空联系人
			break;
		case 0:  //0、退出通讯录
			cout << "欢迎下次再使用通讯录" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}