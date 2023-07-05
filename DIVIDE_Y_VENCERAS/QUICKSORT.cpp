#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& arr,int i,int j) {
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
  //Intercambiado
}
//PIVOTE Y PARTICIÓN
int particion(vector<int>& arr,int low,int high) {
  int pivote=arr[high];//El pivote es el más alto
  int i=low-1;
  for (int j=low;j<high;j++) {
    if(arr[j]<=pivote){
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr,i+1,high);
  return i+1;//Disminuimos 1 posición.
}

void quickSort(vector<int>& arr,int low,int high) {
  if (low>=high){
    return;
  }
  int pivoteIndice=particion(arr,low,high);
  quickSort(arr,low,pivoteIndice-1);
  quickSort(arr,pivoteIndice+1,high);
}
void print(const vector<int>& arr) {
  for (int num : arr)//iterador de elementos
    cout << num << " ";
  cout << endl;
}

int main() {
  vector<int> arr = {9, 4, 2, 7, 1, 5, 3, 8, 6};
  int n=arr.size();
  cout << "Vector original: ";
  print(arr);
  quickSort(arr, 0, n - 1);
  cout << "Vector ordenado: ";
  print(arr);
  return 0;
}