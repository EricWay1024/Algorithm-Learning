#include<bits/stdc++.h>
using namespace std;



// seive prime numbers
void seive(int n, bool prime[])
{
    for(int i=2; i<=n; i++)
        prime[i] = true;
    for(int p=2; p*p<=n; p++)
    {
        if(prime[p] == true)
        {
            for(int i=p*2; i<=n; i+=p)
                prime[i] = false;
        }
    }
}

// calculate the definite integral of a function
double calculate_integral(double a, double b, double h, double (*f)(double))
{
    double sum = 0;
    for(double x=a; x<=b; x+=h)
        sum += f(x);
    return sum;
}



int main() {
    // output every prime numbers less than or equal to 1e5
    int n = 100000;
    bool prime[n+1];
    seive(n, prime);
    for(int i=2; i<=n; i++)
        if(prime[i])
            cout << i << " ";
}    