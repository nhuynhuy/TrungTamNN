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
void xoa_nhan_vien(DSHV& ds_hv);
void hoan_vi_2_hv(HocVien* a, HocVien* b);
void xoa_1_nv(tree t, int ma);
void node_the_mang(tree& t, HocVien*& x);
void hieu_chinh_hv(DSHV& ds_hv);
void hieu_chinh_1_hv(tree t, int ma);
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
//=========xoa cap lop=====================================================
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
//===============hieu chinh cap lop==============================================
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
//==============Nhap nhan vien==============================================

void nhap_hoc_vien(DSHV &ds_hv)
{
	HocVien *p = khoi_tao_node_hoc_vien();
	cin.ignore();
	cout << "Nhap ho: " << endl; getline(cin, p->ho);
	cout << "Nhap ten: " << endl; getline(cin, p->ten);
	cout << "Nhap phai: " << endl; getline(cin, p->phai);
	p->mahocvien = tao_ma_hv(ds_hv.TREE);
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
//========================In danh sach hoc vien===================
void in_ds_hoc_vien(tree t)
{
	if (t!=NULL)
	{
		in_ds_hoc_vien(t->pleft);
		cout << "=======Hoc Vien==========" << endl;
		cout << t->mahocvien << endl;
		cout << t->ho << endl;
		cout << t->ten << endl;
		cout << t->phai << endl;
		in_ds_hoc_vien(t->pright);
	}
	
}
//===============xoa nhan vien============================================
void xoa_nhan_vien(DSHV &ds_hv)
{
	int a;
	cout << "Nhap ma hoc vien: "; cin >> a;
	bool kt = kt_ma_hv_trung(ds_hv.TREE, a);
	if (kt == true)
	{
		xoa_1_nv(ds_hv.TREE, a);
		ds_hv.sl--;
		cout << "Da xoa thanh cong" << endl;
		system("pause");
	}
	else
	{
		cout << "Ma nhan vie khong ton tai. ";
	}
	system("pause");

}
void xoa_1_nv(tree t, int ma)
{
	if (t != NULL)
	{
		if (t->mahocvien == ma)
		{
			HocVien* x = t; // x se luu node can giai phong
			if (t->pleft == NULL)
			{
				t = t->pright;
			}
			else if (t->pright == NULL)
			{
				t = t->pleft;
			}
			else if (t->pleft != NULL && t->pright != NULL);
			{
				//trai cung cay con phai
				node_the_mang(t->pright, x);
			}
			delete x;
		}
	}
	else if (t->mahocvien < ma)
	{
		xoa_1_nv(t->pright, ma);
	}
	else if (t->mahocvien > ma)
	{
		xoa_1_nv(t->pleft, ma);
	}

}
void hoan_vi_2_hv(HocVien *a, HocVien *b)
{
	HocVien* tam = new HocVien;
	tam->mahocvien = a->mahocvien;
	tam->ho = a->ho;
	tam->ten = a->ten;
	tam->phai = a->phai;
	tam->DSDiem = a->DSDiem;
	//===================
	a->mahocvien = b->mahocvien;
	a->ho = b->ho;
	a->ten = b->ten;
	a->phai = b->phai;
	a->DSDiem = b->DSDiem;
	//==========
	b->mahocvien = tam->mahocvien;
	b->ho = tam->ho;
	b->ten = tam->ten;
	b->phai = tam->phai;
	b->DSDiem = tam->DSDiem;
	delete tam;
}
void node_the_mang(tree &t, HocVien *&x)
{
	if (t->pleft != NULL)
	{
		node_the_mang(t->pleft,x);
	}
	else // trai cungf
	{
		hoan_vi_2_hv(t, x);
		x = t; 
		t = t->pright;
	}
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
			cout << "Nhap ma: "; getline(cin, t->ho);
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
//============================DOC GHI FILE NHAN VIEN =============================

//======================================
void menu()
{

	//=====khia boa bien ==
	DSCL ds_cl;
	DSHV ds_hv;
	bool kt = true;
	//=====load file=====
	doc_file_dscl(ds_cl);
	doc_file_hv(ds_hv);
	//==============
	while (kt)
	{
		cout << "1. Them cap lop. " << endl;
		cout << "2. Xuat danh sach cap lop. " << endl;
		cout << "3. Xoa cap lop. " << endl;
		cout << "4. Hieu chinh cap lop. " << endl;
		cout << "5. Nhap hoc vien. " << endl;
		cout << "6. In danh sach hoc vien. " << endl;
		cout << "7. Xoa hoc vien. " << endl;
		cout << "8. Hieu chinh thong tin hoc vien. " << endl;
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
			xoa_nhan_vien(ds_hv);
			system("pause");
			break;
		}
		case 8:
		{
			hieu_chinh_hv(ds_hv);
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
