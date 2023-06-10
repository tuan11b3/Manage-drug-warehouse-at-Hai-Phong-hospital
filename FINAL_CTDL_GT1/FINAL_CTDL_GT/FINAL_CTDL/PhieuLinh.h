#pragma once

#include<iostream>
#include<string.h>	/* strcmp(), strcpy() */
#include<fstream>
#include<stdlib.h>	/* atoi() */
#include<stack>
#include<conio.h> /* getch() */
using namespace std;

class ThoiGian1{
	public:
		int ngay;
		int thang;
		int nam;
};
class PhieuLinh{
	public:
		/* member */
		char sophieu[10];
		char maNV[10];
		char maKCN[10];
		ThoiGian1 ngayYC;
		
		
		/* Constructor */
		PhieuLinh() {}
		PhieuLinh(char *sophieu,char *maNV, char *maKCN, ThoiGian1 ngayYC)
		{
		strcpy(this->sophieu, sophieu);
		strcpy(this->maNV, maNV);
		strcpy(this->maKCN, maKCN);
		this->ngayYC = ngayYC;
		}
		
};

class NodePL{
	public:
		PhieuLinh data;
		NodePL *left;
		NodePL *right;
		int height;
		
		/* Constructor */
		NodePL() {}
		NodePL(PhieuLinh phieulinh){
			data = phieulinh;
			left = NULL;
			right = NULL;
			height = 0;
		}		
};

class TreePL{
	public:
		/* member */
		NodePL *root;
		
		/* constructor */
		TreePL(){ root = NULL; }
		
		bool isTreeEmpty(){
			if (root == NULL) return true;
			else return false;
		}
		
		/* method */
		void CreatePL();
		int Height(NodePL *root); //sua
		NodePL *SingleRotateLeft(NodePL *X);//sua
		NodePL *SingleRotateRight(NodePL *X);//sua
		NodePL *DoubleRotatewithLeft(NodePL *Z);//sua
		NodePL *DoubleRotatewithRight(NodePL *Z);//sua
		NodePL *InsertPL(NodePL *root, NodePL *parent, PhieuLinh data);//sua
		void PrintPL(NodePL *root);//sua
		void ReadFilePL(); //sua
		void SaveFilePL();
		NodePL *SearchPL();
		void DeletePL();
		bool CoincideMaPL(NodePL *root, char *sophieu);
		
		void DataSave(ofstream &fout, PhieuLinh data);
		int SizeOfPL(NodePL *root);
		NodePL* FindNodePL(NodePL* root, const char *tukhoa);
		NodePL* FindMaxPL(NodePL *root);
		NodePL* NNDPL(NodePL* root, char* sophieu);
		void CopyDataPL(NodePL* dest, const NodePL res );
		void ArrayPL(NodePL*root, PhieuLinh *dspl);
		NodePL* CheckFKPL_maKCN(NodePL *root, char* makhoacn);	//NEW
		NodePL* CheckFKPL_maNV(NodePL *root, char* manv);	//NEW
};



