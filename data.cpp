#include "data.h"
#include <cstdlib>
#include <ctime>
#include <graphics.h>

Data::Data() {
	//��ʼ���ߣ���������
	struct node* temp;
	temp = new struct node;
	temp->x = 80;
	temp->y = 400;
	temp->dir = EAST;
	snake.emplace_back(*temp);
	temp->x -= 20;
	snake.emplace_back(*temp);
	temp->x -= 20;
	snake.emplace_back(*temp);
	delete temp;

	//��ʼ��ʳ��
	srand((unsigned int)time(NULL));
	bool flag1 = false;
	int x = rand() % 5 + 0;
	int y = rand() % 5 + 0;
	std::pair<int, int> PII;
	PII.first = x * 100 + y * 20;
	PII.second = y * 100 + x * 20;
	food.emplace(PII);

	this->speed = 100;
	this->scores = 0;
}