#include"link.h"
#include<string>
void help(void)
{
	cout << "********************************************" << endl;
	cout << "help:������Ϣ				   *" << endl;
	cout << "insert:��������ڵ�			   *" << endl;
	cout << "print:��������ڵ�			   *" << endl;
	cout << "search:��ѯ����ĳ���ڵ�			   *" << endl;
	cout << "delete:ɾ������ĳ���ڵ�			   *" << endl;
	cout << "free:�ͷ���������			   *" << endl;
	cout << "quit:�˳�����				   *" << endl;
	cout << "cls:�����Ļ				   *" << endl;
	cout << "********************************************" << endl;

}
void insert(Stu** student, Stu* one)  //�޷��޸����������ֵ
{
	one->next = (*student)->next;
	(*student)->next = one;
}

void print(s* _head)   //�ɹ�ʵ��
{
	while (_head->next != NULL)
	{
		_head = _head->next;
		cout << "id: " << _head->ID << "   " << "name: " << _head->name << endl;
	}
}



void search_ID(s* _head,string name)  //�ɹ�ʵ��
{
	int flag = 0;
	while (_head->next != NULL)
	{
		_head = _head->next;
		if (_head->name == name) {
			cout << "nameΪ" << name << "��ID��: " << _head->ID << endl;
			flag = 1;
			break;
		}
		else
			cout << "���ڲ�ѯ�У����Եȡ�����������" << endl;
	}
	if (!flag) {
		cout << "��Ǹ������û����ϵͳ���ҵ����name���������name�Ƿ���ȷ�����²���" << endl;
	}
	cout << endl;
}

void search_name(s* _head,string id)  //�ɹ�ʵ��
{
	int flag = 0;
	while (_head->next != NULL)
	{
		_head = _head->next;
		if (_head->ID == id) {
			cout << "IDΪ" << id << "��name��: " << _head->name << endl;
			flag = 1;
			break;
		}
		else
			cout << "���ڲ�ѯ�У����Եȡ�����������" << endl;
	}
	if (!flag) {
		cout << "��Ǹ������û����ϵͳ���ҵ����ID���������ID�Ƿ���ȷ�����²���" << endl;
	}
	cout << endl;
}


void delete_ID(s** _head,string id)    //�ɹ�ʵ��
{
	int flag = 0;
	s* tmp;
	tmp = (*_head)->next;
	while ((*_head)->next != NULL)
	{
		if (tmp->ID == id)
		{
			(*_head)->next = tmp->next;
			cout << "�ɹ���idΪ " << id << "��ϵͳ��ɾ��" << endl;
			flag = 1;
			break;
		}
		else
			cout << "���ڲ�ѯ�У����Եȡ�����������" << endl;
		if((*_head)->next != NULL)
			(*_head) = (*_head)->next;
	}
	if (!flag) {
		cout << "��Ǹ������û����ϵͳ���ҵ����ID���������ID�Ƿ���ȷ�����²���" << endl;
	}
	cout << endl;
}

void delete_name(s** _head,string _name)		//�ɹ�ʵ��
{
	int flag = 0;
	s* tmp;
	tmp = (*_head)->next;
	while ((*_head)->next != NULL)
	{
		if (tmp->name == _name)
		{
			(*_head)->next = tmp->next;
			cout << "�ɹ���nameΪ " << _name << "��ϵͳ��ɾ��" << endl;
			flag = 1;
			break;
		}
		else
			cout << "���ڲ�ѯ�У����Եȡ�����������" << endl;
		if ((*_head)->next != NULL)
			(*_head) = (*_head)->next;
	}
	if (!flag) {
		cout << "��Ǹ������û����ϵͳ���ҵ����name���������name�Ƿ���ȷ�����²���" << endl;
	}
	cout << endl;
}

void free(s** _head)	//�ɹ�ʵ��
{
	(*_head)->next = NULL;
	cout << "������Ϣ�������" << endl;
}

