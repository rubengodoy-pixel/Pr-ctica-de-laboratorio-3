#include <iostream>
#include <string>

using namespace std;


class Personaje {
protected:
    string nombre;
    int nivel;
    int vida;
    int ataqueBase;

public:
    
    Personaje(string _nombre, int _nivel, int _vida, int _ataqueBase) 
        : nombre(_nombre), nivel(_nivel), vida(_vida), ataqueBase(_ataqueBase) {}

    
    string getNombre() { return nombre; }
    int getVida() { return vida; }

    void setVida(int _vida) { vida = _vida; }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << " | Nivel: " << nivel 
             << " | Vida: " << vida << " | Ataque Base: " << ataqueBase << endl;
    }

    void recibirDano(int dano) {
        vida -= dano;
        if (vida < 0) vida = 0; 
        cout << nombre << " recibio " << dano << " de dano. Vida restante: " << vida << endl;
    }

    void curar(int cantidad) {
        vida += cantidad;
        cout << nombre << " se ha curado " << cantidad << " puntos. Vida actual: " << vida << endl;
    }

    
    void atacar() { 
        cout << nombre << " realiza un ataque basico." << endl; 
    }

    void atacar(string objetivo) { 
        cout << nombre << " ataca a " << objetivo << "." << endl; 
    }

    void atacar(string objetivo, int danoExtra) { 
        int danoTotal = ataqueBase + danoExtra; 
        cout << nombre << " ataca a " << objetivo << " causando " << danoTotal << " puntos de dano." << endl;
    }
};

            //subclase guerrero
class Guerrero : public Personaje {
private:
    string arma;
    int fuerza;

public:
    Guerrero(string _n, int _l, int _v, int _a, string _arma, int _f) 
        : Personaje(_n, _l, _v, _a), arma(_arma), fuerza(_f) {}

    void mostrarGuerrero() {
        mostrarInformacion();
        cout << "Arma: " << arma << " | Fuerza: " << fuerza << endl;
    }

    void golpeEspecial() {
        int dano = ataqueBase + fuerza; 
        cout << nombre << " usa " << arma << " para un golpe especial de " << dano << " de dano!" << endl;
    }
};

            //subclase mago
class Mago : public Personaje {
private:
    string hechizo;
    int mana;

public:
    Mago(string _n, int _l, int _v, int _a, string _h, int _m) 
        : Personaje(_n, _l, _v, _a), hechizo(_h), mana(_m) {}

    void lanzarHechizo() {
        if (mana >= 10) { 
            mana -= 10;
            cout << nombre << " lanza " << hechizo << ". Mana restante: " << mana << endl;
        } else {
            cout << nombre << " no tiene suficiente mana." << endl; 
        }
    }
};

                //subclase arquero
class Arquero : public Personaje {
private:
    int flechas;
    int precision;

public:
    Arquero(string _n, int _l, int _v, int _a, int _fl, int _p) 
        : Personaje(_n, _l, _v, _a), flechas(_fl), precision(_p) {}

    void dispararFlecha() {
        if (flechas > 0) { 
            flechas--;
            cout << nombre << " disparo una flecha. Flechas restantes: " << flechas << endl;
        } else {
            cout << nombre << " no tiene flechas para atacar." << endl; 
        }
    }
};

                  
int main() {
    Guerrero g1("Arthur", 10, 100, 20, "Espada Excalibur", 15);
    Mago m1("Merlin", 12, 80, 10, "Bola de Fuego", 50);
    Arquero a1("Robin", 11, 90, 15, 5, 85);

    cout << "--- INFO INICIAL ---" << endl;
    g1.mostrarGuerrero();
    m1.mostrarInformacion(); 
    a1.mostrarInformacion();

    cout << "\n--- PRUEBA SOBRECARGA ---" << endl;
    g1.atacar();
    g1.atacar("Goblin");
    g1.atacar("Dragon", 25);

    cout << "\n--- ACCIONES ESPECIALES ---" << endl;
    g1.golpeEspecial();
    m1.lanzarHechizo();
    a1.dispararFlecha();

    cout << "\n--- ESTADO DE SALUD ---" << endl;
    m1.recibirDano(30);
    m1.curar(15);

    cout << "\n--- INFO ACTUALIZADA ---" << endl;
    m1.mostrarInformacion();

    return 0;
}