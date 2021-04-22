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
			ofst << "Count of consonants: " << cont[i]->CountLetters() << endl;
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
		string type;
		string place;
		getline(ifst, type);
		int k = stoi(type);
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
			char junk[50]; //для мусора
			ifst.getline(junk, 50); //Здесь - имя
			ifst.getline(junk, 50); //Здесь - уникальная характеристика
			ifst.getline(junk, 50); //Здесь - место произрастания
			return 0;
		}
		string line; //Временное решение на случай переполнения
		getline(ifst, line);
		if (line.length() < 50) { //Проверка на переполнение - если длина Line < 100
			strcpy_s(sp->m_Name, 50, line.c_str());
			sp->InData(ifst);	
		}
		else {
			line.resize(49);
			strcpy_s(sp->m_Name, 50, line.c_str());
			sp->InData(ifst);
		}
		
		getline(ifst, place);
		int pass = stoi(place);
		switch (pass) {
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
		string num;
		getline(ifst, num);
		int pass = stoi(num);
		switch (pass) {
		case 1:
			this->kind = flowers::Type::Wild;
			break;
		case 2:
			this->kind = flowers::Type::Home;
			break;
		default:
			cout << "Unknown type\n";
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
		return CountLetters() < other.CountLetters();
	}

	void shape::OutTrees(ofstream& ofst) {
		ofst << "Unknown" << endl; // пустая строка 
	}

	// Ввод параметров кустарника ( бывшая shrub_in)
	void shrubs::InData(ifstream& ifst) {
		string num;
		getline(ifst, num);
		int pass = stoi(num);
			switch (pass) {
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
		string age;
		getline(ifst, age);
		if (age.length() < 50) {
			this->m_Age = stol(age);
		}
		else
		{
			age.resize(49);
			this->m_Age = stol(age);
		}
		age.clear();
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

	void trees::OutTrees(ofstream& ofst) {
		Out(ofst);
	}

	int trees::CountLetters() {
		int letter = 0;
		int i = 0;
		char alphabet[] = "bcdfghjklmnpqrstvwxz";

		while (this->m_Name[i] != '\0')
		{
			if (strchr(alphabet, this->m_Name[i])) {
				letter++;
			}
			i++;
		}
		return letter;
	}

	int shrubs::CountLetters() {
		int letter = 0;
		int i = 0;
		char alphabet[] = "bcdfghjklmnpqrstvwxz";

		while (this->m_Name[i] != '\0')
		{
			if (strchr(alphabet, this->m_Name[i])) {
				letter++;
			}
			i++;
		}
		return letter;
	}

	int flowers::CountLetters() {
		int letter = 0;
		int i = 0;
		char alphabet[] = "bcdfghjklmnpqrstvwxz";

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