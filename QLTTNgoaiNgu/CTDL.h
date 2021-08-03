#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;

//============quan ly diem=========
struct Diem
{
	string ma_HV;
	int kn_nghe;
	int kn_noi;
	int kn_doc;
	int kn_viet;//nghe noi doc viet  1 2 3 4

	Diem* pnext;
};
typedef struct Diem DIEM;
struct DSDiem
{
	DIEM* phead = NULL;
	int sl = 0;
};
typedef struct DSDiem DSD;

//==========Quan ly hoc vien============
struct HocVien
{
	//data
	int mahocvien;
	string ho;
	string ten;
	string phai;
	//*qllh
	DIEM DSDiem;
	//pointer
	HocVien* pleft;
	HocVien* pright;
};
typedef struct HocVien* tree;

struct DSHocVien
{
	tree TREE = NULL;
	int sl = 0;
};
typedef struct DSHocVien DSHV;
//==========Quan ly lop hoc============
struct LopHoc
{
	//data
	string malop;
	char trangthai; //0: lop chuan bi mo, 1: lop dang hoc, 2: lop da hoan thanh)
	//*qllh
	tree DSHocVien;
	//pointer
	LopHoc *pnext;
};
typedef struct LopHoc LH;
struct DSLopHoc
{
	LH* phead = NULL;
	int sl = 0;
};
typedef struct DSLopHoc DSLH;

//==========Quan ly cap lop==========
struct CapLop
{
	string macaplop;
	string tencaplop;
	string sotiethoc;
	double hocphi;
	bool kt; //true: da ton tai, false: chua ton tai
	LH DSLopHoc;
};
typedef struct CapLop CL;

struct dsCapLop
{
	CL* ds[100];
	int sl = 0;

};
typedef struct dsCapLop DSCL;
