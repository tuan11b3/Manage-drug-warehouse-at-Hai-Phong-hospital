#include"DongXuat.h"

DongXuat::DongXuat(char *sophieu, char *mathuoc, int slxuat, int dongia, ThoiGian ngayxuat){
	strcpy(this->sophieu, sophieu);
	strcpy(this->mathuoc, mathuoc);
	this->slxuat = slxuat;
	this->dongia = dongia;
	this->ngayxuat = ngayxuat;
}

ListNode_DX::ListNode_DX(DongXuat dongxuat){
	data = dongxuat;
	next = NULL;
}

LinkListDX::~LinkListDX(){
	ListNode_DX *auxilaryNode, *iterator;
	iterator = head;
	while(iterator){
		auxilaryNode = iterator->next;
		delete iterator;
		iterator = auxilaryNode;
	}
	head = NULL;	// to affect the real head back in the caller
}

int LinkListDX:: ListLength(){
	struct ListNode_DX *current = head;
	int count = 0;
	
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

void LinkListDX::InsertDX(DongXuat data, int position){
	int k = 1;
	ListNode_DX *p, *q, *newNode;
	newNode = new ListNode_DX(data);
	
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

bool LinkListDX::CoincideMaThuocDX_SoPhieu(char *sophieu, char *mathuoc){
	ListNode_DX *p = head;
	while(p){
		if(strcmp(sophieu, p->data.sophieu) == 0 && strcmp(mathuoc, p->data.mathuoc) == 0)
			return true;
		p = p->next;
	}
	return false;
}

bool LinkListDX::CheckFKDX_sophieu(char* sophieu){
	ListNode_DX *p = head;
	while(p){
		if(strcmp(sophieu, p->data.sophieu) == 0)
			return true;
		p = p->next;
	}
	return false;
}

bool LinkListDX::CheckFKDX_mathuoc(char* maThuoc){
	ListNode_DX *p = head;
	while(p){
		if(strcmp(maThuoc, p->data.mathuoc) == 0)
			return true;
		p = p->next;
	}
	return false;
}

//void LinkListDX::CreateDX(){
//	char sophieu[10];
//	char mathuoc[10];
//	int slxuat;
//	int dongia;
//	
//	int i = 0;
//	while (true){
////		cin.ignore();
//		fflush(stdin);
//		cout<<"Nhap so phieu(enter de thoat): ";
//		cin.getline(sophieu, 10);
//		if(sophieu[0] == NULL) break;
//		if(strlen(sophieu) != 9 ){
//			cout<<"So phieu phai co 9 ki tu!";
//			cout<<"---Nhap Lai---";
//			continue;
//		}
//
//		cout<<"Nhap ma thuoc: ";
//		cin.getline(mathuoc, 10);
//		if(strlen(mathuoc) != 9){
//			cout<<"Ma thuoc phai co 9 ki tu!";
//			cout<<"---Nhap Lai---";
//			continue;
//		}
//		
//		if(CoincideMaThuocDX_SoPhieu(sophieu, mathuoc)){
//			cout<<"Ma thuoc da ton tai!";
//			cout<<"---Nhap Lai---";
//			continue;
//		}
//		
//		cout<<"Nhap so luong xuat: ";
//		cin>>slxuat;
//		cout<<"Nhap so don gia: ";
//		cin>>dongia;
//		
//		DongXuat dx_new(sophieu, mathuoc, slxuat, dongia);
//		InsertDX(dx_new, ++i);
////		fflush(stdin);
//	}
//}

void LinkListDX::DeleteALL(){
	ListNode_DX *p, *q;
	p = head;
	while(p != NULL){
		q = p;
		p = p->next;
		delete q;
	}
	head = NULL;
}


void LinkListDX::DeleteDX(char *sophieu, char *mathuoc){
//	cout<<"In delete func!";
	ListNode_DX *p, *q, *y;
	if(head == NULL){
//		cout<<"Danh sach rong";
		return;
	}
	p = head;
//	cout<<"head: "<<head->data.sophieu;
	
	if(mathuoc[0] != NULL){
//		cout<<"MA THUOC KHAC NULL";
		/* o vi tri bat dau*/
		if(strcmp(sophieu, head->data.sophieu) == 0 && strcmp(mathuoc, head->data.mathuoc) == 0){
			head = head->next;
			delete p;
//			cout<<"Xoa thanh cong!";
			return;
		}else{
			// Duyet list cho den khi toi vi tri muon xoa
			while((p != NULL) && (strcmp(sophieu, p->data.sophieu) != 0 && strcmp(mathuoc, p->data.mathuoc) != 0)){
//				cout<<"a";
				q = p;
				p = p->next;
			}
			if(p == NULL)
				return; // Du lieu ko ton tai, Kiem tra lai sophieu va mathuoc!
			else{
				// Xoa o vi triu giua
				q->next = p->next;
				delete p;
//				cout<<"Xoa thanh cong!";
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
						//y = q->next;
						delete p; p = NULL;
						p = q;
					}
			}
		}
	}
	return;
}

// In danh sach
void LinkListDX::printDX(){
	ListNode_DX *p = head;
	if(p == NULL){
		cout<<" Danh sach rong!";
		return;
	}
	while(p){
		cout<<"So phieu: "<<p->data.sophieu;
		cout<<"Ma thuoc: "<<p->data.mathuoc;
		cout<<"So luong xuat: "<<p->data.slxuat;
		cout<<"Don gia: "<<p->data.dongia;
		p = p->next;
		cout<<"\n";
	}
}

// Tim kiem
ListNode_DX *LinkListDX::SearchDX(char *sophieu, char *mathuoc){
	ListNode_DX *p;
	p = head;
	while(p != NULL){
		if(strcmp(sophieu, p->data.sophieu) == 0 && strcmp(mathuoc, p->data.mathuoc) == 0)
			return p;
		p = p->next;
	}
	
//	cout<<"Du lieu ko ton tai, Kiem tra lai sophieu va mathuoc!";
	return NULL;
}

// Doc file
void LinkListDX::ReadFileDX(){
	DeleteALL();
	string data;
	int k = 1;
	ifstream fin("dongxuat.txt");
	
	if(!fin){
		cout<<"Khong tim thay file";
		return ;
	}
	getline(fin, data);
	if(data.size() == 0)
		cout<<"Khong co du lieu duoc luu!";
	else{
		int soluong = atoi(data.c_str());	// Gan so luong records trong file
//		cout<<"----So luong PX: "<<soluong<<"----\n"<<endl;
		while(!fin.eof()){
			DongXuat dongxuat;	// Bien tam luu du lieu tu ban phim
			
			getline(fin, data);
			if(data.size() == 0) break;
			strcpy(dongxuat.sophieu, data.c_str());
			getline(fin, data);		strcpy(dongxuat.mathuoc,data.c_str());
			getline(fin, data);		dongxuat.slxuat = atoi(data.c_str());
			getline(fin, data); 	dongxuat.dongia = atoi(data.c_str());
			//new
			getline(fin, data);		char* cstr = new char[data.length() + 1]; strcpy(cstr, data.c_str());
			dongxuat.ngayxuat.ngay = atoi(strtok(cstr, " "));
			dongxuat.ngayxuat.thang = atoi(strtok(NULL, " "));
			dongxuat.ngayxuat.nam = atoi(strtok(NULL, " "));
			
			InsertDX(dongxuat, k);
			k++;
		}
	}
}

int LinkListDX::SizeOfDX(){
	ListNode_DX *p;
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

void LinkListDX::DataSave(ofstream &fout, DongXuat data){
	/* thuc hien ghi du lieu vao file */
	fout<<data.sophieu<<endl;
	fout<<data.mathuoc<<endl;
	fout<<data.slxuat<<endl;
	fout<<data.dongia<<endl;
	fout << data.ngayxuat.ngay << ' ' << data.ngayxuat.thang << ' ' << data.ngayxuat.nam << endl;
}

void LinkListDX::SaveFileDX(){
	cout<<head->data.dongia;
	if(head){
	cout<<head->data.dongia;
	ofstream fout("dongxuat.txt", ios::out);
	int soluong = SizeOfDX();
	ListNode_DX *p;
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

// new
void LinkListDX::ArrayDX(DongXuat *dsdx){
	int i = 0;
	ListNode_DX *p = head;
	
	while(p){
		dsdx[i++] = p->data;
		p = p->next;
	}
}



