#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

//���� ��ȸ 
void inorder(TreeNode* root) {
	if (root != NULL)
	{
		inorder(root->llink);
		printf("[%d] ", root->data);
		inorder(root->rlink);
	}
}
//���� ��ȸ
void preorder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		preorder(root->llink);
		preorder(root->rlink);
	}
}
//���� ��ȸ
void postorder(TreeNode* root)
{
	if (root != NULL)
	{
		postorder(root->llink);
		postorder(root->rlink);
		printf("[%d] ", root->data);
	}
}

int main()
{
    //���� �޸𸮸� �Ҵ�
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* root = n6;

	/*����Ʈ�� ����
	         15
          4 	 20
	    1    16     25
	*/
	n1->data = 1; n1->llink = NULL; n1->rlink = NULL;
	n2->data = 4; n2->llink = n1; n2->rlink = NULL;
	n3->data = 16; n3->llink = NULL; n3->rlink = NULL;
	n4->data = 25; n4->llink = NULL; n4->rlink = NULL;
	n5->data = 20; n5->llink = n3; n5->rlink = n4;
	n6->data = 15; n6->llink = n2; n6->rlink = n5;

	printf("���� ��ȸ: ");
	inorder(root);
	printf("\n");

	printf("���� ��ȸ: ");
	preorder(root);
	printf("\n");

	printf("���� ��ȸ: ");
	postorder(root);
	printf("\n");

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	return 0;
}