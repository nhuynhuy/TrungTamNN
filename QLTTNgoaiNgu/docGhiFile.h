#pragma once
#include "linhTinh.h"
//==================doc file ds_cl========
void doc_file_dscl(DSCL& ds_cl)
{
	ifstream filein;
	filein.open("QLCL.txt", ios_base :: in);
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
		//getline(filein, x->ho, '\n') ;
		them_1_hv(ds_hv.TREE, x);
		ds_hv.sl++;
	}
	filein.close();
}