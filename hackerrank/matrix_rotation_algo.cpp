#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

std::string ltrim(const std::string &);
std::string rtrim(const std::string &);
std::vector<std::string> split(const std::string &);

void matrixRotation(std::vector<std::vector<int>> matrix, int r) {

    int y = matrix.size();
    int x = matrix[0].size();

    std::vector < std::vector<int> > copied(y, std::vector<int>(x, 0));

    int rect_size_x;
    int rect_size_y;

    int newer_index_x;
    int newer_index_y;
    int newer_x;
    int newer_y;

    std::vector<int> move;

    int r_new;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {

            move.push_back(i);
            move.push_back(j);
            move.push_back(y - i - 1);
            move.push_back(x - j - 1);
            std::sort(move.begin(), move.end());

            rect_size_y = y - (move[0]*2);
            rect_size_x = x - (move[0]*2);

            newer_index_x = j - move[0];
            newer_index_y = i - move[0];

            r_new = r % ((rect_size_x * 2 + rect_size_y * 2) - 4);
          
            for (int z = 0 ; z < r_new; z++) {

                if (newer_index_x + 1 == rect_size_x && newer_index_y > 0) { newer_index_y--; continue; }
                if (newer_index_y == 0 && newer_index_x > 0) { newer_index_x--; continue; }
                if (newer_index_x == 0 && newer_index_y + 1 < rect_size_y) { newer_index_y++; continue; }
                if (newer_index_y + 1 == rect_size_y && newer_index_x + 1 < rect_size_x) { newer_index_x++; continue; }
            }
  
           copied[newer_index_y + move[0]][newer_index_x + move[0]] = matrix[i][j];
           move.clear();
		}
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            std::cout << copied[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::string mnr_temp;
    getline(std::cin, mnr_temp);

    std::vector<std::string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    std::vector<std::vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        std::string matrix_row_temp_temp;
        getline(std::cin, matrix_row_temp_temp);

        std::vector<std::string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

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