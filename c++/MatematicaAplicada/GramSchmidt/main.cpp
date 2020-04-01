#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

// http://www.mia.uni-saarland.de/Teaching/NAVC-SS11/sol_c8.pdf
// page 5

double a[4][4] = {
    {1.0, 5.0, -3.0},
    {-1.0, 1.0, -3.0},
    {1.0, 1.0, 1.0},
    {-1.0, 1.0, -3.0}
};
// any column of a is a vector

double r[4][4], q[4][4];

int main(int argc, char *argv[]) {
    int k, i, j;
    for (k=0; k<4; k++){
      r[k][k]=0; // equivalent to sum = 0
      for (i=0; i<4; i++)
        r[k][k] = r[k][k] + a[i][k] * a[i][k]; // rkk = sqr(a0k) + sqr(a1k) + sqr(a2k)
      r[k][k] = sqrt(r[k][k]);  // ||a||
      cout <<endl<<endl << "R"<<k<<k<<": " << r[k][k];

      for (i=0; i<4; i++) {
          q[i][k] = a[i][k]/r[k][k];
          cout << " q"<<i<<k<<": "<<q[i][k] << " ";
      }

      for(j=k+1; j<4; j++) {
        r[k][j]=0;
        for(i=0; i<4; i++) r[k][j] += q[i][k] * a[i][j];
        cout << endl<< endl << "r"<<k<<j<<": " <<r[k][j] << endl<<endl;

        for (i=0; i<4; i++) a[i][j] = a[i][j] - r[k][j]*q[i][k];

        for (i=0; i<4; i++) cout << "a"<<j<<": " << a[i][j]<< " ";
      }
}
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
