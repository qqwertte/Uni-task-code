
#include "Header.h";


int main(){
struct student* pHead = NULL;
st = fopen("students.txt", "r");
float average = 0;
const double delim = 5;
pHead = (Filllist(&pHead));
printf("Your list\n");
OutputList(pHead);
printf("Your sorted list\n");
SortList(pHead);
OutputList(pHead);
printf("Now, please, enter new student\n");
pHead = AddToSort(&pHead);
printf("\nYour list with new person\n");
OutputList(pHead);
printf("\n\n\t\tSORTED LIST BY AVG MARKS(Less than group avg)\n");
average = avgmarkgroup(pHead, average);
pHead = DeleteWithHighLessThanAvg(&pHead, average);
OutputList(pHead);
printf("\n\n\t\tPERSONS  WITH 5\n");
struct student* curr = pHead, * last_curr = NULL; bool ch = 0;
for (struct student* curr = pHead, *last_curr = NULL; curr != NULL; curr = curr->mpNext) {
    if (curr == NULL) break;
    if ((curr->data.mMarks[0] == delim) || (curr->data.mMarks[1] == delim) || (curr->data.mMarks[2] == delim)  || (curr->data.mMarks[3] == delim) || (curr->data.mMarks[4] == delim)) {
        ch = 1;

    }
    if (ch != 1) {
        if (last_curr == NULL) continue;
        else curr = delete_item(last_curr, curr);

    }

    ch = 0;
    last_curr = curr;
}



for (int i = 0; i < 61; i++) {
    printf("-");
}

while ((curr) != NULL) {
    printf("\n| %-10.10s | %-10.10s |   %2.2d.%2.2d.%2.2d |", curr->data.mSurname, curr->data.mName, curr->data.date.mDay, curr->data.date.mMonth, curr->data.date.mYear);

    for (int j = 0; j < N; j++) {

        printf(" %1.0lf,", curr->data.mMarks[j]);
    }

    printf("  ");

    curr = curr->mpNext;
    printf("\n");
}
for (int i = 0; i < 61; i++) {

    printf("-");
}
printf("\n\n");


return 0;
}