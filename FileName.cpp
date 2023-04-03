//#include <iostream>
//#include <string>
//using namespace std;
//
//int mod(int a, int b) {
//    return (a % b + b) % b;
//}
//
//int gcd(int a, int b) {// ������� ����� �������� 
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//int modInverse(int a, int m) {//����������� �������� �� �������������� 
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
//    for (int a = 3; a < 5; a++) {//��� ����� ������ ��������� 
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

int modInverse(int a, int m) {//��������� �������� ������� �� ������ ��� ��������� a � m
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

string affineDecrypt(string ciphertext, int a, int b) {// ��������� ������������� ����� � � b � ���������� �������������� �����
    string plaintext = "";
    int a_inv = modInverse(a, 26);//�������� �������� ��� ���������� �������� �� ������
    for (char c : ciphertext) {
        if (c >= 'a' && c <= 'z') { //�������� �������� �� ����� � ������ �������� 
            int x = (a_inv * (c - 'a' - b + 26)) % 26;//����������� ������ 
            plaintext += (char)(x + 'a');//���������� �������� � ������ 
        }
        else {
            tolower(c);//��������� � ������ ������� 
            plaintext += c;//��������� � ������ 
        }
    }
    return plaintext;
}

int main() {
    string ciphertext = "jzq kuudncrejqg ut jzq jedwai jus tumd qlqpqr";
    string target = "target";

    for (int a = 3; a < 5; a ++) { // ����� ��� ����� (4)
        int a_inv = modInverse(a, 26);
        for (int b = 3; b < 5; b++) {//����� 
            string plaintext = affineDecrypt(ciphertext, a, b);
                cout << "������ ����: a = " << a << ", b = " << b << endl;
                cout << "�������� �����: " << plaintext << endl;
            
        }
    }

    return 0;
}
