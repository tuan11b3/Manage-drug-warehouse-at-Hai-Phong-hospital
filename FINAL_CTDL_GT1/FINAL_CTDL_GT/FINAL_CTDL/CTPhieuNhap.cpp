#include"CTPhieuNhap.h"

NodeCTPN* ListCTPN::deleteFirst(NodeCTPN* &pHead){
    NodeCTPN *p;
    if(pHead == NULL)   return NULL;
    p= pHead;
    pHead = p->pNext;
    delete p;
    return pHead;
}


NodeCTPN* ListCTPN::deleteTail(NodeCTPN* p, NodeCTPN* q){
    q->pNext = NULL;
    p = NULL;
    delete p;
    return NULL;
        
}

NodeCTPN* ListCTPN::deleteAfter(NodeCTPN *&pHead, char soPhieu[], char maThuoc[]){
    NodeCTPN* q = NULL;
    NodeCTPN* p;
    for(p = pHead; p->pNext != NULL && (strcmp(p->dataCTPN.soPhieuNhap, soPhieu) != 0 || strcmp(p->dataCTPN.maThuoc, maThuoc) !=0); q = p, p=p->pNext);
    q->pNext = p->pNext;
    p->pNext = NULL;
    delete p;
    return q->pNext;
}

int ListCTPN::deleteInfo(NodeCTPN* &pHead, char soPhieu[], char maThuoc[]){
    NodeCTPN* p = pHead;
    NodeCTPN *q = NULL;
    if(pHead== NULL)
        return 0;
    if(strcmp(pHead->dataCTPN.soPhieuNhap, soPhieu) == 0 && strcmp(pHead->dataCTPN.maThuoc, maThuoc) == 0)
    {
        deleteFirst(pHead);
        return 1;
    }
    for(p = pHead; p->pNext != NULL && (strcmp(p->dataCTPN.soPhieuNhap, soPhieu) != 0 && strcmp(p->dataCTPN.maThuoc, maThuoc) !=0); q = p, p=p->pNext);
    if(p->pNext != NULL)
    {
        deleteAfter(pHead, soPhieu, maThuoc);
        return 1;
    }
    if(p->pNext == NULL && (strcmp(p->dataCTPN.soPhieuNhap, soPhieu) == 0 && strcmp(p->dataCTPN.maThuoc, maThuoc) == 0)){
        deleteTail(p, q);
        return 1;
    }
    return 0;
}

void ListCTPN::insertCTPN(NodeCTPN *&pHead, CHITIETPN ctpn){
    NodeCTPN* newNode = new NodeCTPN();
    newNode->dataCTPN = ctpn;
    newNode->pNext = NULL;

    if(pHead == NULL){
        pHead = newNode;
        return;
    }
    else{
        NodeCTPN* current = pHead;
        while(current->pNext != NULL)
        {
            current = current->pNext;
        }
        current->pNext = newNode;
    }
}
NodeCTPN* ListCTPN::searchCTPN(NodeCTPN* pHead, char soPhieu[], char maThuoc[])
{
    NodeCTPN* current = pHead;
    while (current != NULL)
    {
        if (strcmp(soPhieu, current->dataCTPN.soPhieuNhap) == 0 && strcmp(maThuoc, current -> dataCTPN.maThuoc) == 0)
        {
            return current;
        }
        current = current->pNext;
    }
    return NULL;
}

int ListCTPN::CTPN_demSL()
{
    int count = 0;
    NodeCTPN* current = pHead;
    while (current != NULL)
    {
        count++;
        current = current->pNext;
    }
    return count;
}
void ListCTPN::CTPN_Array(CHITIETPN *arrarPN)
    {
        NodeCTPN* current = pHead;
        int i = 0;
        while (current != NULL && i < CTPN_demSL())
        {
            arrarPN[i] = current->dataCTPN;
            current = current->pNext;
            i++;
        }
    }

