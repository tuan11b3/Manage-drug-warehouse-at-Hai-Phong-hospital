#include"NVKiemKe.h"


void TreeNVKK::CreateNVKK(){
	char  sophieu[10];
	char manv[10];
	ThoiGian ngayKiemKe;

	ngayKiemKe.ngay = 5;
	ngayKiemKe.thang = 4;
	ngayKiemKe.nam = 2023;

	NodeNVKK* parent = NULL;

	while (true) {
		//cin.ignore();
		cout << "Nhap so phieu(enter de thoat): ";
		cin.getline(sophieu, 10);
		if (sophieu[0] == NULL) break;
		if(strlen(sophieu) != 9){
			cout<<"So phieu phai co 9 ki tu!";
			cout<<"---Nhap Lai---";
			continue;
		}
		if(CoincideSoPhieuNVKK(this->root, sophieu)){
			cout<<"So phieu da ton tai!";
			cout<<"---Nhap Lai---";
			continue;
		}
		cout << "Nhap manv: ";
		cin.getline(manv, 10);
		/*stt = soluong + 1;	// Tang so luong record
		soluong += 1;*/

//		phieunhap_new = new PhieuXuat(sophieu, manv, makhoacn, ngayxuat, tenkhont, tenkhoxt);
		NVKiemKe nvkk_new(sophieu, manv, ngayKiemKe);
		
		this->root = InsertNVKK(this->root, parent, nvkk_new);
	}
}

int TreeNVKK::Height(NodeNVKK *root){
	if (!root)
		return -1;
	else
		return root->height;
}

NodeNVKK *TreeNVKK::SingleRotateLeft(NodeNVKK *X){
	NodeNVKK* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodeNVKK *TreeNVKK::SingleRotateRight(NodeNVKK *X){
	NodeNVKK* W = X->right;
	X->right = W->left;
	W->left = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), X->height) + 1;
	return W; /*New root*/
}

NodeNVKK *TreeNVKK::DoubleRotatewithLeft(NodeNVKK* Z){
	Z->left = SingleRotateRight(Z->left);
	return SingleRotateLeft(Z);
}

NodeNVKK *TreeNVKK::DoubleRotatewithRight(NodeNVKK* Z){
	Z->right = SingleRotateLeft(Z->right);
	return SingleRotateRight(Z);
}

bool TreeNVKK::CoincideSoPhieuNVKK(NodeNVKK *root, char *sophieu){
	if(root==NULL)
    {
        return false;
    }
    else if(strcmp(sophieu, root->data.sophieu)==0)
        return true;
    else if(strcmp(sophieu, root->data.sophieu)<0)
    {
        return CoincideSoPhieuNVKK(root->left, sophieu);
    }
    else if(strcmp(sophieu, root->data.sophieu)>0){
        return CoincideSoPhieuNVKK(root->right,sophieu);
    }
}

