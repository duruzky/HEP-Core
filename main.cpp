#include <iostream>
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
cout<< "Parcacik ID: " << id 
 << " | Konum: (" << x << ", " << y << ", " << z << ") | Energy:"<< energy <<  endl;
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
        cout << "Event " << eventId << " olusturuldu. Bellekten yer ayrildi.\n";
    }
    ~Event() {
        delete[] particles;
        cout<< "Event " << eventId << " silindi. Bellek temizlendi.\n";
    }

    void addParticle(int p_id, double x, double y, double z,double p_energy) {
        if (particleCount < capacity) {
            particles[particleCount] = Particle(p_id, x, y, z, p_energy);
            particleCount++;
        } else {
            cout << "Hata: Event kapasitesi dolu!\n";
        }
    }

    void printEvent() {
        std::cout << "--- Event ID: " << eventId << " Sonuclari ---\n";
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

    std::cout << "HEP-Core Sistemi Baslatiliyor...\n";
    std::cout << "--------------------------------\n";


    Event collision1(101, 5);

    collision1.addParticle(1, 10.5, 20.1, 0.0, 50.5);
    collision1.addParticle(2, -5.2, 8.4, 3.1, 120.0);
    collision1.addParticle(3, 0.0, 0.0, 15.9, 15.2);
    collision1.addParticle(4, 1.1, 2.2, 3.3, 400.8);
    collision1.addParticle(5, 7.7, 8.8, 9.9, 85.4);

    cout << "\n--- Siralamadan Once (Sensorden Gelen Sira) ---\n";
    collision1.printEvent();

    collision1.sortParticlesByEnergy();

    std::cout << "\n--- Enerjiye Gore Siralandiktan Sonra ---\n";
    collision1.printEvent();

    std::cout << "\nSistem kapatiliyor...\n";
    return 0;

}
