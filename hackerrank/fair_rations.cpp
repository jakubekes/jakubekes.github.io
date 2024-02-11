#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

std::string fairRations(std::vector<int> B) {
    
	int odd=0;
	int sum=0;

	for(long unsigned int i=0; i<B.size(); i++){
		if(B[i]%2!=0)odd++;
	}

	if(odd%2==1)return "NO";


	for(int i=0; i<B.size(); i++){
		 if (B[i]%2==1){
		 sum+=2;
		 B[i+1]+=1;    
		 }
	}

	std::string sum_s=std::to_string(sum);
	return sum_s;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string N_temp;
    getline(std::cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    std::string B_temp_temp;
    getline(std::cin, B_temp_temp);

    std::vector<std::string> B_temp = split(rtrim(B_temp_temp));

    std::vector<int> B(N);

    for (int i = 0; i < N; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    std::string result = fairRations(B);

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