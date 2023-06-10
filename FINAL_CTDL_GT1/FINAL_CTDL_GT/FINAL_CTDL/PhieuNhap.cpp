#include "PhieuNhap.h"


NodePN*TreePN::taoNodePN(PhieuNhap phieunhap) {
            NodePN* node = new NodePN();
            node->dataPN = phieunhap;
            node->left = NULL;
            node->right = NULL;
            node->height = 1;
            return node;
        }
bool TreePN::CheckMaPN(NodePN* rootPN, char soPhieu[])
{
    if (rootPN == NULL) {
        return false;
    } else if (strcmp(soPhieu, rootPN->dataPN.soPhieuNhap) == 0) {
        return true;
    } else if (strcmp(soPhieu, rootPN->dataPN.soPhieuNhap) < 0) {
        return CheckMaPN(rootPN->left, soPhieu);
    } else {
        return CheckMaPN(rootPN->right, soPhieu);
    }
}

bool TreePN::checkForeignKeyChiTietPN(NodePN* rootPN) {
		ListCTPN cptn;
        NodeCTPN* temp = cptn.pHead;
        while (temp != NULL) {
            if (searchPN(rootPN, temp->dataCTPN.soPhieuNhap) == NULL) {
                return false;  // Foreign key khong tim thay
            }
            temp = temp->pNext;
        }
        return true;  // Foreign key found
    }


int TreePN::SoLuongNodePN(NodePN *rootPN)
{
    if(rootPN == NULL)  return 0;
    else return (1+SoLuongNodePN(rootPN->left) + SoLuongNodePN(rootPN->right));
}
void TreePN::DuyetNLRPN(NodePN* rootPN, PhieuNhap *phieunhap) {
	stack<NodePN*> stack;
	int i = 0;
	while(1){
		while(rootPN){
			stack.push(rootPN);
			// duyet cay con trai va them vao stack
			rootPN = rootPN->left;
		}
		if(stack.empty()) break;
		rootPN = stack.top();
		stack.pop();
		phieunhap[i++] = rootPN->dataPN;
		rootPN = rootPN->right;
	}
}

int TreePN::height(NodePN *rootPN){
    if(rootPN == NULL)
        return 0;
    return rootPN->height;
}
NodePN* TreePN::rotateLeft(NodePN* rootPN) {
    NodePN* newrootPN = rootPN->right;
    rootPN->right = newrootPN->left;
    newrootPN->left = rootPN;
    rootPN->height = max(height(rootPN->left), height(rootPN->right)) + 1;
    newrootPN->height = max(height(newrootPN->left), height(newrootPN->right)) + 1;
    return newrootPN;
}

NodePN* TreePN::rotateRight(NodePN* rootPN) {
    NodePN* newrootPN = rootPN->left;
    rootPN->left = newrootPN->right;
    newrootPN->right = rootPN;
    rootPN->height = max(height(rootPN->left), height(rootPN->right)) + 1;
    newrootPN->height = max(height(newrootPN->left), height(newrootPN->right)) + 1;
    return newrootPN;
}

int TreePN::getBalance(NodePN *rootPN){
    if(rootPN == NULL)
        return 0;
    return height(rootPN->left) - height(rootPN->right);
}

NodePN* TreePN::rotateLeftRight(NodePN* rootPN) {
    rootPN->left = rotateLeft(rootPN->left);
    return rotateRight(rootPN);
}

NodePN* TreePN::rotateRightLeft(NodePN* rootPN) {
    rootPN->right = rotateRight(rootPN->right);
    return rotateLeft(rootPN);
}

NodePN* TreePN::insertPN(NodePN *&rootPN, NodePN *p) {
    if (rootPN == NULL)
        return p;
    if (strcmp(p->dataPN.soPhieuNhap, rootPN->dataPN.soPhieuNhap) < 0) {
        rootPN->left = insertPN(rootPN->left, p);
    } else if (strcmp(p->dataPN.soPhieuNhap, rootPN->dataPN.soPhieuNhap) > 0) {
        rootPN->right = insertPN(rootPN->right, p);
    } else {
        return rootPN;
    }

    rootPN->height = 1 + max(height(rootPN->left), height(rootPN->right));

    int balance = getBalance(rootPN);

    if (balance > 1 && strcmp(p->dataPN.soPhieuNhap, rootPN->left->dataPN.soPhieuNhap) < 0)
        return rotateRight(rootPN);

    if (balance < -1 && strcmp(p->dataPN.soPhieuNhap, rootPN->right->dataPN.soPhieuNhap) > 0)
        return rotateLeft(rootPN);

    if (balance > 1 && strcmp(p->dataPN.soPhieuNhap, rootPN->left->dataPN.soPhieuNhap) > 0)
        return rotateLeftRight(rootPN);

    if (balance < -1 && strcmp(p->dataPN.soPhieuNhap, rootPN->right->dataPN.soPhieuNhap) < 0)
        return rotateRightLeft(rootPN);

    return rootPN;
}

