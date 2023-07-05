#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& array,int inicio,int medio,int fin){
  int izquierda=medio-inicio+1;//Hasta la mitad del array
  int derecha=fin-medio;//El restante del array
  vector<int> izqArr(izquierda);
  vector<int> derArr(derecha);
  for (int i=0; i<izquierda; i++){ 
    izqArr[i]=array[inicio+i]; 
  }
  for (int j=0; j<derecha; j++){
    derArr[j]=array[medio+1+j]; 
  }
  int actual=inicio;
  int izqC=0;
  int derC=0;
  while(izqC<izquierda && derC<derecha){
    if(izqArr[izqC]<=derArr[derC]){
      array[actual]=izqArr[izqC];
      izqC++;
    }else{
      array[actual]=derArr[derC];
      derC++;
    }
    actual++;
  }
  while(izqC<izquierda){
    array[actual]=izqArr[izqC];
    izqC++;
    actual++;
  }
  while(derC<derecha){
    array[actual]=derArr[derC];
    derC++;
    actual++;
  }//Lo quería hacer sin whiles, pero en teoría el coste auxiliar aumentaba
}
void mergeSort(vector<int>& array,int inicio,int fin){
  if(inicio>=fin){
    return;
  }
  int medio=inicio+(fin-inicio)/2;
  //Tomar todos los subpares hasta alcanzar el límite y ordenar hasta asegurar la totalidad de orden
  mergeSort(array,inicio,medio);
  mergeSort(array,(medio+1),fin);
  merge(array,inicio,medio,fin);
}
void print(vector<int> array){
    for (int i=0;i < array.size();i++)
        cout << array[i]<<" ";
    cout << "\n";
}
int main() {
  vector<int> array={12,23,30,22,1};
  int n = array.size();
  cout<<"LISTA INICIAL: \n";
  print(array);
  mergeSort(array,0,n-1);
  cout<<"LISTA POST MERGESORT: \n";
  print(array);
}