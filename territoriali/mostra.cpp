//libreria per poter utilizzare i file con facilità
#include <fstream>
//libreria per poter fare cout e cin e quindi gestire I/O da terminale (la useremo per test)
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

//Inserite le altre librerie che potrebbero servirvi qui

//per evitare di usare std::
using namespace std;

int max_profit(vector<vector<int>>& DP, vector<int>& G, vector<int>& V, int i, int j, int N, int M){
    if(j == M || i == N){
        return DP[i][j];
    } else {
        if(DP[i][j] == -1){
            if(G[j] > V[i]){
                DP[i][j] = max(2 + max_profit(DP, G, V, i+1, j+1, N, M), max(max_profit(DP, G, V, i, j+1, N, M), 1 + max_profit(DP, G, V, i+1, j, N, M)));
            } else {
                DP[i][j] = max(1 + max_profit(DP, G, V, i+1, j, N, M), max_profit(DP, G, V, i, j+1, N, M));
            }
            
        }
        return DP[i][j];
    }
}

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("mostra_input_1.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int T = 0;
    in >> T;

    for(int i = 1; i <= T; i++){
        int N = 0;
        int M = 0;
        in >> N >> M;
        vector<int> V(N, -1);
        vector<int> G(M, -1);
        for(int i = 0; i < N; i++){
            in >> V[i];
        }
        for(int j = 0; j < M; j++){
            in >> G[j];
        }

vector<vector<int>> DP(N+1, vector<int>(M+1, -1));
for(int i = 0; i < N; i++){
    DP[i][M] = N-i;
}
for(int j = 0; j <= M; j++){
    DP[N][j] = 0;
}

out << "Case #" << i << ": " << max_profit(DP, G, V, 0, 0, N, M) << endl;
    }

    return 0;
}