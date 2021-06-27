#pragma once
#include "view.h"
#include "data.h"

//���������������ͼ����
class service {
public:
	void firstPage(view& window);     //��ӡ����
	void selectMap(view& window);     //ѡ���ͼ
	void backGround(view& window);    //��ӡ����
	void drawSnake(Data& data, view& window);   //����
	void drawFood(Data& data, view& window);    //��ʳ��
	void changeDir(Data& data);    //�ı��ߵķ���
	void snakeMove(Data& data);    //�ߵ��ƶ�
	bool snakeDead(Data& data);    //�ж�������
	void pauseGame(view& window);    //��Ϸ��ͣ
	void snakeGrow(Data& data);   //�߱䳤
	void printScores(Data& data, view& window);   //��ӡ����
	void gameOver(Data& data, view& window);   //��Ϸ����
	void changeDiff(Data& data);    //�ı���Ϸ�Ѷ�
};