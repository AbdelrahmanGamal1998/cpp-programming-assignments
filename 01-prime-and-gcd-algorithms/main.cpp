#include <bits/stdc++.h>
using namespace std;

/// fermat fpr prime
int power(int a, int n, int p)
{
    int res = 1;
    a = a % p;

    while (n > 0)
    {

        if (n & 1)
            res = (res*a) % p;


        n = n>>1;
        a = (a*a) % p;
    }
    return res;
}
int gcd(int a, int b)
{
    if(a < b)
        return gcd(b, a);
    else if(a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}
bool isPrime(unsigned int n, int k)
{

    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;


    while (k>0)
    {

        int a = 2 + rand()%(n-4);

        if (gcd(n, a) != 1)
            return false;


        if (power(a, n-1, n) != 1)
            return false;

        k--;
    }

    return true;
}


// school algorithm
bool isPrime2(int n)
{

    if (n <= 1)
        return false;


    for (int i=2; i<n; i++)
        if (n%i == 0)
            return false;

    return true;
}
/// trial divison
int TrialDivision(int N)
{

    int i = 2;
    int k = ceil(sqrt(N));
    while(i<= k)
    {
        if(N % i == 0)
            return 0;
        i += 1;
    }
    return 1;
}
////// millier algorthm
long long mul(long long a,long long b,long long c);

long long mod(long long a,long long b,long long c)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=mul(x,y,c);
        }
        y = mul(y,y,c);
        b /= 2;
    }
    return x%c;
}

long long mul(long long a,long long b,long long c)
{
    long long x = 0,y=a%c;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

int Miller(long long p,long long it)
{
    if(p<2)
    {
        return 0;
    }
    if(p!=2 && p%2==0)
    {
        return 0;
    }
    long long s=p-1;
    while(s%2==0)
    {
        s/=2;
    }
    long long i;
    for(i=0; i<it; i++)
    {
        long long a=rand()%(p-1)+1,tt=s;
        long long md=mod(a,tt,p);
        while(tt!=p-1 && md!=1 && md!=p-1)
        {
            md=mul(md,md,p);
            tt *= 2;
        }
        if(md!=p-1 && tt%2==0)
        {
            return 0;
        }
    }
    return 1;
}

//////////////////
//Euclidean algorithms gcd :
int gcd1(int a,int b)
{
    int R;
    while ((a % b) > 0)
    {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}
////////////////////////
//Stein’s Algorithm  GCD
int gcd2(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }
    while ((a & 1) == 0)
        a >>= 1;

    do
    {
        while ((b & 1) == 0)
            b >>= 1;

        if (a > b)
            swap(a, b);

        b = (b - a);
    }
    while (b != 0);


    return a << k;
}
////////////////
//recursive
int gcd3(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main()
{
    int k = 3;
    int N = 7;

    int p = TrialDivision(N);
    cout << " fermat algorithm to check prime number \n ";

    isPrime(11, k)?  cout << " true\n": cout << " false\n";


    cout << " School algorithm to check prime number \n ";

    isPrime2(11)?  cout << " true\n": cout << " false\n";

    cout << " trial Divison  algorithm to check prime number  \n";


    if(p)
        cout << ("Prime \n");
    else
        cout << ("not prime \n ");
/////////////////////////

    cout << " millier algorithm to check prime number \n";
    long long test, n;
    cout<<"\n";
    cout<<"please enter the number that you want to check ?"<<"\n";;
    scanf("%lld", &n);
    int fl = Miller(n, 20);
    if(fl)
        printf("YES number is Prime\n");
    else
        printf("NO Number is not Prime\n");


    cout << "and those are algorithms to find GCD \n";
    cout << "  Euclidean algorithms gcd  to find GCD \n ";
/////////////////////////////


    cout<<gcd1(2,4);
    cout<<"\n";
////////////////////
    cout << "  Stein’s Algorithm  GCD algorithms gcd  to find GCD \n ";
    int a = 2, b = 4;
    cout<<"\n";
    printf("Gcd of given numbers is %d\n", gcd2(a, b));





////////////////
    cout << "  Recursion  Algorithm  GCD algorithms gcd  to find GCD \n ";
    int a1, b1;
    cout<<"Enter the values of a and b: "<<endl;
    cin>>a1>>b1;
    cout<<"GCD of "<< a1 <<" and "<< b1 <<" is "<< gcd3(a, b);
    return 0;
    return 0;
}
