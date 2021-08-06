#pragma once
#include "CTDL.h"
void chuan_hoa_chu(string a)
{
	//xu li khoang trang dau
	while (a[0] == ' ')
	{
		a.erase(a.begin() + 0);

	}
	while (a[a.length() - 1] == ' ')
	{
		a.erase(a.begin() + a.length() - 1);
	}
	//xoa khoang trang giua
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ' && a[i+1] == ' ')
		{
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	//chuan hoa ki tu
	if (a[0] >= 97 && a[0] <= 122)
	{
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			i++;
			if (a[i] >= 97 && a[i] <= 122)
			{
				a[i] -= 32;
			}
		}
		else
		{
			if (a[i] >= 65 && a[i] <= 90)
			{
				a[i] += 32;
			}
		}
	}

}
HocVien* khoi_tao_node_hoc_vien()
{
	HocVien* p = new HocVien;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}
void them_1_hv(tree &t, HocVien* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->mahocvien > t->mahocvien)
		{
			them_1_hv(t->pright, p);
		}
		else if (p->mahocvien < t->mahocvien)
		{
			them_1_hv(t->pleft, p);
		}
	}
}
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
		for (LH* k = ds_lh.phead; ; k = k->pnext)
		{
			if (k->pnext == NULL)
			{
				k->pnext = p;
				break;
			}
		}
	}
}
DIEM* khoi_tao_node_diem(DIEM diem)
{
	
	DIEM* p = new DIEM;
	if (p == NULL)
	{
		cout << "\n khong du bo nho";
		return NULL;
	}
	p->ki_nang = diem.ki_nang;
	p->diem_so = diem.diem_so;
	p->pnext = NULL;
	return p;
}
void them_vao_cuoi_diem(DSD& ds_diem, DIEM* p)
{
	if (ds_diem.phead == NULL)
	{
		ds_diem.phead = p;
	}
	else
	{
		for (DIEM* k = ds_diem.phead; ; k = k->pnext)
		{
			if (k->pnext == NULL)
			{
				k->pnext = p;
				break;
			}
		}
	}
}