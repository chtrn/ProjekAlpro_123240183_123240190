#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int max_Menu = 100;
const int max_toko = 5;
string carinama; 
char awal;
int pilih, pilih1, pilih2;
void menu();
void makyus();
void Legenda();
void FoodKuy();
void Nusantara();
void Gepriks();

struct Menu {
    string nama;
    int harga;
    string namaWarung;
};

Menu daftarMenu[max_Menu] =
    {
        {"Seblak", 120000, "Makyus"},
        {"Mie Goreng", 70000, "Makyus"},
        {"Bakso Bakar", 100000, "Makyus"},
        {"Mie Ayam", 90000, "Makyus"},
        {"Mie Pedas", 100000, "Makyus"},
        {"Es Teh", 300000, "Makyus"},
        {"Es Jeruk", 300000, "Makyus"},
        {"Air Putih", 200000, "Makyus"},

        {"Risol", 3000000, "Legenda"},
        {"Piscok", 2000000, "Legenda"},
        {"Sosis", 3000000, "Legenda"},
        {"Onde-onde", 5000000, "Legenda"},
        {"Kue Lapis", 3000000, "Legenda"},
        {"Jus Jambu", 9000000, "Legenda"},
        {"Es Teller", 5000000, "Legenda"},
        {"Es Buah", 6000000, "Legenda"},

        {"Dimsum", 100000, "Foodkuy"},
        {"Corndog", 200000, "Foodkuy"},
        {"Burger", 150000, "Foodkuy"},
        {"Spaghetti", 120000, "Foodkuy"},
        {"Sushi", 130000, "Foodkuy"},
        {"Jus Mangga", 500000, "Foodkuy"},
        {"Es Kyut", 300000, "Foodkuy"},
        {"Es Durian", 500000, "Foodkuy"},

        {"Nasi Padang", 130000, "Nusantara"},
        {"Gudeg", 102000, "Nusantara"},
        {"Salad Solo", 250000, "Nusantara"},
        {"Nasi Goreng", 150000, "Nusantara"},
        {"Pempek", 120000, "Nusantara"},
        {"Wedang Ronde", 600000, "Nusantara"},
        {"Wedang Uwuh", 500000, "Nusantara"},
        {"Es Dawet", 400000, "Nusantara"},

        {"Ayam Geprek", 150000, "Gepriks"},
        {"Es Teh", 300000, "Gepriks"},
        {"Es Jeruk", 200000, "Gepriks"},
        {"Es Cokelat", 400000, "Gepriks"}
};

void tampilkanMenu(const string& namaWarung) {
    
        cout << "======= MENU " << namaWarung << "=======" << endl;
        cout << left << setw(20) << "Makanan " << " Harga " << endl;

        for (int i = 0; i < 5; i++) {
            cout << left << i + 1 << ". "<< setw(20) << daftarMenu[i].nama
                 << setw(5) << daftarMenu[i].harga << "\n";
        }

        cout << "\nMinuman " << endl;

        for (int i = 5; i < 8; i++) {
            cout << left << i + 1 << ". " << setw(20) << daftarMenu[i].nama
                 << setw(5) << daftarMenu[i].harga << "\n";
        }

        cout << left << "9. " << setw(20) << "Kembali ke menu awal\n";
    
}

void cariMenuDiWarung(const string& namaWarung) {
    bool found = false;
    cout << "Masukkan nama menu yang dicari: ";
    cin.ignore();
    getline(cin, carinama);

    for (int i = 0; i < sizeof(daftarMenu) / sizeof(daftarMenu[0]); i++)
    {
        if (daftarMenu[i].namaWarung == namaWarung && daftarMenu[i].nama == carinama)
        {
            cout << "\nMenu ditemukan di " << daftarMenu[i].namaWarung << " :\n"
                 << daftarMenu[i].nama << " - Rp" << daftarMenu[i].harga << endl;
            found = true;
        }
    }
    cout << "Kembali ke menu awal (y/n) ? : "; cin >> awal;
    if (awal == 'y' || awal == 'Y')
        if (namaWarung == "Makyus")
            makyus();
        if (namaWarung == "Legenda")
            Legenda();
        if (namaWarung == "Foodkuy")
            FoodKuy();
        if (namaWarung == "Nusantara")
            Nusantara();
        if (namaWarung == "Gepriks")
            Gepriks();
    if (!found)
        cout << "Menu tidak ditemukan di warung " << namaWarung << ".\n";
}

void makyus ()
{   
    system("cls");
    do {
        cout << "* Warung Makyus *\n1. Lihat menu\n2. Cari menu\n3. Kembali ke menu utama\nPilih : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                while (pilih1 > 9 || pilih1 < 1){
                tampilkanMenu("Makyus");
                cout << "Pilih : "; cin >> pilih1;
                }
                break;

            case 2:
                cariMenuDiWarung("Makyus");
                break;

            case 3:
                menu();
                break;

            default : 
                cout << " Pilihan tidak valid!\n";
                break;
        }
    } while (pilih > 3 || pilih < 1 || pilih1 == 9);
}

void Legenda ()
{
    system("cls");
    do
    {
    cout << "* Warung Legenda *\n";
    cout << "1. Lihat menu\n";
    cout << "2. Cari menu\n";
    cout << "3. Kembali ke menu utama\n";
    cout << "Pilih : "; cin >> pilih;
    switch (pilih)
    {
        case 1 : 
            while (pilih1 > 9 || pilih1 < 1){
                tampilkanMenu("Legenda");
                cout << "Pilih : "; cin >> pilih1;
            }
            break;

        case 2 :
            cariMenuDiWarung("Legenda");
            break;

        case 3 :
            menu();
            break;

        default : 
            cout << " Pilihan tidak valid!";
            break;
    }
    } while(pilih > 3 || pilih < 1 || pilih1 == 9);
}

void FoodKuy ()
{
    system("cls");
    do { 
    cout << "* Warung FoodKuy *\n";
    cout << "1. Lihat menu\n";
    cout << "2. Cari menu\n";
    cout << "3. Exit\n";
    cout << "Pilih : "; cin >> pilih;
    switch ( pilih ) {
        case 1 :
        while (pilih1 > 9 || pilih1 < 1){
            tampilkanMenu("Foodkuy");
            cout << "Pilih : "; cin >> pilih1;
        }
        break;

    case 2 :
        cariMenuDiWarung("Foodkuy");
        break;
    
    case 3 :
        exit(0);
        break;

    default :
        cout << "Pilihan tidak valid!\n";
        break;
    }

} while ( pilih > 3 || pilih < 1);
} 

void Nusantara ()
{
    system("cls");
    do {
    cout << "* Warung Nusantara *\n";
    cout << "1. Lihat menu\n";
    cout << "2. Cari menu\n";
    cout << "3. Exit\n";
    cout << "Pilih : "; cin >> pilih;
    switch (pilih)
    {
        case 1 :
        while (pilih1 > 9 || pilih < 1) {
                tampilkanMenu("Nusantara");
                cout << "Pilih : "; cin >> pilih1;
            }
            break;
    
        case 2 :
            cariMenuDiWarung("Nusantara");
            break;

        case 3 :
            exit(0);
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }
    } while (pilih > 3 || pilih < 1);
}

void Gepriks()
{
    system("cls");
    do
    {
        cout << "* Warung Gepriks *\n";
        cout << "1. Lihat menu\n";
        cout << "2. Cari menu\n";
        cout << "3. Exit\n";
        cout << "Pilih : "; cin >> pilih;
        switch (pilih)
        {
        case 1 :
            while (pilih1 > 9 || pilih1 < 1) {
                tampilkanMenu("Gepriks");
                cout << "Pilih : "; cin >> pilih1;
            }
            break;

        case 2 :
            cariMenuDiWarung("Gepriks");
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilih > 3 || pilih < 1);
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
    cout << " 1. Makyus \n 2. Jajanan Legenda \n 3. Street Food Kuy! \n 4. Nusantara\n";
    cout << " 5. Gepriks\n 6. Keluar\n";
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
        cout << "Keluar dari program! ";
        exit(0);
        break;

    default : 
        cout << "Input salah harap ulangi input Anda!";
        break;
   }
   
} while (( pilih > 5 || pilih < 1 ));
}

int main () {
    system("cls");
    menu();

return 0;
}
