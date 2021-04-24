#pragma once
#ifndef __container_atd__
#define __container_atd__
#include <fstream>
using namespace std;
namespace nature {
	
//////////////////////// �����, ����������� ��� ��������� �������.
// �������� �����������, �����������, ��� �����,
// �������� ����������
	class shape {
	public:
		//char area[100];
		char m_Name[50];
		// �������������, ���������� � ���� �������� �� ������
		static shape* In(ifstream& ifst);
		virtual void InData(ifstream& ifst) = 0; // ����
		virtual void Out(ofstream& ofst) = 0; // �����
		virtual void OutTrees(ofstream& ofst);
		virtual void MultiMethod(shape* other, ofstream& ofst) = 0;
		virtual void MMTree(ofstream& ofst) = 0;
		virtual void MMShrub(ofstream& ofst) = 0;
		virtual void MMOut(ofstream& ofst) = 0;

	};
		/////////////////// ���������� ��������� �� ������ ����������� �������
	class container {
		enum { max_len = 100 }; // ������������ �����
		int len; // ������� �����
		shape *cont[max_len];
		public:
			void In(ifstream &ifst); // ����
			void Out(ofstream &ofst); // �����
			void OutTrees(ofstream& ofst);
			void Clear(); // ������� ���������� �� �����
			container(); // ������������� ����������
			~container() { Clear(); } // ���������� ����������
			void MultiMethod(ofstream& ofst);
	};

		////////////////// ������
	class trees : public shape {
		long int m_Age; // �������, ��������
		public:
			// �������������� ��������� ������
			void InData(ifstream& ifst); // ����
			void Out(ofstream& ofst); // �����
			void OutTrees(ofstream& ofst);
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMOut(ofstream& ofst);
			trees() {} // �������� ��� �������������.
		};
	
		////////////////// ���������
	class shrubs : public shape {
		enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		Month flowering;
		public:
			// �������������� ��������� ������
			void InData(ifstream& ifst); // ����
			void Out(ofstream& ofst); // �����
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMOut(ofstream& ofst);
			shrubs() {} // �������� ��� �������������.
		};

} 
#endif
