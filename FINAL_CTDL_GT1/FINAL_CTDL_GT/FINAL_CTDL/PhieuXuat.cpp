#include"PhieuXuat.h"

//
//void TreePX::CreatePX(){
//	char  sophieu[10];
//	char manv[10];
//	char makhoacn[10];
//	ThoiGian ngayxuat;
//	char tenkhont[50] = "hanoi";
//	char tenkhoxt[50] = "haiphong";
//
//	ngayxuat.ngay = 5;
//	ngayxuat.thang = 4;
//	ngayxuat.nam = 2023;
//
//	NodePX* parent = NULL;
//
//	while (true) {
//		//cin.ignore();
//		cout << "Nhap so phieu(enter de thoat): ";
//		cin.getline(sophieu, 10);
//		if (sophieu[0] == NULL) break;
//		if(strlen(sophieu) != 9){
//			cout<<"So phieu phai co 9 ki tu!";
//			cout<<"---Nhap Lai---";
//			continue;
//		}
//		if(CoincideSoPhieuPX(this->root, sophieu)){
//			cout<<"So phieu da ton tai!";
//			cout<<"---Nhap Lai---";
//			continue;
//		}
//		cout << "Nhap manv: ";
//		cin.getline(manv, 10);
//		cout << "Nhap ma khoa chuc nang: ";
//		cin.getline(makhoacn, 10);
//		/*stt = soluong + 1;	// Tang so luong record
//		soluong += 1;*/
//
////		phieunhap_new = new PhieuXuat(sophieu, manv, makhoacn, ngayxuat, tenkhont, tenkhoxt);
//		PhieuXuat px_new(sophieu, manv, makhoacn, ngayxuat, tenkhont, tenkhoxt);
//		
//		this->root = InsertPX(this->root, parent, px_new);
//	}
//}

int TreePX::Height(NodePX *root){
	if (!root)
		return -1;
	else
		return root->height;
}

NodePX *TreePX::SingleRotateLeft(NodePX *X){
	NodePX* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodePX *TreePX::SingleRotateRight(NodePX *X){
	NodePX* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodePX *TreePX::DoubleRotatewithLeft(NodePX* Z){
	Z->left = SingleRotateRight(Z->left);
	return SingleRotateLeft(Z);
}

NodePX *TreePX::DoubleRotatewithRight(NodePX* Z){
	Z->right = SingleRotateLeft(Z->right);
	return SingleRotateRight(Z);
}

bool TreePX::CoincideSoPhieuPX(NodePX *root, char *sophieu){
	if(root==NULL)
    {
        return false;
        
    }
    else if(strcmp(sophieu, root->data.sophieu)==0)
        return true;
    else if(strcmp(sophieu, root->data.sophieu)<0)
    {
        return CoincideSoPhieuPX(root->left, sophieu);
    }
    else if(strcmp(sophieu, root->data.sophieu)>0){
        return CoincideSoPhieuPX(root->right,sophieu);
    }
}

NodePX* TreePX::InsertPX(NodePX *root, NodePX *parent, PhieuXuat data){
	// TrHop 1: root == NULL
	if (!root) {
		root = new NodePX(data);
		if (!root) {
			cout << "Loi bo nho"; return NULL;
		}
		else{
			root->left = root->right = NULL;
		}
	}

	else if (strcmp(data.sophieu, root->data.sophieu) < 0) {
		root->left = InsertPX(root->left, root, data);
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (strcmp(data.sophieu, root->left->data.sophieu) < 0)
				root = SingleRotateLeft(root);
			else root = DoubleRotatewithLeft(root);
		}
	}
	
	else if (strcmp(data.sophieu, root->data.sophieu) > 0) {
		root->right = InsertPX(root->right, root, data);
		if ((Height(root->right) - Height(root->left)) == 2) {
			if (strcmp(data.sophieu, root->right->data.sophieu) > 0)
				root = SingleRotateRight(root);
			else root = DoubleRotatewithRight(root);
		}
	}
	/*Nguoc sophieu da ton tai trong cay. Nen ko lam gi ca*/
	root->height = max(Height(root->left), Height(root->right)) + 1;
	
	return root;
}

void TreePX::PrintPX( NodePX* root) {
	// Inorder Traversal LDR
	if (root) {
		PrintPX(root->left);
		cout << "So phieu" << root->data.sophieu << endl;
		cout << "Ma nv: " << root->data.manv << endl;
		cout << "Ma khoacn: "<< root->data.makhoacn;

		cout << endl<<endl;
		PrintPX(root->right);
	}
}

void TreePX::ReadFilePX() {
	string data;
	ifstream fin("phieuxuat.txt");
	this->root = NULL;

	if (!fin) {
		cout <<"Khong tim thay file";
		return ;
	}
	getline(fin, data);
	if (data.size() == 0) {
		cout << "Khong co du lieu duoc luu!";
	}	
	else{
		int soluong = atoi(data.c_str());	// Gan so luong records trong file
//		cout<<"----So luong PX: "<<soluong<<"----\n"<<endl;
		while (!fin.eof()) {	
			PhieuXuat phieuxuat;	// Bien tam luu du lieu tu ban phim
	
			getline(fin, data);
			if (data.size() == 0) break;
			strcpy(phieuxuat.sophieu, data.c_str());
			getline(fin, data);		strcpy(phieuxuat.manv,data.c_str());
			getline(fin, data);		strcpy(phieuxuat.makhoacn, data.c_str());
			getline(fin, data);		char* cstr = new char[data.length() + 1]; strcpy(cstr, data.c_str());
			phieuxuat.ngayxuat.ngay = atoi(strtok(cstr, " "));
			phieuxuat.ngayxuat.thang = atoi(strtok(NULL, " "));
			phieuxuat.ngayxuat.nam = atoi(strtok(NULL, " "));
			getline(fin, data);		strcpy(phieuxuat.tenkhont, data.c_str());
			getline(fin, data);		strcpy(phieuxuat.tenkhoxt, data.c_str());
			getline(fin, data);		strcpy(phieuxuat.manvnew,data.c_str());
			
			this->root = InsertPX(this->root, NULL, phieuxuat);
		}
	
//		PrintPX(this->root);
	}		// Ko dung reference dc vi root coThe NULL
}

void TreePX::DataSave(ofstream &fout, PhieuXuat data) {
	/* thuc hien ghi du lieu vao file */
	fout << data.sophieu << endl;
	fout << data.manv << endl;
	fout << data.makhoacn << endl;
	fout << data.ngayxuat.ngay << ' ' << data.ngayxuat.thang << ' ' << data.ngayxuat.nam << endl;
	fout << data.tenkhont << endl;
	fout << data.tenkhoxt << endl;
	fout << data.manvnew << endl;
}

int TreePX::SizeOfPX(NodePX *root){
	/* Tim so luong phieu xuat trong cay */
	if(root == NULL)
		return 0;
	else return(SizeOfPX(root->left) + 1 + SizeOfPX(root->right));
}

void TreePX::SaveFilePX(){
		if (this->root) {
		stack<NodePX*> stack;
		ofstream fout("phieuxuat.txt", ios::out);
		int soluong = SizeOfPX(this->root);
		
		fout << soluong << endl;
		
		NodePX *root = this->root;
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

NodePX* TreePX::FindNodePX(NodePX* root, const  char *tukhoa) {
	NodePX *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(tukhoa, root->data.sophieu))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = FindNodePX(root->left, tukhoa);
			if (temp)
				return temp;
			else return(FindNodePX(root->right, tukhoa));
		}
	}
	return NULL;
}

