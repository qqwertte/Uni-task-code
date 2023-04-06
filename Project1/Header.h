
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <stdbool.h>

#define N 5
#define M 6

struct birth {
	int mDay;
	int mMonth;
	int mYear;

};
struct mInfo {
	char mSurname[20];
	char mName[15];
	struct birth date;
	double mMarks[N];
};
struct student {
	struct  mInfo data;
	struct student* mpNext;
};

FILE* st;

struct student* Filllist(struct student** pHead);
void OutputList(struct student* pHead);
double avarenge(double arr[]);
void Swap(struct student** a, struct student** b);
void SortList(struct student* pHead);
int Elemcount(struct student* pHead);
void Free(struct student* pHead);
struct student* AddToSort(struct student** pHead);
float avgmarkgroup(struct student* pHead,float average);
struct  student* DeleteWithHighLessThanAvg(struct student** pHead, float average);;
struct student* DeleteWithout5(struct student* pHead, const int delim);
struct student* delete_item(struct student* last_curr, struct student* curr);