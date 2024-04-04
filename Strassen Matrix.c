#include <iostream>
using namespace std;

int main() {
    int arr1[2][2], arr2[2][2], z[2][2];
    int i,j;
    //input for first matrix
    cout<<"Enter elements of first matrix: \n";
    for (i=0;i<2;i++) {
        for (j=0;j<2;j++) {
            cin>>arr1[i][j];
        }
    }
    //input for second matrix
    cout<<"Enter elements of second matrix: \n";
    for (i=0;i<2;i++) {
        for (j=0;j<2;j++) {
            cin>>arr2[i][j];
        }
    }
    //print the matrices
    cout<<"\n the first matrix is: \n";
    for (i=0;i<2;i++) {
        for (j=0;j<2;j++) {
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n the second matrix is: \n";
    for (i=0;i<2;i++) {
        for (j=0;j<2;j++) {
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }
    int a=arr1[0][0];
    int b=arr1[0][1];
    int c=arr1[1][0];
    int d=arr1[1][1];
    int e=arr2[0][0];
    int f=arr2[0][1];
    int g=arr2[1][0];
    int h=arr2[1][1];
    int P1=a*(f-h);
    int P2=(a+b)*h;
    int P3=(c+d)*e;
    int P4=d*(g-e);
    int P5=(a+d)*(e+h);
    int P6=(b-d)*(g+h);
    int P7=(a-c)*(e+f);

    //calculate result matrix
    z[0][0]=P5+P4-P2+P6;
    z[0][1]=P1+P2;
    z[1][0]=P3+P4;
    z[1][1]=P5+P1-P3-P7;

    //print result matrix
    cout<<"\n the product achieved using Strassen's Algorithm: \n";
    for (i=0;i<2;i++) {
        for (j=0;j<2;j++) {
            cout<<z[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}
