//libreria per poter utilizzare i file con facilità
#include <fstream>
//libreria per poter fare cout e cin e quindi gestire I/O da terminale (la useremo per test)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

//Inserite le altre librerie che potrebbero servirvi qui

//per evitare di usare std::
using namespace std;

void findVirus(vector<vector<vector<vector<int>>>>& DP, const string F1, const string F2, const string F3, const string F4, int N1, int N2, int N3, int N4, int M, vector<int>& sol){
    for (int i = 0; i <= N1; i++){
        for (int j = 0; j <= N2; j++){
            for (int k = 0; k <= N3; k++){
                for (int l = 0; l <= N4; l++){
                    if (i == 0 || j == 0 || k == 0 || l == 0){
                        DP[i][j][k][l] = 0;
                    }else if (F1[i-1] == F2[j-1] && F2[j-1] == F3[k-1] && F3[k-1] == F4[l-1]) {
                        //cout << i << " " << j << " " << k << " " << l << endl;
                        //cout << F1[i-1] << " " << F2[j-1] << " " << F3[k-1] << " " << F4[l-1] << endl ;
                        DP[i][j][k][l] = DP[i-1][j-1][k-1][l-1] + 1;
                        //cout << DP[i][j][k][l] << endl << endl;
                        if(DP[i][j][k][l] == M){
                            sol[0] = i - M;
                            sol[1] = j - M;
                            sol[2] = k - M;
                            sol[3] = l - M;
                            return;
                        }
                    }
                    else{
                        DP[i][j][k][l] = 0;
                    }
                }
            }
        }
    }    
}

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("antivirus_input_1.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int T = 0;
    in >> T;

    for(int i = 1; i <= T; i++){
        int N1, N2, N3, N4 = 0;
        in >> N1 >> N2 >> N3 >> N4;

        int M = 0;
        in >> M;

        string F1, F2, F3, F4;
        in >> F1 >> F2 >> F3 >> F4;
        
        vector<vector<vector<vector<int>>>> DP(N1+1,vector<vector<vector<int>>>(N2+1, vector<vector<int>>(N3+1, vector<int>(N4+1, 0))));
        vector<int> sol(4);
        findVirus(DP, F1, F2, F3, F4, N1, N2, N3, N4, M, sol);
        
        out << "Case #" << i << ": " << sol[0] << " " << sol[1] << " " << sol[2] << " " << sol[3] << endl;
        /*
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                cout << DP[i][j] << " ";
            }
            cout << endl;
        }
        */
    }

    return 0;
}