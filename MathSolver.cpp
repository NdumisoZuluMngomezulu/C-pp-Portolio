#include<iostream>
#include<math.h>
#include <limits>

using namespace std;

// Function definition to process calculations
double calculate(double num1, char op, double num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            // Edge-case handling for division by zero
            if (num2 == 0) {
                std::cerr << "Error: Division by zero is undefined! " << std::endl;
                return std::numeric_limits<double>::quiet_NaN(); 
            }
            return num1 / num2;
        default:
            std::cerr << "Error: Invalid operator '" << op << "'." << std::endl;
            return std::numeric_limits<double>::quiet_NaN();
    }
}

int determinant( int matrix[10][10], int n) {
   int det = 0;
   int submatrix[10][10];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
      }
   }
   return det;
}
int main() {
   int n, i, j;
   int matrix[10][10];
   cout << "Enter the size of the matrix:\n";
   cin >> n;
   cout << "Enter the elements of the matrix:\n";
   for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
   cin >> matrix[i][j];
   cout<<"The entered matrix is:"<<endl;
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
      cout << matrix[i][j] <<" ";
      cout<<endl;
   }
   cout<<"Determinant of the matrix is "<< determinant(matrix, n);
   return 0;
}
