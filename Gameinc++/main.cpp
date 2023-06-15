#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void border(char *);
void frontView();
void gamePlay1(char *);
void gamePlay2(char *);
void computerPlay(char *);
void startGame(char *,int);
int gameRule(char *,int,int);
int checkValue(char *,int);
int checkPlayers();

//MANUPULATE THE GAME TO PLAY 1VS1 AND 1VSCOMPUTER (SOLO);
//MANUPULATE THE GAME TO PLAY CHOICE BASED SYMBOLS;

int main()
{

    char choice='n';
    do
    {
        int temp;
        char arr[9] = {'1','2','3','4','5','6','7','8','9'};
        temp = checkPlayers();
        system("cls");
        frontView();
        border(arr);
        startGame(arr,temp);
        cout<<endl<<endl;
        cout<<"DO YOU WANT TO PLAY AGAIN(Y/N): ";
        cin>>choice;
        system("cls");
    }while(choice=='y' || choice=='Y');
    return 0;
}

void frontView()
{
    cout<<endl;
    cout<<"Welcome To The Tik Tak Toe Game"<<endl;
    cout<<"Symbol for Player 1 is X"<<endl;
    cout<<"Symbol for Player 2 is O"<<endl;
}


void border(char *p)
{
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t"<<"     |    |   "<<endl;
    cout<<"\t"<<"   "<<p[0]<<" |"" "<<p[1]<<"  | "<<p[2]  <<endl;
    cout<<"\t"<<" ----|----|----"<<endl;
    cout<<"\t"<<"     |    |   "<<endl;
    cout<<"\t"<<"   "<<p[3]<<" |"" "<<p[4]<<"  | "<<p[5]  <<endl;
    cout<<"\t"<<" ----|----|----"<<endl;
    cout<<"\t"<<"     |    |   "<<endl;
    cout<<"\t"<<"   "<<p[6]<<" |"" "<<p[7]<<"  | "<<p[8]  <<endl;
}

void gamePlay1(char *p)
{
    int p1,temp=0;
    cout<<endl;
    do
    {
        cout<<endl;
        cout<<"Enter position Player 1:";
        cin>>p1;
        temp=checkValue(p,p1);
    }while(temp==0);
    p[p1-1]='X';

}



void gamePlay2(char *p)
{
    int p2,temp=0;
    cout<<endl;
    do
    {
        cout<<endl;
        cout<<"Enter position Player 2:";
        cin>>p2;
        temp=checkValue(p,p2);
    }while(temp==0);
    p[p2-1]='O';

}

void computerPlay(char *p)
{
    int p2,temp=0;
    cout<<endl;
    do
    {
        cout<<endl;
        cout<<"Position Entered by computer :";
        srand(time(NULL));
        p2 = ((rand() %(9 - 1 + 1)) + 1);
        temp=checkValue(p,p2);
    }while(temp==0);
    cout<<p2<<endl;
    Sleep(2000);
    p[p2-1]='O';

}

void startGame(char *p,int k)
{
    int i,j;
    for(i=1;i<10  && k == 1;i++)
    {
        if(i%2!=0)
        {
            gamePlay1(p);
            system("cls");
            j=gameRule(p,i,k);
            if(j==0 || j==1)
                break;
            frontView();
            border(p);
        }
        else
        {
            gamePlay2(p);
            system("cls");
            j=gameRule(p,i,k);
            if(j==0 || j==1)
                break;
            frontView();
            border(p);
        }
    }

    for(i=1;i<10 && k == 2;i++)
    {
        if(i%2!=0)
        {
            gamePlay1(p);
            system("cls");
            j=gameRule(p,i,k);
            if(j==0 || j==1)
                break;
            frontView();
            border(p);
        }
        else
        {
            computerPlay(p);
            system("cls");
            j=gameRule(p,i,k);
            if(j==0 || j==1)
                break;
            frontView();
            border(p);
        }
    }
}

int gameRule(char *p, int j,int temp)
{
    if((p[0]==p[1] && p[1]==p[2]) ||
       (p[3]==p[4] && p[4]==p[5]) ||
       (p[6]==p[7] && p[7]==p[8]) ||
       (p[0]==p[3] && p[3]==p[6]) ||
       (p[1]==p[4] && p[4]==p[7]) ||
       (p[2]==p[5] && p[5]==p[8]) ||
       (p[0]==p[4] && p[4]==p[8]) ||
       (p[2]==p[4] && p[4]==p[6])
       )
    {
        if(j%2 ==0 && temp == 2)
        {
            cout<<endl;
            cout<<"CONGRATULATION! COMPUTER WON THE MATCH";
            return 0;
        }
        else if(j%2!=0 || temp == 2)
        {
           cout<<endl;
            cout<<"CONGRATULATION! PLAYER 1 WON THE MATCH";
            return 0;
        }
        else
        {
            cout<<endl;
            cout<<"CONGRATULATION! PLAYER 2 WON THE MATCH";
            return 0;
        }
    }
    else if(j==9)
    {
        cout<<endl;
        cout<<"........... MATCH TIE ..........";
        return 1;
    }
    return 5;
}

int checkValue(char *p,int i)
{
    if(i>=1 && i<=9)
    {
        if(p[i-1]=='X' || p[i-1]=='O')
        {
        cout<<endl;
        cout<<"Sorry! THIS PLACE IS CHOISEN BY THE PLAYER PLEASE WAIT.";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".";
        Sleep(500);
        cout<<".";
        Sleep(500);
        system("cls");
        frontView();
        border(p);
        return 0;
        }
        else
            return 1;

    }
    else
    {
        cout<<endl;
        cout<<"PLEASE ENTER A VALID POSITION"<<endl;
        system("pause");
        system("cls");
        frontView();
        border(p);
        cin.clear();
        cin.ignore(30,'\n');
        return 0;
    }
}


int checkPlayers()
{
    int choice,temp=1;
    while(temp)
    {
        cout<<"Select an option:"<<endl;
        cout<<"1.Player vs player"<<endl;
        cout<<"2.player vs computer"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.clear();
        cin.ignore(10,'\n');
        if(choice == 1 || choice == 2)
        {
            temp = 0;
            return choice;
        }

        else
        {
            cout<<endl<<endl;
            cout<<"PLEASE ENTER A VALID INPUT......."<<endl;
            system("pause");
            system("cls");
        }
    }
    return 0;
}


//int printRandoms(int lower, int upper,int count)
//{
//	int i,num;
//	//
//		 num = (rand() %
//		(upper - lower + 1)) + lower;
//
//
//	//}
//	cout<<num<<endl;
//	return num;
//}
