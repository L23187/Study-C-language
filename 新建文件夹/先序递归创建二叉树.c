#include <stdio.h>
#include <stdlib.h>
typedef char Datatype;
/*������*/
typedef struct Node {
	Datatype data;
	struct Node *LChild;
	struct Node *RChild;
} BiTNode, *BiTree;
 
void createBiTree(BiTree *tree);
void traverseTree(BiTree tree); 
int main(int argc, char *argv[]) {
	BiTree tree;
	printf("������������н���������:\n");
	createBiTree(&tree);
	traverseTree(tree);
	return 0;
}
 
void createBiTree(BiTree *tree) {
	char ch;
	ch = getchar();
	if(ch == ' ') {
		*tree = NULL;
	} else {
		//����һ���½��
		*tree = (BiTree)malloc(sizeof(BiTNode));
		(*tree)->data = ch;
		//����������
		createBiTree(&((*tree)->LChild));
		//����������
		createBiTree(&((*tree)->RChild));
	}
}
/**�������Ľ��*/
void traverseTree(BiTree tree) {
	int i;
	if(tree == NULL) {
		return;
	}
	printf("%c", tree->data);
	traverseTree(tree->LChild);
	traverseTree(tree->RChild);
}
