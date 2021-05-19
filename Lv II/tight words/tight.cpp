#include <iostream>
//libreria per poter eseguire alcune operazioni matematiche come elevamento a potenza, radice quadrata, ...
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

__uint128_t CountTightWords(vector<vector<__uint128_t>>& DP, long long int i, long long int j, long long int k, long long int n);


//struttura base del programma
int main(){

    long long int k, n;
    __uint128_t tightWords;
    long double answer;

    while( cin >> k >> n ){
        vector<vector<__uint128_t>> DP(k+1, vector<__uint128_t>(n, -1));
        for(long long int i = 0; i <= k; i++){
            DP[i][n-1] = 1;
        }

        tightWords = 1;

        if(k > 0){
            tightWords = 0;
            for(long long int i = 0; i <= k; i++){
                tightWords += CountTightWords(DP, i, 0, k, n);
            }
        }

        answer = (long double)tightWords/pow(k+1, n)*100;
        
        cout << fixed;
        cout << setprecision(107);
        cout << answer << endl;
    }
}

__uint128_t CountTightWords(vector<vector<__uint128_t>>& DP, long long int i, long long int j, long long int k, long long int n){
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