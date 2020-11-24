#pragma once
#ifndef __CLASS_H__
#define __CLASS_H__

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <windows.h>

using namespace std;

/*----------------------------------*
	           类定义
*-----------------------------------*/
class Graduate
{
private:
	string name; //姓名
	bool gender; //性别
	int id; //学号
	double score; //入学成绩
	string research; //研究领域
	string tutor; //指导教师
	const string university; //学校名称
public:
	Graduate(); //无参构造函数
	Graduate(string n, bool g, int i, double s, string r, string t); //有参构造函数
	Graduate(const Graduate &gra); //拷贝构造函数
	~Graduate(); // 析构函数
	void OutInfor(); //普通成员函数形式输出研究生基本数据信息
	void OutInfor()const; //常成员函数形式输出研究生基本数据信息
	static double total;
	static int number;
	static void OutcScore();
	friend char ScoreGrade(const Graduate &); //以友元函数形式计算每个研究生对象的成绩等级
};

double Graduate::total = 0;
int Graduate::number = 0;

Graduate::Graduate():university("sdnu")  // 常数据成员初始化
{
	cout << "please input the information of the graduate:" << endl;
	cout << "name:";
	getline(cin, name);
	cout << "gender:";
	cin >> gender;
	cout << "id:" ;
	cin >> id;
	cout << "score:";
	cin >> score;
	total = total + score;
	cin.ignore();
	cout << "research:" ;
	getline(cin, research);
	cout << "tutor:" ;
	getline(cin, tutor);
	number++;
}

Graduate::Graduate(string n, bool g, int i, double s, string r, string t) :university("sdnu")
{
	name = n;
	gender = g;
	id = i;
	score = s;
	research = r;
	tutor = t;
	total = total + score;
	number++;
}

Graduate::Graduate(const Graduate &gra) :university("sdnu")
{
	name = gra.name;
	gender = gra.gender;
	id = gra.id;
	score = gra.score;
	research = gra.research;
	tutor = gra.tutor;
}

Graduate::~Graduate()
{
	total -= score;
	number--;
}

void Graduate::OutInfor()
{
	cout << "name:" << name << endl;
	cout << "gender:" << gender << endl;
	cout << "id:" << id << endl;
	cout << "score:" << score << endl;
	cout << "research:" <<research<<endl;
	cout << "tutor:" <<tutor<<endl;
	cout << "university:" << university << endl;
}

void Graduate::OutInfor()const
{
	cout << "name:" << name << endl;
	cout << "gender:" << gender << endl;
	cout << "id:" << id << endl;
	cout << "score:" << score << endl;
	cout << "research:" <<research<< endl;
	cout << "tutor:" <<tutor<< endl;
	cout << "university:" << university << endl;
}


char ScoreGrade(const Graduate &Gra)
{
	switch (int(Gra.score/10))
	{
	case 10:
	case 9:
		return 'A';
		break;
	case 8:
		return 'B';
		break;
	case 7:
		return 'C';
		break;
	case 6:
		return 'D';
		break;
	default:
		return 'E';
		break;
	}
}

void Graduate::OutcScore()
{
	cout << "average score:" << total / number << endl;
}

#endif