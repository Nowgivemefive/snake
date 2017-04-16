/*
*	*制作 Give_Me_Five
*	*转载请注明出处
*/

#include<graphics.h>
#include<conio.h>
#include "snake.h"

#define LIMIT 8
#define SLEEP_TIME 200 //推荐300ms

void endGame();//游戏结束
void game();//运行游戏
void outScore(SNAKE *temp);

void paintLine() {
	setlinecolor(WHITE);
	line(640, 0, 640, 480);
}

void testGame(SNAKE *temp) {
	TCHAR s[100];
	_stprintf_s(s, _T("%hs : %d,%d"),"apple", temp->getAppleX(),temp->getAppleY());
	outtextxy(650, 20, s);
	_stprintf_s(s, _T("%hs : %d,%d"), "head", temp->getX(), temp->getY());// 高版本 VC 推荐使用 _stprintf_s 函数
	outtextxy(650, 50, s);
}

void outScore(SNAKE *temp) {
	TCHAR s[12];
	_stprintf_s(s, _T("%hs%d"), "score: ", temp->getScore());
	outtextxy(520, 430, s);
}

void endGame() {
	TCHAR s[30];
	_stprintf_s(s, _T("%hs"), "game over ! pess R to replay");        // 高版本 VC 推荐使用 _stprintf_s 函数
	outtextxy(260, 230, s);
	char temp = _getch();
	if (temp == 'r') {
		game();
	}
	else {
		closegraph();
	}
	
}

void game() {
	initgraph(640, 480);

	int x = 312; //初始X坐标
	int y = 232; //初始Y坐标
	SNAKE *pr = new SNAKE(x, y, 8, 8); //初始蛇（X,Y ,半径,长度）,不要修改半径

	//开局向右
	char c = 'd';
	char temp = 'd';
	//被吃,生成苹果
	bool isEat = true;

	while (true)
	{
		outScore(pr);
		//testGame(pr);//使用时需将窗口X设置为740
		//paintMap();

		//被吃生成新的苹果
		if (isEat) {
			pr->addApple();
		}

		//获取当前头部的X和Y
		int tmpx = pr->getX();
		int tmpy = pr->getY();

		if (_kbhit()) {
			// 获取按键
			c = _getch();
			if (c == ' ') {
				_getch();
				continue;
			}
			//防止反向
			if (temp == 'd'&&c == 'a') {
				continue;
			}
			else if (temp == 'a'&&c == 'd') {
				continue;
			}
			else if (temp == 'w'&&c == 's') {
				continue;
			}
			else if (temp == 's'&&c == 'w') {
				continue;
			}

			switch (c)
			{
			case 'a':
				if (tmpx - LIMIT <= 0) { 
					endGame(); break;
				}else if (pr->isInNode(tmpx - 16, tmpy)) {
					endGame(); break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx - 16 == pr->getAppleX())){
					pr->left(); isEat = true; break;
				}else {
					pr->rmEnd(); pr->left(); isEat = false; break;
				}
			case 'd':
				if (tmpx + LIMIT >= 640) {
					endGame(); break;
				}else if (pr->isInNode(tmpx + 16, tmpy)) {
					endGame();break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx + 16 == pr->getAppleX())) { 
					pr->right(); isEat = true; break; 
				}else {
					pr->rmEnd(); pr->right(); isEat = false; break;
				}
			case 'w':
				if (tmpy - LIMIT <= 0) {
					endGame();break;}
				else if (pr->isInNode(tmpx, tmpy - 16)) {
					endGame();break;
				}else if((tmpx == pr->getAppleX()) && (tmpy - 16 == pr->getAppleY())) { 
					pr->up(); isEat = true; break;
				}else{
					pr->rmEnd(); pr->up();  isEat = false; break;
				}
			case 's':
				if (tmpy + LIMIT >= 480) {
					endGame();break;
				}
				else if (pr->isInNode(tmpx, tmpy + 16)) {
					endGame();break;
				}
				else if((tmpx == pr->getAppleX()) && (tmpy + 16 == pr->getAppleY())) {
					pr->down(); isEat = true; break; 
				}else{
					pr->rmEnd(); pr->down();isEat = false; break;
				}
			}
			temp = c;

		}
		else {
			switch (temp) {
			case 'a':
				if (tmpx - LIMIT <= 0) {
					endGame();break;
				}else if (pr->isInNode(tmpx - 16, tmpy)) {
					endGame();break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx - 16 == pr->getAppleX())) {
					pr->left(); isEat = true; continue;
				}else {
					pr->rmEnd(); pr->left();  isEat = false; break;
				}
			case 'd':
				if (tmpx + LIMIT >= 640) {
					endGame();break;
				}else if (pr->isInNode(tmpx + 16, tmpy)) {
					endGame();break;
				}else if ((tmpy == pr->getAppleY()) && (tmpx + 16 == pr->getAppleX())) {
					pr->right(); isEat = true; continue;
				}
				else {
					pr->rmEnd(); pr->right(); isEat = false; break;
				}
			case 'w':
				if (tmpy - LIMIT <= 0) {
					endGame();break;
				}else if (pr->isInNode(tmpx, tmpy - 16)) {
					endGame();break;
				}else if ((tmpx == pr->getAppleX()) && (tmpy - 16 == pr->getAppleY())) {
					pr->up(); isEat = true; continue;
				}else {
					pr->rmEnd(); pr->up(); isEat = false; break;
				}
			case 's':
				if (tmpy + LIMIT >= 480) {
					endGame();break;
				}else if (pr->isInNode(tmpx, tmpy + 16)) {
					endGame();break;
				}else if ((tmpx == pr->getAppleX()) && (tmpy + 16 == pr->getAppleY())) {
					pr->down(); isEat = true; continue;
				}else {
					pr->rmEnd(); pr->down(); isEat = false; break;
				}
			}

		}
		
		// 延时
		Sleep(SLEEP_TIME);
	}
	

	closegraph();
}



int main(){
	game();

	return 0;
}
