#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <functional>
#include <algorithm>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);

std::string happyLadybugs(std::string b) {

    std::vector<int> vec;
    bool is_underl=false;
    
    if(b.length()==1 && b=="_") return "YES";
    if(b.length()==1) return "NO";
    
    for(int i=0; i<b.length(); i++){       
        vec.push_back(b[i]);
        if(b[i]=='_')is_underl=true;       
    }
    
    std::sort(vec.begin(),vec.end());
    
    for(int i=1; i<vec.size()-1; i++){      
        if(vec[i]!=vec[i-1] && vec[i]!=vec[i+1] && vec[i]>=60 && vec[i]<=90)return "NO";
    }
    if(vec[0]!=vec[1] && vec[0]>=60 && vec[0]<=90)return "NO";
    if(vec[vec.size()-1]!=vec[vec.size()-2] && vec[vec.size()-1]>=60 && vec[vec.size()-1]<=90)return "NO";
    
    if(is_underl)return "YES";
    
    for(int i=0; i<b.length(); i++){       
    
        if(b[i]!=b[i-1] && b[i]!=b[i+1] && b[i]>=60 && b[i]<=90)return "NO";       
    }
    if(b[0]!=b[1] && b[0]>=60 && b[0]<=90)return "NO";
    if(b[b.length()-1]!=b[b.length()-2] && b[b.length()-1]>=60 && b[b.length()-1]<=90)return "NO";
 
 return "YES";
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string g_temp;
    getline(std::cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        std::string n_temp;
        getline(std::cin, n_temp);

        int n = std::stoi(ltrim(rtrim(n_temp)));

        std::string b;
        getline(std::cin, b);

        std::string result = happyLadybugs(b);

        fout << result << "\n";
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