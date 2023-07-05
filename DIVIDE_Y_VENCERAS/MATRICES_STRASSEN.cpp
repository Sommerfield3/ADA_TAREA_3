#include <bits/stdc++.h>
using namespace std;

// Función para sumar matrices
vector<vector<int>> sumMatrix(const vector<vector<int>>& A,const vector<vector<int>>& B) {
  int n = A.size();
  vector<vector<int>> C(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return C;
}

// Función para restar matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A,const vector<vector<int>>& B){
  int n=A.size();
  vector<vector<int>> C(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      C[i][j]=A[i][j]-B[i][j];
    }
  } 
  return C;
}

// Función para multiplicar matrices usando el algoritmo de Strassen
vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
  int n = A.size();
  // 1x1
  if(n==1){
    vector<vector<int>> C(1,vector<int>(1,0));
    C[0][0]=A[0][0]*B[0][0];
    return C;
  }
  // Dividir en submatrices
  int halfSize = n / 2;
  vector<vector<int>> A11(halfSize,vector<int>(halfSize));
  vector<vector<int>> A12(halfSize,vector<int>(halfSize));
  vector<vector<int>> A21(halfSize,vector<int>(halfSize));
  vector<vector<int>> A22(halfSize,vector<int>(halfSize));
  vector<vector<int>> B11(halfSize,vector<int>(halfSize));
  vector<vector<int>> B12(halfSize,vector<int>(halfSize));
  vector<vector<int>> B21(halfSize,vector<int>(halfSize));
  vector<vector<int>> B22(halfSize,vector<int>(halfSize));
  for (int i=0; i<halfSize; i++) {
    for (int j=0; j<halfSize; j++) {
      A11[i][j]=A[i][j];
      A12[i][j]=A[i][j+halfSize];
      A21[i][j]=A[i+halfSize][j];
      A22[i][j]=A[i+halfSize][j+halfSize];
      B11[i][j]=B[i][j];
      B12[i][j]=B[i][j+halfSize];
      B21[i][j]=B[i+halfSize][j];
      B22[i][j]=B[i+halfSize][j+halfSize];
    }
  }
  // Cálculo recursivo de las submatrices
  vector<vector<int>> M1=strassenMultiply(sumMatrix(A11, A22),sumMatrix(B11, B22));
  vector<vector<int>> M2=strassenMultiply(sumMatrix(A21, A22),B11);
  vector<vector<int>> M3=strassenMultiply(A11,subtractMatrix(B12, B22));
  vector<vector<int>> M4=strassenMultiply(A22,subtractMatrix(B21, B11));
  vector<vector<int>> M5=strassenMultiply(sumMatrix(A11,A12),B22);
  vector<vector<int>> M6=strassenMultiply(subtractMatrix(A21,A11),sumMatrix(B11,B12));
  vector<vector<int>> M7=strassenMultiply(subtractMatrix(A12,A22),sumMatrix(B21,B22));
  
  // Calcular submatrices resultantes
  vector<vector<int>> C11=subtractMatrix(sumMatrix(sumMatrix(M1,M4),M7),M5);
  vector<vector<int>> C12=sumMatrix(M3,M5);
  vector<vector<int>> C21=sumMatrix(M2,M4);
  vector<vector<int>> C22=subtractMatrix(sumMatrix(subtractMatrix(M1,M2),M3),M6);
  // Combinar las submatrices 
  vector<vector<int>>C(n, vector<int>(n, 0));
  for (int i=0;i<halfSize;i++) {
    for (int j=0;j<halfSize;j++) {
      C[i][j]=C11[i][j];
      C[i][j+halfSize]=C12[i][j];
      C[i+halfSize][j]=C21[i][j];
      C[i+halfSize][j+halfSize]=C22[i][j];
    }
  } 
  return C;
}

// Función para imprimir una matriz
void printMatrix(const vector<vector<int>> matrix) {
  int n=matrix.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<matrix[i][j]<<" ";
    }
    cout << endl;
  }
}

int main() {
    // Ejemplo de uso
    vector<vector<int>> A={{1, 3}, {5, 6}};
    vector<vector<int>> B={{2, 3}, {4, 10}};
    vector<vector<int>> result=strassenMultiply(A,B);
    cout<<"MATRIZ A:"<<endl;
    printMatrix(A);
    cout<<"MATRIZ B:"<<endl;
    printMatrix(B);
    cout<<"Resultado de la multiplicación de matrices: "<<endl;
    printMatrix(result);
    
    return 0;
}
