#pragma once
#include"CTDL.h"
#include "docGhiFile.h"
//=================QUAN LY CAP LOP=================
void them_cap_lop(DSCL& ds_cl);
string tao_ma_cl(DSCL ds_cl);
int kt_trung_cl(string a, DSCL ds_cl);
int kt_ma_cl(string a, DSCL ds_cl);
void xuat_ds_cap_lop(DSCL ds_cl);
//void xoa_cap_lop(DSCL ds_cl);
void hieu_chinh_cl(DSCL ds_cl);
//=================QUAN LY HOV VIEN================
//HocVien* khoi_tao_node_hoc_vien();
//void nhap_hoc_vien(DSHV ds_hv);
//void them_1_hv(tree t, HocVien* p);
string tao_ma_hv(tree t);
bool kt_ma_hv_trung(tree t, string ma);
//void xoa_hoc_vien(DSHV& ds_hv);
//void hoan_vi_2_hv(HocVien* a, HocVien* b);
//void xoa_1_hv(tree &t, int ma);
//void node_the_mang(tree& t, HocVien*& x);
void hieu_chinh_hv(DSHV& ds_hv);
void hieu_chinh_1_hv(tree t, string ma);
//=======================Diem============================
//DIEM* khoi_tao_node_diem();
//HocVien* kt_ma_hv(tree t, string ma);
void nhap_diem_1_hoc_vien(tree t, string ma);

//================================QUAN LY CAP LOP==================================
//================them cap lop======================================
int kt_trung_cl(string a, DSCL ds_cl)
{
	for (int i = 0; i < ds_cl.sl; i++)
	{
		if (ds_cl.ds[i]->macaplop == a)
		{
			return i;
		}
	}
	return -1;
}
bool kt_trung_cap_lop(string a, DSCL ds_cl)
{
	for (int i = 0; i < ds_cl.sl; i++)
	{
		if (ds_cl.ds[i]->macaplop == a)
		{
			return true;
		}
	}
	return false;
}
//======duyet cap lop trung thi xoa========
void xoa_cap_lop_trung(DSCL &ds_cl)
{

	for (int i = 0; i < ds_cl.sl-1; i++)
	{
		for (int j = i + 1; j < ds_cl.sl ; i++)
		{
			if(ds_cl.ds[i] == ds_cl.ds[j])
			{
				ds_cl.ds[j]->macaplop = ds_cl.ds[j + 1]->macaplop;
				ds_cl.ds[j]->tencaplop = ds_cl.ds[j + 1]->tencaplop;
				ds_cl.ds[j]->sotiethoc = ds_cl.ds[j + 1]->sotiethoc;
				ds_cl.ds[j]->hocphi = ds_cl.ds[j + 1]->hocphi;
				CL* tam = ds_cl.ds[ds_cl.sl - 1];
			}
		}
	}
}
//=================================
void them_cap_lop(DSCL& ds_cl)
{
	CL* p = new CL;
	string x;
	string y;
	//p->macaplop = tao_ma_cl(ds_cl);
	
	cin.ignore();
	bool ktt = true;
	while (ktt == true)
	{
		cout << "Nhap ma cap lop: ";
		cin >> x;
		bool kt = kt_trung_cap_lop(x, ds_cl);
		if (kt == true)
		{
			cout << "Cap lop da ton tai!" << endl;
			continue;
		}
		else {
			p->macaplop = x;
			cout << "Nhap ten cap lop: ";
			cin >> y;
			p->tencaplop = y;
			cout << "Nhap so tiet hoc: ";
			cin >> p->sotiethoc;
			cout << "Nhap hoc phi : ";
			cin >> p->hocphi;
			ds_cl.ds[ds_cl.sl] = p;
			ds_cl.sl++;
			break;
		}
	}
	
	//=============chuan hoa chu=========
	/*chuan_hoa_chu(p->macaplop);
	chuan_hoa_chu(p->tencaplop);*/
	int xac_nhan;
	cout << "Ban co muon ghi vao file khong ?" << endl;
	cout << "0: Khong          1: Co" << endl;
	cout << "Chon :";
	cin >> xac_nhan;
	if (xac_nhan == 1)
	{
		ofstream fileout;
		ghi_file_DSCL(fileout, ds_cl);
	}
	system("pause");
}
string tao_ma_cl(DSCL ds_cl)
{
	string a = "CL0000";
	do
	{
		for (int i = 2;i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;

		}
	} while (kt_trung_cl(a, ds_cl) >= 0);
	return a;
}

