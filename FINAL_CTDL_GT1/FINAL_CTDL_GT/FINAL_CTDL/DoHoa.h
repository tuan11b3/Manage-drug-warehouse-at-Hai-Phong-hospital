#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
using namespace std;

// Ham thay doi kich thuoc cua khung voi height, weight
void resizeConsole(int width, int height);

// Ham dich chuyen con tro den x, y
void gotoXY(int x, int y);

// H?m x?a m?n h?nh.
void XoaManHinh();

// Doi mau chu
void TextColor(int x);

// Ham to mau
void ToMau(int x, int y, char *a, int color);

// Ham chon mau
void setColor(int x);

// Ham in chuoi
void drawText(int x, int y, string text, int color);

void DisableCtrButton(bool Close, bool Min, bool Max);

void SetWindowSize(SHORT width, SHORT height);

void DisableResizeWindow();

