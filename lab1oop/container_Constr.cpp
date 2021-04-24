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
		getline(ifst, Type);
		int k = stoi(Type);
		switch (k) {
		case 1:
			sp = new trees;
			break;
		case 2:
			sp = new shrubs;
			break;
		default:
			return 0;
		}
		ifst.getline(sp->m_Name, 50);
		sp->InData(ifst);
		//ifst >> sp->growth;
		return sp;
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
		ofst << "It is tree: " << this->m_Name << "\nAge: " << this->m_Age << "\n";
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

	void container::MultiMethod(ofstream& ofst) {
		ofst << "Multimethod." << endl;
		for (int i = 0; i < len - 1; i += 2) {
			for (int j = i + 1; j < len; j++) {
				ofst << endl;
				cont[i]->MultiMethod(cont[j], ofst);
				cont[i]->MMOut(ofst);
				cont[j]->MMOut(ofst);
				break;
			}
		}
	}

	////Группа для деревьев
	void trees::MMTree(ofstream& ofst) {
		ofst << "Tree and Tree" << endl;
	}

	void trees::MMShrub(ofstream& ofst) {
		ofst << "Shrub and Tree" << endl;
	}

	void trees::MultiMethod(shape* other, ofstream& ofst) {
		other->MMTree(ofst);
	}

	void trees::MMOut(ofstream& ofst) {
		ofst << "It is a Tree: " << this->m_Name << "\nAge: " << this->m_Age << "\n" << endl;
	}

	///Группа для кустарников
	void shrubs::MultiMethod(shape* other, ofstream& ofst) {
		other->MMShrub(ofst);
	}

	void shrubs::MMTree(ofstream& ofst) {
		ofst << "Tree and shrub" << endl;
	}

	void shrubs::MMShrub(ofstream& ofst) {
		ofst << "Shrub and Shrub" << endl;
	}

	void shrubs::MMOut(ofstream& ofst) {
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
	}
} 