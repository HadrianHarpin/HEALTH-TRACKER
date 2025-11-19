#include <iostream>
#include <string>
using namespace std;
//jadi untuk array ini aku pakai untuk nyimpen variabel aktivitas, abis itu nanti aktivitasnya bakal ditampilin pake loop (di fungsi main)

void teksAwal()
{
    cout << "=====================================================================================" << endl;
    cout << "                          Welcome to Program Health Tracker                        " << endl;
    cout << "Program ini dibuat untuk mengukur Kesehatan melalui perhitungan BMI & Kalori harian" << endl << endl;
    cout << "          HASIL DARI REKOMENDASI KALORI HARIAN INI HANYA SEKEDAR PERKIRAAN         " << endl;
    cout << "               KONSULTASIKAN KE AHLI GIZI UNTUK REKOMENDASI YANG PASTI!            " << endl;
    cout << "=====================================================================================" << endl << endl;
}
string activity[5] = {
    "Sangat Ringan", "Ringan", "Sedang", "Berat", "Sangat Berat"
};

void tampilkanAktivitas()
{
    cout << "\nPilih Tingkat Aktivitas Harian:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << activity[i] << endl;
    } 
}

double hitungBMI(double t, double b)
{
    double tinggiMeter = t / 100.0;
    double BMI = b / (tinggiMeter * tinggiMeter);

    return BMI;
}

void kategori(double bmi)
{
    if (bmi < 18.5){ 
        cout << "Kekurangan berat badan\n";
    }else if (bmi < 25){
        cout << "Normal\n";
    }else if (bmi < 30){
        cout << "Kelebihan berat badan\n";
    }else{
        cout << "Obesitas\n";
    }
}

double hitungBMR(double t, double b, double u, char g)
{
    double bmr;

    if (g == 'L' || g == 'l') {
        bmr = 10 * b + 6.25 * t - 5 * u + 5;
    } else if(g == 'P' || g == 'p'){
        bmr = 10 * b + 6.25 * t - 5 * u - 161;
    }else{
        cout << "Tidak Dikenali. Default: Wanita (P)\n";
        bmr = 10 * b + 6.25 * t - 5 * u - 161;
    }

    return bmr;
}

// double hitungAktivitas(int akti)
// {
//     double fAct;
//     switch (akti){
//             case 1: fAct = 1.2; break;
//             case 2: fAct = 1.375; break;
//             case 3: fAct = 1.55; break;
//             case 4: fAct = 1.725; break;
//             case 5: fAct = 1.9; break;
//             default: fAct = 1.2; break;
//         }
// }

void rekomendasi(double bmi)
{
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

int main() {
    string nama;
    double berat, tinggi, bmi, bmr, kalori;
    int umur, aktivitasku;
    char ulang, gender;

    

    do{
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

        tampilkanAktivitas();
        cout << "Masukkan Pilihan (1-5): ";
        cin >> aktivitasku;


        bmi = hitungBMI(tinggi, berat);
        bmr = hitungBMR(tinggi, berat, umur, gender);
        
    double faktorAktivitas;
    switch (aktivitasku){
        case 1: faktorAktivitas = 1.2; break;
        case 2: faktorAktivitas = 1.375; break;
        case 3: faktorAktivitas = 1.55; break;
        case 4: faktorAktivitas = 1.725; break;
        case 5: faktorAktivitas = 1.9; break;
        default: faktorAktivitas = 1.2; break;
    }

    kalori = bmr*faktorAktivitas;

    cout << "\n============================================\n";
    cout << "              HasilL Health Tracker           \n";
    cout << "============================================\n";
    
    cout << "Nama                : " << nama << endl;
    cout << "Umur                : " << umur << " tahun" << endl;
    cout << "Berat Badan         : " << berat << " kg" << endl;
    cout << "Tinggi Badan        : " << tinggi << " cm" << endl;
    cout << "BMI                 : " << bmi << endl;
    cout << "Kategori BMI        : ";kategori(bmi);
    cout << "Aktivitas Harian    : " << activity[aktivitasku - 1] << endl;
    cout << "Kalori Harian       : " << kalori << " kkal" << endl;
    cout << "---------------------------------------------\n";
    cout << "Rekomendasi         : ";rekomendasi(bmi);
    cout << "\n============================================\n";

    cout << "\nApakah ingin menghitung lagi? (y/n): ";
    cin >> ulang;
        
    }while  (ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih sudah menggunakan program ini!\n";
    return 0;
}

