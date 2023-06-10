#include"KCN.h"


void TreeKCN::CreateKCN(){
	char maKCN[10];
	char  tenKCN[25];
	char  tenNguoiDD[25];
	
	NodeKCN* parent = NULL;

	while (true) {
		//cin.ignore();
		cout << "Nhap ma khoa chuc nang(enter de thoat): ";
		cin.getline(maKCN, 10);
		if (maKCN[0] == NULL) break;
		if(strlen(maKCN) != 9){
			cout<<"Ma KCN phai co 9 ki tu!";
			cout<<"---Nhap Lai---";
			continue;
		}
		if(CoincideMaKCN(this->root, maKCN)){
			cout<<"Ma KCN da ton tai!";
			cout<<"---Nhap Lai---";
			continue;
		}
		cout << "Nhap ten khoa chuc nang: ";
		cin.getline(tenKCN, 30);
		
		cout << "Nhap ten nguoi dai dien: ";
		cin.getline(tenNguoiDD, 20);
		/*stt = soluong + 1;	// Tang so luong record
		soluong += 1;*/

//		phieunhap_new = new PhieuXuat(sophieu, manv, makhoacn, ngayxuat, tenkhont, tenkhoxt);
		KhoaChucNang kcn_new( maKCN,tenKCN, tenNguoiDD );
		
		this->root = InsertKCN(this->root, parent, kcn_new);
	}
}

int TreeKCN::Height(NodeKCN *root){
	if (!root)
		return -1;
	else
		return root->height;
}

NodeKCN *TreeKCN::SingleRotateLeft(NodeKCN *X){
	NodeKCN* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodeKCN *TreeKCN ::SingleRotateRight(NodeKCN *X){
	NodeKCN* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodeKCN *TreeKCN::DoubleRotatewithLeft(NodeKCN* Z){
	Z->left = SingleRotateRight(Z->left);
	return SingleRotateLeft(Z);
}

NodeKCN *TreeKCN::DoubleRotatewithRight(NodeKCN* Z){
	Z->right = SingleRotateLeft(Z->right);
	return SingleRotateRight(Z);
}

bool TreeKCN::CoincideMaKCN(NodeKCN *root, char *maKCN){
	if(root==NULL)
    {
        return false;
    }
    else if(strcmp(maKCN, root->data.maKCN)==0)
        return true;
    else if(strcmp(maKCN, root->data.maKCN)<0)
    {
        return CoincideMaKCN(root->left, maKCN);
    }
    else if(strcmp(maKCN, root->data.maKCN)>0){
        return CoincideMaKCN(root->right,maKCN);
    }
}

NodeKCN* TreeKCN::InsertKCN(NodeKCN *root, NodeKCN *parent, KhoaChucNang data){
	// TrHop 1: root == NULL
	if (!root) {
		root = new NodeKCN(data);
		if (!root) {
			cout << "Loi bo nho"; return NULL;
		}
		else{
			root->left = root->right = NULL;
		}
	}

	else if (strcmp(data.maKCN, root->data.maKCN) < 0) {
		root->left = InsertKCN(root->left, root, data);
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (strcmp(data.maKCN, root->left->data.maKCN) < 0)
				root = SingleRotateLeft(root);
			else root = DoubleRotatewithLeft(root);
		}
	}
	
	else if (strcmp(data.maKCN, root->data.maKCN) > 0) {
		root->right = InsertKCN(root->right, root, data);
		if ((Height(root->right) - Height(root->left)) == 2) {
			if (strcmp(data.maKCN, root->right->data.maKCN) > 0)
				root = SingleRotateRight(root);
			else root = DoubleRotatewithRight(root);
		}
	}
	/*Nguoc sophieu da ton tai trong cay. Nen ko lam gi ca*/
	root->height = max(Height(root->left), Height(root->right)) + 1;
	
	return root;
}

void TreeKCN::PrintKCN( NodeKCN* root) {
	// Inorder Traversal LDR
	if (root) {
		PrintKCN(root->left);
		cout << "Ma KCN : " << root->data.maKCN << endl;
		cout << "Ten KCN" << root->data.tenKCN << endl;
		cout << "Ten nguoi DD:" << root->data.tenNguoiDD << endl;
		cout << endl<<endl;
		PrintKCN(root->right);

	}
}

void TreeKCN::ReadFileKCN() {
	string data;
	ifstream fin("khoachucnang.txt");
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
//		cout<<"----So luong khoa chuc nang: "<<soluong<<"----\n"<<endl;
		while (!fin.eof()) {	
			KhoaChucNang khoachucnang;	// Bien tam luu du lieu tu ban phim
	
			getline(fin, data);
			if (data.size() == 0) break;
			strcpy(khoachucnang.maKCN, data.c_str());
			getline(fin, data);		strcpy(khoachucnang.tenKCN,data.c_str());
			getline(fin, data);		strcpy(khoachucnang.tenNguoiDD,data.c_str());
			this->root = InsertKCN(this->root, NULL, khoachucnang);
		}
	
//		PrintKCN(this->root);
	}		// Ko dung reference dc vi root coThe NULL
}
//da sua tu nay tro len
void TreeKCN::DataSave(ofstream &fout, KhoaChucNang data) {
	/* thuc hien ghi du lieu vao file */
	fout << data.maKCN << endl;
	fout << data.tenKCN << endl;
	fout << data.tenNguoiDD << endl;
}

