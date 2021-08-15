#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

//����� ������ ���ϴ� �Լ�
int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->llink) 
		          + get_node_count(node->rlink);
	return count;
}
//�ܸ� ����� ������ ���ϴ� �Լ� 
int get_leaf_count(TreeNode* node) {
	int count = 0;

	if (node != NULL)
	{
		if (node->llink == NULL && node->rlink == NULL)  //�ܸ� ����� ����
			return 1;
		else
			count = get_leaf_count(node->llink) 
			      + get_leaf_count(node->rlink);
	}
	return count;
}
//Ʈ���� ���̸� ���ϴ� �Լ�
int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->llink), 
			             get_height(node->rlink));
	return height;
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
	TreeNode* root;

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
	root = n6;

	printf("����� ����: %d\n", get_node_count(root));
	printf("�ܸ� ����� ����: %d\n", get_leaf_count(root));
	printf("Ʈ���� ����: %d\n", get_height(root));

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	return 0;
}