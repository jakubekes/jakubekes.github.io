#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

long arrayManipulation(int n, std::vector<std::vector<int>> queries) {

	std::vector <long> vec(n,0);

	long max=0;
	long temp=0;

	for (int j = 0; j < queries.size(); j++) {
		vec[(queries[j][0])-1]+=queries[j][2]; 
		if(queries[j][1]<=vec.size()-1)vec[(queries[j][1])]-=queries[j][2];   
	}

	for (int j = 0; j < n; j++) {
		temp+=vec[j];
		if(temp>max)max=temp; 
	}

	return max;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string first_multiple_input_temp;
    getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    std::vector<std::vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        std::string queries_row_temp_temp;
        getline(std::cin, queries_row_temp_temp);

        std::vector<std::string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

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