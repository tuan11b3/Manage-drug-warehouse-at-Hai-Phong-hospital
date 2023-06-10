#pragma once

#include<iostream>
#include<stdio.h>
#include<string.h>
#include <fstream>
#include <cstdlib>

using namespace std;


class CHITIETPN{
    public:
        char soPhieuNhap[10];
        char maThuoc[10];
        int soLuongNhap;
        int donGia;

       	CHITIETPN(){};
        CHITIETPN(char *soPhieuNhap, char *maThuoc, int slNhap, int donGia)
        {
            strcpy(this->soPhieuNhap, soPhieuNhap);
            strcpy(this->maThuoc, maThuoc);
            this ->soLuongNhap = slNhap;
            this ->donGia = donGia;
        }
};
class NodeCTPN{
    public:
        CHITIETPN dataCTPN;
        NodeCTPN *pNext;

        NodeCTPN() {};

};

class ListCTPN{
    public:

        NodeCTPN *pHead;
        ListCTPN(){
        	pHead = NULL;
		}
        void insertCTPN(NodeCTPN *&pHead, CHITIETPN ctpn);
        NodeCTPN* searchCTPN(NodeCTPN* pHead, char maThuoc[], char soPhieu[]);
        int CTPN_demSL();
        void CTPN_Array(CHITIETPN *arrarPN);
        NodeCTPN* deleteFirst(NodeCTPN* &pHead);
        NodeCTPN* deleteTail(NodeCTPN* p, NodeCTPN* q);
        NodeCTPN* deleteAfter(NodeCTPN *&pHead, char soPhieu[], char maThuoc[]);
        int deleteInfo(NodeCTPN* &pHead, char soPhieu[], char maThuoc[]);
        void writefileCTPN(ofstream& fileOut, NodeCTPN* pHead);
        void SaveFileCTPN(NodeCTPN* pHead);
        void ReadFileCTPN(NodeCTPN* &pHead);
        void printCTPN(NodeCTPN* pHead);
        void DeleteAllCTPN(NodeCTPN* &pHead);
        bool checkMaThuoc(NodeCTPN *pHead, char* maThuoc);
        bool checkSoPhieu(NodeCTPN *pHead, char* soPhieu);
        int checkTrung2Field(NodeCTPN* pHead, char soPhieu[], char maThuoc[]);
};

