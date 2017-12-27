#include <iostream>
#include <stdlib.h>
#include "Treap.h"
using namespace std;

struct TreapNode
{
	int key;
	int priority;
	TreapNode *left;
	TreapNode *right;
};


TreapNode *rightRotateTreap(TreapNode *y)
{
	TreapNode *x = y->left;
	TreapNode *T2 = x->right;
	x->right = y;
	y->left = T2;

	return x;
}

TreapNode *leftRotateTreap(TreapNode *x)
{
	TreapNode *y = x->right, *T2 = y->left;
	y->left = x;
	x->right = T2;
	return y;
}

TreapNode* newNodeTreap(int key)
{
	TreapNode* temp = new TreapNode;
	temp->key = key;
	temp->priority = rand() % 100;
	temp->left = temp->right = NULL;
	return temp;
}

TreapNode* searchTreap(TreapNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;

	if (root->key < key)
		return searchTreap(root->right, key);

	return searchTreap(root->left, key);
}

TreapNode* insertTreap(TreapNode* root, int key)
{
	if (!root)
		return newNodeTreap(key);

	if (key <= root->key)
	{
		root->left = insertTreap(root->left, key);

		if (root->left->priority > root->priority)
			root = rightRotateTreap(root);
	}
	else
	{
		root->right = insertTreap(root->right, key);

		if (root->right->priority > root->priority)
			root = leftRotateTreap(root);
	}
	return root;
}

TreapNode* deleteNodeTreap(TreapNode* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNodeTreap(root->left, key);
	else if (key > root->key)
		root->right = deleteNodeTreap(root->right, key);

	else if (root->left == NULL)
	{
		TreapNode *temp = root->right;
		delete(root);
		root = temp;
	}
	else if (root->right == NULL)
	{
		TreapNode *temp = root->left;
		delete(root);
		root = temp;
	}

	else if (root->left->priority < root->right->priority)
	{
		root = leftRotateTreap(root);
		root->left = deleteNodeTreap(root->left, key);
	}
	else
	{
		root = rightRotateTreap(root);
		root->right = deleteNodeTreap(root->right, key);
	}

	return root;
}

void printTreap(TreapNode* root)
{
	if (root)
	{
		printTreap(root->left);
		if (root->left)
			std::cout << " | left child: " << root->left->key;
		if (root->right)
			std::cout << " | right child: " << root->right->key;
		std::cout << std::endl;
		printTreap(root->right);
	}
}


