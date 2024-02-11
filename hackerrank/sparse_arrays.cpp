#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>

std::string ltrim(const std::string&);
std::string rtrim(const std::string&);

std::vector<int> matchingStrings(std::vector<std::string> strings, std::vector<std::string> queries) {

    std::vector<std::vector<std::string>>sum;
    std::vector<std::string>temp;
    std::sort(strings.begin(), strings.end());

    std::string current = strings[0];
    int suma = 1;

    for (std::vector<std::string>::iterator it = strings.begin() + 1; it != strings.end(); ++it) {
        if (*it == current) {
            suma++;
        }
        else {
            temp.push_back(*(it - 1));
            temp.push_back(std::to_string(suma));
            sum.push_back(temp);
            temp.clear();
            current = *it;
            suma = 1;
        }
    }

    if (suma > 0) {
        temp.push_back(current);
        temp.push_back(std::to_string(suma));
        sum.push_back(temp);
        temp.clear();
    }

    std::vector<int>ret;

    for (std::vector<std::string>::iterator it = queries.begin(); it != queries.end(); ++it) {
        for (int i = 0; i < sum.size(); i++) {
            if (*it == sum[i][0]) {
                ret.push_back(stoi(sum[i][1]));
                break;
            }
            if (i == sum.size() - 1)ret.push_back(0);
        }
    }

    return ret;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string strings_count_temp;
    getline(std::cin, strings_count_temp);

    int strings_count = stoi(ltrim(rtrim(strings_count_temp)));

    std::vector<std::string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        std::string strings_item;
        getline(std::cin, strings_item);

        strings[i] = strings_item;
    }

    std::string queries_count_temp;
    getline(std::cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    std::vector<std::string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        std::string queries_item;
        getline(std::cin, queries_item);

        queries[i] = queries_item;
    }

    std::vector<int> res = matchingStrings(strings, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

std::string ltrim(const std::string& str) {
    std::string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace)))
    );

    return s;
}

std::string rtrim(const std::string& str) {
    std::string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}