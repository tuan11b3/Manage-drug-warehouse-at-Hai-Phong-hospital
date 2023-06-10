#pragma once

#include"DoHoa.h"

#define ENTER 13 
#define ESC 27
#define DOWN 80
#define UP 72
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define TAB 9
#define INSERT 82
#define BACKSPACE 8
#define DLT 83
#define F5 63
#define F2 60 //Save
#define F4 62 //Edit

int GetKey();

void GioiThieu();

void GhiChu(string c, int x, int y, int color, int sleep);

void xoaKhungNhap();

void khungThongTin();

void PhanTrang(int trang, int tongtrang, int x, int y) ;

int ThongBao_LuuFile();
//========HANG THUOC===========
int ThongBao_HuyHT();
void HT_KhungXuat();
void HT_KhungMenuSua();
void HT_KhungMenuXoa();
void HT_KhungThem();
void HT_KhungSua();

//============THUOC============
int	 ThongBao_HuyThuoc();
void Thuoc_KhungXuat();
void Thuoc_KhungMenuSua();
void Thuoc_KhungMenuXoa();
void Thuoc_KhungThem();
void Thuoc_KhungSua();

//============PHIEU NHAP==============
int	 ThongBao_HuyPhieuNhap();
void PhieuNhap_KhungXuat();
void PhieuNhap_KhungMenuSua();
void PhieuNhap_KhungMenuXoa();
void PhieuNhap_KhungThem();
void PhieuNhap_KhungSua();
int ThongBaoXoaMa_HT_PN();

//===============CHI TIET PHIEU NHAP======
int ThongBao_HuyCTPN();
void CTPhieuNhap_KhungXuat();
void CTPhieuNhap_KhungMenuSua();
void CTPhieuNhap_KhungMenuXoa();
void CTPhieuNhap_KhungThem();
void CTPhieuNhap_KhungSua();
int ThongBaoXoaSoPhieu_CTPN();

//==============DONG LINH=============
int ThongBao_HuyDL();
void DongLinh_KhungXuat();
void DongLinh_KhungMenuSua();
void DongLinh_KhungMenuXoa();
void DongLinh_KhungThem();
void DongLinh_KhungSua();

//  DO HOA PhieuXuat
void KhungXuat_PX();
void PX_KhungMenuSua();
void PX_KhungMenuThem();
void PX_KhungSua();
int ThongBaoXoaFK_PX();
void PX_KhungXoa();

// DO HOA DongXuat
void KhungXuat_DX();
void DX_KhungMenuThem();
void DX_KhungMenuSua();
void DX_KhungSua();
void DX_KhungXoa();

// GIAO DIEN NhanVien
void KhungXuat_NV();
void NV_KhungMenuSua();
void NV_KhungMenuThem();
void NV_KhungThem();
void NV_KhungSua();
int ThongBaoXoaFK_NV();
void NV_KhungXoa();

// GIAO DIEN NVKiemKe
void KhungXuat_NVKK();
void NVKK_KhungMenuSua();
void NVKK_KhungMenuThem();
void NVKK_KhungSua();
void NVKK_KhungThem();
int ThongBaoXoaFK_NVKK();
void NVKK_KhungXoa();

// GIAO DIEN Khoa Chuc Nang
void KhungXuat_KCN();
void KCN_KhungMenuSua();
void KCN_KhungMenuThem();
void KCN_KhungSua();
void KCN_KhungThem();
void KCN_KhungXoa();

// GIAO DIEN Phieu linh
void KhungXuat_PL();
void PL_KhungMenuSua();
void PL_KhungMenuThem();
void PL_KhungSua();
void PL_KhungThem();
void PL_KhungXoa();

// GIAO DIEN Dong Kiem Ke
void KhungXuat_DKK();
void KhungMenuSua_DKK();
void KhungMenuThem_DKK();
void KhungSua_DKK();
void KhungXoa_DKK();