NodePX *TreePX::SearchPX(){
	/* Tim Kiem phieu xuat, tra ve phieu xuat tim dc */
	char m_sophieu[10];
	NodePX* phieuTimDc;

	cout << "\nNhap ma so phieu can tim: ";
	cin.getline(m_sophieu, 10);

	phieuTimDc = FindNodePX(this->root, m_sophieu);
	if (phieuTimDc) {
		cout << "So phieu" << phieuTimDc->data.sophieu << endl;
		cout << "Ma nv: " << phieuTimDc->data.manv << endl;
		cout << "Ma khoacn: " << phieuTimDc->data.makhoacn;

		cout << endl << endl;
	}
	else cout << "Khong co so phieu nay!";
	return phieuTimDc;
}

NodePX *TreePX::FindMaxPX(NodePX *root){
	if(root == NULL)
		return NULL;
	else if(root->right == NULL)
		return root;
	else return FindMaxPX(root->right);
}

void TreePX::CopyDataPX(NodePX* dest, const NodePX res ){
	strcpy(dest->data.sophieu, res.data.sophieu);
	strcpy(dest->data.manv, res.data.manv);
	strcpy(dest->data.makhoacn, res.data.makhoacn);
	dest->data.ngayxuat = res.data.ngayxuat;
	strcpy(dest->data.tenkhont, res.data.tenkhont);
	strcpy(dest->data.tenkhoxt, res.data.tenkhoxt);
	strcpy(dest->data.manvnew, res.data.manvnew);
}

NodePX* TreePX::NNDPX(NodePX* root, char* sophieu) {
	//Node Need Delete PX
	NodePX* temp;
	if (root == NULL) cout<<"";
	else if (strcmp(sophieu, root->data.sophieu)<0)
		root->left = NNDPX(root->left, sophieu);
	else if (strcmp(sophieu, root->data.sophieu)>0)
		root->right = NNDPX(root->right, sophieu);
	else {
		//Tim thay phieu xuat
		if (root->left && root->right) {
			/*Doi vitri voi node lon nhat ben trai cay*/
			temp = FindMaxPX(root->left);
			CopyDataPX(root, *temp);
			root->left = NNDPX(root->left, root->data.sophieu);
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

void TreePX::DeletePX() {
	NodePX* find_sophieu;

	find_sophieu = SearchPX();
	NodePX *ERR = NNDPX(this->root, find_sophieu->data.sophieu);
	if(ERR)
		cout << "Phieu xuat da duoc xoa!" << endl;
	else
		cout << "Khong tim thay so phieu nay!";
}

// new
void TreePX::ArrayPX(NodePX *root, PhieuXuat *dspx){
	stack<NodePX*> stack;
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
		dspx[i++] = root->data;
		root = root->right;
	}
}

NodePX *TreePX::CheckFKPX_maNV(NodePX *root, char* manv){
	NodePX *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(manv, root->data.manv))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = CheckFKPX_maNV(root->left, manv);
			if (temp)
				return temp;
			else return(CheckFKPX_maNV(root->right, manv));
		}
	}
	return NULL;
}

NodePX *TreePX::CheckFKPX_maKCN(NodePX *root, char* makhoacn){
	NodePX *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(makhoacn, root->data.makhoacn))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = CheckFKPX_maKCN(root->left, makhoacn);
			if (temp)
				return temp;
			else return(CheckFKPX_maKCN(root->right, makhoacn));
		}
	}
	return NULL;
}