NodePN* TreePN::findMinPN(NodePN* rootPN) {
    if (rootPN == NULL)
        return NULL;
    else if (rootPN->left == NULL)
        return rootPN;
    else
        return findMinPN(rootPN->left);
}

void TreePN::tempPN(NodePN* des, NodePN *src)
{
    strcpy(des->dataPN.soPhieuNhap, src->dataPN.soPhieuNhap);
    strcpy(des->dataPN.maNV, src->dataPN.maNV);
    strcpy(des->dataPN.maHT, src->dataPN.maHT);
    des->dataPN.ngayNhap = src->dataPN.ngayNhap;
    strcpy(des->dataPN.tenKhoNhapThuoc, src->dataPN.tenKhoNhapThuoc);
    strcpy(des->dataPN.diaDiemNhap, src->dataPN.diaDiemNhap);
}

NodePN* TreePN::deleteNodePN(NodePN*& rootPN, char soPhieu[]) {
    if (rootPN == NULL)
        return rootPN;

    if (strcmp(soPhieu, rootPN->dataPN.soPhieuNhap) < 0)
        rootPN->left = deleteNodePN(rootPN->left, soPhieu);
    else if (strcmp(soPhieu, rootPN->dataPN.soPhieuNhap) > 0)
        rootPN->right = deleteNodePN(rootPN->right, soPhieu);
    else {
        if ((rootPN->left == NULL) || (rootPN->right == NULL)) {
            NodePN* temp = rootPN->left ? rootPN->left : rootPN->right;
            if (temp == NULL) {
                temp = rootPN;
                rootPN = NULL;
            }
            else
                *rootPN = *temp;
            delete temp;
        }
        else {
            NodePN* temp = findMinPN(rootPN->right);
            tempPN(rootPN, temp);
            rootPN->right = deleteNodePN(rootPN->right, temp->dataPN.soPhieuNhap);
        }
    }

    if (rootPN == NULL)
        return rootPN;

    rootPN->height = 1 + max(height(rootPN->left), height(rootPN->right));

    int balance = getBalance(rootPN);

    if (balance > 1 && getBalance(rootPN->left) >= 0)
        return rotateRight(rootPN);

    if (balance > 1 && getBalance(rootPN->left) < 0)
        return rotateLeftRight(rootPN);

    if (balance < -1 && getBalance(rootPN->right) <= 0)
        return rotateLeft(rootPN);

    if (balance < -1 && getBalance(rootPN->right) > 0)
        return rotateRightLeft(rootPN);

    return rootPN;
}


NodePN* TreePN::searchPN(NodePN *rootPN, char soPhieu[])
{
    if(rootPN == NULL || strcmp(soPhieu, rootPN->dataPN.soPhieuNhap) == 0)  
		return rootPN;
    else if(strcmp(soPhieu, rootPN->dataPN.soPhieuNhap) < 0){
        return searchPN(rootPN -> left, soPhieu);
    }
    else
    	return searchPN(rootPN->right, soPhieu);
}

bool TreePN::checkMa_HT_PN(NodePN *rootPN, char* maHT) {
	
    if (rootPN == NULL) {
        return false;
    } else if (strcmp(maHT, rootPN->dataPN.maHT) == 0) {
        return true;
    } else if (strcmp(maHT, rootPN->dataPN.maHT) < 0) {
        return checkMa_HT_PN(rootPN->left, maHT);
    } else {
        return checkMa_HT_PN(rootPN->right, maHT);
    }  
}
/*
char soPhieuNhap[10];
        char maNV[10];
        char maHT[10];
        date ngayNhap;
        char tenKhoNhapThuoc[50];
        char diaDiemNhap[50];*/
