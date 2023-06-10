#pragma once
#include<iostream>
#include<string.h>
#include <string>
#include <fstream>

#include"Thuoc.h"
#include"CTPhieuNhap.h"
#include"Date.h"


using namespace std;

class Thuoc{
    public:
        char maThuoc[10];
        char tenThuoc[100];
//        char tenHoatChat[50];
        char nongDoHamLuong[10];
//        char soDangKy[15];
        char noiSanXuat[50];
        char donViTinh[20];
        date hanDung;
        Thuoc(){};
        Thuoc(char *maThuoc, char *tenThuoc, char *nongDoHamLuong, char *noiSanXuat, char *donViTinh, date hanDung){
            strcpy(this->maThuoc, maThuoc);
            strcpy(this->tenThuoc, tenThuoc);
//            strcpy(this->tenHoatChat, tenHoatChat);
            strcpy(this->nongDoHamLuong, nongDoHamLuong);
//            strcpy(this->soDangKy, soDangKy);
            strcpy(this->noiSanXuat, noiSanXuat);
            strcpy(this->donViTinh, donViTinh);
            this->hanDung = hanDung;
        }
};

class NodeT{
    public:
        Thuoc dataT;
        NodeT *left;
        NodeT *right;
        int height;
        NodeT(){};
};

class TreeThuoc{
    public:
        NodeT *rootT;

        int height(NodeT *rootT);
        int getBalance(NodeT *rootT);
        bool isExistT(char maThuoc[]);
        int SoLuongNodeThuoc(NodeT *rootT);
        bool checkForeignKeyMaThuoc(NodeT* rootT, NodeCTPN* pHead);
        NodeT* taoNodeT(Thuoc ht);
        bool CheckMaThuoc(NodeT *rootT, char maThuoc[]);
        NodeT* rotateLeft(NodeT* rootT);
        NodeT* rotateLeftRight(NodeT* rootT);
        NodeT* rotateRight(NodeT* rootT);
        NodeT* rotateRightLeft(NodeT* rootT);
        NodeT* insertT(NodeT *&rootT, NodeT *p);
        void createT(NodeT* &rootT);
        NodeT* findMinT(NodeT *rootT);
        void tempT(NodeT* des, NodeT *src);
        NodeT* deleteNodeT(NodeT *&rootT, char maThuoc[]);
        void deleteInfoT(NodeT*&rootT);
        NodeT* searchT(NodeT* rootT, char maThuoc[]);
        NodeT* searchInfoT(NodeT* rootT);
        void writefileT(ofstream &fileOut, NodeT* rootT);
        void SaveFileT(NodeT *rootT);
        void ReadFileT(NodeT* &rootT);
        void printT(NodeT *rootT);
        void DuyetNLRThuoc(NodeT* rootT, Thuoc *thuoc);
        void DeleteAllT(NodeT *&rootT);

};




