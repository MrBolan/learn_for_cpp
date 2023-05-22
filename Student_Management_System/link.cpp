#include"link.h"
#include<string>
void help(void)
{
	cout << "********************************************" << endl;
	cout << "help:帮助信息				   *" << endl;
	cout << "insert:插入链表节点			   *" << endl;
	cout << "print:遍历链表节点			   *" << endl;
	cout << "search:查询链表某个节点			   *" << endl;
	cout << "delete:删除链表某个节点			   *" << endl;
	cout << "free:释放整个链表			   *" << endl;
	cout << "quit:退出程序				   *" << endl;
	cout << "cls:清空屏幕				   *" << endl;
	cout << "********************************************" << endl;

}
void insert(Stu** student, Stu* one)  //无法修改主函数里的值
{
	one->next = (*student)->next;
	(*student)->next = one;
}

void print(s* _head)   //成功实现
{
	while (_head->next != NULL)
	{
		_head = _head->next;
		cout << "id: " << _head->ID << "   " << "name: " << _head->name << endl;
	}
}



void search_ID(s* _head,string name)  //成功实现
{
	int flag = 0;
	while (_head->next != NULL)
	{
		_head = _head->next;
		if (_head->name == name) {
			cout << "name为" << name << "的ID是: " << _head->ID << endl;
			flag = 1;
			break;
		}
		else
			cout << "正在查询中，请稍等······" << endl;
	}
	if (!flag) {
		cout << "抱歉，我们没有在系统中找到这个name，请您检查name是否正确并重新操作" << endl;
	}
	cout << endl;
}

void search_name(s* _head,string id)  //成功实现
{
	int flag = 0;
	while (_head->next != NULL)
	{
		_head = _head->next;
		if (_head->ID == id) {
			cout << "ID为" << id << "的name是: " << _head->name << endl;
			flag = 1;
			break;
		}
		else
			cout << "正在查询中，请稍等······" << endl;
	}
	if (!flag) {
		cout << "抱歉，我们没有在系统中找到这个ID，请您检查ID是否正确并重新操作" << endl;
	}
	cout << endl;
}


void delete_ID(s** _head,string id)    //成功实现
{
	int flag = 0;
	s* tmp;
	tmp = (*_head)->next;
	while ((*_head)->next != NULL)
	{
		if (tmp->ID == id)
		{
			(*_head)->next = tmp->next;
			cout << "成功将id为 " << id << "从系统中删除" << endl;
			flag = 1;
			break;
		}
		else
			cout << "正在查询中，请稍等······" << endl;
		if((*_head)->next != NULL)
			(*_head) = (*_head)->next;
	}
	if (!flag) {
		cout << "抱歉，我们没有在系统中找到这个ID，请您检查ID是否正确并重新操作" << endl;
	}
	cout << endl;
}

void delete_name(s** _head,string _name)		//成功实现
{
	int flag = 0;
	s* tmp;
	tmp = (*_head)->next;
	while ((*_head)->next != NULL)
	{
		if (tmp->name == _name)
		{
			(*_head)->next = tmp->next;
			cout << "成功将name为 " << _name << "从系统中删除" << endl;
			flag = 1;
			break;
		}
		else
			cout << "正在查询中，请稍等······" << endl;
		if ((*_head)->next != NULL)
			(*_head) = (*_head)->next;
	}
	if (!flag) {
		cout << "抱歉，我们没有在系统中找到这个name，请您检查name是否正确并重新操作" << endl;
	}
	cout << endl;
}

void free(s** _head)	//成功实现
{
	(*_head)->next = NULL;
	cout << "所有信息均已清空" << endl;
}

