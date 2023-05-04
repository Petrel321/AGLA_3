#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct Triple {
    double time;
    double victims;
    double killers;
};

int main() {
    double V_0, K_0, a1, b1, a2, b2, T, N;
    cin >> V_0 >> K_0 >> a1 >> b1 >> a2 >> b2 >> T >> N;
    double dt = T / N, c1 = a1 / b1, c2 = a2 / b2, v_0 = V_0 - c2, k_0 = K_0 - c1;
    vector<Triple> triple;
    N++;
    for (int i = 0; i < N; ++i) {
        double V = c2, K = c1, t = dt * i;
        V += v_0* cos(sqrt(a1*a2)*t)-k_0*(sqrt(a2) * b1 / (sqrt(a1)*b2))* sin(sqrt(a1*a2)*t);
        K += v_0*(sqrt(a1) * b2 / (sqrt(a2)*b1))* sin(sqrt(a1*a2)*t)+k_0* cos(sqrt(a1*a2)*t);
        V = round(V*100) / 100;
        K = round(K*100) / 100;
        triple.push_back({t, V, K});
    }
    cout << fixed << setprecision(2);
    cout << "t:\n";
    for (int i = 0; i < N; ++i) {
        cout << triple[i].time << ' ';
    }
    cout << "\nv:\n";
    for (int i = 0; i < N; ++i) {
        cout << triple[i].victims << ' ';
    }
    cout << "\nk:\n";
    for (int i = 0; i < N; ++i) {
        cout << triple[i].killers << ' ';
    }
}
