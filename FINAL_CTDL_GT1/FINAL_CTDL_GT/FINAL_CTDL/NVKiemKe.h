#pragma once

#include<iostream>
#include<string.h>	/* strcmp(), strcpy() */
#include<fstream>
#include<stdlib.h>	/* atoi() */
#include<stack>
#include<conio.h> /* getch() */

#include"PhieuXuat.h"
using namespace std;

//class ThoiGian{
//	public:
//		int ngay;
//		int thang;
//		int nam;
//};

class NVKiemKe{
	public:
		/* member */
		char sophieu[10];
		char manv[10];
		ThoiGian ngayKiemKe;
		
		/* Constructor */
		NVKiemKe() {}
		NVKiemKe(char *sophieu,char *manv, ThoiGian ngayKiemKe)
		{
		strcpy(this->sophieu, sophieu);
		strcpy(this->manv, manv);
		this->ngayKiemKe = ngayKiemKe;
		}
		
};

class NodeNVKK{
	public:
		NVKiemKe data;
		NodeNVKK *left;
		NodeNVKK *right;
		int height;
		
		/* Constructor */
		NodeNVKK() {}
		NodeNVKK(NVKiemKe nvkiemke){
			data = nvkiemke;
			left = NULL;
			right = NULL;
			height = 0;
		}		
};

class TreeNVKK{
	public:
		/* member */
		NodeNVKK *root;
		
		/* constructor */
		TreeNVKK(){ root = NULL; }
		
		bool isTreeEmpty(){
			if (root == NULL) return true;
			else return false;
		}
		
		/* method */
		void CreateNVKK();
		int Height(NodeNVKK *root); //sua
		NodeNVKK *SingleRotateLeft(NodeNVKK *X);//sua
		NodeNVKK *SingleRotateRight(NodeNVKK *X);//sua
		NodeNVKK *DoubleRotatewithLeft(NodeNVKK *Z);//sua
		NodeNVKK *DoubleRotatewithRight(NodeNVKK *Z);//sua
		NodeNVKK *InsertNVKK(NodeNVKK *root, NodeNVKK *parent, NVKiemKe data);//sua
		void PrintNVKK(NodeNVKK *root);//sua
		void ReadFileNVKK(); //sua
		void SaveFileNVKK();
		NodeNVKK *SearchNVKK();
		void DeleteNVKK();
		bool CoincideSoPhieuNVKK(NodeNVKK *root, char *sophieu);
		
		void DataSave(ofstream &fout, NVKiemKe data);
		int SizeOfNVKK(NodeNVKK *root);
		NodeNVKK* FindNodeNVKK(NodeNVKK* root, const  char *tukhoa);
		NodeNVKK* FindMaxNVKK(NodeNVKK *root);
		NodeNVKK* NNDNVKK(NodeNVKK* root, char* sophieu);
		void CopyDataNVKK(NodeNVKK* dest, const NodeNVKK res );
		void ArrayNVKK(NodeNVKK*root, NVKiemKe *dsnvkk);
};


