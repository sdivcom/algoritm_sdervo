#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
const int M=4; 

int x, o, k;

x=0;

double I[M][M],t[M],Kp=1,Kd=1,Ki=1,Iz=25;

double fatpoint(double point)
{
	int iF,jF;
	double MassI[M],res=0;
	for(jF=0;jF<M;jF++)
	{
		MassI[jF]=I[0][jF];
		for(iF=0;iF<jF;iF++)
		{
			MassI[jF]*=point-t[iF];
		}
		res+=MassI[jF];
	}
	return res;
}

int main()
{

cout << "zaday nachalo ->" ;
cin >> o;

cout << "zaday konec ->" ;
cin >> k;

if(0>x<360) {
if (o>k) x = o - k;
else if (o<k) x = k - o;
else if (k==o) cout << "otdex"<< endl;

cout << "molodec! x="<< x << endl;

if (x<90) o=1;
else if (x<180) o=2;
else if (x<270) o=3;
else if (x<359) o=4;

cout << "obmotok stoka:"<< o << endl;


	int i,j;
    double eps=0.01,stepinteg,h=0.001;


    double propor, integ=0, differ=0,output;

    for(i=0;i<M;i++)
    {
    	cout <<"t["<<i<<"]="<<' ';
    	cin >> t[i];
    	cout <<"I["<<i<<"]="<<' ';
    	cin >> I[i][0];	
	}

    propor=Iz-I[M-1][0];
    cout <<"propor= "<<propor <<endl;
    if (propor<eps) return 0;

    for(j=1;j<M;j++)
	{
		for(i=0;i<M-j;i++)
		{
			I[i][j]=(I[i+1][j-1]-I[i][j-1])/(t[i+j]-t[i]);
		}
	}

	int N=200;
	stepinteg=(t[M-1]-t[0])/N;
	double step=t[0];
	for(i=0;i<N;i++)
	{
		integ+=(fatpoint(step)+fatpoint(step+stepinteg))/2*stepinteg;
		step+=stepinteg;
	}
	cout <<"integ= "<<integ <<endl;
	
	differ=(fatpoint(t[M-1])-fatpoint(t[M-1]-h))/h;
	cout <<"differ= "<<differ <<endl;

	for(i=0;i<M;i++)
        {
        	cout <<t[i]<<'\t';
            for(j=0;j<M;j++)
                cout << I[i][j] << '\t';
            cout << endl;
        }

    output=Kp*propor+Ki*integ+Kd*differ;
    cout <<"output= "<<output <<endl;
    return 0;
}