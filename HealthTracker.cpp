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

void kategoriBMI(double BMI) {
    if (BMI < 18.5) {
        cout << "Kekurangan Berat Badan" << endl;
    } else if (BMI < 25) {
        cout << "Normal" << endl;
    } else if (BMI < 30) {
        cout << "Kelebihan Berat Badan" << endl;
    } else {
        cout << "Obesitas" << endl;
    }
}

double hitungBMR(double t, double b, double u, char g) {
    double bmr;

    if (g == 'L' || g == 'l') {
        bmr = 10 * b + 6.25 * t - 5 * u + 5;
    } else if(g == 'P' || g == 'p'){
        bmr = 10 * b + 6.25 * t - 5 * u - 161;
    }else{
        cout << "Tidak Dikenali." << endl;
        bmr = 0.0;
    }
    return bmr;
}

void rekomendasi(double bmi) {
        cout << "Rekomendasi         : ";
        if (bmi < 18.5) {
            cout << "Anda kekurangan berat badan. Tambahkan asupan kalori, perbanyak makanan bergizi";
        } else if (bmi < 25){
            cout << "Berat badan anda normal. Pertahankan pola makan sehat dan olahraga teratur.\n";
        } else if (bmi < 30) {
            cout << "Anda mengalami kelebihan berat badan. Kurangi asupan kalori (sekitar 300-500 kka)";
        } else {
            cout << "Anda obesitas. Disarankan konsultasi ke ahli gizi, kurangi kalori lebih banyak";
        }
}
