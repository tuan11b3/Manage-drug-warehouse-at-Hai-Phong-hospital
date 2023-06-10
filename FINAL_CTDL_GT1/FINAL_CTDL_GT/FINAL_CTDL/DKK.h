#pragma once

#include<iostream>
#include<string.h>	/* strcmp(), strcpy() */
#include<fstream>
#include<stdlib.h>	/* atoi() */
#include<stack>
 /* getch() */
using namespace std;

class DongKiemKe{
	public: 
		// member
		char sophieu[10];
		char maThuoc[10];
		int SLTtruoc ;
		int SLNtrongNgay;
		int SLXtrongNgay;
		int SLhetHan;
		int SLvoHong;
		int SLTcuoiNgay;
		//constructor
		DongKiemKe(){}
		DongKiemKe(char *sophieu,char *maThuoc, int SLTtruoc, int SLNtrongNgay, int SLXtrongNgay, int SLhetHan, int SLvoHong, int SLTcuoiNgay);
		~DongKiemKe(){}
};



class ListNode_DKK{
	public:
		// member
		DongKiemKe data;
		ListNode_DKK *next;
		
		// constructor
		ListNode_DKK(){}
		ListNode_DKK(DongKiemKe dongkiemke);
		// destructor
		~ListNode_DKK(){}
};



class LinkListDKK{
	public:
		ListNode_DKK *head;
		
		// constructor
		LinkListDKK(){
			head = NULL;
		}
		// destructor
		~LinkListDKK();
		
		// method
		int ListLength();
		void InsertDKK(DongKiemKe data, int position);
		void CreateDKK();
		void DeleteALL();
		void DeleteDKK(char* sophieu, char* maThuoc);
		bool CoincideMaThuocDKK_SoPhieu(char* sophieu, char* maThuoc);
		bool CheckFKDKK_sophieu(char* sophieu);
		bool CheckFKDKK_mathuoc(char* maThuoc);
		void printDKK();
		ListNode_DKK *SearchDKK(char *sophieu, char *maThuoc);
		void ReadFileDKK();
		void DataSave(ofstream &fout, DongKiemKe data);
		void SaveFileDKK();
		//void DeleteAllDKK(ListNode_DKK* head);
		int SizeOfDKK();
		void ArrayDKK(DongKiemKe *dsdkk);
//		bool DeleteAll();
};



