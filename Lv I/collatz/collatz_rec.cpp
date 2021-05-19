#include <fstream>
#include <iostream>

using namespace std;

/**
 * se volete provare a vedere una versione del codice di collatz ricorsiva, vi consiglio
 * di usare la tail recursion: se utilizzate una ricorsione normale rischiate infatti di
 * finire lo spazio sullo stack per le chiamate ricorsive. Con tail recursion si intende
 * un tipo di ricorsione per cui non e' necessario eseguire i calcoli quando tutte le 
 * chiamate sono terminate (cioe' quando avete ottenuto il numero 1).
 * Esempio pratico: se fate un codice del tipo 
 * 
 * return 1 + rec(N);
 * 
 * avete bisogno di arrivare al caso base prima di poter computare il tutto. Se invece
 * vi salvate il valore parziale mano a mano, facendo ad esempio
 * 
 * return rec(N, length + 1);
 * 
 * potete "dimenticarvi" delle chiamate precedenti: se il linguaggio lo permette dunque
 * potete riutilizzare sempre la stessa area di memoria in quanto non e' necessario 
 * mantenere tutto sullo stack. Tutto questo per dire: occhio allo Stack Overflow!
**/

//ho deciso di usare i riferimenti solamente per efficienza 
int collatz(int N, int length);

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

    out << collatz(N, length);

    return 0;
}

int collatz(int N, int length){
    //controllo se N non è pari a 1
    if(N != 1){
        //verifico se il numero e' pari
        if(N % 2 == 0){
            //in quel caso lo divido per 2
            N = N/2;
        } else {
            //se invece e' dispari moltiplico per 3 e sommo 1 
            N = 3*N + 1;
        }
        //chiamo la funzione ricorsiva: occhio a non fare length++
        return collatz(N, length + 1);
    } else {
        //come caso base restituisco length
        return length;
    }
}