//=========xuat ds cap lop=============
void xuat_ds_cap_lop(DSCL ds_cl)
{
	
	for (int i = 0; i < ds_cl.sl; i++)
	{	
		cout << "=========CAP LOP " << i + 1 << "============" << endl;
		
		cout << "Ma cap lop: " << ds_cl.ds[i]->macaplop << endl;
	
		cout << "Ten cap lop: " << ds_cl.ds[i]->tencaplop << endl;
	
		cout << "So tiet hoc: " << ds_cl.ds[i]->sotiethoc << endl;
	
		cout << "Hoc phi: " << ds_cl.ds[i]->hocphi << endl;
	}
}
//===================================Xoa cap lop=====================================================
void xoa_1_cap_lop(DSCL& ds_cl)
{
	string a;
	cout << "Nhap ma cap lop: ";
	cin >> a;	//chuan_hoa_chu(a);
	int cl = kt_ma_cl(a, ds_cl);
	cout << ds_cl.sl;
	if (cl < 0) {
		cout << "Cap lop khong ton tai" << endl;
		system("pause");
	}
	cout << cl;
	for (int i = cl; i < ds_cl.sl - 1; i++)
	{

		ds_cl.ds[i]->macaplop = ds_cl.ds[i + 1]->macaplop;
		ds_cl.ds[i]->tencaplop = ds_cl.ds[i + 1]->tencaplop;
		ds_cl.ds[i]->sotiethoc = ds_cl.ds[i + 1]->sotiethoc;
		ds_cl.ds[i]->hocphi = ds_cl.ds[i + 1]->hocphi;
	}
	//ds_cl.ds[ds_cl.sl] = ds_cl.ds[ds_cl.sl - 1];
	//free(tam);
	ds_cl.sl--;
	cout << ds_cl.sl;
}
void xoa_cap_lop(DSCL& ds_cl)
{

	xoa_1_cap_lop(ds_cl);

	cout << "Da xoa thanh cong";
	system("pause");
}
//int kt_ma_cl(string a, DSCL ds_cl)== ben linhtinh.h==
//=========================================hieu chinh cap lop==============================================
void hieu_chinh_1_cap_lop(DSCL& ds_cl)
{
	string x;
	string y;
	//p->macaplop = tao_ma_cl(ds_cl);

	//cin.ignore();
	bool ktt = true;
	cout << "Nhap ma cap lop can hieu chinh: ";
	cin >> x;
	int cl = kt_ma_cl(x, ds_cl);
	while (ktt == true)
	{
		
		if (cl < 0 )
		{
			cout << "Cap lop khong ton tai!" << endl;
			continue;
		}
		else {

			cout << "\nNhap ten cap lop: " ;
			cin.ignore();
			getline(cin, ds_cl.ds[cl]->tencaplop);
			cout << "\nNhap so tiet hoc: " ;
			getline(cin, ds_cl.ds[cl]->sotiethoc);
			cout << "\nNhap hoc phi: " ;
			cin >> ds_cl.ds[cl]->hocphi;
			cout << "\nDa thay doi cap lop. " << endl;
			system("pause");
			break;
		}
	}
	int xac_nhan;
	cout << "Ban co muon ghi vao file khong ?" << endl;
	cout << "0: Khong          1: Co" << endl;
	cout << "Chon :";
	cin >> xac_nhan;
	if (xac_nhan == 1)
	{
		ofstream fileout;
		ghi_file_DSCL(fileout, ds_cl);
	}
}
void hieu_chinh_cl(DSCL ds_cl)
{
	hieu_chinh_1_cap_lop(ds_cl);
	//doc_file_dscl(ds_cl);

}

//================================QUAN LY LOP HOC============================
//==========================================Them lop hoc===========================

bool kt_ma_LH_trung(DSLH ds_lh, string ma) {
	for (LH* k = ds_lh.phead; k != NULL; k = k->pnext)
	{
		if (k->malop == ma)
		{
			return true;
		}
	}
	return false;
}

