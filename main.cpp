#include <iostream>
#include <fstream> 
#include <cmath> 
using namespace std; 

class Vector {
    public:
        double x, y, z ;
    
        Vector(double vx=0.0, double vy=0.0, double vz=0.0){
            x=vx;
            y=vy;
            z=vz;
        } 
        double magnitude(){
             return sqrt(x*x + y*y + z*z);
        }
        void display(){
            cout << "Vector: (" << x << ", " << y << ", " << z << ")";
        }

};
class Matrix {
public:
    double M[3][3];
    Matrix(){
        for(int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                M[i][j]=0.0;
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
class Particle {
    protected:
        int id;
        Vector position;
        double energy;

    public:
        Particle() {
            id = 0;
            energy = 0.0;
        }
    
        Particle(int pid, double px, double py, double pz, double penergy){
            id = pid;
            position = Vector(px, py, pz);
            energy = penergy;
        }
        double GetEnergy(){
            return energy;
        }
        virtual void printInfo(){
            cout<< "Particle ID: " << id << endl;
            cout<< "Position"<<endl;
            position.display() ;
            cout<< endl << "Magnitude:" << position.magnitude() << endl;
            cout<< "Energy: " << energy << endl;
        }
        void transform(Matrix m) {
            position = m * position;
        }
};

class Electron: public Particle {
    public:
    Electron (int pid, double px, double py, double pz, double penergy): Particle (pid, px, py, pz, penergy){
    }
    void printInfo() override {
        cout << "-ELECTRON-" << endl;
        cout << "ID: " << id << " \nEnergy: " << energy << " MeV" << endl;
        cout << "Position: ";
        position.display();
        cout << endl << "----------------\n" << endl;
    }
};

class Proton: public Particle {
    public:
    Proton (int pid, double px, double py, double pz, double penergy): Particle (pid, px, py, pz, penergy){
    }
    void printInfo() override {
        cout << "+PROTON+" << endl;
        cout << "ID: " << id << " \nEnergy: " << energy << " MeV" << endl;
        cout << "Position: ";
        position.display();
        cout << endl << "++++++++++++++\n" << endl;
    }

};

class Event {
    private:
        int eventId;
        int capacity;
        int particleCount;
        Particle** particles;
    
    public:
       Event(int eid, int ecapacity) {
            eventId = eid;
            capacity = ecapacity;
            particleCount = 0; 
            particles = new Particle*[capacity]; 
       }
       ~Event() {
        for(int i=0; i < particleCount; i++){
                delete particles[i];
       }
       delete[] particles; 
    }
       
       void addParticle(Particle* newParticle) {
            if (particleCount < capacity) {
                particles[particleCount] = newParticle; // Anahtarı panoya as!
                particleCount++;
            } 
            else {
                cout << "Error: Event capacity is full.\n";
            }
        }

        void printEvent() {
            cout << "\n============================\n";
            cout << "EVENT ID: " << eventId << " RESULTS\n";
            cout << "==============================\n\n";
            for (int i = 0; i < particleCount; i++) {
                particles[i]->printInfo();
            }
        }

        void sortParticlesByEnergy() {
        for (int i = 0; i < particleCount - 1; i++) {
            for (int j = 0; j < particleCount - i - 1; j++) {
                if (particles[j]->GetEnergy() < particles[j + 1]->GetEnergy()) {
                    Particle* temp = particles[j];
                    particles[j] = particles[j + 1];
                    particles[j + 1] = temp;
                }
            }
        }
    }
    void applyMagneticField(Matrix m){
        for(int i=0; i<particleCount; i++) {
            particles[i]->transform(m);
        }
    }
};
int main() {
    cout << "\nInitializing HEP-Core System..\n\n";
    Proton p1(102, -3.0, 0.0, 1.5, 990.0);
    p1.printInfo();
    Electron e1(101, 5.0, 5.0, 5.0, 120.5);
    e1.printInfo();
    Event collision1(67, 100);
    
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open data.txt!\n";
        return 1;
    }
    
    double x, y, z, enerji;
    int id_counter = 1;
    
    cout << "File opened, particles are loading to RAM.\n\n";

    while (file >> x >> y >> z >> enerji) {
        Particle* newParticle; 
        if (id_counter % 2 == 0) {
            newParticle = new Electron(id_counter, x, y, z, enerji);
        } 
        
        else {
            newParticle = new Proton(id_counter, x, y, z, enerji);
        }

        collision1.addParticle(newParticle);
        id_counter++;
    }
    
    file.close();
    collision1.sortParticlesByEnergy();
    collision1.printEvent();
    
    cout << "Before Magnetic Field \n";
    collision1.printEvent(); 
    
    Matrix magneticField; 
    double angle = 1.5708; 
 
    magneticField.M[0][0] = cos(angle);
    magneticField.M[0][1] = -sin(angle);
    magneticField.M[0][2] = 0.0;
   
    magneticField.M[1][0] = sin(angle);
    magneticField.M[1][1] = cos(angle);
    magneticField.M[1][2] = 0.0;
    
    magneticField.M[2][0] = 0.0;
    magneticField.M[2][1] = 0.0;
    magneticField.M[2][2] = 1.0;

    collision1.applyMagneticField(magneticField);

    cout << "\nAfter Magnetic Field \n";
    collision1.printEvent();
    return 0;
}
    