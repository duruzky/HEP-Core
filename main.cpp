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
class Particle {
    private:
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
        void printInfo(){
            cout<< "Particle ID: " << id << endl;
            cout<< "Position:";
            position.display() ;
            cout<< endl << "Magnitude:" << position.magnitude() << endl;
            cout<< "Energy: " << energy << endl;
        }
};

class Event {
    private:
        int eventId;
        int capacity;
        int particleCount;
        Particle* particles;
    
    public:
       Event(int eid, int ecapacity) {
            eventId = eid;
            capacity = ecapacity;
            particleCount = 0; 
            particles = new Particle[capacity]; 
       }
       ~Event() {
        delete[] particles;
       }
       
       void addParticle(int pid, double x, double y, double z, double penergy) {
            if (particleCount < capacity) {
                particles[particleCount] = Particle(pid, x, y, z, penergy);
                particleCount++;
            } 
            else {
                cout << "Error: Event capacity is full.\n";
            }
        }

        void printEvent() {
            cout << "Event ID: " << eventId << " Results:\n";
            for (int i = 0; i < particleCount; i++) {
                particles[i].printInfo();
            }
        }

        void sortParticlesByEnergy() {
        for (int i = 0; i < particleCount - 1; i++) {
            for (int j = 0; j < particleCount - i - 1; j++) {
                if (particles[j].GetEnergy() < particles[j + 1].GetEnergy()) {
                    Particle temp = particles[j];
                    particles[j] = particles[j + 1];
                    particles[j + 1] = temp;
                }
            }
        }
    }
};
int main() {
    cout << "Initializing HEP-Core System...\n";
    Event collision1(67, 100);
    
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open data.txt!\n";
        return 1;
    }
    
    double x, y, z, enerji;
    int id_counter = 1;
    
    cout << "File opened, particles are loading to RAM...\n\n";

    while (file >> x >> y >> z >> enerji) {
        collision1.addParticle(id_counter, x, y, z, enerji);
        id_counter++;
    }
    file.close();
    collision1.sortParticlesByEnergy();
    collision1.printEvent();
    
    cout << "\nSystem shutting down.\n";
    return 0;
}
    