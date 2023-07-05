#include <iostream>
using namespace std;

float potencia(float num, int pow){
  if(pow==0){
    return 1;
  }else if(pow==1){
    return num;
  }
  if(pow<0){
    return num*(potencia(num,pow+1)); 
  }
  return num*(potencia(num,pow-1)); 
}
float potenciaNum(float num, int pow){
  float numAux=potencia(num,pow);
  if(pow<0){
    numAux=1.0/numAux;
  }
  return numAux;
}
int main() {
  float num=2;
  int pow=4;
  int pow2=-2;
  int pow3=16;
  int pow4=0;
  cout <<num<<"^"<<pow<<"="<<potenciaNum(num,pow)<<"\n";
  cout <<num<<"^"<<pow2<<"="<<potenciaNum(num,pow2)<<"\n";
  cout <<num<<"^"<<pow3<<"="<<potenciaNum(num,pow3)<<"\n";
  cout <<num<<"^"<<pow4<<"="<<potenciaNum(num,pow4)<<"\n";
}