//
//NodePN* TreePN::searchInfoPN(NodePN* rootPN)
//{
//    char soPhieu[10];
//    NodePN *tempma = NULL;
//    cout<<"\nNhap So Phieu Nhap can tim: ";
//    cin.getline(soPhieu, 10);
//    
//    while (strlen(soPhieu) == 0 || strlen(soPhieu) >= 10) {
//        cout << "\nNhap lai So Phieu Nhap (khong qua 10 ky tu): ";
//        cin.getline(soPhieu, 10);
//    }
//    tempma = searchPN(rootPN, soPhieu);
//    if(tempma == NULL)
//    {
//        cout<<"Khong tim thay HANG THUOC!!\n";
//    }else{
//        cout<<"SO PHIEU NHAP: "<<rootPN->dataPN.soPhieuNhap<<endl;
//        cout<<"MA NHAN VIEN: "<<rootPN->dataPN.maNV<<endl;
//        cout<<"MA HANG THUOC: "<<rootPN->dataPN.maHT<<endl;
//        cout<<"NGAY NHAP: "<<rootPN->dataPN.ngayNhap.ngay<<"/"<<rootPN->dataPN.ngayNhap.thang<<"/"<<rootPN->dataPN.ngayNhap.nam<<endl;
//        cout<<"TEN KHO NHAP THUOC: "<<rootPN->dataPN.tenKhoNhapThuoc<<endl;
//        cout<<"DIA CHI NHAP THUOC: "<<rootPN->dataPN.diaDiemNhap<<endl<<endl; 
//
//    }
//    return tempma;
//}

void TreePN::deleteInfoPN(NodePN* &rootPN)
{
    
    char soPhieu[10];
    NodePN* tempma = NULL;
    cout << "\nNhap ma hang thuoc can xoa: ";
    cin.getline(soPhieu, 10);

    tempma = searchPN(rootPN, soPhieu);
    if(tempma == NULL)
    {
        cout << "\nKhong tim thay hang thuoc co ma " << soPhieu << " de xoa!" << endl;
    }
    else
    {
        rootPN = deleteNodePN(rootPN, soPhieu);
        cout << "Da xoa thanh cong hang thuoc co ma " << soPhieu << endl;
    }
}
bool isExistHT(char maht[]) {
	TreeHT tree;
   // NodeHT *rootHT = NULL; 
    NodeHT* node = tree.searchHT(tree.rootHT, maht);
    return node != NULL;
}
//
//void TreePN::createPN(NodePN* &rootPN)
//{
//    PhieuNhap phieunhap;
//    cout<<"---Nhap Thong Tin PHIEU NHAP can them---"<<endl<<endl;
//    cout<<"\nNhap vao SO PHIEU NHAP: ";
//    fflush(stdin);
//    gets(phieunhap.soPhieuNhap);
//    while(CheckTrungPN(rootPN, phieunhap.soPhieuNhap) == true)
//    {
//        cout<<"\nSO PHIEU NHAP da ton tai. Nhap Lai!!!!";
//        cout<<"\nNhap lai SO PHIEU NHAP: ";
//        fflush(stdin);
//        gets(phieunhap.soPhieuNhap);
//    }
//    cout<<"\nNhap vao MA NHAN VIEN: ";
//    fflush(stdin);
//    gets(phieunhap.maNV);
//
//    cout<<"\nNhap vao MA HANG THUOC: ";
//    fflush(stdin);
//    gets(phieunhap.maHT);
//    while(!isExistHT(phieunhap.maHT))
//    {
//        cout<<"\nMA HANG THUOC khong tim thay. Nhap Lai!!!";
//        cout<<"\nNhap lai MA HANG THUOC: ";
//        fflush(stdin);
//        gets(phieunhap.maHT);
//    }
//    
//    cout << "Nhap ngay: " << endl;
//    cout << "Ngay: ";
//    cin >> phieunhap.ngayNhap.ngay;
//    cout << "Thang: ";
//    cin >> phieunhap.ngayNhap.thang;
//    cout << "Nam: ";
//    cin >> phieunhap.ngayNhap.nam;
//
//    cout<<"\nNhap vao TEN KHO NHAP THUOC: ";
//    fflush(stdin);
//    gets(phieunhap.tenKhoNhapThuoc);
//
//    cout<<"\nNhap vao DIA CHI KHO NHAP THUOC: ";
//    fflush(stdin);
//    gets(phieunhap.diaDiemNhap);
//	
//    NodePN *p = taoNodePN(phieunhap);
//    insertPN(rootPN, p);
//}

