//
// Created by Luis Lobo on 29/04/2017.
//

#include <cstdlib>
#include <sstream>
#include "StringUtils.h"

string StringUtils::trim(string source) {
    size_t first = source.find_first_not_of(' ');
    if (first == -1) {
        return source;
    }
    size_t last = source.find_last_not_of(' ');
    return source.substr(first, (last - first + 1));

}

string StringUtils::join(vector<string> strings, string glue) {
    ostringstream joined;
    for (int i = 0; i < strings.size(); i++) {
        if (i > 0)
            joined << glue;
        joined << strings[i];
    }
    return joined.str();
}

string StringUtils::join(vector<int> integers, string glue) {
    ostringstream joined;
    for (int i = 0; i < integers.size(); i++) {
        if (i > 0)
            joined << glue;
        joined << integers[i];
    }
    return joined.str();
}
