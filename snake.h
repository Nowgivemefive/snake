#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#define LINE_COLOR BLACK
#define FULL_COLOR GREEN

#include<graphics.h>
#include "snakenode.h"

class SNAKE {
public:
	SNAKE(int x, int y, int r, int length); //初始蛇

	void right(); //上下左右
	void left();
	void up();
	void down();
	void rmEnd(); //移除尾部

	int getR(); //获取半径
	int getX(); //获取头部横坐标
	int getY(); //获取头部纵坐标
	int getScore(); //获取分数

	void addApple(); //增加苹果
	int getAppleX(); //苹果X
	int getAppleY(); //苹果Y

	bool isInNode(int x, int y);//判断撞到身体
	

private:
	SnakeNode *sk;

	int r; //半径
	int Apple_x;//apple x
	int Apple_y;// apple y
	int temp_x; //上次消失的尾部X和Y
	int temp_y; 

	int score = 0; //分数
};

#endif //SNAKE_H