void TreePN::writefilePN(ofstream& fileOut, NodePN* rootPN) {
    if (rootPN != NULL) {
        writefilePN(fileOut, rootPN->left);
        fileOut << rootPN->dataPN.soPhieuNhap << endl;
        fileOut << rootPN->dataPN.maNV << endl;
        fileOut << rootPN->dataPN.maHT << endl;
        fileOut << rootPN->dataPN.ngayNhap.ngay<<"/"<<rootPN->dataPN.ngayNhap.thang<<"/"<<rootPN->dataPN.ngayNhap.nam << endl;
        fileOut << rootPN->dataPN.tenKhoNhapThuoc << endl;
        fileOut << rootPN->dataPN.diaDiemNhap << endl;
        writefilePN(fileOut, rootPN->right);
    }
}

void TreePN::SaveFilePN(NodePN* rootPN) {
    ofstream fileOut("DSPN.txt", ios::out);
    writefilePN(fileOut, rootPN);
    fileOut.close();
    cout << "Da luu danh sach hang thuoc vao file DSPN.txt" << endl;
}
/*void TreeHT::ReadFileHT(NodeHT* &rootHT) {
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
}*/

void TreePN::ReadFilePN(NodePN* &rootPN)
{
    ifstream fileIn;
    string data;
    fileIn.open("DSPN.txt", ios::in);
    if (!fileIn.is_open()) {
        cout << "Khong Tim Thay File." << endl;
        return;
    }
    DeleteAllPN(rootPN);
    while(!fileIn.eof())
    {
        PhieuNhap phieunhap;
        getline(fileIn, data);
        if (data.size() == 0) {
            break; 
        } // cos file nhung chua co du lieu
        strcpy(phieunhap.soPhieuNhap, data.c_str());

        getline(fileIn, data);
        strcpy(phieunhap.maNV, data.c_str());

        getline(fileIn, data);
        strcpy(phieunhap.maHT, data.c_str());

        getline(fileIn, data);
        stringstream dateStream(data);
        dateStream >> phieunhap.ngayNhap.ngay;
        dateStream.ignore();
        dateStream >> phieunhap.ngayNhap.thang;
        dateStream.ignore();
        dateStream >> phieunhap.ngayNhap.nam;

        getline(fileIn, data);
        strcpy(phieunhap.tenKhoNhapThuoc, data.c_str());

        getline(fileIn, data);
        strcpy(phieunhap.diaDiemNhap, data.c_str());

        NodePN *p = taoNodePN(phieunhap);
       	rootPN = insertPN(rootPN, p);
    }
    fileIn.close();
}

void TreePN::printPN(NodePN *rootPN){
    if(rootPN != NULL)
    {
        printPN(rootPN->left);
        cout<<"SO PHIEU NHAP: "<<rootPN->dataPN.soPhieuNhap<<endl;
        cout<<"MA NHAN VIEN: "<<rootPN->dataPN.maNV<<endl;
        cout<<"MA HANG THUOC: "<<rootPN->dataPN.maHT<<endl;
        cout<<"NGAY NHAP: "<<rootPN->dataPN.ngayNhap.ngay<<"/"<<rootPN->dataPN.ngayNhap.thang<<"/"<<rootPN->dataPN.ngayNhap.nam<<endl;
        cout<<"TEN KHO NHAP THUOC: "<<rootPN->dataPN.tenKhoNhapThuoc<<endl;
        cout<<"DIA CHI NHAP THUOC: "<<rootPN->dataPN.diaDiemNhap<<endl<<endl;
        
        printPN(rootPN->right);
    }
}
void TreePN::DeleteAllPN(NodePN *&rootPN) {
    if (rootPN == NULL)
        return;
    DeleteAllPN(rootPN->left);
    DeleteAllPN(rootPN->right);
    delete rootPN;
    rootPN = NULL;
    cout << "Successfully deleted all enterprises." << endl;
}
