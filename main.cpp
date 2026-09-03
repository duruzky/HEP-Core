#include <iostream>
#include <fstream>
using namespace std;

class Particle {
private:
int id;
double x, y, z;
double energy;

public:
Particle() {
        id = 0; x = 0.0; y = 0.0; z = 0.0; energy = 0.0;
    }
Particle(int p_id, double p_x, double p_y, double p_z, double p_energy ) {
        id = p_id; x = p_x; y = p_y; z = p_z; energy = p_energy;
    }
double getEnergy() {
        return energy;
    }

void printInfo() {
cout<< "Particle ID: " << id 
 << " | Position: (" << x << ", " << y << ", " << z << ") | Energy:"<< energy <<  endl;
}
};

class Event {
    private: 
    int eventId;
    int capacity;
    int particleCount;
    Particle* particles;

public:
    Event(int e_id, int e_capacity) {
        eventId = e_id;
        capacity = e_capacity;
        particleCount = 0;
        particles = new Particle[capacity];
        cout << "Event " << eventId << " created. Memory allocated.\n";
    }
    ~Event() {
        delete[] particles;
        cout<< "Event " << eventId << " deleted. Memory cleared.\n";
    }

    void addParticle(int p_id, double x, double y, double z,double p_energy) {
        if (particleCount < capacity) {
            particles[particleCount] = Particle(p_id, x, y, z, p_energy);
            particleCount++;
        } else {
            cout << "Error: Event capacity is full.\n";
        }
    }

    void printEvent() {
        cout << "Event ID: " << eventId << " Results\n";
        for (int i = 0; i < particleCount; i++) {
            particles[i].printInfo();
        }
    }

    void sortParticlesByEnergy() {
        for (int i = 0; i < particleCount - 1; i++) {
            for (int j = 0; j < particleCount - i - 1; j++) {
                if (particles[j].getEnergy() < particles[j + 1].getEnergy()) {
                    Particle temp = particles[j];
                    particles[j] = particles[j + 1];
                    particles[j + 1] = temp;
                }
            }
        }
    }

};

int main() {
    cout << "Initializing HEP-Core System.\n";
    Event collision1(67, 100);
   
    
    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open data.txt!\n";
        return 1;
    }
    double x, y, z, energy;
    int id_counter = 1;
    cout<< "File opened,particles are loading to RAM.\n";


    while (file >> x >> y >> z >> energy) {
        collision1.addParticle(id_counter, x, y, z, energy);
        id_counter++;
    }
    file.close();
    cout << "File closed.\n";

    cout << (id_counter - 1) << " particles loaded successfully.\n\n";
    cout << "Original Order:\n";
    collision1.printEvent();
    cout << "Sorting by Energy:\n";
    collision1.sortParticlesByEnergy();
    collision1.printEvent();
    cout << "System shutting down.\n";
    return 0;
}
