#pragma once
#include<iostream>
#include<string>
using namespace std;
void help(void);
struct Stu
{
	string ID;
	string name;
	Stu* next;
}typedef s;

void insert(Stu** student, Stu* one);
void print(s* _head);
void search_name(s* _head,string id);
void search_ID(s* _head,string name);
void delete_ID(s** _head,string id);
void delete_name(s** _head,string _name);
void free(s** _head);