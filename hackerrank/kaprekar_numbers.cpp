#include <iostream>
#include <string>
#include <vector>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);

void kaprekarNumbers(unsigned long long int p, unsigned long long int q) {

unsigned long long int val;
std::string s1,s2,x,y;
unsigned long long int t1,t2;
std::vector<unsigned long long int> vec;

for(unsigned long long int i=p; i<=q; i++){
    
    val=i*i;
    x=std::to_string(val);
    y=std::to_string(i);
        
   if(val==i){
	   vec.push_back(i);
	   continue;
   } else if(x.length()>1){
	   s1=x.substr(0,x.length()-y.length());
	   s2=x.substr(x.length()-y.length());
	   t1=stoi(s1);
	   t2=stoi(s2);
	   if(t1+t2==i){
		   vec.push_back(i);
	   }
   }
}

if(vec.size()>0){
        for(std::vector<unsigned long long int>::iterator it=vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
        }
    }else{
        std::cout<<"INVALID RANGE";
    }
}

int main()
{
    std::string p_temp;
    getline(std::cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    std::string q_temp;
    getline(std::cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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