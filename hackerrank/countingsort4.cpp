#include <iostream>
#include <string>
#include <vector>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

void countSort(std::vector<std::vector<std::string>> arr) {

    std::vector<std::vector<std::string>>vec(100);

    int temp;
    for (int i = 0; i < arr.size() / 2; i++) {
        temp = stoi(arr[i][0]);

        vec[temp].push_back("-");
    }
    for (int i = arr.size() / 2; i < arr.size(); i++) {
        temp = stoi(arr[i][0]);

        vec[temp].push_back(arr[i][1]);
    }

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].size()>0) {
            for (int j = 0; j < vec[i].size(); j++) {
                std::cout << vec[i][j] << " ";
            }
        }
    }
}

int main()
{
    std::string n_temp;
    getline(std::cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    std::vector<std::vector<std::string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        std::string arr_row_temp_temp;
        getline(std::cin, arr_row_temp_temp);

        std::vector<std::string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            std::string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

    return 0;
}

std::string ltrim(const std::string &str) {
    std::string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(isspace)))
    );

    return s;
}

std::string rtrim(const std::string &str) {
    std::string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

std::vector<std::string> split(const std::string &str) {
    std::vector<std::string> tokens;

    std::string::size_type start = 0;
    std::string::size_type end = 0;

    while ((end = str.find(" ", start)) != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}