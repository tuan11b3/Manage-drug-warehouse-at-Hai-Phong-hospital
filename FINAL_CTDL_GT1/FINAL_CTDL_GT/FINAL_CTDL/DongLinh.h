#pragma once

#include<iostream>
#include<stdio.h>
#include<string.h>
#include <fstream>
#include <cstdlib>


using namespace std;


class DongLinh{
    public:
        char soPhieuLinh[10];
        char maThuoc[10];
        int slYeuCau;
        int slCapPhat;

       	DongLinh(){};
        DongLinh(char *soPhieuLinh, char *maThuoc, int slYeuCau, int slCapPhat)
        {
            strcpy(this->soPhieuLinh, soPhieuLinh);
            strcpy(this->maThuoc, maThuoc);
            this ->slYeuCau = slYeuCau;
            this ->slCapPhat = slCapPhat;
        }
};
class NodeDL{
    public:
        DongLinh dataDL;
        NodeDL *pNext;

        NodeDL() {};

};

class ListDL{
    public:

        NodeDL *pHead;
        ListDL(){
        	pHead = NULL;
		}
        void insertDL(NodeDL *&pHead, DongLinh ctpn);
        NodeDL* searchDL(NodeDL* pHead, char maThuoc[], char soPhieu[]);
        int DL_demSL();
        void DL_Array(DongLinh *arrarDL);
        NodeDL* deleteFirst(NodeDL* &pHead);
        NodeDL* deleteTail(NodeDL* p, NodeDL* q);
        NodeDL* deleteAfter(NodeDL *&pHead, char soPhieu[], char maThuoc[]);
        int deleteInfo(NodeDL* &pHead, char soPhieu[], char maThuoc[]);
        void writefileDL(ofstream& fileOut, NodeDL* pHead);
        void SaveFileDL(NodeDL* pHead);
        void ReadFileDL(NodeDL* &pHead);
        void printDL(NodeDL* pHead);
        void DeleteAllDL(NodeDL* &pHead);
        bool checkMaThuoc(NodeDL *pHead, char* maThuoc);
        bool checkSoPhieuLinh(NodeDL *pHead, char* soPhieu);
        int checkTrung2Field(NodeDL* pHead, char soPhieu[], char maThuoc[]);
};

