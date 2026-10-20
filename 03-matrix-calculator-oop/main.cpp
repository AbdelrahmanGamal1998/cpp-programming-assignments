#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

int main()
{
/*int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};

  Matrix mat1, mat2, mat3;
  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);

  //The next code will not work until you write the functions
cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
Matrix m1,m2;
bool w=1;
int x,y,z;
cin>>m1;
cout<<endl;
cin>>m2;
cout<<endl;
while(w==1){
cout<<"Press 1 to add/Press 2 to subtract/Press 3 to Multiply/Press 4 to add with scalar/Press 5 to subtract with scalar"<<endl;
cout<<"/Press 6 to multiply by scalar/Press 7 to transpose/Press 8 to check if square/Press 9 to check if identity/Press 10 to"<<endl;
cout<<" add same matrix/Press 11 to subtract same matrix/Press 12 to add with scalar/Press 13 to subtract with scalar /Press 14"<<endl;
cout<<"to add 1 to matrix/Press 15 to subtract 1 from matrix/Press 16 to check if equal/Press 17 to check if not equal/Press 18"<<endl;
cout<<"to check if symmetric"<<endl;
cout<<endl;
cin>>x;
switch(x)
{
case 1:
    cout<<m1+m2<<endl;
    break;
case 2:
    cout<<m1-m2<<endl;
    break;
case 3:
    cout<<m1*m2<<endl;
    break;
case 4:
    cout<<"If you want to add an integer to matrix one press 1, If you want to add an integer to matrix two press 2"<<endl;
    cin>>z;
    if(z==1)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        cout<<m1+y<<endl;
    }
    else if(z==2)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        cout<<m2+y<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 5:
    cout<<"If you want to subtract an integer from matrix one press 1, If you want to subtract an integer from matrix two press 2"<<endl;
    cin>>z;
    if(z==1)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        cout<<m1-y<<endl;
    }
    else if(z==2)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        cout<<m2-y<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 6:
    cout<<"If you want to multiply an integer by matrix one press 1, If you want to multiply an integer by matrix two press 2"<<endl;
    cin>>z;
    if(z==1)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        cout<<m1*y<<endl;
    }
    else if(z==2)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        cout<<m2*y<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 7:
    cout<<"If you want matrix one to be transposed press 1, If you want matrix two to be transposed press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        cout<<m1.transpose()<<endl;
    }
    else if(y==2)
    {
        cout<<m2.transpose()<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 8:
    cout<<"If you want to check if matrix one is square press 1, If you want to check if matrix two is square press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        cout<<m1.isSquare()<<endl;
    }
    else if(y==2)
    {
        cout<<m2.isSquare()<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 9:
    cout<<"If you want to check if matrix one is identity press 1, If you want to check if matrix two is identity press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        cout<<m1.isIdentity()<<endl;
    }
    else if(y==2)
    {
        cout<<m2.isIdentity()<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 10:
    cout<<"If you want to add matrix one to matrix two and save new value in matrix one press 1, If you want to add matrix two to matrix one and save new value in matrix two press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        m1+=m2;
        cout<<m1;
    }
    else if(y==2)
    {
        m2+=m1;
        cout<<m2;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 11:
    cout<<"If you want to subtract matrix one from matrix two and save new value in matrix one press 1, If you want to subtract matrix two from matrix one and save new value in matrix two press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        m1-=m2;
        cout<<m1;
    }
    else if(y==2)
    {
        m2-=m1;
        cout<<m2;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 12:
    cout<<"If you want to add an integer to matrix one press 1, If you want to add an integer to matrix two press 2"<<endl;
    cin>>z;
    if(z==1)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        m1+=y;
        cout<<m1;
    }
    else if(z==2)
    {
        cout<<"Enter integer to be added matrix"<<endl;
        cin>>y;
        m2+=y;
        cout<<m2;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 13:
    cout<<"If you want to subtract an integer from matrix one press 1, If you want to subtract an integer from matrix two press 2"<<endl;
    cin>>z;
    if(z==1)
    {
        cout<<"Enter integer to be subtracted matrix"<<endl;
        cin>>y;
        m1-=y;
        cout<<m1;
    }
    else if(z==2)
    {
        cout<<"Enter integer to be subtracted matrix"<<endl;
        cin>>y;
        m2-=y;
        cout<<m2;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 14:
    cout<<"If you want to perform on matrix one press 1, If you want to perform on matrix two press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        cout<<++m1<<endl;
    }
    else if(y==2)
    {
        cout<<++m2<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 15:
    cout<<"If you want to perform on matrix one press 1, If you want to perform on matrix two press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        cout<<--m1<<endl;
    }
    else if(y==2)
    {
        cout<<--m2<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
case 16:
    bool d;
    d=(m1==m2);
    cout<<d;
    break;
case 17:
    d=(m1!=m2);
    cout<<d;
    break;
case 18:
    cout<<"If you want to perform on matrix one press 1, If you want to perform on matrix two press 2"<<endl;
    cin>>y;
    if(y==1)
    {
        cout<<m1.isSymmetric()<<endl;
    }
    else if(y==2)
    {
        cout<<m2.isSymmetric()<<endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
    break;
default:
    cout<<"Error,Please enter number from 1 to 18"<<endl;
}
cout<<endl;
cout<<"Press 1 to preform another operation, Press 0 to exit"<<endl;
cin>>w;
}
    return 0;
}
