#include "snakenode.h"
#include <iostream>

using namespace std;

SnakeNode::SnakeNode(){
}

void SnakeNode::addNode(int x, int y) {
	Node *pr = new Node;
	if (head != NULL) {
		pr->prev = end;
		end->next = pr;
		pr->x = x;
		pr->y = y;
		pr->next = NULL;
		end = pr;
	}
	else {
		pr->x = x;
		pr->y = y;
		pr->prev = NULL;
		pr->next = end;
		head = end = pr;
	}
	return;
}

void SnakeNode::addHeadNode(int x, int y) {
	Node *pr = new Node; 
	pr->prev = NULL;
	pr->x = x;
	pr->y = y;
	pr->next = head;
	head->prev = pr;
	head = pr;
}
	
	

void SnakeNode::rmNode() {
	Node *p = end;
	end->prev->next = NULL;
	end = end->prev;
	return;
}
Node* SnakeNode::getEnd() {
	return this->end;
}



void SnakeNode::showAll() {
	Node *pr = head;
	while (	pr!= NULL) {
		cout << "x " << pr->x << " " << "y " << pr->y << "\n";
		pr = pr->next;
	}
}

Node* SnakeNode::getHead() {
	return this->head;
}

bool SnakeNode::inNode(int x, int y) {
	Node *pr = head;
	while (pr!= NULL) {
		if (x == pr->x && y == pr->y) {
			return true;
		}
		pr = pr->next;
	}
	return false;
}

bool SnakeNode::headInNode(int x, int y) {
	Node *pr = head->next;
	while (pr->next != NULL) {
		if (x == pr->x && y == pr->y) {
			return true;//false
		}
		pr = pr->next;
	}
	return false; //false
}
