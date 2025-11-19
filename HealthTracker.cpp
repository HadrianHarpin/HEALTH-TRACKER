#include <iostream>
#include <string>
using namespace std;

string activity[5] = {"Sangat Ringan", "Ringan", "Sedang", "Berat", "Sangat Berat"};
void teksAwal() {
    cout << "============================================================================================" << endl;
    cout << "                            SELAMAT DATANG DI HEALTH TRACKER                                " << endl;
    cout << "        Program Pengukur Kesehatan Melalui Perhitungan BMI dan Kalori Harian Anda!          " << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;
    cout << "              Hasil dari Rekomendasi Kalori Harian Ini Hanya Sekedar Perkiraan.              " << endl;
    cout << "                  Konsultasikan Ke Ahli Gizi Untuk Rekomendasi Yang Pasti!                   " << endl;
    cout << "=============================================================================================" << endl;
}
double hitungBMI(double tinggi, double berat) {
    double tinggiMeter = tinggi / 100.0;
    double BMI = berat / (tinggiMeter * tinggiMeter);
    return BMI; 
}
string kategoriBMI(double BMI) {
    if (BMI < 18.5) {
        return "Kurus";
    } else if (BMI >= 18.5 && BMI < 24.9) {
        return "Normal";
    } else if (BMI >= 25.0 && BMI < 29.9) {
        return "Gemuk";
    } else {
        return "Obesitas";
    }
}