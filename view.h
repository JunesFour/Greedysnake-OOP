
#pragma once
#include <iostream>
#include <graphics.h>
using namespace std;

class view {
public:
	IMAGE firstpage;
	IMAGE map;

	//���캯������һ������
	view(int, int);
	~view() { }

	//���ô�����ɫ
	void setWindowColor(COLORREF);
	void setWindowColor(int, int, int);

	//����
	void setLineStyle(COLORREF);
	void setLineStyle(int, int, int);
	void drawLine(int, int, int, int);

	//������
	void setRectangleStyle(COLORREF);
	void setRectangleStyle(int, int, int);
	void drawRectangle(int, int, int, int);

	//�������
	void setTextStyle(COLORREF color, int, int, const char*);
	void setTextStyle(int, int, int, int, int, const char*);
	void outText(int, int, const char*);

	//��ͼ
	void loadImage(IMAGE *, const char *, int, int);
	void putImage(int, int, IMAGE *);
	void setBkMode(int);
};