bool kt_trang_thai(DSLH ds_lh, int y)
{
	if (y != 0 && y != 1 && y != 2 && y != 3)
	{
		return false;
	}
	else {
		return true;
	}
}
void them_lop_hoc( DSLH& ds_lh, DSCL& ds_cl, LH &lh)
{
	
	string x;
	string t;
	int y;
	string z;
	cout << "\nNhap ma lop hoc can them: ";
	cin >> x;
	bool kt = kt_ma_LH_trung(ds_lh, x);
	if (kt == true)
	{
		cout << "Ma lop hoc da ton tai! " << endl;
		return;
	}
	else
	{
		lh.malop = x;
		cout << "Nhap so phong hoc: ";
		//cin.ignore();
		cin >> t;
		lh.phonghoc = t;
		cout << lh.phonghoc << t;
		bool ktt = true;
		while (ktt == true)
		{
			cout << "\nNhap trang thai lop hoc (0: lop chuan bi mo, 1: lop dang hoc, 2: lop da hoan tat): ";
			cin >> y;
			bool kt = kt_trang_thai(ds_lh, y);
			if (kt == false)
			{
				cout << "Khong hop le!" << endl;
				continue;
			}
			else {
				lh.trangthai = y;
				break;
			}
		}
		
		LH* p = KhoiTaoNode(lh);
		them_vao_cuoi(ds_lh, p);
		ds_lh.sl++;
		
	}
	
	
}
//==================================
void link_cl_lh(DSCL &ds_cl, LH& lh, DSLH& ds_lh)
{
	string a;
	cout << "Nhap ma cap lop can them lop hoc: ";
	cin >> a;	//chuan_hoa_chu(a);
	int cl = kt_ma_cl(a, ds_cl);

	if (cl < 0) {
		cout << "Cap lop khong ton tai" << endl;
		system("pause");
	}
	else
	{
		
		them_lop_hoc( ds_lh, ds_cl,lh);
		LH *p = KhoiTaoNode(lh);
		them_vao_cuoi(ds_cl.ds[cl]->DSlop_hoc, p);
		//ds_cl.ds[cl]->DSlop_hoc = ds_lh;
		ofstream fileout;
		CL macl;
		macl.macaplop = a;
		ghi_file_lop_hoc(fileout, ds_lh, macl);
	}
	system("pause");
}
//==================================In danh sach lop hoc==================================
void xuat_lop_hoc(DSLH ds_lh)
{
	if (ds_lh.phead == NULL)
	{
		cout << "Danh sach lop hoc rong.";
	}
	else 
	{
		for (LH* k = ds_lh.phead; k != NULL; k = k->pnext)
		{
			cout << "Ma lop: " << k->malop << endl;
			cout << "Phong hoc: " << k->phonghoc << endl;
			cout << "Trang thai: " << k->trangthai << endl;
		}
	}
}
//===============================Xoa lop hoc =======================================
void XoaDau(DSLH& ds_lh)
{
	if (ds_lh.phead == NULL)
	{
		return;
	}
	LH* p = ds_lh.phead;
	ds_lh.phead = ds_lh.phead->pnext;
	delete p;
}
void XoaCuoi(DSLH& ds_lh)
{
	if (ds_lh.phead == NULL)
	{
		return;
	}
	if (ds_lh.phead->pnext == NULL)
	{
		XoaDau(ds_lh);
		return;
	}
	for (LH* k = ds_lh.phead; k != NULL; k = k->pnext)
	{
		if (k->pnext == ds_lh.ptail)
		{
			delete ds_lh.ptail;
			k->pnext = NULL;
			ds_lh.ptail = k;
			return;
		}
	}
}
void xoa_1_lop_hoc(DSLH &ds_lh, string x)
{
	if (ds_lh.phead == NULL)
	{
		return;
	}
	if (ds_lh.phead->malop == x )
	{
		XoaDau(ds_lh);
		return;
	}
	if (ds_lh.ptail->malop == x)
	{
		XoaCuoi(ds_lh);
		return;
	}
	LH* g = new LH;
	for (LH* k = ds_lh.phead; k != NULL; k = k->pnext)
	{
		if (k->malop == x)
		{
			g->pnext = k->pnext;
			delete k;
			return;
		}
		g = k;
	}
}

void xoa_lop_hoc(DSLH &ds_lh)
{
	string x;
	cout << "Nhap ma lop can xoa: ";
	cin >> x;
	bool kt = kt_ma_LH_trung(ds_lh, x);
	//XoaCuoi(ds_lh);
	if (kt == true)
	{
		xoa_1_lop_hoc(ds_lh,x);
		ds_lh.sl--;
		cout << "\nda xoa thanh cong! ";
		system("pause");
	}
	else
	{
		cout << "ma lop hoc khong ton tai! ";
	}
	
}
//============================Hieu chinh thong tin lop hoc==================================

