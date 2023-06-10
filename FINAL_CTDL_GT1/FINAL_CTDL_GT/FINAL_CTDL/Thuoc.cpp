#include"Thuoc.h"
NodeT* TreeThuoc::taoNodeT(Thuoc thuoc){
    NodeT* node = new NodeT();
    node->dataT = thuoc;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
bool TreeThuoc::CheckMaThuoc(NodeT* rootT, char mathuoc[])
{
    if (rootT == NULL) {
        return false;
    } else if (strcmp(mathuoc, rootT->dataT.maThuoc) == 0) {
        return true;
    } else if (strcmp(mathuoc, rootT->dataT.maThuoc) < 0) {
        return CheckMaThuoc(rootT->left, mathuoc);
    } else {
        return CheckMaThuoc(rootT->right, mathuoc);
    }
}
bool TreeThuoc::checkForeignKeyMaThuoc(NodeT* rootT, NodeCTPN* pHead) {
    NodeCTPN* current = pHead;
    while (current != NULL) {
        NodeT* found = searchT(rootT, current->dataCTPN.maThuoc);
        if (found == NULL) {
            return false; // Foreign key khong tim thay trong NodeHT
        }
        current = current->pNext;
    }
    return true; // tim thay khoa ngoai
}
int TreeThuoc::SoLuongNodeThuoc(NodeT *rooT)
{
    if(rooT == NULL)  return 0;
    else return (1+SoLuongNodeThuoc(rooT->left) + SoLuongNodeThuoc(rooT->right));
}


int TreeThuoc::height(NodeT *rootT){
    if(rootT == NULL)
        return 0;
    return rootT->height;
}
NodeT* TreeThuoc::rotateLeft(NodeT* rootT) {
    NodeT* newRootT = rootT->right;
    rootT->right = newRootT->left;
    newRootT->left = rootT;
    rootT->height = max(height(rootT->left), height(rootT->right)) + 1;
    newRootT->height = max(height(newRootT->left), height(newRootT->right)) + 1;
    return newRootT;
}

NodeT* TreeThuoc::rotateRight(NodeT* rootT) {
    NodeT* newRootT = rootT->left;
    rootT->left = newRootT->right;
    newRootT->right = rootT;
    rootT->height = max(height(rootT->left), height(rootT->right)) + 1;
    newRootT->height = max(height(newRootT->left), height(newRootT->right)) + 1;
    return newRootT;
}

int TreeThuoc::getBalance(NodeT *rootT){
    if(rootT == NULL)
        return 0;
    return height(rootT->left) - height(rootT->right);
}

NodeT* TreeThuoc::rotateLeftRight(NodeT* rootT) {
    rootT->left = rotateLeft(rootT->left);
    return rotateRight(rootT);
}

NodeT* TreeThuoc::rotateRightLeft(NodeT* rootT) {
    rootT->right = rotateRight(rootT->right);
    return rotateLeft(rootT);
}

NodeT* TreeThuoc::insertT(NodeT *&rootT, NodeT *p)
{
    if(rootT == NULL)
        return p;
    if(strcmp(p->dataT.maThuoc, rootT->dataT.maThuoc) < 0){
        rootT->left = insertT(rootT->left, p);
    } else if (strcmp(p->dataT.maThuoc, rootT->dataT.maThuoc) > 0) {
        rootT->right = insertT(rootT->right, p);
    } else {
        return rootT;
    }

    rootT->height = 1 + max(height(rootT->left), height(rootT->right));

    int balance = getBalance(rootT);

    if (balance > 1 && strcmp(p->dataT.maThuoc, rootT->left->dataT.maThuoc) < 0)
        return rotateRight(rootT);

    if (balance < -1 && strcmp(p->dataT.maThuoc, rootT->right->dataT.maThuoc) > 0)
        return rotateLeft(rootT);

    if (balance > 1 && strcmp(p->dataT.maThuoc, rootT->left->dataT.maThuoc) > 0)
        return rotateLeftRight(rootT);

    if (balance < -1 && strcmp(p->dataT.maThuoc, rootT->right->dataT.maThuoc) < 0)
        return rotateRightLeft(rootT);

    return rootT;
}

NodeT* TreeThuoc::findMinT(NodeT* rootT) {
    if (rootT == NULL)
        return NULL;
    else if (rootT->left == NULL)
        return rootT;
    else
        return findMinT(rootT->left);
}

void TreeThuoc::tempT(NodeT* des, NodeT *src)
{
    strcpy(des->dataT.maThuoc, src->dataT.maThuoc);
    strcpy(des->dataT.tenThuoc, src->dataT.tenThuoc);
//    strcpy(des->dataT.tenHoatChat, src->dataT.tenHoatChat);
    strcpy(des->dataT.nongDoHamLuong, src->dataT.nongDoHamLuong);
//    strcpy(des->dataT.soDangKy, src->dataT.soDangKy);
    strcpy(des->dataT.noiSanXuat, src->dataT.noiSanXuat);
    strcpy(des->dataT.donViTinh, src->dataT.donViTinh);
    des->dataT.hanDung = src->dataT.hanDung;
}

NodeT* TreeThuoc::deleteNodeT(NodeT*& rootT, char maThuoc[]) {
    if (rootT == NULL)
        return rootT;

    if (strcmp(maThuoc, rootT->dataT.maThuoc) < 0)
        rootT->left = deleteNodeT(rootT->left, maThuoc);
    else if (strcmp(maThuoc, rootT->dataT.maThuoc) > 0)
        rootT->right = deleteNodeT(rootT->right, maThuoc);
    else {
        if ((rootT->left == NULL) || (rootT->right == NULL)) {
            NodeT* temp = rootT->left ? rootT->left : rootT->right;
            if (temp == NULL) {
                temp = rootT;
                rootT = NULL;
            }
            else
                *rootT = *temp;
            delete temp;
        }
        else {
            NodeT* temp = findMinT(rootT->right);
            tempT(rootT, temp);
            rootT->right = deleteNodeT(rootT->right, temp->dataT.maThuoc);
        }
    }

    if (rootT == NULL)
        return rootT;

    rootT->height = 1 + max(height(rootT->left), height(rootT->right));

    int balance = getBalance(rootT);

    if (balance > 1 && getBalance(rootT->left) >= 0)
        return rotateRight(rootT);

    if (balance > 1 && getBalance(rootT->left) < 0)
        return rotateLeftRight(rootT);

    if (balance < -1 && getBalance(rootT->right) <= 0)
        return rotateLeft(rootT);

    if (balance < -1 && getBalance(rootT->right) > 0)
        return rotateRightLeft(rootT);

    return rootT;
}


NodeT* TreeThuoc::searchT(NodeT* rootT, char maThuoc[])
{
    if (rootT == NULL || strcmp(maThuoc, rootT->dataT.maThuoc) == 0)
        return rootT;
    else if (strcmp(maThuoc, rootT->dataT.maThuoc) < 0)
        return searchT(rootT->left, maThuoc);
    else
        return searchT(rootT->right, maThuoc);
}
NodeT* TreeThuoc::searchInfoT(NodeT* rootT)
{
    char maThuoc[10];
    NodeT *tempma = NULL;
    cout<<"\nNhap ma THUOC can tim: ";
    cin.getline(maThuoc, 10);
    
    while (strlen(maThuoc) == 0 || strlen(maThuoc) >= 10) {
        cout << "\nNhap lai ma THUOC (khong qua 10 ky tu): ";
        cin.getline(maThuoc, 10);
    }
    tempma = searchT(rootT, maThuoc);
    if(tempma == NULL)
    {
        cout<<"Khong tim thay THONG TIN THUOC!!\n";
    }else{
        cout<<"MA THUOC: "<<tempma->dataT.maThuoc<<endl;
        cout<<"TEN THUOC: "<<tempma->dataT.tenThuoc<<endl;
//        cout<<"TEN HOAT CHAT: "<<tempma->dataT.tenHoatChat<<endl;
        cout<<"NONG DO HAM LUONG: "<<tempma->dataT.nongDoHamLuong<<endl;
//        cout<<"SO DANG KY: "<<tempma->dataT.soDangKy<<endl;
        cout<<"NOI SAN XUAT: "<<tempma->dataT.noiSanXuat<<endl;
        cout<<"DON VI TINH: "<<tempma->dataT.donViTinh<<endl<<endl;
        cout<<"HAN DUNG: "<<tempma->dataT.hanDung.ngay<<"/"<<tempma->dataT.hanDung.thang<<"/"<<tempma->dataT.hanDung.nam<<endl;

    }
    return tempma;
}

void TreeThuoc::deleteInfoT(NodeT*&rootT)
{
    
    char maThuoc[10];
    NodeT* tempma = NULL;
    cout << "\nNhap ma THUOC can xoa: ";
    cin.getline(maThuoc, 10);

    tempma = searchT(rootT, maThuoc);
    if(tempma == NULL)
    {
        cout << "\nKhong tim thay THUOC co ma " << maThuoc << " de xoa!" << endl;
    }
    else
    {
        rootT = deleteNodeT(rootT, maThuoc);
        cout << "Da xoa thanh cong THUOC co ma " << maThuoc << endl;
    }
}
//
//void TreeThuoc::createT(NodeT* &rootT)
//{
//    Thuoc thuoc;
//    cout<<"---Nhap Thong Tin THUOC Can Them---"<<endl<<endl;
//    cout<<"\n Nhap vao MA THUOC: ";
//    cin.ignore();
//    fflush(stdin);
//    cin.getline(thuoc.maThuoc, 10);
//    //gets(hangthuoc.maThuoc);
//    while(CheckTrungT(rootT, thuoc.maThuoc)==true)
//    {
//        cout<<"\nMa thuoc da ton tai. Nhap lai !!\n";
//        cout<<"\nNhap lai MA THUOC: ";
//        fflush(stdin);
//        cin.getline(thuoc.maThuoc, 10);
//    }
//    cout<<"\n Nhap vao TEN THUOC: ";
//    fflush(stdin);
//    cin.getline(thuoc.tenThuoc, 100);
//
//    cout<<"\n Nhap vao TEN HOAT CHAT CUA THUOC: ";
//    fflush(stdin);
//    cin.getline(thuoc.tenHoatChat, 50);
//    // while(strlen(thuoc.tenHoatChat)!=10)
//    // {
//    //     cout<<"\n SDT bao gom 10 so. Nhap lai!!\n ";
//    //     cout<<"\n Nhap lai SDT: ";
//    //     fflush(stdin);
//    //     cin.getline(thuoc.sdt, 12);
//    // }
//    cout<<"\n Nhap vao NONG DO HAM LUONG CUA THUOC: ";
//    fflush(stdin);
//    cin.getline(thuoc.nongDoHamLuong, 10);
//
//    cout<<"\n Nhap vao SO SO DANG KY CUA THUOC: ";
//    fflush(stdin);
//    cin.getline(thuoc.soDangKy, 15);
//    while(strlen(thuoc.soDangKy)!=10)
//    {
//        cout<<"\n SO DANG KY bao gom 10 so. Nhap lai!!\n ";
//        cout<<"\n Nhap lai SO DANG KY: ";
//        fflush(stdin);
//        cin.getline(thuoc.soDangKy, 15);
//    }
//
//    cout<<"\n Nhap vao NOI SAN XUAT THUOC: ";
//    fflush(stdin);
//    cin.getline(thuoc.noiSanXuat, 50);
//
//    cout<<"\n Nhap vao DON VI TINH CUA THUOC: ";
//    fflush(stdin);
//    gets(thuoc.donViTinh);
//    while(strlen(thuoc.donViTinh)!=10)
//    {
//        cout<<"\n DON VI TINH bao gom 10 so. Nhap lai!!\n ";
//        cout<<"\n Nhap lai DON VI TINH: ";
//        fflush(stdin);
//        gets(thuoc.donViTinh);
//    }
//
//    NodeT* p = taoNodeT(thuoc);
//    if (rootT == NULL) {
//        rootT = p;
//    } else {
//        rootT = insertT(rootT, p); 
//    }
//}

void TreeThuoc::writefileT(ofstream& fileOut, NodeT* rootT) {
    if (rootT != NULL) {
        writefileT(fileOut, rootT->left);
        fileOut << rootT->dataT.maThuoc << endl;
        fileOut << rootT->dataT.tenThuoc << endl;
        fileOut << rootT->dataT.nongDoHamLuong <<endl;
        fileOut << rootT->dataT.noiSanXuat << endl;
        fileOut << rootT->dataT.donViTinh << endl;
        fileOut << rootT->dataT.hanDung.ngay<<"/"<<rootT->dataT.hanDung.thang<<"/"<<rootT->dataT.hanDung.nam << endl;
        writefileT(fileOut, rootT->right);
    }
}

void TreeThuoc::SaveFileT(NodeT* rootT) {
    ofstream fileOut("DSTHUOC.txt", ios::out);
    writefileT(fileOut, rootT);
    fileOut.close();
    cout << "Da luu danh sach thuoc vao file DSTHUOC.txt" << endl;
}

void TreeThuoc::ReadFileT(NodeT*& rootT) {
	ifstream fileIn;
    string data;
    fileIn.open("DSTHUOC.txt", ios::in);
    if(!fileIn.is_open()){
        cout<<"Khong tim thay file";
        return;
    }
    DeleteAllT(rootT);
    while (getline(fileIn, data)) {
        Thuoc thuoc;
        strcpy(thuoc.maThuoc, data.c_str());

        getline(fileIn, data);
        strcpy(thuoc.tenThuoc, data.c_str());

        getline(fileIn, data);
        strcpy(thuoc.nongDoHamLuong, data.c_str());

        getline(fileIn, data);
        strcpy(thuoc.noiSanXuat, data.c_str());

        getline(fileIn, data);
        strcpy(thuoc.donViTinh, data.c_str());

        getline(fileIn, data);
        stringstream dateStream(data);
        dateStream >> thuoc.hanDung.ngay;
        dateStream.ignore();
        dateStream >> thuoc.hanDung.thang;
        dateStream.ignore();
        dateStream >> thuoc.hanDung.nam;

        NodeT* p = taoNodeT(thuoc);
        rootT = insertT(rootT, p);
    }
}


void TreeThuoc::printT(NodeT *rootT){
    if(rootT != NULL)
    {
        printT(rootT->left);
        cout<<"MA THUOC: "<<rootT->dataT.maThuoc<<endl;
        cout<<"TEN THUOC: "<<rootT->dataT.tenThuoc<<endl;
//        cout<<"TEN HOAT CHAT: "<<rootT->dataT.tenHoatChat<<endl;
        cout<<"NONG DO HAM LUONG: "<<rootT->dataT.nongDoHamLuong<<endl;
//        cout<<"SO DANG KY: "<<rootT->dataT.soDangKy<<endl;
        cout<<"NOI SAN XUAT: "<<rootT->dataT.noiSanXuat<<endl;
        cout<<"DON VI TINH: "<<rootT->dataT.donViTinh<<endl<<endl;
        cout<<"HAN DUNG: "<<rootT->dataT.hanDung.ngay<<"/"<<rootT->dataT.hanDung.thang<<"/"<<rootT->dataT.hanDung.nam<<endl;
        
        printT(rootT->right);
    }
}
void TreeThuoc::DuyetNLRThuoc(NodeT* rootT, Thuoc *thuoc) {
	stack<NodeT*> stack;
	int i = 0;
	while(1){
		while(rootT){
			stack.push(rootT);
			// duyet cay con trai va them vao stack
			rootT = rootT->left;
		}
		if(stack.empty()) break;
		rootT = stack.top();
		stack.pop();
		thuoc[i++] = rootT->dataT;
		rootT = rootT->right;
	}
}
void TreeThuoc::DeleteAllT(NodeT *&rootT) {
    if (rootT == NULL)
        return;
    DeleteAllT(rootT->left);
    DeleteAllT(rootT->right);
    delete rootT;
    rootT = NULL;
    cout << "Successfully deleted all enterprises." << endl;
}
