#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define ll long long
#define M 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii pair< int,int >
#define pll pair< ll,ll >
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define vii vector<pii>
#define vll vector<pll>
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout)
#define endc "\n"
#define MAX 100003
#define N 10003

using namespace std;

vi prime;
// int ans[N];
// unordered_set<ll>ans;
// prime numbers till n
void prime_numbers(int n) 
{
    vector<bool>primes(n+1,true);
    f(i,2,n+1)
    {
        if(primes[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                primes[j] = false;
            }
        }
    }
    f(i,2,n+1){
        if(primes[i])prime.pb(i);
    }
}

//calculate smallest prime factor for every number
vi spf(MAX);
void find_spf()
{
    // make every number's spf equal to itself
    f(i,1,MAX)spf[i] = i;

    //make even number's spf to 2
    for(int i=2;i<=MAX;i+=2){
        spf[i] = 2;
    }

    for(int i=3;i<=MAX;i+=2)
    {
        //check if i is prime
        if(spf[i] == i)
        {
            for(int j=i*i;j<=MAX;j+=i)
            {
                if(spf[j] == j)spf[j] = i;
            }
        }
    }
    
}

void swap1(int* x,int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        // set<int>s1,s2;
        vi x(n+1),y(n+1);
        f(i,1,n+1){
            cin>>x[i]>>y[i];
            // s1.insert(x[i]);
            // s2.insert(y[i]);
        }
        sort(all(x));
        sort(all(y));

        if(n&1){
            cout<<1<<endl;
            continue;
        }
        ll cnt1 = 0,cnt2= 0;
        cnt1 = abs(x[n/2+1]-x[n/2])+1;
        cnt2 = abs(y[n/2+1]-y[(n)/2])+1;

        cout<<1LL*cnt1*cnt2<<endl;
    }
    // to find the ceil of x/y  ===>>> (x+y-1)/y
    // Always take each variable long long
    
    // If first condition satisfies then the compiler
    // won't go to the other condition
  
    return 0;
}