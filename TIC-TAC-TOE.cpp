// Created by Ishan grover on 23-04-2023.
#include <iostream>
using namespace std;


int x,o;

// Tic-Tac-Toe board structure defining
char board[9]={'1','2','3','4','5','6','7','8','9'};

void print_board(){
    string space="\t\t\t\t\t\t  ";
    string line="\t\t\t\t\t\t_____|_____|_____";
    string newline="\t\t\t\t\t\t     |     |";

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
    if(x>9 || x<1){
        x_turn();
    }
    
    //To assign the value of x in board
    if (board[x-1]=='X' || board[x-1]=='O'){        //if given x value is already assigned
        x_turn();
    }
    else{
        board[x-1]='X';
    }

    //print again board after turn
    print_board();
}


void o_turn(){
    //input the x place
    cout<<"PLAYER 2(O) turn"<<endl;
    cout<<"Print value beetween 1-9: ";
    cin>>o;
    if(o>9 || o<1){
        o_turn();
    }
    
    //To assign the value of x in board
    if (board[o-1]=='X' || board[o-1]=='O'){        //if given x value is already assigned
        o_turn();
    }
    else{
        board[o-1]='O';
    }

    //print again board after turn
    print_board();
}


string result(){
    if(board[0]==board[1] && board[1]==board[2]){
        (board[0]=='X')?(winner="X wins"):(winner="O wins");
    }
    else if(board[3]==board[4] && board[3]==board[5]){
        (board[3]=='X')?(winner="X wins"):(winner="O wins");
    }
    else if(board[6]==board[7] && board[6]==board[8]){
        (board[6]=='X')?(winner="X wins"):(winner="O wins");
    }
    else if(board[1]==board[4] && board[1]==board[7]){
        (board[1]=='X')?(winner="X wins"):(winner="O wins");
    }
    else if(board[2]==board[5] && board[2]==board[8]){
        (board[2]=='X')?(winner="X wins"):(winner="O wins");
    }
    else if(board[3]==board[6] && board[3]==board[9]){
        (board[3]=='X')?(winner="X wins"):(winner="O wins");
    }
    else if(board[1]==board[5] && board[1]==board[9]){
        (board[1]=='X')?(winner="X wins"):(winner="O wins");
    }
    else if(board[3]==board[5] && board[3]==board[7]){
        (board[3]=='X')?(winner="X wins"):(winner="O wins");
    }
    else{
        winner="Draw";
    }
    return winner;
}


int main(){
    cout<<"\n\n\t\t\t  ***********************************\n";
    cout<<"\t\t\t\tT I C  -- T A C -- T O E\t\t\t\n";
    cout<<"\t\t\t  ***********************************\n";
    cout<<"\t\t\t\t     FOR 2 PLAYERS\n\t\t\t";
    
    // print_board();
    // x_turn();
    // o_turn();
    // x_turn();
    // o_turn();
    // x_turn();
    // o_turn();
    // cout<<result();
    // result();
    return 0;
}
