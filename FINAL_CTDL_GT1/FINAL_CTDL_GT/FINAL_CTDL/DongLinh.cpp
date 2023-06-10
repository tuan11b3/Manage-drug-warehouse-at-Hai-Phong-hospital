#include"DongLinh.h"

NodeDL* ListDL::deleteFirst(NodeDL* &pHead){
    NodeDL *p;
    if(pHead == NULL)   return NULL;
    p= pHead;
    pHead = p->pNext;
    delete p;
    return pHead;
}


NodeDL* ListDL::deleteTail(NodeDL* p, NodeDL* q){
    q->pNext = NULL;
    p = NULL;
    delete p;
    return NULL;
        
}

NodeDL* ListDL::deleteAfter(NodeDL *&pHead, char soPhieu[], char maThuoc[]){
    NodeDL* q = NULL;
    NodeDL* p;
    for(p = pHead; p->pNext != NULL && (strcmp(p->dataDL.soPhieuLinh, soPhieu) != 0 || strcmp(p->dataDL.maThuoc, maThuoc) !=0); q = p, p=p->pNext);
    q->pNext = p->pNext;
    p->pNext = NULL;
    delete p;
    return q->pNext;
}

int ListDL::deleteInfo(NodeDL* &pHead, char soPhieu[], char maThuoc[]){
    NodeDL* p = pHead;
    NodeDL *q = NULL;
    if(pHead== NULL)
        return 0;
    if(strcmp(pHead->dataDL.soPhieuLinh, soPhieu) == 0 && strcmp(pHead->dataDL.maThuoc, maThuoc) == 0)
    {
        deleteFirst(pHead);
        return 1;
    }
    for(p = pHead; p->pNext != NULL && (strcmp(p->dataDL.soPhieuLinh, soPhieu) != 0 && strcmp(p->dataDL.maThuoc, maThuoc) !=0); q = p, p=p->pNext);
    if(p->pNext != NULL)
    {
        deleteAfter(pHead, soPhieu, maThuoc);
        return 1;
    }
    if(p->pNext == NULL && (strcmp(p->dataDL.soPhieuLinh, soPhieu) == 0 && strcmp(p->dataDL.maThuoc, maThuoc) == 0)){
        deleteTail(p, q);
        return 1;
    }
    return 0;
}

void ListDL::insertDL(NodeDL *&pHead, DongLinh donglinh){
    NodeDL* newNode = new NodeDL();
    newNode->dataDL = donglinh;
    newNode->pNext = NULL;

    if(pHead == NULL){
        pHead = newNode;
        return;
    }
    else{
        NodeDL* current = pHead;
        while(current->pNext != NULL)
        {
            current = current->pNext;
        }
        current->pNext = newNode;
    }
}
NodeDL* ListDL::searchDL(NodeDL* pHead, char soPhieu[], char maThuoc[])
{
    NodeDL* current = pHead;
    while (current != NULL)
    {
        if (strcmp(soPhieu, current->dataDL.soPhieuLinh) == 0 && strcmp(maThuoc, current -> dataDL.maThuoc) == 0)
        {
            return current;
        }
        current = current->pNext;
    }
    return NULL;
}

int ListDL::DL_demSL()
{
    int count = 0;
    NodeDL* current = pHead;
    while (current != NULL)
    {
        count++;
        current = current->pNext;
    }
    return count;
}
void ListDL::DL_Array(DongLinh *arrarDL)
    {
        NodeDL* current = pHead;
        int i = 0;
        while (current != NULL && i < DL_demSL())
        {
            arrarDL[i] = current->dataDL;
            current = current->pNext;
            i++;
        }
    }

void ListDL::writefileDL(ofstream& fileOut, NodeDL* pHead) {
    NodeDL* p;
    for (p = pHead; p != NULL; p = p->pNext) {
        fileOut << p->dataDL.soPhieuLinh << endl;
        fileOut << p->dataDL.maThuoc << endl;
        fileOut << p->dataDL.slYeuCau << endl;
        fileOut << p->dataDL.slCapPhat << endl;
    }
}

void ListDL::SaveFileDL(NodeDL* pHead)
{
    ofstream fileOut("DSDLinh.txt", ios::out);
    writefileDL(fileOut, pHead);
    fileOut.close();
    
}

void ListDL::ReadFileDL(NodeDL*& pHead)
{
    ifstream fileIn;
    string data;
    fileIn.open("DSDLinh.txt", ios::in);
    if(!fileIn){
        cout<<"Khong tim thay file"<<endl;;
        return;
    }
    DeleteAllDL(pHead);
    
    while(!fileIn.eof())
    {
        DongLinh donglinh;
        getline(fileIn, data);
        if (data.size() == 0) {
            break;
        }  // cos file nhung chua co du lieu
        strcpy(donglinh.soPhieuLinh, data.c_str());

        getline(fileIn, data);
        strcpy(donglinh.maThuoc, data.c_str());

        getline(fileIn, data);
        donglinh.slYeuCau = atoi(data.c_str());
        
        getline(fileIn, data);
        donglinh.slCapPhat = atoi(data.c_str()) ;

        insertDL(pHead, donglinh); 
    }
    fileIn.close();
}

void ListDL::DeleteAllDL(NodeDL* &pHead) {
    NodeDL* p;
    while (pHead != NULL) {
        p = pHead;
        pHead = pHead->pNext;
        delete p;
    }
}
bool ListDL::checkSoPhieuLinh(NodeDL *pHead, char* soPhieu) {
     NodeDL* current = pHead;
    while (current) {
    	if(strcmp(soPhieu, current->dataDL.soPhieuLinh) == 0)
    		return true;
    		
        current = current->pNext;
    }
    return false; 
}
bool ListDL::checkMaThuoc(NodeDL *pHead, char* maThuoc) {
    NodeDL* current = pHead;
    while (current) {
    	if(strcmp(maThuoc, current->dataDL.maThuoc) == 0)
    		return true;
    		
        current = current->pNext;
    }
    return false; 
}

int ListDL::checkTrung2Field(NodeDL* pHead, char soPhieu[], char maThuoc[]) {
    NodeDL* current = pHead;
    while (current != NULL) {
        if (strcmp(current->dataDL.soPhieuLinh, soPhieu) == 0 && strcmp(current->dataDL.maThuoc, maThuoc) == 0) {
            return 1; // tim thay phieu trung
        }
        current = current->pNext;
    }
    return 0; // k trung
}



