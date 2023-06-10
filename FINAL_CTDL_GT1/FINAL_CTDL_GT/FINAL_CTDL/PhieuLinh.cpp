#include"PhieuLinh.h"


void TreePL::CreatePL(){
	char sophieu[10];
	char  maThuoc[10];
	char  maKCN[10];
	ThoiGian1 ngayYC;
	ngayYC.ngay = 5;
	ngayYC.thang = 4;
	ngayYC.nam = 2023;
	NodePL* parent = NULL;

	while (true) {
		//cin.ignore();
		cout << "Nhap so phieu linh (enter de thoat): ";
		cin.getline(sophieu, 10);
		if (sophieu[0] == NULL) break;
		if(strlen(sophieu) != 9){
			cout<<"So phieu phai co 9 ki tu!";
			cout<<"---Nhap Lai---";
			continue;
		}
		if(CoincideMaPL(this->root, sophieu)){
			cout<<"So phieu da ton tai!";
			cout<<"---Nhap Lai---";
			continue;
		}
		cout << "Nhap ma thuoc: ";
		cin.getline(maThuoc, 10);
		
		cout << "Nhap ma khoa chuc nang: ";
		cin.getline(maKCN, 10);
		
		
		/*stt = soluong + 1;	// Tang so luong record
		soluong += 1;*/

//		phieunhap_new = new PhieuXuat(sophieu, manv, makhoacn, ngayxuat, tenkhont, tenkhoxt);
		PhieuLinh pl_new( sophieu,maThuoc,maKCN, ngayYC );
		
		this->root = InsertPL(this->root, parent, pl_new);
	}
}

int TreePL::Height(NodePL *root){
	if (!root)
		return -1;
	else
		return root->height;
}

