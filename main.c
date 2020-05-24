#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMP(a,b) (a > b) ? 1 : (a < b) ? -1 : 0

typedef struct personal_information{
    char id[11], name[21];
}PI;

typedef struct student_score{
    PI pi;
    int score[4];
}SS;

void getName(char n[21])
{
    getchar();
    int flag = -1, i = 0;
    while(flag != (*(n + i) = getchar())){
        if(*(n + i++) == ' ') flag = ' ';
    }
    *(n + i) = 0;
}

int CM1(const void *a, const void *b)  //Sort by ID
{
    SS c = *(SS *)a;
    SS d = *(SS *)b;
    return strcmp(c.pi.id, d.pi.id);
}

int CM2(const void *a, const void *b)  //Sort by Name
{
    SS c = *(SS *)a;
    SS d = *(SS *)b;
    return strcmp(c.pi.name, d.pi.name);
}

int CM3(const void *a, const void *b)  //Sort by Score1
{
    SS c = *(SS *)a;
    SS d = *(SS *)b;
    return CMP(c.score[0], d.score[0]);
}

int CM4(const void *a, const void *b)  //Sort by Score2
{
    SS c = *(SS *)a;
    SS d = *(SS *)b;
    return CMP(c.score[1], d.score[1]);
}

int CM5(const void *a, const void *b)  //Sort by Score3
{
    SS c = *(SS *)a;
    SS d = *(SS *)b;
    return CMP(c.score[2], d.score[2]);
}

int CM6(const void *a, const void *b)  //Sort by Score4
{
    SS c = *(SS *)a;
    SS d = *(SS *)b;
    return CMP(c.score[3], d.score[3]);
}

void showList(int n, SS l[n])
{
    for(int i = 0; i < n; i++)
        printf("%s %s %d %d %d %d\n", l[i].pi.id, l[i].pi.name, l[i].score[0], l[i].score[1], l[i].score[2], l[i].score[3]);
    putchar('\n');
}

#define sort(i) qsort((void *)list, n, sizeof(SS), CM ## i);
#define SL showList(n, list)
int main()
{
    //freopen("list", "r", stdin);

    int n;
    scanf("%d", &n);
    SS list[n];

    for(int i = 0; i < n; i++){
        scanf("%s", list[i].pi.id);
        getName(list[i].pi.name);
        scanf("%d %d %d %d", &list[i].score[0], &list[i].score[1], &list[i].score[2], &list[i].score[3]);
    }

    sort(1);
    SL;
    sort(2);
    SL;
    sort(3);
    SL;
    sort(4);
    SL;
    sort(5);
    SL;
    sort(6);
    SL;

    return 0;
}
