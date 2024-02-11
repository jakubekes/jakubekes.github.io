#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

int workbook(int n, int k, std::vector<int> arr) {
    
    int result=0;
    int page=1;
    int pages;
    
    for(int i=0; i<n; i++){
       pages=arr[i]/k;
       if(arr[i]%k>0)pages+=1;
       
       for(int j=page; j<=page+pages-1; j++){
           if(j>=(j-page+1)*k-k+1 && j<=(j-page+1)*k && j<=arr[i])result++;
       }
       
       page+=pages;
    }
    
	return result;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string first_multiple_input_temp;
    getline(std::cin, first_multiple_input_temp);

    std::vector<std::string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = std::stoi(first_multiple_input[0]);

    int k = std::stoi(first_multiple_input[1]);

    std::string arr_temp_temp;
    getline(std::cin, arr_temp_temp);

    std::vector<std::string> arr_temp = split(rtrim(arr_temp_temp));

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = std::stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = workbook(n, k, arr);

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