#include <iostream>
#include <string>
using namespace std;

void teksAwal() {
    cout << "=============================================================================================" << endl;
    cout << "                               SELAMAT DATANG DI HEALTH TRACKER                              " << endl;
    cout << "          Program Pengukur Kesehatan Melalui Perhitungan BMI dan Kalori Harian Anda!         " << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "              Hasil dari Rekomendasi Kalori Harian Ini Hanya Sekedar Perkiraan.              " << endl;
    cout << "                  Konsultasikan Ke Ahli Gizi Untuk Rekomendasi Yang Pasti!                   " << endl;
    cout << "=============================================================================================" << endl;
}

string activity[5] = {
    "Sangat Ringan", "Ringan", "Sedang", "Berat", "Sangat Berat"
};

void tampilkanAktivitas() 
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << activity[i] << endl;
    }
}

double hitungBMI(double tinggi, double berat) {
    double tinggiMeter = tinggi / 100.0;
    double BMI = berat / (tinggiMeter * tinggiMeter);
    return BMI; 
}

void kategoriBMI(double BMI) {
    cout << "Kategori BMI        : ";
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

int main()
{
    string nama;
    double berat, tinggi, bmi, bmr, kalori;
    int umur, aktivitasku;
    char ulang, gender;

    do
    {
        teksAwal();
        cout << "Masukkan nama : ";
        cin >> nama;
        cout << "Masukkan berat badan (kg) : ";
        cin >> berat;
        cout << "Masukkan tinggi badan (cm) : ";
        cin >> tinggi;
        cout << "Masukkan umur (tahun) : ";
        cin >> umur;
        cout << "Jenis kelamin (L = pria, P = wanita) : ";
        cin >> gender;

        cout << endl <<  "Pilih Tingkat Aktivitas Harian : " << endl;

        tampilkanAktivitas();
        cout << "Masukkan Pilihan (1-5) : ";
        cin >> aktivitasku;

        bmi = hitungBMI(tinggi, berat);
        bmr = hitungBMR(tinggi, berat, umur, gender);

        double faktorAktivitas;
        switch (aktivitasku)
        {
            case 1: faktorAktivitas = 1.2; break;
            case 2: faktorAktivitas = 1.375; break;
            case 3: faktorAktivitas = 1.55; break;
            case 4: faktorAktivitas = 1.725; break;
            case 5: faktorAktivitas = 1.9; break;
            default: faktorAktivitas = 1.2; break;
        }

        double kalori = bmr*faktorAktivitas;

        cout << endl << "============================================" << endl;
        cout << "              HasilL Health Tracker           " << endl;
        cout << "============================================" << endl;
        
        cout << "Nama                : " << nama << endl;
        cout << "Umur                : " << umur << " tahun" << endl;
        cout << "Berat Badan         : " << berat << " kg" << endl;
        cout << "Tinggi Badan        : " << tinggi << " cm" << endl;
        cout << "BMI                 : " << bmi << endl;
        
        kategoriBMI(bmi); 
        cout << "Aktivitas Harian    : " << activity[aktivitasku - 1] << endl;
        cout << "Kalori Harian       : " << kalori << " kkal" << endl;
        cout << "---------------------------------------------" << endl;
        
        rekomendasi(bmi);
        cout << endl << "============================================"  << endl;

        cout << endl <<"Apakah ingin menghitung lagi? (y/n): ";
        cin >> ulang;
        
    }
    while  (ulang == 'y' || ulang == 'Y');

    cout << endl <<"Terima kasih sudah menggunakan program ini!" << endl;
    
    return 0;
}
