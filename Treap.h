#pragma once
struct TreapNode;
TreapNode *rightRotateTreap(TreapNode *y);
TreapNode *leftRotateTreap(TreapNode *y);
TreapNode* newNodeTreap(int key);
TreapNode* searchTreap(TreapNode* root, int key);
TreapNode* insertTreap(TreapNode* root, int key);
TreapNode* deleteNodeTreap(TreapNode* root, int key);
void printTreap(TreapNode* root);
