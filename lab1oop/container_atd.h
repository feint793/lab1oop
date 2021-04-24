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
			// иденитфикация, порождение и ввод объектов из потока
			static shape* In(ifstream& ifst);
			virtual void InData(ifstream& ifst) = 0; // ввод
			virtual void Out(ofstream& ofst) = 0; // вывод
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
		enum { max_len = 100 }; // максимальная длина
		shape *cont[max_len];
		public:
			int len; // текущая длина
			void In(ifstream &ifst); // ввод
			void Out(ofstream &ofst); // вывод
			void OutTrees(ofstream& ofst);
			void Clear(); // очистка контейнера от фигур
			void Sort();
			void MultiMethod(ofstream& ofst);
			container(); // инициализация контейнера
			~container() { 
				Clear(); 
			} // утилизация контейнера
	};

	class trees : public shape {
		long int m_Age; // возраст, название
		public:
			// переопределяем интерфейс класса
			void InData(ifstream& ifst); // ввод
			void Out(ofstream& ofst); // вывод
			void OutTrees(ofstream& ofst);
			int CountLetters();
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMFlower(ofstream& ofst);
			void MMOut(ofstream& ofst);
			trees() {
				m_Age = 0;
			} // создание без инициализации.
	};
	
	class shrubs : public shape {
		enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		Month flowering;
		public:
			// переопределяем интерфейс класса
			void InData(ifstream& ifst); // ввод
			void Out(ofstream& ofst); // вывод
			int CountLetters();
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMFlower(ofstream& ofst);
			void MMOut(ofstream& ofst);
			shrubs() {} // создание без инициализации.
	};

	class flowers : public shape {
		enum Type { Wild, Home };
		Type kind;
		public:
			// переопределяем интерфейс класса
			void InData(ifstream& ifst); // ввод
			void Out(ofstream& ofst); // вывод
			int CountLetters();
			void MultiMethod(shape* other, ofstream& ofst);
			void MMTree(ofstream& ofst);
			void MMShrub(ofstream& ofst);
			void MMFlower(ofstream& ofst);
			void MMOut(ofstream& ofst);
			flowers() {} // создание без инициализации.
	};

} 
#endif

