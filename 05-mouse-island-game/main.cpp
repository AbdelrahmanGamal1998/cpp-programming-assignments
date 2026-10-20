#include <iostream>
#include <string>
#include <cstdlib>
#include<windows.h>
using namespace std;



string arr [23][45];
int z;int r;int c;
int mouse1=12,mouse2=23;
int sunk=0;int eaten=0;int escaped=0;int starved=0;




  int number1, number2;

void mouse(int number1,int number2 ,int a,int t){
    int x;

    for(int counter=1;counter<=100;counter++){
        if(counter==100){
            starved++;
        }
        x=rand()%4;


        switch(x){
        case 0:
   system("cls");
    arr[number1][number2]={char(32)};
    number1=number1+1;
    arr[number1][number2]={'*'};

    for (int r=0 ; r<23 ;r++){
    cout<<endl;
    for(int c=0; c<45 ; c++){
        cout<<arr[r][c];
    }
}


cout<<endl;


    if (number1==12 && number2==44){

            cout<<"you escaped!!"<<endl;

            escaped++;
            r=101;

        }
        else if(number2==t && number1==a){

            cout<<"you got eaten by a cat"<<endl;

            eaten++;
            r=101;

            }

            else if(number1==0 || number1==22){

                cout<<"game over"<<endl;

                sunk++;
                r=101;
            }

            else if(number2==0 || number2==44){
                cout<<"game over"<<endl;

                sunk++;
                r=101;
            }


            break;


case 1:
    system("cls");
    arr[number1][number2]={char(32)};
    number2=number2+1;
    arr[number1][number2]={'*'};

    for (int r=0 ; r<23 ;r++){
    cout<<endl;
    for(int c=0; c<45 ; c++){
        cout<<arr[r][c];
    }
}
cout<<endl;
    if (number1==12 && number2==44){

            cout<<"you escaped!!"<<endl;

            escaped++;
            r=101;

        }
        else if(number2==t && number1==a){

            cout<<"you got eaten by a cat"<<endl;

            eaten++;
            r=101;

            }
            else if(number1==0 || number1==22){

                cout<<"game over"<<endl;

                sunk++;
                r=101;
            }
            else if(number2==0 || number2==44){

                cout<<"game over"<<endl;
                Sleep(1000);
                sunk++;
                r=101;
            }
break;

case 2:
    system("cls");
    arr[number1][number2]={char(32)};
    number1=number1-1;
    arr[number1][number2]={'*'};
    Sleep(10);
    for (int r=0 ; r<23 ;r++){
    cout<<endl;
    for(int c=0; c<45 ; c++){
        cout<<arr[r][c];
    }
}
cout<<endl;
    if (number1==12 && number2==44){

            cout<<"you escaped!!"<<endl;

            escaped++;
            r=101;

        }
        else if(number2==t && number1==a){

            cout<<"you got eaten by a cat"<<endl;

            eaten++;
            r=101;

            }
            else if(number1==0 || number1==22){

                cout<<"game over"<<endl;

                sunk++;
                r=101;
            }
            else if(number2==0 || number2==44){

                cout<<"game over"<<endl;

                sunk++;
                r=101;
            }
    break;
case 3:
    system("cls");
    arr[number1][number2]={char(32)};
    number2=number2-1;
    arr[number1][number2]={'*'};

    for (int r=0 ; r<23 ;r++){
    cout<<endl;
    for(int c=0; c<45 ; c++){
        cout<<arr[r][c];
        }
    }
    cout<<endl;
    if (number1==12 && number2==44){

            cout<<"you escaped!!"<<endl;

            escaped++;
            r=101;

        }
        else if(number2==t && number1==a){

            cout<<"you got eaten by a cat"<<endl;

            eaten++;
            r=101;

            }
            else if(number1==0 || number1==22){

                cout<<"game over"<<endl;

                sunk++;
                r=101;
            }
            else if(number2==0 || number2==44){

                cout<<"game over"<<endl;

                sunk++;
                r=101;
            }
    break;
    }
}
}








int main()
{
    cout<<"hello dear ,welcome to our tom and jerry game "<<endl;
    cout<<"how many many times do you want to play ?"<<endl;
    cin>>z;
    for(int r=0;r<z;r++){
        system("cls");


    //upper line
  for(int r=0;r<1;r++){
    for(int c=0;c<=45;c++){
     arr[r][c] =char(219);

    }
  }
  //lower line
for(int r=22;r<23;r++){
    for(int c=0;c<45;c++){
        arr[r][c]=char(219);
    }
}
//left line
for(int c=0;c<1;c++){
    for(int r=0;r<23;r++){
        arr[r][c]=char(219);
    }
}
    //right line
 for(int c=44;c<45;c++){
    for(int r=0;r<23;r++){
        arr[r][c]=char(219);
    }
 }
// blanke of water
for(int r=1;r<22;r++){
    for(int c=1;c<44;c++){
        arr[r][c]=char(32);
    }
}

arr[12][44]={char(175)};//bridge
arr[12][23]={'*'};//mouse
int i ;int j ;//cat
i=rand()%19;
j=rand()%40;
arr[i][j]={'+'};


//final cout for the arr
for(int r=0;r<23;r++){
    cout<<endl;
    for(int c=0;c<45;c++){
        cout<<arr[r][c];
    }

}

 Sleep(1000);
mouse(mouse1,mouse2,j,i);
    }

    cout<<"jerry has died from starving "<<starved<< " times"<<endl;
     cout<<" jerry has died from the water "<<sunk<< " times"<<endl;
      cout<<"you escaped "<<escaped<< " times"<<endl;
       cout<<"you eaten "<<eaten<< " times"<<endl;


       Sleep(200000000);

    return 0;
}
