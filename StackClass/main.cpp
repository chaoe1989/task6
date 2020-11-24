#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include "class.h"
const int N = 3;
using namespace std;

int main()
{
	Graduate g[N];
	for (int i=0;i<N;i++)
	{
		g[i].OutInfor(); 
		cout << "score grade:" << ScoreGrade(g[i]) << endl;
	}

	Graduate gra1("li", 1, 01, 80, "computer", "zhang");
	gra1.OutInfor();
	cout << "score grade:" << ScoreGrade(gra1) << endl;

	const Graduate gra2("wang", 1, 02, 70, "computer", "zhang");
	gra2.OutInfor();
	cout << "score grade:" << ScoreGrade(gra2) << endl;

	Graduate::OutcScore();
	system("pause");

	return 0;
}