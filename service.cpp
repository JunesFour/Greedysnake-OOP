//ʹ��sprintf����ʱ����ʹ���������Ԥ����
#define _CRT_SECURE_NO_WARNINGS
#include "service.h"
#include "view.h"
#include "data.h"
#include "conio.h"
#include <cstdlib>
#include <ctime>

void service::firstPage(view& window) {

	srand((unsigned int)time(NULL));

	for (int i = 0, j = 600; i <= 140; i += 2, j -= 5) {
		BeginBatchDraw();
		cleardevice();
		window.putImage(0, 0, &window.firstpage);
		window.setBkMode(TRANSPARENT);

		window.setTextStyle(237, 24, 35, 70, 0, "��Ӱ��������");
		window.outText(90, i, "��ӭ����̰����");

		window.setTextStyle(237, 24, 35, 50, 0, "��Ӱ��������");
		window.outText(150, j, "��ѡ����Ϸ��ͼ");

		window.setTextStyle(23, 2, 3, 30, 0, "��Ӱ��������");
		window.outText(230, j + 80, "1.��ɽ�緢");
		window.outText(230, j + 110, "2.��ҰѰ��");
		window.outText(230, j + 140, "3.�̽��");
		window.outText(230, j + 170, "4.�������");
		window.outText(230, j + 200, "5.�Ǽʴ�Խ");
		window.outText(230, j + 230, "6.��Ҷ֮ͥ");

		Sleep(22);
		EndBatchDraw();
	}
}
void service::selectMap(view& window) {
	//�������ѡ�����Ϸ��ͼ
	char ch = _getch();
	while (ch < '1' || ch > '6') {
		ch = _getch();
	}
	switch (ch) {
	case '1': window.loadImage(&window.map, "��ɽ�緢.jpg", 1200, 600); break; //��ɽ�緢 
	case '2': window.loadImage(&window.map, "��ҰѰ��.jpg", 1200, 600); break;  //��ҰѰ��
	case '3': window.loadImage(&window.map, "�̽��.jpg", 1200, 600); break; //�̽��
	case '4': window.loadImage(&window.map, "�������.png", 1200, 600); break; //�������
	case '5': window.loadImage(&window.map, "�Ǽʴ�Խ.jpg", 1200, 600); break; //�Ǽʴ�Խ
	case '6': window.loadImage(&window.map, "��Ҷ֮ͥ.jpg", 1000, 600); break; //��Ҷ֮ͥ
	}
	cleardevice();

}

void service::backGround(view& window) {
	window.putImage(0, 0, &window.map);
	window.setBkMode(TRANSPARENT);
	window.setLineStyle(RGB(130, 130, 130));
	for (int i = 0; i < 600; i += 20) {
		window.drawLine(i, 0, i, 600);
		window.drawLine(0, i, 600, i);
	}
}

void service::drawSnake(Data& data, view& window) {  //ʵ��
	//�߿����л��ɲ�ͬ����ɫ
	srand((unsigned int)time(NULL));
	//��������
	for (auto it = data.snake.cbegin(); it != data.snake.cend(); it++) {
		window.setRectangleStyle(RGB(rand() % 255 + 0, rand() % 255 + 0, rand() % 255 + 0));
		window.drawRectangle(it->x, it->y, it->x + 20, it->y + 20);
	}
}

void service::drawFood(Data& data, view& window) {
	//�ж���Ϸ��������û��ʳ��
	if (data.food.empty()) {
		std::pair<int, int> PII;
		//ѭ���жϲ�����ʳ��᲻���������غ�
		while (1) {
			srand((unsigned int)time(NULL));
			bool flag = false;
			int x = rand() % 5 + 0;
			int y = rand() % 5 + 0;
			PII.first = x * 100 + y * 20;
			PII.second = y * 100 + x * 20;
			for (auto it = data.snake.cbegin(); it != data.snake.cend(); it++)
				if (PII.first == it->x && PII.second == it->y) {
					flag = true;
					break;
				}
			if (flag == false)
				break;
		}
		data.food.emplace(PII);
	}
	//��ʳ��
	window.setRectangleStyle(RGB(255, 72, 72));
	window.drawRectangle(data.food.top().first, data.food.top().second,
		data.food.top().first + 20, data.food.top().second + 20);
}

