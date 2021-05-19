#include <fstream>
#include <iostream>

using namespace std;
int combination(int &total_sum, int &product, int &remains);

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int N;
    in >> N; 
    int total_sum = 0;
    int product = 1;

    out << combination(total_sum, product, N) + 1;

    return 0;
}

int combination(int &total_sum, int &product, int &remains){
    if(remains == 0){
        if(total_sum == product){
            return 1;
        }
        return 0;
    } else {
        int total_combinations = 0;
        for(int i = 1; i <= 9; i++){
            total_sum = ((total_sum + i) % 1000000007 + 1000000007) % 1000000007;
            product = ((product * i) % 1000000007 + 1000000007) % 1000000007;
            remains -= 1;
            total_combinations += combination(total_sum, product, remains);
            total_combinations = total_combinations % 1000000007;
            remains += 1;
            total_sum = ((total_sum - i) % 1000000007 + 1000000007) % 1000000007;
            product = ((product / i) % 1000000007 + 1000000007) % 1000000007;
        }
        return total_combinations;
    }
    
}