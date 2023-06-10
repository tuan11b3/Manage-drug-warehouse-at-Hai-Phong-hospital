
#include"DoHoa.h"
#include"GiaoDien.h"
#include"HangThuoc.h"
#include"PhieuNhap.h"
#include"Thuoc.h"
#include"CTPhieuNhap.h"
#include"DongLinh.h"
#include"PhieuXuat.h"
#include"GiaoDien.h"
#include"DongXuat.h"
#include"NhanVien.h"
#include"NVKiemKe.h"
#include"KCN.h"
#include"PhieuLinh.h"
#include"DKK.h"
#include"Date.h"

#include <string>
#include<windows.h>
#include<conio.h>
#include <ctime>
#include <string>
#include<sstream>
#include<iostream>

void ToMauMenuChinh(int color, int vitri);
int MenuCha();
int ChonMENU();
int numlen(int numb);
//======HANG THUOC======================
void HT_Sua(TreeHT *treeHT);
void HT_Them(TreeHT *treeHT);
void HT_Xoa(TreeHT *treeHT);
void HT_ThemSuaXoaDS();
//=======THUOC=======================
void Thuoc_Sua(TreeThuoc *treeThuoc);
void Thuoc_Them(TreeThuoc *treeThuoc);
void Thuoc_Xoa(TreeThuoc *treeThuoc);
void Thuoc_ThemSuaXoaDS();
date getCurrentDate();
bool isValidDate(int ngay, int thang, int nam) ;
bool compareDates(const date& date1, const date& date2);

//=============PHIEUNHAP==================
void Date_PN(NodePN *nPN);
void PN_Sua(TreePN *treePN);
void PN_Them(TreePN *treePN);
void PN_Xoa(TreePN *treePN);
void PN_ThemSuaXoaDS();
//===============CHI TIET PHIEU NHAP========
void CTPN_Them(ListCTPN *ListCTPN, TreePN *treePN, TreeThuoc *treeThuoc);
void CTPN_Sua(ListCTPN *ListCTPN, TreePN *treePN, TreeThuoc *treeThuoc);
void CTPN_Xoa(ListCTPN *ListCTPN);
void CTPN_ThemSuaXoaDS();
//============DONG LINH===========
void DL_Them(ListDL *listDL, TreeThuoc *treeThuoc);
void DL_Sua(ListDL *listDL, TreeThuoc *treeThuoc);
void DL_Xoa(ListDL *listDL);
void DL_ThemSuaXoaDS();
// Phieu xuat
void PX_Sua(TreePX *dspx, TreeNV dsnv, TreeKCN dskcn);
void PX_Them(TreePX *dspx, TreeNV dsnv, TreeKCN dskcn);
void Date_PX(NodePX *nf);
void PX_Xoa(TreePX *dspx);
void MH_ChucNangPX();

// Dong xuat
void DX_Sua(LinkListDX *dsdx);
void DX_Them(LinkListDX *dsdx, TreePX dspx, int position);
void Date_DX(DongXuat *nf);
void DX_Xoa(TreePX *dspx);
void MH_ChucNangDX();
void Date_DX(DongXuat *px);

// Nhan Vien
void NV_Sua(TreeNV *dsnv);
void NV_Them(TreeNV *dsnv);
void NV_Xoa(TreeNV* dsnv, TreePX dspx);
void MH_ChucNangPX();

// Nhan Vien Kiem Ke
void Date_NVKK(NodeNVKK *nf);
void NVKK_Sua(TreeNVKK *dsnvkk, TreeNV dsnv);
void NVKK_Them(TreeNVKK *dsnvkk, TreeNV dsnv);
void NVKK_Xoa(TreeNVKK* dsnvkk);
void MHKK_ChucNangPX();

// Khoa Chuc Nang
void KCN_Sua(TreeKCN *dskcn);
void KCN_Them(TreeKCN *dskcn);
void KCN_Xoa(TreeKCN* dskcn, TreePX dspx, TreePL dspl);
void MH_ChucNangKCN();

// Phieu Linh
void PL_Sua(TreePL *dspl, TreeNV dsnv, TreeKCN dskcn);
void PL_Them(TreePL *dsnvkk, TreeNV dsnv, TreeKCN dskcn);
void PL_Xoa(TreePL* dsnvkk);
void Date_PN(NodePL *nf);
void MH_ChucNangPL();

// dong kiem ke
void DKK_Them(LinkListDKK *dsdkk, int position);
void DKK_Sua(LinkListDKK *dsdkk);
void DKK_Xoa( LinkListDKK *dsdkk);
void MH_ChucNangDKK();

char MENUChinh[12][40] = {
	"  1.Quan Ly Hang Thuoc  ",
	"  2.Quan Ly Thuoc       ",
	"  3.Quan Ly Phieu Nhap  ",
	"  4.Quan Ly CTPN        ",
	"  5.Quan Ly Dong Linh   ",
	"  6,Quan Ly Phieu Xuat  ",
	"  7,Quan Ly Nhan Vien   ",
	"  8,Quan Ly KhoaCN      ",
	"  9,Quan ly Dong Xuat   ",
	" 10,Quan ly Phieu Linh  ",
	" 11,Quan ly Dong KK     ",
	" 12,Quan ly NhanvienKK  "
};
	
void ToMauMenuChinh(int color, int vitri)
{	
	int x, y;
	x = vitri/4;
	y = vitri - 4*x;
	TextColor(color);
	gotoXY(10+x*40, 6 + y * 4 + 3); cout << "                        ";
	gotoXY(10+x*40, 7 + y * 4 + 3); cout << MENUChinh[vitri];
	gotoXY(10+x*40, 8 + y * 4 + 3); cout << "                        ";
}

void ToMauMenuCon(int color, char MENUCON[][40], int vitri)
{
	TextColor(color);
	gotoXY(75, 6 + (vitri + 1) * 4);	cout << "                                       ";
	gotoXY(75, 7 + (vitri + 1) * 4);	cout << MENUCON[vitri];
	gotoXY(75, 8 + (vitri + 1) * 4);	cout << "                                       ";
}

