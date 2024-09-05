#include<bits/stdc++.h>
using namespace std;

// T.C - O(n)
// S.C - O(n)

// for a string we find LPPS(Longest proper prifix suffix array)
// each index i of array represents the LPPS from 0 to i

void computeLPS(string pattern, vector<int>& lps) {
            int M = pattern.length();
            // Length of the previous longest prefix & suffix
            int len = 0; 
            
            // Because there is no proper suffix and prefix of pattern[0..0]
            lps[0] = 0; 
        
            int i = 1;
            while (i < M) {
                if (pattern[i] == pattern[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len - 1]; 
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }
