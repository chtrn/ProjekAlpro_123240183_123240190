#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int max_Menu = 100;
const int max_toko = 5;
string carinama; 
char ulang;
int pilih;

struct Menu {
    string nama;
    int harga;
    string namaWarung;
};

Menu daftarMenu[] =
    {
        {"risol", 3000000, "Legenda"},
        {"piscok", 2000000, "Legenda"},
        {"sosis", 3000000, "Legenda"},
        {"onde-onde", 5000000, "Legenda"},
        {"kue", 3000000, "Legenda"},
        {"jus jambu", 9000000, "Legenda"},
        {"es teller", 5000000, "Legenda"},
        {"es buah", 6000000, "Legenda"},

        {"dimsum", 100000, "Foodkuy"},
        {"corndog", 200000, "Foodkuy"},
        {"burger", 150000, "Foodkuy"},
        {"spaghetti", 120000, "Foodkuy"},
        {"sushi", 130000, "Foodkuy"},
        {"jus mangga", 500000, "Foodkuy"},
        {"es kyut", 300000, "Foodkuy"},
        {"es durian", 500000, "Foodkuy"},

        {"nasi padang", 130000, "Nusantara"},
        {"gudeg", 102000, "Nusantara"},
        {"salad solo", 250000, "Nusantara"},
        {"nasi goreng", 150000, "Nusantara"},
        {"pempek", 120000, "Nusantara"},
        {"wedang ronde", 600000, "Nusantara"},
        {"wedang uwuh", 500000, "Nusantara"},
        {"es dawet", 400000, "Nusantara"},

        {"ayam geprek", 150000, "Gepriks"},
        {"es teh", 300000, "Gepriks"},
        {"es jeruk", 200000, "Gepriks"},
        {"es cokelat", 400000, "Gepriks"}
};

