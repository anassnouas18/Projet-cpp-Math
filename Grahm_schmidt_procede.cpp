#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
float produit(float *v, float *u, int dim) {
    float x = 0;

    for (int i = 0; i < dim; i++)
        x += v[i] * u[i];

    return x;
}
void projection(float *V1, float *V2, float *V3, int dim) {
    float U, U2, U1;

    U2 = produit(V1, V2, dim);
    U1 = produit(V2, V2, dim);
    U = U2 / U1;

    for (int i = 0; i < dim; i++) {
        V3[i] = V2[i] * U;
    }
}
void normaliser(float *u, int dim) {
    float normalisation = sqrt(produit(u, u, dim));

    for (int i = 0; i < dim; i++)
        u[i] /= normalisation;
}
void grahm_schmidt() {
    int dim, dim1;

    cout << "Entrer la dimension de la base : ";
    cin >> dim1;

    cout << "Entrer la dimension du vecteur : ";
    cin >> dim;

    float Z[dim1][dim];

    cout << "Entrer les vecteurs \n";
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim; j++) {
            cout << "Entrer V" << i + 1 << "[" << j + 1 << "]=";
            cin >> Z[i][j];
        }
        cout << '\n';
    }

    cout << '\n';


    for (int i = 1; i < dim1; i++) {
        for (int j = 0; j < i; j++) {

            float ut = produit(Z[j], Z[i], dim) / produit(Z[j], Z[j], dim);

            for (int k = 0; k < dim; ++k)
                Z[i][k] -= ut * Z[j][k];
        }
    }


    for (int i = 0; i < dim1; ++i)
        normaliser(Z[i], dim);


    cout << "les  vecteurs orthonormaux"<<'\n';
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim; j++) {
            cout << "V" << i + 1 << "[" << j + 1 << "]=" << Z[i][j] << " "<<'\n';
        }
        cout << '\n';
    }
}
int main() {
    int choix, a;

    cout << '\n' << "Grahm Schmidt & realise par NOUAS ANASS (GI) " << '\n';

    system("pause");
    system("cls");

    do {
        cout << " 1- procede de grahm-schmidt" << '\n';
        cout << '\n';
        cout << " 0- Quitter" << '\n';
        cout << '\n';
        cin >> choix;

        switch (choix) {
        case 1:
            grahm_schmidt();
            system("pause");
            system("cls");

            cout << "    Menu principal <<  1  >> " << '\n';
            cout << '\n';
            cout << "    QUITTER        <<  0  >>" << '\n';

            cin >> a;
            break;

        case 0:
            system("pause");
            system("cls");
            cout << '\n' << "AU revoir ";
            a = 0;
            break;

        default:
            cout << "Choix invalide. Veuillez reessayer "<<'\n';
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

    } while (a != 0);

    return 0;
}


