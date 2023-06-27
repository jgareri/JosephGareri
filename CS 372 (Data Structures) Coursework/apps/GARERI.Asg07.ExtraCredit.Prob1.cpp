// GARERI.Asg07.ExtraCredit.Prob1.cpp
// Joseph Gareri
// jgareri@my.athens.edu
// Asg 07 Extra Credit
// Problem 1

#include <iostream>
using namespace std;

struct node
{
	int key;
	struct node* left, * right;
};

struct listNode
{
	int key;
	struct node* next;
} *front = NULL, * rear = NULL;

struct node* newNode(int item);
struct listNode* newListNode(int key);
void inOrder(struct node* root);
void descendingOrder(struct node* root);
struct node* insert(struct node* node, int key);

struct node* newNode(int item)
{
	struct node* temp = new struct node;
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;

}

struct listNode* newListNode(int key)
{
	struct listNode* temp = new struct listNode;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

void inOrder(struct node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		std::cout << root->key << "\n";
		if (front == NULL)
		{
			front = rear = newListNode(root->key);
		}
		else
		{
			rear = newListNode(root->key);
			rear->next;
		}
		inOrder(root->right);
	}
}

void descendingOrder(struct node* root)
{
	if (root != NULL)
	{
		descendingOrder(root->right);
		std::cout << root->key << "\n";
		if (rear == NULL)
		{
			rear = front = newListNode(root->key);
		}
		else
		{
			front = newListNode(root->key);
			front->next;
		}
		descendingOrder(root->left);
	}
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
	{
		return newNode(key);
	}
	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	return node;
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 30);
    insert(root, 10);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    insert(root, 90);

    inOrder(root);
	cout << endl;
	descendingOrder(root);

    return 0;

}

