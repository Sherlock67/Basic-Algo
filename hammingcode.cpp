#include <bits/stdc++.h>
using namespace std;
#define bit 3
#define mod 10000007
void hammingcode(int N){
    int msg[] = {0,1,1,0};
    int r[bit], q[bit], s[bit], a[bit+1], b[bit+1];
    for(int i = bit;i>=0;i--){
        a[i] = msg[i];
    }
    r[0] = a[2] ^ a[1] ^ a[0];
    r[1] = a[3] ^ a[2] ^ a[1];
    r[2] = a[1] ^ a[0] ^ a[3];


     int err,n,m;
    for(int i=0;i<bit+1;i++)
        b[i]=a[i];
    for(int i=bit-1;i>=0;i--)
        q[i]=r[i];

    err=rand()%2;
    if(err==1)
    {
        n= rand()%bit+1;
        m= rand()%2;
        b[n]=m;
    }
    else
    {
        n= rand()%bit+1;
        m= rand()%2;
        q[n]=m;
    }

    s[0] = b[2] ^ b[1] ^ b[0] ^ q[0];
    s[1] = b[3] ^ b[2] ^ b[1] ^ q[1];
    s[2] = b[1] ^ b[0] ^ b[3] ^ q[2];


     cout<<"Sent Code Word: ";
    for(int i=bit;i>=0;i--)
        cout<<a[i];
    for(int i=bit-1;i>=0;i--)
        cout<<r[i];
    cout<<endl;

    cout<<"Received Code Word: ";
    for(int i=bit;i>=0;i--)
        cout<<b[i];
    for(int i=bit-1;i>=0;i--)
        cout<<q[i];
    cout<<endl;

    cout<<"Syndromes: ";
    for(int i=bit-1;i>=0;i--)
        cout<<s[i];
    cout<<endl;

    if(s[2]==0)
    {
        if(s[1]==0)
        {
            if(s[0]==0)
            {
                cout<<"No error"<<endl;
            }
            else
            {
                cout<<"Error in q0"<<endl;
            }
        }
        else
        {
            if(s[0]==0)
            {
                cout<<"Error in q1"<<endl;
            }
            else
            {
                cout<<"Error in b2"<<endl;
            }
        }
    }
    else
    {
        if(s[1]==0)
        {
            if(s[0]==0)
            {
                cout<<"Error in q2"<<endl;
            }
            else
            {
                cout<<"Error in b0"<<endl;
            }
        }
        else
        {
            if(s[0]==0)
            {
                cout<<"Error in b3"<<endl;
            }
            else
            {
                cout<<"Error in b1"<<endl;
            }
        }
    }
}
int main(){

    srand(time(0));
    for(int i=0;i<3;i++)
        hammingcode(i+1);
    return 0;
}




