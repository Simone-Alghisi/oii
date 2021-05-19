#include <fstream>
#include <iostream>
//libreria per poter eseguire alcune operazioni matematiche come elevamento a potenza, radice quadrata, ...
#include <math.h>
#include <vector>

using namespace std;

int CountTightWords(vector<vector<int>>& DP, int i, int j, int k, int n);


//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int k, n;
    int tightWords;

    while( !in.eof() ){
        in >> k >> n;

        vector<vector<int>> DP(k+1, vector<int>(n, -1));

        for(int i = 0; i <= k; i++){
            DP[i][n-1] = 1;
        }

        tightWords = 1;

        if(k > 0){
            tightWords = 0;
            for(int i = 0; i <= k; i++){
                tightWords += CountTightWords(DP, i, 0, k, n);
            }
        }

        out << (double)tightWords/pow(k+1, n)*100 << endl;
    }

    return 0;
}

int CountTightWords(vector<vector<int>>& DP, int i, int j, int k, int n){
    if(DP[i][j] == -1){
        if(i == 0){
            DP[i][j] = CountTightWords(DP, i, j+1, k, n) + CountTightWords(DP, i+1, j+1, k, n);
        } else if(i == k){
            DP[i][j] = CountTightWords(DP, i, j+1, k, n) + CountTightWords(DP, i-1, j+1, k, n);
        } else {
            DP[i][j] = CountTightWords(DP, i-1, j+1, k, n) + CountTightWords(DP, i, j+1, k, n) + CountTightWords(DP, i+1, j+1, k, n);
        }
    }

    return DP[i][j];
}