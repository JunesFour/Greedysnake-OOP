#include "view.h"
#include <graphics.h>
#include <conio.h>

view::view(int x, int y) {
	initgraph(x, y);
	cleardevice();
	this->loadImage(&firstpage, "∑‚√Ê.png", 1000, 600);
}
void view::setWindowColor(COLORREF color) {
	setbkcolor(color);
	cleardevice();
}
void view::setWindowColor(int x, int y, int z) {
	setbkcolor(RGB(x, y, z));;
	cleardevice();
}
void view::setLineStyle(COLORREF color) {
	setlinecolor(color);
}
void view::setLineStyle(int x, int y, int z) {
	setlinecolor(RGB(x, y, z));
}
void view::drawLine(int x1, int y1, int x2, int y2) {
	line(x1, y1, x2, y2);
}
void view::setRectangleStyle(COLORREF color) {
	setfillcolor(color);
}
void view::setRectangleStyle(int x, int y, int z) {
	setfillcolor(RGB(x, y, z));
}
void view::drawRectangle(int x1, int y1, int x2, int y2) {
	fillrectangle(x1, y1, x2, y2);
}
void view::setTextStyle(COLORREF color, int x, int y, const char* font) {
	settextcolor(color);
	settextstyle(x, y, font);
}
void view::setTextStyle(int a, int b, int c, int x, int y, const char* font) {
	settextcolor(RGB(a, b, c));
	settextstyle(x, y, font);
}
void view::outText(int a, int b, const char* text) {
	outtextxy(a, b, text);
}
void view::loadImage(IMAGE *a, const char *path, int x, int y) {
	loadimage(a, path, x, y);
}
void view::putImage(int x, int y, IMAGE *a) {
	putimage(x, y, a);
}
void view::setBkMode(int STYLE) {
	setbkmode(STYLE);
}