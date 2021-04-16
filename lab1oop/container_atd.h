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
		enum place { Forest, Garden, Steppe, Tundra };
		place area;
		// �������������, ���������� � ���� �������� �� ������
		static shape* In(ifstream& ifst);
		virtual void InData(ifstream& ifst) = 0; // ����
		virtual void Out(ofstream& ofst) = 0; // �����
		

		virtual void OutTrees(ofstream& ofst);
		virtual int Count_letters() = 0;
		bool Compare(shape& other);

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
			void Sort();
			container(); // ������������� ����������
			~container() { Clear(); } // ���������� ����������
	};

		////////////////// ������
	class trees : public shape {
		long int m_Age; // �������, ��������
		public:
			// �������������� ��������� ������
			void InData(ifstream& ifst); // ����
			void Out(ofstream& ofst); // �����
			void OutTrees(ofstream& ofst);
			int Count_letters();
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
			int Count_letters();
			shrubs() {} // �������� ��� �������������.
		};

} 
#endif
