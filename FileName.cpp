//#include <iostream>
//#include <string>
//using namespace std;
//
//int mod(int a, int b) {
//    return (a % b + b) % b;
//}
//
//int gcd(int a, int b) {// находим обший делитель 
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//int modInverse(int a, int m) {//инверсируем значение по целочислености 
//    a = mod(a, m);
//    for (int x = 1; x < m; x++) {
//        if (mod(a * x, m) == 1) {
//            return x;
//        }
//    }
//    return -1;
//}
//
//void decrypt(string ciphertext, int a, int b) {
//    string plaintext = "";  
//    int a_inverse = modInverse(a, 26);
//    for (int i = 0; i < ciphertext.length(); i++) {
//        if (isalpha(ciphertext[i])) {
//            char c = tolower(ciphertext[i]);
//            int d = mod(a_inverse * (c - 'a' - b), 26);
//            plaintext += char(d + 'a');
//        }
//        else {
//            plaintext += ciphertext[i];
//        }
//    }
//    cout << "Key: a = " << a << ", b = " << b << endl;
//    cout << "Plaintext: " << plaintext << endl;
//}
//
//int main() {
//    string ciphertext = "jzq kuudncrejqg ut jzq jedwai jus tumd qlqpqr";
//    for (int a = 3; a < 5; a++) {//пол байта размер шифратора 
//        for (int b = 4; b < 5; b++) {
//            if (gcd(a, 26) == 1) {
//                decrypt(ciphertext, a, b);
//            }
//        }
//    }
//    return 0;
//}


#include <iostream>
#include <string>

using namespace std;

int modInverse(int a, int m) {//вычисляет обратный элемент по модулю для заданного a и m
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

string affineDecrypt(string ciphertext, int a, int b) {// принимает зашифрованный текст а и b и возвращает расшифрованный текст
    string plaintext = "";
    int a_inv = modInverse(a, 26);//передает значение для вычисление элемента по модулю
    for (char c : ciphertext) {
        if (c >= 'a' && c <= 'z') { //провекра является ли буква в нижнем регистре 
            int x = (a_inv * (c - 'a' - b + 26)) % 26;//разшифровка текста 
            plaintext += (char)(x + 'a');//добавление елемента к строке 
        }
        else {
            tolower(c);//переводим в нижнйи регистр 
            plaintext += c;//добавляем к строке 
        }
    }
    return plaintext;
}

int main() {
    string ciphertext = "jzq kuudncrejqg ut jzq jedwai jus tumd qlqpqr";
    string target = "target";

    for (int a = 3; a < 5; a ++) { // ключи пол байка (4)
        int a_inv = modInverse(a, 26);
        for (int b = 3; b < 5; b++) {//также 
            string plaintext = affineDecrypt(ciphertext, a, b);
                cout << "Найден ключ: a = " << a << ", b = " << b << endl;
                cout << "Открытый текст: " << plaintext << endl;
            
        }
    }

    return 0;
}
