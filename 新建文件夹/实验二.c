#include<stdio.h>
#include<string.h>
struct massage {
    char id[10000];
    char name[80];
    int score1, score2, score3;
    double count;
};
int main () {
    struct massage student[100];
    int the;
    double r1, r2, r3;
    int i;
    int N;
    scanf("%d", &the);
    while(the != 0) {
        if(the==1) {
            scanf("%d", &N);
            for(i=0;i<N;i++) {
                scanf("%s %s %d %d %d", student[i].id, student[i].name, &student[i].score1, &student[i].score2, &student[i].score3);
                student[i].count = 0;
            }
        }
        else if(the==2) {
            scanf("%lf %lf %lf", &r1, &r2, &r3);
            for(i=0;i<N;i++) {
                student[i].count = student[i].score1 * r1 + student[i].score2 * r2 + student[i].score3 * r3;
            }
        }
        else if(the==3) {
            int n;
            scanf("%d", &n);
            if(n<=N) { 
                for(int a=N-1;a>=n-1;a--) {
                    student[a+1] = student[a];
                }
                scanf("%s %s %d %d %d", student[n-1].id, student[n-1].name, &student[n-1].score1, &student[n-1].score2, &student[n-1].score3);
                student[n-1].count = 0;
            }
            else {
                scanf("%s %s %d %d %d", student[N].id, student[N].name, &student[N].score1, &student[N].score2, &student[N].score3);
                student[N].count = 0;
            }
            N++;
        }
        else if(the==4) {
            int n;
            scanf("%d", &n);
            if(n<=N) {
                for(int a=n-1;a<N;a++) {
                    student[a] = student[a+1];
                }
                N--;
            }
        }
        else if(the==5) {
            char id1[10000];
            scanf("%s", &id1);
            int flot = 0, n = 0;
            for(i=0;i<N;i++) {
                if(strcmp(student[i].id, id1) == 0) {
                    flot = 1;
                    n = i;
                }
            }
            if(flot==1) {
                printf("学号:%s 姓名:%s 成绩1:%d 成绩2:%d 成绩3:%d 综合成绩:%.2lf\n", student[n].id, student[n].name, student[n].score1, student[n].score2, student[n].score3, student[n].count);
            }
            else {
                printf("Not Found.\n");
            }
            printf("\n");
        }
        else if(the==6) {
            char name1[80];
            scanf("%s", &name1);
            int flot = 0, n = 0;
            for(i=0;i<N;i++) {
                if(strcmp(student[i].name, name1) == 0) {
                    flot = 1;
                    n = i;
                }
            }
            if(flot==1) {
                printf("学号:%s 姓名:%s 成绩1:%d 成绩2:%d 成绩3:%d 综合成绩:%.2lf\n", student[n].id, student[n].name, student[n].score1, student[n].score2, student[n].score3, student[n].count);
            }
            else {
                printf("Not Found.\n");
            }
            printf("\n");
        }
        else if(the=7) {
            for(i=0;i<N;i++) {
                printf("学号:%s 姓名:%s 成绩1:%d 成绩2:%d 成绩3:%d 综合成绩:%.2lf\n", student[i].id, student[i].name, student[i].score1, student[i].score2, student[i].score3, student[i].count);
            }
            printf("\n");
        }
        scanf("%d", &the);
    }
    return 0;
}

