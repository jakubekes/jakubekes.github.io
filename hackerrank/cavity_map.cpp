#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);

std::vector<std::string> cavityMap(std::vector<std::string> grid) {

    int check;
	
    for (int i=1; i<grid.size()-1; i++){
         for (int j=1; j<grid.size()-1; j++){
             check=(grid[i])[j];
             if((grid[i])[j-1]<check && (grid[i])[j+1]<check && (grid[i-1])[j]<check && (grid[i+1])[j]<check) grid[i]=grid[i].substr(0,j)+"X"+grid[i].substr(j+1);
         }
    }
	
	return grid;
}

int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string n_temp;
    getline(std::cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    std::vector<std::string> grid(n);

    for (int i = 0; i < n; i++) {
        std::string grid_item;
        getline(std::cin, grid_item);

        grid[i] = grid_item;
    }

    std::vector<std::string> result = cavityMap(grid);

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