NodeNVKK* TreeNVKK::InsertNVKK(NodeNVKK *root, NodeNVKK *parent, NVKiemKe data){
	// TrHop 1: root == NULL
	if (!root) {
		root = new NodeNVKK(data);
		if (!root) {
			cout << "Loi bo nho"; return NULL;
		}
		else{
			root->left = root->right = NULL;
		}
	}

	else if (strcmp(data.sophieu, root->data.sophieu) < 0) {
		root->left = InsertNVKK(root->left, root, data);
		if ((Height(root->left) - Height(root->right)) == 2) {
			if (strcmp(data.sophieu, root->left->data.sophieu) < 0)
				root = SingleRotateLeft(root);
			else root = DoubleRotatewithLeft(root);
		}
	}
	
	else if (strcmp(data.sophieu, root->data.sophieu) > 0) {
		root->right = InsertNVKK(root->right, root, data);
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

void TreeNVKK::PrintNVKK( NodeNVKK* root) {
	// Inorder Traversal LDR
	if (root) {
		PrintNVKK(root->left);
		cout << "So phieu" << root->data.sophieu << endl;
		cout << "Ma nv: " << root->data.manv << endl;
		cout << "Ngay kiem ke: " << root->data.ngayKiemKe.ngay <<" " << root->data.ngayKiemKe.thang << " " << root->data.ngayKiemKe.nam<< endl;
		cout << endl<<endl;
		PrintNVKK(root->right);

	}
}

void TreeNVKK::ReadFileNVKK() {
	string data;
	ifstream fin("nvkiemke.txt");
	this->root = NULL;

	if (!fin) {
//		cout <<"Khong tim thay file";
		return ;
	}
	getline(fin, data);
	if (data.size() == 0) 
		cout << "Khong co du lieu duoc luu!";
	else{
		int soluong = atoi(data.c_str());	// Gan so luong records trong file
		while (!fin.eof()) {	
			NVKiemKe nvkiemke;	// Bien tam luu du lieu tu ban phim
	
			getline(fin, data);
			if (data.size() == 0) break;
			strcpy(nvkiemke.sophieu, data.c_str());
			getline(fin, data);		strcpy(nvkiemke.manv,data.c_str());
			
			getline(fin, data);		char* cstr = new char[data.length() + 1]; strcpy(cstr, data.c_str());
			nvkiemke.ngayKiemKe.ngay = atoi(strtok(cstr, " "));
			nvkiemke.ngayKiemKe.thang = atoi(strtok(NULL, " "));
			nvkiemke.ngayKiemKe.nam = atoi(strtok(NULL, " "));
	
			this->root = InsertNVKK(this->root, NULL, nvkiemke);
		}
	
//		PrintNVKK(this->root);
	}		// Ko dung reference dc vi root coThe NULL
}

void TreeNVKK::DataSave(ofstream &fout, NVKiemKe data) {
	/* thuc hien ghi du lieu vao file */
	fout << data.sophieu << endl;
	fout << data.manv << endl;
	fout << data.ngayKiemKe.ngay << ' ' << data.ngayKiemKe.thang << ' ' << data.ngayKiemKe.nam << endl;
}

int TreeNVKK::SizeOfNVKK(NodeNVKK *root){
	/* Tim so luong phieu xuat trong cay */
	if(root == NULL)
		return 0;
	else return(SizeOfNVKK(root->left) + 1 + SizeOfNVKK(root->right));
}

void TreeNVKK::SaveFileNVKK(){
		if (this->root) {
		stack<NodeNVKK*> stack;
		ofstream fout("nvkiemke.txt", ios::out);
		int soluong1 = SizeOfNVKK(this->root);
		
		fout << soluong1 << endl;
		
		NodeNVKK *root = this->root;
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

NodeNVKK* TreeNVKK::FindNodeNVKK(NodeNVKK* root, const  char *tukhoa) {
	NodeNVKK *temp;
	// Tr hop, cay rong. return NULL
	if (root == NULL)
		return NULL;
	else {
		//kiem tra neu tim thay o day
		if (!strcmp(tukhoa, root->data.sophieu))
			return root;
		else {
			// Nguoc lai dequy xuong cay con
			temp = FindNodeNVKK(root->left, tukhoa);
			if (temp)
				return temp;
			else return(FindNodeNVKK(root->right, tukhoa));
		}
	}
	return NULL;
}

NodeNVKK *TreeNVKK::SearchNVKK(){
	/* Tim Kiem phieu xuat, tra ve phieu xuat tim dc */
	char m_sophieu[10];
	NodeNVKK* NVKKTimDc;

	cout << "\nNhap ma so phieu can tim: ";
	cin.getline(m_sophieu, 10);

	NVKKTimDc = FindNodeNVKK(this->root, m_sophieu);
	if (NVKKTimDc) {
		cout << "So phieu" << NVKKTimDc->data.sophieu << endl;
		cout << "Ma nv: " << NVKKTimDc->data.manv << endl;

		cout << endl << endl;
	}
	else cout << "Khong co so phieu nay!";
	return NVKKTimDc;
}

NodeNVKK *TreeNVKK::FindMaxNVKK(NodeNVKK *root){
	if(root == NULL)
		return NULL;
	else if(root->right == NULL)
		return root;
	else return FindMaxNVKK(root->right);
}

void TreeNVKK::CopyDataNVKK(NodeNVKK* dest, const NodeNVKK res ){
	strcpy(dest->data.sophieu, res.data.sophieu);
	strcpy(dest->data.manv, res.data.manv);
	dest->data.ngayKiemKe = res.data.ngayKiemKe;
}

NodeNVKK* TreeNVKK::NNDNVKK(NodeNVKK* root, char* sophieu) {
	NodeNVKK* temp;
	if (root == NULL) cout<<"";
	else if (strcmp(sophieu, root->data.sophieu)<0)
		root->left = NNDNVKK(root->left, sophieu);
	else if (strcmp(sophieu, root->data.sophieu)>0)
		root->right = NNDNVKK(root->right, sophieu);
	else {
		//Tim thay phieu xuat
		if (root->left && root->right) {
			/*Doi vitri voi node lon nhat ben trai cay*/
			temp = FindMaxNVKK(root->left);
			CopyDataNVKK(root, *temp);
			root->left = NNDNVKK(root->left, root->data.sophieu);
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

void TreeNVKK::DeleteNVKK() {
	NodeNVKK* find_sophieu;

	find_sophieu = SearchNVKK();
	NodeNVKK *ERR = NNDNVKK(this->root, find_sophieu->data.sophieu);
	if(ERR)
		cout << "Phieu xuat da duoc xoa!" << endl;
	else
		cout << "Khong tim thay so phieu nay!";
}

void TreeNVKK::ArrayNVKK(NodeNVKK *root, NVKiemKe *dsnvkk){
	stack<NodeNVKK*> stack;
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
		dsnvkk[i++] = root->data;
		root = root->right;
	}
}



