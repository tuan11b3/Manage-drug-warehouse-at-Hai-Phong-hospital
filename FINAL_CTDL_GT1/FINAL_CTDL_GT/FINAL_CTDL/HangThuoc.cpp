#include"HangThuoc.h"

NodeHT*TreeHT::taoNodeHT(HangThuoc ht) {
    NodeHT* node = new NodeHT();
    node->dataHT = ht;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

bool TreeHT::CheckMaHT(NodeHT* rootHT, const char* maht)
{
    if (rootHT == NULL) {
        return false;
    } else if (strcmp(maht, rootHT->dataHT.maHT) == 0) {
        return true;
    } else if (strcmp(maht, rootHT->dataHT.maHT) < 0) {
        return CheckMaHT(rootHT->left, maht);
    } else {
        return CheckMaHT(rootHT->right, maht);
    }
}
int TreeHT::SoLuongNodeHT(NodeHT *rootHT)
{
    if(rootHT == NULL)  return 0;
    else return (1+SoLuongNodeHT(rootHT->left) + SoLuongNodeHT(rootHT->right));
}
void TreeHT::DuyetNLR(NodeHT* rootHT, HangThuoc *ht) {
	stack<NodeHT*> stack;
	int i = 0;
	while(1){
		while(rootHT){
			stack.push(rootHT);
			// duyet cay con trai va them vao stack
			rootHT = rootHT->left;
		}
		if(stack.empty()) break;
		rootHT = stack.top();
		stack.pop();
		ht[i++] = rootHT->dataHT;
		rootHT = rootHT->right;
	}
}

int TreeHT::height(NodeHT *rootHT){
    if(rootHT == NULL)
        return 0;
    return rootHT->height;
}
NodeHT* TreeHT::rotateLeft(NodeHT* rootHT) {
    NodeHT* newRootHT = rootHT->right;
    rootHT->right = newRootHT->left;
    newRootHT->left = rootHT;
    rootHT->height = max(height(rootHT->left), height(rootHT->right)) + 1;
    newRootHT->height = max(height(newRootHT->left), height(newRootHT->right)) + 1;
    return newRootHT;
}

NodeHT* TreeHT::rotateRight(NodeHT* rootHT) {
    NodeHT* newRootHT = rootHT->left;
    rootHT->left = newRootHT->right;
    newRootHT->right = rootHT;
    rootHT->height = max(height(rootHT->left), height(rootHT->right)) + 1;
    newRootHT->height = max(height(newRootHT->left), height(newRootHT->right)) + 1;
    return newRootHT;
}

int TreeHT::getBalance(NodeHT *rootHT){
    if(rootHT == NULL)
        return 0;
    return height(rootHT->left) - height(rootHT->right);
}

NodeHT* TreeHT::rotateLeftRight(NodeHT* rootHT) {
    rootHT->left = rotateLeft(rootHT->left);
    return rotateRight(rootHT);
}

NodeHT* TreeHT::rotateRightLeft(NodeHT* rootHT) {
    rootHT->right = rotateRight(rootHT->right);
    return rotateLeft(rootHT);
}

NodeHT* TreeHT::insertHT(NodeHT *&rootHT, NodeHT *p) {
    if (rootHT == NULL)
        return p;
    if (strcmp(p->dataHT.maHT, rootHT->dataHT.maHT) < 0) {
        rootHT->left = insertHT(rootHT->left, p);
    } else if (strcmp(p->dataHT.maHT, rootHT->dataHT.maHT) > 0) {
        rootHT->right = insertHT(rootHT->right, p);
    } else {
        return rootHT;
    }

    rootHT->height = 1 + max(height(rootHT->left), height(rootHT->right));

    int balance = getBalance(rootHT);

    if (balance > 1 && strcmp(p->dataHT.maHT, rootHT->left->dataHT.maHT) < 0)
        return rotateRight(rootHT);

    if (balance < -1 && strcmp(p->dataHT.maHT, rootHT->right->dataHT.maHT) > 0)
        return rotateLeft(rootHT);

    if (balance > 1 && strcmp(p->dataHT.maHT, rootHT->left->dataHT.maHT) > 0)
        return rotateLeftRight(rootHT);

    if (balance < -1 && strcmp(p->dataHT.maHT, rootHT->right->dataHT.maHT) < 0)
        return rotateRightLeft(rootHT);

    return rootHT;
}

NodeHT* TreeHT::findMinHT(NodeHT* rootHT) {
    if (rootHT == NULL)
        return NULL;
    else if (rootHT->left == NULL)
        return rootHT;
    else
        return findMinHT(rootHT->left);
}
void TreeHT::tempHT(NodeHT* des, NodeHT *src)
{
    strcpy(des->dataHT.maHT, src->dataHT.maHT);
    strcpy(des->dataHT.tenHT, src->dataHT.tenHT);
    strcpy(des->dataHT.sdt, src->dataHT.sdt);
    strcpy(des->dataHT.diaChi, src->dataHT.diaChi);
//    strcpy(des->dataHT.fax, src->dataHT.fax);
//    strcpy(des->dataHT.soTK, src->dataHT.soTK);
    strcpy(des->dataHT.maSoThue, src->dataHT.maSoThue);
}

NodeHT* TreeHT::deleteNodeHT(NodeHT*& rootHT, char maht[]) {
    if (rootHT == NULL)
        return rootHT;

    if (strcmp(maht, rootHT->dataHT.maHT) < 0)
        rootHT->left = deleteNodeHT(rootHT->left, maht);
    else if (strcmp(maht, rootHT->dataHT.maHT) > 0)
        rootHT->right = deleteNodeHT(rootHT->right, maht);
    else {
        if ((rootHT->left == NULL) || (rootHT->right == NULL)) {
            NodeHT* temp = rootHT->left ? rootHT->left : rootHT->right;
            if (temp == NULL) {
                temp = rootHT;
                rootHT = NULL;
            }
            else
                *rootHT = *temp;
            delete temp;
        }
        else {
            NodeHT* temp = findMinHT(rootHT->right);
            tempHT(rootHT, temp);
            rootHT->right = deleteNodeHT(rootHT->right, temp->dataHT.maHT);
        }
    }

    if (rootHT == NULL)
        return rootHT;

    rootHT->height = 1 + max(height(rootHT->left), height(rootHT->right));

    int balance = getBalance(rootHT);

    if (balance > 1 && getBalance(rootHT->left) >= 0)
        return rotateRight(rootHT);

    if (balance > 1 && getBalance(rootHT->left) < 0)
        return rotateLeftRight(rootHT);

    if (balance < -1 && getBalance(rootHT->right) <= 0)
        return rotateLeft(rootHT);

    if (balance < -1 && getBalance(rootHT->right) > 0)
        return rotateRightLeft(rootHT);

    return rootHT;
}
NodeHT* TreeHT::searchHT(NodeHT* rootHT, char maht[]) {
    if (rootHT == NULL || strcmp(maht, rootHT->dataHT.maHT) == 0)
        return rootHT;
    else if (strcmp(maht, rootHT->dataHT.maHT) < 0)
        return searchHT(rootHT->left, maht);
    else
        return searchHT(rootHT->right, maht);
}

NodeHT* TreeHT::searchInfoHT(NodeHT* rootHT)
{
    char maht[10];
    NodeHT *tempma = NULL;
    cout<<"\nNhap ma hang thuoc can tim: ";
    cin.getline(maht, 10);
    
    while (strlen(maht) == 0 || strlen(maht) >= 10) {
        cout << "\nNhap lai ma hang thuoc (khong qua 10 ky tu): ";
        cin.getline(maht, 10);
    }
    tempma = searchHT(rootHT, maht);
    if(tempma == NULL)
    {
        cout<<"Khong tim thay HANG THUOC!!\n";
    }else{
        cout<<"MA HANG THUOC: "<<tempma->dataHT.maHT<<endl;
        cout<<"TEN HANG THUOC: "<<tempma->dataHT.tenHT<<endl;
        cout<<"SDT: "<<tempma->dataHT.sdt<<endl;
        cout<<"DIA CHI: "<<tempma->dataHT.diaChi<<endl;
//        cout<<"SO FAX: "<<tempma->dataHT.fax<<endl;
//        cout<<"SO TAI KHOAN: "<<tempma->dataHT.soTK<<endl;
        cout<<"MA SO THUE: "<<tempma->dataHT.maSoThue<<endl<<endl;

    }
    return tempma;
}

void TreeHT::deleteInfoHT(NodeHT*&rootHT)
{
    
    char maht[10];
    NodeHT* tempma = NULL;
    cout << "\nNhap ma hang thuoc can xoa: ";
    cin.getline(maht, 10);

    tempma = searchHT(rootHT, maht);
    if(tempma == NULL)
    {
        cout << "\nKhong tim thay hang thuoc co ma " << maht << " de xoa!" << endl;
    }
    else
    {
        rootHT = deleteNodeHT(rootHT, maht);
        cout << "Da xoa thanh cong hang thuoc co ma " << maht << endl;
    }
}
//
//void TreeHT::CreateHT(NodeHT* &rootHT)
//{
//    HangThuoc hangthuoc;
//    cout<<"---Nhap Thong Tin Hang Thuoc Can Them---"<<endl<<endl;
//    cout<<"\n Nhap vao MA HANG THUOC: ";
//    cin.ignore();
//    fflush(stdin);
//    cin.getline(hangthuoc.maHT, 10);
//    //gets(hangthuoc.maHT);
//    while(CheckTrungHT(rootHT, hangthuoc.maHT)==true)
//    {
//        cout<<"\nMa hang thuoc da ton tai. Nhap lai !!\n";
//        cout<<"\nNhap lai MA HANG THUOC: ";
//        fflush(stdin);
//        cin.getline(hangthuoc.maHT, 10);
//    }
//    cout<<"\n Nhap vao TEN HANG THUOC: ";
//    fflush(stdin);
//    cin.getline(hangthuoc.tenHT, 100);
//
//    cout<<"\n Nhap vao SDT HANG THUOC: ";
//    fflush(stdin);
//    cin.getline(hangthuoc.sdt, 12);
//    while(strlen(hangthuoc.sdt)!=10)
//    {
//        cout<<"\n SDT bao gom 10 so. Nhap lai!!\n ";
//        cout<<"\n Nhap lai SDT: ";
//        fflush(stdin);
//        cin.getline(hangthuoc.sdt, 12);
//    }
//    cout<<"\n Nhap vao DIA CHI HANG THUOC: ";
//    fflush(stdin);
//    cin.getline(hangthuoc.diaChi, 50);
//
////    cout<<"\n Nhap vao SO FAX HANG THUOC: ";
////    fflush(stdin);
////    cin.getline(hangthuoc.fax, 15);
////    while(strlen(hangthuoc.fax)!=10)
////    {
////        cout<<"\n FAX bao gom 10 so. Nhap lai!!\n ";
////        cout<<"\n Nhap lai FAX: ";
////        fflush(stdin);
////        cin.getline(hangthuoc.fax, 15);
////    }
////
////    cout<<"\n Nhap vao SO TAI KHOAN HANG THUOC: ";
////    fflush(stdin);
////    cin.getline(hangthuoc.soTK, 20);
//
//    cout<<"\n Nhap vao MA SO THUE HANG THUOC: ";
//    fflush(stdin);
//    gets(hangthuoc.maSoThue);
//    while(strlen(hangthuoc.maSoThue)!=10)
//    {
//        cout<<"\n MA SO THUE bao gom 10 so. Nhap lai!!\n ";
//        cout<<"\n Nhap lai MA SO THUE: ";
//        fflush(stdin);
//        gets(hangthuoc.maSoThue);
//    }
//
//    NodeHT* p = taoNodeHT(hangthuoc);
//    if (rootHT == NULL) {
//        rootHT = p;
//    } else {
//        rootHT = insertHT(rootHT, p); // Update rootHT pointer
//    }
//}

void TreeHT::writefileHT(ofstream& fileOut, NodeHT* rootHT) {
    if (rootHT != NULL) {
        writefileHT(fileOut, rootHT->left);
        fileOut << rootHT->dataHT.maHT << endl;
        fileOut << rootHT->dataHT.tenHT << endl;
        fileOut << rootHT->dataHT.sdt << endl;
        fileOut << rootHT->dataHT.diaChi << endl;
//        fileOut << rootHT->dataHT.fax << endl;
//        fileOut << rootHT->dataHT.soTK << endl;
        fileOut << rootHT->dataHT.maSoThue << endl;
        writefileHT(fileOut, rootHT->right);
    }
}

void TreeHT::SaveFileHT(NodeHT* rootHT) {
    ofstream fileOut("DSHT.txt", ios::out);
    if (!fileOut) {
        cout << "File loi." << endl;
        return;
    }
    writefileHT(fileOut, rootHT);
    fileOut.close();
    cout << "Da luu danh sach hang thuoc vao file DSHT.txt" << endl;
}

void TreeHT::ReadFileHT(NodeHT* &rootHT) {
    ifstream fileIn;
    string data;
    fileIn.open("DSHT.txt", ios::in);
    if (!fileIn.is_open()) {
        cout << "File Loi." << endl;
        return;
    }

    // Clear the existing tree
    DeleteAllHT(rootHT);

    while (!fileIn.eof()) {
        HangThuoc hangthuoc;

        getline(fileIn, data);
        if (data.size() == 0) {
            break; 
        }
        strcpy(hangthuoc.maHT, data.c_str());

        getline(fileIn, data);
        strcpy(hangthuoc.tenHT, data.c_str());

        getline(fileIn, data);
        strcpy(hangthuoc.sdt, data.c_str());

        getline(fileIn, data);
        strcpy(hangthuoc.diaChi, data.c_str());

        getline(fileIn, data);
        strcpy(hangthuoc.maSoThue, data.c_str());

        NodeHT* newNode = taoNodeHT(hangthuoc);
        rootHT = insertHT(rootHT, newNode);
    }

    fileIn.close();
}


void TreeHT::printHT(NodeHT *rootHT){
    if(rootHT != NULL)
    {
        printHT(rootHT->left);
        cout<<"MA HANG THUOC: " << rootHT->dataHT.maHT<<endl;
        cout<<"TEN HANG THUOC: "<<rootHT->dataHT.tenHT<<endl;
        cout<<"SDT: "<<rootHT->dataHT.sdt<<endl;
        cout<<"DIA CHI: "<<rootHT->dataHT.diaChi<<endl;
        cout<<"MA SO THUE: "<<rootHT->dataHT.maSoThue<<endl<<endl;
        
        printHT(rootHT->right);
    }
}
void TreeHT::HoanViHT(HangThuoc &ht1, HangThuoc &ht2){
	HangThuoc tamp = ht1;
	ht1 = ht2;
	ht2 = tamp;
}

int SoSanhChuoi(char Str1[], char Str2[])
{
	return strcmp(Str1, Str2);
}

void TreeHT::SapXepHT(NodeHT *rootHT, HangThuoc ht[] ,int dem)
{
	for (int i = 0; i < dem; i++)
	{
		for(int j = 0; j < dem; j++)
		{
			if( SoSanhChuoi(ht[i].tenHT, ht[j].tenHT) == -1)
			{
				HoanViHT(ht[i], ht[j]);
			}
		}
	}
}

void TreeHT::DeleteAllHT(NodeHT *&rootHT) {
    if (rootHT == NULL)
        return;
    DeleteAllHT(rootHT->left);
    DeleteAllHT(rootHT->right);
    delete rootHT;
    rootHT = NULL;
    cout << "Successfully deleted all enterprises." << endl;
}