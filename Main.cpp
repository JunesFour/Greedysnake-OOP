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
		BeginBatchDraw();  //消除闪烁，提前在内存中画好图
		game.pauseGame(window);
		cleardevice();
		game.pauseGame(window);
		game.backGround(window);  //打印背景
		game.pauseGame(window);
		game.drawFood(data, window);  //设置食物
		game.pauseGame(window);
		game.snakeGrow(data);  //蛇变长
		game.pauseGame(window);
		game.printScores(data, window);   //实时打印分数
		game.pauseGame(window);
		game.changeDir(data);   //改变方向
		game.pauseGame(window);
		game.snakeMove(data);   //蛇的移动
		game.pauseGame(window);
		game.drawSnake(data, window); //打印蛇
		game.pauseGame(window);
		if (game.snakeDead(data)) {
			EndBatchDraw();
			game.gameOver(data, window);
			if (MessageBox(GetHWnd(), "您已阵亡，是否继续游戏", "提示", MB_YESNO) == IDYES) {
				goto FLAG;
			}
			else {
				break;
			}
		}
		game.pauseGame(window);
		game.changeDiff(data);  //达到一定的分数改变难度
		game.pauseGame(window);
		Sleep(data.speed);    //控制闪屏
		game.pauseGame(window);
		EndBatchDraw();  //输出在内存中画好的图
	}
	return 0;
}