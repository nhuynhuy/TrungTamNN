#pragma once
#include "linhTinh.h"
//==================doc file ds_cl========
void doc_file_dscl(DSCL& ds_cl)
{
	ifstream filein;
	filein.open("DSCL.txt", ios_base :: in);
	while (filein.eof() != true)
	{
		ds_cl.ds[ds_cl.sl] = new CL;
		getline(filein, ds_cl.ds[ds_cl.sl]->macaplop, ',');
		getline(filein, ds_cl.ds[ds_cl.sl]->tencaplop, ',');
		getline(filein, ds_cl.ds[ds_cl.sl]->sotiethoc, ',');
		filein >> ds_cl.ds[ds_cl.sl]->hocphi;
		filein.ignore();
		ds_cl.ds[ds_cl.sl]->kt;
		filein.ignore();
		ds_cl.sl++;
	}
	filein.close();
}

void ghi_file_DSCL(ofstream& fileout, DSCL &ds_cl)
{
	CL* sl = ds_cl.ds[ds_cl.sl - 1];
	fileout.open("DSCL.txt", ios_base::app);
	fileout << endl;
	fileout << sl->macaplop << "," << sl->tencaplop << "," << sl->sotiethoc << "," << sl->hocphi << ",";
	fileout.close();
}
//==============================Quan ly lop hoc==========================
void doc_file_lop_hoc(DSLH &ds_lh)
{ 
	LH lh;
	ifstream filein;
	filein.open("DSLH.txt", ios_base::in);
	while (filein.eof() != true)
	{
		//filein.ignore();
		getline(filein,lh.malop, ',');
		getline(filein, lh.phonghoc, ',');
		filein >> lh.trangthai;
		filein.ignore();
		filein.ignore();
		LH* p = KhoiTaoNode(lh);
		them_vao_cuoi(ds_lh, p);
		//filein.ignore();
		ds_lh.sl++;
		//cout << ds_lh.sl;
		//system("pause");
	}
	filein.close();
}
void ghi_file_lop_hoc(ofstream &fileout,DSLH &ds_lh)
{
	LH* lh;
	fileout.open("DSLH.txt", ios :: out | ios::trunc);
	for (LH* k = ds_lh.phead; k != NULL; k = k->pnext)
	{
		
			fileout << k->malop << "," << k->phonghoc << "," << k->trangthai << ",";
			//cout << k->malop << "," << k->trangthai <;< "\n"
			if (k->pnext != NULL)
			{
				fileout << endl;
			}
		/*
		else
		{
			continue;
		}*/
		//cout << k->malop << "," << k->trangthai << "," << endl;
	}
	fileout.close();
}
//=====================quan ly hoc vien=========================
void doc_file_hv(DSHV& ds_hv)
{
	ifstream filein;
	filein.open("DSHV.txt", ios_base::in);
	while (filein.eof() != true)
	{
		HocVien* x = khoi_tao_node_hoc_vien();
		getline(filein, x->mahocvien, ',');
		//filein.ignore();
		getline(filein, x->ho, ',');
		getline(filein, x->ten, ',');
		getline(filein, x->phai, '\n');
		them_1_hv(ds_hv.TREE, x);
		ds_hv.sl++;
	}
	filein.close();
}
void ghi_file_hV (ofstream& fileout, tree t)
{
	
	if (t != NULL)
	{
		ghi_file_hV(fileout,t->pleft);
		fileout << t->mahocvien << "," << t->ho << "," << t->ten << "," << t->phai << ",";
		fileout << endl;
		ghi_file_hV(fileout, t->pright);
	}
}
void ghi_file_hoc_vien(DSHV& ds_hv)
{
	ofstream fileout;
	fileout.open("DSHV.txt", ios::out | ios::trunc);
	ghi_file_hV(fileout, ds_hv.TREE);
	fileout.close();
}


//void ghi_file_hV(ofstream& fileout, tree t)
//{
//
//	if (t != NULL)
//	{
//		ghi_file_hV(fileout, t->pleft);
//		fileout << t->mahocvien;
//		for(DIEM *k = t->danh_sach_diem.phead; k != NULL; k = k->pnext)
//		{
//			fileout << t->pointer_diem->diem_so << ",";
//		}
//		fileout << endl;
//		ghi_file_hV(fileout, t->pright);
//	}
//}