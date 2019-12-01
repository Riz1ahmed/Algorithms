///Full instruction at bottom
///AC sub: codeforces.com/problemsets/acmsguru/submission/99999/66034902
///Tested: codeforces.com/contest/1263/submission/66026737
#include<bits/stdc++.h>
using ll=long long int;
using namespace std;

struct Bigint {
    string a;
    int sign;

    Bigint() {}
    void operator = (string b) {
        a= (b[0]=='-' ? b.substr(1) : b);
        reverse(a.begin(), a.end());
        (*this).Remove0(b[0]=='-' ? -1 : 1);
    }
    Bigint(string x) {(*this)=x;}
    Bigint(ll x) {(*this)=to_string(x);}
    void operator = (ll x){*this=to_string(x);}

    char operator[](int i){return a[i];}
    int size() {return a.size();}
    Bigint inverseSign() {sign*=-1; return (*this);}

    Bigint Remove0(int newSign) {
        sign = newSign;
        for(int i=a.size()-1; i>0 && a[i]=='0'; i--) a.pop_back();
        if(a.size()==1 && a[0]=='0') sign=1;
        return (*this);
    }

    bool operator == (Bigint x) {return sign==x.sign && a==x.a;}
    bool operator == (string x) {return *this==Bigint(x);}
    bool operator == (ll x)     {return *this==Bigint(x);}

    bool operator != (Bigint x) {return !(*this==x);}
    bool operator != (string x) {return !(*this==x);}
    bool operator != (ll x)     {return !(*this==x);}

    bool operator < (Bigint b) {
    	if (sign!=b.sign) return sign<b.sign;
        if(a.size()!=b.size()) return a.size()*sign<b.size()*sign;
        for(int i=a.size()-1; i>=0; i--)
			if(a[i] != b[i]) return a[i]<b[i];
        return false;
    }
    bool operator < (string x) {return *this<Bigint(x);}
    bool operator < (ll x)     {return *this<Bigint(x);}

    bool operator <= (Bigint b) {return *this==b || *this<b;}
    bool operator <= (string b) {return *this==b || *this<b;}
    bool operator <= (ll b)     {return *this==b || *this<b;}

    bool operator > (Bigint b) {return !(*this==b || *this<b);}
    bool operator > (string x) {return !(*this==x || *this<x);}
    bool operator > (ll b)     {return !(*this==b || *this<b);}

	bool operator >= (Bigint b) {return *this==b || *this>b;}
    bool operator >= (string b) {return *this==b || *this>b;}
    bool operator >= (ll b)     {return *this==b || *this>b;}

    Bigint operator + (Bigint b) {
        if(sign != b.sign) return (*this)-b.inverseSign();
        Bigint sum;
        for(int i=0, carry=0; i<a.size() || i<b.size() || carry; i++){
			if (i<a.size()) carry+=a[i]-'0';
			if (i<b.size()) carry+=b[i]-'0';
            sum.a += (carry % 10 + 48);
            carry /= 10;
        }
        return sum.Remove0(sign);
    }
    Bigint operator + (string x) {return *this+Bigint(x);}
    Bigint operator + (ll x)     {return *this+Bigint(x);}
    Bigint operator ++ (int) {*this+=1; return *this-1;}
    Bigint operator ++ ()    {*this+=1; return *this;}
    void operator += (Bigint x) {*this = *this+x;}
    void operator += (string x) {*this = *this+x;}
    void operator += (ll x)     {*this = *this+x;}


    Bigint operator - ( Bigint b ) {
        if(sign != b.sign) return (*this)+b.inverseSign();
        if(*this < b) return (b - *this).inverseSign();
        Bigint sub;
        for(int i=0,borrow=0; i<a.size(); i++) {
            borrow = a[i]-borrow-(i<b.size() ? b.a[i] : '0');
            sub.a += borrow>=0 ? borrow+'0' : borrow + 58;
            borrow = borrow>=0 ? 0:1;
        }
        return sub.Remove0(sign);
    }
    Bigint operator - (string x) {return *this-Bigint(x);}
    Bigint operator - (ll x)     {return *this-Bigint(x);}
    Bigint operator -- (int) {*this-=1; return *this+1;}
    Bigint operator -- ()    {*this-=1; return *this;}
    void operator -= (Bigint x) {*this = *this-x;}
    void operator -= (string x) {*this = *this-x;}
    void operator -= (ll x)     {*this = *this-x;}

    Bigint operator * (Bigint b) {
        Bigint mult("0");
        for(int i=0, k=a[i]; i<a.size(); i++, k=a[i]) {
            while(k-- -'0') mult=mult+b;
            b.a.insert(b.a.begin(),'0');
        }
        return mult.Remove0(sign * b.sign);
    }
    Bigint operator * (string x) {return *this*Bigint(x);}
    Bigint operator * (ll x)     {return *this*Bigint(x);}
    void operator *= (Bigint x) {*this = *this*x;}
    void operator *= (string x) {*this = *this*x;}
    void operator *= (ll x)     {*this = *this*x;}

