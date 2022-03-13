#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <stdexcept>
#include "mat.hpp"
using namespace std;
using namespace ariel;


string ariel::mat(int a, int b, char c, char d) {

        // make sure the mat dimensions are valid 
        if (a % 2 == 0 || b % 2 == 0 || a <= 0 || b <= 0) {
            throw invalid_argument("bad input (a/b)");
        }
        
        // make sure the chars entered are valid printable chars
        if (isprint(c) == 0 || isprint(d) == 0 || isspace(c) != 0 || isspace(d) != 0) {
            throw invalid_argument("bad input (c/d)");
        }
        
        string ans;

        // deal with an edge case, where there is 1 column and more then 1 rows
        if (a == 1 && b > 1) {
            for (int i = 0; i < b; i++) {
                ans += c;
            }
            return ans;
        }

        vector<vector<char>> mat_matrix(b, vector<char>(a));
        

        // make circles that get smaller and smaller untill you get to the center
        for (int i = 0, j = a - 1, f = b - 1; i < b; i++, j--, f--) {
            for (int k = i; k <= j; k++) {
                if (i % 2 == 0) {
                    mat_matrix[i][k] = c;
                    mat_matrix[f][k] = c;
                } else {
                    mat_matrix[i][k] = d;
                    mat_matrix[f][k] = d;
                }
            }
            for (int s = i; s <= f; s++) {
                if (i % 2 == 0) {
                    mat_matrix[s][i] = c;
                    mat_matrix[s][j] = c;
                } else {
                    mat_matrix[s][i] = d;
                    mat_matrix[s][j] = d;
                }
            }
        }

        // convert the matrix to string
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j ++) {
                ans += mat_matrix[i][j];
            }
            ans += '\n';
        }

        return ans;


    }