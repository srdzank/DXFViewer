// generated by classgen.pl

#ifndef SIMPLELIST_H
#define SIMPLELIST_H

//#include <windows.h>

template <class T> class SimpleListNode {

public:
	T &get() { return object; };
	void set(T &object) { this->object = object; };

	SimpleListNode<T> *getNext() { return nextNode; };
	void setNext(SimpleListNode<T> *nextNode) { this->nextNode = nextNode; };

private:
	T object;
	SimpleListNode<T> *nextNode;
};

template <class T> class SimpleList {

public:
	// Constructor
	SimpleList() {
		headNode = new SimpleListNode<T>;
		headNode->setNext(NULL);

		currentNode = NULL;
		size = 0;
	};

	// Destructor
	~SimpleList() {

		SimpleListNode<T> *pointerToDelete, *pointer = headNode;

		while (pointer != NULL) {
			pointerToDelete = pointer;
			pointer = pointer->getNext();
			delete pointerToDelete;
		}
	};

	T &get() { 

		if (currentNode == NULL) 
			start();

		return currentNode->get(); 
	};

	void add(T &addObject) {

		SimpleListNode<T> *newNode = new SimpleListNode<T>;

		newNode->set(addObject);

		newNode->setNext(headNode->getNext());
		headNode->setNext(newNode);

		size++;
	};
		
	void remove() {

		lastCurrentNode->setNext(currentNode->getNext());

		delete currentNode;

		currentNode = lastCurrentNode;

		size--;
	};

	void start() {
		lastCurrentNode = headNode;
		currentNode = headNode;
	};

	bool next() {

		// If the currentNode now points at nothing, we've reached the end
		if (currentNode == NULL)
			return false;

		// Update the last node and current node
		lastCurrentNode = currentNode;
		currentNode = currentNode->getNext();

		// If currentNode points at nothing or there is nothing added, we can immediately return false
		if (currentNode == NULL || size == 0) 
			return false;
		else
			return true;
	};

	int getSize() { return size; };

private:
	int size;
	SimpleListNode<T> *headNode;
	SimpleListNode<T> *currentNode, *lastCurrentNode;
};

#endif
