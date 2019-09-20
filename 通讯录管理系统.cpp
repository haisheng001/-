//��װ������ʾ����   ��void showMenu()
//��main�����е��÷�װ�õĺ���

#include<iostream>
#include<string>  //string�ļ�ͷ
#define MAX 2000 //ͨѶ¼��󴢴�����
using namespace std;

//�����ϵ�˵Ľṹ��
struct  Person
{
	//����
	string m_Name;
	//�Ա�   1����   2��Ů
	int m_sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};

//ͨѶ¼�Ľṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person PersonArray[MAX];

	//ͨѶ¼�ܵ�ǰ��¼��ϵ�˸���
	int m_Size;
};

//1�������ϵ��
void AddPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ���������������������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			//�������1����2�����˳�ѭ��     ������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->PersonArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "��������룺" << endl;
		string Phone;
		cin >> Phone;
		abs->PersonArray[abs->m_Size].m_Phone = Phone;

		//סַ
		cout << "�������ͥסַ��" << endl;
		string Address;
		cin >> Address;
		abs->PersonArray[abs->m_Size].m_Addr = Address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}

//2����ʾ��ϵ��
void showPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�������0����ʾΪ��
	//�������0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->PersonArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->PersonArray[i].m_sex ==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->PersonArray[i].m_Age << "\t";
			cout << "�绰��" << abs->PersonArray[i].m_Phone << "\t";
			cout << "סַ:  " << abs->PersonArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
//�˵�����
void showMenu()
{
	cout << "\t*****��ӭʹ��ͨѶ¼*****" << endl;
	cout << "\t***����������Ҫ��ѡ��***" << endl;
	cout << "\t************************" << endl;
	cout << "\t******1�������ϵ��*****" << endl;
	cout << "\t******2����ʾ��ϵ��*****" << endl;
	cout << "\t******3��ɾ����ϵ��*****" << endl;
	cout << "\t******4��������ϵ��*****" << endl;
	cout << "\t******5���޸���ϵ��*****" << endl;
	cout << "\t******6�������ϵ��*****" << endl;
	cout << "\t******0���˳�ͨѶ¼*****" << endl;
	cout << "\t************************" << endl;
}

int main()
{
	//����ͨѶ¼�Ľṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;//�����û�ѡ��ı���

	while (true)
	{
		//�˵��ĵ���
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  //1�������ϵ��
			AddPerson(&abs);
			break;
		case 2:  //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  //3��ɾ����ϵ��
			break;
		case 4:  //4��������ϵ��
			break;
		case 5:  //5���޸���ϵ��
			break;
		case 6:  //6�������ϵ��
			break;
		case 0:  //0���˳�ͨѶ¼
			cout << "��ӭ�´���ʹ��ͨѶ¼" << endl;
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