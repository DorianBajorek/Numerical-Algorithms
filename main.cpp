#include <iostream>
#include <vector>
using namespace std;
class Matrix{
 private:
  int row;
  int column;
  vector<vector<double>>elements;
 public:
  Matrix(const int &row, const int &column){
    this->row=row;
    this->column=column;
    elements=vector<vector<double>>(row);
    for(int i=0;i<row;i++){
      elements[i]=vector<double>(column);
    }
  }
  Matrix& operator+(Matrix& B){
    for(int i=0;i<row;i++){
      for(int j=0;j<column;j++){
        elements[i][j]+=B.elements[i][j];
      }
    }
    return *this;
  }
  Matrix& operator*(double x){
    for(int i=0;i<row;i++){
      for(int j=0;i<column;j++){
        elements[i][j]+=x;
      }
    }
    return *this;
  }
  Matrix operator*(Matrix &B){
    int rowB=B.row,coulmnB=B.column;
    Matrix C(row,B.row);
    for(int i=0;i<row;i++){
      for(int j=0;j<column;j++){
        int sum=0;
        for(int k=0;k<coulmnB;k++){
          sum+=(elements[i][k]+B.elements[k][j]);
        }
        C.elements[i][j]=sum;
      }
    }
    return C;
  }
  Matrix& transposition(){
    for(int i=0;i<this->row;i++){
      for(int j=i;j<this->column;j++){
        swap(elements[i][j],elements[j][i]);
      }
    }
    return *this;
  }
  vector<double>& operator[](const int x){
    return elements[x];
  };
  friend ostream& operator<<(ostream& streamToShow,const Matrix& A){
    for(int i=0;i<A.row;i++){
      for(int j=0;j<A.column;j++){
       streamToShow<<A.elements[i][j]<<" ";
      }
      streamToShow<<endl;
    }
    return streamToShow;
  }
};
int main(){
  Matrix A(2,2);
  Matrix B(2,2);
  A[0][0]=1;
  A[0][1]=2;
  A[1][0]=3;
  A[1][1]=4;
  B[0][0]=1;
  B[0][1]=2;
  B[1][0]=3;
  B[1][1]=4;
  cout<<A<<endl;
  cout<<(A.transposition());
  return 0;
}
