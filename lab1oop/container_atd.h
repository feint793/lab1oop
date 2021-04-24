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

			virtual void MultiMethod(shape* other, ofstream& ofst) = 0;
			virtual void MMTree(ofstream& ofst) = 0;
			virtual void MMShrub(ofstream& ofst) = 0;
			virtual void MMFlower(ofstream& ofst) = 0;
			virtual void MMOut(ofstream& ofst) = 0;
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
			void MultiMethod(ofstream& ofst);
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
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMFlower(ofstream& ofst);
			void MMOut(ofstream& ofst);
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
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMFlower(ofstream& ofst);
			void MMOut(ofstream& ofst);
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
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMFlower(ofstream& ofst);
			void MMOut(ofstream& ofst);
			flowers() {} // �������� ��� �������������.
	};

} 
#endif

