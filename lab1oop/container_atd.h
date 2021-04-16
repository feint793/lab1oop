#pragma once
#ifndef __container_atd__
#define __container_atd__
#include <fstream>
using namespace std;
namespace nature {
	
//////////////////////// Класс, обобщающает все имеющиеся объекты.
// Является абстрактным, обеспечивая, тем самым,
// проверку интерфейса
	class shape {
	public:
		//char area[100];
		char m_Name[50];
		enum place { Forest, Garden, Steppe, Tundra };
		place area;
		// иденитфикация, порождение и ввод объектов из потока
		static shape* In(ifstream& ifst);
		virtual void InData(ifstream& ifst) = 0; // ввод
		virtual void Out(ofstream& ofst) = 0; // вывод
		

		virtual void OutTrees(ofstream& ofst);
		virtual int Count_letters() = 0;
		bool Compare(shape& other);

	};
		/////////////////// Простейший контейнер на основе одномерного массива
	class container {
		enum { max_len = 100 }; // максимальная длина
		int len; // текущая длина
		shape *cont[max_len];
		public:
			void In(ifstream &ifst); // ввод
			void Out(ofstream &ofst); // вывод
			void OutTrees(ofstream& ofst);
			void Clear(); // очистка контейнера от фигур
			void Sort();
			container(); // инициализация контейнера
			~container() { Clear(); } // утилизация контейнера
	};

		////////////////// дерево
	class trees : public shape {
		long int m_Age; // возраст, название
		public:
			// переопределяем интерфейс класса
			void InData(ifstream& ifst); // ввод
			void Out(ofstream& ofst); // вывод
			void OutTrees(ofstream& ofst);
			int Count_letters();
			trees() {} // создание без инициализации.
		};
	
		////////////////// кустарник
	class shrubs : public shape {
		enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		Month flowering;
		public:
			// переопределяем интерфейс класса
			void InData(ifstream& ifst); // ввод
			void Out(ofstream& ofst); // вывод
			int Count_letters();
			shrubs() {} // создание без инициализации.
		};

} 
#endif
