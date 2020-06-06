#include <string>
#include <iostream>
#include <limits>
#include "Polynomial.hpp"
#include "Residue.hpp"

using namespace std;

void banner();

int main() {
    const long Z_n = 2;
    int *ptr;
    long mod = 0;
    size_t degree = 0;
    long coefficient = 0;
    bool fin = true;
    char anotherTerm;
    int i = 1;

    banner();
    cout << "Para el anillo Zn, indique el valor (entero positivo) de \"n\": ";
    cin >> (mod);

    while (cin.fail()) {
        cout << "Para el anillo Zn, indique el valor (entero positivo) de \"n\": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> (mod);
    }
    cout << endl;

    ptr = (int*)( &Z_n );
    *ptr = mod;

    // Definir polinomios
    Polynomial<ResidueNum<Z_n>> g_x, h_x, d_x, q_x, r_x, s_x, s1_x, s2_x, t_x, t1_x, t2_x, zero;

    // g(x)
    g_x.setMember(10, ResidueNum<Z_n>(1));  // x^10
    g_x.setMember(9, ResidueNum<Z_n>(1));   // x^9
    g_x.setMember(8, ResidueNum<Z_n>(1));   // x^8
    g_x.setMember(6, ResidueNum<Z_n>(1));   // x^6
    g_x.setMember(5, ResidueNum<Z_n>(1));   // x^5
    g_x.setMember(4, ResidueNum<Z_n>(1));   // x^4
    g_x.setMember(0, ResidueNum<Z_n>(1));   // 1

    // h(x)
    h_x.setMember(9, ResidueNum<Z_n>(1));   // x^9
    h_x.setMember(6, ResidueNum<Z_n>(1));   // x^6
    h_x.setMember(5, ResidueNum<Z_n>(1));   // x^5
    h_x.setMember(3, ResidueNum<Z_n>(1));   // x^3
    h_x.setMember(2, ResidueNum<Z_n>(1));   // x^2
    h_x.setMember(0, ResidueNum<Z_n>(1));   // 1

//    // g(x)
//    cout << "Polinomio g(x)" <<endl;
//
//    while(fin){
//        cout << "Indique el grado del t\202rmino: ";
//        cin >> degree;
//
//        while (cin.fail()) {
//            cout << "Indique el grado del t\202rmino: ";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cin >> degree;
//        }
//
//        cout << "Indique el coeficiente del t\202rmino: ";
//        cin >> coefficient;
//
//        while (cin.fail()) {
//            cout << "Indique el coeficiente del t\202rmino: ";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cin >> coefficient;
//        }
//
//        g_x.setMember(degree, ResidueNum<Z_n>(coefficient));
//
//        cout << "¿Desea agregar otro t\202rmino al polinomio g(x)? [Y/N]: ";
//        cin >> anotherTerm;
//
//        while (anotherTerm != 'Y' && anotherTerm != 'N') {
//            cout << "¿Desea agregar otro t\202rmino al polinomio g(x)? [Y/N]: ";
//            cin >> anotherTerm;
//        }
//
//        if(anotherTerm == 'N') {
//            fin = false;
//        }
//    }
//    fin = true;
//    cout << endl;
//
//    // h(x)
//    cout << "Polinomio h(x)" <<endl;
//    while(fin){
//        cout << "Indique el grado del t\202rmino: ";
//        cin >> degree;
//
//        while (cin.fail()) {
//            cout << "Indique el grado del t\202rmino: ";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cin >> degree;
//        }
//
//        cout << "Indique el coeficiente del t\202rmino: ";
//        cin >> coefficient;
//
//        while (cin.fail()) {
//            cout << "Indique el coeficiente del t\202rmino: ";
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cin >> coefficient;
//        }
//
//        h_x.setMember(degree, ResidueNum<Z_n>(coefficient));
//
//        cout << "¿Desea agregar otro t\202rmino al polinomio h(x)? [Y/N]: ";
//        cin >> anotherTerm;
//
//        while (anotherTerm != 'Y' && anotherTerm != 'N') {
//            cout << "¿Desea agregar otro t\202rmino al polinomio h(x)? [Y/N]: ";
//            cin >> anotherTerm;
//        }
//
//        if(anotherTerm == 'N') {
//            fin = false;
//        }
//        cout << endl;
//    }

    d_x.setMember(0, ResidueNum<Z_n>(0));
    q_x.setMember(0, ResidueNum<Z_n>(0));
    r_x.setMember(0, ResidueNum<Z_n>(0));
    s_x.setMember(0, ResidueNum<Z_n>(1));
    s1_x.setMember(0, ResidueNum<Z_n>(1));
    s2_x.setMember(0, ResidueNum<Z_n>(0));
    t_x.setMember(0, ResidueNum<Z_n>(0));
    t1_x.setMember(0, ResidueNum<Z_n>(0));
    t2_x.setMember(0, ResidueNum<Z_n>(1));
    zero.setMember(0, ResidueNum<Z_n>(0));

    Polynomial<ResidueNum<Z_n>>g_x_o = g_x;
    Polynomial<ResidueNum<Z_n>>h_x_o = h_x;

    if (h_x == zero) {
        d_x = g_x_o;
        cout << "GCD(" << g_x_o << ", " << h_x_o << ") = d(x)" << endl;
        cout << "d(x)= " << d_x << endl;
        cout << "s(x)= " << s_x << endl;
        cout << "t(x)= " << t_x << endl;
    }

    while (h_x != zero) {
        cout << "_-_-_-_-_-_-_-_-_-_-_-_ ITERACION " << i << " _-_-_-_-_-_-_-_-_-_-_-_" << endl << endl;
        cout << "g(x)= " << g_x << endl;
        cout << "h(x)= " << h_x << endl;

        try
        {
            q_x = (g_x / h_x);
            r_x = (g_x % h_x);
            s_x = s2_x - q_x * s1_x;
            t_x = t2_x - q_x * t1_x;

            cout << "s2(x)= " << s2_x << endl;
            cout << "s1(x)= " << s1_x << endl;
            cout << "t2(x)= " << t2_x << endl;
            cout << "t1(x)= " << t1_x << endl;
            cout << "q(x)= " << q_x << endl;
            cout << "r(x)= " << r_x << endl;
            cout << "s(x)= " << s_x << endl;
            cout << "t(x)= " << t_x << endl;

            g_x = h_x;
            h_x = r_x;
            s2_x = s1_x;
            s1_x = s_x;
            t2_x = t1_x;
            t1_x = t_x;
        }
        catch (const exception& e)
        {
            cout << "ERROR: " << endl << e.what() << endl;
        }
        cout << endl;
        i+=1;
    }
    d_x = g_x;

    cout << "_-_-_-_-_-_-_-_-_-_-_-_ RESULTADO FINAL _-_-_-_-_-_-_-_-_-_-_-_" << endl << endl;
    cout << "GCD(" << g_x_o << ", " << h_x_o << ") = d(x)" << endl;
    cout << "d(x)= " << d_x << endl;
    cout << "s(x)= " << s2_x << endl;
    cout << "t(x)= " << t2_x << endl;

    return 0;
}

