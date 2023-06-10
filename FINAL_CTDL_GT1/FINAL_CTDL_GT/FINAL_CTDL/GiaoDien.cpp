
#include"GiaoDien.h"

// doi key -32 thanh cac so duong
int GetKey() {
	char key; 
	key = _getch();
	if (key == -32 || key == 0)
		return (_getch());
	else return key;
}

//==========Giao Dien Dung Chung=========

void GioiThieu() {
	drawText(35,0,  " _____ _______ _____ _______  _    _  _____  __   __",11);
	drawText(35,1,"|  __ \\__   __|_   _|__   __ | |  | |/ ____ |  \\/    |",11);
	drawText(35,2,"| |__) | | |    | |    | |   | |__| | |     |  \\  /  |",11);
	drawText(35,3,"|  ___/  | |    | |    | |   |  __  | |     | |\\ /|  |",11);
	drawText(35,4,"| |      | |   _| |_   | |   | |  | | |____ | |   |  |",11);
	drawText(35,5,"|_|      |_|  |_____|  |_|   |_|  |_|\\_____ |_|   |__|",11);
	drawText(45,7,"NHOM 41: QUAN LY KHO DUOC BENH VIEN HAI PHONG",11);
}

void xoaKhungNhap(){
	for(int i = 4; i < 30; i++) {
		gotoXY(20, i); cout << "                                                                                                                              ";
	}
}
void khungThongTin() {
	TextColor(228);
	for(int i = 30; i <= 90; i++) 
	{	TextColor(228);
		gotoXY(i, 18); cout << char(205);
		gotoXY(i, 27); cout << char(205);

	}
	
	for(int i = 18; i <= 27; i++) {
		
		// ve duong doc ben trai va phai
		gotoXY(30, i); cout << char(186);
		gotoXY(90, i); cout << char(186);
	}
	gotoXY(90, 18); cout << char(187);
	gotoXY(90, 27); cout << char(188);
	
	gotoXY(30, 18); cout << char(201);
	gotoXY(30, 27); cout << char(200);
}


int	 ThongBao_LuuFile() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12); cout << "     Ban Co Muon Luu Vao File!   ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(25, 12); cout << "                                 ";
				gotoXY(25, 13);	cout << "   ";
				gotoXY(55, 13);	cout << "   ";
				gotoXY(25, 14);	cout << "   ";
				gotoXY(55, 14);	cout << "   ";
				gotoXY(25, 15);	cout << "   ";
				gotoXY(55, 15);	cout << "   ";
				gotoXY(25, 16);	cout << "                                 ";
				gotoXY(28, 13); cout << "                           ";
				gotoXY(28, 14); cout << "                           ";
				gotoXY(28, 15); cout << "                           ";
				gotoXY(33, 14);	cout << "     ";
				gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

int	 ThongBao_HuyHT() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12); cout << " Ban Co Chac Huy HANG THUOC Nay? ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(25, 12); cout << "                                 ";
				gotoXY(25, 13);	cout << "   ";
				gotoXY(55, 13);	cout << "   ";
				gotoXY(25, 14);	cout << "   ";
				gotoXY(55, 14);	cout << "   ";
				gotoXY(25, 15);	cout << "   ";
				gotoXY(55, 15);	cout << "   ";
				gotoXY(25, 16);	cout << "                                 ";
				gotoXY(28, 13); cout << "                           ";
				gotoXY(28, 14); cout << "                           ";
				gotoXY(28, 15); cout << "                           ";
				gotoXY(33, 14);	cout << "     ";
				gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

void GhiChu(string c, int x, int y, int color, int sleep)
{

	gotoXY(x, y);
	TextColor(color);
	cout << c;
	Sleep(sleep);
	gotoXY(x, y);
	TextColor(14);
	for (int j = 0; j <= c.length(); j++)
	{
		cout << ' ';
	}

}

void PhanTrang(int trang, int tongtrang, int x, int y) {
	TextColor(174);	gotoXY(x, y); cout << " Trang:        ";
	gotoXY(x + 8, y); cout << trang << "/" << tongtrang;
	TextColor(14);
}
//=========================GIAO DIEN HANG THUOC=========

