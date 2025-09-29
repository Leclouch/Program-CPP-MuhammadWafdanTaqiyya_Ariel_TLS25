#include <iostream>
#include <string>
#include <cctype>

// ambil input
std::string getWord() {
    std::cout << "Your Code: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    return name;
}

// menghilangkan vowels
std::string encrpt_removeVowels(std::string code) {
    std::string vowels{"aeiouAEIOU"};

    for (size_t i = 0; i < code.length(); i++) {
        for (size_t j = 0; j < vowels.length(); j++) {
            if (code[i] == vowels[j]) {
                code.erase(code.begin() + i);
                i--; 
                break;
            }
        }
    }
    return code;
}

// reverse string
std::string encrypt_Reverse(std::string code1) {
    for (int i = 0, j = code1.length() - 1; i < j; i++, j--) {
        std::swap(code1[i], code1[j]);
    }
    return code1;
}

// sisipkan ASCII huruf terakhir ke tengah string
void encrypt_ASCII(std::string code2) {
    if (code2.empty()) {
        std::cout << "String kosong!\n";
        return;
    }

    int ASCII = static_cast<int>(code2[code2.length() - 1]);
    size_t pos = code2.length() / 2;
    code2.insert(pos, std::to_string(ASCII));

    std::cout << code2 << '\n';
}

// proses enkripsi
void encrypt() {
    std::string code{getWord()};
    std::cout << "So your Code is " << code << '\n';

    std::string code1{encrpt_removeVowels(code)};
    std::cout << "Without vowels: " << code1 << '\n';

    std::string code2{encrypt_Reverse(code1)};
    std::cout << "Reversed: " << code2 << '\n';

    std::cout << "Final with ASCII inserted: ";
    encrypt_ASCII(code2);
}

// hapus ASCII yang ditambahkan di tengah
std::string removeInsertedASCII(const std::string &str) {
    std::string result;
    for (size_t i = 0; i < str.size(); i++) {
        if (std::isdigit(str[i])) continue; 
        result += str[i];
    }
    return result;
}

// proses dekripsi
void decrypt() {
    std::string code{getWord()};

    std::string removed = removeInsertedASCII(code);
    std::cout << "After removing ASCII: " << removed << '\n';

    std::string original = encrypt_Reverse(removed);
    std::cout << "Reversed back: " << original << '\n';

    std::cout << "(Note: vowels cannot be restored!)\n";
}

int main() {
start:
    std::cout << "Crypt (c) or Reverse (r)\n";
    char InputOption{};
    std::cin >> InputOption;

    if (InputOption == 'c') {
        std::cout << "Crypt it is\n";
        encrypt();
    } else if (InputOption == 'r') {
        std::cout << "Decrypt it is\n";
        decrypt();
    } else {
        goto start;
    }
    return 0;
}
