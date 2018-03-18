#include "Line.h"

#include "StringUtils.h"
#include <sstream>
#include <fstream>


Line::Line(string line) {
    vector<string> result;

    stringstream lineStream(line);
    string cell;

    while (getline(lineStream, cell, ';')) {
        result.push_back(StringUtils::trim(cell));
    }

    m_id = (unsigned int) stoi(result[0]);
    m_frequency = (unsigned int) stoi(result[1]);

    stringstream stopStream(result[2]);
    while (getline(stopStream, cell, ',')) {
        m_busStops.push_back(StringUtils::trim(cell));
    }

    stringstream timeStream(result[3]);
    while (getline(timeStream, cell, ',')) {
        m_timings.push_back(stoi(StringUtils::trim(cell)));
    }
}


void Line::saveTo(string filename) {
    ifstream input(filename);

    vector<Line> lines;
    bool found = false;

    // Ler todas as linhas primeiro
    if (!input.fail()) {
        string line;
        while (getline(input, line)) {
            Line l(line);

            // se é a linha atual, substitui-la no vetor
            if (l.getId() == m_id) {
                found = true;
                lines.push_back(*this);
            } else {
                lines.push_back(l);
            }
        }
    }

    if (!found)
        lines.push_back(*this);

    ofstream output(filename);
    for (int i = 0; i < lines.size(); i++) {
        output << lines[i].toString() << endl;
    }
}

string Line::toString() {
    ostringstream output;
    output << m_id << " ; "
           << m_frequency << " ; "
           << StringUtils::join(m_busStops, ", ") << "; "
           << StringUtils::join(m_timings, ", ");
    return output.str();
}

void Line::fillFromInput() {
    cout << "What's the line's id: " << endl;
    cin >> m_id;

    cout << "What's the frequency of the line: " << endl;
    cin >> m_frequency;

    int n_stops;
    cout << "Number of stops of the line: ";
    cin >> n_stops;

    cout << " What are the stops?" << endl;

    cin.ignore();
    for (unsigned long i = 0; i < n_stops; i++) {
        cout << "Stop " << (i + 1) << "/" << n_stops << ": ";
        string stop;
        getline(cin, stop);
        m_busStops.push_back(stop);
    }

    cout << "Please input the times between stops:" << endl;
    for (unsigned long u = 0; u < n_stops - 1; u++) {
        int time;
        cout << "Time " << (u + 1) << "/" << (n_stops - 1) << ": ";
        cin >> time;
        m_timings.push_back(time);
    }
}



vector<Line> Line::readFrom(string filename) {
    ifstream file(filename);
    if (file.fail()) {
        std::cerr << "Erro ao ler o ficheiro: " << filename << std::endl;
        exit(1);
    }

    string line;
    vector<Line> lines;
    while (getline(file, line)) {
        Line l(line);
        lines.push_back(l);
    }

    return lines;
}

