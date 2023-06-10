#pragma once

#include<iostream>
#include<string.h>	/* strcmp(), strcpy() */
#include<fstream>
#include<stdlib.h>	/* atoi() */
#include<stack>
#include<conio.h> /* getch() */
using namespace std;

class ThoiGian{
	public:
		int ngay;
		int thang;
		int nam;
};

class PhieuXuat{
	public:
		/* member */
		char sophieu[10];
		char manv[10];
		char makhoacn[10];
		ThoiGian ngayxuat;
		char tenkhont[50];
		char tenkhoxt[50];
		char manvnew[10];
		
		/* Constructor */
		PhieuXuat() {}
		PhieuXuat(char *sophieu,char *manv, char*makhoacn, ThoiGian ngayxuat, char *tenkhont, char* tenkhoxt, char *mnvnew)
		{
		strcpy(this->sophieu, sophieu);
		strcpy(this->manv, manv);
		strcpy(this->makhoacn, makhoacn);
		this->ngayxuat = ngayxuat;
		strcpy(this->tenkhont, tenkhont);
		strcpy(this->tenkhoxt, tenkhoxt);
		strcpy(this->manvnew, manvnew);
		}
		
};

class NodePX{
	public:
		PhieuXuat data;
		NodePX *left;
		NodePX *right;
		int height;
		
		/* Constructor */
		NodePX() {}
		NodePX(PhieuXuat phieuxuat){
			data = phieuxuat;
			left = NULL;
			right = NULL;
			height = 0;
		}		
};

class TreePX{
	public:
		/* member */
		NodePX *root;
		
		/* constructor */
		TreePX(){ root = NULL; }
		
		bool isTreeEmpty(){
			if (root == NULL) return true;
			else return false;
		}
		
		/* method */
		
		void CreatePX();
		int Height(NodePX *root);
		NodePX *SingleRotateLeft(NodePX *X);
		NodePX *SingleRotateRight(NodePX *X);
		NodePX *DoubleRotatewithLeft(NodePX *Z);
		NodePX *DoubleRotatewithRight(NodePX *Z);
		NodePX *InsertPX(NodePX *root, NodePX *parent, PhieuXuat data);
		void PrintPX(NodePX *root);
		void ReadFilePX();
		void SaveFilePX();
		NodePX *SearchPX();
		void DeletePX();
		bool CoincideSoPhieuPX(NodePX *root, char *sophieu);
		
		void DataSave(ofstream &fout, PhieuXuat data);
		int SizeOfPX(NodePX *root);
		NodePX* FindNodePX(NodePX* root, const  char *tukhoa);
		NodePX* FindMaxPX(NodePX *root);
		NodePX* NNDPX(NodePX* root, char* sophieu);
		void CopyDataPX(NodePX* dest, const NodePX res );
		void ArrayPX(NodePX*root, PhieuXuat *dspx); //NEW
		NodePX* CheckFKPX_maNV(NodePX* root, char* manv); //NEW
		NodePX* CheckFKPX_maKCN(NodePX* root, char* makhoacn); //NEW
};