void HT_KhungXuat(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n   +----------------------------------------------+-------------+--------------------------------------------+";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |-----+----------------------------------------+-------------+--------------------------------------------|";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |     |           |                            |             |                               |            |";
	cout << "\n   |---------------------------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                                         |";
	cout << "\n   +---------------------------------------------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "              DANH SACH HANG THUOC         ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(12, 6);	cout << "MA HT";
	gotoXY(27, 6);	cout << "TEN HANG THUOC";
	gotoXY(55, 6);	cout << "SDT";
	gotoXY(74, 6);	cout << "DIA CHI";
	gotoXY(101, 6);	cout << "MST";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(45, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(56, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}
void HT_KhungMenuXoa(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                 ";
	gotoXY(30, 17); cout << "                                 ";
	gotoXY(30, 18); cout << "                                 ";
	gotoXY(30, 19); cout << "                                 ";
	gotoXY(33, 16); cout << "Nhap Ma Hang Thuoc Can Xoa";
	TextColor(228); gotoXY(33, 19); cout << "Enter:";
	gotoXY(51, 19); cout << "ESC:";
	TextColor(225); gotoXY(40, 19); cout << "OK";
	gotoXY(56, 19); cout << "Exit";
	TextColor(14);
	gotoXY(35, 17); cout << "          ";
}

void HT_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                 ";
	gotoXY(30, 17); cout << "                                 ";
	gotoXY(30, 18); cout << "                                 ";
	gotoXY(30, 19); cout << "                                 ";
	gotoXY(33, 16); cout << "Nhap Ma Hang Thuoc Can Sua";
	TextColor(228); gotoXY(33, 19); cout << "Enter:";
	gotoXY(51, 19); cout << "ESC:";
	TextColor(225); gotoXY(40, 19); cout << "OK";
	gotoXY(56, 19); cout << "Exit";
	TextColor(14);
	gotoXY(35, 17); cout << "          ";
}
void HT_KhungThem(){
	TextColor(225);
	gotoXY(7, 14);		cout << "                                     NHAP THONG TIN HANG THUOC CAN THEM                            ";
	TextColor(228);
	gotoXY(7, 15);		cout << "                                                                                                   ";
	gotoXY(7, 16);    	cout << "                                                                                                   ";
	gotoXY(10, 16);    	cout << "MA HT";
	gotoXY(25, 16);		cout << "TEN HANG THUOC";

	gotoXY(52, 16);		cout << "SDT";
	gotoXY(70, 16);		cout << "DIA CHI";
	gotoXY(97, 16);     cout << "MST";
	gotoXY(7, 17);    	cout << "                                                                                                   ";
	gotoXY(7, 18);    	cout << "                                                                                                   ";
	gotoXY(7, 19);    	cout << "                                                                                                 ";
	TextColor(225);
	gotoXY(9, 19);    	cout << "                                                                                                 ";
	TextColor(15);
	gotoXY(9, 17);    	cout << "         ";
	gotoXY(20, 17);    	cout << "                         ";

	gotoXY(48, 17);		cout << "           ";
	gotoXY(61, 17);		cout << "                              ";
	gotoXY(92, 17);		cout << "           ";
}

void HT_KhungSua(){
	TextColor(225);
	gotoXY(18, 14);		cout << "                                     NHAP THONG TIN HANG THUOC CAN THEM                           ";
	TextColor(228);
	gotoXY(18, 15);		cout << "                                                                                                 ";
	gotoXY(18, 16);    	cout << "                                                                                                  ";
	gotoXY(25, 16);		cout << "TEN HANG THUOC";

	gotoXY(52, 16);		cout << "SDT";
	gotoXY(70, 16);		cout << "DIA CHI";
	gotoXY(95, 16);     cout << "MST";
	gotoXY(18, 17);    	cout << "                                                                                                  ";
	gotoXY(18, 18);    	cout << "                                                                                                  ";
	gotoXY(18, 19);    	cout << "                                                                                                ";
	TextColor(225);
	gotoXY(20, 19);    	cout << "                                                                                                ";
	TextColor(15);
	gotoXY(20, 17);    	cout << "                         ";

	gotoXY(48, 17);		cout << "           ";
	gotoXY(61, 17);		cout << "                              ";
	gotoXY(92, 17);		cout << "          ";
}

int ThongBaoXoaMa_HT_PN(){
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 11); cout << "       Thao tac se xoa tat ca tat     ";
	gotoXY(25, 12); cout << "       THONG TIN cua HANG THUOC nay!     ";
	gotoXY(25, 13);	cout << "       ";
	gotoXY(55, 13);	cout << "        ";
	gotoXY(25, 14);	cout << "       ";
	gotoXY(55, 14);	cout << "        ";
	gotoXY(25, 15);	cout << "       ";
	gotoXY(55, 15);	cout << "        ";
	gotoXY(25, 16);	cout << "                                      ";
	TextColor(238);
	gotoXY(30, 13); cout << "                            ";
	gotoXY(30, 14); cout << "                            ";
	gotoXY(30, 15); cout << "                            ";
	TextColor(252);	gotoXY(35, 14);	cout << " YES ";
	TextColor(233);	gotoXY(50, 14);	cout << " NO ";
	gotoXY(36, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(35, 14); cout << " YES ";
				TextColor(252);		gotoXY(50, 14); cout << " NO ";
				gotoXY(51, 14);
			}
			else {
				TextColor(252);		gotoXY(35, 14); cout << " YES ";
				TextColor(233);		gotoXY(50, 14); cout << " NO ";
				gotoXY(36, 14);
			}
		}
		if (key == ENTER) {
			if (count % 2 == 0) {
				TextColor(14);
				TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 11); cout << "                                       	";
					gotoXY(25, 12); cout << "                                       	";
					gotoXY(25, 13);	cout << "   	";
					gotoXY(55, 13);	cout << "   	";
					gotoXY(25, 14);	cout << "   	";
					gotoXY(55, 14);	cout << "   	";
					gotoXY(25, 15);	cout << "   	";
					gotoXY(55, 15);	cout << "   	";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           	";
					gotoXY(28, 14); cout << "                           	";
					gotoXY(28, 15); cout << "                           	";
					gotoXY(33, 14);	cout << "     	";
					gotoXY(45, 14);	cout << "     	";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "      ";
			gotoXY(55, 13);	cout << "      ";
			gotoXY(25, 14);	cout << "      ";
			gotoXY(55, 14);	cout << "      ";
			gotoXY(25, 15);	cout << "      ";
			gotoXY(55, 15);	cout << "      ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

//==================GIAO DIEN THUOC====================
void Thuoc_KhungXuat(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n   +-----------------------------------------+-----------+------------------------+--------------------------------+";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |-----+-----------------------------------+-----------+------------------------+--------------------------------|";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |     |           |                       |            |                                |          |            |";
	cout << "\n   |---------------------------------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                                               |";
	cout << "\n   +---------------------------------------------------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "                     DANH SACH THUOC         ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(12, 6);	cout << "MA THUOC";
	gotoXY(29, 6);	cout << "TEN THUOC";
	gotoXY(48, 6);	cout << "NONG DO";
	gotoXY(68, 6);	cout << "NOI SAN XUAT";
	gotoXY(95, 6);	cout << "DVT";
	gotoXY(105, 6);	cout << "HAN DUNG";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(45, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(56, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}
void Thuoc_KhungMenuXoa(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                 ";
	gotoXY(30, 17); cout << "                                 ";
	gotoXY(30, 18); cout << "                                 ";
	gotoXY(30, 19); cout << "                                 ";
	gotoXY(33, 16); cout << "Nhap Ma Thuoc Can Xoa";
	TextColor(228); gotoXY(33, 19); cout << "Enter:";
	gotoXY(51, 19); cout << "ESC:";
	TextColor(225); gotoXY(40, 19); cout << "OK";
	gotoXY(56, 19); cout << "Exit";
	TextColor(14);
	gotoXY(35, 17); cout << "          ";
}

void Thuoc_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                 ";
	gotoXY(30, 17); cout << "                                 ";
	gotoXY(30, 18); cout << "                                 ";
	gotoXY(30, 19); cout << "                                 ";
	gotoXY(33, 16); cout << "Nhap Ma Thuoc Can Sua";
	TextColor(228); gotoXY(33, 19); cout << "Enter:";
	gotoXY(51, 19); cout << "ESC:";
	TextColor(225); gotoXY(40, 19); cout << "OK";
	gotoXY(56, 19); cout << "Exit";
	TextColor(14);
	gotoXY(35, 17); cout << "          ";
}
void Thuoc_KhungThem(){
	TextColor(225);
	gotoXY(7, 14);		cout << "                                     NHAP THONG TIN THUOC CAN THEM                                   ";
	TextColor(228);
	gotoXY(7, 15);		cout << "                                                                                                     ";
	gotoXY(7, 16);    	cout << "                                                                                                     ";
	gotoXY(9, 16);    	cout << "MA THUOC";
	gotoXY(26, 16);		cout << "TEN THUOC";
	gotoXY(42, 16);		cout << "NONG DO";
	gotoXY(62, 16);		cout << "NOI SAN XUAT";
	gotoXY(88, 16);     cout << "DVT";
	gotoXY(95, 16);     cout << "HAN DUNG";
	gotoXY(7, 17);    	cout << "                                                                                                     ";
	gotoXY(7, 18);    	cout << "                                                                                                     ";
	gotoXY(7, 19);    	cout << "                                                                                                   ";
	TextColor(225);
	gotoXY(9, 19);    	cout << "                                                                                                   ";
	TextColor(15);
	gotoXY(9, 17);    	cout << "         ";
	gotoXY(20, 17);    	cout << "                    ";
	gotoXY(42, 17);		cout << "          ";
	gotoXY(54, 17);		cout << "                              ";
	gotoXY(86, 17);		cout << "       ";
	gotoXY(95, 17);		cout << "           ";
}

void Thuoc_KhungSua(){
	TextColor(225);
	gotoXY(18, 14);		cout << "                                     NHAP THONG TIN THUOC CAN SUA                         ";
	TextColor(228);
	gotoXY(18, 15);		cout << "                                                                                          ";
	gotoXY(18, 16);    	cout << "                                                                                          ";
	gotoXY(23, 16);		cout << "TEN THUOC";
	gotoXY(44, 16);		cout << "NONG DO";
	gotoXY(60, 16);		cout << "NOI SAN XUAT";
	gotoXY(87, 16);     cout << "DVT";
	gotoXY(95, 16);     cout << "HAN DUNG";
	gotoXY(18, 17);    	cout << "                                                                                          ";
	gotoXY(18, 18);    	cout << "                                                                                          ";
	gotoXY(18, 19);    	cout << "                                                                                          ";
	TextColor(225);
	gotoXY(20, 19);    	cout << "                                                                                       ";
	TextColor(15);
	gotoXY(20, 17);    	cout << "                    ";
	gotoXY(42, 17);		cout << "          ";
	gotoXY(54, 17);		cout << "                              ";
	gotoXY(86, 17);		cout << "       ";
	gotoXY(95, 17);		cout << "           ";
}
int	 ThongBao_HuyThuoc() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12); cout << " Ban Co Chac Huy THUOC Nay?      ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(25, 12); cout << "                                 ";
				gotoXY(25, 13);	cout << "   ";
				gotoXY(55, 13);	cout << "   ";
				gotoXY(25, 14);	cout << "   ";
				gotoXY(55, 14);	cout << "   ";
				gotoXY(25, 15);	cout << "   ";
				gotoXY(55, 15);	cout << "   ";
				gotoXY(25, 16);	cout << "                                 ";
				gotoXY(28, 13); cout << "                           ";
				gotoXY(28, 14); cout << "                           ";
				gotoXY(28, 15); cout << "                           ";
				gotoXY(33, 14);	cout << "     ";
				gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

//=============GIAO DIEN PHIEU NHAP=============
void PhieuNhap_KhungXuat(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n   +-----------------------------------------+-----------+------------------------+----------------------------------+";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |-----+-----------------------------------+-----------+-----------------------+-----------------------------------|";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |     |           |           |           |            |                           |                              |";
	cout << "\n   |-----------------------------------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                                                 |";
	cout << "\n   +-----------------------------------------------------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "                     DANH SACH PHIEU NHAP                       ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(11, 6);	cout << "SO PHIEU";
	gotoXY(24, 6);	cout << "MA NV";
	gotoXY(37, 6);	cout << "MA HT";
	gotoXY(48, 6);	cout << "NGAY NHAP";
	gotoXY(68, 6);	cout << "TEN KHO";
	gotoXY(97, 6);	cout << "DIA DIEM";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(45, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(56, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}
void PhieuNhap_KhungMenuXoa(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                      ";
	gotoXY(30, 17); cout << "                                      ";
	gotoXY(30, 18); cout << "                                      ";
	gotoXY(30, 19); cout << "                                      ";
	gotoXY(33, 16); cout << "Nhap So Phieu Can Xoa"; 
	TextColor(228); gotoXY(33, 19); cout << "Enter:";
	gotoXY(51, 19); cout << "ESC:";
	TextColor(225); gotoXY(40, 19); cout << "OK";
	gotoXY(56, 19); cout << "Exit";
	TextColor(14);
	gotoXY(35, 17); cout << "          ";
}

void PhieuNhap_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                        ";
	gotoXY(30, 17); cout << "                                        ";
	gotoXY(30, 18); cout << "                                        ";
	gotoXY(30, 19); cout << "                                        ";
	gotoXY(33, 16); cout << "Nhap So Phieu Can Sua";
	TextColor(228); gotoXY(33, 19); cout << "Enter:";
	gotoXY(51, 19); cout << "ESC:";
	TextColor(225); gotoXY(40, 19); cout << "OK";
	gotoXY(56, 19); cout << "Exit";
	TextColor(14);
	gotoXY(35, 17); cout << "          ";
}
void PhieuNhap_KhungThem(){
	TextColor(225);
	gotoXY(7, 14);		cout << "                                     NHAP THONG TIN SO PHIEU CAN THEM                                     ";
	TextColor(228);
	gotoXY(7, 15);		cout << "                                                                                                          ";
	gotoXY(7, 16);    	cout << "                                                                                                          ";
	gotoXY(9, 16);    	cout << "SO PHIEU";
	gotoXY(22, 16);		cout << "MA NV";
	gotoXY(32, 16);		cout << "MA HT";
//	gotoXY(43, 16);		cout << "NGAY NHAP";
	gotoXY(50, 16);     cout << "TEN KHO";
	gotoXY(80, 16);     cout << "DIA DIEM";
	gotoXY(7, 17);    	cout << "                                                                                                          ";
	gotoXY(7, 18);    	cout << "                                                                                                          ";
	gotoXY(7, 19);    	cout << "                                                                                                        ";
	TextColor(225);
	gotoXY(9, 19);    	cout << "                                                                                                        ";
	TextColor(15);
	gotoXY(9, 17);    	cout << "         ";
	gotoXY(20, 17);    	cout << "         ";
	gotoXY(31, 17);		cout << "         ";
	//gotoXY(43, 17);		cout << "          ";
	gotoXY(43, 17);		cout << "                          ";
	gotoXY(75, 17);		cout << "                                ";
}

void PhieuNhap_KhungSua(){
	TextColor(225);
	gotoXY(18, 14);		cout << "                                     NHAP THONG TIN THUOC CAN SUA                         ";
	TextColor(228);
	gotoXY(18, 15);		cout << "                                                                                          ";
	gotoXY(18, 16);    	cout << "                                                                                          ";
	gotoXY(20, 16);		cout << "MA NV";
	gotoXY(32, 16);		cout << "MA HT";
	gotoXY(51, 16);		cout << "TEN KHO";
	gotoXY(85, 16);     cout << "DIA DIEM";
//	gotoXY(95, 16);     cout << "DIA DIEM";
	gotoXY(18, 17);    	cout << "                                                                                          ";
	gotoXY(18, 18);    	cout << "                                                                                          ";
	gotoXY(18, 19);    	cout << "                                                                                          ";
	TextColor(225);
	gotoXY(20, 19);    	cout << "                                                                                      ";
	TextColor(15);
	gotoXY(20, 17);    	cout << "         ";
	gotoXY(31, 17);		cout << "         ";
//	gotoXY(43, 17);		cout << "          ";
	gotoXY(43, 17);		cout << "                          ";
	gotoXY(75, 17);		cout << "                               ";
}
int	 ThongBao_HuyPhieuNhap() {
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 12); cout << " Ban Co Chac Huy Phieu Nhap Nay? ";
	gotoXY(25, 13);	cout << "   ";
	gotoXY(55, 13);	cout << "   ";
	gotoXY(25, 14);	cout << "   ";
	gotoXY(55, 14);	cout << "   ";
	gotoXY(25, 15);	cout << "   ";
	gotoXY(55, 15);	cout << "   ";
	gotoXY(25, 16);	cout << "                                 ";
	TextColor(238);
	gotoXY(28, 13); cout << "                           ";
	gotoXY(28, 14); cout << "                           ";
	gotoXY(28, 15); cout << "                           ";
	TextColor(252);	gotoXY(33, 14);	cout << " YES ";
	TextColor(233);	gotoXY(45, 14);	cout << " NO ";
	gotoXY(34, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(33, 14); cout << " YES ";
				TextColor(252);		gotoXY(45, 14); cout << " NO ";
				gotoXY(46, 14);
			}
			else {
				TextColor(252);		gotoXY(33, 14); cout << " YES ";
				TextColor(233);		gotoXY(45, 14); cout << " NO ";
				gotoXY(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				TextColor(14);
				gotoXY(25, 12); cout << "                                 ";
				gotoXY(25, 13);	cout << "   ";
				gotoXY(55, 13);	cout << "   ";
				gotoXY(25, 14);	cout << "   ";
				gotoXY(55, 14);	cout << "   ";
				gotoXY(25, 15);	cout << "   ";
				gotoXY(55, 15);	cout << "   ";
				gotoXY(25, 16);	cout << "                                 ";
				gotoXY(28, 13); cout << "                           ";
				gotoXY(28, 14); cout << "                           ";
				gotoXY(28, 15); cout << "                           ";
				gotoXY(33, 14);	cout << "     ";
				gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 12); cout << "                                 ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                 ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

//========================GIAO DIEN CHI TIET PHIEU NHAP===============
void CTPhieuNhap_KhungXuat(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n            +----------------------------------+----------------------------------+";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |-----+----------------------------+----------------------------------|";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |---------------------------------------------------------------------|";
	cout << "\n            |                                                                     |";
	cout << "\n            +---------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "   DANH SACH CHI TIET PHIEU NHAP         ";
	TextColor(14);	gotoXY(14, 6);    cout << "STT";
	gotoXY(21, 6);	cout << "SO PHIEU";
	gotoXY(35, 6);	cout << "MA THUOC";
	gotoXY(51, 6);	cout << "SO LUONG";
	gotoXY(67, 6);	cout << "DON GIA";
	gotoXY(15, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(28, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(45, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(56, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(67, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}
void CTPhieuNhap_KhungMenuXoa(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                            ";
	gotoXY(30, 17); cout << "                                            ";
	gotoXY(30, 18); cout << "                                            ";
	gotoXY(30, 19); cout << "                                            ";
	gotoXY(30, 20); cout << "                                            ";
	gotoXY(40, 16); cout << "Nhap Thong Tin Can Xoa";
	gotoXY(39, 17); cout << "SO PHIEU";
	gotoXY(56, 17); cout << "MA THUOC";
	TextColor(228); gotoXY(36, 20); cout << "Enter:";
	gotoXY(60, 20); cout << "ESC:";
	TextColor(225); gotoXY(49, 20); cout << "OK";
	gotoXY(65, 20); cout << "Exit";
	TextColor(14);
	gotoXY(37, 18); cout << "            ";
	gotoXY(53, 18); cout << "            ";
}

void CTPhieuNhap_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                            ";
	gotoXY(30, 17); cout << "                                            ";
	gotoXY(30, 18); cout << "                                            ";
	gotoXY(30, 19); cout << "                                            ";
	gotoXY(30, 20); cout << "                                            ";
	gotoXY(40, 16); cout << "Nhap Thong Tin Can Sua";
	gotoXY(39, 17); cout << "SO PHIEU";
	gotoXY(56, 17); cout << "MA THUOC";
	TextColor(228); gotoXY(36, 20); cout << "Enter:";
	gotoXY(60, 20); cout << "ESC:";
	TextColor(225); gotoXY(49, 20); cout << "OK";
	gotoXY(65, 20); cout << "Exit";
	TextColor(14);
	gotoXY(37, 18); cout << "            ";
	gotoXY(53, 18); cout << "            ";
}
void CTPhieuNhap_KhungThem(){
	TextColor(225);
	gotoXY(20, 14);		cout << "          NHAP THONG TIN CHI TIET PHIEU NHAP CAN THEM              ";
	TextColor(228);
	gotoXY(20, 15);		cout << "                                                                   ";
	gotoXY(20, 16);    	cout << "                                                                   ";
	gotoXY(22, 16);    	cout << "SO PHIEU";
	gotoXY(33, 16);		cout << "MA THUOC";

	gotoXY(45, 16);		cout << "SO LUONG";
	gotoXY(63, 16);		cout << "DON GIA";
	gotoXY(20, 17);    	cout << "                                                                   ";
	gotoXY(20, 18);    	cout << "                                                                   ";
	gotoXY(20, 19);    	cout << "                                                              ";
	TextColor(225);
	gotoXY(22, 19);    	cout << "                                                                 ";
	TextColor(15);
	gotoXY(22, 17);    	cout << "         ";
	gotoXY(33, 17);    	cout << "         ";
	gotoXY(44, 17);		cout << "          ";
	gotoXY(58, 17);		cout << "                    ";
}

void CTPhieuNhap_KhungSua(){
	TextColor(225);
	gotoXY(20, 14);		cout << "          NHAP THONG TIN CHI TIET PHIEU NHAP CAN SUA               ";
	TextColor(228);
	gotoXY(20, 15);		cout << "                                                                   ";
	gotoXY(20, 16);    	cout << "                                                                   ";
	gotoXY(22, 16);    	cout << "SO PHIEU";
	gotoXY(33, 16);		cout << "MA THUOC";

	gotoXY(44, 16);		cout << "SO LUONG";
	gotoXY(63, 16);		cout << "DON GIA";
	gotoXY(20, 17);    	cout << "                                                                   ";
	gotoXY(20, 18);    	cout << "                                                                   ";
	gotoXY(20, 19);    	cout << "                                                              ";
	gotoXY(20, 20);    	cout << "                                                                   ";
	TextColor(225);
	gotoXY(22, 19);    	cout << "                                                                 ";
	TextColor(15);
	gotoXY(22, 17);    	cout << "         ";
	gotoXY(33, 17);    	cout << "         ";
	gotoXY(44, 17);		cout << "          ";
	gotoXY(58, 17);		cout << "                    ";
}

int ThongBao_HuyCTPN(){
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 11); cout << "       Thao tac se xoa tat ca tat     ";
	gotoXY(25, 12); cout << "   THONG TIN cua CT PHIEU NHAP nay!   ";
	gotoXY(25, 13);	cout << "       ";
	gotoXY(55, 13);	cout << "        ";
	gotoXY(25, 14);	cout << "       ";
	gotoXY(55, 14);	cout << "        ";
	gotoXY(25, 15);	cout << "       ";
	gotoXY(55, 15);	cout << "        ";
	gotoXY(25, 16);	cout << "                                      ";
	TextColor(238);
	gotoXY(30, 13); cout << "                            ";
	gotoXY(30, 14); cout << "                            ";
	gotoXY(30, 15); cout << "                            ";
	TextColor(252);	gotoXY(35, 14);	cout << " YES ";
	TextColor(233);	gotoXY(50, 14);	cout << " NO ";
	gotoXY(36, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(35, 14); cout << " YES ";
				TextColor(252);		gotoXY(50, 14); cout << " NO ";
				gotoXY(51, 14);
			}
			else {
				TextColor(252);		gotoXY(35, 14); cout << " YES ";
				TextColor(233);		gotoXY(50, 14); cout << " NO ";
				gotoXY(36, 14);
			}
		}
		if (key == ENTER) {
			if (count % 2 == 0) {
				TextColor(14);
				TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 11); cout << "                                       	";
					gotoXY(25, 12); cout << "                                       	";
					gotoXY(25, 13);	cout << "   	";
					gotoXY(55, 13);	cout << "   	";
					gotoXY(25, 14);	cout << "   	";
					gotoXY(55, 14);	cout << "   	";
					gotoXY(25, 15);	cout << "   	";
					gotoXY(55, 15);	cout << "   	";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           	";
					gotoXY(28, 14); cout << "                           	";
					gotoXY(28, 15); cout << "                           	";
					gotoXY(33, 14);	cout << "     	";
					gotoXY(45, 14);	cout << "     	";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "      ";
			gotoXY(55, 13);	cout << "      ";
			gotoXY(25, 14);	cout << "      ";
			gotoXY(55, 14);	cout << "      ";
			gotoXY(25, 15);	cout << "      ";
			gotoXY(55, 15);	cout << "      ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

//======================GIAO DIEN DONG LINH
void DongLinh_KhungXuat(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n            +----------------------------------+----------------------------------+";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |-----+----------------------------+----------------------------------|";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |     |             |              |             |                    |";
	cout << "\n            |---------------------------------------------------------------------|";
	cout << "\n            |                                                                     |";
	cout << "\n            +---------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "   DANH SACH DONG LINH         ";
	TextColor(14);	gotoXY(14, 6);    cout << "STT";
	gotoXY(21, 6);	cout << "SO PHIEU";
	gotoXY(35, 6);	cout << "MA THUOC";
	gotoXY(51, 6);	cout << "SL YEU CAU";
	gotoXY(67, 6);	cout << "SL CAP PHAT";
	gotoXY(15, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(28, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(45, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(56, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(67, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}
void DongLinh_KhungMenuXoa(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                            ";
	gotoXY(30, 17); cout << "                                            ";
	gotoXY(30, 18); cout << "                                            ";
	gotoXY(30, 19); cout << "                                            ";
	gotoXY(30, 20); cout << "                                            ";
	gotoXY(40, 16); cout << "Nhap Thong Tin Can Xoa";
	gotoXY(39, 17); cout << "SO PHIEU";
	gotoXY(56, 17); cout << "MA THUOC";
	TextColor(228); gotoXY(36, 20); cout << "Enter:";
	gotoXY(60, 20); cout << "ESC:";
	TextColor(225); gotoXY(49, 20); cout << "OK";
	gotoXY(65, 20); cout << "Exit";
	TextColor(14);
	gotoXY(37, 18); cout << "            ";
	gotoXY(53, 18); cout << "            ";
}

void DongLinh_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 16); cout << "                                            ";
	gotoXY(30, 17); cout << "                                            ";
	gotoXY(30, 18); cout << "                                            ";
	gotoXY(30, 19); cout << "                                            ";
	gotoXY(30, 20); cout << "                                            ";
	gotoXY(40, 16); cout << "Nhap Thong Tin Can Sua";
	gotoXY(39, 17); cout << "SO PHIEU";
	gotoXY(56, 17); cout << "MA THUOC";
	TextColor(228); gotoXY(36, 20); cout << "Enter:";
	gotoXY(60, 20); cout << "ESC:";
	TextColor(225); gotoXY(49, 20); cout << "OK";
	gotoXY(65, 20); cout << "Exit";
	TextColor(14);
	gotoXY(37, 18); cout << "            ";
	gotoXY(53, 18); cout << "            ";
}
void DongLinh_KhungThem(){
	TextColor(225);
	gotoXY(20, 14);		cout << "               NHAP THONG TIN DONG LINH CAN THEM                   ";
	TextColor(228);
	gotoXY(20, 15);		cout << "                                                                   ";
	gotoXY(20, 16);    	cout << "                                                                   ";
	gotoXY(22, 16);    	cout << "SO PHIEU";
	gotoXY(33, 16);		cout << "MA THUOC";

	gotoXY(45, 16);		cout << "SL YEU CAU";
	gotoXY(63, 16);		cout << "SL CAP PHAT";
	gotoXY(20, 17);    	cout << "                                                                   ";
	gotoXY(20, 18);    	cout << "                                                                   ";
	gotoXY(20, 19);    	cout << "                                                              ";
	TextColor(225);
	gotoXY(22, 19);    	cout << "                                                                 ";
	TextColor(15);
	gotoXY(22, 17);    	cout << "         ";
	gotoXY(33, 17);    	cout << "         ";
	gotoXY(44, 17);		cout << "          ";
	gotoXY(58, 17);		cout << "          ";
}

void DongLinh_KhungSua(){
	TextColor(225);
	gotoXY(20, 14);		cout << "          NHAP THONG TIN DONG LINH CAN SUA               ";
	TextColor(228);
	gotoXY(20, 15);		cout << "                                                                   ";
	gotoXY(20, 16);    	cout << "                                                                   ";
	gotoXY(22, 16);    	cout << "SO PHIEU";
	gotoXY(33, 16);		cout << "MA THUOC";

	gotoXY(44, 16);		cout << "SO LUONG";
	gotoXY(63, 16);		cout << "DON GIA";
	gotoXY(20, 17);    	cout << "                                                                   ";
	gotoXY(20, 18);    	cout << "                                                                   ";
	gotoXY(20, 19);    	cout << "                                                              ";
	gotoXY(20, 20);    	cout << "                                                                   ";
	TextColor(225);
	gotoXY(22, 19);    	cout << "                                                                 ";
	TextColor(15);
	gotoXY(22, 17);    	cout << "         ";
	gotoXY(33, 17);    	cout << "         ";
	gotoXY(44, 17);		cout << "          ";
	gotoXY(58, 17);		cout << "          ";
}

int ThongBao_HuyDL(){
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 11); cout << "       Thao tac se xoa tat ca tat     ";
	gotoXY(25, 12); cout << "      THONG TIN cua DONG LINH nay!    ";
	gotoXY(25, 13);	cout << "       ";
	gotoXY(55, 13);	cout << "        ";
	gotoXY(25, 14);	cout << "       ";
	gotoXY(55, 14);	cout << "        ";
	gotoXY(25, 15);	cout << "       ";
	gotoXY(55, 15);	cout << "        ";
	gotoXY(25, 16);	cout << "                                      ";
	TextColor(238);
	gotoXY(30, 13); cout << "                            ";
	gotoXY(30, 14); cout << "                            ";
	gotoXY(30, 15); cout << "                            ";
	TextColor(252);	gotoXY(35, 14);	cout << " YES ";
	TextColor(233);	gotoXY(50, 14);	cout << " NO ";
	gotoXY(36, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(35, 14); cout << " YES ";
				TextColor(252);		gotoXY(50, 14); cout << " NO ";
				gotoXY(51, 14);
			}
			else {
				TextColor(252);		gotoXY(35, 14); cout << " YES ";
				TextColor(233);		gotoXY(50, 14); cout << " NO ";
				gotoXY(36, 14);
			}
		}
		if (key == ENTER) {
			if (count % 2 == 0) {
				TextColor(14);
				TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 11); cout << "                                       	";
					gotoXY(25, 12); cout << "                                       	";
					gotoXY(25, 13);	cout << "   	";
					gotoXY(55, 13);	cout << "   	";
					gotoXY(25, 14);	cout << "   	";
					gotoXY(55, 14);	cout << "   	";
					gotoXY(25, 15);	cout << "   	";
					gotoXY(55, 15);	cout << "   	";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           	";
					gotoXY(28, 14); cout << "                           	";
					gotoXY(28, 15); cout << "                           	";
					gotoXY(33, 14);	cout << "     	";
					gotoXY(45, 14);	cout << "     	";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "      ";
			gotoXY(55, 13);	cout << "      ";
			gotoXY(25, 14);	cout << "      ";
			gotoXY(55, 14);	cout << "      ";
			gotoXY(25, 15);	cout << "      ";
			gotoXY(55, 15);	cout << "      ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}


// ------ DO HOA PhieuXuat ---------
void KhungXuat_PX(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n   +-----------------------------------------+----------+-------------------------+-------------------------+";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |-----+-----------------------------------+----------+-------------------------+-------------------------|";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |     |           |           |           |          |                         |                         |";
	cout << "\n   |--------------------------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                                        |";
	cout << "\n   +--------------------------------------------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "    DANH SACH PHIEU XUAT    ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(10, 6);	cout << " SO PHIEU  ";
	gotoXY(22, 6);	cout << "   MANV    ";
	gotoXY(34, 6);	cout << " MAKHOACN  ";
	gotoXY(46, 6);	cout << "NGAY XUAT ";
	gotoXY(57, 6);	cout << "   TEN KHO NHAN THUOC    ";
	gotoXY(83, 6);	cout << "   TEN KHONT    MANVNT   ";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(45, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(56, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

//void PhanTrang(int trang, int tongtrang, int x, int y){
//	TextColor(174);
//	gotoXY(x, y);
//	cout<<"Trang: "<<trang<<"/"<<tongtrang;
//}

void PX_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap So Phieu Can Sua";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "                           ";
}

void PX_KhungMenuThem(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                                 ";
	gotoXY(30, 14); cout << "                                                 ";
	gotoXY(30, 15); cout << "                                                 ";
	gotoXY(33, 13); cout << "Nhap So Phieu Can Them";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "           ";
}

void PX_KhungSua() {
	TextColor(228);
	gotoXY(12, 13); cout << "   MANV      MAKHOACN       TEN KHO NHAN THUOC    TEN KHONT      MANVNT        ";
	gotoXY(12, 14); cout << "                                                                               ";
	gotoXY(12, 15); cout << "                                                                               ";
	TextColor(228);	gotoXY(53, 15); cout << "Enter:";
	gotoXY(65, 15); cout << "ESC:";
	TextColor(225);	gotoXY(60, 15); cout << "OK";
	gotoXY(70, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(15, 14); cout << "          ";
	gotoXY(26, 14); cout << "          ";
	gotoXY(37, 14); cout << "                         ";
	gotoXY(63, 14); cout << "       ";
	gotoXY(73, 14); cout << "          ";
}


int ThongBaoXoaFK_PX(){
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 11); cout << "       Thao tac se xoa tat ca tat     ";
	gotoXY(25, 12); cout << "       Don Xuat cua so phieu nay!     ";
	gotoXY(25, 13);	cout << "       ";
	gotoXY(55, 13);	cout << "        ";
	gotoXY(25, 14);	cout << "       ";
	gotoXY(55, 14);	cout << "        ";
	gotoXY(25, 15);	cout << "       ";
	gotoXY(55, 15);	cout << "        ";
	gotoXY(25, 16);	cout << "                                      ";
	TextColor(238);
	gotoXY(30, 13); cout << "                            ";
	gotoXY(30, 14); cout << "                            ";
	gotoXY(30, 15); cout << "                            ";
	TextColor(252);	gotoXY(35, 14);	cout << " YES ";
	TextColor(233);	gotoXY(50, 14);	cout << " NO ";
	gotoXY(36, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(35, 14); cout << " YES ";
				TextColor(252);		gotoXY(50, 14); cout << " NO ";
				gotoXY(51, 14);
			}
			else {
				TextColor(252);		gotoXY(35, 14); cout << " YES ";
				TextColor(233);		gotoXY(50, 14); cout << " NO ";
				gotoXY(36, 14);
			}
		}
		if (key == ENTER) {
			if (count % 2 == 0) {
				TextColor(14);
				TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 11); cout << "                                       	";
					gotoXY(25, 12); cout << "                                       	";
					gotoXY(25, 13);	cout << "   	";
					gotoXY(55, 13);	cout << "   	";
					gotoXY(25, 14);	cout << "   	";
					gotoXY(55, 14);	cout << "   	";
					gotoXY(25, 15);	cout << "   	";
					gotoXY(55, 15);	cout << "   	";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           	";
					gotoXY(28, 14); cout << "                           	";
					gotoXY(28, 15); cout << "                           	";
					gotoXY(33, 14);	cout << "     	";
					gotoXY(45, 14);	cout << "     	";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "      ";
			gotoXY(55, 13);	cout << "      ";
			gotoXY(25, 14);	cout << "      ";
			gotoXY(55, 14);	cout << "      ";
			gotoXY(25, 15);	cout << "      ";
			gotoXY(55, 15);	cout << "      ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

void PX_KhungXoa() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Mon Hoc Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);	gotoXY(33, 14); cout << "                           ";
}

// -------- DO HOA DongXuat -------
void KhungXuat_DX(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n   +-----------------------------------------+----------|-------------+";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |-----+-----------------------------------+----------|-------------|";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |     |           |           |           |          |             |";
	cout << "\n   |----------------------------------------------------|-------------";
	cout << "\n   |                                                    |             |";
	cout << "\n   |                                                    |             |";
	cout << "\n   |                                                    |             |";
	cout << "\n   +----------------------------------------------------+-------------";
	TextColor(174);
	gotoXY(33, 2);	cout << "    DANH SACH DONG XUAT    ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(10, 6);	cout << " SO PHIEU  ";
	gotoXY(22, 6);	cout << " MA THUOC  ";
	gotoXY(34, 6);	cout << "  SL XUAT  ";
	gotoXY(46, 6);	cout << "  DON GIA  ";
	gotoXY(57, 6);	cout << "  THOI GIAN  ";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(45, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(4, 26);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

void DX_KhungMenuThem(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                         ";
	gotoXY(30, 14); cout << "                                         ";
	gotoXY(30, 15); cout << "                                         ";
	gotoXY(33, 13); cout << "Nhap So Phieu va Ma Thuoc Can Them";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(233);
	gotoXY(33, 14); cout<<"SoPhieu"; 
	gotoXY(51, 14); cout<<"MaThuoc";
	TextColor(14);
	gotoXY(40, 14); cout << "          ";
	gotoXY(58, 14); cout << "          ";
}

void DX_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                         ";
	gotoXY(30, 14); cout << "                                         ";
	gotoXY(30, 15); cout << "                                         ";
	gotoXY(33, 13); cout << "Nhap So Phieu va Ma Thuoc Can Sua";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(233);
	gotoXY(33, 14); cout<<"SoPhieu"; 
	gotoXY(51, 14); cout<<"MaThuoc";
	TextColor(14);
	gotoXY(40, 14); cout << "          ";
	gotoXY(58, 14); cout << "          ";
}

void DX_KhungSua(){
	TextColor(228);
	gotoXY(17, 13); cout << "   SOPHIEU    MATHUOC    SO LUONG XUAT       DON GIA     ";
	gotoXY(17, 14); cout << "                                                         ";
	gotoXY(17, 15); cout << "                                                         ";
	TextColor(228);	gotoXY(54, 15); cout << "Enter:";
	gotoXY(65, 15); cout << "ESC:";
	TextColor(225);	gotoXY(60, 15); cout << "OK";
	gotoXY(70, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(20, 14); cout << "          ";
	gotoXY(31, 14); cout << "          ";
	gotoXY(42, 14); cout << "              ";
	gotoXY(57, 14); cout << "              ";
}

void DX_KhungXoa(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                         ";
	gotoXY(30, 14); cout << "                                         ";
	gotoXY(30, 15); cout << "                                         ";
	gotoXY(33, 13); cout << "Nhap So Phieu va Ma Thuoc Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(233);
	gotoXY(33, 14); cout<<"SoPhieu"; 
	gotoXY(51, 14); cout<<"MaThuoc";
	TextColor(14);
	gotoXY(40, 14); cout << "          ";
	gotoXY(58, 14); cout << "          ";
}

//----------GIAO DIEN NHANVIEN--------
void KhungXuat_NV(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n             +-----------------------------------------+--------------------+";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |-----+-----------------------------------+--------------------+";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |     |           |                       |                    |";
	cout << "\n             |--------------------------------------------------------------|";
	cout << "\n             |                                                              |";
	cout << "\n             +--------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "    DANH SACH NHAN VIEN    ";
	TextColor(14);	gotoXY(14, 6);    cout << "STT";
	gotoXY(22, 6);	cout << " MANV";
	gotoXY(38, 6);	cout << " HO VA TEN";
	gotoXY(61, 6);	cout << " CHUC VU";
	gotoXY(14, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(26, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(42, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(52, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(61, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

void NV_KhungMenuSua(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma NV Can Sua";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "                           ";
}

void NV_KhungMenuThem(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                                 ";
	gotoXY(30, 14); cout << "                                                 ";
	gotoXY(30, 15); cout << "                                                 ";
	gotoXY(33, 13); cout << "Nhap Ma NV Can Them";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "           ";
}

void NV_KhungThem() {
	TextColor(228);
	gotoXY(14, 13); cout << "    HO VA TEN                      CHUC VU         ";
	gotoXY(14, 14); cout << "                                                   ";
	gotoXY(14, 15); cout << "                                                   ";
	TextColor(228);	gotoXY(53, 15); cout << "Enter:";
	gotoXY(66, 15); cout << "ESC:";
	TextColor(225);	gotoXY(60, 15); cout << "OK";
	gotoXY(70, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(15, 14); cout << "                              ";
	gotoXY(47, 14); cout << "               ";
	//gotoXY(63, 14); cout << "                         ";
}

void NV_KhungSua() {
	TextColor(228);
	gotoXY(14, 13); cout << "    HO VA TEN                      CHUC VU                   ";
	gotoXY(14, 14); cout << "                                                             ";
	gotoXY(14, 15); cout << "                                                             ";
	TextColor(228);	gotoXY(53, 15); cout << "Enter:";
	gotoXY(66, 15); cout << "ESC:";
	TextColor(225);	gotoXY(60, 15); cout << "OK";
	gotoXY(70, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(15, 14); cout << "                              ";
	gotoXY(47, 14); cout << "               ";
	//gotoXY(63, 14); cout << "                         ";
}

int ThongBaoXoaFK_NV(){
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 11); cout << "       Thao tac se xoa tat ca tat     ";
	gotoXY(25, 12); cout << "       Nhien vien cua ds nhan vien nay";
	gotoXY(25, 13);	cout << "       ";
	gotoXY(55, 13);	cout << "        ";
	gotoXY(25, 14);	cout << "       ";
	gotoXY(55, 14);	cout << "        ";
	gotoXY(25, 15);	cout << "       ";
	gotoXY(55, 15);	cout << "        ";
	gotoXY(25, 16);	cout << "                                      ";
	TextColor(238);
	gotoXY(30, 13); cout << "                            ";
	gotoXY(30, 14); cout << "                            ";
	gotoXY(30, 15); cout << "                            ";
	TextColor(252);	gotoXY(35, 14);	cout << " YES ";
	TextColor(233);	gotoXY(50, 14);	cout << " NO ";
	gotoXY(36, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(35, 14); cout << " YES ";
				TextColor(252);		gotoXY(50, 14); cout << " NO ";
				gotoXY(51, 14);
			}
			else {
				TextColor(252);		gotoXY(35, 14); cout << " YES ";
				TextColor(233);		gotoXY(50, 14); cout << " NO ";
				gotoXY(36, 14);
			}
		}
		if (key == ENTER) {
			if (count % 2 == 0) {
				TextColor(14);
				TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

void NV_KhungXoa() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap Ma Nhan Vien Can Xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);	gotoXY(33, 14); cout << "                           ";
}

//--------GIAO DIEN NVKIEMKE------------

void KhungXuat_NVKK(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n             +--------------------------------+----------+";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |-----+--------------------------+----------+";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |     |           |              |          |";
	cout << "\n             |-------------------------------------------|";
	cout << "\n             |                                           |";
	cout << "\n             |                                           |";
	cout << "\n             |                                           |";
	cout << "\n             +-------------------------------------------+";
	TextColor(174);
	gotoXY(25, 2);	cout << " DANH SACH NV KIEM KE ";
	TextColor(14);	gotoXY(14, 6);    cout << "STT";
	gotoXY(21, 6);	cout << " SOPHIEU";
	gotoXY(37, 6);	cout << " MANV ";
	gotoXY(48, 6);	cout << " NGAYKK";
	gotoXY(14, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(26, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(42, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(14, 26);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(26, 26);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

void NVKK_KhungMenuSua(){
	TextColor(228);
	gotoXY(17, 13); cout << "                                 ";
	gotoXY(17, 14); cout << "                                 ";
	gotoXY(17, 15); cout << "                                 ";
	gotoXY(20, 13); cout << "Nhap So Phieu Can Sua";
	TextColor(228); gotoXY(17, 15); cout << "Enter:";
	gotoXY(27, 15); cout << "ESC:";
	TextColor(225); gotoXY(24, 15); cout << "OK";
	gotoXY(32, 15); cout << "Exit";
	TextColor(14);
	gotoXY(20, 14); cout << "                   ";
}

void NVKK_KhungMenuThem(){
	TextColor(228);
	gotoXY(14, 13); cout << "                                           ";
	gotoXY(14, 14); cout << "                                           ";
	gotoXY(14, 15); cout << "                                           ";
	gotoXY(14, 16); cout << "                                           ";
	gotoXY(16, 13); cout << "Nhap So Phieu Can Them";
	TextColor(228); gotoXY(16, 15); cout << "Enter:";
	gotoXY(28, 15); cout << "ESC:";
	TextColor(225); gotoXY(23, 15); cout << "OK";
	gotoXY(33, 15); cout << "Exit";
	TextColor(14);
	gotoXY(16, 14); cout << "           ";
}

void NVKK_KhungSua() {
	TextColor(228);
	gotoXY(14, 13); cout << "   MANV                          ";
	gotoXY(14, 14); cout << "                                 ";
	gotoXY(14, 15); cout << "                                 ";
	gotoXY(14, 16); cout << "                                 ";
	TextColor(228);	gotoXY(18, 15); cout << "Enter:";
	gotoXY(29, 15); cout << "ESC:";
	TextColor(225);	gotoXY(25, 15); cout << "OK";
	gotoXY(34, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(15, 14); cout << "          ";
}
void NVKK_KhungThem() {
	TextColor(228);
	gotoXY(14, 13); cout << "    MANV                            ";
	gotoXY(14, 14); cout << "                                    ";
	gotoXY(14, 15); cout << "                                    ";
	gotoXY(14, 16); cout << "                                    ";
	TextColor(228);	gotoXY(18, 15); cout << "Enter:";
	gotoXY(29, 15); cout << "ESC:";
	TextColor(225);	gotoXY(25, 15); cout << "OK";
	gotoXY(34, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(15, 14); cout << "          ";
}

void NVKK_KhungXoa() {
	TextColor(228);
	gotoXY(14, 13); cout << " SO Phieu                           ";
	gotoXY(14, 14); cout << "                                    ";
	gotoXY(14, 15); cout << "                                    ";
	gotoXY(14, 16); cout << "                                    ";
	TextColor(228);	gotoXY(18, 15); cout << "Enter:";
	gotoXY(29, 15); cout << "ESC:";
	TextColor(225);	gotoXY(25, 15); cout << "OK";
	gotoXY(34, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(15, 14); cout << "          ";
}

//---------GIAO DIEN KHOA CHUC NANG---------
void KhungXuat_KCN(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n             +----------------------------------------------------------------------+";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |-----+-----------+---------------------+------------------------------+";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |     |           |                     |                              |";
	cout << "\n             |----------------------------------------------------------------------|";
	cout << "\n             |                                                                      |";
	cout << "\n             +----------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(32, 2);	cout << " DANH SACH KHOA CHUC NANG ";
	TextColor(14);	gotoXY(14, 6);    cout << "STT";
	gotoXY(21, 6);	cout << " MAKHOACN";
	gotoXY(35, 6);	cout << " TENKHOACN ";
	gotoXY(59, 6);	cout << " TENNGUOIDAIDIEN";
	gotoXY(14, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(26, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(42, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(52, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(61, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

void KCN_KhungMenuSua(){
	TextColor(228);
	gotoXY(25, 13); cout << "                                                       ";
	gotoXY(25, 14); cout << "                                                       ";
	gotoXY(25, 15); cout << "                                                       ";
	gotoXY(30, 13); cout << "Nhap Ma Khoa CN Can Sua";
	TextColor(228); gotoXY(30, 15); cout << "Enter:";
	gotoXY(40, 15); cout << "ESC:";
	TextColor(225); gotoXY(37, 15); cout << "OK";
	gotoXY(45, 15); cout << "Exit";
	TextColor(14);
	gotoXY(31, 14); cout << "                   ";
}

void KCN_KhungMenuThem(){
	TextColor(228);
	gotoXY(25, 13); cout << "                                                       ";
	gotoXY(25, 14); cout << "                                                       ";
	gotoXY(25, 15); cout << "                                                       ";
	gotoXY(30, 13); cout << "Nhap Ma Khoa CN Can Them";
	TextColor(228); gotoXY(30, 15); cout << "Enter:";
	gotoXY(40, 15); cout << "ESC:";
	TextColor(225); gotoXY(37, 15); cout << "OK";
	gotoXY(45, 15); cout << "Exit";
	TextColor(14);
	gotoXY(31, 14); cout << "                   ";
}

void KCN_KhungSua() {
	TextColor(228);
	gotoXY(20, 13); cout << "       TENKHOACN                TENNGUOIDAIDIEN  ";
	gotoXY(20, 14); cout << "                                                 ";
	gotoXY(20, 15); cout << "                                                 ";
	gotoXY(20, 16); cout << "                                                            ";
	TextColor(228);	gotoXY(22, 15); cout << "Enter:";
	gotoXY(30, 15); cout << "ESC:";
	TextColor(225);	gotoXY(27, 15); cout << "OK";
	gotoXY(35, 15); cout << "Exit";
	TextColor(12);
	

	gotoXY(22, 14); cout << "                    ";
	gotoXY(49, 14); cout << "                           ";
	//gotoXY(63, 14); cout << "                         ";
}
void KCN_KhungThem() {
	TextColor(228);
	gotoXY(20, 13); cout << "       TENKHOACN                TENNGUOIDAIDIEN  ";
	gotoXY(20, 14); cout << "                                                 ";
	gotoXY(20, 15); cout << "                                                 ";
	gotoXY(20, 16); cout << "                                                            ";
	TextColor(228);	gotoXY(22, 15); cout << "Enter:";
	gotoXY(30, 15); cout << "ESC:";
	TextColor(225);	gotoXY(27, 15); cout << "OK";
	gotoXY(35, 15); cout << "Exit";
	TextColor(12);
	

	gotoXY(22, 14); cout << "                    ";
	gotoXY(49, 14); cout << "                           ";
	//gotoXY(63, 14); cout << "                         ";
}

void KCN_KhungXoa(){
	TextColor(228);
	gotoXY(25, 13); cout << "                                                       ";
	gotoXY(25, 14); cout << "                                                       ";
	gotoXY(25, 15); cout << "                                                       ";
	gotoXY(30, 13); cout << "Nhap Ma Khoa CN Can Sua";
	TextColor(228); gotoXY(30, 15); cout << "Enter:";
	gotoXY(40, 15); cout << "ESC:";
	TextColor(225); gotoXY(37, 15); cout << "OK";
	gotoXY(45, 15); cout << "Exit";
	TextColor(14);
	gotoXY(31, 14); cout << "                   ";
}

//----------GIAO DIEN KHOA PHIEU LINH--------------
void KhungXuat_PL(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n             +----------------------------------------------------------+";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |-----+--------------------------+-------------------------+";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |     |           |              |            |            |";
	cout << "\n             |----------------------------------------------------------|";
	cout << "\n             |                                                          |";
	cout << "\n             |                                                          |";
	cout << "\n             |                                                          |";
	cout << "\n             +----------------------------------------------------------+";
	TextColor(174);
	gotoXY(24, 2);	cout << " DANH SACH PHIEU LINH ";
	TextColor(14);	gotoXY(15, 6);    cout << "STT";
	gotoXY(21, 6);	cout << " SOPHIEU";
	gotoXY(34, 6);	cout << " MATHUOC ";
	gotoXY(49, 6);	cout << "MAKHOACN";
	gotoXY(60, 6);	cout << "NGAYYEUCAU";
	gotoXY(16, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(27,24 );	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(43, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(16, 26);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(26, 26);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

void PL_KhungMenuSua(){
	TextColor(228);
	gotoXY(27, 13); cout << "                                           ";
	gotoXY(27, 14); cout << "                                           ";
	gotoXY(27, 15); cout << "                                           ";
	gotoXY(27, 16); cout << "                                           ";
	gotoXY(28, 13); cout << "Nhap So Phieu Can Them";
	TextColor(228); gotoXY(28, 15); cout << "Enter:";
	gotoXY(37, 15); cout << "ESC:";
	TextColor(225); gotoXY(35, 15); cout << "OK";
	gotoXY(42, 15); cout << "Exit";
	TextColor(14);
	gotoXY(28, 14); cout << "             ";
}

void PL_KhungMenuThem(){
	TextColor(228);
	gotoXY(27, 13); cout << "                                           ";
	gotoXY(27, 14); cout << "                                           ";
	gotoXY(27, 15); cout << "                                           ";
	gotoXY(27, 16); cout << "                                           ";
	gotoXY(28, 13); cout << "Nhap So Phieu Can Them";
	TextColor(228); gotoXY(28, 15); cout << "Enter:";
	gotoXY(37, 15); cout << "ESC:";
	TextColor(225); gotoXY(35, 15); cout << "OK";
	gotoXY(42, 15); cout << "Exit";
	TextColor(14);
	gotoXY(28, 14); cout << "             ";
}

void PL_KhungSua() {
	TextColor(228);
	gotoXY(27, 13); cout << "  MANV        MAKHOACN           ";
	gotoXY(27, 14); cout << "                                 ";
	gotoXY(27, 15); cout << "                                 ";
	gotoXY(27, 16); cout << "                                 ";
	TextColor(228);	gotoXY(28, 15); cout << "Enter:";
	gotoXY(39, 15); cout << "ESC:";
	TextColor(225);	gotoXY(35, 15); cout << "OK";
	gotoXY(44, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(28, 14); cout << "          ";
	gotoXY(40, 14); cout << "            ";
	//gotoXY(63, 14); cout << "                         ";
}
void PL_KhungThem() {
	TextColor(228);
	gotoXY(27, 13); cout << "  MANV        MAKHOACN           ";
	gotoXY(27, 14); cout << "                                 ";
	gotoXY(27, 15); cout << "                                 ";
	gotoXY(27, 16); cout << "                                 ";
	TextColor(228);	gotoXY(28, 15); cout << "Enter:";
	gotoXY(39, 15); cout << "ESC:";
	TextColor(225);	gotoXY(35, 15); cout << "OK";
	gotoXY(44, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(28, 14); cout << "          ";
	gotoXY(40, 14); cout << "            ";
	//gotoXY(63, 14); cout << "                         ";
}
void PL_KhungXoa(){
	TextColor(228);
	gotoXY(27, 13); cout << "                                           ";
	gotoXY(27, 14); cout << "                                           ";
	gotoXY(27, 15); cout << "                                           ";
	gotoXY(27, 16); cout << "                                           ";
	gotoXY(28, 13); cout << "Nhap So Phieu Can Them";
	TextColor(228); gotoXY(28, 15); cout << "Enter:";
	gotoXY(37, 15); cout << "ESC:";
	TextColor(225); gotoXY(35, 15); cout << "OK";
	gotoXY(42, 15); cout << "Exit";
	TextColor(14);
	gotoXY(28, 14); cout << "             ";
}

//--------GIAO DIEN DONG KIEM KE----------
void KhungXuat_DKK(){
	gotoXY(0, 0);
	TextColor(14);
	cout << "\n\n\n\n";
	cout << "\n   +-----------------------------------------+------------+------------+----------+----------+---------------------+";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |-----+-----------------------------------+------------+------------+----------+----------+---------------------|";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |     |           |           |           |            |            |          |          |                     |";
	cout << "\n   |---------------------------------------------------------------------------------------------------------------|";
	cout << "\n   |                                                                                                               |";
	cout << "\n   +---------------------------------------------------------------------------------------------------------------+";
	TextColor(174);
	gotoXY(33, 2);	cout << "    DANH SACH DONG KIEM KE    ";
	TextColor(14);	gotoXY(5, 6);    cout << "STT";
	gotoXY(11, 6);	cout << "SO PHIEU";
	gotoXY(23, 6);	cout << "MATHUOC";
	gotoXY(35, 6);	cout << "SLTONKHO";
	gotoXY(46, 6);	cout << "SLNTRONGNGAY";
	gotoXY(59, 6);	cout << "SLXTRONGNGAY";
	gotoXY(72, 6);	cout << "SLHETHAN";
	gotoXY(84, 6);	cout << "SLVOHONG";
	gotoXY(97, 6);	cout << "SLTCUOINGAY";
	gotoXY(4, 24);	TextColor(252);	cout << "ESC";
	TextColor(14);	cout << ": Exit";
	gotoXY(18, 24);	TextColor(252);	cout << "INSERT";
	TextColor(14);	cout << ": Insert";
	gotoXY(33, 24);	TextColor(252);	cout << "F4";
	TextColor(14);	cout << ": EDIT";
	gotoXY(45, 24);	TextColor(252);	cout << "F2";
	TextColor(14);	cout << ": SAVE";
	gotoXY(56, 24);	TextColor(252);	cout << "DELETE";
	TextColor(14);	cout << ": Delete";
	gotoXY(0, 27);
}

void KhungMenuSua_DKK(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                                 ";
	gotoXY(30, 14); cout << "                                                 ";
	gotoXY(30, 15); cout << "                                                 ";
	gotoXY(33, 13); cout << "Nhap So Phieu          Nhap Ma Thuoc";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "           ";
	gotoXY(56, 14); cout << "           ";
}

void KhungMenuThem_DKK(){
	TextColor(228);
	gotoXY(30, 13); cout << "                                                 ";
	gotoXY(30, 14); cout << "                                                 ";
	gotoXY(30, 15); cout << "                                                 ";
	gotoXY(33, 13); cout << "Nhap So Phieu          Nhap Ma Thuoc";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);
	gotoXY(33, 14); cout << "           ";
	gotoXY(56, 14); cout << "           ";
}

void KhungSua_DKK() {
	TextColor(228);
	gotoXY(12, 13); cout << " SOPHIEU    MATHUOC     SLTONKHO     SLNTRONGNGAY     SLXTRONGNGAY    SLHETHAN   SLVOHONG    SLTCUOINGAY    ";
	gotoXY(12, 14); cout << "                                                                                                            ";
	gotoXY(12, 15); cout << "                                                                                                            ";
	TextColor(228);	gotoXY(53, 15); cout << "Enter:";
	gotoXY(65, 15); cout << "ESC:";
	TextColor(225);	gotoXY(60, 15); cout << "OK";
	gotoXY(70, 15); cout << "Exit";
	TextColor(12);
	
	gotoXY(13, 14); cout << "          ";
	gotoXY(24, 14); cout << "          ";
	gotoXY(36, 14); cout << "          ";
	gotoXY(50, 14); cout << "          ";
	gotoXY(67, 14); cout << "          ";
	gotoXY(81, 14); cout << "          ";
	gotoXY(93, 14); cout << "          ";
	gotoXY(105, 14); cout << "          ";
}

int ThongBaoXoaFK_DKK(){
	int key, count = 0;
	TextColor(206);
	gotoXY(25, 11); cout << "       Thao tac se xoa tat ca tat     ";
	gotoXY(25, 12); cout << "       dong kiem ke cua so phieu nay! ";
	gotoXY(25, 13);	cout << "       ";
	gotoXY(55, 13);	cout << "        ";
	gotoXY(25, 14);	cout << "       ";
	gotoXY(55, 14);	cout << "        ";
	gotoXY(25, 15);	cout << "       ";
	gotoXY(55, 15);	cout << "        ";
	gotoXY(25, 16);	cout << "                                      ";
	TextColor(238);
	gotoXY(30, 13); cout << "                            ";
	gotoXY(30, 14); cout << "                            ";
	gotoXY(30, 15); cout << "                            ";
	TextColor(252);	gotoXY(35, 14);	cout << " YES ";
	TextColor(233);	gotoXY(50, 14);	cout << " NO ";
	gotoXY(36, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoXY(35, 14); cout << " YES ";
				TextColor(252);		gotoXY(50, 14); cout << " NO ";
				gotoXY(51, 14);
			}
			else {
				TextColor(252);		gotoXY(35, 14); cout << " YES ";
				TextColor(233);		gotoXY(50, 14); cout << " NO ";
				gotoXY(36, 14);
			}
		}
		if (key == ENTER) {
			if (count % 2 == 0) {
				TextColor(14);
				TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
				return 1;
			}
			else if (count % 2 == 1) {
					TextColor(14);
					gotoXY(25, 11); cout << "                                       ";
					gotoXY(25, 12); cout << "                                       ";
					gotoXY(25, 13);	cout << "   ";
					gotoXY(55, 13);	cout << "   ";
					gotoXY(25, 14);	cout << "   ";
					gotoXY(55, 14);	cout << "   ";
					gotoXY(25, 15);	cout << "   ";
					gotoXY(55, 15);	cout << "   ";
					gotoXY(25, 16);	cout << "                                   ";
					gotoXY(28, 13); cout << "                           ";
					gotoXY(28, 14); cout << "                           ";
					gotoXY(28, 15); cout << "                           ";
					gotoXY(33, 14);	cout << "     ";
					gotoXY(45, 14);	cout << "    ";
					return 0;
				}			
		}
		if (key == ESC||key==F2) {
			TextColor(14);
			gotoXY(25, 12); cout << "                                 ";
			gotoXY(25, 13);	cout << "   ";
			gotoXY(55, 13);	cout << "   ";
			gotoXY(25, 14);	cout << "   ";
			gotoXY(55, 14);	cout << "   ";
			gotoXY(25, 15);	cout << "   ";
			gotoXY(55, 15);	cout << "   ";
			gotoXY(25, 16);	cout << "                                 ";
			gotoXY(28, 13); cout << "                           ";
			gotoXY(28, 14); cout << "                           ";
			gotoXY(28, 15); cout << "                           ";
			gotoXY(33, 14);	cout << "     ";
			gotoXY(45, 14);	cout << "    ";
			return -1;
		}
	}
}

void KhungXoa_DKK() {
	TextColor(228);
	gotoXY(30, 13); cout << "                                 ";
	gotoXY(30, 14); cout << "                                 ";
	gotoXY(30, 15); cout << "                                 ";
	gotoXY(33, 13); cout << "Nhap so phieu can xoa";
	TextColor(228); gotoXY(33, 15); cout << "Enter:";
	gotoXY(51, 15); cout << "ESC:";
	TextColor(225); gotoXY(40, 15); cout << "OK";
	gotoXY(56, 15); cout << "Exit";
	TextColor(14);	gotoXY(33, 14); cout << "                           ";
}



