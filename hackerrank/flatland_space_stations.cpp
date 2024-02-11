#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split_string(std::string);

int flatlandSpaceStations(int n, std::vector<int> c) {

    int max = 0;
    std::sort(c.begin(), c.end());

    for (int i = 0; i < c.size() - 1; i++) {
        if ((c[i + 1] - c[i]) / 2 > max) max = (c[i + 1] - c[i]) / 2;
    }

    if (c[0] > max)max = c[0];
    if (n - 1 - c[c.size() - 1] > max)max = n - 1 - c[c.size() - 1];

    return max;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string nm_temp;
    getline(std::cin, nm_temp);

    std::vector<std::string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    std::string c_temp_temp;
    getline(std::cin, c_temp_temp);

    std::vector<std::string> c_temp = split_string(c_temp_temp);

    std::vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}

std::vector<std::string> split_string(std::string input_string) {
    std::string::iterator new_end = std::unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y && x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    std::vector<std::string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != std::string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, std::min(pos, input_string.length()) - i + 1));

    return splits;
}