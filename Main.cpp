#include "service.h"
#include "data.h"

int main() {
FLAG:
	view window(600, 600);
	service game;
	Data data;
	game.firstPage(window);
	game.selectMap(window);
	game.backGround(window);

	game.drawSnake(data, window);
	game.drawFood(data, window);

	while (1) {
		BeginBatchDraw();  //������˸����ǰ���ڴ��л���ͼ
		game.pauseGame(window);
		cleardevice();
		game.pauseGame(window);
		game.backGround(window);  //��ӡ����
		game.pauseGame(window);
		game.drawFood(data, window);  //����ʳ��
		game.pauseGame(window);
		game.snakeGrow(data);  //�߱䳤
		game.pauseGame(window);
		game.printScores(data, window);   //ʵʱ��ӡ����
		game.pauseGame(window);
		game.changeDir(data);   //�ı䷽��
		game.pauseGame(window);
		game.snakeMove(data);   //�ߵ��ƶ�
		game.pauseGame(window);
		game.drawSnake(data, window); //��ӡ��
		game.pauseGame(window);
		if (game.snakeDead(data)) {
			EndBatchDraw();
			game.gameOver(data, window);
			if (MessageBox(GetHWnd(), "�����������Ƿ������Ϸ", "��ʾ", MB_YESNO) == IDYES) {
				goto FLAG;
			}
			else {
				break;
			}
		}
		game.pauseGame(window);
		game.changeDiff(data);  //�ﵽһ���ķ����ı��Ѷ�
		game.pauseGame(window);
		Sleep(data.speed);    //��������
		game.pauseGame(window);
		EndBatchDraw();  //������ڴ��л��õ�ͼ
	}
	return 0;
}