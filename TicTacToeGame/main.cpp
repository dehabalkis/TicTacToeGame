// TicTacToeGame.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>

#include"TicTacToeField.h"
#include"TicTacToeGame.h"

using namespace std;

auto zahlRowCol = 3;


int main(){

    string player1, player2;

    cout << "Bitte schreiben Sie das Name des erste Spieler =>  ";
    cin >> player1;

    cout << "Bitte schreiben Sie das Name des erste Spieler =>  ";
    cin >> player2 ;

    TicTacToeGame game(player1, player2);

    cout << game.getFieldStr() << endl;

    while (!game.isFinisched()) {

        cout << " Hey " << game.getCurrentPlayer() << " --->  Bitte gebe deine gewuenschte Position ein: " << endl;

        int row, col;

        cin >> row >> col;

        if (row >= zahlRowCol || col >= zahlRowCol) {

            cout << "Bitte geben Sie kleine Zahl als "<< zahlRowCol << endl;

        }
        else {

            game.play(row, col);

            cout << game.getFieldStr() << endl;

        }
    }

    cout << "Der Gewinner ist:  " << game.getWinner() << endl;


}
