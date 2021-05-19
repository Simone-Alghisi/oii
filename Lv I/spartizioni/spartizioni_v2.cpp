#include <fstream>
#include <iostream>
//libreria per poter eseguire alcune operazioni matematiche come elevamento a potenza, radice quadrata, ...
#include <math.h>

using namespace std;

//consiglio fortemente di guardare la spiegazione su github di questo esercizio per poterlo capire appieno

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

    //calcoliamo b che utilizzeremo poi per calcolare l'equazione di secondo grado
    int b = 2*(P-1) + 1;
    //ed anche il delta perlo stesso motivo
    int delta = pow(b, 2) + 8*G;
    //calcolo il numero di turni per cui le gemme basteranno sia per Toto che per gli altri
    turn = floor( (-b + sqrt(delta))/2 );

    //calcolo il numero di gemme parziali di Toto
    totoGem = turn*(turn+1)/2;
    //e rimuovo le gemme di Toto e quelle dei suoi compagni
    G -= (totoGem + ((P-1)*turn));

    //a questo punto devo verificare quante sono le gemme rimanenti
    if( (G - (turn+1)) >= 0){
        //se ci sono piu' gemme di quelle che ne prenderebbe Toto allora ne prendo quel numero
        totoGem += (G - (turn+1));
    } else {
        //invece, se non ci sono abbastanza gemme, Toto ne prende il numero rimanente
        totoGem += G;
    }

    out << totoGem;

    return 0;
}