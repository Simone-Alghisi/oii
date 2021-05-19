#include <fstream>
#include <iostream>

using namespace std;

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int A, B;
    in >> A >> B; 

    //variabile per contare i casi tra A e B per cui pollatz < collatz 
    int N = 0;

    //variabili temporanee per poter calcolare la sequenza di collatz e pollatz assieme
    int icollatz, ipollatz;

    //per ogni numero tra A e B compresi
    for(int i = A; i <= B; i++){
        //faccio partire entrambe le sequenze dallo stesso punto
        icollatz = ipollatz = i;

        //finchè una delle due sequenze non termina
        while(icollatz != 1 && ipollatz != 1){
            //verifico se il numero e' pari
            if(icollatz % 2 == 0){
                //in quel caso lo divido per 2
                icollatz = icollatz/2;
            } else {
                //se invece e' dispari moltiplico per 3 e sommo 1 
                icollatz = 3*icollatz + 1;
            }

            //se collatz ha gia' finito posso fermarmi e passare al prossimo numero
            if(icollatz != 1){
                //in caso contrario controllo se il numero e' pari
                if(ipollatz % 2 == 0){
                    //in quel caso lo divido per 2
                    ipollatz = ipollatz/2;
                } else {
                    //se invece e' dispari moltiplico per 5 e sommo 1 
                    ipollatz = 5*ipollatz + 1;
                }

                //se collatz non ha ancora finito ma pollatz ha finito
                if(ipollatz == 1){
                    //allora ho trovato una sequenza per cui pollatz < collatz
                    N++;
                }
            }
        }
    }

    out << N;

    return 0;
}