#pragma once
#include"CTDL.h"
#include "docGhiFile.h"
//=================QUAN LY CAP LOP=================
void them_cap_lop(DSCL& ds_cl);
string tao_ma_cl(DSCL ds_cl);
int kt_trung_cl(string a, DSCL ds_cl);
int kt_ma_cl(string a, DSCL ds_cl);
void xuat_ds_cap_lop(DSCL ds_cl);
void xoa_cap_lop(DSCL ds_cl);
void hieu_chinh_cl(DSCL ds_cl);
//=================QUAN LY HOV VIEN================
//HocVien* khoi_tao_node_hoc_vien();
//void nhap_hoc_vien(DSHV ds_hv);
//void them_1_hv(tree t, HocVien* p);
int tao_ma_hv(tree t);
bool kt_ma_hv_trung(tree t, int ma);
//void xoa_hoc_vien(DSHV& ds_hv);
//void hoan_vi_2_hv(HocVien* a, HocVien* b);
//void xoa_1_hv(tree &t, int ma);
//void node_the_mang(tree& t, HocVien*& x);
void hieu_chinh_hv(DSHV& ds_hv);
void hieu_chinh_1_hv(tree t, int ma);
//=======================Diem============================
DIEM* khoi_tao_node_diem();
HocVien* kt_ma_hv(tree t, int ma);
//================them cap lop======================================
void them_cap_lop(DSCL& ds_cl)
{
	CL* p = new CL;
	//p->macaplop = tao_ma_cl(ds_cl);
	cout << "Nhap ma cap lop: ";
	cin.ignore();
	getline(cin, p->macaplop);
	cout << "Nhap ten cap lop: ";
	getline(cin, p->tencaplop);
	cout << "Nhap so tiet hoc: ";
	cin >> p->sotiethoc;
	cout << "Nhap hoc phi : ";
	cin >> p->hocphi;
	//=============chuan hoa chu=========
	chuan_hoa_chu(p->macaplop);
	chuan_hoa_chu(p->tencaplop);
	ds_cl.ds[ds_cl.sl] = p;
	ds_cl.sl++;

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
void xoa_cap_lop(DSCL ds_cl)
{
	string a;
	cout << "Nhap ma cap lop: ";
	cin >> a;	chuan_hoa_chu(a);
	int cl = kt_ma_cl(a, ds_cl);

	if (cl < 0) {
		cout << "Vat tu khong ton tai" << endl;
		system("pause");
	}
	for (int i = 0; i < ds_cl.sl - 1; i++)
	{
		ds_cl.ds[i]->macaplop = ds_cl.ds[i + 1]->macaplop;
		ds_cl.ds[i]->tencaplop = ds_cl.ds[i + 1]->tencaplop;
		ds_cl.ds[i]->sotiethoc = ds_cl.ds[i + 1]->sotiethoc;
		ds_cl.ds[i]->hocphi = ds_cl.ds[i + 1]->hocphi;
	}
	CL* tam = ds_cl.ds[ds_cl.sl - 1];
	ds_cl.sl--;
	cout << "Da xoa thanh cong";
	system("pause");
}
int kt_ma_cl(string a, DSCL ds_cl)
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
//=========================================hieu chinh cap lop==============================================
void hieu_chinh_cl(DSCL ds_cl)
{
	string a;
	cout << "Nhap ma cap lop can hieu chinh: " << endl;
	cin >> a;
	//=====kiem tra========================
	int cl = kt_trung_cl(a, ds_cl);
	if (cl < 0)
	{
		cout << "Ma khong ton tai." << endl;
		system("pause");
	}
	else
	{
		cout << "Nhap ten cap lop: " << endl;
		getline(cin, ds_cl.ds[cl]->tencaplop);
		cout << "Nhap so tiet hoc: " << endl;
		getline(cin, ds_cl.ds[cl]->sotiethoc);
		cout << "Nhap hoc phi: " << endl;
		cin >> ds_cl.ds[cl]->hocphi;
		cout << "Da thay doi cap lop. " << endl;
		system("pause");
	}

}
//==========================================Them lop hoc===========================
LH* KhoiTaoNode(LH lh)
{
	LH* p = new LH;
	if (p == NULL)
	{
		cout << "\n khong du bo nho";
		return NULL;
	}
	p->malop = lh.malop;
	p->trangthai = lh.trangthai;
	p->pnext = NULL;
	return p;
}
void them_vao_cuoi(DSLH& ds_lh, LH* p)
{
	if (ds_lh.phead == NULL)
	{
		ds_lh.phead = p;
	}
	else
	{
		for (LH* k = ds_lh.phead; ;k = k->pnext)
		{
			if (k->pnext == NULL)
			{
				k->pnext = p;
				break;
			}
		}
	}
}
void them_lop_hoc(LH& lh, DSLH &ds_lh)
{
	cout << "\nNhap ma lop hoc can them: ";
	cin >> lh.malop;
	cout << "\nNhap trang thai lop hoc (0: lop chuan bi mo, 1: lop dang hoc, 2: lop da hoan tat): ";
	cin >> lh.trangthai;
	 
	LH* p = KhoiTaoNode(lh);
	them_vao_cuoi(ds_lh, p);
}
void xuat_lop_hoc(DSLH ds_lh)
{
	for (LH *k = ds_lh.phead; k != NULL; k = k->pnext)
	{
		cout << "Ma lop: " << k->malop << endl;
		cout << "Trang thai: " << k->trangthai << endl;
		cout << "aaaaaa";
	}
}
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
}

