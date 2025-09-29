#include <iostream>
#include <string>

std::string getLampColor(int t) {
    int cycle = 103; // total durasi 1 siklus
    int offset = 25; // geser supaya t=45 masuk ke kuning

    // hitung posisi dalam siklus
    int pos = (t - offset) % cycle;
    if (pos < 0) pos += cycle; // jaga supaya tidak negatif

    if (pos >= 0 && pos <= 19) return "Hijau";
    else if (pos >= 20 && pos <= 22) return "Kuning";
    else return "Merah";
}

int main() {
    int t;
    std::cout << "Masukkan detik ke berapa: ";
    std::cin >> t;

    std::string warna = getLampColor(t);
    std::cout << "Pada detik ke-" << t << ", lampu APILL menunjukkan: " 
              << warna << std::endl;

    return 0;
}