//=========================================QUAN LY HOC VIEN =================================================

//==========================================Nhap hoc vien==============================================
void nhap_hoc_vien(DSHV &ds_hv)
{
	HocVien *p = khoi_tao_node_hoc_vien();
	cin.ignore();
	cout << "Nhap ho: " << endl; getline(cin, p->ho);
	cout << "Nhap ten: " << endl; getline(cin, p->ten);
	cout << "Nhap phai: " << endl; getline(cin, p->phai);
	p->mahocvien = tao_ma_hv(ds_hv.TREE);
	cout << p->mahocvien;
	them_1_hv(ds_hv.TREE, p);
	ds_hv.sl++;
	ghi_file_hoc_vien(ds_hv);
}

string tao_ma_hv(tree t)
{
	string a = "HV0000";
	do
	{
		for ( int i = 2; i < a.length(); i++)
		{
			a[i] = rand() % (57 - 48 + 1) + 48;

		}

	} while (kt_ma_hv_trung(t,a)==true);
	return a;
}
bool kt_ma_hv_trung(tree t, string ma)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (t->mahocvien == ma)
		{
			return 1;
		}
		else if (t->mahocvien < ma)
		{
			kt_ma_hv_trung(t->pright, ma);

		}
		else
		{
			kt_ma_hv_trung(t->pleft, ma);
		}
	}
}
//====================================In danh sach hoc vien===========================
void in_ds_hoc_vien(tree t)
{

	if (t!=NULL)
	{
		in_ds_hoc_vien(t->pleft);
		cout << "=======Hoc Vien=========" << endl;
		cout <<"Ma hoc vien: "<< t->mahocvien << endl;
		cout <<"Ho: "<< t->ho << endl;
		cout <<"Ten: "<< t->ten << endl;
		cout <<"Phai: "<< t->phai << endl;
		in_ds_hoc_vien(t->pright);
	}
}
//===============================Xoa hoc vien============================================
void node_the_mang(HocVien *&x, HocVien *&y)
{
	if (y->pleft == NULL)
	{
		node_the_mang(x, y->pleft);
	}
	else
	{
		x->mahocvien = y->mahocvien;
		x->ho = y->ho;
		x->ten = y->ten;
		x->phai = y->phai;

		x = y;

		y = y->pright;
	}
}
void xoa_1_hoc_vien(tree &t, string data)
{
	
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (data > t->mahocvien)
		{
			xoa_1_hoc_vien(t->pright, data);

		}
		else if (data < t->mahocvien)
		{
			xoa_1_hoc_vien(t->pleft, data);
		}
		else
		{
			HocVien* x = t;
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if (t->pright == NULL)
			{
				t = t->pleft;
			}
			else
			{
				node_the_mang(x, t->pright);
			}
		}
	}

}
void xoa_hoc_vien(DSHocVien &ds_hv)
{
	string data;
	cout << "Nhap phan tu can xoa: ";
	cin >> data;
	bool kt = kt_ma_hv_trung(ds_hv.TREE, data);
	if (kt == true)
	{
		xoa_1_hoc_vien(ds_hv.TREE, data);
		ds_hv.sl--;
		cout << "Da xoa thanh cong" << endl;
		system("pause");
	}
	else
	{
		cout << "Ma hoc vien khong ton tai. ";
	}
	system("pause");
}
//==================Hieu chinh hoc vien =========================================
void hieu_chinh_hv(DSHV &ds_hv)
{
	string a;
	cout << "Nhap ma hoc vien can hieu chinh: "; cin >> a;
	bool kt = kt_ma_hv_trung(ds_hv.TREE, a);
	if (kt == true)
	{
		hieu_chinh_1_hv(ds_hv.TREE, a);
		cout << "Da hieu chinh thong tin cua nhan vien " << endl;
	}
	else {
		cout << "Ma khong ton tai. " << endl;
	}
	system("pause");
}
void hieu_chinh_1_hv(tree t, string ma)
{
	if (t != NULL)
	{
		if (t->mahocvien == ma)
		{
			cin.ignore();
			cout << "Nhap ho: "; getline(cin, t->ho);
			cout << "Nhap ten: "; getline(cin, t->ten);
			cout << "Nhap phai: "; getline(cin, t->phai);
					
		}

		else if (t->mahocvien > ma)
		{
			hieu_chinh_1_hv(t->pleft, ma);
		}
		else if (t->mahocvien < ma)
		{
			hieu_chinh_1_hv(t->pright, ma);
		}
	}
}
//===============================================
HocVien* kt_ma_hv(tree t, string ma)
{
	if (t != NULL)
	{
		if (t->mahocvien == ma)
		{
			return t;
		}
		else if (t->mahocvien < ma)
		{
			kt_ma_hv(t->pright, ma);
		}
		else if (t->mahocvien > ma);
		{
			kt_ma_hv(t->pleft, ma);
		}
	}
	else
	{
		return NULL;
	}
}

