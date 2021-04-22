#pragma once
#ifndef __container_atd__
#define __container_atd__
#include <fstream>

using namespace std;

namespace nature {
	
	class shape {
		public:
			enum place { Forest, Garden, Steppe, Tundra };
			place area;
			char m_Name[50];
			// �������������, ���������� � ���� �������� �� ������
			static shape* In(ifstream& ifst);
			virtual void InData(ifstream& ifst) = 0; // ����
			virtual void Out(ofstream& ofst) = 0; // �����
			virtual void OutTrees(ofstream& ofst);
			virtual int CountLetters() = 0;
			bool Compare(shape& other);

	};

	class container {
		enum { max_len = 100 }; // ������������ �����
		shape *cont[max_len];
		public:
			int len; // ������� �����
			void In(ifstream &ifst); // ����
			void Out(ofstream &ofst); // �����
			void OutTrees(ofstream& ofst);
			void Clear(); // ������� ���������� �� �����
			void Sort();
			container(); // ������������� ����������
			~container() { 
				Clear(); 
			} // ���������� ����������
	};

	class trees : public shape {
		long int m_Age; // �������, ��������
		public:
			// �������������� ��������� ������
			void InData(ifstream& ifst); // ����
			void Out(ofstream& ofst); // �����
			void OutTrees(ofstream& ofst);
			int CountLetters();
			trees() {
				m_Age = 0;
			} // �������� ��� �������������.
	};
	
	class shrubs : public shape {
		enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		Month flowering;
		public:
			// �������������� ��������� ������
			void InData(ifstream& ifst); // ����
			void Out(ofstream& ofst); // �����
			int CountLetters();
			shrubs() {} // �������� ��� �������������.
	};

	class flowers : public shape {
		enum Type { Wild, Home };
		Type kind;
		public:
			// �������������� ��������� ������
			void InData(ifstream& ifst); // ����
			void Out(ofstream& ofst); // �����
			int CountLetters();
			flowers() {} // �������� ��� �������������.
	};

} 
#endif

