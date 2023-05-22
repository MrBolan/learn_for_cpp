﻿// Student_Management.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"link.h"
#include <iostream>
#include<string>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	help();
	string id;
	string _name;
	s* tmp_1;
	char cmd[64];
	char cmd0[64];
	s one = { "1225","luo",NULL};
	s* head = new s;
	s* student = &one;
	head->next = student;
	while (1)
	{
		cout << "请输入操作指令： " << endl;
		cin >> cmd;
		if (strcmp(cmd, "help") == 0)
			help();
		else if (strcmp(cmd, "insert") == 0)
		{
			tmp_1 = new s;
			cout << "请输入增加的学生的id和name（按id name的方式输入）: " << endl;
			cin >> id >> _name;
			tmp_1->ID = id;
			tmp_1->name = _name;
			insert(&head, tmp_1);
			cout << "插入节点成功！请继续操作" << endl;
			cout << endl;
			
		}
		else if (strcmp(cmd, "print") == 0)
		{
			if (head->next != NULL)
				print(head);
			else
				cout << "该学生管理系统中还没有学生的信息，请您先添加学生信息 " << endl;
			cout << endl;
		}
		else if (strcmp(cmd, "search") == 0)
		{
			cout << "如果你想通过name查询ID,请输入‘1’；如果你想通过ID查询name，请输入‘2’" << endl;
			cin >> cmd0;
			if (strcmp(cmd0, "1") == 0)
			{
				string name_1;
				cout << "请输入你要查询的name: ";
				cin >> name_1;
				search_ID(head,name_1);
			}
			else if (strcmp(cmd0, "2") == 0)
			{
				string ID_1 ;
				cout << "请输入你要查询的ID: ";
				cin >> ID_1;
				search_name(head,ID_1);
			}
			else
			{
				cout << "您输入的命令不合法，请您重新开始操作" << endl;
			}
		}
		else if (strcmp(cmd, "delete") == 0)
		{
			cout << "如果你想通过ID删除,请输入‘1’；如果你想通过name删除，请输入‘2’" << endl;
			cin >> cmd0;
			if (strcmp(cmd0, "1") == 0)
			{
				string ID_2;
				cout << "请输入你要删除的ID: ";
				cin >> ID_2;
				delete_ID(&head, ID_2);
			}
			else if (strcmp(cmd0, "2") == 0)
			{
				string name_2;
				cout << "请输入你要删除的name: ";
				cin >> name_2;
				delete_name(&head, name_2);
			}
			else
			{
				cout << "您输入的命令不合法，请您重新开始操作" << endl;
			}
		}
		else if (strcmp(cmd, "free") == 0)
		{
			free(&head);
		}
		else if (strcmp(cmd, "quit") == 0)
		{
			delete head;
			break;
		}
		else if (strcmp(cmd, "cls") == 0)
		{
			system("cls");
			help();
		}
		else
			cout << "您输入的指令错误，请重新输入指令" << endl;

	}
}

