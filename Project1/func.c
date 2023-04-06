#include "Header.h"

struct student* Filllist(struct student** pHead) {

	
	char date[20];
	char* x;

	struct student* p = (struct student*)malloc(sizeof(struct student));
	
	for (int i = 0; i < M; i++) {
		fscanf(st, "%s", p->data.mSurname);
		fscanf(st, "%s", p->data.mName);
		fscanf(st, "%s", date);

		x = strtok(date, ".");

		p->data.date.mDay = atoi(x);
		x = strtok(NULL, ".");
		p->data.date.mMonth = atoi(x);
		x = strtok(NULL, ".");
		p->data.date.mYear = atoi(x);


		for (int j = 0; j < N; j++) {

			fscanf(st, "%lf", &(p->data.mMarks[j]));
		}

		p->mpNext = NULL;
	

		if (!*pHead) {

			*pHead = p;
		}

		struct student* pp = (struct student*)malloc(sizeof(struct student));
		p->mpNext = pp;

		if (i < M - 1) {

			p = pp;
		}
	}
	p->mpNext = NULL;
	return (*pHead);
}


void OutputList(struct student* pHead) {

	struct student* pTemp = pHead;

	for (int i = 0; i < 61; i++){
		printf("-");
	}
	
	while ((pTemp) != NULL){
		printf("\n| %-10.10s | %-10.10s |   %2.2d.%2.2d.%2.2d |",  pTemp->data.mSurname, pTemp->data.mName, pTemp->data.date.mDay, pTemp->data.date.mMonth, pTemp->data.date.mYear);

		for (int j = 0; j < N; j++){

			printf(" %1.0lf,", pTemp->data.mMarks[j]);
		}
	
		printf("  ");

		pTemp = pTemp->mpNext;
		printf("\n");
	}
	for (int i = 0; i < 61; i++){

		printf("-");
	}
	printf("\n\n");
}


void SortList(struct student* pHead) {

	int counter = (Elemcount(pHead) - 1);
	struct student* temp = pHead;

	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if ((pHead->data.date.mYear) < ((pHead->mpNext->data.date.mYear)))
			{
				Swap(&pHead, &(pHead->mpNext));
			}
			else
			{
				if ((pHead->data.date.mYear) == (pHead->mpNext->data.date.mYear))
				{
					if ((pHead->data.date.mMonth) < (pHead->mpNext->data.date.mMonth))
					{
						Swap(&pHead, &(pHead->mpNext));
					}
					else
					{
						if ((pHead->data.date.mMonth) == (pHead->mpNext->data.date.mMonth))
						{
							if ((pHead->data.date.mDay) < (pHead->mpNext->data.date.mDay))
							{
								Swap(&pHead, &(pHead->mpNext));
							}
						}
					}
				}
			}
			pHead = pHead->mpNext;
		}
		pHead = temp;
	}

}


struct student* AddToSort(struct student** pHead) {
	struct student* pBefore = (*pHead), * pBefBef = (*pHead), * newElem = (struct student*)malloc(sizeof(struct student));

	printf("New student name and surname: ");
	scanf("%s %s", &(newElem->data.mSurname), &(newElem->data.mName));

	printf(" birthbay date: ");
	scanf("%d %d %d", &(newElem->data.date.mDay), &(newElem->data.date.mMonth), &(newElem->data.date.mYear));

	printf("Marks : \n");
	for (int i = 0; i < N; i++) {
		scanf("%lf", &(newElem->data.mMarks[i]));
	}
	double  counter = avarenge(newElem->data.mMarks);

	while (pBefore && pBefore != newElem) {
		if (counter > (avarenge(pBefore->data.mMarks)) && pBefore == (*pHead)) {

			newElem->mpNext = pBefore;
			(*pHead) = newElem;
			break;
		}
		else if (counter > (avarenge(pBefore->data.mMarks)) && pBefore != (*pHead)) {

			newElem->mpNext = pBefore;
			pBefBef->mpNext = newElem;
			break;
		}
		else if (counter < (avarenge(pBefore->data.mMarks)) && pBefore->mpNext == NULL) {

			pBefore->mpNext = newElem;
			newElem->mpNext = NULL;
			break;
		}
		pBefBef = pBefore;
		pBefore = pBefore->mpNext;
	}

	return (*pHead);
}



void Free(struct student* pHead){

	for (int i = 0; i < Elemcount(pHead); i++){
		struct student* pTemp = pHead;
		pHead = pHead->mpNext;
		free(pTemp);
	}
}


int Elemcount(struct student* pHead){

	int counter = 0;

	while (pHead){
		
		pHead = pHead->mpNext;
		counter++;
	}
	return counter;
}


double avarenge(double arr[]) {

	double sum = 0, avar = 0;

	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}
	avar = sum / N;
	return avar;
}


void Swap(struct student** a, struct student** b){

	struct mInfo temp ;

	temp = (*b)->data;
	(*b)->data = (*a)->data;
	(*a)->data = temp;
}

float avgmarkgroup(struct student* pHead,float average) {
	int studc = 0; float marks[30]; float sum = 0;
	struct student* tmp = pHead;
	while (tmp != NULL) {

		for (int j = 0; j < N+1; j++) {
			marks[j] = tmp->data.mMarks[j];
			sum += marks[j];
		}
		tmp = tmp->mpNext;
	}
	 average = sum / 30;
	printf("\n\t\t\t AVERAGE MARK = %f\t\t\t", average);
	return average;
}
	
struct  student* DeleteWithHighLessThanAvg(struct student** pHead,float average) {

	struct student* pbefore = (*pHead), * p = (*pHead), * pnext;

	while (p->mpNext) {

		if ((avarenge(p->data.mMarks)) > average) {
			if (p == (*pHead)) {

				(*pHead) = p->mpNext;
				free(p);
				p = NULL;
				p = (*pHead);
				pnext = p->mpNext;
			}
			else {

				pbefore->mpNext = p->mpNext;
				pnext = p->mpNext;
				free(p);
				p = NULL;
				p = pnext;
			}
		}
		else if (!((avarenge(p->data.mMarks)) > average)) {

			pbefore = p;
			p = p->mpNext;
			pnext = p->mpNext;
		}
	}
	p->mpNext = NULL;

	return *pHead;
}

struct student* DeleteWithout5(struct student* pHead, const int delim) {
	struct student* curr = pHead, * last_curr = NULL; bool ch=0;
	for (struct student* curr = pHead, *last_curr = NULL; curr != NULL; curr = curr->mpNext) {
		if (curr == NULL) break;
		if ((curr)->data.mMarks[0] == delim || (curr)->data.mMarks[1] == delim || (curr)->data.mMarks[2] == delim || (curr)->data.mMarks[3] == delim || (curr)->data.mMarks[4] == delim) ch = 1;
		if (ch != 1) {
			if (last_curr == NULL) continue;
			else curr = delete_item(last_curr, curr);

		}

		ch = 0;
		last_curr = curr;
	}

	return pHead;
}
struct student* delete_item(struct student* last_curr, struct student* curr) {
	last_curr->mpNext = curr->mpNext;
	free(curr);
	return(last_curr);
}


