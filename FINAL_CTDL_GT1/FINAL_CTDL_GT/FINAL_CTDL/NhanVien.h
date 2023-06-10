#pragma once

#include<iostream>
#include<string.h>	/* strcmp(), strcpy() */
#include<fstream>
#include<stdlib.h>	/* atoi() */
#include<stack>
#include<conio.h> /* getch() */
using namespace std;

class NhanVien{
	public:
		/* member */
		char maNV[10];
		char hoTen[30];
		char chucVu[20];
		
		/* Constructor */
		NhanVien() {}
		NhanVien(char *maNV,char *hoTen, char *chucVu)
		{
		strcpy(this->maNV, maNV);
		strcpy(this->hoTen, hoTen);
		strcpy(this->chucVu, chucVu);
		}
		
};

class NodeNV{
	public:
		NhanVien data;
		NodeNV *left;
		NodeNV *right;
		int height;
		
		/* Constructor */
		NodeNV() {}
		NodeNV(NhanVien nhanvien){
			data = nhanvien;
			left = NULL;
			right = NULL;
			height = 0;
		}		
};

class TreeNV{
	public:
		/* member */
		NodeNV *root;
		
		/* constructor */
		TreeNV(){ root = NULL; }
		
		bool isTreeEmpty(){
			if (root == NULL) return true;
			else return false;
		}
		
		/* method */
		void CreateNV();
		int Height(NodeNV *root); //sua
		NodeNV *SingleRotateLeft(NodeNV *X);//sua
		NodeNV *SingleRotateRight(NodeNV *X);//sua
		NodeNV *DoubleRotatewithLeft(NodeNV *Z);//sua
		NodeNV *DoubleRotatewithRight(NodeNV *Z);//sua
		NodeNV *InsertNV(NodeNV *root, NodeNV *parent, NhanVien data);//sua
		void PrintNV(NodeNV *root);//sua
		void ReadFileNV(); //sua
		void SaveFileNV();
		NodeNV *SearchNV();
		void DeleteNV();
		bool CoincideMaNV(NodeNV *root, char *maNV);
		
		void DataSave(ofstream &fout, NhanVien data);
		int SizeOfNV(NodeNV *root);
		NodeNV* FindNodeNV(NodeNV* root, const  char *tukhoa);
		NodeNV* FindMaxNV(NodeNV *root);
		NodeNV* NNDNV(NodeNV* root, char* maNV);
		void CopyDataNV(NodeNV* dest, const NodeNV res );
		void ArrayNV(NodeNV*root, NhanVien *dsnv);
		bool CheckFKNV_maNV(NodeNV* root, char* manv); //NEW
};


