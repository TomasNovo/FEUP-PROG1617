#pragma once

#include <string>
#include <vector>

using namespace std;

class StringUtils {
public:
    static string trim(string source);

    static string join(vector<string> strings, string glue);

    static string join(vector<int> integers, string glue);
};