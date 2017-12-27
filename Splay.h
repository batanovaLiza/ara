#pragma once
struct splay;
splay* rightRotateSplay(splay* k2);
splay* leftRotateSplay(splay* k2);
splay* Splay(splay* root, int key);
splay* new_NodeSplay(int key);
splay* insertSplay(splay* root, int key );
splay* deleteNodeSplay(splay* root, int key);
splay* searchSplay(splay* root, int key);
void printSplay(splay* root);