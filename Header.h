#pragma once

#include "Line.h"
#include <iostream>
#include <string>
#include <fstream>


void deleteLineFrom(string filename, const int id) { //apagar filename
	// Ler todas as linhas primeiro
	ifstream input(filename);
	if (input.fail()) {
		std::cerr << "Erro ao ler o ficheiro: " << filename << std::endl;
		exit(1);
	}

	string line;
	vector<Line> lines;
	bool found = false;
	while (getline(input, line)) {
		Line l(line);
		if (l.getId() != id)
			lines.push_back(l);
	}

	ofstream output(filename);
	for (int i = 0; i < lines.size(); i++) {
		output << lines[i].toString() << endl;
	}
}


int PesquisaId(int id, vector<Line> linhas) {

	cin >> id;
	
	for (int i = 0; i < linhas.size(); i++)
	{
		if (id == linhas[i].getId())
		{
			return i;
		}
	}
	

}
