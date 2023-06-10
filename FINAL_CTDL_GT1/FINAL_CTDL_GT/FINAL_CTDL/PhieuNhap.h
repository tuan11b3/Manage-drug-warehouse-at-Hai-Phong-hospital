#pragma once

#include<iostream>
#include<conio.h>
#include<string.h>
#include <fstream>
#include<stdio.h>

#include"Date.h"
#include"CTPhieuNhap.h"
#include "HangThuoc.h"



using namespace std;

class PhieuNhap{
    public:
        char soPhieuNhap[10];
        char maNV[10];
        char maHT[10];
        date ngayNhap;
        char tenKhoNhapThuoc[50];
        char diaDiemNhap[50];
        
        PhieuNhap(){};
        PhieuNhap(char *soPhieuNhap, char *maNV, char *maHT, date ngayNhap, char *tenKhoNhapThuoc, char *diaDiemNhap)
        {
            strcpy(this->soPhieuNhap, soPhieuNhap);
            strcpy(this->maNV, maNV);
            strcpy(this->maHT, maHT);
            this->ngayNhap = ngayNhap;
            strcpy(this->tenKhoNhapThuoc, tenKhoNhapThuoc);
            strcpy(this->diaDiemNhap, diaDiemNhap);
        }
};
class NodePN{
    public:
        PhieuNhap dataPN;
        NodePN *left;
        NodePN *right;
        int height;
 
        NodePN(){};

};
class TreePN{
    public:
        NodePN *rootPN;
        
        int height(NodePN *rootPN);
        int getBalance(NodePN *rootPN);
        bool checkForeignKeyChiTietPN(NodePN* rootPN);
        bool CheckMaPN(NodePN *rootPN, char soPhieu[]);
        bool checkMa_HT_PN(NodePN *rootPN,char* maHT) ;
        int SoLuongNodePN(NodePN *rootPN);
        void DuyetNLRPN(NodePN* rootPN, PhieuNhap *phieunhap);
        NodePN* taoNodePN(PhieuNhap phieunhap);
      //  bool CheckTrungPN(NodePN *rootPN, char soPhieu[]);
        NodePN* rotateLeft(NodePN* rootPN);
        NodePN* rotateLeftRight(NodePN* rootPN);
        NodePN* rotateRight(NodePN* rootPN);
        NodePN* rotateRightLeft(NodePN* rootPN);
        NodePN* insertPN(NodePN *&rootPN, NodePN *p);
        void createPN(NodePN* &rootPN);
        NodePN* findMinPN(NodePN *rootPN);
        void tempPN(NodePN* des, NodePN *src);
        NodePN* deleteNodePN(NodePN *&rootPN, char soPhieu[]);
        void deleteInfoPN(NodePN*&rootPN);
        NodePN* searchPN(NodePN* rootPN, char soPhieu[]);
        NodePN* searchInfoPN(NodePN* rootPN);
        void writefilePN(ofstream &fileOut, NodePN*rootPN);
        void SaveFilePN(NodePN *rootPN);
        void ReadFilePN(NodePN* &rootPN);
        void printPN(NodePN *rootPN);
        void DeleteAllPN(NodePN *&rootPN);
};




