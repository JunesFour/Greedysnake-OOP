#pragma once
#include "view.h"
#include "data.h"

//用来交互数据类和图形类
class service {
public:
	void firstPage(view& window);     //打印封面
	void selectMap(view& window);     //选择地图
	void backGround(view& window);    //打印背景
	void drawSnake(Data& data, view& window);   //画蛇
	void drawFood(Data& data, view& window);    //画食物
	void changeDir(Data& data);    //改变蛇的方向
	void snakeMove(Data& data);    //蛇的移动
	bool snakeDead(Data& data);    //判断蛇死亡
	void pauseGame(view& window);    //游戏暂停
	void snakeGrow(Data& data);   //蛇变长
	void printScores(Data& data, view& window);   //打印分数
	void gameOver(Data& data, view& window);   //游戏结束
	void changeDiff(Data& data);    //改变游戏难度
};