void service::changeDir(Data& data) {
	if (GetAsyncKeyState('W') && (data.snake[0].dir != NORTH) && (data.snake[0].dir != SOUTH)) {
		data.snake[0].dir = NORTH;
	}
	if (GetAsyncKeyState('S') && (data.snake[0].dir != NORTH) && (data.snake[0].dir != SOUTH)) {
		data.snake[0].dir = SOUTH;
	}
	if (GetAsyncKeyState('A') && (data.snake[0].dir != WEST) && (data.snake[0].dir != EAST)) {
		data.snake[0].dir = WEST;
	}
	if (GetAsyncKeyState('D') && (data.snake[0].dir != WEST) && (data.snake[0].dir != EAST)) {
		data.snake[0].dir = EAST;
	}
}

void service::snakeMove(Data& data) {
	for (auto it = data.snake.end() - 1; it != data.snake.begin(); it--) {
		it->x = (it - 1)->x;
		it->y = (it - 1)->y;
		it->dir = (it - 1)->dir;
	}

	//��ͷ������Ҫ���⴦����Ϊ��ͷ���ܸı��˷���
	auto it = data.snake.begin();
	if (it->dir == NORTH) {
		it->y -= 20;
	}
	else if (it->dir == EAST) {
		it->x += 20;
	}
	else if (it->dir == SOUTH) {
		it->y += 20;
	}
	else if (it->dir == WEST) {
		it->x -= 20;
	}
}
bool service::snakeDead(Data& data) {
	//�ж���ͷ�᲻��ҧ���Լ�
	for (auto it = data.snake.cbegin() + 1; it != data.snake.cend(); it++) {
		if (data.snake[0].x == it->x && data.snake[0].y == it->y) {
			return true;
		}
	}
	//�ж���ͷ�᲻��ײǽ
	if (data.snake[0].x < 0 || data.snake[0].x >= 600 || data.snake[0].y < 0 || data.snake[0].y >= 600) {
		return true;
	}
	return false;
}

void service::snakeGrow(Data& data) {
	//�ж�ʳ�������Ƿ�����ͷ�����غ�
	if (data.snake[0].x == data.food.top().first && data.snake[0].y == data.food.top().second) {
		data.scores += 20;
		data.food.pop();
		data.snake.emplace_back();
	}
}
void service::printScores(Data& data, view& window) {
	char text[20] = "";
	sprintf(text, "�÷֣�%d", data.scores);

	window.setTextStyle(WHITE, 25, 0, "�����ѾѾ");
	window.outText(200, 10, text);

	window.outText(250, 560, "��P��ͣ");
	switch (data.speed) {
	case 100: window.outText(320, 10, "�Ѷȣ�1"); break;
	case 75: window.outText(320, 10, "�Ѷȣ�2"); break;
	case 50: window.outText(320, 10, "�Ѷȣ�3"); break;
	case 25: window.outText(320, 10, "�Ѷȣ�4"); break;
	}
}
void service::changeDiff(Data& data) {
	switch (data.scores) {
	case 100: data.speed = 75; break;
	case 400: data.speed = 50; break;
	case 600: data.speed = 25; break;
	}
}
void service::pauseGame(view& window) {
	if (GetAsyncKeyState('P') || GetAsyncKeyState('p')) {
		EndBatchDraw();
		char ch;
		window.setTextStyle(WHITE, 40, 0, "�����ѾѾ");
		window.outText(100, 200, "��Ϸ��ͣ�����ո����!");
		ch = _getch();
		while (ch != ' ') {
			ch = _getch();
		}
	}
}
void service::gameOver(Data& data, view& window) {
	char text[20] = "";
	sprintf(text, "���յ÷֣� %d", data.scores);
	window.setTextStyle(WHITE, 50, 0, "�����ѾѾ");
	window.outText(200, 200, "��Ϸ����!");
	window.outText(130, 300, text);
}