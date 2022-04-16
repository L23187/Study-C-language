#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode {
	int data;
	struct treeNode* left;
	struct treeNode* right;
}NODE,* LPNODE;

LPNODE insert(int  root, int start, int end);
void LayerOrder(LPNODE tree);

LPNODE Tree = NULL;

int n;
int a[50], b[50];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	Tree = insert(n - 1, 0, n - 1);
	LayerOrder(Tree);
	return 0;
}
LPNODE insert(int  root, int start, int end) {
	LPNODE tree;
	if (start > end)
		return NULL;
	int i;
	for (i = start; a[root] != b[i]; i++);
	tree = (LPNODE)malloc(sizeof(NODE));
	tree->data = a[root];
	tree->left = insert(root - (end - i) - 1, start, i - 1);
	tree->right = insert(root - 1, i + 1, end);
	return tree;
}
void LayerOrder(LPNODE tree) {
	if (tree == NULL) {
		return;
	}
	int flag = 0;
	LPNODE queue[50];
	int start = -1;
	int end = 0;
	queue[end] = tree;
	while (start != end) {
		start++;
		if (flag) {
			printf(" ");
		}
		printf("%d", queue[start]->data);
		flag++;
		if (queue[start]->left != NULL) {
			end++;
			queue[end] = queue[start]->left;
		}
		if (queue[start]->right != NULL) {
			end++;
			queue[end] = queue[start]->right;
		}
	}
}