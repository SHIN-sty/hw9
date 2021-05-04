/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
	struct node *p;
} Node;

// data�� ��Ʈ ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
Node* makeRootNode(int data, Node* leftNode, Node* rightNode){
	Node* root = (Node*)malloc(sizeof(Node));
	root -> key = data;
	root -> left = leftNode;
	root -> right = rightNode;
	return root;
}
int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");
        
		printf("����: ���¾�\n");
		printf("�й�: 2017038096\n");
		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->right, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->right);
			break;
		case 'p': case 'P':
			preorderTraversal(head->right);
			break;
		case 't': case 'T':
			postorderTraversal(head->right);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->right = NULL;	/* root */
	(*h)->left = NULL;
	(*h)->key = -9999;
	return 1;
}

// �̿� Ž�� Ʈ���� ���� ���� ��ȸ ����

void inorderTraversal(Node* ptr)
{
 if(ptr){
	inorderTraversal(ptr -> left);
	printf("[%d]", ptr -> key);
	inorderTraversal(ptr -> right);
 }
}

// �̿� Ž�� Ʈ���� ���� ���� ��ȸ ����

void preorderTraversal(Node* ptr)
{
 if(ptr){
	 printf("[%d]", ptr->key);
	 preorderTraversal(ptr -> left);
	 preorderTraversal(ptr -> right);
 }
}

// �̿� Ž�� Ʈ���� ���� ���� ��ȸ ����

void postorderTraversal(Node* ptr)
{
 if(ptr){
	postorderTraversal(ptr -> left);
	postorderTraversal(ptr -> right);
	printf("[%d]", ptr -> key);
 }
}


int insert(Node* head, int key)
{
 Node* n = (Node*)malloc(sizeof(Node));
    Node* temp = head; 

    n->key = key;
    n->p = NULL;
    n->left = NULL;
    n->right= NULL;

    if( temp == NULL)
    {
        head = n;

        
    }

    while( temp != NULL)
    {
        n->p = temp;
       
        if( temp->key > key)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

   
    if( (n->p)->key > key)
    {
        (n->p)->left = n;
    }
    else if(n->p->key==key){

    free(n);

    printf("Ű���� (%d)�� ��尡 �̹� �����մϴ�.", key);

    return -1;

    }

    else{

    (n->p)->right = n;

    }

    return key;
}

int deleteLeafNode(Node* head, int key)
{
     Node * node= searchRecursive(head, key);

     if (node==NULL){
         return 0; // fail
         }

     if (node->left==NULL && node->right==NULL){ // leaf
     if(node->key<node->p->key){
     node->p->left=NULL;
     }
     else{
     node->p->right=NULL;
     }
     free(node);
     printf("Ű���� (%d)�� ��带 �����մϴ�. [��������]\n", key);
     return 1; // success
     }
     else{ // non-leaf
    printf("Ű���� (%d)�� ���� leaf ��尡 �ƴմϴ�. [��������]\n", key);
    return 0; // fail
    }

}

Node* searchRecursive(Node* ptr, int key)
{
	/* Ű���� key�� ��忡 ���� �����͸� ��ȯ��.
	�׷� ��尡 ���� ���� NULL�� ��ȯ */
 if(ptr == NULL){
        printf("Ű���� (%d)�� ���� �����ϴ�. [�˻�����]\n", key);
        return NULL;
    } else if (key == ptr->key){
        printf("Ű���� (%d)�� ��带 ��ȯ�մϴ�. [�˻�����]\n", key);
        return ptr;
    } else if (key < ptr->key){
        return searchRecursive(ptr->left, key); // key ���� ã�� Ű���� ptr���� ������ ����
    } else {
        return searchRecursive(ptr->right, key); // �׷��� ������ ������
    }
}

Node* searchIterative(Node* head, int key)
{
	/* Ű���� key�� ��忡 ���� �����͸� ��ȯ��.
	�׷� ��尡 ���� ���� NULL�� ��ȯ */
while (head != NULL) {
if (key == head->key) {
return head;
}
else if (key < head->key) {
head = head->left;
}
else
head = head->right;
}
return NULL;
}


int freeBST(Node* head)
{
 if(head != NULL){
	freeBST(head -> left);
	freeBST(head -> right);
	free(head);
 }

}





