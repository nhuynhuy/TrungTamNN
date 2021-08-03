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