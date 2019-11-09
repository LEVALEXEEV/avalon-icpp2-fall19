
#include "Extention.hpp"
#include <iostream>

using namespace std;

int main()
{ int agents[10][12];
int ran=0;
int lim=0;
int masmed[10];
for(int i=0;i<10;i++){
    for(int j=0;j<12;j++){
        agents[i][j]=GetRandomValue(1000, 100000);
   ran=GetRandomValue(-1, 3);
    if (ran==-1){agents[i][j]=ran;}
    }
    for(int j=0;j<11;j++){
        if (agents[i][j]<agents[i][j+1]){
           int t=agents[i][j];
           agents[i][j]=agents[i][j+1];
           agents[i][j+1]=t;
        }
    }
    for(int j=0;j<12;j++){
        if (agents[i][j]==-1){
            lim=j;
            break;
        }
    }
    if (lim%2==0){masmed[i]=(agents[i][lim/2]+agents[i][lim/2+1])/2;}
    else masmed[i]=agents[i][lim/2];
cout<<masmed[i]<<endl;
    }
}
