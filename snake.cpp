#include "snake.h"

SNAKE::SNAKE(int x, int y, int r, int length) {
	sk = new SnakeNode();
	setlinecolor(LINE_COLOR);
	setfillcolor(FULL_COLOR);
	for (int i = 0; i < length; i++) {
		sk->addNode(x - i * 2 * r, y);
		fillcircle(x - i * 2 * r, y, r);
	}
	this->r = r;
}


void SNAKE::right() {
	setlinecolor(LINE_COLOR);
	setfillcolor(FULL_COLOR);
	sk->addHeadNode((2 * r + sk->getHead()->x), sk->getHead()->y);
	fillcircle(sk->getHead()->x, sk->getHead()->y, this->r);
	return;
}

void SNAKE::left() {
	setlinecolor(LINE_COLOR);
	setfillcolor(FULL_COLOR);
	sk->addHeadNode(sk->getHead()->x-2*r, sk->getHead()->y);
	fillcircle(sk->getHead()->x, sk->getHead()->y, this->r);
	return;
}


void SNAKE::up() {
	setlinecolor(LINE_COLOR);
	setfillcolor(FULL_COLOR);
	sk->addHeadNode(sk->getHead()->x, sk->getHead()->y -2*r);
	fillcircle(sk->getHead()->x, sk->getHead()->y, this->r);
	return;
}

void SNAKE::down() {
	setlinecolor(LINE_COLOR);
	setfillcolor(FULL_COLOR);
	sk->addHeadNode(sk->getHead()->x, sk->getHead()->y + 2 * r);
	fillcircle(sk->getHead()->x, sk->getHead()->y, this->r);
	return;
}

void SNAKE::rmEnd() {
	setlinecolor(BLACK);
	setfillcolor(BLACK);
	this->temp_x = sk->getEnd()->x;
	this->temp_y = sk->getEnd()->y;
	fillcircle(this->temp_x, this->temp_y, this->r);
	sk->rmNode();
}

int SNAKE::getR() {
	return this->r;
}
int SNAKE::getX() {
	return sk->getHead()->x;
}
int SNAKE::getY() {
	return sk->getHead()->y;
}

void SNAKE::addApple() {
	while (1) {
		this->Apple_x = 8 + 16 * (rand() % 39);
		this->Apple_y = 8 + 16 * (rand() % 29);
		//苹果不在蛇身上 且 不在蛇的尾部
		if (this->Apple_x == this->temp_x && this->Apple_y == this->temp_y) {
			continue;
		}
		if (!sk->inNode(this->Apple_x, this->Apple_y)) {
			break;
		}
	}
	setlinecolor(RED);
	setfillcolor(RED);
	fillcircle(this->Apple_x, this->Apple_y, this->r);
	this->score++;
	return;

}

int SNAKE::getScore() {
	if (this->score == 0) {
		return 0;
	}else
		return score - 1;
}




int SNAKE::getAppleX() {
	return this->Apple_x;
}
int SNAKE::getAppleY() {
	return this->Apple_y;
}

bool SNAKE::isInNode(int x, int y) {
	return sk->headInNode(x,y);
}