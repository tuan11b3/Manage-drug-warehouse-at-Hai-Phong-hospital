#pragma once

#include<iostream>
#include<string.h>	/* strcmp(), strcpy() */
#include<fstream>
#include<stdlib.h>	/* atoi() */
#include<stack>
#include<conio.h> /* getch() */
using namespace std;

class KhoaChucNang{
	public:
		/* member */
		char maKCN[10];
		char tenKCN[25];
		char tenNguoiDD[25];
		
		/* Constructor */
		KhoaChucNang() {}
		KhoaChucNang(char *maKCN,char *tenKCN, char *tenNguoiDD)
		{
		strcpy(this->maKCN, maKCN);
		strcpy(this->tenKCN, tenKCN);
		strcpy(this->tenNguoiDD, tenNguoiDD);
		}
		
};

class NodeKCN{
	public:
		KhoaChucNang data;
		NodeKCN *left;
		NodeKCN *right;
		int height;
		
		/* Constructor */
		NodeKCN() {}
		NodeKCN(KhoaChucNang khoachucnang){
			data = khoachucnang;
			left = NULL;
			right = NULL;
			height = 0;
		}		
};

class TreeKCN{
	public:
		/* member */
		NodeKCN *root;
		
		/* constructor */
		TreeKCN(){ root = NULL; }
		
		bool isTreeEmpty(){
			if (root == NULL) return true;
			else return false;
		}
		
		/* method */
		void CreateKCN();
		int Height(NodeKCN *root); //sua
		NodeKCN *SingleRotateLeft(NodeKCN *X);//sua
		NodeKCN *SingleRotateRight(NodeKCN *X);//sua
		NodeKCN *DoubleRotatewithLeft(NodeKCN *Z);//sua
		NodeKCN *DoubleRotatewithRight(NodeKCN *Z);//sua
		NodeKCN *InsertKCN(NodeKCN *root, NodeKCN *parent, KhoaChucNang data);//sua
		void PrintKCN(NodeKCN *root);//sua
		void ReadFileKCN(); //sua
		void SaveFileKCN();
		NodeKCN *SearchKCN();
		void DeleteKCN();
		bool CoincideMaKCN(NodeKCN *root, char *maKCN);
		
		void DataSave(ofstream &fout, KhoaChucNang data);
		int SizeOfKCN(NodeKCN *root);
		NodeKCN* FindNodeKCN(NodeKCN* root, const  char *tukhoa);
		NodeKCN* FindMaxKCN(NodeKCN *root);
		NodeKCN* NNDKCN(NodeKCN* root, char* maKCN);
		void CopyDataKCN(NodeKCN* dest, const NodeKCN res );
		void ArrayKCN(NodeKCN*root, KhoaChucNang *dskcn);
};