//============================QUAN LY DIEM======================================
//============================Nhap diem hoc vien =============================
void nhap_diem(DSHV& ds_hv, DSD &ds_diem)
{
	string a;
	cout << "Nhap ma hoc vien can nhap diem: "; cin >> a;
	bool tam = kt_ma_hv_trung(ds_hv.TREE, a);
	if (tam == false)
	{
		cout << "Ma hoc vien khong ton tai" << endl;

	}
	else
	{
		nhap_diem_1_hoc_vien(ds_hv.TREE, a);
	}
}
void nhap_diem_vao_dsd(DSD &ds_diem)
{
	DIEM diem;
	
	cout << "Nhap diem nghe (0) : ";  cin >> diem.diem_so;
	DIEM* diem_nghe = khoi_tao_node_diem(diem);
	them_vao_cuoi_diem(ds_diem, diem_nghe);
	
	DIEM diem1;
	cout << "Nhap diem noi (1) : "; cin >> diem1.diem_so;
	DIEM* diem_noi = khoi_tao_node_diem(diem1);
	them_vao_cuoi_diem(ds_diem, diem_noi);

	DIEM diem2;
	cout << "Nhap diem doc (2) : "; cin >> diem2.diem_so;
	DIEM* diem_doc = khoi_tao_node_diem(diem2);
	them_vao_cuoi_diem(ds_diem, diem_doc);

	DIEM diem3;
	cout << "Nhap diem viet (3) : "; cin >> diem3.diem_so;
	DIEM* diem_viet = khoi_tao_node_diem(diem3);
	them_vao_cuoi_diem(ds_diem, diem_viet);
}
void nhap_diem_1_hoc_vien( tree t, string ma)
{
	if (t != NULL)
	{
		if (t->mahocvien == ma)
		{
			
			DSD ds_diem;
			nhap_diem_vao_dsd(ds_diem);
			ds_diem.sl++;
			t->danh_sach_diem = ds_diem;
			
		}

		else if (t->mahocvien > ma)
		{
			nhap_diem_1_hoc_vien(t->pleft, ma);
		}
		else if (t->mahocvien < ma)
		{
			nhap_diem_1_hoc_vien(t->pright, ma);
		}
	}
}
void in_diem_1_hoc_vien(tree t, string ma)
{
	if (t != NULL)
	{
		if (t->mahocvien == ma)
		{

			cout << "Diem cua hoc vien " << ma << " gom nghe noi doc viet lan luot la: ";
			for (DIEM* k = t->danh_sach_diem.phead; k != NULL; k = k->pnext)
			{

				cout << " | ";
				//k->diem_so;
				cout << k->diem_so;
				
				break;

			}



		}

		else if (t->mahocvien > ma)
		{
			in_diem_1_hoc_vien(t->pleft, ma);
		}
		else if (t->mahocvien < ma)
		{
			in_diem_1_hoc_vien(t->pright, ma);
		}
	}
}
void in_diem(DSD ds_diem, DSHV ds_hv)
{
	string ma;
	cout << "Nhap ma hoc vien can in diem:  "; cin >> ma;
	bool tam = kt_ma_hv_trung(ds_hv.TREE, ma);
	if (tam == false)
	{
		cout << "Ma hoc vien khong ton tai! " << endl;

	}
	else
	{
		in_diem_1_hoc_vien(ds_hv.TREE, ma);
		
	}
}

