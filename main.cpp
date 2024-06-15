#include <iostream>
#include <fstream>
using namespace std;

void logToFile(double sayi1, char islem, double sayi2, double sonuc) {
    ofstream dosya("gecmis.txt", ios::app);
    if (dosya.is_open()) {
        dosya << sayi1 << " " << islem << " " << sayi2 << " = " << sonuc << endl;
        dosya.close();
    } else {
        cout << "Dosya açýlamadý!" << endl;
    }
}

int main() {
    double sayi1, sayi2, sonuc;
    char islem;
    char devam;

    do {   
        cout << "Birinci sayiyi girin: ";
        cin >> sayi1;
        cout << "Ikinci sayiyi girin: ";
        cin >> sayi2;
        cout << "Islemi girin (+, -, *, /): ";
        cin >> islem;

        switch (islem) {
            case '+':
                sonuc = sayi1 + sayi2;
                cout << "Sonuc: " << sonuc << endl;
                logToFile(sayi1, islem, sayi2, sonuc);
                break;
            case '-':
                sonuc = sayi1 - sayi2;
                cout << "Sonuc: " << sonuc << endl;
                logToFile(sayi1, islem, sayi2, sonuc);
                break;
            case '*':
                sonuc = sayi1 * sayi2;
                cout << "Sonuc: " << sonuc << endl;
                logToFile(sayi1, islem, sayi2, sonuc);
                break;
            case '/':
                if (sayi2 == 0) {
                    cout << "Hata: Bolen sifir olamaz!" << endl;
                } else {
                    sonuc = sayi1 / sayi2;
                    cout << "Sonuc: " << sonuc << endl;
                    logToFile(sayi1, islem, sayi2, sonuc);
                }
                break;
            default:
                cout << "Gecersiz islem!" << endl;
                break;
        }
        cout << "Devam etmek istiyor musunuz? (Evet icin 'e', Hayýr icin 'h' girin): ";
        cin >> devam;
			
    } while (devam == 'e' || devam == 'E');
    cout << "Hesap makinasindan cikiliyor:" << endl;

    return 0;
}

