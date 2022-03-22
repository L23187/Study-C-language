#include <stdio.h>
#include <stdlib.h>
typedef char Datatype;
/*二叉树*/
typedef struct Node {
	Datatype data;
	struct Node *LChild;
	struct Node *RChild;
} BiTNode, *BiTree;
 
void createBiTree(BiTree *tree);
void traverseTree(BiTree tree); 
int main(int argc, char *argv[]) {
	BiTree tree;
	printf("按先序遍历序列建立二叉树:\n");
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
		//生成一个新结点
		*tree = (BiTree)malloc(sizeof(BiTNode));
		(*tree)->data = ch;
		//生成左子树
		createBiTree(&((*tree)->LChild));
		//生成右子树
		createBiTree(&((*tree)->RChild));
	}
}
/**遍历树的结点*/
void traverseTree(BiTree tree) {
	int i;
	if(tree == NULL) {
		return;
	}
	printf("%c", tree->data);
	traverseTree(tree->LChild);
	traverseTree(tree->RChild);
}
