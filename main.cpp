#include <iostream>
#include <stdlib.h>

using namespace std;


class player
{   private :
        int player_wins=0;
        char player_symbol;
        string player_name;


    public :

        void display_name()
        {
            cout<<player_name;
        }
        void getPdata()
        {
            cout<<"Enter the player Name :\n";
            cin>>player_name;
            cout<<"Choose your symbol :\n";
            cin>>player_symbol;
            cout<<"\n------the player id and name has successfully been entered------\n\n\n\n";
        }
        void showPdata()
        {
            cout<<"Name : "<<player_name<<endl;
            cout<<"wins : "<<player_wins<<endl;
            cout<<"-------------------------------";
        }
        void winUpdate()
        {
            player_wins++;
        }

        int wins()
        {
            return player_wins;
        }

    friend class table;

};

class table
{
    private :
        char board[3][3];
        int locID;
        int arr[9]={0};
 
    public :

        void ResetAll()
        {
            for(int i=0; i<9; i++)
                arr[i]=0;
        }

        void clearQuitCheck()
        {
            char ch;
            cout<<"\nEnter Y to Proceed or Q to Quit\n";
            cin>>ch;
            if(ch=='Y' || ch=='y')
                system("clear");
            else if(ch=='Q'|| ch=='q')
                exit(0);
            else
            {
                cout<<"Invalid Option\n";
                clearQuitCheck();
            }
        }
       
        void showloctable()
        { 
            int p=1;
            cout<<"\nLOCATION TABLE\n";
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<" "<<p<<" ";
                    p++;
                    if(j!=2)
                        cout<<"|";
                }
                cout<<endl;
                for(int k=0;k<3;k++)
                {
                    if(i!=2)
                    {
                        cout<<"___ ";
                    }
                }
                cout<<endl;
            }
        }

        void reset()
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                    board[i][j]=' ';
            }
        }

        void check_draw()
        {
            int sum=0;
            for(int i=0;i<9;i++)
                sum=sum+arr[i];

            if(sum==9)
            {
                cout<<"\nGAME OVER\n\n";
                cout<<" It's a DRAW :-} :-} \n\n";
                exit(0);
            }
            else
                return;
        }
        int rowcheck()
        {
            int flag;
            for(int i=0;i<3;i++)
            {
                if((board[i][0]==board[i][1])&&(board[i][1]==board[i][2])&&(board[i][0]!=' ')&&(board[i][1]!=' ')&&(board[i][2]!=' '))
                {
                   flag=1;
                   break;
                }
                else
                    flag=0;
            }
            return flag;
        }

        int colcheck()
        {
            int flag;
            for(int j=0;j<3;j++)
            {
                if((board[0][j]==board[1][j])&&(board[1][j]==board[2][j])&&(board[0][j]!=' ')&&(board[1][j]!=' ')&&(board[2][j]!=' '))
                {
                    flag=1;
                    break;
                }
                else
                    flag=0;
            }
            return flag;
        }

        int diagcheck()
        {
            int flag;
            if((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&(board[0][0]!=' ')&&(board[1][1]!=' ')&&(board[2][2]!=' '))
            {
                flag=1;
            }
            else if((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])&&(board[0][2]!=' ')&&(board[1][1]!=' ')&&(board[2][0]!=' '))
            {
               flag=1;
            }
            else
                flag=0;

            return flag;
        }

        void matInput(player *P)
        {
            cout<<"Enter the location you want to put your symbol :";
            cin>>locID;

            if(locID<=9 && locID>0)
            {
                if(arr[locID-1]==0)
                {
                    int counter=1;
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(locID==counter)
                            {
                                board[i][j]=P->player_symbol;
                            }
                            counter++;
                        }
                    }
                    arr[locID-1]=1;
                }
                else
                {
                    cout<<"\n\nThe location has already been filled :\\\n TRY AGAIN\n\n";
                        matInput(&*P);
                }

            }
            else
            {
                cout<<"====invalid input location====\n";
                    matInput(&*P);
            }
            system("clear");
            return;
        }

        void showtable()
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<" "<<board[i][j]<<" ";
                    if(j!=2)
                        cout<<"|";
                }
                cout<<endl;
                for(int k=0;k<3;k++)
                {
                    if(i!=2)
                    {
                        cout<<"___ ";
                    }
                }
                cout<<endl;
            }
        }

};





int main()
{
    player p1,p2;
    table t;
    int over=9;
    system("clear");
    cout<<"\n\n===========================$$ WELCOME TO THE GAME $$============================\n";
    cout<<"                                  TIC TAC TOE\n\n\n\n";
    cout<<"Enter the details of first player >\n";
    p1.getPdata();

    cout<<"Enter the details of second player >\n";
    p2.getPdata();

    int game_type=0, game_rounds=0, invalid_input=0;
    do{
        cout<<"====Choose Game format===="<<endl
        <<"1. One Round battle"<<endl
        <<"2. Best of three"<<endl
        <<"3. custom mode"<<endl
        <<"Enter you option: ";
        cin>>game_type;
        switch(game_type)
        {
            case 1:
                game_rounds=1;
                invalid_input=0;
                break;
            case 2:
                game_rounds=3;
                invalid_input=0;
                break;
            case 3:
                cout<<"Enter the nuber of Rounds "<<endl;
                cin>>game_rounds;
                invalid_input=0;
                break;

            default:
                cout<<"Invalid input";
                invalid_input=1;
        }
    }while(invalid_input==1);
    
    system("clear");

    for(int i=0; i<game_rounds; i++)
    {   
        cout<<endl; 
        t.clearQuitCheck();

        cout<<"==================**GAME BEGINS**==================\n";
        cout<<"\nROUND "<<i+1<<" Begins\n\n";
        t.showloctable();
        t.reset();
        cout<<"\n\n\n";
        t.showtable();
        int r_check,c_check,d_check;
        while(over!=0)
        {
            cout<<"Player 1|";p1.display_name();cout<<endl;
            t.matInput(&p1); 
            t.showloctable();
            cout<<"\n\n\n";
            t.showtable();
            r_check=t.rowcheck();
            c_check=t.colcheck();
            d_check=t.diagcheck();
            if(r_check==1 || c_check==1 || d_check==1)
            {
                cout<<"\nGAME OVER\n\n";
                p1.display_name();
                cout<<" WON the game\n\n\n\n";
                p1.winUpdate();
                over=0;
                continue;
            }
            else
                t.check_draw();



            cout<<"Player 2|";p2.display_name();cout<<endl;
            t.matInput(&p2);
            t.showloctable();
            cout<<"\n\n\n";
            t.showtable();
            r_check=t.rowcheck();
            c_check=t.colcheck();
            d_check=t.diagcheck();
            if(r_check==1 || c_check==1 || d_check==1)
            {
                cout<<"\nGAME OVER\n\n";
                p2.display_name();
                cout<<" WON the game\n\n\n\n";
                p2.winUpdate();
                over=0;
            }
            else
                t.check_draw();

        }
        over=1;
        cout<<"Current game points: "<<endl;
        p1.showPdata();
        cout<<endl;
        p2.showPdata();

        t.ResetAll();                       //reset all the "set" locations of the table for new round
    }
    cout<<"\n\n";
    if(p1.wins() > p2.wins())
    {
        p1.display_name();cout<<" is the finall WINNER of this Battle"<<endl;
    }

    else if(p1.wins() == p2.wins())
    {
        cout<<"It's a DRAW"<<endl;
    }
    
    else
    {
        p2.display_name();cout<<" is the finall WINNER of this Battle"<<endl;
    }

    return 0;
}