int TreeKCN::SizeOfKCN(NodeKCN *root){
	/* Tim so luong phieu xuat trong cay */
	if(root == NULL)
		return 0;
	else return(SizeOfKCN(root->left) + 1 + SizeOfKCN(root->right));
}

void TreeKCN::SaveFileKCN(){
		if (this->root) {
		stack<NodeKCN*> stack;
		ofstream fout("khoachucnang.txt", ios::out);
		int soluong = SizeOfKCN(this->root);
		
		fout << soluong << endl;
		
		NodeKCN *root = this->root;
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

NodeKCN* TreeKCN::FindNodeKCN(NodeKCN* root, const  char *tukhoa) {
	NodeKCN *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(tukhoa, root->data.maKCN))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = FindNodeKCN(root->left, tukhoa);
			if (temp)
				return temp;
			else return(FindNodeKCN(root->right, tukhoa));
		}
	}
	return NULL;
}

NodeKCN *TreeKCN::SearchKCN(){
	/* Tim Kiem phieu xuat, tra ve phieu xuat tim dc */
	char m_maKCN[10];
	NodeKCN* KCNTimDc;

	cout << "\nNhap ma khoa chuc nang can tim: ";
	cin.getline(m_maKCN, 10);

	KCNTimDc = FindNodeKCN(this->root, m_maKCN);
	if (KCNTimDc) {
		cout << "Ma KCN" << KCNTimDc->data.maKCN << endl;
		cout << "Ten KCN: " << KCNTimDc->data.tenKCN << endl;
		cout << "Ten nguoi DD: " << KCNTimDc->data.tenNguoiDD << endl;
		cout << endl << endl;
	}
	else cout << "Khong co khoa chuc nang nay!";
	return KCNTimDc;
}

NodeKCN *TreeKCN::FindMaxKCN(NodeKCN *root){
	if(root == NULL)
		return NULL;
	else if(root->right == NULL)
		return root;
	else return FindMaxKCN(root->right);
}

void TreeKCN::CopyDataKCN(NodeKCN* dest, const NodeKCN res ){
	strcpy(dest->data.maKCN, res.data.maKCN);
	strcpy(dest->data.tenKCN, res.data.tenKCN);
	strcpy(dest->data.tenNguoiDD, res.data.tenNguoiDD);
}

NodeKCN* TreeKCN::NNDKCN(NodeKCN* root, char* maKCN) {
	NodeKCN* temp;
	if (root == NULL) cout<<"";
	else if (strcmp(maKCN, root->data.maKCN)<0)
		root->left = NNDKCN(root->left, maKCN);
	else if (strcmp(maKCN, root->data.maKCN)>0)
		root->right = NNDKCN(root->right, maKCN);
	else {
		//Tim thay phieu xuat
		if (root->left && root->right) {
			/*Doi vitri voi node lon nhat ben trai cay*/
			temp = FindMaxKCN(root->left);
			CopyDataKCN(root, *temp);
			root->left = NNDKCN(root->left, root->data.maKCN);
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

void TreeKCN::DeleteKCN() {
	NodeKCN* find_maKCN;

	find_maKCN = SearchKCN();
	NodeKCN *ERR = NNDKCN(this->root, find_maKCN->data.maKCN);
	if(ERR)
		cout << "Khoa chuc nang da duoc xoa!" << endl;
	else
		cout << "Khong tim thay khoa chuc nang nay!";
}

void TreeKCN::ArrayKCN(NodeKCN *root, KhoaChucNang *dskcn){
	stack<NodeKCN*> stack;
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
		dskcn[i++] = root->data;
		root = root->right;
	}
}