void cariMenuDiWarung(const string& namaWarung) {
    bool found = false;
    cout << " Masukkan nama menu yang dicari: ";
    cin.ignore();
    getline(cin, carinama);

    cout << "\nMenu yang ditemukan:\n";
    for (int i = 0; i < sizeof(daftarMenu) / sizeof(daftarMenu[0]); i++)
    {
        if (daftarMenu[i].namaWarung == namaWarung && daftarMenu[i].nama == carinama)
        {
            cout << "\nMenu ditemukan di " << daftarMenu[i].namaWarung << ": "
                 << daftarMenu[i].nama << " - Rp" << daftarMenu[i].harga << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Menu tidak ditemukan di warung " << namaWarung << ".\n";
}

void makyus ()
{
    do {
        cout << "Pilih :\n1. Lihat menu\n2. Cari menu\n3. Exit\nPilih : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                cout << " MENU : \n";
                cout << left << setw(20) << " Makanan " << " harga " << endl;
                cout << left << setw(20) << " 1. Seblak " << " 120.000 " << endl;
                cout << left << setw(20) << " 2. Mie Goreng " << " 70.000 " << endl;
                cout << left << setw(20) << " 3. Bakso Bakar " << " 100.000 " << endl;
                cout << left << setw(20) << " 4. Mie Ayam " << " 90.000 " << endl;
                cout << left << setw(20) << " 5. Mie Pedas " << " 100.000 " << endl;
                cout << " Minuman " << endl;
                cout << left << setw(20) << " 1. Es Teh " << " 300.000 " << endl;
                cout << left << setw(20) << " 2. Es Jeruk " << " 300.000 " << endl;
                cout << left << setw(20) << " 3. Air Putih " << " 200.000\n";
                break;
            case 2:
                cariMenuDiWarung("Makyus");
                break;

            case 3:
                exit(0);
                break;
            default : 
                cout << " Pilihan tidak ada ! ";
                break;
        }
    } while (pilih < 3 && pilih > 0);
}

void Legenda ()
{
    system("cls");
    do{
    cout << "Pilih :\n";
    cout << "1. Lihat menu\n";
    cout << "2. Cari menu\n";
    cout << "3. Exit\n";
    cout << "Pilih : "; cin >> pilih;
    switch (pilih) {
        case 1 :  
            cout << " Menu : \n";
            cout << left << setw(20)  <<  " Makanan "      <<  " Harga " << endl;
            cout << left << setw(20)  << " 1. Risol Mayo "  <<  " 3.000.000 \n";
            cout << left << setw(20)  << " 2. Piscok "      <<  " 2.000.000 \n";
            cout << left << setw(20)  << " 3. Sosis Bakar " <<  " 3.000.000 \n";
            cout << left << setw(20)  << " 4. Onde-onde "   <<  " 5.000.000\n";
            cout << left << setw(20)  << " 5. Kue Lapis "   <<  " 3.000.000\n";
            cout << " Minuman "     << endl;
            cout << left  << setw(20)  <<  " 1. Jus Jambu "   <<  " 9.000.000\n";
            cout <<  left << setw(20)   << " 2. Es Teller "   <<  " 5.000.000\n";
            cout << left << setw(20)    << " 3. Es Buah "     <<  " 6.000.000\n";
            cout << " Pilih Makanan :  ";
        break;

        case 2 :
            cariMenuDiWarung("Legenda");
        break;

        case 3 :
            exit(0);
        break;

        default : 
            cout << " Pilihan tidak ada!";
        break;
}
} while(pilih < 3 && pilih > 0);
}

void FoodKuy ()
{
    system("cls");
    do { 
     cout << "Pilih :\n";
    cout << "1. Lihat menu\n";
    cout << "2. Cari menu\n";
    cout << "3. Exit\n";
    cout << "Pilih : "; cin >> pilih;
    switch ( pilih ) {
        case 1 : 
    cout << " Menu : \n";
    cout << left << setw(20) << " Makanan "      <<  " Harga " << endl;
    cout << left << setw(20) << " 1. Dimsum "    <<  " 100.000 \n";
    cout << left << setw(20) << " 2. Corndog "   <<  " 200.000 \n";
    cout << left << setw(20) << " 3. Burger "    <<  " 150.000 \n";
    cout << left << setw(20) << " 4. Spaghetti " <<  " 120.000\n";
    cout << left << setw(20) << " 5. Sushi "     <<  " 130.000\n";
    cout << " Minuman \n";
    cout << left << setw(20) << " 1. Jus Mangga " <<  " 500.000\n";
    cout << left << setw(20) << " 2. Es Kyut "   << " 300.000\n";
    cout << left << setw(20) << " 3. Es Durian " << " 500.000\n";
    cout << " Pilih Makanan : ";
    }
    cin >> pilih;
} while ( pilih > 3 || pilih < 1);
} 

void Nusantara ()
{
    system("cls");
    cout << " Menu : \n";
    cout << left << setw(20) << " Makanan "        << " Harga " << endl;
    cout << left << setw(20) << " 1. Nasi Padang " << " 130.000 \n";
    cout << left << setw(20) << " 2. Gudeg "       << " 102.000 \n";
    cout << left << setw(20) << " 3. Salad Solo "  << " 250.000\n";
    cout << left << setw(20) << " 4. Nasi Goreng " << " 150.000\n";
    cout << left << setw(20) << " 5. Pempek "      << " 120.000\n";
    cout << " Minuman \n";
    cout << left << setw(20) << " 1. Wedang Ronde " << " 600.000\n";
    cout << left << setw(20) << " 2. Wedang Uwuh "  << " 500.000\n";
    cout << left << setw(20) << " 3. Es Dawet "     << " 400.000\n";
    cout << " Pilih Makanan : ";
    cin >> pilih;
}

void Gepriks()
{
    system("cls");
    cout << " Menu : \n";
    cout << left << setw(22) << " Makanan " << " Harga " << endl;
    cout << left << setw(20) << " 1. Ayam Geprek lv 0 " << " 150.000\n";
    cout << left << setw(20) << " 2. Ayam Geprek lv 1 " << " 160.000\n";
    cout << left << setw(20) << " 3. Ayam geprek lv 2 " << " 170.000\n";
    cout << left << setw(20) << " 4. Ayam Geprek lv 3 " << " 180.000\n";
    cout << left << setw(20) << " 5. Ayam Geprek lv 4 " << " 190.000\n";
    cout << "Minuman \n";
    cout << left << setw(20) << " 1. Es Teh "     << " 300.000\n";
    cout << left << setw(20) << " 2. Es Jeruk "   << " 200.000\n";
    cout << left << setw(20) << " 3. Es Cokelat " << " 400.000\n";
    cout << " Pilih Makanan : ";
    cin >> pilih;
}

void cariMenu ()
{
    system ("cls");
    bool found = false;
    cout << " Masukan nama menu yang dicari : ";
    cin.ignore();
    getline(cin, carinama);
    cout << "\nMenu yang ditemukan : \n";
    for (int i = 0; i < 40; i++)
    {
        if (daftarMenu[i].nama == carinama)
        {
            cout << "\nMenu ditemukan di " << daftarMenu[i].namaWarung << ": "
                 << daftarMenu[i].nama << " - Rp" << daftarMenu[i].harga << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Menu tidak ditemukan.\n";
}

void menu ()
{
   do {
    system("cls");
    cout << " * Selamat datang di Kuliner Street Food ! * " << endl;
    cout << " 1. Warung Maknyus \n 2. Jajanan Legenda \n 3. Street Food Kuy! \n 4. Warung Rasa Nusantara\n";
    cout << " 5. Gepriks\n";
    cout << " Pilih Warung : ";
    cin >> pilih;
    switch (pilih) {
    case 1 : 
        makyus();
        break;

    case 2 : 
        Legenda();
        break;

    case 3 : 
        FoodKuy();
        break;

    case 4 : 
        Nusantara();
        break;

    case 5 : 
        Gepriks();
        break;

    case 6 : 
        cout << " Keluar dari program! ";
        exit(0);
        break;

    default : 
        cout << " Input salah harap ulangi input Anda!";
        break;
   }
   cout << " Ingin kembali ke menu? y/n : ";
   cin >> ulang;
} while (( pilih > 5 || pilih < 1 || ulang == 'y'));
}

int main () {
    system("cls");
    menu();
return 0;
}
