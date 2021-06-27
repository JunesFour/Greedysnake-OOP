#pragma once
#include <vector>
#include <stack>
//四个方向
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

//数据类，处理游戏中的所有数据
class Data {
	friend class service;
public:
	//蛇的横纵坐标、运动方向
	struct node {
		int x, y;
		int dir;
	};
	//储存蛇
	std::vector<struct node> snake;
	//储存食物
	std::stack<std::pair<int, int>> food;
	//蛇的速度
	int speed;
	//分数
	int scores;

	Data();
	~Data() { }
};