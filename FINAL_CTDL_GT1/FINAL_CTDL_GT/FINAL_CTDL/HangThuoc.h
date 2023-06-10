#pragma once

#include<iostream>
#include<string.h>	
#include<fstream>
#include<stdlib.h>	
#include<stack>
#include<conio.h>
#include <ctime>
#include<sstream>


using namespace std;

class HangThuoc{
    public:
        char maHT[10];
        char tenHT[100];
        char sdt[12];
        char diaChi[50];
        char maSoThue[10];
        
        HangThuoc(){};
        HangThuoc(char *maHT, char *tenHT, char *sdt, char *diaChi, char *maSoThue){
            strcpy(this->maHT, maHT);
            strcpy(this->tenHT, tenHT);
            strcpy(this->sdt, sdt);
            strcpy(this->diaChi, diaChi);
//            strcpy(this->fax, fax);
//            strcpy(this->soTK, soTK);
            strcpy(this->maSoThue, maSoThue);
        }
};

class NodeHT{
    public:
        HangThuoc dataHT;
        NodeHT *left;
        NodeHT *right;
        int height;
        
        NodeHT(){};
};

class TreeHT{
    public:
        NodeHT *rootHT;
        int height(NodeHT *rootHT);
        int getBalance(NodeHT *rootHT);
//        bool checkMa_HT_PN(NodeHT* rootHT);
        int SoLuongNodeHT(NodeHT *rootHT);
        void SapXepHT(NodeHT *rootHT ,HangThuoc ht[], int dem);
        void HoanViHT(HangThuoc &ht1, HangThuoc &ht2);
        NodeHT* taoNodeHT(HangThuoc ht);
        bool CheckMaHT(NodeHT *rootHT, const char* maht);
        NodeHT* rotateLeft(NodeHT* rootHT);
        NodeHT* rotateLeftRight(NodeHT* rootHT);
        NodeHT* rotateRight(NodeHT* rootHT);
        NodeHT* rotateRightLeft(NodeHT* rootHT);
        NodeHT* insertHT(NodeHT *&rootHT, NodeHT *p);
        void CreateHT(NodeHT* &rootHT);
        NodeHT* findMinHT(NodeHT *rootHT);
        void tempHT(NodeHT* des, NodeHT *src);
        NodeHT* deleteNodeHT(NodeHT *&rootHT, char maht[]);
        void deleteInfoHT(NodeHT*&rootHT);
        NodeHT* searchHT(NodeHT* rootHT, char maht[]);
        NodeHT* searchInfoHT(NodeHT* rootHT);
        void writefileHT(ofstream &fileOut, NodeHT*rootHT);
        void SaveFileHT(NodeHT *rootHT);
        void ReadFileHT(NodeHT* &rootHT);
        void printHT(NodeHT *rootHT);
        void DeleteAllHT(NodeHT *&rootHT);
        void DuyetNLR(NodeHT* rootHT, HangThuoc *ht);

};





