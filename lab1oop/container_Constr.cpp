#include "stdafx.h"
#include <string>
#include <iostream>
#include "container_atd.h"
using namespace std;
namespace nature {
	// Инициализация контейнера
	container::container() : len(0) { }
	// Очистка контейнера от элементов
	void container::Clear() {
		for (int i = 0; i < len; i++) {
			delete cont[i];
		}
		len = 0;
	}

	// Ввод содержимого контейнера
	void container::In(ifstream& ifst) {
		while (!ifst.eof()) {
			if ((cont[len] = shape::In(ifst)) != 0) {
				len++;
			}
		}
	}

	// Вывод содержимого контейнера
	void container::Out(ofstream& ofst) {
		ofst << "Container contents " << len
			<< " elements." << endl;
		for (int i = 0; i < len; i++) {
			ofst << i << ": ";
			cont[i]->Out(ofst);
			ofst << "Count of consonants: " << cont[i]->Count_letters() << endl;
		}
	}

	void container::Sort() {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (cont[i]->Compare(*cont[j])) {
					shape* tmp = cont[i];
					cont[i] = cont[j];
					cont[j] = tmp;
				}
			}
		}
	}

	void container::OutTrees(ofstream& ofst) {
		ofst << "Only trees: " << endl;
		for (int i = 0; i < len; i++) {
			ofst << i << ": ";
			cont[i]->OutTrees(ofst);
		}
	}

	// Ввод параметров обобщенного объекта ( бывшая shape_in)
	shape* shape::In(ifstream& ifst) {
		shape* sp;
		string Type;
		string Place_P;
		getline(ifst, Type);
		int k = stoi(Type);
		switch (k) {
		case 1:
			sp = new trees;

			break;
		case 2:
			sp = new shrubs;
			break;
		case 3:
			sp = new flowers;
			break;
		default:
			return 0;
		}
		ifst.getline(sp->m_Name, 50);
		sp->InData(ifst);
		getline(ifst, Place_P);
		int Pass = stoi(Place_P);
		switch (Pass) {
		case 1:
			sp->area = shape::place::Forest;
			break;
		case 2:
			sp->area = shape::place::Garden;
			break;
		case 3:
			sp->area = shape::place::Steppe;
			break;
		case 4:
			sp->area = shape::place::Tundra;
			break;
		default:
			return 0;
		}
		return sp;
	}
	void flowers::InData(ifstream& ifst) {
		string Num;
		getline(ifst, Num);
		int Pass = stoi(Num);
		switch (Pass) {
		case 1:
			this->kind = flowers::Type::Wild;
			break;
		case 2:
			this->kind = flowers::Type::Home;
			break;
		default:
			cout << "Error\n";
		}
	}
	void flowers::Out(ofstream& ofst) {
		ofst << "It is flower: " << this->m_Name << "\n";

		switch (this->kind) {
		case flowers::Type::Wild:
			ofst << "Type: Home\n";
			break;
		case flowers::Type::Home:
			ofst << "Type: Wild\n";
			break;
		default:
			cout << "Error\n";
		}
	}

	bool shape::Compare(shape& other) {
		return Count_letters() < other.Count_letters();
	}

	void shape::OutTrees(ofstream& ofst) {
		ofst << "Unknown" << endl; // пустая строка 
	}

	// Ввод параметров кустарника ( бывшая shrub_in)
	void shrubs::InData(ifstream& ifst) {
		string Num;
		getline(ifst, Num);
		int Pass = stoi(Num);
		switch (Pass) {
		case 1:
			this->flowering = shrubs::Month::Jan;
			break;
		case 2:
			this->flowering = shrubs::Month::Feb;
			break;
		case 3:
			this->flowering = shrubs::Month::Mar;
			break;
		case 4:
			this->flowering = shrubs::Month::Apr;
			break;
		case 5:
			this->flowering = shrubs::Month::May;
			break;
		case 6:
			this->flowering = shrubs::Month::Jun;
			break;
		case 7:
			this->flowering = shrubs::Month::Jul;
			break;
		case 8:
			this->flowering = shrubs::Month::Aug;
			break;
		case 9:
			this->flowering = shrubs::Month::Sep;
			break;
		case 10:
			this->flowering = shrubs::Month::Oct;
			break;
		case 11:
			this->flowering = shrubs::Month::Nov;
			break;
		case 12:
			this->flowering = shrubs::Month::Dec;
			break;
		default:
			cout << "Error in InShrubs func!\n";
		}
		
		
	}

	// Вывод параметров кустарника (бывшая shrub_out)
	void shrubs::Out(ofstream& ofst) {
		ofst << "It is Shrub: " << this->m_Name << "\n";

		switch (this->flowering) {
		case shrubs::Month::Jan:
			ofst << "Month: January\n";
			break;
		case shrubs::Month::Feb:
			ofst << "Month: February\n";
			break;
		case shrubs::Month::Mar:
			ofst << "Month: March\n";
			break;
		case shrubs::Month::Apr:
			ofst << "Month: April\n";
			break;
		case shrubs::Month::May:
			ofst << "Month: May\n";
			break;
		case shrubs::Month::Jun:
			ofst << "Month: June\n";
			break;
		case shrubs::Month::Jul:
			ofst << "Month: July\n";
			break;
		case shrubs::Month::Aug:
			ofst << "Month: August\n";
			break;
		case shrubs::Month::Sep:
			ofst << "Month: September\n";
			break;
		case shrubs::Month::Oct:
			ofst << "Month: October\n";
			break;
		case shrubs::Month::Nov:
			ofst << "Month: November\n";
			break;
		case shrubs::Month::Dec:
			ofst << "Month: December\n";
			break;
		default:
			cout << "Error in OutShrubs func!\n";
		}

		switch (this->area) {
		case shape::place::Forest:
			ofst << "Grows in a forest" << endl;
			break;
		case shape::place::Garden:
			ofst << "Grows in a garden" << endl;
			break;
		case shape::place::Steppe:
			ofst << "Grows in a steppe" << endl;
			break;
		case shape::place::Tundra:
			ofst << "Grows in a tundra" << endl;
			break;
		default:
			ofst << "Incorrect area!" << endl;
		}
	}

	// Ввод параметров дерева (бывшая tree_in)
	void trees::InData(ifstream& ifst) {
		string Age;
		getline(ifst, Age);
		this->m_Age = stol(Age);
		
		//ifst.getline(this->x, 100);
		//ifst.getline(this->y, 100);
		//shape::InData(ifst);
	}

	// Вывод параметров дерева (бывшая tree_out)
	void trees::Out(ofstream& ofst) {
		ofst << "It is tree: " << this->m_Name << "\nAge: " << this->m_Age <<"\n";

		
		switch (this->area) {
		case shape::place::Forest:
			ofst << "Grows in a forest" << endl;
			break;
		case shape::place::Garden:
			ofst << "Grows in a garden" << endl;
			break;
		case shape::place::Steppe:
			ofst << "Grows in a steppe" << endl;
			break;
		case shape::place::Tundra:
			ofst << "Grows in a tundra" << endl;
			break;
		default:
			ofst << "Incorrect area!" << endl;
		}
	}
	// Ввод параметров фигуры
	/*void shape::InData(ifstream& ifst) {
		ifst >> growth;
	}
	// Вывод параметров фигуры
	void shape::Out(ofstream& ofst) {
		ofst << "angle = " << growth;
	}*/

	void trees::OutTrees(ofstream& ofst) {
		Out(ofst);
	}

	int trees::Count_letters() {
		int letter = 0;
		int i = 0;
		char alphabet[] = "bcdfghjklmnpqrstvwxz";
		//int lent = alphabet.length();

		while (this->m_Name[i] != '\0')
		{
			if (strchr(alphabet, this->m_Name[i])) {
				letter++;
			}
			i++;
		}
		return letter;
	}

	int shrubs::Count_letters() {
		int letter = 0;
		int i = 0;
		char alphabet[] = "bcdfghjklmnpqrstvwxz";
		//int lent = alphabet.length();

		while (this->m_Name[i] != '\0')
		{
			if (strchr(alphabet, this->m_Name[i])) {
				letter++;
			}
			i++;
		}
		return letter;
	}
} 