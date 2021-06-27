
#pragma once
#include <iostream>
#include <graphics.h>
using namespace std;

class view {
public:
	IMAGE firstpage;
	IMAGE map;

	//构造函数构造一个窗口
	view(int, int);
	~view() { }

	//设置窗口颜色
	void setWindowColor(COLORREF);
	void setWindowColor(int, int, int);

	//画线
	void setLineStyle(COLORREF);
	void setLineStyle(int, int, int);
	void drawLine(int, int, int, int);

	//画矩形
	void setRectangleStyle(COLORREF);
	void setRectangleStyle(int, int, int);
	void drawRectangle(int, int, int, int);

	//输出文字
	void setTextStyle(COLORREF color, int, int, const char*);
	void setTextStyle(int, int, int, int, int, const char*);
	void outText(int, int, const char*);

	//贴图
	void loadImage(IMAGE *, const char *, int, int);
	void putImage(int, int, IMAGE *);
	void setBkMode(int);
};