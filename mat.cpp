#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "mat.hpp"
using namespace std;
using namespace ariel;


string ariel::mat(int a, int b, char c, char d) {
        if (a % 2 == 0 || b % 2 == 0 || a <= 0 || b <= 0) {
            throw invalid_argument("bad input (a/b)");
        }
        
        if (isprint(c) == 0 || isprint(d) == 0 || isspace(c) != 0 || isspace(d) != 0) {
            throw invalid_argument("bad input (c/d)");
        }
        
        string ans;


        if (a == 1 && b > 1) {
            for (int i = 0; i < b; i++) {
                ans += c;
            }
            return ans;
        }

        vector<vector<char>> m(b);
        
        for(int i = 0; i < b; i++) {
            m[i] = vector<char>(a);
        }

        for (int i = 0, j = a - 1, f = b - 1; i < b; i++, j--, f--) {
            for (int k = i; k <= j; k++) {
                if (i % 2 == 0) {
                    m[i][k] = c;
                    m[f][k] = c;
                } else {
                    m[i][k] = d;
                    m[f][k] = d;
                }
            }
            for (int s = i; s <= f; s++) {
                if (i % 2 == 0) {
                    m[s][i] = c;
                    m[s][j] = c;
                } else {
                    m[s][i] = d;
                    m[s][j] = d;
                }
            }
        }


        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j ++) {
                ans += m[i][j];
            }
            ans += '\n';
        }

        return ans;


    }