int MenuCha()
{

	int vitri = 0;
	while (1)
	{
		GioiThieu();
		char key = GetKey();
		if (key == ENTER) // vitri!= 6 la ngay tai o Tho?t
		{	
			return vitri + 1;
		}
		switch (key)
		{
		case DOWN:
		{	int x;
			x = vitri/4;
			if ((vitri-4*x) == 3)
			{
				ToMauMenuChinh(240, vitri);
				vitri = vitri - 3;
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri++;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		case UP:
		{	int x;
			x = vitri/4;
			if ((vitri-4*x) == 0)
			{
				ToMauMenuChinh(240, vitri);
				vitri = vitri + 3;
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri--;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		case RIGHT:
		{
			if(vitri/4 == 2){
				ToMauMenuChinh(240, vitri);
				vitri = vitri - 8;
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri += 4;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		case LEFT:
		{
			if(vitri/4 == 0){
				ToMauMenuChinh(240, vitri);
				vitri = vitri + 8;
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(240, vitri);
				vitri -= 4;
				ToMauMenuChinh(236, vitri);
			}
		}break;
		}
	}
}

int MenuCon(int item, char MENUCON[][40])
{

	char key;
	int vitri = 0;	int color = 188; int color1 = 236;
	while (1)
	{
		GioiThieu();
		key = GetKey();
		if (key == ENTER)
			return vitri + 1;
		if (key == ESC || key == LEFT)
		return 0;	
			
		switch (key)
		{
		case DOWN:
		{
			if (vitri == (item - 1))
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri = 0;
				ToMauMenuCon(236, MENUCON, vitri);
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri++;
				ToMauMenuCon(236, MENUCON, vitri);
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri = item - 1;
				ToMauMenuCon(236, MENUCON, vitri);
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri--;
				ToMauMenuCon(236, MENUCON, vitri);
			}
		}break;
		}
	}
}

void HT_Them(TreeHT *treeHT){
    int key, vitri = 0, x = 9, y = 17;
	NodeHT *nHT;
	HangThuoc ht;
	HT_KhungThem(); gotoXY(x, y);
MAHT:
    while(1)
    {
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(9 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			ht.maHT[vitri] = char(key);
			ht.maHT[vitri] = toupper(ht.maHT[vitri]);
			cout << ht.maHT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(9 + vitri, y);
			cout << " ";
			gotoXY(9 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ht.maHT[vitri] = '\0';
			nHT = treeHT->searchHT(treeHT->rootHT, ht.maHT);
			if (nHT) {
				TextColor(78);	gotoXY(9, 18);
				cout << "Trung Ma Hang Thuoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			nHT = treeHT->taoNodeHT(ht);
			strcpy(nHT->dataHT.maHT, ht.maHT);
			goto TENHT;
		}

		if (key == ESC ) { 
		return; 
		}
	}
TENHT:
	vitri = 0;
	while (1)
	{
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 25";
		TextColor(12); gotoXY(20 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 25))
		{
			nHT->dataHT.tenHT[vitri] = char(key);
			nHT->dataHT.tenHT[vitri] = toupper(nHT->dataHT.tenHT[vitri]);
			cout << nHT->dataHT.tenHT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(20 + vitri, y);
			cout << " ";
			gotoXY(20 + vitri, y);
		}
		if (key == SPACE && nHT->dataHT.tenHT[vitri - 1] != ' ' && vitri > 0 && vitri < 25) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(20 + vitri, y);
			cout << " ";
			nHT->dataHT.tenHT[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nHT->dataHT.tenHT[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nHT->dataHT.tenHT[vitri] = '\0';
			vitri = 0;
			gotoXY(48 + vitri, y);
			goto SDT;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
SDT:
	while (1)
	{
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (0-9 & .). Toi da: 10";
		TextColor(12); gotoXY(48 + vitri, y); // Ghi ch?
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 11) )
		{
			nHT->dataHT.sdt[vitri] = char(key);
			nHT->dataHT.sdt[vitri] = toupper(nHT->dataHT.sdt[vitri]);
			cout << nHT->dataHT.sdt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(48 + vitri, y);
			cout << " ";
			gotoXY(48 + vitri, y);
		}
		if (key == ENTER && vitri >=10)
		{
			if(nHT->dataHT.sdt[vitri - 1]==' ')	{ vitri--;} ////Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nHT->dataHT.sdt[vitri] = '\0';
		//	ht.sdt = atoi(sdt);
			vitri = 0;
			gotoXY(61 + vitri, y);
			goto DIACHI;
		}
		if (key == ESC ) { 
		return; 
		}
	}
DIACHI:
	while (1)
	{
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		TextColor(12); gotoXY(61 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			nHT->dataHT.diaChi[vitri] = char(key);
			nHT->dataHT.diaChi[vitri] = toupper(nHT->dataHT.diaChi[vitri]);
			cout << nHT->dataHT.diaChi[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(61 + vitri, y);
			cout << " ";
			gotoXY(61 + vitri, y);
		}
		if (key == SPACE && nHT->dataHT.diaChi[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(61 + vitri, y);
			cout << " ";
			nHT->dataHT.diaChi[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (ht.diaChi[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nHT->dataHT.diaChi[vitri] = '\0';
			vitri = 0;
			gotoXY(92 + vitri, y);
			goto MASOTHUE;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
MASOTHUE:
 while (1)
	{
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (0-9 & .). Toi da: 9";
		TextColor(12); gotoXY(92 + vitri, y); // Ghi ch?
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 9) )
		{
			nHT->dataHT.maSoThue[vitri] = char(key);
			nHT->dataHT.maSoThue[vitri] = toupper(nHT->dataHT.maSoThue[vitri]);
			cout << nHT->dataHT.maSoThue[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(92 + vitri, y);
			cout << " ";
			gotoXY(92 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			nHT->dataHT.maSoThue[vitri] = '\0';
			treeHT->rootHT = treeHT->insertHT(treeHT->rootHT, nHT);
			GhiChu("THEM HANG THUOC THANH CONG. F2 DE LUU", 35, 27, 79, 1000);
			break;
		}
		if (key == ESC ) { 
		return; 
		}
	}
}


void HT_Sua(TreeHT *treeHT){
    int key, vitri = 0, x = 33, y = 17, checkMaHT;
	NodeHT *nHT;
	HangThuoc ht;
	HT_KhungMenuSua(); gotoXY(x, y);

    while(1)
    {
		TextColor(250);	gotoXY(30, 18);
		cout << "Ki tu:(A-Z) & (0-9). Toi da:9 ";
		TextColor(12); gotoXY(35 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			ht.maHT[vitri] = char(key);
			ht.maHT[vitri] = toupper(ht.maHT[vitri]);
			cout << ht.maHT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35 + vitri, y);
			cout << " ";
			gotoXY(35 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ht.maHT[vitri] = '\0';
			nHT = treeHT->searchHT(treeHT->rootHT, ht.maHT);
			if (nHT) {
				HT_KhungSua();
				x = 20, y = 17;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(20, 17); cout<<nHT->dataHT.tenHT;
				gotoXY(48, 17); cout<<nHT->dataHT.sdt;
				gotoXY(61, 17); cout<<nHT->dataHT.diaChi;
				gotoXY(92, 17); cout<<nHT->dataHT.maSoThue;
				vitri = strlen(nHT->dataHT.tenHT);
				goto TENHT;
				break;
			}
			else{
				GhiChu("MA HANG THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				Sleep(1000);
				gotoXY(33 + vitri, y);
			}
		}

		if (key == ESC ) { 
		return; 
		}
	}
TENHT:
	while (1)
	{
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 25";
		TextColor(12); gotoXY(20 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 25))
		{
			nHT->dataHT.tenHT[vitri] = char(key);
			nHT->dataHT.tenHT[vitri] = toupper(nHT->dataHT.tenHT[vitri]);
			cout << nHT->dataHT.tenHT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(20 + vitri, y);
			cout << " ";
			gotoXY(20 + vitri, y);
		}
		if (key == SPACE && nHT->dataHT.tenHT[vitri - 1] != ' ' && vitri > 0 && vitri < 25) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(20 + vitri, y);
			cout << " ";
			nHT->dataHT.tenHT[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nHT->dataHT.tenHT[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nHT->dataHT.tenHT[vitri] = '\0';
			goto SDT;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
SDT:
	vitri = strlen(nHT->dataHT.sdt);
	while (1)
	{
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (0-9 & .). Toi da: 10";
		TextColor(12); gotoXY(48 + vitri, y); // Ghi ch?
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 11) )
		{
			nHT->dataHT.sdt[vitri] = char(key);
			nHT->dataHT.sdt[vitri] = toupper(nHT->dataHT.sdt[vitri]);
			cout << nHT->dataHT.sdt[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(48 + vitri, y);
			cout << " ";
			gotoXY(48 + vitri, y);
		}
		if (key == ENTER && vitri >= 10)
		{
			nHT->dataHT.sdt[vitri] = '\0';
			goto DIACHI;
		}
		if (key == ESC ) { 
		return; 
		}
	}
DIACHI:
	vitri = strlen(nHT->dataHT.diaChi);
	while (1)
	{
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		TextColor(12); gotoXY(61 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			nHT->dataHT.diaChi[vitri] = char(key);
			nHT->dataHT.diaChi[vitri] = toupper(nHT->dataHT.diaChi[vitri]);
			cout << nHT->dataHT.diaChi[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(61 + vitri, y);
			cout << " ";
			gotoXY(61 + vitri, y);
		}
		if (key == SPACE && nHT->dataHT.diaChi[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(61 + vitri, y);
			cout << " ";
			nHT->dataHT.diaChi[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nHT->dataHT.diaChi[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nHT->dataHT.diaChi[vitri] = '\0';
			// vitri = 0;
			// gotoXY(112 + vitri, y);
			goto MASOTHUE;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
MASOTHUE:
	vitri = strlen(nHT->dataHT.maSoThue);
 	while (1)
	{
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (0-9 & .). Toi da: 9";
		TextColor(12); gotoXY(92 + vitri, y); // Ghi ch?
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri < 9) )
		{
			nHT->dataHT.maSoThue[vitri] = char(key);
			nHT->dataHT.maSoThue[vitri] = toupper(nHT->dataHT.maSoThue[vitri]);
			cout << nHT->dataHT.maSoThue[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(92 + vitri, y);
			cout << " ";
			gotoXY(92 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			nHT->dataHT.maSoThue[vitri] = '\0';
			GhiChu("DA SUA HANG THUOC THANH CONG. F2 DE LUU", 35, 27, 79, 1000);
			return;
		}
		if (key == ESC ) { 
		return; 
		}
	}
}

void HT_Xoa(TreeHT *treeHT, TreePN *treePN)
{
	int key, vitri = 0, x = 33, y = 17;
	bool checkMa_HT_PN,  checkMaHT;
	char maHT[10];
	NodeHT *nHT;
QuayLai:
	vitri = 0; HT_KhungMenuXoa(); gotoXY(35, 17);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			maHT[vitri] = char(key);
			maHT[vitri] = toupper(maHT[vitri]);
			cout<< maHT[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			maHT[vitri] = '\0';
			checkMaHT = treeHT->CheckMaHT(treeHT->rootHT, maHT);
			checkMa_HT_PN = treePN->checkMa_HT_PN(treePN->rootPN, maHT);
			if(checkMaHT == true)
			{
				if(checkMa_HT_PN == true)
				{
					GhiChu("KHONG THE XOA VI MA HT DA CO TRONG PN!!!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y); 
					goto QuayLai;
				}
				else
				{
//					xoaKhungNhap();
//					khungThongTin();
//				
//					gotoXY(50, 18); cout << "THONG TIN HANG THUOC MUON XOA ";
//					TextColor(14);
//					gotoXY(34, 20); cout << "Ma Hang Thuoc			: " << nHT->dataHT.maHT;
//					gotoXY(34, 21); cout << "Ten Hang Thuoc		: " << nHT->dataHT.tenHT;
//					gotoXY(34, 22); cout << "SDT				: " << nHT->dataHT.sdt;
//					gotoXY(34, 23);	cout << "Dia Chi			: " << nHT->dataHT.diaChi;
//					gotoXY(34, 24); cout << "MST				: " << nHT->dataHT.maSoThue;
					int tamp = ThongBao_HuyHT();
					if(tamp == true){
						treeHT->rootHT = treeHT->deleteNodeHT(treeHT->rootHT, maHT);
						GhiChu("XOA HANG THUOC THANH CONG!", 35, 27, 79, 2000);
						gotoXY(33 + vitri, y);
						break;
					}
					else
					{
						GhiChu("XOA HANG THUOC KHONG THANH CONG!!!", 35, 27, 79, 2000);
						return;	
					}
				}
			}
			else
			{
				GhiChu("MA HANG THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				goto QuayLai;
			}
					
		}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35 + vitri, y);
			cout<<" ";
			gotoXY(35 + vitri, y);
		}
		
		if(key == ESC){
			return;
		}
	}
}
//====check ngay
bool isValidDate(int ngay, int thang, int nam) {
    if (nam < 1 || nam > 9999) {
        return false;
    }

    tm timeinfo = {};
    timeinfo.tm_year = nam - 1900;
    timeinfo.tm_mon = thang - 1;
    timeinfo.tm_mday = ngay;

    time_t time = mktime(&timeinfo);

    if (time == -1 || timeinfo.tm_mday != ngay || timeinfo.tm_mon != thang - 1 || timeinfo.tm_year != nam - 1900) {
        return false;
    }

    return true;
}

date getCurrentDate() {
    date currentDate;
    time_t t = time(NULL);
    tm* now = localtime(&t);
    currentDate.ngay = now->tm_mday;
    currentDate.thang = now->tm_mon + 1;
    currentDate.nam = now->tm_year + 1900;
    return currentDate;
}
bool isDateLessThanCurrent(int ngay, int thang, int nam) {
    date currentDate = getCurrentDate();
    if (nam < currentDate.nam) {
        return true;
    }
    if (nam == currentDate.nam && thang < currentDate.thang) {
        return true;
    }
    if (nam == currentDate.nam && thang == currentDate.thang && ngay <= currentDate.ngay) {
        return true;
    }
    return false;
}

//=================THUOC
void Thuoc_Them(TreeThuoc *treeThuoc){
    int key, vitri = 0, x = 9, y = 17;
	NodeT *nThuoc;
	Thuoc thuoc;
	Thuoc_KhungThem(); gotoXY(x, y);
MATHUOC:
    while(1)
    {
    	
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(9 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			thuoc.maThuoc[vitri] = char(key);
			thuoc.maThuoc[vitri] = toupper(thuoc.maThuoc[vitri]);
			cout << thuoc.maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(9 + vitri, y);
			cout << " ";
			gotoXY(9 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			thuoc.maThuoc[vitri] = '\0';
			nThuoc = treeThuoc->searchT(treeThuoc->rootT, thuoc.maThuoc);
			if (nThuoc) {
				TextColor(78);	gotoXY(9, 18);
				cout << "Trung Ma Thuoc. Nhap Lai!";
				Sleep(500);
				continue;
			}
			nThuoc = treeThuoc->taoNodeT(thuoc);
			strcpy(nThuoc->dataT.maThuoc, thuoc.maThuoc);
			goto TENTHUOC;
		}

		if (key == ESC ) { 
		return; 
		}
	}
TENTHUOC:
	vitri = 0;
	while (1)
	{
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 20";
		TextColor(12); gotoXY(20 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 20))
		{
			nThuoc->dataT.tenThuoc[vitri] = char(key);
			nThuoc->dataT.tenThuoc[vitri] = toupper(nThuoc->dataT.tenThuoc[vitri]);
			cout << nThuoc->dataT.tenThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(20 + vitri, y);
			cout << " ";
			gotoXY(20 + vitri, y);
		}
		if (key == SPACE && nThuoc->dataT.tenThuoc[vitri - 1] != ' ' && vitri > 0 && vitri < 20) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(20 + vitri, y);
			cout << " ";
			nThuoc->dataT.tenThuoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nThuoc->dataT.tenThuoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nThuoc->dataT.tenThuoc[vitri] = '\0';
			vitri = 0;
			gotoXY(42 + vitri, y);
			goto NONGDOHAMLUONG;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
NONGDOHAMLUONG:
	while (1) {
	    TextColor(250);
	    gotoXY(9, 18);
	    cout << "Ki tu: (A-Z) & (0-9). Toi da: 10 ";
	    TextColor(12);
	    gotoXY(42 + vitri, y);
	    key = GetKey();
	    
	    if ((key <= '9' && key >= '0' || key =='.') && (vitri < 10))
	    {   
	    	if (vitri == 0 && key == '.'){
	        	continue;
    		}
			if (key == '.' && vitri > 0 && nThuoc->dataT.nongDoHamLuong[vitri - 1] == '.') {
            	continue;
        	}   
			nThuoc->dataT.nongDoHamLuong[vitri] = char(key);
	        nThuoc->dataT.nongDoHamLuong[vitri] = toupper(nThuoc->dataT.nongDoHamLuong[vitri]);
	        cout << nThuoc->dataT.nongDoHamLuong[vitri];
	        vitri++;
	    }
	
	    if (key == BACKSPACE && vitri > 0) {
	        vitri--;
	        gotoXY(42 + vitri, y);
	        cout << " ";
	        gotoXY(42 + vitri, y);
	    }
	
	    if (key == ENTER && vitri != 0) {
	        if (nThuoc->dataT.nongDoHamLuong[vitri - 1] == ' ') {
	            vitri--;
	        }
	        if (nThuoc->dataT.nongDoHamLuong[vitri - 1] == '.') {
	            vitri--;
	        }
	        nThuoc->dataT.nongDoHamLuong[vitri] = '\0';
	        vitri = 0;
	        gotoXY(54 + vitri, y);
	        goto NOISANXUAT;
	    }
	
	    if (key == ESC) {
	        return;
	    }
	}
NOISANXUAT:
	while (1)
	{
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		TextColor(12); gotoXY(54 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			nThuoc->dataT.noiSanXuat[vitri] = char(key);
			nThuoc->dataT.noiSanXuat[vitri] = toupper(nThuoc->dataT.noiSanXuat[vitri]);
			cout << nThuoc->dataT.noiSanXuat[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(54 + vitri, y);
			cout << " ";
			gotoXY(54 + vitri, y);
		}
		if (key == SPACE && nThuoc->dataT.noiSanXuat[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(54 + vitri, y);
			cout << " ";
			nThuoc->dataT.noiSanXuat[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nThuoc->dataT.noiSanXuat[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nThuoc->dataT.noiSanXuat[vitri] = '\0';
			vitri = 0;
			gotoXY(86 + vitri, y);
			goto DONVITINH;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
DONVITINH:
	while(1)
    {
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 7 ";
		TextColor(12); gotoXY(86 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 7))
		{
			nThuoc->dataT.donViTinh[vitri] = key;
			nThuoc->dataT.donViTinh[vitri] = toupper(nThuoc->dataT.donViTinh[vitri]);
			cout << nThuoc->dataT.donViTinh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(86 + vitri, y);
			cout << " ";
			gotoXY(86 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (nThuoc->dataT.donViTinh[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nThuoc->dataT.donViTinh[vitri] = '\0';
			nThuoc->dataT.hanDung.ngay = 0;
			nThuoc->dataT.hanDung.thang = 0;
			nThuoc->dataT.hanDung.nam = 0;
			vitri = 0;
			gotoXY(95 + vitri, y);
			goto HANDUNG;
		}

		if (key == ESC ) { 
		return; 
		}
	}	
HANDUNG:
	

		
    while (1) {
        TextColor(250); gotoXY(9, 18);
        cout << "Nhap han su dung (dd/mm/yyyy)";
        TextColor(12); gotoXY(95 + vitri, y);
        key = GetKey();
        if ((key <= '9' && key >= '0' || key == '/') && (vitri < 10)) {
            if (key != '/') {
   				if (vitri < 2) {
       				nThuoc->dataT.hanDung.ngay = nThuoc->dataT.hanDung.ngay * 10 + (key - '0');
    			} else if (vitri < 5) {
        			nThuoc->dataT.hanDung.thang = nThuoc->dataT.hanDung.thang * 10 + (key - '0');
    			} else {
        			nThuoc->dataT.hanDung.nam = nThuoc->dataT.hanDung.nam * 10 + (key - '0');
    			}
			}
            cout <<(char)key;
            vitri++;
        }
        if (key == BACKSPACE && vitri > 0) {
            vitri--;
            gotoXY(95 + vitri, y);
            cout << " ";
            gotoXY(95 + vitri, y);
            if (vitri < 2) {
                nThuoc->dataT.hanDung.ngay = nThuoc->dataT.hanDung.ngay / 10;  // Remove the last digit
            } else if (vitri < 5) {
                nThuoc->dataT.hanDung.thang = nThuoc->dataT.hanDung.thang / 10;
            } else {
                nThuoc->dataT.hanDung.nam = nThuoc->dataT.hanDung.nam / 10;
            }
        }
        if (key == ENTER && vitri == 10) {  			
			int ngay = nThuoc->dataT.hanDung.ngay;
   			int thang = nThuoc->dataT.hanDung.thang;
    		int nam = nThuoc->dataT.hanDung.nam;
    		gotoXY(70, 18);
    		cout << nThuoc->dataT.hanDung.ngay;
    		gotoXY(75, 18);
    		cout << nThuoc->dataT.hanDung.thang;
    		gotoXY(80, 18);
    		cout << nThuoc->dataT.hanDung.nam;
            if (!isValidDate(ngay, thang, nam)) {
                TextColor(78);
                gotoXY(9, 19);
                cout << "Ngay Thang Nam khong hop le. Nhap lai!";
                Sleep(2000);
                TextColor(228);
                gotoXY(9, 19);
                cout << "                                                  ";
				goto HANDUNG;
            }else if (isDateLessThanCurrent(ngay, thang, nam)) {
                TextColor(78);
                gotoXY(9, 19);
                cout << "Ngay Thang Nam nho hon ngay hien tai. Nhap lai!";
                Sleep(2000);
                gotoXY(9, 19);
                TextColor(228);
                cout << "                                                  ";
				goto HANDUNG;
			}else {
				treeThuoc->rootT = treeThuoc->insertT(treeThuoc->rootT, nThuoc);
        		GhiChu("THEM THUOC THANH CONG. F2 DE LUU", 35, 27, 79, 1000);
        		break;
			}	
        	
    }
        if (key == ESC) {
            return;
        }
    }

}	

void Thuoc_Sua(TreeThuoc *treeThuoc)
{
    int key, vitri = 0, x = 33, y = 17;
	NodeT *nThuoc;
	Thuoc thuoc;
	Thuoc_KhungMenuSua(); gotoXY(x, y);
MATHUOC:
    while(1)
    {
		TextColor(250);	gotoXY(30, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(35 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			thuoc.maThuoc[vitri] = char(key);
			thuoc.maThuoc[vitri] = toupper(thuoc.maThuoc[vitri]);
			cout << thuoc.maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35 + vitri, y);
			cout << " ";
			gotoXY(35 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			thuoc.maThuoc[vitri] = '\0';
			nThuoc = treeThuoc->searchT(treeThuoc->rootT, thuoc.maThuoc);
			if (nThuoc) {
				Thuoc_KhungSua();
				x = 20, y =17;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(20, 17); cout<<nThuoc->dataT.tenThuoc;
				gotoXY(42, 17); cout<<nThuoc->dataT.nongDoHamLuong;
				gotoXY(54, 17); cout<<nThuoc->dataT.noiSanXuat;
				gotoXY(86, 17); cout<<nThuoc->dataT.donViTinh;
				gotoXY(95, 17); cout<<nThuoc->dataT.hanDung.ngay<<"/"<<nThuoc->dataT.hanDung.thang<<"/"<<nThuoc->dataT.hanDung.nam;
				vitri = strlen(nThuoc->dataT.tenThuoc);
				goto TENTHUOC;
				break;;
			}
			else{
				GhiChu("MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				Sleep(1000);
				continue;
			}
		}

		if (key == ESC ) { 
		return; 
		}
	}
TENTHUOC:
	while (1)
	{
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 20";
		TextColor(12); gotoXY(20 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 20))
		{
			nThuoc->dataT.tenThuoc[vitri] = char(key);
			nThuoc->dataT.tenThuoc[vitri] = toupper(nThuoc->dataT.tenThuoc[vitri]);
			cout << nThuoc->dataT.tenThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(20 + vitri, y);
			cout << " ";
			gotoXY(20 + vitri, y);
		}
		if (key == SPACE && nThuoc->dataT.tenThuoc[vitri - 1] != ' ' && vitri > 0 && vitri < 20) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(20 + vitri, y);
			cout << " ";
			nThuoc->dataT.tenThuoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nThuoc->dataT.tenThuoc[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nThuoc->dataT.tenThuoc[vitri] = '\0';
			goto NONGDOHAMLUONG;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
NONGDOHAMLUONG:
	vitri = strlen(nThuoc->dataT.nongDoHamLuong);
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 10 ";
		TextColor(12); gotoXY(42 + vitri, y);
		key = GetKey();
		if ((key <= '9' && key >= '0' || key =='.') && (vitri < 10))
		{   
	    	if (vitri == 0 && key == '.'){
	        	continue;
    		}
			if (key == '.' && vitri > 0 && nThuoc->dataT.nongDoHamLuong[vitri - 1] == '.') {
            	continue;
        	}   
			nThuoc->dataT.nongDoHamLuong[vitri] = char(key);
	        nThuoc->dataT.nongDoHamLuong[vitri] = toupper(nThuoc->dataT.nongDoHamLuong[vitri]);
	        cout << nThuoc->dataT.nongDoHamLuong[vitri];
	        vitri++;
	    }
	
	    if (key == BACKSPACE && vitri > 0) {
	        vitri--;
	        gotoXY(42 + vitri, y);
	        cout << " ";
	        gotoXY(42 + vitri, y);
	    }
	
	    if (key == ENTER && vitri != 0) {
	        if (nThuoc->dataT.nongDoHamLuong[vitri - 1] == ' ') {
	            vitri--;
	        }
	        if (nThuoc->dataT.nongDoHamLuong[vitri - 1] == '.') {
	            vitri--;
	        }
	        nThuoc->dataT.nongDoHamLuong[vitri] = '\0';
	        vitri = 0;
	        gotoXY(54 + vitri, y);
	        goto NOISANXUAT;
	    }
	}
NOISANXUAT:
	vitri = strlen(nThuoc->dataT.noiSanXuat);
	while (1)
	{
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 30";
		TextColor(12); gotoXY(54 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			nThuoc->dataT.noiSanXuat[vitri] = char(key);
			nThuoc->dataT.noiSanXuat[vitri] = toupper(nThuoc->dataT.noiSanXuat[vitri]);
			cout << nThuoc->dataT.noiSanXuat[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(54 + vitri, y);
			cout << " ";
			gotoXY(54 + vitri, y);
		}
		if (key == SPACE && nThuoc->dataT.noiSanXuat[vitri - 1] != ' ' && vitri > 0 && vitri < 30) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(54 + vitri, y);
			cout << " ";
			nThuoc->dataT.noiSanXuat[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nThuoc->dataT.noiSanXuat[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nThuoc->dataT.noiSanXuat[vitri] = '\0';
			goto DONVITINH;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
DONVITINH:
	vitri = strlen(nThuoc->dataT.donViTinh);
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 7 ";
		TextColor(12); gotoXY(86 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 7))
		{
			nThuoc->dataT.donViTinh[vitri] = char(key);
			nThuoc->dataT.donViTinh[vitri] = toupper(nThuoc->dataT.donViTinh[vitri]);
			cout << nThuoc->dataT.donViTinh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(86 + vitri, y);
			cout << " ";
			gotoXY(86 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (nThuoc->dataT.donViTinh[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nThuoc->dataT.donViTinh[vitri] = '\0';
			goto HANDUNG;
		}

		if (key == ESC ) { 
		return; 
		}
	}	
HANDUNG:
	vitri = 10;
//	vitri = 0;
//	nThuoc->dataT.hanDung.ngay =0;
//   	nThuoc->dataT.hanDung.thang=0;
//    nThuoc->dataT.hanDung.nam=0;
    while (1) {
        TextColor(250); gotoXY(20, 18);
        cout << "Nhap han su dung (dd/mm/yyyy)";
        TextColor(12); gotoXY(95 + vitri, y);
        key = GetKey();
        if ((key <= '9' && key >= '0' || key == '/') && (vitri < 10)) {
            if (key != '/') {
   				if (vitri < 2) {
       				nThuoc->dataT.hanDung.ngay = nThuoc->dataT.hanDung.ngay * 10 + (key - '0');
    			} else if (vitri < 5) {
        			nThuoc->dataT.hanDung.thang = nThuoc->dataT.hanDung.thang * 10 + (key - '0');
    			} else {
        			nThuoc->dataT.hanDung.nam = nThuoc->dataT.hanDung.nam * 10 + (key - '0');
    			}
			}
            cout <<(char)key;
            vitri++;
        }
        if (key == BACKSPACE && vitri > 0) {
            vitri--;
            gotoXY(95 + vitri, y);
            cout << " ";
            gotoXY(95 + vitri, y);
            if (vitri < 2) {
                nThuoc->dataT.hanDung.ngay = nThuoc->dataT.hanDung.ngay / 10;  // Remove the last digit
            } else if (vitri < 5) {
                nThuoc->dataT.hanDung.thang = nThuoc->dataT.hanDung.thang / 10;
            } else {
                nThuoc->dataT.hanDung.nam = nThuoc->dataT.hanDung.nam / 10;
            }
        }
        if (key == ENTER && vitri == 10) { 
		 			
    		int ngay = nThuoc->dataT.hanDung.ngay;
   			int thang = nThuoc->dataT.hanDung.thang;
    		int nam = nThuoc->dataT.hanDung.nam;		
        	gotoXY(70, 18);
    		cout << nThuoc->dataT.hanDung.ngay;
    		gotoXY(75, 18);
    		cout << nThuoc->dataT.hanDung.thang;
    		gotoXY(80, 18);
    		cout << nThuoc->dataT.hanDung.nam;

            if (!isValidDate(ngay, thang, nam)) {
                TextColor(78);
                gotoXY(20, 19);
                cout << "Ngay Thang Nam khong hop le. Nhap lai!";
                Sleep(2000);
                TextColor(228);
                gotoXY(20, 19);
                cout << "                                                  ";
				continue;
            }else if (isDateLessThanCurrent(ngay, thang, nam)) {
                TextColor(78);
                gotoXY(20, 19);
                cout << "Ngay Thang Nam nho hon ngay hien tai. Nhap lai!";
                Sleep(2000);
                gotoXY(20, 19);
                TextColor(228);
                cout << "                                                  ";
				continue;
			}else {
				
        		GhiChu("SUA THUOC THANH CONG. F2 DE LUU", 35, 27, 79, 1000);
        		break;
			}	
        	
    }
        if (key == ESC) {
            return;
        }
    }

}

void Thuoc_Xoa(TreeThuoc *treeThuoc, ListCTPN *listCTPN, ListDL *listDL,LinkListDKK *listDKK, LinkListDX *listDX )
{

	int key, vitri = 0, x = 33, y = 17;
	bool checkMa_Thuoc_CTPN,  checkMaThuoc, checkMaThuoc_DKK, checkMaThuoc_DLinh, checkMaThuoc_DXuat;
	char maThuoc[10];
QuayLai:
	vitri = 0; Thuoc_KhungMenuXoa(); gotoXY(35, 17);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			maThuoc[vitri] = char(key);
			maThuoc[vitri] = toupper(maThuoc[vitri]);
			cout<< maThuoc[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			maThuoc[vitri] = '\0';
			checkMaThuoc = treeThuoc->CheckMaThuoc(treeThuoc->rootT, maThuoc);
			checkMa_Thuoc_CTPN = listCTPN->checkMaThuoc(listCTPN->pHead, maThuoc);
			checkMaThuoc_DKK = listDKK->CheckFKDKK_mathuoc(maThuoc);
			checkMaThuoc_DLinh = listDL->checkMaThuoc(listDL->pHead, maThuoc);
			checkMaThuoc_DXuat = listDX->CheckFKDX_mathuoc(maThuoc);
			if(checkMaThuoc == true)
			{
				if(checkMa_Thuoc_CTPN == true)
				{
					GhiChu("KHONG THE XOA VI MA THUOC DA CO TRONG CTPN!!!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y); 
					goto QuayLai;
				}
				else if(checkMaThuoc_DKK == true)
				{
					GhiChu("KHONG THE XOA VI MA THUOC DA CO TRONG DONG KIEM KE!!!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y); 
					goto QuayLai;
				}
				else if(checkMaThuoc_DLinh == true)
				{
					GhiChu("KHONG THE XOA VI MA THUOC DA CO TRONG DONG LINH!!!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y); 
					goto QuayLai;
				}
				else if(checkMaThuoc_DXuat == true)
				{
					GhiChu("KHONG THE XOA VI MA THUOC DA CO TRONG DONG XUAT!!!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y); 
					goto QuayLai;
				}
				else
				{
					//xoaKhungNhap();
//				khungThongTin();
//				
//				gotoXY(50, 18); cout << "THONG TIN HANG THUOC MUON XOA ";
//				TextColor(14);
//				gotoXY(34, 20); cout << "Ma Hang Thuoc			: " << nHT->dataHT.maHT;
//				gotoXY(34, 21); cout << "Ten Hang Thuoc		: " << nHT->dataHT.tenHT;
//				gotoXY(34, 22); cout << "SDT				: " << nHT->dataHT.sdt;
//				gotoXY(34, 23);	cout << "Dia Chi			: " << nHT->dataHT.diaChi;
//				gotoXY(34, 24); cout << "MST				: " << nHT->dataHT.maSoThue;
					int tamp = ThongBao_HuyThuoc();
					if(tamp == true){
						
						treeThuoc->rootT = treeThuoc->deleteNodeT(treeThuoc->rootT, maThuoc);
						GhiChu("XOA THUOC THANH CONG!", 35, 27, 79, 2000);
						gotoXY(33 + vitri, y);
						break;
					}
					else{
						GhiChu("XOA THUOC KHONG THANH CONG!!!", 35, 27, 79, 2000);
						return;
					}	
				}
			}
			else
			{
				GhiChu("MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				goto QuayLai;
			}
					
			}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35 + vitri, y);
			cout<<" ";
			gotoXY(35 + vitri, y);
		}
		
		if(key == ESC){
			return;
		}
	}
}

//===============PHIEU NHAP==============
void Date_PN(NodePN *nPN)
{
	date currentDate = getCurrentDate();
    nPN->dataPN.ngayNhap.ngay= currentDate.ngay ;
    nPN->dataPN.ngayNhap.thang = currentDate.thang;
    nPN->dataPN.ngayNhap.nam = currentDate.nam;
}
void PN_Them(TreePN *treePN, TreeHT *treeHT, TreeNV *treeNV)
{
	int key, vitri = 0, x = 9, y = 17, checkMaNV;
	bool checkMaHT;
	NodePN *nPN ;
	NodeNV *nNV;
	PhieuNhap phieunhap;
	PhieuNhap_KhungThem(); gotoXY(x, y);
SOPHIEUNHAP:
	while(1)
    {
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(9 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			phieunhap.soPhieuNhap[vitri] = char(key);
			phieunhap.soPhieuNhap[vitri] = toupper(phieunhap.soPhieuNhap[vitri]);
			cout << phieunhap.soPhieuNhap[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(9 + vitri, y);
			cout << " ";
			gotoXY(9 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			phieunhap.soPhieuNhap[vitri] = '\0';
			nPN = treePN->searchPN(treePN->rootPN, phieunhap.soPhieuNhap);
			if (nPN) {
				TextColor(78);	gotoXY(9, 18);
				cout << "Trung So Phieu Nhap. Nhap Lai!";
				Sleep(500);
				continue;
			}
			nPN = treePN->taoNodePN(phieunhap);
			strcpy(nPN->dataPN.soPhieuNhap, phieunhap.soPhieuNhap);
			goto MANV;
		}

		if (key == ESC ) { 
		return; 
		}
	}
MANV:
	vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(20 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nPN->dataPN.maNV[vitri] = char(key);
			nPN->dataPN.maNV[vitri] = toupper(nPN->dataPN.maNV[vitri]);
			cout << nPN->dataPN.maNV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(20 + vitri, y);
			cout << " ";
			gotoXY(20 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (nPN->dataPN.maNV[vitri - 1] == ' ') { vitri--; }
			nPN->dataPN.maNV[vitri] = '\0';
			nNV = treeNV->FindNodeNV(treeNV->root, nPN->dataPN.maNV);
			if(nNV)
			{
				vitri = 0;
				gotoXY(31 + vitri, y);
				TextColor(206);
				gotoXY(20 + vitri, 19);
				cout<<nNV->data.hoTen;
				goto MAHT;
			}
			else{
                GhiChu("MA NHAN VIEN CHUA CO. NHAP LAI!", 35, 27, 79, 1000);
                Sleep(1000);
                gotoXY(9, 18);
                TextColor(228);
                cout << "                                                  ";
                gotoXY(20 + vitri, y);
                continue;
            	
			}
			
		}

		if (key == ESC ) { 
		return; 
		}
	}
MAHT:
	vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(31 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nPN->dataPN.maHT[vitri] = char(key);
			nPN->dataPN.maHT[vitri] = toupper(nPN->dataPN.maHT[vitri]);
			cout << nPN->dataPN.maHT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(31 + vitri, y);
			cout << " ";
			gotoXY(31 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			nPN->dataPN.maHT[vitri] = '\0';
			checkMaHT =treeHT->CheckMaHT(treeHT->rootHT, nPN->dataPN.maHT);
//			gotoXY(30, 19);
//			cout << nPN->dataPN.maHT;
            if(checkMaHT == true)
            {
            	vitri = 0;
            	gotoXY(43 + vitri, y);
            	TextColor(206);
            	gotoXY(30 + vitri, 19);
            	NodeHT *check;
            	check = treeHT->searchHT(treeHT->rootHT, nPN->dataPN.maHT);
            	cout << check->dataHT.tenHT;
                Date_PN(nPN);
				goto TENKHO;
            }
            else{
                GhiChu("MA HANG THUOC CHUA CO TRONG HANG THUOC. NHAP LAI!", 35, 27, 79, 1000);
                Sleep(1000);
                gotoXY(9, 18);
                TextColor(228);
                cout << "                                                  ";
                gotoXY(31 + vitri, y);
                continue;
            	
			}	
		}

		if (key == ESC ) { 
		return; 
		}
	}	
TENKHO:
	//vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 25 ";
		TextColor(12); gotoXY(43 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 25))
		{
			nPN->dataPN.tenKhoNhapThuoc[vitri] = char(key);
			nPN->dataPN.tenKhoNhapThuoc[vitri] = toupper(nPN->dataPN.tenKhoNhapThuoc[vitri]);
			cout << nPN->dataPN.tenKhoNhapThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE &&  vitri > 0 )
		{
			vitri--;
			gotoXY(43 + vitri, y);
			cout << " ";
			gotoXY(43 + vitri, y);
		}
		if (key == SPACE && nPN->dataPN.tenKhoNhapThuoc[vitri - 1] != ' ' && vitri > 0 && vitri < 25)
		{
			gotoXY(43 + vitri, y);
			cout << " ";
			nPN->dataPN.tenKhoNhapThuoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nPN->dataPN.tenKhoNhapThuoc[vitri - 1] == ' ') { vitri--; }
			nPN->dataPN.tenKhoNhapThuoc[vitri] = '\0';
			goto DIADIEM;
		}

		if (key == ESC ) { 
		return; 
		}
	}
DIADIEM:
	vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(9, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 30 ";
		TextColor(12); gotoXY(75 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			nPN->dataPN.diaDiemNhap[vitri] = char(key);
			nPN->dataPN.diaDiemNhap[vitri] = toupper(nPN->dataPN.diaDiemNhap[vitri]);
			cout << nPN->dataPN.diaDiemNhap[vitri];
			vitri++;
		}
		if (key == BACKSPACE &&  vitri > 0 )
		{
			vitri--;
			gotoXY(75 + vitri, y);
			cout << " ";
			gotoXY(75 + vitri, y);
		}
		if (key == SPACE && nPN->dataPN.diaDiemNhap[vitri - 1] != ' ' && vitri > 0 && vitri < 30)
		{
			gotoXY(75 + vitri, y);
			cout << " ";
			nPN->dataPN.diaDiemNhap[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nPN->dataPN.diaDiemNhap[vitri - 1] == ' ') { vitri--; }
			nPN->dataPN.diaDiemNhap[vitri] = '\0';
			treePN->rootPN = treePN->insertPN(treePN->rootPN, nPN);
			GhiChu("THEM PHIEU NHAP THANH CONG. F2 DE LUU", 35, 27, 79, 1000);
			return;
		}

		if (key == ESC ) { 
		return; 
		}
	}		
}

void PN_Sua(TreePN *treePN, TreeHT *treeHT, TreeNV *treeNV)
{
	int key, vitri = 0, x = 33, y = 17;
	bool checkMaHT;
	NodePN *nPN;
	NodeNV *nNV;
	PhieuNhap phieunhap;
	PhieuNhap_KhungMenuSua(); gotoXY(x, y);
SOPHIEUNHAP:
	while(1)
    {
		TextColor(250);	gotoXY(30, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(35 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			phieunhap.soPhieuNhap[vitri] = char(key);
			phieunhap.soPhieuNhap[vitri] = toupper(phieunhap.soPhieuNhap[vitri]);
			cout << phieunhap.soPhieuNhap[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35 + vitri, y);
			cout << " ";
			gotoXY(35 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			phieunhap.soPhieuNhap[vitri] = '\0';
			nPN = treePN->searchPN(treePN->rootPN, phieunhap.soPhieuNhap);
			if (nPN) {
				PhieuNhap_KhungSua();
				x = 20, y =17;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(20, 17); cout<<nPN->dataPN.maNV;
				gotoXY(31, 17); cout<<nPN->dataPN.maHT;
//				gotoXY(20, 17); cout<<nPN->dataPN.ngayNhap;
				gotoXY(43, 17); cout<<nPN->dataPN.tenKhoNhapThuoc;
				gotoXY(75, 17); cout<<nPN->dataPN.diaDiemNhap;
				vitri = strlen(nPN->dataPN.maNV);
				goto MANV;
				break;
			}
			else{
				GhiChu("SO PHIEU KHONG TON TAI!", 35, 27, 79, 1000);
				Sleep(1000);
				continue;
			}
		}

		if (key == ESC ) { 
		return; 
		}
	}
MANV:
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(20 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nPN->dataPN.maNV[vitri] = char(key);
			nPN->dataPN.maNV[vitri] = toupper(nPN->dataPN.maNV[vitri]);
			cout << nPN->dataPN.maNV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(20 + vitri, y);
			cout << " ";
			gotoXY(20 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			if (nPN->dataPN.maNV[vitri - 1] == ' ') { vitri--; }
			nPN->dataPN.maNV[vitri] = '\0';
			nNV = treeNV->FindNodeNV(treeNV->root, nPN->dataPN.maNV);
			if(nNV)
			{
				vitri = 0;
				gotoXY(31 + vitri, y);
				TextColor(206);
				gotoXY(20 + vitri, 19);
				cout<<nNV->data.hoTen;
				goto MAHT;
			}
			else{
                GhiChu("MA NHAN VIEN CHUA CO. NHAP LAI!", 35, 27, 79, 1000);
                Sleep(1000);
                gotoXY(9, 18);
                TextColor(228);
                cout << "                                                  ";
                gotoXY(20 + vitri, y);
                continue;
            	
			}
		}

		if (key == ESC ) { 
		return; 
		}
	}
MAHT:
	vitri = strlen(nPN->dataPN.maHT);
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(31 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nPN->dataPN.maHT[vitri] = char(key);
			nPN->dataPN.maHT[vitri] = toupper(nPN->dataPN.maHT[vitri]);
			cout << nPN->dataPN.maHT[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(31 + vitri, y);
			cout << " ";
			gotoXY(31 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			nPN->dataPN.maHT[vitri] = '\0';
			checkMaHT =treeHT->CheckMaHT(treeHT->rootHT, nPN->dataPN.maHT);
			//	cout << (checkMaHT ? "true" : "false");
            if(checkMaHT == true)
            {
            	vitri = 0;
            	gotoXY(43 + vitri, y);
            	TextColor(206);
            	gotoXY(30 + vitri, 18);
            	NodeHT *check;
            	check = treeHT->searchHT(treeHT->rootHT, nPN->dataPN.maHT);
            	cout << check->dataHT.tenHT;
                Date_PN(nPN);
				goto TENKHO;
            }
            else{
            	GhiChu("MA HANG THUOC CHUA CO TRONG HANG THUOC. NHAP LAI!", 35, 27, 79, 1000);
                Sleep(1000);
                gotoXY(31 + vitri, y);
                continue;     	
			}		
		}

		if (key == ESC ) { 
		return; 
		}
	}	
TENKHO:
	vitri = strlen(nPN->dataPN.tenKhoNhapThuoc);
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 25 ";
		TextColor(12); gotoXY(43 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 25))
		{
			nPN->dataPN.tenKhoNhapThuoc[vitri] = char(key);
			nPN->dataPN.tenKhoNhapThuoc[vitri] = toupper(nPN->dataPN.tenKhoNhapThuoc[vitri]);
			cout << nPN->dataPN.tenKhoNhapThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE &&  vitri > 0 )
		{
			vitri--;
			gotoXY(43 + vitri, y);
			cout << " ";
			gotoXY(43 + vitri, y);
		}
		if (key == SPACE && nPN->dataPN.tenKhoNhapThuoc[vitri - 1] != ' ' && vitri > 0 && vitri < 25)
		{
			gotoXY(43 + vitri, y);
			cout << " ";
			nPN->dataPN.tenKhoNhapThuoc[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nPN->dataPN.tenKhoNhapThuoc[vitri - 1] == ' ') { vitri--; }
			nPN->dataPN.tenKhoNhapThuoc[vitri] = '\0';
			goto DIADIEM;
		}

		if (key == ESC ) { 
		return; 
		}
	}
DIADIEM:
	vitri = strlen(nPN->dataPN.diaDiemNhap);
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 30 ";
		TextColor(12); gotoXY(75 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 30))
		{
			nPN->dataPN.diaDiemNhap[vitri] = char(key);
			nPN->dataPN.diaDiemNhap[vitri] = toupper(nPN->dataPN.diaDiemNhap[vitri]);
			cout << nPN->dataPN.diaDiemNhap[vitri];
			vitri++;
		}
		if (key == BACKSPACE &&  vitri > 0 )
		{
			vitri--;
			gotoXY(75 + vitri, y);
			cout << " ";
			gotoXY(75 + vitri, y);
		}
		if (key == SPACE && nPN->dataPN.diaDiemNhap[vitri - 1] != ' ' && vitri > 0 && vitri < 30)
		{
			gotoXY(92 + vitri, y);
			cout << " ";
			nPN->dataPN.diaDiemNhap[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nPN->dataPN.diaDiemNhap[vitri - 1] == ' ') { vitri--; }
			nPN->dataPN.diaDiemNhap[vitri] = '\0';
			GhiChu("SUA PHIEU NHAP THANH CONG. F2 DE LUU", 35, 27, 79, 1000);
			break;
		}

		if (key == ESC ) { 
		return; 
		}
	}		
}

void PN_Xoa(TreePN *treePN, ListCTPN *CTPN)
{
	int key, vitri = 0, x = 33, y = 17;
	bool checkSoPhieu_CTPN,  checkSoPhieu;
	char soPhieu[10];
QuayLai:
	vitri = 0; PhieuNhap_KhungMenuXoa(); gotoXY(35, 17);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			soPhieu[vitri] = char(key);
			soPhieu[vitri] = toupper(soPhieu[vitri]);
			cout<< soPhieu[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			soPhieu[vitri] = '\0';
			checkSoPhieu = treePN->CheckMaPN(treePN->rootPN, soPhieu);
			checkSoPhieu_CTPN = CTPN->checkSoPhieu(CTPN->pHead, soPhieu);
			if(checkSoPhieu == true)
			{
				if(checkSoPhieu_CTPN==true)
				{
					GhiChu("KHONG THE XOA VI SO PHIEU DA CO TRONG CTPN!!!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y); 
					goto QuayLai;
				}
				else
				{
		//			xoaKhungNhap();
//					khungThongTin();
//				
//					gotoXY(50, 18); cout << "THONG TIN HANG THUOC MUON XOA ";
//					TextColor(14);
//					gotoXY(34, 20); cout << "Ma Hang Thuoc			: " << nHT->dataHT.maHT;
//					gotoXY(34, 21); cout << "Ten Hang Thuoc		: " << nHT->dataHT.tenHT;
//					gotoXY(34, 22); cout << "SDT				: " << nHT->dataHT.sdt;
//					gotoXY(34, 23);	cout << "Dia Chi			: " << nHT->dataHT.diaChi;
//					gotoXY(34, 24); cout << "MST				: " << nHT->dataHT.maSoThue;
					int tamp = ThongBao_HuyPhieuNhap();
					if(tamp == true){
						treePN->rootPN = treePN->deleteNodePN(treePN->rootPN, soPhieu);
						GhiChu("XOA THUOC THANH CONG!", 35, 27, 79, 2000);
						gotoXY(33 + vitri, y);
						break;
					}
					else
					{
						GhiChu("XOA THUOC KHONG THANH CONG!!!", 35, 27, 79, 2000);
						return;
					}
				}
			}
			else
			{
				GhiChu("SO PHIEU KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				goto QuayLai;
			}
					
		}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(35 + vitri, y);
			cout<<" ";
			gotoXY(35 + vitri, y);
		}
		
		if(key == ESC){
			return;
		}
	}
}

//=================CHI TIET PHIEU NHAP==========================

void CTPN_Them(ListCTPN *listCTPN, TreePN *treePN, TreeThuoc *treeThuoc)
{
	int key, vitri = 0, x = 20, y = 17, checkSoPhieu_MaThuoc;
	bool checkMaThuoc;
	NodeCTPN *nCTPN ;
	NodePN *nPN;
	CHITIETPN ctpn;
	CTPhieuNhap_KhungThem(); gotoXY(x, y);
SOPHIEUNHAP:
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(22 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			ctpn.soPhieuNhap[vitri] = char(key);
			ctpn.soPhieuNhap[vitri] = toupper(ctpn.soPhieuNhap[vitri]);
			cout << ctpn.soPhieuNhap[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(22 + vitri, y);
			cout << " ";
			gotoXY(22 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ctpn.soPhieuNhap[vitri] = '\0';
			nPN = treePN->searchPN(treePN->rootPN, ctpn.soPhieuNhap);
			if (!nPN) {
				GhiChu("KHONG TIM THAY SO PHIEU TRONG PHIEU NHAP. NHAP LAI!", 35, 27, 79, 1000);
				Sleep(1000);
//				TextColor(78);	gotoXY(21, 18);
//				cout << "Khong Tim Thay So Phieu Trong PHIEU NHAP. Nhap Lai!";
//				Sleep(500);
//				gotoXY(21, 18);
//                TextColor(228);
//                cout << "                                                     ";
				continue;
			}
//			ctpn = new NodeCTPN();
//			strcpy(ctpn->soLuongNhap, phieunhap.soPhieuNhap);
			goto MATHUOC;
		}

		if (key == ESC ) { 
		return; 
		}
	}
MATHUOC:
	vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(33 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			ctpn.maThuoc[vitri] = char(key);
			ctpn.maThuoc[vitri] = toupper(ctpn.maThuoc[vitri]);
			cout << ctpn.maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ctpn.maThuoc[vitri] = '\0';
			checkMaThuoc =treeThuoc->CheckMaThuoc(treeThuoc->rootT, ctpn.maThuoc);
			checkSoPhieu_MaThuoc = listCTPN->checkTrung2Field(listCTPN->pHead, ctpn.soPhieuNhap, ctpn.maThuoc );
            if(checkMaThuoc == true)
            {
            	vitri = 0;
            	gotoXY(44 + vitri, y);
            	TextColor(206);
            	gotoXY(33 + vitri, 19);
            	NodeT *check;
            	check = treeThuoc->searchT(treeThuoc->rootT, ctpn.maThuoc);
            	cout << check->dataT.tenThuoc;
            	if(checkSoPhieu_MaThuoc == 1)
            	{
            		GhiChu("TRUNG SO PHIEU VA MA THUOC. NHAP LAI", 35, 27, 79, 1000);
					Sleep(1000);
               	 	goto SOPHIEUNHAP; 
				}
				else{
					goto SOLUONG;
				}
				
            }
            else{
            	GhiChu("MA THUOC CHUA CO TRONG THUOC. NHAP LAI!!", 35, 27, 79, 1000);
				Sleep(1000);
                gotoXY(44 + vitri, y);
                continue;
            	
			}	
		}

		if (key == ESC ) { 
		return; 
		}
	}
SOLUONG:
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 10 " ;
		TextColor(12); gotoXY(44 + vitri, y);
		key = GetKey();
		char SoLuong[10];
		if ((key >= '0' && key <= '9') && (vitri < 10))
		{
			SoLuong[vitri] = char(key);
			cout << SoLuong[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(44 + vitri, y);
			cout << " ";
			gotoXY(44 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			SoLuong[vitri] = '\0';
			vitri = 0;
			ctpn.soLuongNhap = atoi(SoLuong);
			gotoXY(58 + vitri, y);
			goto DONGIA;
		}
		if (key == ESC ) { 
		return; 
		}
	}
DONGIA:
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 20 " ;
		TextColor(12); gotoXY(58 + vitri, y);
		key = GetKey();
		char DonGia[20];
		if ((key >= '0' && key <= '9') && (vitri < 20))
		{
			DonGia[vitri] = char(key);
			cout << DonGia[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(58 + vitri, y);
			cout << " ";
			gotoXY(58 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			DonGia[vitri] = '\0';
			ctpn.donGia = atoi(DonGia);
			listCTPN->insertCTPN(listCTPN->pHead, ctpn);
			GhiChu("THEM CHI TIET PHIEU NHAP THANH CONG. F2 DE LUU", 40, 27, 228, 2000);	TextColor(12);
			return;	
		}

		if (key == ESC ) { 
		return; 
		}
	}
}
int numlen(int numb){
	int len = 0;
	while(numb!=0){
		numb/=10;
		++len;
	}
	return len;
}
void CTPN_Sua(ListCTPN *listCTPN, TreePN *treePN, TreeThuoc *treeThuoc)
{
	int key, vitri = 0, x = 25, y = 18;
	bool checkMaThuoc;
	NodeCTPN *nCTPN ;
	NodePN *nPN;
	CHITIETPN ctpn;
	CTPhieuNhap_KhungMenuSua(); gotoXY(x, y);
SOPHIEUNHAP:
	while(1)
    {
		TextColor(250);	gotoXY(36, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(37 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			ctpn.soPhieuNhap[vitri] = char(key);
			ctpn.soPhieuNhap[vitri] = toupper(ctpn.soPhieuNhap[vitri]);
			cout << ctpn.soPhieuNhap[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(37 + vitri, y);
			cout << " ";
			gotoXY( + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ctpn.soPhieuNhap[vitri] = '\0';
			goto MATHUOC;
		}

		if (key == ESC ) { 
		return; 
		}
	}
MATHUOC:
	vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(36, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(53 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			ctpn.maThuoc[vitri] = char(key);
			ctpn.maThuoc[vitri] = toupper(ctpn.maThuoc[vitri]);
			cout << ctpn.maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(53 + vitri, y);
			cout << " ";
			gotoXY(53 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			ctpn.maThuoc[vitri] = '\0';
			checkMaThuoc =treeThuoc->CheckMaThuoc(treeThuoc->rootT, ctpn.maThuoc);
            nCTPN = listCTPN->searchCTPN(listCTPN->pHead, ctpn.soPhieuNhap, ctpn.maThuoc);
			if(checkMaThuoc == true)
            {
            	if(nCTPN != NULL)
            	{
            		CTPhieuNhap_KhungSua();
            		x = 20, y = 17;
					gotoXY(x, y);
					TextColor(14);
					
					gotoXY(22, 17); cout<<nCTPN->dataCTPN.soPhieuNhap;
					gotoXY(33, 17); cout<<nCTPN->dataCTPN.maThuoc;
					gotoXY(44, 17); cout<<nCTPN->dataCTPN.soLuongNhap;
					gotoXY(58, 17); cout<<nCTPN->dataCTPN.donGia;
					vitri = numlen(nCTPN->dataCTPN.soLuongNhap);
					gotoXY(44 + vitri, 17);
               	 	goto SOLUONG; 
               	 	break;
				}
				else{
					GhiChu("SO PHIEU HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
					Sleep(1000);
					goto SOPHIEUNHAP;
				}			
            }
            else{
            	GhiChu("MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				Sleep(1000);
                gotoXY(44 + vitri, y);
                continue;
            	
			}	
		}

		if (key == ESC ) { 
		return; 
		}
	}
SOLUONG:
	char SoLuong[10];
	key = GetKey();
	if(key == ENTER) {
		ctpn.soLuongNhap = nCTPN->dataCTPN.soLuongNhap;
		goto A;
	}
	gotoXY(44, 17); cout << "          "; vitri = 0;
	
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 10 " ;
		TextColor(12); gotoXY(44 + vitri, y);
		key = GetKey();
		
		if ((key >= '0' && key <= '9') && (vitri < 10))
		{
			SoLuong[vitri] = char(key);
			cout << SoLuong[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(44 + vitri, y);
			cout << " ";
			gotoXY(44 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			SoLuong[vitri] = '\0';
			ctpn.soLuongNhap = atoi(SoLuong);
		A:
			vitri = numlen(nCTPN->dataCTPN.donGia);			
			gotoXY(58 + vitri, y);
			goto DONGIA;
		}
		if (key == ESC ) { 
		return; 
		}
	}
DONGIA:
	char DonGia[20];
	key = GetKey();
	if(key == ENTER){
		ctpn.donGia =  nCTPN->dataCTPN.donGia;
		goto B;
	}
	gotoXY(58, 17); cout<<"                    "; vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 20 " ;
		TextColor(12); gotoXY(58 + vitri, y);
		key = GetKey();
		
		if ((key >= '0' && key <= '9') && (vitri < 20))
		{
			DonGia[vitri] = char(key);
			cout << DonGia[vitri];
			
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(58 + vitri, y);
			cout << " ";
			gotoXY(58 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			DonGia[vitri] = '\0';
			ctpn.donGia = atoi(DonGia);
		B:
			nCTPN->dataCTPN = ctpn;					
			GhiChu("SUA CHI TIET PHIEU NHAP THANH CONG. F2 DE LUU", 40, 27, 228, 2000);	TextColor(12);
			return;	
		}

		if (key == ESC ) { 
		return; 
		}
	}
}

void CTPN_Xoa(ListCTPN *listCTPN)
{
	int key, vitri = 0, x = 25, y = 18;
	bool checkSoPhieu;
	NodeCTPN *nCTPN;
	char soPhieu[10], maThuoc[10];
SOPHIEU:
	vitri = 0; CTPhieuNhap_KhungMenuXoa(); gotoXY(37,18);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			soPhieu[vitri] = char(key);
			soPhieu[vitri] = toupper(soPhieu[vitri]);
			cout<< soPhieu[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(37 + vitri, y);
			cout << " ";
			gotoXY(37 + vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			soPhieu[vitri] = '\0';
			goto MATHUOC;
		}
		if (key == ESC ) { return; }
	}
MATHUOC:
	vitri = 0;
	while(1)
	{
		TextColor(250);	gotoXY(36, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(53 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			maThuoc[vitri] = char(key);
			maThuoc[vitri] = toupper(maThuoc[vitri]);
			cout << maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(53 + vitri, y);
			cout << " ";
			gotoXY(53 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			maThuoc[vitri] ='\0';
			nCTPN = listCTPN->searchCTPN(listCTPN->pHead, soPhieu, maThuoc);
			if(!nCTPN)
			{
				GhiChu("SO PHIEU HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				goto SOPHIEU;
			}
			else{
				int tamp = ThongBao_HuyCTPN();
				if(tamp == true){
					listCTPN->deleteInfo(listCTPN->pHead, soPhieu, maThuoc);
					GhiChu("XOA CHI TIET PHIEU NHAP THANH CONG!", 35, 27, 79, 2000);
					gotoXY(33 + vitri, y);
					break;
				}
				else
				{
					GhiChu("XOA CHI TIET PHIEU NHAP KHONG THANH CONG!!!", 35, 27, 79, 2000);
					return;
				}	
			}	
		}
	}
}

//=========================PHAN DONG LINH

void DL_Them(ListDL *listDL, TreePL *treePL, TreeThuoc *treeThuoc)
{
	int key, vitri = 0, x = 20, y = 17, checkSoPhieu_MaThuoc, checkSoPhieu_PL;
	bool checkMaThuoc;
	NodeDL *nDL ;
	NodePL *nPL;
	DongLinh donglinh;
	DongLinh_KhungThem(); gotoXY(x, y);
SOPHIEULINH:
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(22 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			donglinh.soPhieuLinh[vitri] = char(key);
			donglinh.soPhieuLinh[vitri] = toupper(donglinh.soPhieuLinh[vitri]);
			cout << donglinh.soPhieuLinh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(22 + vitri, y);
			cout << " ";
			gotoXY(22 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			donglinh.soPhieuLinh[vitri] = '\0';
			checkSoPhieu_PL = treePL->CoincideMaPL(treePL->root, donglinh.soPhieuLinh);
			if (!checkSoPhieu_PL) {
				GhiChu("KHONG TIM THAY SO PHIEU TRONG PHIEU LINH. NHAP LAI!", 35, 27, 79, 1000);
				Sleep(1000);
				continue;
			}
			goto MATHUOC;
		}

		if (key == ESC ) { 
		return; 
		}
	}
MATHUOC:
	vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(20, 18);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(33 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			donglinh.maThuoc[vitri] = char(key);
			donglinh.maThuoc[vitri] = toupper(donglinh.maThuoc[vitri]);
			cout << donglinh.maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout << " ";
			gotoXY(33 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			donglinh.maThuoc[vitri] = '\0';
			checkMaThuoc =treeThuoc->CheckMaThuoc(treeThuoc->rootT, donglinh.maThuoc);
			checkSoPhieu_MaThuoc = listDL->checkTrung2Field(listDL->pHead, donglinh.soPhieuLinh, donglinh.maThuoc );
            if(checkMaThuoc == true)
            {
            	vitri = 0;
            	gotoXY(44 + vitri, y);
            	TextColor(206);
            	gotoXY(33 + vitri, 19);
            	NodeT *check;
            	check = treeThuoc->searchT(treeThuoc->rootT, donglinh.maThuoc);
            	cout << check->dataT.tenThuoc;
            	if(checkSoPhieu_MaThuoc == 1)
            	{
            		GhiChu("TRUNG SO PHIEU VA MA THUOC. NHAP LAI", 35, 27, 79, 1000);
					Sleep(1000);
               	 	goto SOPHIEULINH; 
				}
				else{
					goto SLYEUCAU;
				}
				
            }
            else{
            	GhiChu("MA THUOC CHUA CO TRONG THUOC. NHAP LAI!!", 35, 27, 79, 1000);
				Sleep(1000);
                gotoXY(44 + vitri, y);
                continue;
            	
			}	
		}

		if (key == ESC ) { 
		return; 
		}
	}
SLYEUCAU:
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 10 " ;
		TextColor(12); gotoXY(44 + vitri, y);
		key = GetKey();
		char slyeucau[10];
		if ((key >= '0' && key <= '9') && (vitri < 10))
		{
			slyeucau[vitri] = char(key);
			cout << slyeucau[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(44 + vitri, y);
			cout << " ";
			gotoXY(44 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			slyeucau[vitri] = '\0';
			vitri = 0;
			donglinh.slYeuCau= atoi(slyeucau);
			gotoXY(58 + vitri, y);
			goto SLCAPPHAT;
		}
		if (key == ESC ) { 
		return; 
		}
	}
SLCAPPHAT:
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 20 " ;
		TextColor(12); gotoXY(58 + vitri, y);
		key = GetKey();
		char slcapphat[20];
		if ((key >= '0' && key <= '9') && (vitri < 20))
		{
			slcapphat[vitri] = char(key);
			cout << slcapphat[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(58 + vitri, y);
			cout << " ";
			gotoXY(58 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			slcapphat[vitri] = '\0';
			donglinh.slCapPhat = atoi(slcapphat);
			listDL->insertDL(listDL->pHead, donglinh);
			GhiChu("THEM DONG LINH THANH CONG. F2 DE LUU", 40, 27, 228, 2000);	TextColor(12);
			return;	
		}

		if (key == ESC ) { 
		return; 
		}
	}
}

void DL_Sua(ListDL *listDL, TreeThuoc *treeThuoc)
{
	int key, vitri = 0, x = 25, y = 18;
	bool checkMaThuoc;
	NodeDL *nDL ;
	DongLinh donglinh;
	DongLinh_KhungMenuSua(); gotoXY(x, y);
SOPHIEUNHAP:
	while(1)
    {
		TextColor(250);	gotoXY(36, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(37 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			donglinh.soPhieuLinh[vitri] = char(key);
			donglinh.soPhieuLinh[vitri] = toupper(donglinh.soPhieuLinh[vitri]);
			cout << donglinh.soPhieuLinh[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(37 + vitri, y);
			cout << " ";
			gotoXY( + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			donglinh.soPhieuLinh[vitri] = '\0';
			goto MATHUOC;
		}

		if (key == ESC ) { 
		return; 
		}
	}
MATHUOC:
	vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(36, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(53 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			donglinh.maThuoc[vitri] = char(key);
			donglinh.maThuoc[vitri] = toupper(donglinh.maThuoc[vitri]);
			cout << donglinh.maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(53 + vitri, y);
			cout << " ";
			gotoXY(53 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			donglinh.maThuoc[vitri] = '\0';
			checkMaThuoc =treeThuoc->CheckMaThuoc(treeThuoc->rootT, donglinh.maThuoc);
            nDL = listDL->searchDL(listDL->pHead, donglinh.soPhieuLinh, donglinh.maThuoc);
			if(checkMaThuoc == true)
            {
            	if(nDL != NULL)
            	{
            		DongLinh_KhungSua();
            		x = 20, y = 17;
					gotoXY(x, y);
					TextColor(14);
					
					gotoXY(22, 17); cout<<nDL->dataDL.soPhieuLinh;
					gotoXY(33, 17); cout<<nDL->dataDL.maThuoc;
					gotoXY(44, 17); cout<<nDL->dataDL.slYeuCau;
					gotoXY(58, 17); cout<<nDL->dataDL.slCapPhat;
					vitri = numlen(nDL->dataDL.slYeuCau);
					gotoXY(44 + vitri, 17);
               	 	goto SLYEUCAU; 
               	 	break;
				}
				else{
					GhiChu("SO PHIEU HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
					Sleep(1000);
					goto SOPHIEUNHAP;
				}			
            }
            else{
            	GhiChu("MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				Sleep(1000);
                gotoXY(44 + vitri, y);
                continue;
            	
			}	
		}

		if (key == ESC ) { 
		return; 
		}
	}
SLYEUCAU:
	char slyeucau[10];
	key = GetKey();
	if(key == ENTER) {
		donglinh.slYeuCau = nDL->dataDL.slYeuCau;
		goto A;
	}
	gotoXY(44, 17); cout << "          "; vitri = 0;
	
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 10 " ;
		TextColor(12); gotoXY(44 + vitri, y);
		key = GetKey();
		
		if ((key >= '0' && key <= '9') && (vitri < 10))
		{
			slyeucau[vitri] = char(key);
			cout << slyeucau[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(44 + vitri, y);
			cout << " ";
			gotoXY(44 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			slyeucau[vitri] = '\0';
			donglinh.slYeuCau = atoi(slyeucau);
		A:
			vitri = numlen(nDL->dataDL.slYeuCau);			
			gotoXY(58 + vitri, y);
			goto SLCAPPHAT;
		}
		if (key == ESC ) { 
		return; 
		}
	}
SLCAPPHAT:
	char slcapphat[21];
	key = GetKey();
	if(key == ENTER){
		donglinh.slCapPhat =  nDL->dataDL.slCapPhat;
		goto B;
	}
	gotoXY(58, 17); cout<<"                    "; vitri = 0;
	while(1)
    {
		TextColor(250);	gotoXY(21, 18);
		cout << "Ki tu:(0-9). Toi da: 20 " ;
		TextColor(12); gotoXY(58 + vitri, y);
		key = GetKey();
		
		if ((key >= '0' && key <= '9') && (vitri < 20))
		{
			slcapphat[vitri] = char(key);
			cout << slcapphat[vitri];
			
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(58 + vitri, y);
			cout << " ";
			gotoXY(58 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			slcapphat[vitri] = '\0';
			donglinh.slCapPhat = atoi(slcapphat);
		B:
			nDL->dataDL = donglinh;					
			GhiChu("SUA DONG LINH THANH CONG. F2 DE LUU", 40, 27, 228, 2000);	TextColor(12);
			return;	
		}

		if (key == ESC ) { 
		return; 
		}
	}
}

void DL_Xoa(ListDL *listDL)
{
	int key, vitri = 0, x = 25, y = 18;
	bool checkSoPhieu;
	NodeDL *nDL;
	char soPhieu[10], maThuoc[10];
SOPHIEULINH:
	vitri = 0; DongLinh_KhungMenuXoa(); gotoXY(37,18);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			soPhieu[vitri] = char(key);
			soPhieu[vitri] = toupper(soPhieu[vitri]);
			cout<< soPhieu[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(37 + vitri, y);
			cout << " ";
			gotoXY(37 + vitri, y);
		}
		if(key == ENTER && vitri != 0)
		{
			soPhieu[vitri] = '\0';
			goto MATHUOC;
		}
		if (key == ESC ) { return; }
	}
MATHUOC:
	vitri = 0;
	while(1)
	{
		TextColor(250);	gotoXY(36, 19);
		cout << "Ki tu: (A-Z) & (0-9). Toi da: 9 ";
		TextColor(12); gotoXY(53 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			maThuoc[vitri] = char(key);
			maThuoc[vitri] = toupper(maThuoc[vitri]);
			cout << maThuoc[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(53 + vitri, y);
			cout << " ";
			gotoXY(53 + vitri, y);
		}
		if (key == ENTER && vitri != 0)
		{
			maThuoc[vitri] ='\0';
			nDL = listDL->searchDL(listDL->pHead, soPhieu, maThuoc);
			if(!nDL)
			{
				GhiChu("SO PHIEU LINH HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				goto SOPHIEULINH;
			}
			else{
				int tamp = ThongBao_HuyDL();
				if(tamp == true){
					listDL->deleteInfo(listDL->pHead, soPhieu, maThuoc);
					GhiChu("XOA DONG LINH THANH CONG!", 35, 27, 79, 2000);
					gotoXY(33 + vitri, y);
					break;
				}
				else
				{
					GhiChu("XOA DONG LINH KHONG THANH CONG!!!", 35, 27, 79, 2000);
					return;
				}	
			}	
		}
	}
}

//=============PHIEU XUAT================
void PX_Sua(TreePX *dspx, TreeNV dsnv, TreeKCN dskcn){
	int key, vitri = 0, x = 33, y = 14, checkSoPhieu;
	NodePX *nf;
	PhieuXuat px; 
	PX_KhungMenuSua(); gotoXY(x, y);
	
	while(1){
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{	
			gotoXY(33+vitri, 14);
			px.sophieu[vitri] = (char)key;
			px.sophieu[vitri] = toupper(px.sophieu[vitri]);
			cout<<px.sophieu[vitri];
			vitri++;
		}
		
		 if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout<<" ";
			gotoXY(33 + vitri, y);
		}
		
		if (key == ENTER && vitri != 0)
		{
			px.sophieu[vitri] = '\0';
			nf = dspx->FindNodePX(dspx->root, px.sophieu);
			if(nf){
				PX_KhungSua();
				x = 15, y = 14;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(15, 14); cout<<nf->data.manv;
				gotoXY(26, 14); cout <<nf->data.makhoacn;
				gotoXY(37, 14); cout << nf->data.tenkhont;
				gotoXY(63, 14); cout << nf->data.tenkhoxt;
				vitri = strlen(nf->data.manv);
				goto MANV;
				break;
			}
			else{
				cout<<"Ma ko ton tai";
			}
		}
		if(key == ESC) return;
	}
	MANV:
		while (1)
	{
		TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(15 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nf->data.manv[vitri] = char(key);
			nf->data.manv[vitri] = toupper(nf->data.manv[vitri]);
			cout << nf->data.manv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(15 + vitri, y);
			cout << " ";
			gotoXY(15 + vitri, y);
		}
		if (key == SPACE && nf->data.manv[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(15 + vitri, y);
			cout << " ";
			nf->data.manv[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.manv[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.manv[vitri] = '\0';
			if(!dsnv.CoincideMaNV(dsnv.root, nf->data.manv)){
				GhiChu("KHONG CO MA NHAN VIEN NAY. Nhap lai!!!", 40, 27, 228, 2000);	TextColor(12);
				Sleep(1000);
				goto MANV;
			}
			vitri = strlen(nf->data.makhoacn);	
			goto MAKHOACN;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	MAKHOACN:
		while(1)
		{
			TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(26 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))	// dc nhap 9 ky tu vi ky tu cuoi'\0'
			{	
				nf->data.makhoacn[vitri] = char(key);	// dua tung ky tu vao mang makhoacn
				nf->data.makhoacn[vitri] = toupper(nf->data.makhoacn[vitri]);	// chuyen du ky tu sang dang viet hoa
				cout << nf->data.makhoacn[vitri];	// in ra man hinh
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) // Xoa ky tu tren man hinh
			{
				vitri--;
				gotoXY(26 + vitri, y);
				cout << " ";
				gotoXY(26 + vitri, y);
			}
			if (key == SPACE && nf->data.makhoacn[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(26 + vitri, y);
				cout << " ";
				nf->data.makhoacn[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)	// gan gia tri index cuoi = '\0'
			{
				if (nf->data.makhoacn[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				nf->data.makhoacn[vitri] = '\0';
				if(!dskcn.CoincideMaKCN(dskcn.root, nf->data.makhoacn)){
				GhiChu("KHONG CO MA KHOA CHUC NANG NAY. Nhap lai!!!", 40, 27, 228, 2000);	TextColor(12);
				Sleep(1000);
				goto MAKHOACN;
			}
				goto TENKHONT;
			}
			
			if (key == ESC ) { 	// esc de thoat
			return; 
			}
		}	
	TENKHONT:
		vitri = strlen(nf->data.tenkhont);
		while(1){
			TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(37 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
			{
				nf->data.tenkhont[vitri] = char(key);
				nf->data.tenkhont[vitri] = toupper(nf->data.tenkhont[vitri]);
				cout << nf->data.tenkhont[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(37 + vitri, y);
				cout << " ";
				gotoXY(37 + vitri, y);
			}
			if (key == SPACE && nf->data.tenkhont[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(37 + vitri, y);
				cout << " ";
				nf->data.tenkhont[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)
			{
				if (nf->data.manv[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				nf->data.tenkhont[vitri] = '\0';
				goto TENKHOXT;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
	TENKHOXT:
		vitri = strlen(nf->data.tenkhoxt);
		while(1){
			TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(63 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
			{
				nf->data.tenkhoxt[vitri] = char(key);
				nf->data.tenkhoxt[vitri] = toupper(nf->data.tenkhoxt[vitri]);
				cout << nf->data.tenkhoxt[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(63 + vitri, y);
				cout << " ";
				gotoXY(63 + vitri, y);
			}
			if (key == SPACE && nf->data.tenkhoxt[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(63 + vitri, y);
				cout << " ";
				nf->data.tenkhoxt[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)
			{
				if (nf->data.tenkhoxt[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				nf->data.tenkhoxt[vitri] = '\0';
//				vitri = 0;
//				gotoXY(56 + vitri, y);
				GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;	
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
}

void Date_PX(PhieuXuat *px){
	time_t now = time(0);

   tm *ltm = localtime(&now);
   px->ngayxuat.nam = 1900 + ltm->tm_year;
   px->ngayxuat.thang = 1 + ltm->tm_mon;
   px->ngayxuat.ngay = ltm->tm_mday;
}

void PX_Them(TreePX *dspx, TreeNV dsnv, TreeKCN dskcn){
	int key, vitri = 0, x = 33, y = 14, checkSoPhieu;
	NodePX *nf;
	PhieuXuat px; 
	PX_KhungMenuThem(); gotoXY(x, y);
		// Vong lap nay de ghi lai so phieu muon them
	SOPHIEU:
		while(1)
		{	
			TextColor(250);	gotoXY(45, 14);
			cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			gotoXY(33+vitri, y);
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
	//			gotoXY(33+vitri, 14);
				px.sophieu[vitri] = (char)key;
				px.sophieu[vitri] = toupper(px.sophieu[vitri]);
				cout<<px.sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(33 + vitri, y);
				cout<<" ";
				gotoXY(33 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				px.sophieu[vitri] = '\0';	// them ky tu ket thuc chuoi
				nf = dspx->FindNodePX(dspx->root, px.sophieu);
				if(nf){
					TextColor(78); gotoXY(45, 14);
					cout<<"So Phieu da ton tai.  Nhap Lai!";
					Sleep(1000);
					continue;
				}
				PX_KhungSua();
				vitri = 0;
				goto MANV;
			}
			if(key == ESC) return;
		}
	MANV:
		while (1)
	{
		TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(15 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			px.manv[vitri] = char(key);
			px.manv[vitri] = toupper(px.manv[vitri]);
			cout << px.manv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(15 + vitri, y);
			cout << " ";
			gotoXY(15 + vitri, y);
		}
		if (key == SPACE && px.manv[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(15 + vitri, y);
			cout << " ";
			px.manv[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (px.manv[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			px.manv[vitri] = '\0';
			if(!dsnv.CoincideMaNV(dsnv.root, px.manv)){
				GhiChu("KHONG CO MA NHAN VIEN NAY. Nhap lai!!!", 40, 27, 228, 2000);	TextColor(12);
				Sleep(1000);
				goto MANV;
			}
			vitri = 0;	
			goto MAKHOACN;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	MAKHOACN:
		while(1)
		{
			TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(26 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))	// dc nhap 9 ky tu vi ky tu cuoi'\0'
			{	
				px.makhoacn[vitri] = char(key);	// dua tung ky tu vao mang makhoacn
				px.makhoacn[vitri] = toupper(px.makhoacn[vitri]);	// chuyen du ky tu sang dang viet hoa
				cout << px.makhoacn[vitri];	// in ra man hinh
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) // Xoa ky tu tren man hinh
			{
				vitri--;
				gotoXY(26 + vitri, y);
				cout << " ";
				gotoXY(26 + vitri, y);
			}
			if (key == SPACE && px.makhoacn[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(26 + vitri, y);
				cout << " ";
				px.makhoacn[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)	// gan gia tri index cuoi = '\0'
			{
				if (px.makhoacn[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				px.makhoacn[vitri] = '\0';
				if(!dskcn.CoincideMaKCN(dskcn.root, px.makhoacn)){
					GhiChu("KHONG CO MA KHOA CHUC NANG NAY. Nhap lai!!!", 40, 27, 228, 2000);	TextColor(12);
					Sleep(1000);
					goto MAKHOACN;
			}
				goto TENKHONT;
			}
			
			if (key == ESC ) { 	// esc de thoat
			return; 
			}
		}	
	TENKHONT:
		vitri = 0;
		while(1){
			TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(37 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
			{
				px.tenkhont[vitri] = char(key);
				px.tenkhont[vitri] = toupper(px.tenkhont[vitri]);
				cout << px.tenkhont[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(37 + vitri, y);
				cout << " ";
				gotoXY(37 + vitri, y);
			}
			if (key == SPACE && px.tenkhont[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(37 + vitri, y);
				cout << " ";
				px.tenkhont[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)
			{
				if (px.manv[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				px.tenkhont[vitri] = '\0';
//				vitri = 0;
//				gotoXY(56 + vitri, y);
				goto TENKHOXT;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
	TENKHOXT:
		vitri = 0;
		while(1){
			TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(63 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
			{
				px.tenkhoxt[vitri] = char(key);
				px.tenkhoxt[vitri] = toupper(px.tenkhoxt[vitri]);
				cout << px.tenkhoxt[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(63 + vitri, y);
				cout << " ";
				gotoXY(63 + vitri, y);
			}
			if (key == SPACE && px.tenkhoxt[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(63 + vitri, y);
				cout << " ";
				px.tenkhoxt[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)
			{
				if (px.tenkhoxt[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				px.tenkhoxt[vitri] = '\0';
//				Date_PX(&px);
//				dspx->root = dspx->InsertPX(dspx->root, NULL, px);
//				GhiChu("Da them du lieu. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
//				return;	
				goto MANVNEW;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
	MANVNEW:
		vitri = 0;
		while (1)
	{
		TextColor(244);	gotoXY(12, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(73 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			px.manvnew[vitri] = char(key);
			px.manvnew[vitri] = toupper(px.manvnew[vitri]);
			cout << px.manvnew[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(73 + vitri, y);
			cout << " ";
			gotoXY(73 + vitri, y);
		}
		if (key == SPACE && px.manvnew[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(73 + vitri, y);
			cout << " ";
			px.manvnew[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (px.manvnew[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			px.manvnew[vitri] = '\0';
			if(!dsnv.CoincideMaNV(dsnv.root, px.manvnew)){
				GhiChu("KHONG CO MA NHAN VIEN NAY. Nhap lai!!!", 40, 27, 228, 2000);	TextColor(12);
				Sleep(1000);
				goto MANVNEW;
			}
			if(strcmp(px.manvnew, px.manv)){
				GhiChu("MANV nhanThuoc phai Khac MANV xuatThuoc. Nhap lai!!!", 40, 27, 228, 2000);	TextColor(12);
				Sleep(2000);
				goto MANVNEW;
			}
			Date_PX(&px);
				dspx->root = dspx->InsertPX(dspx->root, NULL, px);
				GhiChu("Da them du lieu. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;	
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	
}

void PX_Xoa(TreePX *dspx, LinkListDX *dongxuat){
	int key, vitri = 0, x = 33, y = 14;
	bool check_sp, checkfk_px;
	char t_sophieu[10], mathuoc[10];
	
QuayLai:
	vitri = 0; PX_KhungXoa(); gotoXY(33, 14);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			t_sophieu[vitri] = char(key);
			t_sophieu[vitri] = toupper(t_sophieu[vitri]);
			cout<< t_sophieu[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			t_sophieu[vitri] = '\0';
			check_sp = dspx->CoincideSoPhieuPX(dspx->root, t_sophieu);
			if (!check_sp){
				GhiChu("SO PHIEU KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				continue;
			}
			else{
				checkfk_px = dongxuat->CheckFKDX_sophieu(t_sophieu);
				if(checkfk_px){
					GhiChu("PHAI XOA PHIEU XUAT TRONG BANG DONG XUAT TRUOC!", 20, 27, 79, 2000);
					Sleep(1000);
					continue;
				}
				else{
					dspx->NNDPX(dspx->root, t_sophieu);
			 }
			 GhiChu("XOA THANH CONG PHIEU XUAT!", 20, 27, 79, 2000);
			 return;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout<<" ";
			gotoXY(33 + vitri, y);
		}
		
		if(key == ESC){
			return;
		}
	}
}


// Man hinh chuc nang Dong Xuat
void DX_Sua(LinkListDX *dsdx){
	char strnumb[14];
	SOPHIEU:
	int key, vitri = 0, x = 40, y = 14;
	ListNode_DX *nf;
	DongXuat dx; 
	DX_KhungMenuSua(); gotoXY(x, y);	
		while(1){
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				gotoXY(40+vitri, 14);
				dx.sophieu[vitri] = (char)key;
				dx.sophieu[vitri] = toupper(dx.sophieu[vitri]);
				cout<<dx.sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(40 + vitri, y);
				cout<<" ";
				gotoXY(40 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				dx.sophieu[vitri] = '\0';
					goto MATHUOC;
					break;
			}
			if(key == ESC) return;
		}
		MATHUOC:
			vitri = 0; gotoXY(58+vitri, 14);
			while(1){
				TextColor(14);
				key = GetKey(); 
				if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
				{	
					gotoXY(58+vitri, 14);
					dx.mathuoc[vitri] = (char)key;
					dx.mathuoc[vitri] = toupper(dx.mathuoc[vitri]);
					cout<<dx.mathuoc[vitri];
					vitri++;
				}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(58 + vitri, y);
				cout<<" ";
				gotoXY(58 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				dx.mathuoc[vitri] = '\0';
				nf = dsdx->SearchDX(dx.sophieu, dx.mathuoc);
				if(nf){
					DX_KhungSua();
					x = 15, y = 14;
					gotoXY(x, y);
					TextColor(12);
					gotoXY(20, 14); cout<<nf->data.sophieu;
					gotoXY(31, 14); cout <<nf->data.mathuoc;
					TextColor(14);
					gotoXY(42, 14); cout << nf->data.slxuat;
					gotoXY(57, 14); cout << nf->data.dongia;
					vitri = numlen(nf->data.slxuat);
					gotoXY(42 + vitri, 14);
					goto SLXUAT;
					break;
				}
				else{
					GhiChu("SO PHIEU HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
					Sleep(1000);
					goto SOPHIEU;
				}
			}
			if(key == ESC) return;
			}
		SLXUAT:
			key = GetKey();
			if(key == ENTER) {
				dx.slxuat =  nf->data.slxuat;
				goto A;
			}
			gotoXY(42, 14); cout << "              "; vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(17, 15); cout << "Ki tu: (0-9). Toi da: 13        ";
			TextColor(14); gotoXY(42 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(42 + vitri, y);
				cout << " ";
				gotoXY(42 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dx.slxuat = atoi(strnumb);
			A:
				vitri = numlen(nf->data.dongia);
				gotoXY(57+vitri, 14);
				goto DONGIA;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
	DONGIA:
		key = GetKey();
		if(key == ENTER){
			dx.dongia =  nf->data.dongia;
			goto B;
		} 
		gotoXY(57, 14); cout << "              "; vitri = 0;
		while (1)
		{
			TextColor(244);	gotoXY(17, 15); cout << "Ki tu: (0-9). Toi da: 13        ";
			TextColor(14); gotoXY(57 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(57 + vitri, y);
				cout << " ";
				gotoXY(57 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dx.dongia = atoi(strnumb);
			B:
				nf->data = dx;
				GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;	
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
}

void Date_DX(DongXuat *px){
	time_t now = time(0);

   tm *ltm = localtime(&now);
   px->ngayxuat.nam = 1900 + ltm->tm_year;
   px->ngayxuat.thang = 1 + ltm->tm_mon;
   px->ngayxuat.ngay = ltm->tm_mday;
}

void DX_Them(LinkListDX *dsdx, TreePX dspx,TreeThuoc *treeThuoc, int position){
	char strnumb[14];
	bool checkMaThuoc;
	
	int key, vitri = 0, x = 40, y = 14;
	ListNode_DX *nf;
	DongXuat dx; 
	gotoXY(40, 14);
	SOPHIEU:
	DX_KhungMenuThem(); 	
		while(1){
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				gotoXY(40+vitri, 14);
				dx.sophieu[vitri] = (char)key;
				dx.sophieu[vitri] = toupper(dx.sophieu[vitri]);
				cout<<dx.sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(40 + vitri, y);
				cout<<" ";
				gotoXY(40 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				dx.sophieu[vitri] = '\0';
				if(!dspx.CoincideSoPhieuPX(dspx.root, dx.sophieu)){
					GhiChu("SO PHIEU KHONG CO TRONG BANG SOPHIEU!", 35, 27, 79, 1000);
					Sleep(1000);
					continue;
				}	
					vitri = 0;
					goto MATHUOC;
					break;
			}
			if(key == ESC) return;
		}
		MATHUOC:
			gotoXY(58+vitri, 14);
			while(1){
				TextColor(14);
				key = GetKey(); 
				if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
				{	
					gotoXY(58+vitri, 14);
					dx.mathuoc[vitri] = (char)key;
					dx.mathuoc[vitri] = toupper(dx.mathuoc[vitri]);
					cout<<dx.mathuoc[vitri];
					vitri++;
				}
			
			 	if(key == BACKSPACE && vitri > 0)
				{
					vitri--;
					gotoXY(58 + vitri, y);
					cout<<" ";
					gotoXY(58 + vitri, y);
				}
			
				if (key == ENTER && vitri != 0)
				{
					dx.mathuoc[vitri] = '\0';
				
				// Kiem tra khoa ngoai DX
					checkMaThuoc = treeThuoc->CheckMaThuoc(treeThuoc->rootT, dx.mathuoc);
					nf = dsdx->SearchDX(dx.sophieu, dx.mathuoc);
					
					if(checkMaThuoc ==true)
					{
						if(!nf){
						
							DX_KhungSua();
							gotoXY(20, 14); cout<<dx.sophieu;
							gotoXY(31, 14); cout <<dx.mathuoc;
							vitri = 0;
							goto SLXUAT;
						}
						else{
							GhiChu("SO PHIEU HOAC MA THUOC DA TON TAI!", 35, 27, 79, 1000);
							Sleep(1000);
							goto SOPHIEU;
						}
					}
					else
					{
						GhiChu("MA THUOC KHONG CO TRONG BANG THUOC!", 35, 27, 79, 1000);
						Sleep(1000);
						goto MATHUOC;
					}			
														
				}
				if(key == ESC) return;
		}
		SLXUAT:
			gotoXY(42+vitri, 14);
			while (1)
		{
			TextColor(244);	gotoXY(17, 15); cout << "Ki tu: (0-9). Toi da: 9";
			TextColor(14); gotoXY(42 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{	
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(42 + vitri, y);
				cout << " ";
				gotoXY(42 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dx.slxuat = atoi(strnumb);
				goto DONGIA;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
	DONGIA:
		vitri = 0;
		while (1)
		{
			TextColor(244);	gotoXY(17, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(57 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(57 + vitri, y);
				cout << " ";
				gotoXY(57 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dx.dongia = atoi(strnumb);
				Date_DX(&dx);
				dsdx->InsertDX(dx, position+1);
				GhiChu("Da luu thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;	
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
}

void DX_Xoa(LinkListDX *dsdx){
	char t_sophieu[10], t_mathuoc[10];
	DX_KhungXoa(); gotoXY(33, 14);
	ListNode_DX *nf;
	SOPHIEU:
	int key, vitri = 0, x = 40, y = 14;
	DX_KhungMenuSua(); gotoXY(x, y);	
		while(1){
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				gotoXY(40+vitri, 14);
				t_sophieu[vitri] = (char)key;
				t_sophieu[vitri] = toupper(t_sophieu[vitri]);
				cout<<t_sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(40 + vitri, y);
				cout<<" ";
				gotoXY(40 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				t_sophieu[vitri] = '\0';
					goto MATHUOC;
					break;
			}
			if(key == ESC) return;
		}
		MATHUOC:
			vitri = 0; gotoXY(58+vitri, 14);
			while(1){
				TextColor(14);
				key = GetKey(); 
				if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
				{	
					gotoXY(58+vitri, 14);
					t_mathuoc[vitri] = (char)key;
					t_mathuoc[vitri] = toupper(t_mathuoc[vitri]);
					cout<<t_mathuoc[vitri];
					vitri++;
				}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(58 + vitri, y);
				cout<<" ";
				gotoXY(58 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				t_mathuoc[vitri] = '\0';
				nf = dsdx->SearchDX(t_sophieu, t_mathuoc);
				if(!nf){
					GhiChu("SO PHIEU HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y);
					goto SOPHIEU;
				}
				else{
					dsdx->DeleteDX(t_sophieu, t_mathuoc);
					GhiChu("Da xoa dong xuat, F2 de luu!!!", 20, 27, 79, 2000);
			 		return;
				}
			}
			if(key == ESC) return;
			}
}


//-------NHAN VIEN---------
void NV_Them(TreeNV *dsnv){
	int key, vitri = 0, x = 33, y = 14, checkmaNV;
	NodeNV *nf;
	NhanVien nv; 
	NV_KhungMenuThem(); gotoXY(x, y);
	
		// Vong lap nay de ghi lai so phieu muon them
	MANV:
		while(1)
		{	
			TextColor(250);	gotoXY(45, 14);
			cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			gotoXY(33+vitri, y);
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
	//			gotoXY(33+vitri, 14);
				nv.maNV[vitri] = (char)key;
				nv.maNV[vitri] = toupper(nv.maNV[vitri]);
				cout<<nv.maNV[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(33 + vitri, y);
				cout<<" ";
				gotoXY(33 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				nv.maNV[vitri] = '\0';	// them ky tu ket thuc chuoi
				nf = dsnv->FindNodeNV(dsnv->root, nv.maNV);
				if(nf){
					TextColor(78); gotoXY(45, 14);
					cout<<"Ma NV da ton tai.  Nhap Lai!";
					Sleep(1000);
					continue;
				}
				NV_KhungThem();
				nf = new NodeNV();		// Neu so phieu chua ton tai, cap phat dong nf la NodePX
				strcpy(nf->data.maNV, nv.maNV);		// gan so phieu cho nf
				goto HOTEN;
			}
			if(key == ESC) return;
		}
	HOTEN:
		vitri = 0;
		while (1)
	{
		TextColor(244);	gotoXY(15, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da:24";
		TextColor(14); gotoXY(15 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
		{
			nf->data.hoTen[vitri] = char(key);
			nf->data.hoTen[vitri] = toupper(nf->data.hoTen[vitri]);
			cout << nf->data.hoTen[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(15 + vitri, y);
			cout << " ";
			gotoXY(15 + vitri, y);
		}
		if (key == SPACE && nf->data.hoTen[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(15 + vitri, y);
			cout << " ";
			nf->data.hoTen[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.hoTen[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.hoTen[vitri] = '\0';
//			vitri = 0;
//			gotoXY(56 + vitri, y);
			goto CHUCVU;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	CHUCVU:
		vitri = 0;	
		while(1)
		{
			TextColor(244);	gotoXY(15, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(47 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))	// dc nhap 9 ky tu vi ky tu cuoi'\0'
			{	
				nf->data.chucVu[vitri] = char(key);	// dua tung ky tu vao mang makhoacn
				nf->data.chucVu[vitri] = toupper(nf->data.chucVu[vitri]);	// chuyen du ky tu sang dang viet hoa
				cout << nf->data.chucVu[vitri];	// in ra man hinh
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) // Xoa ky tu tren man hinh
			{
				vitri--;
				gotoXY(47 + vitri, y);
				cout << " ";
				gotoXY(47 + vitri, y);
			}
			if (key == SPACE && nf->data.chucVu[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(47 + vitri, y);
				cout << " ";
				nf->data.chucVu[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)	// gan gia tri index cuoi = '\0'
			{
				if (nf->data.chucVu[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				nf->data.chucVu[vitri] = '\0';
				dsnv->root = dsnv->InsertNV(dsnv->root, NULL, nf->data);
				GhiChu("Da them nhan vien . F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;
			}
			
			if (key == ESC ) { 	// esc de thoat
			return; 
			}
		}	
	
}


void NV_Sua(TreeNV *dsnv){
	int key, vitri = 0, x = 33, y = 14, checkmaNV;
	NodeNV *nf;
	NhanVien nv; 
	NV_KhungMenuSua(); gotoXY(x, y);
	
	while(1){
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{	
			gotoXY(33+vitri, 14);
			nv.maNV[vitri] = (char)key;
			nv.maNV[vitri] = toupper(nv.maNV[vitri]);
			cout<<nv.maNV[vitri];
			vitri++;
		}
		
		 if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout<<" ";
			gotoXY(33 + vitri, y);
		}
		
		if (key == ENTER && vitri != 0)
		{
			nv.maNV[vitri] = '\0';
			nf = dsnv->FindNodeNV(dsnv->root, nv.maNV);
			if(nf){
				NV_KhungSua();
				x = 15, y = 14;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(15, 14); cout <<nf->data.hoTen;
				gotoXY(47, 14); cout << nf->data.chucVu;
				vitri = strlen(nf->data.maNV);
				goto HOTEN;
				break;
			}
			else{
				cout<<"Ma ko ton tai";
			}
		}
		if(key == ESC) return;
	}
	HOTEN:
		vitri = strlen(nf->data.hoTen);
		while (1)
	{
		TextColor(244);	gotoXY(15, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 24";
		TextColor(14); gotoXY( 15+ vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
		{
			nf->data.hoTen[vitri] = char(key);
			nf->data.hoTen[vitri] = toupper(nf->data.hoTen[vitri]);
			cout << nf->data.hoTen[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(15 + vitri, y);
			cout << " ";
			gotoXY(15 + vitri, y);
		}
		if (key == SPACE && nf->data.hoTen[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(15 + vitri, y);
			cout << " ";
			nf->data.hoTen[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.hoTen[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.hoTen[vitri] = '\0';
			goto CHUCVU;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	CHUCVU:
		vitri = strlen(nf->data.chucVu);	
		while(1)
		{
			TextColor(244);	gotoXY(15, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(47 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))	// dc nhap 9 ky tu vi ky tu cuoi'\0'
			{	
				nf->data.chucVu[vitri] = char(key);	// dua tung ky tu vao mang makhoacn
				nf->data.chucVu[vitri] = toupper(nf->data.chucVu[vitri]);	// chuyen du ky tu sang dang viet hoa
				cout << nf->data.chucVu[vitri];	// in ra man hinh
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) // Xoa ky tu tren man hinh
			{
				vitri--;
				gotoXY(47 + vitri, y);
				cout << " ";
				gotoXY(47 + vitri, y);
			}
			if (key == SPACE && nf->data.chucVu[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(47 + vitri, y);
				cout << " ";
				nf->data.chucVu[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)	// gan gia tri index cuoi = '\0'
			{
				if (nf->data.chucVu[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				nf->data.chucVu[vitri] = '\0';
//				dsnv->InsertNV(dsnv->root, NULL, nf->data);
				GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;
//				vitri = 0;
//				gotoXY(56 + vitri, y);
				
			}
			
			if (key == ESC ) { 	// esc de thoat
			return; 
			}
		}	
	
	
}

void NV_Xoa(TreeNV *dsnv, TreePX dspx, TreePL dspl){
	int key, vitri = 0, x = 33, y = 14;
	bool check_nv, checkfk_px, checkfk_pl;
	char t_sophieu[10], t_maNV[10];
	
QuayLai:
	vitri = 0; NV_KhungXoa(); gotoXY(33, 14);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			t_maNV[vitri] = char(key);
			t_maNV[vitri] = toupper(t_maNV[vitri]);
			cout<< t_maNV[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			t_maNV[vitri] = '\0';
			check_nv = dsnv->CoincideMaNV(dsnv->root, t_maNV);
			if (!check_nv){
				GhiChu("SO PHIEU KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(33 + vitri, y);
				continue;
			}
			else{
				checkfk_px = dspx.CheckFKPX_maNV(dspx.root, t_maNV);
				checkfk_pl = dspl.CheckFKPL_maNV(dspl.root, t_maNV);
				if(checkfk_px){
					GhiChu("KHONG THE XOA VI CO MANV TRONG PHIEU XUAT!", 20, 27, 79, 2000);
					Sleep(1000);
					goto QuayLai;
				}
				if(checkfk_pl){
					GhiChu("KHONG THE XOA VI CO MANV TRONG PHIEU LINH!", 20, 27, 79, 2000);
					Sleep(1000);
					goto QuayLai;
				}
				else{
					dsnv->NNDNV(dsnv->root, t_maNV);
			 }
			 GhiChu("XOA THANH CONG PHIEU XUAT!", 20, 27, 79, 2000);
			 Sleep(500);
			 return;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(33 + vitri, y);
			cout<<" ";
			gotoXY(33 + vitri, y);
		}
		
		if(key == ESC){
			return;
		}
	}
}


//--------NV KIEM KE---------
void Date_NVKK(NodeNVKK *nf){
	time_t now = time(0);

   tm *ltm = localtime(&now);
   nf->data.ngayKiemKe.nam = 1900 + ltm->tm_year;
   nf->data.ngayKiemKe.thang = 1 + ltm->tm_mon;
   nf->data.ngayKiemKe.ngay = ltm->tm_mday;
}
void NVKK_Them(TreeNVKK *dsnvkk, TreeNV dsnv){
	int key, vitri = 0, x = 33, y = 14, checksophieu;
	NodeNVKK *nf;
	NVKiemKe nvkk; 
	NVKK_KhungMenuThem(); gotoXY(x, y);
	
		// Vong lap nay de ghi lai so phieu muon them
	SOPHIEU:
		while(1)
		{	
			TextColor(250);	gotoXY(16, 16);
			cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			gotoXY(16+vitri, y);
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
	//			gotoXY(33+vitri, 14);
				nvkk.sophieu[vitri] = (char)key;
				nvkk.sophieu[vitri] = toupper(nvkk.sophieu[vitri]);
				cout<<nvkk.sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(16 + vitri, y);
				cout<<" ";
				gotoXY(16 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				nvkk.sophieu[vitri] = '\0';	// them ky tu ket thuc chuoi
				nf = dsnvkk->FindNodeNVKK(dsnvkk->root, nvkk.sophieu);
				if(nf){
					TextColor(78); gotoXY(45, 14);
					cout<<"Ma NV da ton tai.  Nhap Lai!";
					Sleep(1000);
					continue;
				}
				
				NVKK_KhungThem();
				nf = new NodeNVKK();		// Neu so phieu chua ton tai, cap phat dong nf la NodePX
				strcpy(nf->data.sophieu, nvkk.sophieu);		// gan so phieu cho nf
				vitri = 0;
				goto MANV;
			}
			if(key == ESC) return;
		}
	MANV:
		while (1)
	{
		TextColor(244);	gotoXY(15, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(15 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nf->data.manv[vitri] = char(key);
			nf->data.manv[vitri] = toupper(nf->data.manv[vitri]);
			cout << nf->data.manv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(15 + vitri, y);
			cout << " ";
			gotoXY(15 + vitri, y);
		}
		if (key == SPACE && nf->data.manv[vitri - 1] != ' ' && vitri > 0 && vitri < 10) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(15 + vitri, y);
			cout << " ";
			nf->data.manv[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.manv[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.manv[vitri] = '\0';
			if(!dsnv.CoincideMaNV(dsnv.root, nf->data.manv)){
				GhiChu("KHONG CO MA NHAN VIEN NAY. Nhap lai!!!", 40, 27, 228, 2000);	TextColor(12);
				Sleep(1000);
				goto MANV;
			}
			Date_NVKK(nf);
			dsnvkk->root = dsnvkk->InsertNVKK(dsnvkk->root, NULL, nf->data);
			GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
			return;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}	
}

void NVKK_Sua(TreeNVKK *dsnvkk, TreeNV dsnv){
	int key, vitri = 0, x = 33, y = 14, checkSoPhieu;
	NodeNVKK *nf;
	NVKiemKe nvkk; 
	NVKK_KhungMenuSua(); gotoXY(20, 14);
	
	while(1){
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{	
			gotoXY(20+vitri, 14);
			nvkk.sophieu[vitri] = (char)key;
			nvkk.sophieu[vitri] = toupper(nvkk.sophieu[vitri]);
			cout<<nvkk.sophieu[vitri];
			vitri++;
		}
		
		 if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(20 + vitri, y);
			cout<<" ";
			gotoXY(20 + vitri, y);
		}
		
		if (key == ENTER && vitri != 0)
		{
			nvkk.sophieu[vitri] = '\0';
			nf = dsnvkk->FindNodeNVKK(dsnvkk->root, nvkk.sophieu);
			if(nf){
				NVKK_KhungSua();
				x = 15, y = 14;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(15, 14); cout<<nf->data.manv;
				vitri = strlen(nf->data.manv);
				goto MANV;
				break;
			}
			else{
				GhiChu("SO PHIEU KHONG CO TRONG BANG NVKIEMKE, Nhap Lai!", 35, 27, 79, 1000);
				Sleep(1000);
				continue;
			}
		}
		if(key == ESC) return;
	}
	MANV:
		while (1)
	{
		TextColor(244);	gotoXY(15, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(15 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nf->data.manv[vitri] = char(key);
			nf->data.manv[vitri] = toupper(nf->data.manv[vitri]);
			cout << nf->data.manv[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(15 + vitri, y);
			cout << " ";
			gotoXY(15 + vitri, y);
		}
		if (key == SPACE && nf->data.manv[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(15 + vitri, y);
			cout << " ";
			nf->data.manv[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.manv[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.manv[vitri] = '\0';
			if(!dsnv.CoincideMaNV(dsnv.root, nf->data.manv)){
				GhiChu("KHONG CO MA NHAN VIEN NAY. Nhap lai!!!", 35, 27, 79, 1000);	TextColor(12);
				Sleep(1000);
				goto MANV;
			}
			Date_NVKK(nf);
			GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
			return;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}

}

void NVKK_Xoa(TreeNVKK *dsnvkk){
	int key, vitri = 0, x = 15, y = 14;
	bool check_nvkk;
	char t_sophieu[10];
	
QuayLai:
	vitri = 0; NVKK_KhungXoa(); gotoXY(15, 14);
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			t_sophieu[vitri] = char(key);
			t_sophieu[vitri] = toupper(t_sophieu[vitri]);
			cout<< t_sophieu[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			t_sophieu[vitri] = '\0';
			check_nvkk = dsnvkk->CoincideSoPhieuNVKK(dsnvkk->root, t_sophieu);
			if (!check_nvkk){
				GhiChu("SO PHIEU KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(15 + vitri, y);
				continue;
			}
			else{
				dsnvkk->NNDNVKK(dsnvkk->root, t_sophieu);
				GhiChu("XOA THANH CONG PHIEU XUAT!", 20, 27, 79, 2000);
			 Sleep(500);
			 return;
			} 
		}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(15 + vitri, y);
			cout<<" ";
			gotoXY(15 + vitri, y);
		}
		
		if(key == ESC){
			return;
		}
	}
}


//--------KHOA CHUC NANG------------
void KCN_Them(TreeKCN *dskcn){
	int key, vitri = 0, x = 33, y = 14, checkmaKCN;
	NodeKCN *nf;
	KhoaChucNang kcn; 
	KCN_KhungMenuThem(); gotoXY(x, y);
	
		// Vong lap nay de ghi lai so phieu muon them
	MAKCN:
		while(1)
		{	
			TextColor(250);	gotoXY(45, 14);
			cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			gotoXY(31+vitri, y);
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				kcn.maKCN[vitri] = (char)key;
				kcn.maKCN[vitri] = toupper(kcn.maKCN[vitri]);
				cout<<kcn.maKCN[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(31 + vitri, y);
				cout<<" ";
				gotoXY(31 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				kcn.maKCN[vitri] = '\0';	// them ky tu ket thuc chuoi
				nf = dskcn->FindNodeKCN(dskcn->root, kcn.maKCN);
				if(nf){
					TextColor(78); gotoXY(45, 14);
					cout<<"Ma NV da ton tai.  Nhap Lai!";
					Sleep(1000);
					continue;
				}
				KCN_KhungThem();
				nf = new NodeKCN();		// Neu so phieu chua ton tai, cap phat dong nf la NodePX
				strcpy(nf->data.maKCN, kcn.maKCN);		// gan so phieu cho nf
				goto TENKCN;
			}
			if(key == ESC) return;
		}
	TENKCN:
		vitri = 0;
		while (1)
	{
		TextColor(244);	gotoXY(22, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(22 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
		{
			nf->data.tenKCN[vitri] = char(key);
			nf->data.tenKCN[vitri] = toupper(nf->data.tenKCN[vitri]);
			cout << nf->data.tenKCN[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(22 + vitri, y);
			cout << " ";
			gotoXY(22 + vitri, y);
		}
		if (key == SPACE && nf->data.tenKCN[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(22 + vitri, y);
			cout << " ";
			nf->data.tenKCN[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.tenKCN[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.tenKCN[vitri] = '\0';
			goto TENNGUOIDD;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	TENNGUOIDD:
		vitri = 0;	
		while(1)
		{
			TextColor(244);	gotoXY(22, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(49 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))	// dc nhap 9 ky tu vi ky tu cuoi'\0'
			{	
				nf->data.tenNguoiDD[vitri] = char(key);	// dua tung ky tu vao mang makhoacn
				nf->data.tenNguoiDD[vitri] = toupper(nf->data.tenNguoiDD[vitri]);	// chuyen du ky tu sang dang viet hoa
				cout << nf->data.tenNguoiDD[vitri];	// in ra man hinh
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) // Xoa ky tu tren man hinh
			{
				vitri--;
				gotoXY(49 + vitri, y);
				cout << " ";
				gotoXY(49 + vitri, y);
			}
			if (key == SPACE && nf->data.tenNguoiDD[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(49 + vitri, y);
				cout << " ";
				nf->data.tenNguoiDD[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)	// gan gia tri index cuoi = '\0'
			{
				if (nf->data.tenNguoiDD[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				nf->data.tenNguoiDD[vitri] = '\0';
				dskcn->root = dskcn->InsertKCN(dskcn->root, NULL, nf->data);
				GhiChu("Da them nhan vien . F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;
			}
			
			if (key == ESC ) { 	// esc de thoat
			return; 
			}
		}	
}

void KCN_Sua(TreeKCN *dskcn){
	int key, vitri = 0, x = 33, y = 14, checkmaKCN;
	NodeKCN *nf;
	KhoaChucNang kcn; 
	KCN_KhungMenuSua(); gotoXY(x, y);
	
	while(1){
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{	
			gotoXY(31+vitri, 14);
			kcn.maKCN[vitri] = (char)key;
			kcn.maKCN[vitri] = toupper(kcn.maKCN[vitri]);
			cout<<kcn.maKCN[vitri];
			vitri++;
		}
		
		 if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(31 + vitri, y);
			cout<<" ";
			gotoXY(31 + vitri, y);
		}
		
		if (key == ENTER && vitri != 0)
		{
			kcn.maKCN[vitri] = '\0';
			nf = dskcn->FindNodeKCN(dskcn->root, kcn.maKCN);
			if(nf){
				KCN_KhungSua();
				x = 15, y = 14;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(22, 14); cout <<nf->data.tenKCN;
				gotoXY(47, 14); cout << nf->data.tenNguoiDD;
				vitri = strlen(nf->data.maKCN);
				goto TENKCN;
				break;
			}
			else{
				cout<<"Ma ko ton tai";
			}
		}
		if(key == ESC) return;
	}
	TENKCN:
		vitri = strlen(nf->data.tenKCN);
		while (1)
	{
		TextColor(244);	gotoXY(22, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY( 22+ vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))
		{
			nf->data.tenKCN[vitri] = char(key);
			nf->data.tenKCN[vitri] = toupper(nf->data.tenKCN[vitri]);
			cout << nf->data.tenKCN[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(22 + vitri, y);
			cout << " ";
			gotoXY(22 + vitri, y);
		}
		if (key == SPACE && nf->data.tenKCN[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(22 + vitri, y);
			cout << " ";
			nf->data.tenKCN[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.tenKCN[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.tenKCN[vitri] = '\0';
			goto TENNGUOIDD;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	TENNGUOIDD:
		vitri = strlen(nf->data.tenNguoiDD);	
		while(1)
		{
			TextColor(244);	gotoXY(22, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 24";
			TextColor(14); gotoXY(47 + vitri, y); //Ghi ch?
			key = GetKey();
			if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 24))	// dc nhap 9 ky tu vi ky tu cuoi'\0'
			{	
				nf->data.tenNguoiDD[vitri] = char(key);	// dua tung ky tu vao mang makhoacn
				nf->data.tenNguoiDD[vitri] = toupper(nf->data.tenNguoiDD[vitri]);	// chuyen du ky tu sang dang viet hoa
				cout << nf->data.tenNguoiDD[vitri];	// in ra man hinh
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0) // Xoa ky tu tren man hinh
			{
				vitri--;
				gotoXY(47 + vitri, y);
				cout << " ";
				gotoXY(47 + vitri, y);
			}
			if (key == SPACE && nf->data.tenNguoiDD[vitri - 1] != ' ' && vitri > 0 && vitri < 24) // ko cho 2 khoang trang && vitri = 0
			{
				gotoXY(47 + vitri, y);
				cout << " ";
				nf->data.tenNguoiDD[vitri] = ' ';
				vitri++;
			}
			if (key == ENTER && vitri != 0)	// gan gia tri index cuoi = '\0'
			{
				if (nf->data.tenNguoiDD[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
				nf->data.tenNguoiDD[vitri] = '\0';
				GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;				
			}
			
			if (key == ESC ) { 	// esc de thoat
			return; 
			}
		}	
}

void KCN_Xoa(TreeKCN *dskcn, TreePX dspx, TreePL dspl){
	int key, vitri = 0, x = 31, y = 14;
	bool check_kcn, checkfk_px, checkfk_pl;
	char t_sophieu[10], t_maKVN[10];
	KCN_KhungXoa(); gotoXY(31, 14);
	
QuayLai:
	while(1)
	{
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
			t_maKVN[vitri] = char(key);
			t_maKVN[vitri] = toupper(t_maKVN[vitri]);
			cout<< t_maKVN[vitri];
			vitri++;
		}
		if(key == ENTER && vitri != 0)
		{
			t_maKVN[vitri] = '\0';
			check_kcn = dskcn->CoincideMaKCN(dskcn->root, t_maKVN);
			if (!check_kcn){
				GhiChu("SO PHIEU KHONG TON TAI!", 35, 27, 79, 1000);
				gotoXY(31 + vitri, y);
				continue;
			}
			else{
				checkfk_px = dspx.CheckFKPX_maKCN(dspx.root, t_maKVN);
				checkfk_pl = dspl.CheckFKPL_maKCN(dspl.root, t_maKVN);
				if(checkfk_px){
					GhiChu("KHONG THE XOA VI CO MA KHOACN TRONG PHIEU XUAT!", 20, 27, 79, 2000);
					Sleep(1000);
					goto QuayLai;
				}
				if(checkfk_pl){
					GhiChu("KHONG THE XOA VI CO MA KHOACN TRONG PHIEU LINH!", 20, 27, 79, 2000);
					Sleep(1000);
					goto QuayLai;
				}
			dskcn->NNDKCN(dskcn->root, t_maKVN);
			 GhiChu("XOA THANH CONG !", 20, 27, 79, 2000);
			 Sleep(500);
			 return;
			}
		}
		if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(31 + vitri, y);
			cout<<" ";
			gotoXY(31 + vitri, y);
		}
		
		if(key == ESC){
			return;
		}
	}
}


//--------PHIEU LINH---------
void Date_PL(NodePL *nf){
	time_t now = time(0);

   tm *ltm = localtime(&now);
   nf->data.ngayYC.nam = 1900 + ltm->tm_year;
   nf->data.ngayYC.thang = 1 + ltm->tm_mon;
   nf->data.ngayYC.ngay = ltm->tm_mday;
}

void PL_Them(TreePL *dspl, TreeNV dsnv, TreeKCN dskcn){
	int key, vitri = 0, x = 33, y = 14, checksophieu;
	NodePL *nf;
	PhieuLinh pl; 
	PL_KhungMenuThem(); gotoXY(x, y);
	
		// Vong lap nay de ghi lai so phieu muon them
	SOPHIEU:
		while(1)
		{	
			TextColor(250);	gotoXY(28, 16);
			cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			gotoXY(28+vitri, y);
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				pl.sophieu[vitri] = (char)key;
				pl.sophieu[vitri] = toupper(pl.sophieu[vitri]);
				cout<<pl.sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(28 + vitri, y);
				cout<<" ";
				gotoXY(28 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				pl.sophieu[vitri] = '\0';	// them ky tu ket thuc chuoi
				nf = dspl->FindNodePL(dspl->root, pl.sophieu);
				if(nf){
					TextColor(78); gotoXY(45, 14);
					GhiChu("SO PHIEU DA TON TAI. Nhap Lai!", 35, 27, 79, 1000);
					Sleep(1000);
					continue;
				}
				
				PL_KhungThem();
				nf = new NodePL();		// Neu so phieu chua ton tai, cap phat dong nf la NodePX
				strcpy(nf->data.sophieu, pl.sophieu);		// gan so phieu cho nf
				vitri = 0;
				goto MANV;
			}
			if(key == ESC) return;
		}
	MANV:// LA MA NHAN VIEN
		while (1)
	{
		TextColor(244);	gotoXY(27, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(28 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nf->data.maNV[vitri] = char(key);
			nf->data.maNV[vitri] = toupper(nf->data.maNV[vitri]);
			cout << nf->data.maNV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(28 + vitri, y);
			cout << " ";
			gotoXY(28 + vitri, y);
		}
		if (key == SPACE && nf->data.maNV[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(28 + vitri, y);
			cout << " ";
			nf->data.maNV[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.maNV[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.maNV[vitri] = '\0';
			if(!dsnv.CoincideMaNV(dsnv.root, nf->data.maNV)){
				GhiChu("KHONG CO MANV NAY. NHAP LAI!!!", 35, 27, 79, 1000);
				goto MANV;
			}
			vitri =0;
			goto MAKHOACN;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	MAKHOACN:
		while (1)
	{
		TextColor(244);	gotoXY(27, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(40 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nf->data.maKCN[vitri] = char(key);
			nf->data.maKCN[vitri] = toupper(nf->data.maKCN[vitri]);
			cout << nf->data.maKCN[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40 + vitri, y);
			cout << " ";
			gotoXY(40 + vitri, y);
		}
		if (key == SPACE && nf->data.maKCN[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(40 + vitri, y);
			cout << " ";
			nf->data.maKCN[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.maKCN[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.maKCN[vitri] = '\0';
			if(!dskcn.CoincideMaKCN(dskcn.root, nf->data.maKCN)){
				GhiChu("KHONG CO MAKHOACN NAY. NHAP LAI!!!", 35, 27, 79, 1000);
				goto MAKHOACN;
			}
			Date_PL(nf);
			dspl->root = dspl->InsertPL(dspl->root, NULL, nf->data);
			GhiChu("Da Them thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
			return;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	
}

void PL_Sua(TreePL *dspl, TreeNV dsnv, TreeKCN dskcn){
	int key, vitri = 0, x = 33, y = 14, checkSoPhieu;
	NodePL *nf;
	PhieuLinh pl; 
	PL_KhungMenuSua(); gotoXY(28, 14);
	
	while(1){
		TextColor(14);
		key = GetKey();
		if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{	
			gotoXY(28+vitri, 14);
			pl.sophieu[vitri] = (char)key;
			pl.sophieu[vitri] = toupper(pl.sophieu[vitri]);
			cout<<pl.sophieu[vitri];
			vitri++;
		}
		
		 if(key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(28 + vitri, y);
			cout<<" ";
			gotoXY(28 + vitri, y);
		}
		
		if (key == ENTER && vitri != 0)
		{
			pl.sophieu[vitri] = '\0';
			nf = dspl->FindNodePL(dspl->root, pl.sophieu);
			if(nf){
				PL_KhungSua();
				x = 15, y = 14;
				gotoXY(x, y);
				TextColor(14);
				gotoXY(28, 14); cout<<nf->data.maNV;
				gotoXY(40, 14); cout<<nf->data.maKCN;
//				vitri = strlen(nf->data.maNV);
				goto MANV;
				break;
			}
			else{
				GhiChu("KHONG CO PHIEU LINH NAY. NHAP LAI!!!", 35, 27, 79, 1000);
			}
		}
		if(key == ESC) return;
	}
	MANV:
		vitri = strlen(nf->data.maNV);
		while (1)
	{	
		TextColor(244);	gotoXY(27, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(28 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nf->data.maNV[vitri] = char(key);
			nf->data.maNV[vitri] = toupper(nf->data.maNV[vitri]);
			cout << nf->data.maNV[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(28 + vitri, y);
			cout << " ";
			gotoXY(28 + vitri, y);
		}
		if (key == SPACE && nf->data.maNV[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(28 + vitri, y);
			cout << " ";
			nf->data.maNV[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.maNV[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.maNV[vitri] = '\0';
			if(!dsnv.CoincideMaNV(dsnv.root, nf->data.maNV)){
				GhiChu("KHONG CO MA NHAN VIEN NAY. NHAP LAI!!!", 35, 27, 79, 1000);
				goto MANV;
			}
			goto MAKHOACN;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
	MAKHOACN:
		vitri = strlen(nf->data.maKCN);
		while (1)
	{
//		TextColor(244);	gotoXY(28, 16); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
		TextColor(14); gotoXY(40 + vitri, y); //Ghi ch?
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
		{
			nf->data.maKCN[vitri] = char(key);
			nf->data.maKCN[vitri] = toupper(nf->data.maKCN[vitri]);
			cout << nf->data.maKCN[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0)
		{
			vitri--;
			gotoXY(40 + vitri, y);
			cout << " ";
			gotoXY(40 + vitri, y);
		}
		if (key == SPACE && nf->data.maKCN[vitri - 1] != ' ' && vitri > 0 && vitri < 9) // ko cho 2 khoang trang && vitri = 0
		{
			gotoXY(40 + vitri, y);
			cout << " ";
			nf->data.maKCN[vitri] = ' ';
			vitri++;
		}
		if (key == ENTER && vitri != 0)
		{
			if (nf->data.maKCN[vitri - 1] == ' ') { vitri--; } //Kiem tra ki tu cuoi cung la khoang trang thi xoa khoang trang
			nf->data.maKCN[vitri] = '\0';
			if(!dskcn.CoincideMaKCN(dskcn.root, nf->data.maKCN)){
				GhiChu("KHONG CO MAKHOACN NAY. NHAP LAI!!!", 35, 27, 79, 1000);
				goto MAKHOACN;
			}
			Date_PL(nf);
			GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
			return;
		}
		
		if (key == ESC ) { 
		return; 
		}
	}
}

void PL_Xoa(TreePL *dspl){	
	int key, vitri = 0, x = 28, y = 14;
	bool check_pl, checkfk_dl;
	char t_MaPL[10];
	
	QuayLai:
		vitri = 0; PL_KhungXoa(); gotoXY(28, 14);
		while(1)
		{
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9)){
				t_MaPL[vitri] = char(key);
				t_MaPL[vitri] = toupper(t_MaPL[vitri]);
				cout<< t_MaPL[vitri];
				vitri++;
			}
			if(key == ENTER && vitri != 0)
			{
				t_MaPL[vitri] = '\0';
				check_pl = dspl->CoincideMaPL(dspl->root, t_MaPL);
				if (!check_pl){
					GhiChu("MA PHIEU LINH KHONG TON TAI!", 35, 27, 79, 1000);
					gotoXY(28 + vitri, y);
					continue;
				}
				 dspl->NNDPL(dspl->root, t_MaPL);
				 GhiChu("XOA THANH CONG, F2 De Luu !!!", 20, 27, 79, 2000);
				 Sleep(500);
				 return;
				}
			if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(28 + vitri, y);
				cout<<" ";
				gotoXY(28 + vitri, y);
			}
			
			if(key == ESC){
				return;
			}
		}
}


//--------DONG KIEM KE-------
void DKK_Them(LinkListDKK *dsdkk,TreeThuoc *treeThuoc, int position){
	char strnumb[14];
	SOPHIEU:
	int key, vitri = 0, x = 33, y = 14, checkMaThuoc;
	ListNode_DKK *nf;
	DongKiemKe dkk; 
	KhungMenuThem_DKK(); gotoXY(x, y);	
		while(1){
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				gotoXY(33+vitri, 14);
				dkk.sophieu[vitri] = (char)key;
				dkk.sophieu[vitri] = toupper(dkk.sophieu[vitri]);
				cout<<dkk.sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(33 + vitri, y);
				cout<<" ";
				gotoXY(33 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				dkk.sophieu[vitri] = '\0';
					goto MATHUOC;
					break;
			}
			if(key == ESC) return;
		}
		MATHUOC:
			vitri = 0; gotoXY(56+vitri, 14);
			while(1){
				TextColor(14);
				key = GetKey(); 
				if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
				{	
					gotoXY(56+vitri, 14);
					dkk.maThuoc[vitri] = (char)key;
					dkk.maThuoc[vitri] = toupper(dkk.maThuoc[vitri]);
					cout<<dkk.maThuoc[vitri];
					vitri++;
				}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(56 + vitri, y);
				cout<<" ";
				gotoXY(56 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				dkk.maThuoc[vitri] = '\0';
				checkMaThuoc = treeThuoc->CheckMaThuoc(treeThuoc->rootT, dkk.maThuoc);
				nf = dsdkk->SearchDKK(dkk.sophieu, dkk.maThuoc);
				if(checkMaThuoc==true)
				{
					if(nf){
						GhiChu("SO PHIEU VA MA THUOC DA TON TAI!", 35, 27, 79, 1000);
						Sleep(1000);
						goto SOPHIEU;
					}
					else{
						KhungSua_DKK();
						TextColor(12);
						gotoXY(13, 14); cout<<dkk.sophieu;
						gotoXY(24, 14); cout <<dkk.maThuoc;
						goto SLTTRUOC;
					}
				}
				else
				{
					GhiChu("MA THUOC CHUA CO TRONG BANG THUOC. NHAP LAI!", 35, 27, 79, 1000);
					Sleep(1000);
					//gotoXY(56+vitri, 14);
					goto MATHUOC;
				}
				
			}
			if(key == ESC) return;
			}
		SLTTRUOC:
			vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu:  (0-9). Toi da: 9";
			TextColor(14); gotoXY(36 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 9))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(36 + vitri, y);
				cout << " ";
				gotoXY(36 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLTtruoc = atoi(strnumb);
				goto SLNTRONGNGAY;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		SLNTRONGNGAY:
			vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu:  (0-9). Toi da: 9";
			TextColor(14); gotoXY(50 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 9))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(50 + vitri, y);
				cout << " ";
				gotoXY(50 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLNtrongNgay = atoi(strnumb);
				goto SLXTRONGNGAY;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		
		SLXTRONGNGAY:
			vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu:  (0-9). Toi da: 9";
			TextColor(14); gotoXY(67 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 9))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(67 + vitri, y);
				cout << " ";
				gotoXY(67 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLXtrongNgay = atoi(strnumb);
				goto SLHETHAN;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		SLHETHAN:
			vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu:  (0-9). Toi da: 9";
			TextColor(14); gotoXY(81 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 9))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(81 + vitri, y);
				cout << " ";
				gotoXY(81 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLhetHan = atoi(strnumb);
				goto SLVOHONG;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		SLVOHONG:
			vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu:  (0-9). Toi da: 9";
			TextColor(14); gotoXY(93 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 9))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(93 + vitri, y);
				cout << " ";
				gotoXY(93 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLvoHong = atoi(strnumb);
				goto SLTONCUOINGAY;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		
		SLTONCUOINGAY:
			vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu:  (0-9). Toi da: 9";
			TextColor(14); gotoXY(105 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 9))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(105 + vitri, y);
				cout << " ";
				gotoXY(105 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLTcuoiNgay = atoi(strnumb);
				dsdkk->InsertDKK(dkk, position+1);
				GhiChu("Da luu thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;	
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
}

void DKK_Sua(LinkListDKK *dsdkk){
	char strnumb[14];
	SOPHIEU:
	int key, vitri = 0, x = 33, y = 14;
	ListNode_DKK *nf;
	DongKiemKe dkk; 
	KhungMenuSua_DKK(); gotoXY(x, y);	
		while(1){
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				gotoXY(33+vitri, 14);
				dkk.sophieu[vitri] = (char)key;
				dkk.sophieu[vitri] = toupper(dkk.sophieu[vitri]);
				cout<<dkk.sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(33 + vitri, y);
				cout<<" ";
				gotoXY(33 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				dkk.sophieu[vitri] = '\0';
					goto MATHUOC;
					break;
			}
			if(key == ESC) return;
		}
		MATHUOC:
			vitri = 0; gotoXY(56+vitri, 14);
			while(1){
				TextColor(14);
				key = GetKey(); 
				if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
				{	
					gotoXY(56+vitri, 14);
					dkk.maThuoc[vitri] = (char)key;
					dkk.maThuoc[vitri] = toupper(dkk.maThuoc[vitri]);
					cout<<dkk.maThuoc[vitri];
					vitri++;
				}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(56 + vitri, y);
				cout<<" ";
				gotoXY(56 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				dkk.maThuoc[vitri] = '\0';
				nf = dsdkk->SearchDKK(dkk.sophieu, dkk.maThuoc);
				if(nf){
					KhungSua_DKK();
					x = 15, y = 14;
					gotoXY(x, y);
					TextColor(12);
					gotoXY(13, 14); cout<<nf->data.sophieu;
					gotoXY(24, 14); cout <<nf->data.maThuoc;
					TextColor(14);
					gotoXY(36, 14); cout << nf->data.SLTtruoc;
					gotoXY(50, 14); cout << nf->data.SLNtrongNgay;
					gotoXY(67, 14); cout << nf->data.SLXtrongNgay;
					gotoXY(81, 14); cout << nf->data.SLhetHan;
					gotoXY(93, 14); cout << nf->data.SLvoHong;
					gotoXY(105, 14); cout << nf->data.SLTcuoiNgay;
					vitri = numlen(nf->data.SLTtruoc);
					gotoXY(36 + vitri, 14);
					goto SLTTRUOC;
					break;
				}
				else{
					GhiChu("SO PHIEU HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
					Sleep(1000);
					goto SOPHIEU;
				}
			}
			if(key == ESC) return;
			}
		SLTTRUOC:
			key = GetKey();
			if(key == ENTER) {
				dkk.SLTtruoc =  nf->data.SLTtruoc;
				
			}
			gotoXY(36, 14); cout << "          "; vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(36 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(36 + vitri, y);
				cout << " ";
				gotoXY(36 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLTtruoc = atoi(strnumb);
			A:
				vitri = numlen(nf->data.SLNtrongNgay);
				gotoXY(50+vitri, 14);
				goto SLNTRONGNGAY;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		SLNTRONGNGAY:
			key = GetKey();
			if(key == ENTER) {
				dkk.SLNtrongNgay =  nf->data.SLNtrongNgay;
				
			}
			gotoXY(50, 14); cout << "          "; vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(50 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(50 + vitri, y);
				cout << " ";
				gotoXY(50 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLNtrongNgay = atoi(strnumb);
		
				vitri = numlen(nf->data.SLXtrongNgay);
				gotoXY(67+vitri, 14);
				goto SLXTRONGNGAY;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		SLXTRONGNGAY:
			key = GetKey();
			if(key == ENTER) {
				dkk.SLXtrongNgay =  nf->data.SLXtrongNgay;
				
			}
			gotoXY(67, 14); cout << "          "; vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(67 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(67 + vitri, y);
				cout << " ";
				gotoXY(67 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLXtrongNgay = atoi(strnumb);
				vitri = numlen(nf->data.SLhetHan);
				gotoXY(81+vitri, 14);
				goto SLHETHAN;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		SLHETHAN:
			key = GetKey();
			if(key == ENTER) {
				dkk.SLhetHan =  nf->data.SLhetHan;
				
			}
			gotoXY(81, 14); cout << "          "; vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(81 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(81 + vitri, y);
				cout << " ";
				gotoXY(81 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLhetHan = atoi(strnumb);
			
				vitri = numlen(nf->data.SLvoHong);
				gotoXY(93+vitri, 14);
				goto SLVOHONG;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		SLVOHONG:
			key = GetKey();
			if(key == ENTER) {
				dkk.SLvoHong =  nf->data.SLvoHong;
				
			}
			gotoXY(93, 14); cout << "          "; vitri = 0;
			while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(93 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(93 + vitri, y);
				cout << " ";
				gotoXY(93 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLvoHong = atoi(strnumb);
		
				vitri = numlen(nf->data.SLTcuoiNgay);
				gotoXY(105+vitri, 14);
				goto SLTCUOINGAY;
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
		
	SLTCUOINGAY:
		key = GetKey();
		if(key == ENTER){
			dkk.SLTcuoiNgay =  nf->data.SLTcuoiNgay;
			
		} 
		gotoXY(105, 14); cout << "           "; vitri = 0;
		while (1)
		{
			TextColor(244);	gotoXY(13, 15); cout << "Ki tu: (A-Z) & (0-9). Toi da: 9";
			TextColor(14); gotoXY(105 + vitri, y); //Ghi ch?
			key = GetKey();
			if ((key <= '9' && key >= '0') && (vitri < 13))
			{
				strnumb[vitri] = char(key);
				cout << strnumb[vitri];
				vitri++;
			}
			if (key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(105 + vitri, y);
				cout << " ";
				gotoXY(105 + vitri, y);
			}
			if (key == ENTER && vitri != 0)
			{
				strnumb[vitri] = '\0';
				dkk.SLTcuoiNgay = atoi(strnumb);
			B:
				nf->data = dkk;
				GhiChu("Da sua thong tin. F2 de luu!!!", 40, 27, 228, 2000);	TextColor(12);
				return;	
			}
			
			if (key == ESC ) { 
			return; 
			}
		}
}

void DKK_Xoa(LinkListDKK *dsdkk){
	char t_sophieu[10], t_mathuoc[10];
	KhungXoa_DKK(); gotoXY(33, 14);
	ListNode_DKK *nf;
	SOPHIEU:
	int key, vitri = 0, x = 33, y = 14;
	KhungMenuSua_DKK(); gotoXY(x, y);	
		while(1){
			TextColor(14);
			key = GetKey();
			if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
			{	
				gotoXY(33+vitri, 14);
				t_sophieu[vitri] = (char)key;
				t_sophieu[vitri] = toupper(t_sophieu[vitri]);
				cout<<t_sophieu[vitri];
				vitri++;
			}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(33 + vitri, y);
				cout<<" ";
				gotoXY(33 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				t_sophieu[vitri] = '\0';
					goto MATHUOC;
					break;
			}
			if(key == ESC) return;
		}
		MATHUOC:
			vitri = 0; gotoXY(56+vitri, 14);
			while(1){
				TextColor(14);
				key = GetKey(); 
				if(((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 9))
				{	
					gotoXY(56+vitri, 14);
					t_mathuoc[vitri] = (char)key;
					t_mathuoc[vitri] = toupper(t_mathuoc[vitri]);
					cout<<t_mathuoc[vitri];
					vitri++;
				}
			
			 if(key == BACKSPACE && vitri > 0)
			{
				vitri--;
				gotoXY(56 + vitri, y);
				cout<<" ";
				gotoXY(56 + vitri, y);
			}
			
			if (key == ENTER && vitri != 0)
			{
				t_mathuoc[vitri] = '\0';
				nf = dsdkk->SearchDKK(t_sophieu, t_mathuoc);
				if(!nf){
					GhiChu("SO PHIEU HOAC MA THUOC KHONG TON TAI!", 35, 27, 79, 1000);
					gotoXY(33 + vitri, y);
					goto SOPHIEU;
				}
				else{
					dsdkk->DeleteDKK(t_sophieu, t_mathuoc);
					GhiChu("Da xoa dong xuat, F2 de luu!!!", 20, 27, 79, 2000);
			 		return;
				}
			}
			if(key == ESC) return;
			}
}

void HT_ThemSuaXoaDS()
{
	TreeHT treeHT;
	TreePN treePN;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluonght, dem = 0, demdong = 0;
	fflush(stdin);
	treePN.ReadFilePN(treePN.rootPN);
	treeHT.ReadFileHT(treeHT.rootHT);
	 
	while (1)
	{
		soluonght = treeHT.SoLuongNodeHT(treeHT.rootHT); 
		HangThuoc *ht = new HangThuoc[soluonght];	 
		treeHT.DuyetNLR(treeHT.rootHT, ht);
		if (soluonght < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluonght - 1) / 15 + 1);
		}
		
	
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		HT_KhungXuat();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluonght; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout <<(i + 1);
			TextColor(14);
			gotoXY(11, 8 + demdong); cout << ht[i].maHT;
			gotoXY(23, 8 + demdong); cout << ht[i].tenHT;
			gotoXY(52, 8 + demdong); cout << ht[i].sdt;
			gotoXY(66, 8 + demdong); cout << ht[i].diaChi;
			gotoXY(98, 8 + demdong); cout << ht[i].maSoThue;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 107, 26);
		key = GetKey();
		if ((key == RIGHT ) && trang < tongtrang - 1) 
		{ 
			trang++; 
		}
		if ((key == LEFT ) && trang > 0)
		{ 
		 	trang--;
		}
		
		if(key == F4)
		{
			HT_Sua(&treeHT);
			//MH_LuuFile(npmh);
		}
		
		if (key == INSERT)
		{			
			
			HT_Them(&treeHT);
		}
		
		if(key == DLT)
		{
			HT_Xoa(&treeHT, &treePN);
		}
		if(key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
				GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
				treeHT.SaveFileHT(treeHT.rootHT);
				treeHT.ReadFileHT(treeHT.rootHT);
					
				continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				treeHT.ReadFileHT(treeHT.rootHT);
				return;	
			}		
		}
		
		if(key == ESC)
		{
			return;
		}

	}
}

void Thuoc_ThemSuaXoaDS()
{
	TreeThuoc treeThuoc;
	ListCTPN CTPN;
	LinkListDKK listDKK;
	ListDL listDL;
	LinkListDX listDX;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongThuoc, dem = 0, demdong = 0;
	fflush(stdin);
	listDKK.ReadFileDKK();
	listDL.ReadFileDL(listDL.pHead);
	listDX.ReadFileDX();
	CTPN.ReadFileCTPN(CTPN.pHead);
	treeThuoc.ReadFileT(treeThuoc.rootT);
	 
	while (1)
	{
		soluongThuoc = treeThuoc.SoLuongNodeThuoc(treeThuoc.rootT); 
		Thuoc *thuoc = new Thuoc[soluongThuoc];	 
		treeThuoc.DuyetNLRThuoc(treeThuoc.rootT, thuoc);
		if (soluongThuoc < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongThuoc - 1) / 15 + 1);
		}
		
	
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		Thuoc_KhungXuat();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongThuoc; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(11, 8 + demdong); cout << thuoc[i].maThuoc;
			gotoXY(23, 8 + demdong); cout << thuoc[i].tenThuoc;
			gotoXY(47, 8 + demdong); cout << thuoc[i].nongDoHamLuong<<" mg/ml";
			gotoXY(60, 8 + demdong); cout << thuoc[i].noiSanXuat;
			gotoXY(93, 8 + demdong); cout << thuoc[i].donViTinh;
			gotoXY(104, 8 + demdong); cout << thuoc[i].hanDung.ngay << "/" << thuoc[i].hanDung.thang << "/" << thuoc[i].hanDung.nam;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 107, 26);
		
		key = GetKey();
		if ((key == RIGHT ) && trang < tongtrang - 1) 
		{ 
			trang++; 
		}
		if ((key == LEFT ) && trang > 0)
		{ 
		 	trang--;
		}
		
		if(key == F4)
		{
			Thuoc_Sua(&treeThuoc);
			//MH_LuuFile(npmh);
		}
		
		if (key == INSERT)
		{			
			
			Thuoc_Them(&treeThuoc);
		}
		
		if(key == DLT)
		{
			Thuoc_Xoa(&treeThuoc, &CTPN, &listDL,&listDKK, &listDX );
		}
		if(key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
				GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
				treeThuoc.SaveFileT(treeThuoc.rootT);
				treeThuoc.ReadFileT(treeThuoc.rootT);		
				continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				treeThuoc.ReadFileT(treeThuoc.rootT);
				return;	
			}		
		}
		
		if(key == ESC)
		{
			return;
		}

	}
}

void PN_ThemSuaXoaDS()
{
	TreeHT treeHT;
	TreePN treePN ;
	ListCTPN CTPN;
	TreeNV treeNV;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongpn, dem = 0, demdong = 0;
	fflush(stdin);
	treeNV.ReadFileNV();
	CTPN.ReadFileCTPN(CTPN.pHead);
	treePN.ReadFilePN(treePN.rootPN);
	treeHT.ReadFileHT(treeHT.rootHT);
	 
	while (1)
	{
		soluongpn = treePN.SoLuongNodePN(treePN.rootPN); 
		PhieuNhap *PN = new PhieuNhap[soluongpn];	 
		treePN.DuyetNLRPN(treePN.rootPN, PN);
		if (soluongpn < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongpn - 1) / 15 + 1);
		}
		
	
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		PhieuNhap_KhungXuat();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongpn; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(11, 8 + demdong); cout << PN[i].soPhieuNhap;
			gotoXY(23, 8 + demdong); cout << PN[i].maNV;
			gotoXY(35, 8 + demdong); cout << PN[i].maHT;
			date time = PN[i].ngayNhap;
			gotoXY(47, 8 + demdong); cout << time.ngay<<"/"<<time.thang<<"/"<<time.nam;
			gotoXY(60, 8 + demdong); cout << PN[i].tenKhoNhapThuoc;
			gotoXY(87, 8 + demdong); cout << PN[i].diaDiemNhap;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 107, 26);
		
		key = GetKey();
		if ((key == RIGHT ) && trang < tongtrang - 1) 
		{ 
			trang++; 
		}
		if ((key == LEFT ) && trang > 0)
		{ 
		 	trang--;
		}
		
		if(key == F4)
		{
			PN_Sua(&treePN, &treeHT, &treeNV);
			//MH_LuuFile(npmh);
		}
		
		if (key == INSERT)
		{			
			
			PN_Them(&treePN, &treeHT, &treeNV);
		}
		
		if(key == DLT)
		{
			PN_Xoa(&treePN, &CTPN);
		}
		if(key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
				GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
				treePN.SaveFilePN(treePN.rootPN);
				treePN.ReadFilePN(treePN.rootPN);	
				continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				treePN.ReadFilePN(treePN.rootPN);
				continue;	
			}		
		}
		
		if(key == ESC)
		{
			return;
		}

	}
}

void CTPN_ThemSuaXoaDS()
{
	TreeThuoc treeT;
	TreePN treePN ;
	ListCTPN listCTPN;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongCTPN, dem = 0, demdong = 0;
	fflush(stdin);
	treePN.ReadFilePN(treePN.rootPN);
	treeT.ReadFileT(treeT.rootT);
	listCTPN.ReadFileCTPN(listCTPN.pHead);
	 
	while (1)
	{
		soluongCTPN = listCTPN.CTPN_demSL(); 
		CHITIETPN *CTPN = new CHITIETPN[soluongCTPN];	 
		listCTPN.CTPN_Array(CTPN);
		if (soluongCTPN < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongCTPN - 1) / 15 + 1);
		}
		
	
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		CTPhieuNhap_KhungXuat();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongCTPN; i++)
		{
			TextColor(12); gotoXY(15, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(21, 8 + demdong); cout << CTPN[i].soPhieuNhap;
			gotoXY(35, 8 + demdong); cout << CTPN[i].maThuoc;
			gotoXY(51, 8 + demdong); cout << CTPN[i].soLuongNhap;
			gotoXY(64, 8 + demdong); cout << CTPN[i].donGia;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 107, 26);
		
		key = GetKey();
		if ((key == RIGHT ) && trang < tongtrang - 1) 
		{ 
			trang++; 
		}
		if ((key == LEFT ) && trang > 0)
		{ 
		 	trang--;
		}
		
		if(key == F4)
		{
			CTPN_Sua(&listCTPN, &treePN, &treeT);
			
		}
		
		if (key == INSERT)
		{			
			
			CTPN_Them(&listCTPN, &treePN, &treeT);
		}
		
		if(key == DLT)
		{
			CTPN_Xoa(&listCTPN);
		}
		if(key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
				GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
				listCTPN.SaveFileCTPN(listCTPN.pHead);
				listCTPN.ReadFileCTPN(listCTPN.pHead);			
				continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				listCTPN.ReadFileCTPN(listCTPN.pHead);
				continue;	
			}		
		}
		
		if(key == ESC)
		{
			return;
		}
		delete [] CTPN;
	}
}

void DL_ThemSuaXoaDS()
{
	TreeThuoc treeT;
	TreePL treePL ;
	ListDL listDL;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongDL, dem = 0, demdong = 0;
	fflush(stdin);
	treePL.ReadFilePL();
	treeT.ReadFileT(treeT.rootT);
	listDL.ReadFileDL(listDL.pHead);
	 
	while (1)
	{
		soluongDL = listDL.DL_demSL(); 
		DongLinh *dlinh = new DongLinh[soluongDL];	 
		listDL.DL_Array(dlinh);
		if (soluongDL < 15)
		{
			tongtrang = 1;
			trang = 0;
		}
		else {
			tongtrang = ((soluongDL - 1) / 15 + 1);
		}
		
	
		dem = 0; demdong = 0;
		TextColor(14);	system("cls");
		DongLinh_KhungXuat();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongDL; i++)
		{
			TextColor(12); gotoXY(15, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(21, 8 + demdong); cout << dlinh[i].soPhieuLinh;
			gotoXY(35, 8 + demdong); cout << dlinh[i].maThuoc;
			gotoXY(51, 8 + demdong); cout << dlinh[i].slYeuCau;
			gotoXY(64, 8 + demdong); cout << dlinh[i].slCapPhat;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 107, 26);
		
		key = GetKey();
		if ((key == RIGHT ) && trang < tongtrang - 1) 
		{ 
			trang++; 
		}
		if ((key == LEFT ) && trang > 0)
		{ 
		 	trang--;
		}
		
		if(key == F4)
		{
			DL_Sua(&listDL, &treeT);
			
		}
		
		if (key == INSERT)
		{			
			
			DL_Them(&listDL, &treePL, &treeT);
		//	DL_Them(&listDL, &treeT);
		}
		
		if(key == DLT)
		{
			DL_Xoa(&listDL);
		}
		if(key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
				GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
				listDL.SaveFileDL(listDL.pHead);
				listDL.ReadFileDL(listDL.pHead);			
				continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				listDL.ReadFileDL(listDL.pHead);
				continue;	
			}		
		}
		
		if(key == ESC)
		{
			return;
		}
		delete [] dlinh;

	}
}


void MH_ChucNangPX(){
	TreePX dspx;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongdx, dem = 0, demdong = 0;
	fflush(stdin);
	
	dspx.ReadFilePX();
	// Tao mot linklist dongxuat, dc doc tu file
	LinkListDX dongxuat;  // Co khoa ngoai den SOPHIEU, tu DongXuat
	TreeNV dsnv;  // la khoa ngoai den bang dsnv
	TreeKCN dskcn;  // la khoa ngoai den bang dsnv
	
	dongxuat.ReadFileDX();
	dsnv.ReadFileNV();
	dskcn.ReadFileKCN();
	
	while(1)
	{	
		soluongdx = dspx.SizeOfPX(dspx.root);
		PhieuXuat *px = new PhieuXuat[soluongdx];
		dspx.ArrayPX(dspx.root, px);
		
		if(px == NULL) {
			cout<<"loi cap phat bo nho"; getch(); return;
			}
		if (soluongdx < 15){
			tongtrang = 1;
			trang = 0;
		}
		else{
			tongtrang = (soluongdx - 1) / 15 + 1;
		}
		
		dem = 0; demdong = 0;
		TextColor(14); 	
		system("cls");
		KhungXuat_PX();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongdx; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + demdong); cout << px[i].sophieu;
			gotoXY(22, 8 + demdong); cout << px[i].manv;
			gotoXY(34, 8 + demdong); cout << px[i].makhoacn;
			ThoiGian time = px[i].ngayxuat;
			gotoXY(46, 8 + demdong); cout << time.ngay<<"/"<<time.thang<<"/"<<time.nam;
			gotoXY(57, 8 + demdong); cout << px[i].tenkhont;
			gotoXY(83, 8 + demdong); cout << px[i].tenkhoxt;
			gotoXY(95, 8 + demdong); cout << px[i].manvnew;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 92, 26);
		
		key = GetKey();
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			trang++;
		}
		
		if((key == LEFT) && trang > 0)
		{
			trang--;
		}
		
		if(key == F4)
		{
			PX_Sua(&dspx, dsnv, dskcn);
		}
		
		if (key == INSERT)
		{
			PX_Them(&dspx, dsnv, dskcn);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					dspx.SaveFilePX();
					dspx.ReadFilePX();
//					dongxuat.SaveFileDX();
//					dongxuat.ReadFileDX();
					continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				dspx.ReadFilePX();
				dongxuat.ReadFileDX();
				continue;	
			}	
		}
		
		if(key == DLT)
		{	
			PX_Xoa(&dspx, &dongxuat);
		}
		
		if(key == ESC){
			return;
		}
		delete [] px;
	}
}


void MH_ChucNangDX(){
	TreeThuoc treeT;
	LinkListDX dsdx;
	TreePX dspx; // Khoa ngoai bang PhieuXuat
	
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongdx, dem = 0, demdong = 0;
	fflush(stdin);
	dspx.ReadFilePX();	// Doc file PhieuXuat
	dsdx.ReadFileDX();
	treeT.ReadFileT(treeT.rootT);
	
	
	while(1)
	{	
		soluongdx = dsdx.SizeOfDX();
		DongXuat *dx = new DongXuat[soluongdx];
		dsdx.ArrayDX(dx);
		
		if(dx == NULL) {
			cout<<"loi cap phat bo nho"; getch(); return;
			}
		if (soluongdx < 15){
			tongtrang = 1;
			trang = 0;
		}
		else{
			tongtrang = (soluongdx - 1) / 15 + 1;
		}
		
		dem = 0; demdong = 0;
		TextColor(14); 	system("cls");
		KhungXuat_DX();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongdx; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + demdong); cout << dx[i].sophieu;
			gotoXY(22, 8 + demdong); cout << dx[i].mathuoc;
			gotoXY(34, 8 + demdong); cout << dx[i].slxuat;
			gotoXY(46, 8 + demdong); cout << dx[i].dongia;
			ThoiGian time = dx[i].ngayxuat;
			gotoXY(60, 8 + demdong); cout << time.ngay<<"/"<<time.thang<<"/"<<time.nam;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 92, 26);
		
		key = GetKey();
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			trang++;
		}
		
		if((key == LEFT) && trang > 0)
		{
			trang--;
		}
		
		if(key == F4)
		{
			DX_Sua(&dsdx);
		}
		
		if (key == INSERT)
		{
			DX_Them(&dsdx, dspx, &treeT, soluongdx);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					dsdx.SaveFileDX();
					dsdx.ReadFileDX();
					continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				dsdx.ReadFileDX();
				continue;	
			}	
		}
		
		if(key == DLT)
		{	
			DX_Xoa(&dsdx);
		}
		
		if(key == ESC){
			return;
		}
		delete [] dx;
	}
}



void MH_ChucNangNV(){
	TreeNV dsnv;
	TreePX dspx; // Khoa ngoai px
	TreePL dspl; // Khoa ngoai pl
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongnv, dem = 0, demdong = 0;
	fflush(stdin);
	
	dsnv.ReadFileNV();
	dspx.ReadFilePX();	// Doc file PX	
	dspl.ReadFilePL();  // Doc file PL
	while(1)
	{	
		soluongnv = dsnv.SizeOfNV(dsnv.root);
		NhanVien *nv = new NhanVien[soluongnv];
		dsnv.ArrayNV(dsnv.root, nv);
		
		if(nv == NULL) {
			cout<<"loi cap phat bo nho"; getch(); return;
			}
		if (soluongnv < 15){
			tongtrang = 1;
			trang = 0;
		}
		else{
			tongtrang = (soluongnv - 1) / 15 + 1;
		}
		
		dem = 0; demdong = 0;
		TextColor(14); 	system("cls");;
		KhungXuat_NV();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongnv; i++)
		{
			TextColor(12); gotoXY(16, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(20, 8 + demdong); cout << nv[i].maNV;
			gotoXY(32, 8 + demdong); cout << nv[i].hoTen;
			gotoXY(56, 8 + demdong); cout << nv[i].chucVu;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 92, 26);
		
		key = GetKey();
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			trang++;
		}
		
		if((key == LEFT) && trang > 0)
		{
			trang--;
		}
		
		if(key == F4)
		{
			NV_Sua(&dsnv);
		}
		
		if (key == INSERT)
		{
			NV_Them(&dsnv);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					dsnv.SaveFileNV();
					dsnv.ReadFileNV();
					continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				dsnv.ReadFileNV();
				continue;	
			}	
		}
		
		if(key == DLT)
		{	
			NV_Xoa(&dsnv, dspx, dspl); 
		}
		
		if(key == ESC){
			return;
		}
		delete [] nv;
	}
//	getch();
}

void MH_ChucNangNVKK(){
	TreeNVKK dsnvkk;
	TreeNV dsnv;  // khoa ngoai den bang NhanVien
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongnvkk, dem = 0, demdong = 0;
	fflush(stdin);
	
	dsnvkk.ReadFileNVKK();
	dsnv.ReadFileNV();  // Doc file Nhan Vien
	
	while(1)
	{	
		soluongnvkk = dsnvkk.SizeOfNVKK(dsnvkk.root);
		NVKiemKe *nvkk = new NVKiemKe[soluongnvkk];
		dsnvkk.ArrayNVKK(dsnvkk.root, nvkk);
		
		if(nvkk == NULL) {
			cout<<"loi cap phat bo nho"; getch(); return;
			}
		if (soluongnvkk < 15){
			tongtrang = 1;
			trang = 0;
		}
		else{
			tongtrang = (soluongnvkk - 1) / 15 + 1;
		}
		
		dem = 0; demdong = 0;
		TextColor(14); 	system("cls");;
		KhungXuat_NVKK();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongnvkk; i++)
		{
			TextColor(12); gotoXY(16, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(20, 8 + demdong); cout << nvkk[i].sophieu;
			gotoXY(34, 8 + demdong); cout << nvkk[i].manv;
			ThoiGian time = nvkk[i].ngayKiemKe;
			gotoXY(47, 8 + demdong); cout << time.ngay<<"/"<<time.thang<<"/"<<time.nam;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 92, 26);
		
		key = GetKey();
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			trang++;
		}
		
		if((key == LEFT) && trang > 0)
		{
			trang--;
		}
		
		if(key == F4)
		{
			NVKK_Sua(&dsnvkk, dsnv);
		}
		
		if (key == INSERT)
		{
			NVKK_Them(&dsnvkk, dsnv);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					dsnvkk.SaveFileNVKK();
					dsnvkk.ReadFileNVKK();
					continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				dsnvkk.ReadFileNVKK();
				continue;	
			}	
		}
		
		if(key == DLT)
		{	
			NVKK_Xoa(&dsnvkk); 
		}
		
		if(key == ESC){
			return;
		}
		delete [] nvkk;
	}
}


void MH_ChucNangKCN(){
	TreeKCN dskcn;
	TreePX dspx;	// khoa ngoai makcn phieu xuat
	TreePL dspl;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongkcn, dem = 0, demdong = 0;
	fflush(stdin);
	
	dskcn.ReadFileKCN();
	dspx.ReadFilePX();	// doc file phieu xuat
	dspl.ReadFilePL();
	
	while(1)
	{	
		soluongkcn = dskcn.SizeOfKCN(dskcn.root);
		KhoaChucNang *kcn = new KhoaChucNang[soluongkcn];
		dskcn.ArrayKCN(dskcn.root, kcn);
		
		if(kcn == NULL) {
			cout<<"loi cap phat bo nho"; getch(); return;
			}
		if (soluongkcn < 15){
			tongtrang = 1;
			trang = 0;
		}
		else{
			tongtrang = (soluongkcn - 1) / 15 + 1;
		}
		
		dem = 0; demdong = 0;
		TextColor(14); 	system("cls");;
		KhungXuat_KCN();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongkcn; i++)
		{
			TextColor(12); gotoXY(16, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(20, 8 + demdong); cout << kcn[i].maKCN;
			gotoXY(32, 8 + demdong); cout << kcn[i].tenKCN;
			gotoXY(56, 8 + demdong); cout << kcn[i].tenNguoiDD;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 92, 26);
		
		key = GetKey();
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			trang++;
		}
		
		if((key == LEFT) && trang > 0)
		{
			trang--;
		}
		
		if(key == F4)
		{
			KCN_Sua(&dskcn);
		}
		
		if (key == INSERT)
		{
			KCN_Them(&dskcn);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					dskcn.SaveFileKCN();
					dskcn.ReadFileKCN();
					continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				dskcn.ReadFileKCN();
				continue;	
			}	
		}
		
		if(key == DLT)
		{	
			KCN_Xoa(&dskcn, dspx, dspl);	
		}
		
		if(key == ESC){
			return;
		}
		delete [] kcn;
	}
}


void MH_ChucNangPL(){
	TreePL dspl;
	TreeNV dsnv;	//Khoa ngoai manv
	TreeKCN dskcn;	//Khoa ngoai dskcn;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongpl, dem = 0, demdong = 0;
	fflush(stdin);
	
	dspl.ReadFilePL(); 
	dsnv.ReadFileNV();	// Doc file NhanVien
	dskcn.ReadFileKCN();	//Doc file KhoaChucNang
	while(1)
	{	
		soluongpl = dspl.SizeOfPL(dspl.root);
		PhieuLinh *pl = new PhieuLinh[soluongpl];
		dspl.ArrayPL(dspl.root, pl);
		
		if(pl == NULL) {
			cout<<"loi cap phat bo nho"; getch(); return;
			}
		if (soluongpl < 15){
			tongtrang = 1;
			trang = 0;
		}
		else{
			tongtrang = (soluongpl - 1) / 15 + 1;
		}
		
		dem = 0; demdong = 0;
		TextColor(14); 	system("cls");;
		KhungXuat_PL();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongpl; i++)
		{
			TextColor(12); gotoXY(16, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(21, 8 + demdong); cout << pl[i].sophieu;
			gotoXY(34, 8 + demdong); cout << pl[i].maNV;
			gotoXY(49, 8 + demdong); cout << pl[i].maKCN;
			ThoiGian1 time = pl[i].ngayYC;
			gotoXY(60, 8 + demdong); cout << time.ngay<<"/"<<time.thang<<"/"<<time.nam;
		
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 92, 26);
		
		key = GetKey();
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			trang++;
		}
		
		if((key == LEFT) && trang > 0)
		{
			trang--;
		}
		
		if(key == F4)
		{
			PL_Sua(&dspl, dsnv, dskcn);
		}
		
		if (key == INSERT)
		{
			PL_Them(&dspl, dsnv, dskcn);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					dspl.SaveFilePL();
					dspl.ReadFilePL();
					continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				dspl.ReadFilePL();
				continue;	
			}	
		}
		
		if(key == DLT)
		{	
			PL_Xoa(&dspl);
		}
		
		if(key == ESC){
			return;
		}
		delete [] pl;
	}
}

void MH_ChucNangDKK(){
	LinkListDKK dsdkk;
	TreeThuoc treeThuoc;
	int key;
	int STT = 1, trang = 0, tongtrang = 0;
	int soluongdkk, dem = 0, demdong = 0;
	fflush(stdin);
	treeThuoc.ReadFileT(treeThuoc.rootT);
	dsdkk.ReadFileDKK();
	
	while(1)
	{	
		soluongdkk = dsdkk.SizeOfDKK();
		DongKiemKe *dkk = new DongKiemKe[soluongdkk];
		dsdkk.ArrayDKK(dkk);
		
		if(dkk == NULL) {
			cout<<"loi cap phat bo nho"; getch(); return;
			}
		if (soluongdkk < 15){
			tongtrang = 1;
			trang = 0;
		}
		else{
			tongtrang = (soluongdkk - 1) / 15 + 1;
		}
		
		dem = 0; demdong = 0;
		TextColor(14); 	system("cls");
		KhungXuat_DKK();
		for (int i = trang * 15; i < 15 + trang * 15 && i < soluongdkk; i++)
		{
			TextColor(12); gotoXY(6, 8 + demdong); cout << (i + 1);
			TextColor(14);
			gotoXY(10, 8 + demdong); cout << dkk[i].sophieu;
			gotoXY(22, 8 + demdong); cout << dkk[i].maThuoc;
			gotoXY(38, 8 + demdong); cout << dkk[i].SLTtruoc;
			gotoXY(51, 8 + demdong); cout << dkk[i].SLNtrongNgay;
			gotoXY(64, 8 + demdong); cout << dkk[i].SLXtrongNgay;
			gotoXY(76, 8 + demdong); cout << dkk[i].SLhetHan;
			gotoXY(86, 8 + demdong); cout << dkk[i].SLvoHong;
			gotoXY(103, 8 + demdong); cout << dkk[i].SLTcuoiNgay;
			demdong++;
		}
		PhanTrang(trang + 1, tongtrang, 92, 26);
		
		key = GetKey();
		if((key == RIGHT) && trang < tongtrang - 1)
		{
			trang++;
		}
		
		if((key == LEFT) && trang > 0)
		{
			trang--;
		}
		
		if(key == F4)
		{
			DKK_Sua(&dsdkk);
		}
		
		if (key == INSERT)
		{
			DKK_Them(&dsdkk,&treeThuoc, soluongdkk);
		}
		
		if (key == F2)
		{
			int tamp = ThongBao_LuuFile();
			if (tamp == -1) { continue; }
			if (tamp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 79, 2000);
					dsdkk.SaveFileDKK();
					dsdkk.ReadFileDKK();
					continue;
			}
			if (tamp == 0) 
			{ 
				GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 79, 2000);
				dsdkk.ReadFileDKK();
				continue;	
			}	
		}
		
		if(key == DLT)
		{	
			DKK_Xoa(&dsdkk);
		}
		
		if(key == ESC){
			return;
		}
		delete [] dkk;
	}
}

int ChonMENU(){
	int color = 0;
	while(1){
		system("cls");
		GioiThieu();
//		GhiChu("ESC De thoat", 35, 27, 79, 2000);
		for(int i = 0; i< 12; i++){
			if( i == 0) color = 236;	
			else color = 240;
			ToMauMenuChinh(color, i);
		}
		gotoXY(24, 7);	
		int chon = MenuCha();
//		cout<<"Chon: "<< chon;getch();
		switch(chon)
		{
			case 1:{
				system("cls");
				HT_ThemSuaXoaDS();
				break;
			}
			case 2:{
				system("cls");
				Thuoc_ThemSuaXoaDS();
				break;
			}
			case 3:{
				system("cls");
				PN_ThemSuaXoaDS();
				break;
			}
			case 4:{
				system("cls");
				CTPN_ThemSuaXoaDS();
				break;
			}
			case 5:{
				system("cls");
				DL_ThemSuaXoaDS();
				break;
			}
			case 6:{
				system("cls");
				MH_ChucNangPX();
				break;
			}
			case 7:{
				system("cls");
				MH_ChucNangNV();
				break;
			}
			case 8:{
				system("cls");
				MH_ChucNangKCN();
				break;
			}
			case 9:{
				system("cls");
				MH_ChucNangDX();
				break;
			}
			case 10:{
				system("cls");
				MH_ChucNangPL();
				break;
			}
			case 11:{
				system("cls");
				MH_ChucNangDKK();
				break;
			}
			case 12:{
				system("cls");
				MH_ChucNangNVKK();
				break;
			}
		}
	}
}

int main(){
	SetConsoleOutputCP(65001);
	DisableCtrButton(0, 1, 1);
	ChonMENU();
	getche();

}


