#include <iostream>
#include <cmath>
using namespace std;

class Vector {
public:
    double x, y, z;
    Vector(double vx = 0.0, double vy = 0.0, double vz = 0.0) {
        x = vx; y = vy; z = vz;
    }
    void display() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};
class Matrix {
public:
    double M[3][3];
    Matrix(){
        for(int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                M[i][j]=0,0;
            }
        }
    M[0][0] = 1.0;
    M[1][1] = 1.0;
    M[2][2] = 1.0;
    }

    Vector operator* (Vector vec) {
        double n_x = (M[0][0] * vec.x) + (M[0][1] * vec.y) + (M[0][2] * vec.z);
        double n_y = (M[1][0] * vec.x) + (M[1][1] * vec.y) + (M[1][2] * vec.z);
        double n_z = (M[2][0] * vec.x) + (M[2][1] * vec.y) + (M[2][2] * vec.z);
        return Vector(n_x, n_y, n_z);
    }
};
int main() {

    Vector v1(10.0, 5.0, 0.0);
    cout << "Orijinal Vektor: ";
    v1.display();

    Matrix m; 
    
    m.M[0][0] = 2.0;
    m.M[1][1] = 2.0;
    m.M[2][2] = 2.0;

    Vector v2 = m * v1;

    cout << "Buyutulmus Vektor: ";
    v2.display();

    return 0;
}