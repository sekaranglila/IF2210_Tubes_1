#include "Matriks.h"
#include <stdlib.h>
using namespace std;

int main()
{
    bool end = false;
    Matriks A;
    while(!end){
        system("CLS");
        cout << "--Driver Cek Matriks Board--" << endl;
        cout << "1. Load Dari File Eksternal" << endl;
        cout << "2. Save Ke File Eksternal" << endl;
        cout << "3. Display Board" << endl;
        cout << "4. Move Item" << endl;
        cout << "5. Set Item" << endl;
        cout << "6. Get Item" << endl;
        cout << "7. Exit" << endl;
        char p;
        cin >> p;
        cout << endl;
        switch(p){
            case '1':
                    {
                        cout << "Masukkan Nama File Eksternal" << endl;
                        string filename;
                        cin >> filename;
                        A.load(filename.c_str());
                        cout << "File Berhasil Diload" << endl;
                    }
                    break;
            case '2':
                    {
                        cout << "Masukkan Nama File Eksternal" << endl;
                        string filename;
                        cin >> filename;
                        A.save(filename.c_str());
                        cout << "File Berhasil Disave" << endl;
                    }
                    break;
            case '3':
                    {
                    A.display();
                    }
                    break;
            case '4':
                    {
                        int x, y, movx, movy;
                        cout << "Masukkan koordinat x dari benda yang akan dipindah" << endl;
                        cin >> x;
                        cout << "Masukkan koordinat y dari benda yang akan dipindah" << endl;
                        cin >> y;
                        cout << "Masukkan koordinat x dari tujuan pemindahan" << endl;
                        cin >> movx;
                        cout << "Masukkan koordinat y dari tujuan pemindahan" << endl;
                        cin >> movy;
                        A.move(x, y, movx, movy);
                    }
                    break;
            case '5':
                    {
                        int x, y;
                        char c;
                        cout << "Masukkan koordinat x dari benda yang akan diset" << endl;
                        cin >> x;
                        cout << "Masukkan koordinat y dari benda yang akan diset" << endl;
                        cin >> y;
                        cout << "Masukkan karakter yang ingin diset" << endl;
                        cin >> c;
                        A.setBoard(x, y, c);
                    }
                    break;
            case '6':
                    {
                        int x, y;
                        cout << "Masukkan koordinat x dari benda yang akan ditampilkan" << endl;
                        cin >> x;
                        cout << "Masukkan koordinat y dari benda yang akan ditampilkan" << endl;
                        cin >> y;
                        cout << A.getBoard(x, y) << endl;
                    }
                    break;
            case '7':
                    {
                        end = true;
                    }
                    break;
            default:
                    {
                        cout << "Masukan salah.";
                    }
                    break;
        }
        cout << endl;
        system("pause");
    }
}