void ListCTPN::writefileCTPN(ofstream& fileOut, NodeCTPN* pHead) {
    NodeCTPN* p;
    for (p = pHead; p != NULL; p = p->pNext) {
        fileOut << p->dataCTPN.soPhieuNhap << endl;
        fileOut << p->dataCTPN.maThuoc << endl;
        fileOut << p->dataCTPN.soLuongNhap << endl;
        fileOut << p->dataCTPN.donGia << endl;
        
    }
}

void ListCTPN::SaveFileCTPN(NodeCTPN* pHead)
{
    ofstream fileOut("DSCTPN.txt", ios::out);
    if (!fileOut) {
        cout << "File loi." << endl;
        return;
    }
    writefileCTPN(fileOut, pHead);
    fileOut.close();
}

void ListCTPN::ReadFileCTPN(NodeCTPN*& pHead)
{
    ifstream fileIn;
    string data;
    fileIn.open("DSCTPN.txt", ios::in);
    if(!fileIn){
        cout<<"Khong tim thay file"<<endl;;
        return;
    }
    DeleteAllCTPN(pHead);
    
    while(!fileIn.eof())
    {
        CHITIETPN ctpn;
        getline(fileIn, data);
        if (data.size() == 0) {
            break;
        }  // cos file nhung chua co du lieu
        strcpy(ctpn.soPhieuNhap, data.c_str());

        getline(fileIn, data);
        strcpy(ctpn.maThuoc, data.c_str());

        getline(fileIn, data);
        ctpn.soLuongNhap = atoi(data.c_str());
        
        getline(fileIn, data);
        ctpn.donGia = atoi(data.c_str()) ;

        insertCTPN(pHead, ctpn); 
    }
    fileIn.close();
}

void ListCTPN::printCTPN(NodeCTPN* pHead)
{
    NodeCTPN* p;
    if (pHead == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    cout << "Thong tin chi tiet phieu nhap:" << endl;
    for (p = pHead; p != NULL; p = p->pNext) {
        cout << "So phieu nhap: " << p->dataCTPN.soPhieuNhap << endl;
        cout << "Ma thuoc: " << p->dataCTPN.maThuoc << endl;
        cout << "So luong nhap: " << p->dataCTPN.soLuongNhap << endl;
        cout << "Don gia: " << p->dataCTPN.donGia << endl;
        cout << "------------------------" << endl;
    }
}

void ListCTPN::DeleteAllCTPN(NodeCTPN* &pHead) {
    NodeCTPN* p;
    while (pHead != NULL) {
        p = pHead;
        pHead = pHead->pNext;
        delete p;
    }
}
bool ListCTPN::checkSoPhieu(NodeCTPN *pHead, char* soPhieu) {
     NodeCTPN* current = pHead;
    while (current) {
    	if(strcmp(soPhieu, current->dataCTPN.soPhieuNhap) == 0)
    		return true;
    		
        current = current->pNext;
    }
    return false; 
}
bool ListCTPN::checkMaThuoc(NodeCTPN *pHead, char* maThuoc) {
    NodeCTPN* current = pHead;
    while (current) {
    	if(strcmp(maThuoc, current->dataCTPN.maThuoc) == 0)
    		return true;
    		
        current = current->pNext;
    }
    return false; 
}
//
//bool ListCTPN::checkMaThuoc(NodeHT* rootHT, NodeCTPN* pHead) {
//    NodeCTPN* current = pHead;
//    while (current != NULL) {
//        NodeHT* found = searchHT(rootHT, current->dataCTPN.maThuoc);
//        if (found == NULL) {
//            return false; // Ma Thuoc khong tim thay trog THUOC
//        }
//        current = current->pNext;
//    }
//    return true; // tim thay ma thuoc
//}

int ListCTPN::checkTrung2Field(NodeCTPN* pHead, char soPhieu[], char maThuoc[]) {
    NodeCTPN* current = pHead;
    while (current != NULL) {
        if (strcmp(current->dataCTPN.soPhieuNhap, soPhieu) == 0 && strcmp(current->dataCTPN.maThuoc, maThuoc) == 0) {
            return 1; // tim thay phieu trung
        }
        current = current->pNext;
    }
    return 0; // k trung
}



