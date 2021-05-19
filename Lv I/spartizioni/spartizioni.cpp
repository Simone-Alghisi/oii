#include <fstream>
#include <iostream>

using namespace std;

/**
 * P.s. scrivere 
 * 
 * G -= turn;
 * 
 * equivale a scrivere
 * 
 * G = G - turn;
 * 
 * La stessa cosa si applica agli altri operatori
**/

//struttura base del programma
int main(){
    //file da cui leggere
    ifstream in("input.txt");
    //file su cui scrivere
    ofstream out("output.txt");

    int G, P;
    in >> G >> P; 
    
    //istanzio una variabile per il numero di gemme totali che avrà Toto
    int totoGem = 0;
    //e una invece per il numero di turni che sono passati
    int turn = 1;

    //finche' non avrò esaurito le gemme
    while(G > 0){
        //controllo se posso prendere turn gemme
        if(G - turn >= 0){
            //ed in quel caso gliele assegno
            totoGem += turn;
            G -= turn;
        } else {
            //altrimenti gli assegno tutte le gemme rimanenti
            totoGem += G;
            //ed imposto il numero di gemme restanti a zero
            G = 0;
        }
        //dopodichè sottraggo un numero di gemme pari a P-1 (in quanto toto ne distribuisce sempre una a testa)
        G -= P-1;
        //ed infine incremento il numero di gemme che Toto prenderà al turno successivo
        turn++;
    }

    out << totoGem;

    return 0;
}