int tao_ma_hv(tree t)
{
	int ma;
	do
	{
		ma = rand() % (999 - 100 + 1) + 100;

	} while (kt_ma_hv_trung(t,ma)==true);
	return ma;
}
bool kt_ma_hv_trung(tree t, int ma)
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
void xoa_1_hoc_vien(tree &t, int data)
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
	int data;
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
	int a;
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
void hieu_chinh_1_hv(tree t, int ma)
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
//============================Nhap diem hoc vien =============================
void nhap_diem(DSHV& ds_hv)
{
	int a;
	cout << "Nhap ma sinh vien can nhap diem"; cin >> a;
	HocVien* tam = kt_ma_hv(ds_hv.TREE, a);
	if (tam == NULL)
	{
		cout << "Ma hoc vien khong ton tai" << endl;

	}
	else
	{
		DIEM* p = khoi_tao_node_diem();
		DIEM dn;
		cout << "Nhap ki nang can nhap diem: ";
		cout << "0. Nghe " << endl;
		cout << "1. Noi " << endl;
		cout << "2. Doc " << endl;
		cout << "3. Viet" << endl;
		cout << "Ki nang: ";
		int x; cin >> x;
		bool ktd = true;
		switch (x)
		{
		case 0:
		{
			cout << "Nhap diem nghe: ";
			cin >> dn.kn_nghe;
		}
		case 1:
		{
			cout << "Nhap diem noi: ";
			cin >> dn.kn_noi;
		}
		case 2:
		{
			cout << "Nhap diem doc: ";
			cin >> dn.kn_doc;
		}
		case 3:
		{
			cout << "Nhap diem viet: ";
			cin >> dn.kn_viet;
		}
		default:
			break;
		}


	}
}
DIEM * khoi_tao_node_diem()
{
	DIEM* p = new DIEM;
	p->pnext = NULL;
	return p;
}
HocVien* kt_ma_hv(tree t, int ma)
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
			kt_ma_hv(t->pleft,ma);
		}
	}
	else
	{
		return NULL;
	}
}
//======================================
void menu()
{
	//=====khia boa bien ==
	DSCL ds_cl;
	DSHV ds_hv;
	DSLH ds_lh;
	LH lh;
	bool kt = true;

	//=====load file=====
	doc_file_dscl(ds_cl);
	doc_file_hv(ds_hv);
	//==============
	while (kt)
	{
		//=================
		
		//===============
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
		cout << "=========== Quan ly diem ==============" << endl;
		cout << "9. Nhap diem hoc vien. " << endl;
		cout << "=========== Quan ly lop hoc ==============" << endl;
		cout << "10. Them lop hoc. " << endl;
		cout << "11. Xuat danh sach lop hoc. " << endl;

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
		case 10:
		{
			them_lop_hoc(lh, ds_lh);
			system("pause");
			break;
		}
		case 12:
		{
			xuat_lop_hoc(ds_lh);
			system("pause");
			break;
		}
		case 0:
		{
			kt = false;
			break;
		}

		}

	}
}
	//================Them cap lop==========
