/*
*	双向链表储存蛇身坐标
*/
#pragma once
#ifndef NODE_H
#define NODE_H


struct Node {
	int x;
	int y;
	struct Node *next;
	struct Node *prev;
};


class SnakeNode {
public:
	SnakeNode();
	void addNode(int x, int y); //尾部增加结点
	void addHeadNode(int x, int y); //在头部在增加结点
	void rmNode(); //删除尾部结点
	Node* getEnd(); //获取尾部结点
	void showAll(); //测试用
	Node* getHead(); //获取头部结点
	bool inNode(int x, int y); //苹果坐标是否在身体 
	bool headInNode(int x, int y); //头部撞到身体
private:
	Node *head, *end;
};



#endif // !NODE_H
