#pragma once
#include<stdio.h>
#define SIZE 10
#define max(a,b)  (((a) > (b)) ? (a) : (b))

typedef struct treeNode {
	treeNode* parent;
	int data;
	treeNode* child[SIZE] = { NULL };
}treeNode;

int isRoot(treeNode* Node);	// root�� 1, �ƴϸ� 0
int depth(treeNode* Node);	// depth ��ȯ
int isExternal(treeNode* Node);	// External �̸� 1, �ƴϸ� 0
int height(treeNode* Node);	// height ��ȯ

int isRoot(treeNode* Node) {
	if (Node->parent == NULL) return 1;	// �θ� ��尡 ������ Root -> True

	else return 0;	// �ƴϸ� False
}

int depth(treeNode* Node) {
	if (isRoot(Node)) return 0;

	else return 1 + depth(Node->parent);
}

int isExternal(treeNode* Node) {
	int index = 0;
	while (Node->child[index] != NULL) index++;

	if (index == SIZE) return 1;
	else return 0;
}

int height(treeNode* Node) {
	if (isExternal(Node)) return 0;

	else {
		int h = 0; int index = 0;
		while (Node->child[index] != NULL) {
			h = max(h, height(Node->child[index]));
			index++;

			return 1 + h;
		}
	}
}

