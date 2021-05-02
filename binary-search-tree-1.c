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

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

Node* makeRootNode(int key, Node* leftNode, Node* rightNode){
	Node* root = (Node*)malloc(sizeof(Node));
	root -> key = key;
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
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)
{
 if(ptr){
	inorderTraversal(ptr -> left);
	printf("%c", ptr -> key);
	inorderTraversal(ptr -> right);
 }
}

void preorderTraversal(Node* ptr)
{
 if(ptr){
	 printf("%c", ptr->key);
	 preorderTraversal(ptr -> left);
	 preorderTraversal(ptr -> right);
 }
}

void postorderTraversal(Node* ptr)
{
 if(ptr){
	postorderTraversal(ptr -> left);
	postorderTraversal(ptr -> right);
	printf("%c", ptr -> key);
 }
}


int insert(Node* head, int key)
{
  if(head->key)
  else if(head->key){
	  if(head->left == NULL) head->left;
	  else insert(head -> left, key);

  }
  else{
	  if(head->right == NULL) head -> right;
	  else insert(head -> right, key);
  }
}

int deleteLeafNode(Node* head, int key)
{
  Node* parent, *p;
  
  if((p -> left == NULL) && (p -> right == NULL)){
	  if(parent != NULL){
		  if(parent -> left == p) parent -> left = NULL;
		  else parent -> right = NULL;
	  }
	  else head = NULL;
  }
}

Node* searchRecursive(Node* ptr, int key)
{
 if(ptr == NULL){
        printf("Ű���� (%d)�� ���� �����ϴ�. [�˻�����]\n", key);
        return NULL;
    } else if (key == ptr->key){
        printf("Ű���� (%d)�� ��带 ��ȯ�մϴ�. [�˻�����]\n", key);
        return ptr;
    } else if (key < ptr->key){
        searchRecursive(ptr->left, key);
    } else {
        searchRecursive(ptr->right, key);
    }
}

Node* searchIterative(Node* head, int key)
{
 while(head != NULL){
	 if(key == head->key) return head;
	 else if(key < head->key) head = node -> left;
	 else head = node->right;
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





