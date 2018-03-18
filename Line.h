#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Line {
private:
    unsigned int m_id;
    unsigned int m_frequency;
    vector<string> m_busStops;
    vector<int> m_timings;
public:

	
    Line(string line);

    // metodos get
    unsigned int getId() const { return m_id; }

    unsigned int getFrequency() const { return m_frequency; }

    vector<string> getBusStops() const { return m_busStops; }

    vector<int> getTimings() const { return m_timings; }

    // set methods

    void setId(const unsigned int &id) { m_id = id; }

    void setFrequency(const unsigned int &frequency) { m_frequency = frequency; }

    void setBusStops(const vector<string> &busStops) { m_busStops = busStops; }

    void setTimings(const vector<int> &timings) { m_timings = timings; }

    // other methods

    string toString();

    void fillFromInput();

    // store methods

    void saveTo(string filename);



    // utility methods

    static vector<Line> readFrom(string filename);

};
