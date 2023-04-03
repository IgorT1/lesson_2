#include <iostream>
#include <string>

using namespace std;

int modInverse(int a, int m) {//âû÷èñëÿåò îáðàòíûé ýëåìåíò ïî ìîäóëþ äëÿ çàäàííîãî a è m
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

string affineDecrypt(string ciphertext, int a, int b) {// ïðèíèìàåò çàøèôðîâàííûé òåêñò à è b è âîçâðàùàåò ðàñøèôðîâàííûé òåêñò
    string plaintext = "";
    int a_inv = modInverse(a, 26);//ïåðåäàåò çíà÷åíèå äëÿ âû÷èñëåíèå ýëåìåíòà ïî ìîäóëþ
    for (char c : ciphertext) {
        if (c >= 'a' && c <= 'z') { //ïðîâåêðà ÿâëÿåòñÿ ëè áóêâà â íèæíåì ðåãèñòðå 
            int x = (a_inv * (c - 'a' - b + 26)) % 26;//ðàçøèôðîâêà òåêñòà 
            plaintext += (char)(x + 'a');//äîáàâëåíèå åëåìåíòà ê ñòðîêå 
        }
        else {
            tolower(c);//ïåðåâîäèì â íèæíéè ðåãèñòð 
            plaintext += c;//äîáàâëÿåì ê ñòðîêå 
        }
    }
    return plaintext;
}

int main() {
    string ciphertext = "jzq kuudncrejqg ut jzq jedwai jus tumd qlqpqr";
    string target = "target";

    for (int a = 3; a < 5; a ++) { // êëþ÷è ïîë áàéêà (4)
        int a_inv = modInverse(a, 26);
        for (int b = 3; b < 5; b++) {//òàêæå 
            string plaintext = affineDecrypt(ciphertext, a, b);
                cout << "Íàéäåí êëþ÷: a = " << a << ", b = " << b << endl;
                cout << "Îòêðûòûé òåêñò: " << plaintext << endl;
            
        }
    }

    return 0;
}
