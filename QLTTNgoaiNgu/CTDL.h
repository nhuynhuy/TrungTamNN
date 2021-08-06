#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <vector>
using namespace std;

//============quan ly diem=========
struct Diem
{
	//string mhv;
	int ki_nang;//nghe noi doc viet  1 2 3 4
	int diem_so;

	Diem* pnext;
};
typedef struct Diem DIEM;
struct DSDiem
{
	DIEM* phead = NULL;
	DIEM* ptail = NULL;
	int sl = 0;
};
typedef struct DSDiem DSD;

//==========Quan ly hoc vien============
struct HocVien
{
	//data
	string mahocvien;
	string ho;
	string ten;
	string phai;
	//*qldiem
	DIEM *pointer_diem;
	DSD danh_sach_diem;
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
	string phonghoc;
	int trangthai; //0: lop chuan bi mo, 1: lop dang hoc, 2: lop da hoan thanh)
	//*qllh
	tree *DSHocVien;
	//pointer
	LopHoc *pnext;
};
typedef struct LopHoc LH;
struct DSLopHoc
{
	//LopHoc *data;
	LH* phead = NULL;
	LH* ptail = NULL;
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
	DSLH DSlop_hoc;
};
typedef struct CapLop CL;

struct dsCapLop
{
	CL* ds[1000];
	int sl = 0;

};
typedef struct dsCapLop DSCL;
