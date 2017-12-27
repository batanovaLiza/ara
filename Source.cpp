#include <iostream>
#include <fstream>
#include <chrono>
#include <stdlib.h>
#include "Treap.h"
#include <set>
#include <time.h>
#include "Splay.h"
#include <algorithm>
using namespace std;

bool binarySearch(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = left + (right - left) / 2;

		if (key < arr[midd])      
			right = midd - 1;     
		else if (key > arr[midd])  
			left = midd + 1;	  
		else                     
			return true;          

		if (left > right)          
			return false ;
	}
}

void writeInFileTime(char* structName, char* typeOfOperation, std::chrono::duration<double> elapsed_seconds, int size) {
	//fstream fs;
	//fs.open("C:/my/time.txt", ios::app);
	//if (fs.is_open()) {
	//	fs << structName << "," << typeOfOperation << "," << elapsed_seconds.count() << "," << size << '\n';
	//	fs.close();
	//}
	//else {
	//	cout << "error" << endl;
	//}
}


int main()
{
	char* treapTree = "Treap";
	char* splayTree = "Splay";
	char* rbTree = "rbTree";
	char* binary = "binary";
	char* insert = "insert";
	char* deleteElem = "delete";
	char* search = "search";

	int size = 100000;
	srand(time(NULL));
	int *randomArray = new int [size];
	for (int i = 0; i < size; i++) {
		randomArray[i] = rand() % 10000;
	}

	// TREAP
	cout << "TREAP" << endl;
	TreapNode *rootTreap = NULL;
	cout << "insert" << endl;
	for (int i = 0; i < size; i++)
		rootTreap = insertTreap(rootTreap, randomArray[i]);
	auto t1 = std::chrono::high_resolution_clock::now();
	rootTreap = insertTreap(rootTreap, 12300);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(treapTree, insert, elapsed_seconds, size);
	//printTreap(rootTreap);

	cout << "Delete" << endl;
	t1 = std::chrono::high_resolution_clock::now();
	rootTreap = deleteNodeTreap(rootTreap, 17300);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(treapTree, deleteElem, elapsed_seconds, size);

	cout << "search" << endl;
	t1 = std::chrono::high_resolution_clock::now();
	searchTreap(rootTreap, 1200);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(treapTree, search, elapsed_seconds, size);

	// SPLAY ////////////////////////////////////////////////////////////////////////
	cout << "\nSLAY" << endl;
	 splay *rootSplay = NULL;

	for (int i = 0; i < size; i++) 
		randomArray[i] = rand() % size;

	cout << "insert" << endl;
	for (int i = 0; i < size; i++)
		rootSplay = insertSplay(rootSplay, randomArray[i]);
	t1 = std::chrono::high_resolution_clock::now();
	rootSplay = insertSplay(rootSplay, 3343);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(splayTree, insert, elapsed_seconds, size);

	cout << "Delete" << endl;
	t1 = std::chrono::high_resolution_clock::now();
	rootSplay = deleteNodeSplay(rootSplay, 15312);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(splayTree, deleteElem, elapsed_seconds, size);

	cout << "search" << endl;
	t1 = std::chrono::high_resolution_clock::now();
	searchSplay(rootSplay, 36653);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(splayTree, search, elapsed_seconds, size);

	//RB TREE/////////////////////////////////////////////////////////////////////////////////

	cout << "\nRB TREE" << endl;
	std::set<int> intSet;
	for (int i = 0; i < size; i++) {
		randomArray[i] = rand() % size;
	}

	cout << "insert" << endl;
	for (int i = 0; i < size; i++)
		intSet.insert(randomArray[i]);
	t1 = std::chrono::high_resolution_clock::now();
	intSet.insert(55674);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(rbTree, insert, elapsed_seconds, size);

	cout << "Delete" << endl;
	t1 = std::chrono::high_resolution_clock::now();
	intSet.erase(1142);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(rbTree, deleteElem, elapsed_seconds, size);

	cout << "search" << endl;
	t1 = std::chrono::high_resolution_clock::now();
	intSet.find(567334);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(rbTree, search, elapsed_seconds, size);


	 //BINARY/////////////////////////////////////////////////////////////////////////////////////////
	cout << "\nBINARY" << endl;


	for (int i = 0; i < size; i++) {
		randomArray[i]= rand() % size;
	}

	cout << "search" << endl;
	std::sort(randomArray, randomArray + size);
	t1 = std::chrono::high_resolution_clock::now();
	binarySearch(randomArray, 0, size, 25142);
	t2 = std::chrono::high_resolution_clock::now();
	elapsed_seconds = t2 - t1;
	cout << elapsed_seconds.count() << endl;
	writeInFileTime(binary, search, elapsed_seconds, size);

	delete[] randomArray;
	system("pause");

	return 0;


	

}




