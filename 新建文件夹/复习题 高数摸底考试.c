#include <stdio.h>
	struct student{
		char number[20];
		int grade;
	};
int main(){
	struct student s[100];
	int n,i,a=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s%d", s[i].number,&s[i].grade);
		if(s[i].grade<60){
			a++;
		}
	}
	printf("%d\n",a);
	 for(i=1;i<=n;i++){
		if(s[i].grade<60){
			printf("%s %d\n",s[i].number,s[i].grade);
		}
	}
	return 0;
} 