//=======================IN DANH SACH LOP HOC THEO TUNG CAP LOP=========================
void in_ds_lophoc_theo_caplop(DSCL ds_cl)
{
	string a;
	cout << "Nhap ma cap lop can xuat thong tin lop hoc: ";
	cin >> a;	//chuan_hoa_chu(a);
	int cl = kt_ma_cl(a, ds_cl);

	if (cl < 0) {
		cout << "Cap lop khong ton tai" << endl;
		system("pause");
	}
	else
	{
		for (LH* k = ds_cl.ds[cl]->DSlop_hoc.phead; k != NULL; k = k->pnext)
		{
			cout << "==============lOP HOC------------" << endl;
			cout << "Ma lop: " << k->malop << endl;;
			cout << "Phong hoc: " << k->phonghoc << endl;
			cout << "Trang thai: " << k->trangthai << endl;
		}
	}
}
//======================================
void menu()
{
	
	//=====khia boa bien ==
	DSCL ds_cl;
	DSHV ds_hv;
	DSLH ds_lh;
	DSD ds_diem;
	DSD danh_sach_diem;
	DIEM diem;
	LH lh;
	bool kt = true;

	//=====load file=====
	doc_file_dscl(ds_cl);
	doc_file_hv(ds_hv);
	doc_file_lop_hoc(ds_lh,ds_cl);

	//=====================
	//xoa_cap_lop_trung(ds_cl);
	//==============
	while (kt)
	{
		//=================
		
		//===============
		system("cls");
		cout << "=========== Quan ly cap lop ==============" << endl;
		cout << "1. Them cap lop. " << endl;
		cout << "2. Xuat danh sach cap lop. " << endl;
		cout << "3. Xoa cap lop. " << endl;
		cout << "4. Hieu chinh cap lop. " << endl;

		cout << "=========== Quan ly hoc vien ==============" << endl;
		cout << "5. Nhap hoc vien. " << endl;
		cout << "6. In danh sach hoc vien. " << endl;
		cout << "7. Xoa hoc vien. " << endl;
		cout << "8. Hieu chinh thong tin hoc vien. " << endl;
		
		
		cout << "=========== Quan ly lop hoc ==============" << endl;
		cout << "9. Them lop hoc. " << endl;
		cout << "10. Xuat danh sach lop hoc. " << endl;
		cout << "11. Xoa lop hoc. " << endl;

		cout << "=========== Quan ly diem ==============" << endl;
		cout << "12. Nhap diem hoc vien. " << endl;
		cout << "13. In diem hoc vien. " << endl;

		cout << "14.In thong tin lop hoc theo tung cap lop" << endl;
		
		cout << "0. Thoat" << endl;
		int luachon;
		cout << "   Nhap lua chon : "; cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			if (ds_cl.sl == 100)
			{
				cout << "Them khong thanh cong ! data day" << endl;
				system("pause");
			}
			else
			{
				them_cap_lop(ds_cl);
			}
			
			break;
		}
		case 2:
		{
			xuat_ds_cap_lop(ds_cl);
			system("pause");
			break;
		}
		case 3:
		{
			if (ds_cl.sl == 0)
			{
				cout << "Xoa khong thanh cong ! data rong" << endl;
				system("pause");
			}
			else
			{
				xoa_cap_lop(ds_cl);
			}

			break;
		}
		case 4:
		{
			if (ds_cl.sl == 0)
			{
				cout << "Hieu chinh khong thanh cong ! data rong" << endl;
				system("pause");
			}
			else
			{
				hieu_chinh_cl(ds_cl);
			}

			break;
		}
		case 5:
		{
			nhap_hoc_vien(ds_hv);
			break;
		}
		case 6:
		{
			in_ds_hoc_vien(ds_hv.TREE);
			system("pause");
			break;
		}
		case 7:
		{
			xoa_hoc_vien(ds_hv);
			break;
		}
		case 8:
		{
			hieu_chinh_hv(ds_hv);
			system("pause");
			break;
		}
		case 9:
		{
			link_cl_lh(ds_cl, lh, ds_lh);
			//=======================
			
			//======================
			
			/*them_lop_hoc(lh, ds_lh);*/
			system("pause");
			break;
		}
		case 10:
		{
			xuat_lop_hoc(ds_lh);
			
			system("pause");
			break;
		}
		case 11:
		{
			xoa_lop_hoc(ds_lh);
			system("pause");
			break;
		}
		case 12:
		{
			nhap_diem(ds_hv,danh_sach_diem);
			system("pause");
			break;
		}
		case 13:
		{
			
			in_diem(danh_sach_diem ,ds_hv);
			system("pause");
			break;
		}
		case 14:
		{

			in_ds_lophoc_theo_caplop(ds_cl);
			system("pause");
			break;
		}
		default:
		{
			kt = false;
			break;
		}

		}

	}
}
	//================Them cap lop==========
