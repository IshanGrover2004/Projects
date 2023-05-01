// Created by Ishan grover on 23-04-2023.
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//global variables declaration
int x,o;
int computer;
bool game=true;
string winner;
int choices;

//All function used in program
void welcome();
void print_board();
void x_turn();
void o_turn();
void result();


int main(){
    system("CLS");
    print_board();
    while(game){
        x_turn();
        if(game==false){break;}
        o_turn();
    }

    //system("CLS");        //clear the previous outputs
    return 0;
}


void welcome(){
    cout<<"\n\n\t\t\t\t\t  ***********************************\n";
    cout<<"\t\t\t\t\t\tT I C  -- T A C -- T O E\t\t\t\n";
    cout<<"\t\t\t\t\t  ***********************************\n";
    cout<<"\t\t\t\t\t\t     FOR 2 PLAYERS\n\t\t\t";
}

// Tic-Tac-Toe board structure defining
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

void print_board(){
    welcome();
    string space="     \t\t\t\t\t\t  ";
    string line="     \t\t\t\t\t\t_____|_____|_____";
    string newline="     \t\t\t\t\t\t     |     |";

    cout<<endl<<endl;
    cout << space << board[0] << "  |  " << board[1] << "  |  " << board[2] <<endl;
    cout<< line <<endl<<newline<<endl;
    cout << space << board[3] << "  |  " << board[4] << "  |  " << board[5] <<endl;
    cout<< line <<endl<<newline<<endl;
    cout << space << board[6] << "  |  " << board[7] << "  |  " << board[8] <<endl;
    cout<<endl<<endl;
    
}

void x_turn(){
    //input the x place
    cout<<"PLAYER 1(X) turn"<<endl;
    cout<<"Print value beetween 1-9: ";
    cin>>x;
    if(x<1 || x>9){
        cout<<"Write correct value"<<endl;
        x_turn();
    }
    
    //To assign the value of x in board
    if (board[x-1]=='X' || board[x-1]=='O'){        //if given x value is already assigned
        cout<<"Write correct value"<<endl;
        x_turn();
    }
    else{
        board[x-1]='X';
    }
    system("CLS");
    //print again board after turn
    print_board();
    result();
}

void o_turn(){
    //input the x place
    cout<<"PLAYER 2(O) turn"<<endl;
    cout<<"Print value beetween 1-9: ";
    cin>>o;
    if(o>9 || o<1){
        cout<<"Write correct value"<<endl;
        o_turn();
    }
    
    //To assign the value of x in board
    if (board[o-1]=='X' || board[o-1]=='O'){        //if given x value is already assigned
        cout<<"Write correct value"<<endl;
        o_turn();
    }
    else{
        board[o-1]='O';
    }
    system("CLS");
    //print again board after turn
    print_board();
    result();
}

void result(){
    cout<<endl;
    if(winner=="X wins" || winner=="O wins" || winner=="Draw"){
        game=false;
    }

    if(board[0]==board[1] && board[0]==board[2] && (board[0]=='X' || board[0]=='O')){
        (board[0]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[3]==board[4] && board[3]==board[5] && (board[3]=='X' || board[3]=='O')){
        (board[3]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[6]==board[7] && board[6]==board[8] && (board[6]=='X' || board[6]=='O')){
        (board[6]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[1]==board[4] && board[1]==board[7] && (board[1]=='X' || board[1]=='O')){
        (board[1]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[2]==board[5] && board[2]==board[8] && (board[2]=='X' || board[2]=='O')){
        (board[2]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[0]==board[3] && board[0]==board[6] && (board[0]=='X' || board[0]=='O')){
        (board[0]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[0]==board[4] && board[0]==board[8] && (board[0]=='X' || board[0]=='O')){
        (board[0]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[2]==board[4] && board[2]==board[6] && (board[2]=='X' || board[2]=='O')){
        (board[2]=='X')?(winner="X wins"):(winner="O wins");
        game=false;
        cout<<winner<<endl;
    }
    else if(board[0]!=' ' && board[1]!=' ' && board[2]!=' ' && board[3]!=' ' && board[4]!=' ' && board[5]!=' ' && board[6]!=' ' && board[7]!=' ' && board[8]!=' '){
        game=false;
        winner="Draw";
        cout<<winner<<endl;
    }
    else{
        game=true;
    }
    
}
