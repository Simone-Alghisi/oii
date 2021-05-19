#include <fstream>
#include <iostream>

using namespace std;

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int N;
    in >> N; 
    //lunghezza della sequenza di collatz iniziale (ho almeno un numero)
    int length = 1;
    //finchè il numero non e' pari a 1
    while(N != 1){
        //verifico se il numero e' pari
        if(N % 2 == 0){
            //in quel caso lo divido per 2
            N = N/2;
        } else {
            //se invece e' dispari moltiplico per 3 e sommo 1 
            N = 3*N + 1;
        }
        //incremento la lunghezza della sequenza
        length++;
    }

    out << length;

    return 0;
}