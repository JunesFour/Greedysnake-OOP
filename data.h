#pragma once
#include <vector>
#include <stack>
//�ĸ�����
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

//�����࣬������Ϸ�е���������
class Data {
	friend class service;
public:
	//�ߵĺ������ꡢ�˶�����
	struct node {
		int x, y;
		int dir;
	};
	//������
	std::vector<struct node> snake;
	//����ʳ��
	std::stack<std::pair<int, int>> food;
	//�ߵ��ٶ�
	int speed;
	//����
	int scores;

	Data();
	~Data() { }
};