void banner(){
    cout << "\n"
            "_____/\\\\\\\\\\\\\\\\\\\\\\\\________/\\\\\\\\\\\\\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\\\____        \n"
            " ___/\\\\\\//////////______/\\\\\\////////__\\/\\\\\\////////\\\\\\__       \n"
            "  __/\\\\\\_______________/\\\\\\/___________\\/\\\\\\______\\//\\\\\\_      \n"
            "   _\\/\\\\\\____/\\\\\\\\\\\\\\__/\\\\\\_____________\\/\\\\\\_______\\/\\\\\\_     \n"
            "    _\\/\\\\\\___\\/////\\\\\\_\\/\\\\\\_____________\\/\\\\\\_______\\/\\\\\\_    \n"
            "     _\\/\\\\\\_______\\/\\\\\\_\\//\\\\\\____________\\/\\\\\\_______\\/\\\\\\_   \n"
            "      _\\/\\\\\\_______\\/\\\\\\__\\///\\\\\\__________\\/\\\\\\_______/\\\\\\__  \n"
            "       _\\//\\\\\\\\\\\\\\\\\\\\\\\\/_____\\////\\\\\\\\\\\\\\\\\\_\\/\\\\\\\\\\\\\\\\\\\\\\\\/___ \n"
            "        __\\////////////__________\\/////////__\\////////////_____\n"
            "" << endl;
    cout << "ALGORITMO EXTENDIDO DE EUCLIDES PARA POLINOMIOS" << endl << endl;
    cout << "JOAQUIN INOROSA FIGUEROA" << endl << endl;
}
