#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
List Delete( List L, ElementType minD, ElementType maxD );


int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
} 
List Delete( List L, ElementType minD, ElementType maxD ){
	int k = 0;
	int i;
	for(i = 0;i<=L->Last;i++){
		if(L->Data[i]>minD&&L->Data[i]<maxD){
			continue;
		}else{
			L->Data[k++] = L->Data[i];
		}
	}
	L->Last = k-1;
	return L;
} 

