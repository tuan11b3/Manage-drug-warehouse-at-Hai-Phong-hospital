#include"DKK.h"

DongKiemKe::DongKiemKe(char *sophieu,char *maThuoc, int SLTtruoc, int SLNtrongNgay, int SLXtrongNgay, int SLhetHan, int SLvoHong, int SLTcuoiNgay){
		strcpy(this->sophieu, sophieu);
		strcpy(this->maThuoc, maThuoc);
		this->SLTtruoc = SLTtruoc ;
		this->SLNtrongNgay = SLNtrongNgay;
		this->SLXtrongNgay = SLXtrongNgay;
		this->SLhetHan = SLhetHan;
		this->SLvoHong = SLvoHong;
		this->SLTcuoiNgay = SLTcuoiNgay;
}

ListNode_DKK::ListNode_DKK(DongKiemKe dongkiemke){
	data = dongkiemke;
	next = NULL;
} 

LinkListDKK::~LinkListDKK(){
	ListNode_DKK *auxilaryNode, *iterator;
	iterator = head;
	while(iterator){
		auxilaryNode = iterator->next;
		delete iterator;
		iterator = auxilaryNode;
	}
	head = NULL;	// to affect the real head back in the caller
}

int LinkListDKK:: ListLength(){
	struct ListNode_DKK *current = head;
	int count = 0;
	
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

void LinkListDKK::InsertDKK(DongKiemKe data, int position){
	int k = 1;
	ListNode_DKK *p, *q, *newNode;
	newNode = new ListNode_DKK(data);
	
	if(!newNode){
		cout<<"Loi cap phat bo nho!";
		return;
	}
	
	p = head;
	// Them data vi tri dau tien
	if(position == 1)
	{
		newNode->next = p;
		head = newNode;
	}else{
		// Duyet list cho den vitri noi muon them
		while((p!=NULL) && (k<position)){
			k++;
			q = p;
			p = p->next;
		}
		q->next = newNode;	
		newNode->next = p;
	}
}

bool LinkListDKK::CoincideMaThuocDKK_SoPhieu(char *sophieu, char *maThuoc){
	ListNode_DKK *p = head;
	while(p){
		if(strcmp(sophieu, p->data.sophieu) == 0 && strcmp(maThuoc, p->data.maThuoc) == 0)
			return true;
		p = p->next;
	}
	return false;
}

bool LinkListDKK::CheckFKDKK_sophieu(char* sophieu){
	ListNode_DKK *p = head;
	while(p){
		if(strcmp(sophieu, p->data.sophieu) == 0)
			return true;
		p = p->next;
	}
	return false;
}

bool LinkListDKK::CheckFKDKK_mathuoc(char* maThuoc){
	ListNode_DKK *p = head;
	while(p){
		if(strcmp(maThuoc, p->data.maThuoc) == 0)
			return true;
		p = p->next;
	}
	return false;
}

void LinkListDKK::CreateDKK(){
	char sophieu[10];
	char maThuoc[10];
	int SLTtruoc ;
	int SLNtrongNgay;
	int SLXtrongNgay;
	int SLhetHan;
	int SLvoHong;
	int SLTcuoiNgay;
	
	int i = 0;
	while (true){
//		cin.ignore();
		fflush(stdin);
		cout<<"Nhap so phieu(enter de thoat): ";
		cin.getline(sophieu, 10);
		if(sophieu[0] == NULL) break;
		if(strlen(sophieu) != 9 ){
			cout<<"So phieu phai co 9 ki tu!";
			cout<<"---Nhap Lai---";
			continue;
		}

		cout<<"Nhap ma thuoc: ";
		cin.getline(maThuoc, 10);
		if(strlen(maThuoc) != 9){
			cout<<"Ma thuoc phai co 9 ki tu!";
			cout<<"---Nhap Lai---";
			continue;
		}
		
		if(CoincideMaThuocDKK_SoPhieu(sophieu, maThuoc)){
			cout<<"Ma thuoc da ton tai!";
			cout<<"---Nhap Lai---";
			continue;
		}
		
		cout << "Nhap so luong ton truoc: ";
		cin >> SLTtruoc;
		
		cout << "Nhap so luong nhap trong ngay: ";
		cin >> SLNtrongNgay;
		
		cout << "Nhap so luong xuat trong ngay: ";
		cin >> SLXtrongNgay;
		
		cout << "Nhap so luong het hang: ";
		cin >> SLhetHan;
		
		cout << "Nhap so luong vo hong: ";
		cin >> SLvoHong;
		
		cout << "Nhap so luong ton cuoi ngay: ";
		cin >> SLTcuoiNgay;
		
		DongKiemKe dkk_new(sophieu, maThuoc, SLTtruoc, SLNtrongNgay, SLXtrongNgay, SLhetHan, SLvoHong, SLTcuoiNgay);		
		InsertDKK(dkk_new, ++i);
//		fflush(stdin);
	}
}

void LinkListDKK::DeleteALL(){
	ListNode_DKK *p, *q;
	p = head;
	while(p != NULL){
		q = p;
		p = p->next;
		delete q;
	}
	head = NULL;
}
void LinkListDKK::DeleteDKK(char *sophieu, char *maThuoc){
//	cout<<"In delete func!";
	ListNode_DKK *p, *q, *y;
	if(head == NULL){
	//	cout<<"Danh sach rong";
		return;
	}
	p = head;
	
	if(maThuoc[0] != NULL){
		/* o vi tri bat dau*/
		if(strcmp(sophieu, head->data.sophieu) == 0 && strcmp(maThuoc, head->data.maThuoc) == 0){
			head = head->next;
			delete p;
			cout<<"Xoa thanh cong!";
			return;
		}else{
			// Duyet list cho den khi toi vi tri muon xoa
			while((p != NULL) && (strcmp(sophieu, p->data.sophieu) != 0 && strcmp(maThuoc, p->data.maThuoc) != 0)){
				cout<<"a";
				q = p;
				p = p->next;
			}
			if(p == NULL)
			return;
				//cout<<"Du lieu ko ton tai, Kiem tra lai sophieu va mathuoc!";
			else{
				// Xoa o vi triu giua
				q->next = p->next;
				delete p;
				//cout<<"Xoa thanh cong!";
			}	
		}	
	}
	else{
		
			// Duyet list cho den khi toi vi tri muon xoa
		while(p != NULL){
			/* xoa o vi tri head*/
			if(strcmp(sophieu, head->data.sophieu) == 0){
			head = head->next;
			delete p;
			p = head;
		}
		else{
			q = p;
			p = p->next;
			if(p!= NULL  && (strcmp(sophieu, p->data.sophieu) == 0)){
				q->next = p->next;
			//	y = q->next;
				delete p; p = NULL;
				p = q;
				}
			}
		}
	}
	return;
}

// In danh sach
void LinkListDKK::printDKK(){
	ListNode_DKK *p = head;
	if(p == NULL){
		cout<<" Danh sach rong!";
		return;
	}
	while(p){
		cout << "So phieu" << p->data.sophieu << endl;
		cout << "Ma thuoc: " << p->data.maThuoc << endl;
		cout << "So luong ton truoc: " << p->data.SLTtruoc << endl;
		cout << "So luong nhap trong ngay: " << p->data.SLNtrongNgay << endl;
		cout << "So luong xuat trong ngay: " << p->data.SLXtrongNgay << endl;
		cout << "So luong het han: " << p->data.SLhetHan << endl;
		cout << "So luong vo hong: " << p->data.SLvoHong << endl;
		cout << "So luong ton cuoi ngay: " << p->data.SLTcuoiNgay;
		p = p->next;
		cout<<"\n";
	}
}

// Tim kiem
ListNode_DKK *LinkListDKK::SearchDKK(char *sophieu, char *maThuoc){
	ListNode_DKK *p;
	p = head;
	while(p != NULL){
		if(strcmp(sophieu, p->data.sophieu) == 0 && strcmp(maThuoc, p->data.maThuoc) == 0)
			return p;
		p = p->next;
	}
	
//	cout<<"Du lieu ko ton tai, Kiem tra lai sophieu va mathuoc!";
	return NULL;
}

//void LinkListDKK::DeleteAllDKK(ListNode_DKK* head) {
//    ListNode_DKK* p;
//    while (head != NULL) {
//        p = head;
//        head = head->next;
//        delete p;
//    }
//}
// Doc file
void LinkListDKK::ReadFileDKK(){
	DeleteALL();
	string data;
	int k = 1;
	ifstream fin("dongkiemke.txt");
	
	if(!fin){
		cout<<"Khong tim thay file";
		return ;
	}
	
	getline(fin, data);
	if(data.size() == 0)
		cout<<"Khong co du lieu duoc luu!";
	else{
	//	DeleteAllDKK(head);
		int soluong = atoi(data.c_str());	// Gan so luong records trong file
		cout<<"----So luong PX: "<<soluong<<"----\n"<<endl;
	
		while(!fin.eof()){
			DongKiemKe dongkiemke;	// Bien tam luu du lieu tu ban phim
			
			getline(fin, data);
			if(data.size() == 0) break;
			strcpy(dongkiemke.sophieu, data.c_str());
			getline(fin, data);		strcpy(dongkiemke.maThuoc,data.c_str());
			getline(fin, data);		dongkiemke.SLTtruoc = atoi(data.c_str());
			getline(fin, data);		dongkiemke.SLNtrongNgay = atoi(data.c_str());
			getline(fin, data);		dongkiemke.SLXtrongNgay = atoi(data.c_str());
			getline(fin, data);		dongkiemke.SLhetHan = atoi(data.c_str());
			getline(fin, data);		dongkiemke.SLvoHong = atoi(data.c_str());
			getline(fin, data);		dongkiemke.SLTcuoiNgay  = atoi(data.c_str());
			
			InsertDKK(dongkiemke, k);
			k++;
		}
	}
}

int LinkListDKK::SizeOfDKK(){
	ListNode_DKK *p;
	p = head;
	int k = 0;
	/* Tim so luong dong xuat list*/
	if(head == NULL)
		return 0;
	else {
		while(p){
			++k;
			p = p->next;
		}
	}
	return k;
}

void LinkListDKK::DataSave(ofstream &fout, DongKiemKe data){
	/* thuc hien ghi du lieu vao file */
	fout << data.sophieu << endl;
	fout << data.maThuoc << endl;
	fout << data.SLTtruoc << endl;
	fout << data.SLNtrongNgay << endl;
	fout << data.SLXtrongNgay << endl;
	fout << data.SLhetHan << endl;
	fout << data.SLvoHong << endl;
	fout << data.SLTcuoiNgay<<endl;
}

void LinkListDKK::SaveFileDKK(){
	cout<<head->data.SLTcuoiNgay;
	if(head){
	cout<<head->data.SLTcuoiNgay;
	ofstream fout("dongkiemke.txt", ios::out);
	int soluong = SizeOfDKK();
	ListNode_DKK *p;
	p = head;

	fout<<soluong<<endl;
	while(p){
		DataSave(fout, p->data);
		p = p->next;
	}
	fout.close();
	}
	else
		cout<<"Khong co du lieu de luu!";
		
}

void LinkListDKK::ArrayDKK(DongKiemKe *dsdkk){
	int i = 0;
	ListNode_DKK *p = head;
	
	while(p){
		dsdkk[i++] = p->data;
		p = p->next;
	}
}


