#include<iostream>
#include<cstdlib>
#include<cmath>
#include<fstream>

using namespace std;

void eulerf(double*, const int, const double, const double);
void eulerb(double*, const int, const double, const double);

int main(){
  const double pi = M_PI;
  const double dt = pi/100;
  const double T = 20*pi;
  const int N = T/dt;
  double arrayf[N*2];
  double arrayb[N*2];
  
  eulerf(arrayf, N, pi, dt);
  eulerb(arrayb, N,pi,dt);
  ofstream forout("forout.txt");
  ofstream backout("backout.txt");
  ofstream anaout("anaout.txt");
  for(int i=0;i<N;i++){
  forout << i*dt <<"\t"<< arrayf[i] << "\t" <<arrayf[N-1+i] << endl;
  backout << i*dt <<"\t"<< arrayb[i] << "\t" <<arrayb[N-1+i] << endl;
  anaout << i*dt << "\t" << cos(i*dt) <<endl; 
  }
  
  
  forout.close();
  backout.close();
  anaout.close();
  return 0;
}

void eulerf(double* arrayf, const int N, const double pi, const double dt){
  arrayf[0]=1;
  arrayf[N]=0;
  for(int i=1;i<N;i++){
    arrayf[i] = arrayf[N-1+i]*dt+arrayf[i-1];
    arrayf[N+i] = -arrayf[i-1]*dt+arrayf[N-1+i];
  }
}

void eulerb(double* arrayb, const int N, const double pi, const double dt){
  arrayb[0]=1;
  arrayb[N]=0;
  for(int i=1;i<N;i++){
    arrayb[i] = (arrayb[N-1+i]*dt+arrayb[i-1])/(1+dt*dt);
    arrayb[N+i] = -((arrayb[N-1+i]*dt+arrayb[i-1])/(1+dt*dt))*dt+arrayb[N-1+i];
  }
}
