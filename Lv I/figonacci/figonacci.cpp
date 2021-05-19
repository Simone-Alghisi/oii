#include <fstream>
#include <iostream>

using namespace std;

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    long int N, M;
    in >> N >> M; 
    //somma totale dei moduli dei valori precedenti
    int total_sum = (-1 % M + M) % M;
    //valore precedente
    int previous = 0;
    //valore corrente
    int current = 0;

    //ciclo dal secondo valore in poi
    for(long int i = 2; i <= N; i++){
        //innanzitutto eseguo il calcolo per poter calcolare il numero corrente tenenendo conto dei moduli
        current = ( (((i-1)*previous) % M) - (total_sum % M) ) % M;
        //visto che a C piace fare il simpatico con l'operazione modulo è necessario eseguire questa operazione
        current = (current % M + M) % M;
        //aggiorno la somma totale dei numeri precedenti tenendo solamente il modulo
        total_sum = ( (total_sum + previous) % M + M) % M;
        //assegno al valore precedente quello appena calcolato
        previous = current;
    }

    out << current;

    return 0;
}