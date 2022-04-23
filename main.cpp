#include <iostream>

using namespace std;
bool Insert(char board[6][7], int column,int i)
{
    if(board[i][column]!='-')
    {
        return false;
    }
    else
        return true;
}

int iswinning(char board[6][7],char sympol)
{
    int x;
    x=0;
    for(int i=6; i>=1; i--)
    {
        for(int column=7; column>=1; column--)
        {
            if(board[i][column]== sympol &&
                    board[i][column+1]==sympol &&
                    board[i][column+2]==sympol &&
                    board[i][column+3]==sympol)
            {
                x=1;
            }
            if(board[i][column]==sympol &&
                    board[i][column-1]==sympol &&
                    board[i][column-2]==sympol &&
                    board[i][column-3]==sympol)
            {
                x=1;
            }
            if(board[i][column]==sympol &&
                    board[i-1][column]==sympol &&
                    board[i-2][column]==sympol &&
                    board[i-3][column]==sympol)
            {
                x=1;
            }
            if(board[i][column]==sympol &&
                    board[i-1][column-1]==sympol &&
                    board[i-2][column-2]==sympol &&
                    board[i-3][column-3]==sympol)
            {
                x=1;
            }
            if(board[i][column]==sympol &&
                    board[i-1][column+1]==sympol &&
                    board[i-2][column+2]==sympol &&
                    board[i-3][column+3]==sympol)
            {

                x=1;
            }
        }
    }
    return x;
}

void Print(char board[6][7])
{
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<7; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    int k=0,r=0;
    char board[6][7] ;
    int column,b=6;
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<7; j++)
        {
            board[i][j]='-';
        }
    }

    Print( board);
    for(int a=0; a>=0; a++)
    {
        if(a%2==0)
        {

            while (true)
            {
                b=6;
                cin>>column;
                while(column<0 || column>6 )
                {
                    cout<<"enter valid colum"<<endl;
                    cin>>column;
                }
                Insert( board,  column, b);
                if(Insert( board,  column, b)==true)
                {
                    board[b][column]='X';
                }
                else
                {
                    while(board[b][column]!='-' && b>=0)
                    {
                        b--;
                        if(board[b][column]=='-')
                        {
                            board[b][column]='X';
                            break;
                        }
                        if(b<0)
                        {
                            cout<<"this colum is full"<<endl;
                            k++;
                        }
                    }

                    if(k!=0)
                    {
                        k--;
                        continue;
                    }
                    else
                        break;
                }
            }

            Print( board);
            iswinning(board,'X');
            if(iswinning(board,'X')==1)
            {
                cout<<"first player wins";
                break;
            }
        }
        else
        {

            while(true)
            {
                int y=6;
                cin>>column;
                while(column<0 || column>6)
                {
                    cout<<"enter valid colum"<<endl;
                    cin>>column;
                }
                Insert( board,  column, y);
                if(Insert( board,  column, y)==true)
                {
                    board[y][column]='O';
                }
                else
                {
                    while(board[y][column]!='-' && y>=0)
                    {
                        y--;
                        if(board[y][column]=='-')
                        {
                            board[y][column]='O';
                            break;
                        }

                        if(y<0)
                        {
                            cout<<"this colum is full"<<endl;
                            r++;
                        }
                    }
                    if(r!=0)
                    {
                        r--;
                        continue;
                    }
                    else
                        break;
                }
            }
            Print( board);
        }

        iswinning(board,'O');
        if(iswinning(board,'O')==1)
        {
            cout<<"second player wins";
            break;
        }
    }

    return 0;
}
