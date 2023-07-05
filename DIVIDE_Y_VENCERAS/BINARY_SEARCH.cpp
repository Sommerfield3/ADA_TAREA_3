#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr,int init,int end,int x)
{
  if (end>=init) {
    int mid=init+(end-init)/2;
    if (arr[mid]==x)//Encontrado
      return mid;
    if (arr[mid]>x) //Buscar hacia la izquierda
      return binarySearch(arr,init,mid-1,x);//Mitad izq
    return binarySearch(arr,mid+1,end,x); //Mitad der
  }
  return -1;//No encontrado.
}
 
// Driver code
int main()
{
    vector<int> arr= {1,3,5,543,23,2,24,67,567,38,2642,6,12,37,42};
    sort(arr.begin(),arr.end());
    cout<<"Valores de la lista: "<<endl;
    for(auto x:arr){
      cout<<x<<" ";
    }
    cout<<endl;
    int x = 38;
    int result=binarySearch(arr,0,arr.size()-1,x);//Buscamos en el array
    cout<<"Elemento buscado: "<<x<<endl;
    if(result==-1){
      cout<<"El elemento no está en el array."<<endl;
      return 0;
    }
    cout<<"Elemento encontrado en el índice "<<result<<" (numerando desde 0).";
    return 0;
}