#pragma once
#include "listElem.h"
class gameObjList
{
public:
	listElem *head;
	int length;

	void add(std::string id, int x, int y,int **indexArray);
	void pop_back(listElem *&head);
	void pop_front(listElem * &head);
	bool searchList(int indexToFind);

	listElem * getPtrToElemByMapIndex(int index);

	bool empty();
	void operator --(int index);

	gameObjList();
	~gameObjList();
};

