// lab1oop.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "container_atd.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	nature::container c;
	
	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.OutTrees(ofst);
	c.Clear();
	ofst << "Now the container is empty. " << endl;
	//c.Out(ofst);
	cout << "Stop" << endl;
	return 0;
}