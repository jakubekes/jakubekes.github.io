#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);

std::vector<int> stones(int n, int a, int b) {
    
    std::vector<int> result; 
	
    for (int i=0; i<n; i++){
       result.push_back(i*a+(n-i-1)*b);             
    }
    
	std::sort(result.begin(), result.end());

	std::vector<int> result_final;
	result_final.push_back(result[0]); 

	for (int i=1; i<result.size(); i++){
		if(result[i]!=result_final[result_final.size()-1])result_final.push_back(result[i]);
	}

	return result_final;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string T_temp;
    getline(std::cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        std::string n_temp;
        getline(std::cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        std::string a_temp;
        getline(std::cin, a_temp);

        int a = stoi(ltrim(rtrim(a_temp)));

        std::string b_temp;
        getline(std::cin, b_temp);

        int b = stoi(ltrim(rtrim(b_temp)));

        std::vector<int> result = stones(n, a, b);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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