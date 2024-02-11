#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

std::vector<int> circularArrayRotation(std::vector<int> a, int k, std::vector<int> queries) {

    if(k>=a.size()){
        k=k%a.size();
    }
    
    for(std::vector<int>::iterator it=queries.begin(); it!=queries.end(); it++){

        if((*it-k)<0){
          *it= a [ a.size()-(k-*it) ];     
        } else {
          *it=a[*it-k];   
        }
    }
	
	return queries;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string first_multiple_input_temp;
    getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    int k = stoi(first_multiple_input[1]);
    int q = stoi(first_multiple_input[2]);

    std::string a_temp_temp;
    getline(std::cin, a_temp_temp);

    std::vector<std::string> a_temp = split(rtrim(a_temp_temp));
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    std::vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        std::string queries_item_temp;
        getline(std::cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    std::vector<int> result = circularArrayRotation(a, k, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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