#pragma one

#include <iostream>
#include <string.h>
#include <stdio.h>
#include<fstream>
#include<stdlib.h>
#include"PhieuXuat.h"
using namespace std;

class DongXuat{
	public: 
		// member
		char sophieu[10];
		char mathuoc[10];
		int slxuat;
		int dongia;
		ThoiGian ngayxuat;
		
		//constructor
		DongXuat(){}
		DongXuat(char *sophieu, char *mathuoc, int slxuat, int dongia, ThoiGian ngayxuat);
		~DongXuat(){}
};

class ListNode_DX{
	public:
		// member
		DongXuat data;
		ListNode_DX *next;
		
		// constructor
		ListNode_DX(){}
		ListNode_DX(DongXuat dongxuat);
		// destructor
		~ListNode_DX(){}
};

class LinkListDX{
	public:
		ListNode_DX *head;
		
		// constructor
		LinkListDX(){
			head = NULL;
		}
		// destructor
		~LinkListDX();
		// method
		int ListLength();
		void InsertDX(DongXuat data, int position);
		void CreateDX();
		void DeleteALL();
		void DeleteDX(char* sophieu, char* mathuoc);
		bool CoincideMaThuocDX_SoPhieu(char* sophieu, char* mathuoc);
		bool CheckFKDX_sophieu(char* sophieu);
		bool CheckFKDX_mathuoc(char* maThuoc);
		void printDX();
		ListNode_DX *SearchDX(char *sophieu, char *mathuoc);
		void ReadFileDX();
		void DataSave(ofstream &fout, DongXuat data);
		void SaveFileDX();
		int SizeOfDX();	
		void ArrayDX(DongXuat *dsdx);	
};

