#include"NhanVien.h"

//
//void TreeNV::CreateNV(){
//	char maNV[10];
//	char  hoTen[30];
//	char  chucVu[20];
//	
//	NodeNV* parent = NULL;
//
//	while (true) {
//		//cin.ignore();
//		cout << "Nhap ma nhan vien(enter de thoat): ";
//		cin.getline(maNV, 10);
//		if (maNV[0] == NULL) break;
//		if(strlen(maNV) != 9){
//			cout<<"Ma NV phai co 9 ki tu!";
//			cout<<"---Nhap Lai---";
//			continue;
//		}
//		if(CoincideMaNV(this->root, maNV)){
//			cout<<"Ma NV da ton tai!";
//			cout<<"---Nhap Lai---";
//			continue;
//		}
//		cout << "Nhap ho va ten: ";
//		cin.getline(hoTen, 30);
//		
//		cout << "Nhap chuc vu: ";
//		cin.getline(chucVu, 20);
//		/*stt = soluong + 1;	// Tang so luong record
//		soluong += 1;*/
//
////		phieunhap_new = new PhieuXuat(sophieu, manv, makhoacn, ngayxuat, tenkhont, tenkhoxt);
//		NhanVien nhanvien_new( maNV,hoTen, chucVu );
//		
//		this->root = InsertNV(this->root, parent, nhanvien_new);
//	}
//}

int TreeNV::Height(NodeNV *root){
	if (!root)
		return -1;
	else
		return root->height;
}

NodeNV *TreeNV::SingleRotateLeft(NodeNV *X){
	NodeNV* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodeNV *TreeNV ::SingleRotateRight(NodeNV *X){
	NodeNV* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodeNV *TreeNV::DoubleRotatewithLeft(NodeNV* Z){
	Z->left = SingleRotateRight(Z->left);
	return SingleRotateLeft(Z);
}

NodeNV *TreeNV::DoubleRotatewithRight(NodeNV* Z){
	Z->right = SingleRotateLeft(Z->right);
	return SingleRotateRight(Z);
}

bool TreeNV::CoincideMaNV(NodeNV *root, char *maNV){
	if(root==NULL)
    {
        return false;
    }
    else if(strcmp(maNV, root->data.maNV)==0)
        return true;
    else if(strcmp(maNV, root->data.maNV)<0)
    {
        return CoincideMaNV(root->left, maNV);
    }
    else if(strcmp(maNV, root->data.maNV)>0){
        return CoincideMaNV(root->right,maNV);
    }
}

NodeNV* TreeNV::InsertNV(NodeNV *root, NodeNV *parent, NhanVien data){
	// TrHop 1: root == NULL
	if (!root) {
		root = new NodeNV(data);
		if (!root) {
			cout << "Loi bo nho"; return NULL;
		}
		else{
			root->left = root->right = NULL;
		}
	}

	else if (strcmp(data.maNV, root->data.maNV) < 0) {
		root->left = InsertNV(root->left, root, data);
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (strcmp(data.maNV, root->left->data.maNV) < 0)
				root = SingleRotateLeft(root);
			else root = DoubleRotatewithLeft(root);
		}
	}
	
	else if (strcmp(data.maNV, root->data.maNV) > 0) {
		root->right = InsertNV(root->right, root, data);
		if ((Height(root->right) - Height(root->left)) == 2) {
			if (strcmp(data.maNV, root->right->data.maNV) > 0)
				root = SingleRotateRight(root);
			else root = DoubleRotatewithRight(root);
		}
	}
	/*Nguoc sophieu da ton tai trong cay. Nen ko lam gi ca*/
	root->height = max(Height(root->left), Height(root->right)) + 1;
	
	return root;
}

void TreeNV::PrintNV( NodeNV* root) {
	// Inorder Traversal LDR
	if (root) {
		PrintNV(root->left);
		cout << "Ma nv: " << root->data.maNV << endl;
		cout << "Ho va Ten" << root->data.hoTen << endl;
		cout << "Chuc vu" << root->data.chucVu << endl;
		cout << endl<<endl;
		PrintNV(root->right);

	}
}

void TreeNV::ReadFileNV() {
	string data;
	ifstream fin("nhanvien.txt");
	this->root = NULL;

	if (!fin) {
		cout <<"Khong tim thay file";
		return ;
	}
	getline(fin, data);
	if (data.size() == 0) 
		cout << "Khong co du lieu duoc luu!";
	else{
		int soluong = atoi(data.c_str());	// Gan so luong records trong file
		while (!fin.eof()) {	
			NhanVien nhanvien;	// Bien tam luu du lieu tu ban phim
	
			getline(fin, data);
			if (data.size() == 0) break;
			strcpy(nhanvien.maNV, data.c_str());
			getline(fin, data);		strcpy(nhanvien.hoTen,data.c_str());
			getline(fin, data);		strcpy(nhanvien.chucVu,data.c_str());
			this->root = InsertNV(this->root, NULL, nhanvien);
		}
	
//		PrintNV(this->root);
	}		// Ko dung reference dc vi root coThe NULL
}
//da sua tu nay tro len
void TreeNV::DataSave(ofstream &fout, NhanVien data) {
	/* thuc hien ghi du lieu vao file */
	fout << data.maNV << endl;
	fout << data.hoTen << endl;
	fout << data.chucVu << endl;
}

int TreeNV::SizeOfNV(NodeNV *root){
	/* Tim so luong phieu xuat trong cay */
	if(root == NULL)
		return 0;
	else return(SizeOfNV(root->left) + 1 + SizeOfNV(root->right));
}

void TreeNV::SaveFileNV(){
		if (this->root) {
		stack<NodeNV*> stack;
		ofstream fout("nhanvien.txt", ios::out);
		int soluong2 = SizeOfNV(this->root);
		
		fout << soluong2 << endl;
		
		NodeNV *root = this->root;
		while (1) {
			while (root) {
				stack.push(root);
				//Lay cay con trai va tiep tuc nap vao stack
				root = root->left;
			}
			if (stack.empty()) break;
			root = stack.top();
			stack.pop();
			DataSave(fout, root->data);
			//Sau khi duyet het cay con trai va node hien tai. Gio den cay con phai
			root = root->right;
		}

		fout.close();
	}
	else
		cout << "Khong co du lieu de luu";
}

NodeNV* TreeNV::FindNodeNV(NodeNV* root, const  char *tukhoa) {
	NodeNV *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(tukhoa, root->data.maNV))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = FindNodeNV(root->left, tukhoa);
			if (temp)
				return temp;
			else return(FindNodeNV(root->right, tukhoa));
		}
	}
	return NULL;
}

