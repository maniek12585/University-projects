#include "gameObjList.h"

void gameObjList::add(std::string id, int x, int y, int **indexArray)
{
	if (!this->searchList(indexArray[y][x]))
	{
		listElem *newElem = new listElem;
		newElem->setGameObjID(id);
		newElem->setXPos(x);
		newElem->setYPos(y);
		newElem->setIdxInArray(indexArray[y][x]);
		newElem->setNextPtr(nullptr);

		listElem *tmp = this->head;
		if (tmp == nullptr)
		{
			this->head = newElem;
		}
		else
		{
			while (tmp->getNextPtr())
			{
				tmp = tmp->getNextPtr();
			}
			tmp->setNextPtr(newElem);
			newElem->setNextPtr(nullptr);
		}
		this->length++;
	}
	else
	{
		std::cout << "Cannot add obj on the same place as existing one" << std::endl;
	}
}

void gameObjList::pop_front(listElem *&head)
{
	listElem *tmp;
	tmp = this->head;
	if (tmp)
	{
		this->head = tmp->getNextPtr();
		delete tmp;
	}
}

void gameObjList::pop_back(listElem *&head)
{
	listElem *tmp = this->head;
	if (tmp)
	{
		if (tmp->getNextPtr())
		{
			while (tmp->getNextPtr()->getNextPtr())
			{
				tmp = tmp->getNextPtr();
			}
			delete tmp->getNextPtr();
			tmp->setNextPtr(nullptr);

		}
		else
		{
			delete tmp;
			this->head = nullptr;
		}
	}
	this->length--;
}

bool gameObjList::searchList(int indexToFind)
{
	if (this->head != nullptr)
	{
		listElem *tmp = this->head;
		while (tmp)
		{
			if (tmp->getIdxInArray() == indexToFind)
			{
				return true;
			}
			tmp = tmp->getNextPtr();
		}
	}
		return false;
}

listElem * gameObjList::getPtrToElemByMapIndex(int index)
{
	listElem *tmp = this->head;
	while (tmp->getIdxInArray() != index)
	{
		tmp = tmp->getNextPtr();
	}
	return tmp;
}

bool gameObjList::empty()
{
	if (this->head == nullptr)
	{
		return true;
	}
	return false;
}

void gameObjList::operator--(int index)
{
	listElem *tmp;
	listElem *elemToDelete = this->getPtrToElemByMapIndex(index);

	if (this->head == elemToDelete)
	{
		this->pop_front(this->head);
	}
	else
	{
		tmp = this->head;
		while (tmp->getNextPtr() != elemToDelete)
		{
			tmp = tmp->getNextPtr();
		}
		
		tmp->setNextPtr(elemToDelete->getNextPtr()); 
		delete elemToDelete;
	}
	length--;

}

gameObjList::gameObjList()
{
	this->head = nullptr;
	length = 0;
}

gameObjList::~gameObjList()
{
	listElem *tmp = this->head;
	while (tmp)
	{
		this->pop_back(tmp);
	}
	delete this->head;
	this->head = nullptr;
}

