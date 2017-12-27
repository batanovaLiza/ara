#include "Splay.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct splay
{
	int key;
	splay* left;
	splay* right;
};
	splay* rightRotateSplay(splay* k2)
	{
		splay* k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		return k1;
	};

	splay* leftRotateSplay(splay* k2)
	{
		splay* k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		return k1;
	};
	splay* Splay(splay* root, int key)
	{
		if (!root)
			return NULL;
		splay header;
		header.left = header.right = NULL;
		splay* LeftTreeMax = &header;
		splay* RightTreeMin = &header;
		while (1)
		{
			if (key < root->key)
			{
				if (!root->left)
					break;
				if (key < root->left->key)
				{
					root = rightRotateSplay(root);
					if (!root->left)
						break;
				}
				RightTreeMin->left = root;
				RightTreeMin = RightTreeMin->left;
				root = root->left;
				RightTreeMin->left = NULL;
			}
			else if (key > root->key)
			{
				if (!root->right)
					break;
				if (key > root->right->key)
				{
					root = leftRotateSplay(root);
					if (!root->right)
						break;
				}
				LeftTreeMax->right = root;
				LeftTreeMax = LeftTreeMax->right;
				root = root->right;
				LeftTreeMax->right = NULL;
			}
			else
				break;
		}
		LeftTreeMax->right = root->left;
		RightTreeMin->left = root->right;
		root->left = header.right;
		root->right = header.left;
		return root;
	};

	splay* new_NodeSplay(int key)
	{
		splay* p_node = new splay;
		if (!p_node)
		{
			fprintf(stderr, "Out of memory!\n");
			exit(1);
		}
		p_node->key = key;
		p_node->left = p_node->right = NULL;
		return p_node;
	};

	splay* insertSplay(splay* root, int key)
	{
		static splay* p_node = NULL;
		if (!p_node)
			p_node = new_NodeSplay(key);
		else
			p_node->key = key;
		if (!root)
		{
			root = p_node;
			p_node = NULL;
			return root;
		}
		root = Splay(root, key);
		if (key < root->key)
		{
			p_node->left = root->left;
			p_node->right = root;
			root->left = NULL;
			root = p_node;
		}
		else if (key > root->key)
		{
			p_node->right = root->right;
			p_node->left = root;
			root->right = NULL;
			root = p_node;
		}
		else
			return root;
		p_node = NULL;
		return root;
	};

	splay* deleteNodeSplay(splay* root, int key)
	{
		splay* temp;
		if (!root)
			return NULL;
		root = Splay(root, key);
		if (key != root->key)
			return root;
		else
		{
			if (!root->left)
			{
				temp = root;
				root = root->right;
			}
			else
			{
				temp = root;
				root = Splay(root->left, key);
				root->right = temp->right;
			}
			free(temp);
			return root;
		}
	};

	splay* searchSplay(splay* root, int key)
	{
		if (root == NULL || root->key == key)
			return Splay(root, key);

		if (root->key < key)
			return searchSplay(root->right, key);

		return searchSplay(root->left, key);
	};

	void printSplay(splay* root)
	{
		if (root)
		{
			printSplay(root->left);
			cout << "key: " << root->key;
			if (root->left)
				cout << " | left child: " << root->left->key;
			if (root->right)
				cout << " | right child: " << root->right->key;
			cout << "\n";
			printSplay(root->right);
		}
	};