NodePL *TreePL::SingleRotateLeft(NodePL *X){
	NodePL* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodePL *TreePL ::SingleRotateRight(NodePL *X){
	NodePL* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodePL *TreePL::DoubleRotatewithLeft(NodePL* Z){
	Z->left = SingleRotateRight(Z->left);
	return SingleRotateLeft(Z);
}

NodePL *TreePL::DoubleRotatewithRight(NodePL* Z){
	Z->right = SingleRotateLeft(Z->right);
	return SingleRotateRight(Z);
}

bool TreePL::CoincideMaPL(NodePL *root, char *sophieu){
	if(root==NULL)
    {
        return false;
    }
    else if(strcmp(sophieu, root->data.sophieu)==0)
        return true;
    else if(strcmp(sophieu, root->data.sophieu)<0)
    {
        return CoincideMaPL(root->left, sophieu);
    }
    else if(strcmp(sophieu, root->data.sophieu)>0){
        return CoincideMaPL(root->right,sophieu);
    }
}

NodePL* TreePL::InsertPL(NodePL *root, NodePL *parent, PhieuLinh data){
	// TrHop 1: root == NULL
	if (!root) {
		root = new NodePL(data);
		if (!root) {
			cout << "Loi bo nho"; return NULL;
		}
		else{
			root->left = root->right = NULL;
		}
	}

	else if (strcmp(data.sophieu, root->data.sophieu) < 0) {
		root->left = InsertPL(root->left, root, data);
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (strcmp(data.sophieu, root->left->data.sophieu) < 0)
				root = SingleRotateLeft(root);
			else root = DoubleRotatewithLeft(root);
		}
	}
	
	else if (strcmp(data.sophieu, root->data.sophieu) > 0) {
		root->right = InsertPL(root->right, root, data);
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

void TreePL::PrintPL( NodePL* root) {
	// Inorder Traversal LDR
	if (root) {
		PrintPL(root->left);
		cout << "So phieu : " << root->data.sophieu << endl;
		cout << "Ma thuoc" << root->data.maNV << endl;
		cout << "Ma KCN:" << root->data.maKCN << endl;
		cout << "Ngay yeu cau:" << root->data.ngayYC.ngay <<" " << root->data.ngayYC.thang << " " << root->data.ngayYC.nam<< endl;
		cout << endl<<endl;
		PrintPL(root->right);

	}
}

void TreePL::ReadFilePL() {
	string data;
	ifstream fin("phieulinh.txt");
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
//		cout<<"----So luong phieu linh: "<<soluong<<"----\n"<<endl;
		while (!fin.eof()) {	
			PhieuLinh phieulinh;	// Bien tam luu du lieu tu ban phim
	
			getline(fin, data);
			if (data.size() == 0) break;
			strcpy(phieulinh.sophieu, data.c_str());
			getline(fin, data);		strcpy(phieulinh.maNV,data.c_str());
			getline(fin, data);		strcpy(phieulinh.maKCN,data.c_str());
			
			getline(fin, data);		char* cstr = new char[data.length() + 1]; strcpy(cstr, data.c_str());
			phieulinh.ngayYC.ngay = atoi(strtok(cstr, " "));
			phieulinh.ngayYC.thang = atoi(strtok(NULL, " "));
			phieulinh.ngayYC.nam = atoi(strtok(NULL, " "));
			this->root = InsertPL(this->root, NULL, phieulinh);
		}
	
//		PrintPL(this->root);
	}		// Ko dung reference dc vi root coThe NULL
}
//da sua tu nay tro len
void TreePL::DataSave(ofstream &fout, PhieuLinh data) {
	/* thuc hien ghi du lieu vao file */
	fout << data.sophieu << endl;
	fout << data.maNV << endl;
	fout << data.maKCN<< endl;
	fout << data.ngayYC.ngay << ' ' << data.ngayYC.thang << ' ' << data.ngayYC.nam << endl;
}

int TreePL::SizeOfPL(NodePL *root){
	/* Tim so luong phieu xuat trong cay */
	if(root == NULL)
		return 0;
	else return(SizeOfPL(root->left) + 1 + SizeOfPL(root->right));
}

void TreePL::SaveFilePL(){
		if (this->root) {
		stack<NodePL*> stack;
		ofstream fout("phieulinh.txt", ios::out);
		int soluong = SizeOfPL(this->root);
		
		fout << soluong << endl;
		
		NodePL *root = this->root;
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

NodePL* TreePL::FindNodePL(NodePL* root, const  char *tukhoa) {
	NodePL *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(tukhoa, root->data.sophieu))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = FindNodePL(root->left, tukhoa);
			if (temp)
				return temp;
			else return(FindNodePL(root->right, tukhoa));
		}
	}
	return NULL;
}

NodePL *TreePL::SearchPL(){
	/* Tim Kiem phieu xuat, tra ve phieu xuat tim dc */
	char m_sophieu[10];
	NodePL* SPTimDc;

	cout << "\nNhap so phieu can tim: ";
	cin.getline(m_sophieu, 10);

	SPTimDc = FindNodePL(this->root, m_sophieu);
	if (SPTimDc) {
		cout << "So Phieu" << SPTimDc->data.sophieu << endl;
		cout << "Ma Thuoc: " << SPTimDc->data.maNV << endl;
		cout << "Ma KCN: " << SPTimDc->data.maKCN << endl;
		cout << "Ngay yeu cau: " << SPTimDc->data.ngayYC.ngay <<" "<< SPTimDc->data.ngayYC.thang << " " << SPTimDc->data.ngayYC.nam << endl;
		cout << endl << endl;
	}
	else cout << "Khong co so phieu nay!";
	return SPTimDc;
}

NodePL *TreePL::FindMaxPL(NodePL *root){
	if(root == NULL)
		return NULL;
	else if(root->right == NULL)
		return root;
	else return FindMaxPL(root->right);
}

void TreePL::CopyDataPL(NodePL* dest, const NodePL res ){
	strcpy(dest->data.sophieu, res.data.sophieu);
	strcpy(dest->data.maNV, res.data.maNV);
	strcpy(dest->data.maKCN, res.data.maKCN);
	dest->data.ngayYC = res.data.ngayYC;
}

NodePL* TreePL::NNDPL(NodePL* root, char* sophieu) {
	NodePL* temp;
	if (root == NULL) cout<<"";
	else if (strcmp(sophieu, root->data.sophieu)<0)
		root->left = NNDPL(root->left, sophieu);
	else if (strcmp(sophieu, root->data.sophieu)>0)
		root->right = NNDPL(root->right, sophieu);
	else {
		//Tim thay phieu xuat
		if (root->left && root->right) {
			/*Doi vitri voi node lon nhat ben trai cay*/
			temp = FindMaxPL(root->left);
			CopyDataPL(root, *temp);
			root->left = NNDPL(root->left, root->data.sophieu);
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

void TreePL::DeletePL() {
	NodePL* find_sophieu;

	find_sophieu = SearchPL();
	NodePL *ERR = NNDPL(this->root, find_sophieu->data.sophieu);
	if(ERR)
		cout << "Phieu linh da duoc xoa!" << endl;
	else
		cout << "Khong tim thay phieu linh nay!";
}

void TreePL::ArrayPL(NodePL *root, PhieuLinh *dspl){
	stack<NodePL*> stack;
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
		dspl[i++] = root->data;
		root = root->right;
	}
}

NodePL *TreePL::CheckFKPL_maKCN(NodePL *root, char* makhoacn){
	NodePL *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(makhoacn, root->data.maKCN))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = CheckFKPL_maKCN(root->left, makhoacn);
			if (temp)
				return temp;
			else return(CheckFKPL_maKCN(root->right, makhoacn));
		}
	}
	return NULL;
}

NodePL *TreePL::CheckFKPL_maNV(NodePL *root, char* manv){
	NodePL *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(manv, root->data.maNV))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = CheckFKPL_maNV(root->left, manv);
			if (temp)
				return temp;
			else return(CheckFKPL_maNV(root->right, manv));
		}
	}
	return NULL;
}