    Bigint operator / (Bigint b) {
        if(b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0');
        Bigint c("0"), d;
        for(int j=0; j<a.size(); j++) d.a += "0";
        int dSign = sign*b.sign; b.sign=1;
        for(int i=a.size()-1; i>=0; i--) {
            c.a.insert(c.a.begin(),'0');
            c=c+a.substr(i,1);
            while(!(c<b)) c=c-b, d.a[i]++;
        }
        return d.Remove0(dSign);
    }
    Bigint operator / (string x) {return *this/Bigint(x);}
    Bigint operator / (ll x)     {return *this/Bigint(x);}
    void operator /= (Bigint x) {*this = *this/x;}
    void operator /= (string x) {*this = *this/x;}
    void operator /= (ll x)     {*this = *this/x;}

    Bigint operator % (Bigint b) {
        if( b.size()==1 && b[0]=='0') b.a[0]/=(b[0]-'0') ;
        Bigint c("0");
        int cSign = sign*b.sign; b.sign=1;
        for( int i=a.size()-1; i>=0; i-- ) {
            c.a.insert( c.a.begin(),'0');
            c = c+a.substr(i,1);
            while(!(c<b)) c=c-b;
        }
        return c.Remove0(cSign);
    }
    Bigint operator % (string x) {return *this%Bigint(x);}
    Bigint operator % (ll x)     {return *this%Bigint(x);}
    void operator %= (Bigint x) {*this = *this%x;}
    void operator %= (string x) {*this = *this%x;}
    void operator %= (ll x)     {*this = *this%x;}

    void print() {
        if(sign==-1) putchar('-');
        for(int i=a.size()-1; i>=0; i--) putchar(a[i]);
    }

    friend istream& operator >>(istream &in,Bigint &x){
        string s;
        in>>s;
        x=s;
        return in;
    }
    friend ostream& operator <<(ostream &out,Bigint &x){
        if(x.sign==-1) putchar('-');
        for(int i=x.size()-1; i>=0; i--)
            putchar(x[i]);
        return out;
    }

    friend Bigint pow(Bigint base,Bigint pw){
        Bigint ans=1;
        while(pw!=0){
        	if(pw%2 !=0) ans*=base;
			base*=base, pw/=2;
		}
        return ans;
    }
    friend Bigint pow(Bigint a, Bigint b,Bigint mod) {
        if (b==0) return Bigint(1);
        Bigint tmp=pow(a,b/2,mod);
        if ((b%2)==0) return (tmp*tmp)%mod;
        else return (((tmp*tmp)%mod)*a)%mod;
    }
    friend Bigint sqrt(Bigint x) {
        Bigint ans=x,tmp=(x+1)/2;
        while (tmp<ans) ans=tmp, tmp=(tmp+x/tmp)/2;
        return ans;
    }
    friend Bigint gcd(Bigint a,Bigint b){
        return a%b==0? b: gcd(b, a%b);
    }
    friend Bigint lcm(Bigint a,Bigint b){
        return a/gcd(a,b);
    }

/**
At 1st I'm sorry for my bad english.

Here I toke arithmetic operations (+,-,/,*)
logic from the LightOJ forum, written by Jane Alom Jan.
Because Whether I write the code and exist there some bugs.

This BigInteger is the same as the integer data type.
But it has unlimited range (actually limit of a string size).
Because here I used string as a number in BigInt.
It doesn't work to initialize value when declare variable. suppose,
BigInt a=123, b="3435"; will not work.
But you can use as,
BitInt a("123"), b=BigInt("3435"), c=BigInt(3435);

Supported operations are:
Arithmetic: +,+=,++, -,-=,--, *,*=, /,/=.
Logical: <, <=, >. >=, ==, !=.

3 way to possible initialize value:
i. Using BigInt. (n=b)
ii. Using string. (n="1234")
iii. Using Long Long int or Int. (n=12445)
Also support cin>> to input from user. (cin>>a)

2 way to possible output:
i. using cout. (cout<<a)
ii. using built-in print function. (a.print())

N.B: cin>> ans cout<< not work for in multi input or output.
it's work individually (cin>>a>>b; not work).
*/
};


int main() {
    int t;
	scanf("%d",&t);
	while(t--){
		Bigint a,b,ab,n,ans,M=1000000007;
		cin>>a>>b>>n;
		ab=a-b;
		if (ab==0)
			ans=(pow(a,n,M)+pow(b,n,M))%M;
		else
			ans=(pow(a,n,ab)+pow(b,n,ab))%M,
			ans=gcd(ans,ab)%M;
		cout<<ans<<endl;
	}
	return 0;
}
