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
void doc_file_lop_hoc(DSLH &ds_lh)
{ 
	LH lh;
	ifstream filein;
	filein.open("DSLH.txt", ios_base::in);
	while (filein.eof() != true)
	{
		filein.ignore();
		getline(filein,lh.malop, ',');
		filein >> lh.trangthai;
		filein.ignore();
		LH* p = KhoiTaoNode(lh);
		them_vao_cuoi(ds_lh, p);
		ds_lh.sl++;
	}
	filein.close();
}
//void ghi_file_lop_hoc(ofstream &fileout,DSLH &ds_lh)
//{
//	fileout.open("DSLH.txt", ios_base::app);
//	for (LH* k = ds_lh.phead; k != NULL; k = k->pnext)
//	{
//		fileout << endl;
//		fileout << lh.malop << "," << lh.trangthai << ",";
//		
//	}
//	fileout.close();
//}
void doc_file_hv(DSHV& ds_hv)
{
	ifstream filein;
	filein.open("DSHV.txt", ios_base::in);
	while (filein.eof() != true)
	{
		HocVien* x = khoi_tao_node_hoc_vien();
		filein >> x->mahocvien;		
		filein.ignore();
		getline(filein, x->ho, ',');
		getline(filein, x->ten, ',');
		getline(filein, x->phai, '\n');
		them_1_hv(ds_hv.TREE, x);
		ds_hv.sl++;
	}
	filein.close();
}