NodeNV *TreeNV::SearchNV(){
	/* Tim Kiem phieu xuat, tra ve phieu xuat tim dc */
	char m_maNV[10];
	NodeNV* NVTimDc;

	cout << "\nNhap ma nhan vien can tim: ";
	cin.getline(m_maNV, 10);

	NVTimDc = FindNodeNV(this->root, m_maNV);
	if (NVTimDc) {
		cout << "Ma nhan vien" << NVTimDc->data.maNV << endl;
		cout << "Ho ten: " << NVTimDc->data.hoTen << endl;
		cout << "Chuc vu: " << NVTimDc->data.chucVu << endl;
		cout << endl << endl;
	}
	else cout << "Khong co nhan vien nay!";
	return NVTimDc;
}

NodeNV *TreeNV::FindMaxNV(NodeNV *root){
	if(root == NULL)
		return NULL;
	else if(root->right == NULL)
		return root;
	else return FindMaxNV(root->right);
}

void TreeNV::CopyDataNV(NodeNV* dest, const NodeNV res ){
	strcpy(dest->data.maNV, res.data.maNV);
	strcpy(dest->data.hoTen, res.data.hoTen);
	strcpy(dest->data.chucVu, res.data.chucVu);
}

NodeNV* TreeNV::NNDNV(NodeNV* root, char* maNV) {
	NodeNV* temp;
	if (root == NULL) cout<<"";
	else if (strcmp(maNV, root->data.maNV)<0)
		root->left = NNDNV(root->left, maNV);
	else if (strcmp(maNV, root->data.maNV)>0)
		root->right = NNDNV(root->right, maNV);
	else {
		//Tim thay phieu xuat
		if (root->left && root->right) {
			/*Doi vitri voi node lon nhat ben trai cay*/
			temp = FindMaxNV(root->left);
			CopyDataNV(root, *temp);
			root->left = NNDNV(root->left, root->data.maNV);
		}
		else {
			/*Co mot con*/
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			delete(temp);
		}
	}
	return root;
}

void TreeNV::DeleteNV() {
	NodeNV* find_maNV;

	find_maNV = SearchNV();
	NodeNV *ERR = NNDNV(this->root, find_maNV->data.maNV);
	if(ERR)
		cout << "Nhan vien da duoc xoa!" << endl;
	else
		cout << "Khong tim thay nhan vien nay!";
}

void TreeNV::ArrayNV(NodeNV *root, NhanVien *dsnv){
	stack<NodeNV*> stack;
	int i = 0;
	while(1){
		while(root){
			stack.push(root);
			// duyet cay con trai va them vao stack
			root = root->left;
		}
		if(stack.empty()) break;
		root = stack.top();
		stack.pop();
		dsnv[i++] = root->data;
		root = root->right;
	}
}


