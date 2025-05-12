#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

const int max_Menu = 100;
string carinama; 
char awal;
int pilih; 
int pilih1 = 0;
void menu();
void maknyus();
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

        {"Ayam Geprek lv 0", 150000, "Gepriks"},
        {"Ayam Geprek lv 1", 160000, "Gepriks"},
        {"Ayam Geprek lv 2", 170000, "Gepriks"},
        {"Ayam Geprek lv 3", 180000, "Gepriks"},
        {"Ayam Geprek lv 4", 190000, "Gepriks"},
        {"Es Teh", 300000, "Gepriks"},
        {"Es Jeruk", 200000, "Gepriks"},
        {"Es Cokelat", 400000, "Gepriks"}
};

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void tampilkanMenu(const string& namaWarung)
{
    cout << "======= Menu " << namaWarung << " =======" << endl;

    cout << "\nMakanan:\n";
    cout << left << setw(5) << "No." << setw(20) << "Nama Menu" << "Harga" << endl;
    int count = 1;
    for (int i = 0; i < max_Menu; i++) {
        if (daftarMenu[i].namaWarung == namaWarung && i % 8 < 5) { 
            cout << left << setw(5) << count << setw(20) << daftarMenu[i].nama
                 << "Rp " << daftarMenu[i].harga << endl;
            count++;
        }
    }
    cout << left << setw(5) << count << setw(20) << "Tidak pesan makanan\n";
    int totalMakanan = count;

    cout << "\nMinuman:\n";
    cout << left << setw(5) << "No." << setw(20) << "Nama Menu" << "Harga" << endl;
    int minumCount = 1;
    for (int i = 0; i < max_Menu; i++) {
        if (daftarMenu[i].namaWarung == namaWarung && i % 8 >= 5 && i % 8 <= 7) { 
            cout << left << setw(5) << minumCount << setw(20) << daftarMenu[i].nama
                 << "Rp " << daftarMenu[i].harga << endl;
            minumCount++;
        }
    }
    cout << left << setw(5) << minumCount << setw(20) << "Tidak pesan minuman\n";
    if ( pilih1 == 10 ) {
       menu();
        return;
    }
    cout << "\n10. Kembali ke menu awal\n";
}

void pesanMenu(const string& namaWarung)
{
    tampilkanMenu(namaWarung);
    int pilihan;
    cout << "Pilih menu : ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= 8) {
        cout << "Anda memesan " << daftarMenu[pilihan - 1].nama
             << " dari " << namaWarung << endl;
        cout << "Harga: Rp " << daftarMenu[pilihan - 1].harga << endl;
    } else if (pilihan == 10) {
        cout << "Kembali ke menu awal.\n";
    } else {
        cout << "Pilihan tidak valid!\n";
    }
}

void cariMenuDiWarung(const string& namaWarung)
{
    bool found = false;
    cout << "Masukkan nama menu yang dicari : ";
    cin.ignore();
    getline(cin, carinama);

    for (int i = 0; i < sizeof(daftarMenu) / sizeof(daftarMenu[0]); i++)
    {
        if (toLowerCase(daftarMenu[i].namaWarung) == toLowerCase(namaWarung) &&
            toLowerCase(daftarMenu[i].nama) == toLowerCase(carinama))
        {
            cout << "\nMenu ditemukan di " << daftarMenu[i].namaWarung << " :\n"
                 << daftarMenu[i].nama << " - Rp" << daftarMenu[i].harga << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Menu tidak ditemukan di warung " << namaWarung << ".\n";

    cout << "Kembali ke menu awal (y/n)? : "; cin >> awal;
    if (awal == 'y' || awal == 'Y')
        if (namaWarung == "Maknyus")
            maknyus();
        if (namaWarung == "Legenda")
            Legenda();
        if (namaWarung == "Foodkuy")
            FoodKuy();
        if (namaWarung == "Nusantara")
            Nusantara();
        if (namaWarung == "Gepriks")
            Gepriks();
}

void sorting(const string& namaWarung)
{   
    system("cls");
    do {
    cout << "== Sorting Menu " << namaWarung << " ==\n";
    cout << "1. Berdasarkan harga termurah (Ascending)\n";
    cout << "2. Berdasarkan harga termahal (Descending)\n";
    cout << "Pilih: ";
    cin >> pilih;

    Menu menuWarung[max_Menu];
    int jumlah = 0;
    for (int i = 0; i < max_Menu; i++) {
        if (toLowerCase(daftarMenu[i].namaWarung) == toLowerCase(namaWarung)) {
            menuWarung[jumlah++] = daftarMenu[i];
        }
    }

    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            bool perluTukar = false;
            if (pilih == 1 && menuWarung[j].harga > menuWarung[j + 1].harga) {
                perluTukar = true;
            } else if (pilih == 2 && menuWarung[j].harga < menuWarung[j + 1].harga) {
                perluTukar = true;
            }

            if (perluTukar) {
                swap(menuWarung[j], menuWarung[j + 1]);
            }
        }
    }

    cout << "\n=== Menu " << namaWarung << " (Sudah urut) ===\n";
    cout << left << setw(30) << "Nama Menu" << "Harga\n";
    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(30) << menuWarung[i].nama << "Rp" << menuWarung[i].harga << endl;
    }
} while (pilih > 2 || pilih < 1);
}

void maknyus ()
{   
    system("cls");
    do {
        cout << "* Warung Maknyus *\n1. Lihat menu\n2. Pesan Menu\n3. Cari menu\n4. Sorting\n5. Kembali ke menu utama\nPilih : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
            while (pilih1 > 10 || pilih1 < 1){
            tampilkanMenu("Maknyus");
            cout << "Pilih : "; cin >> pilih1;
                maknyus();
                break;

            case 2 : 
                 pesanMenu("Makyus");
                 maknyus();
                 break;
            case 3:
                cariMenuDiWarung("Makyus");
                maknyus();
                break;
            
            case 4 :
                sorting("Makyus");
                maknyus();
                break;

            case 5:
                menu();
                break;

            default : 
                cout << " Pilihan tidak valid!\n";
                break;
        }
    } 
     } while (pilih >5 || pilih < 1 || pilih1 == 10);
}

  void Legenda ()
{
    system("cls");
    do
    {
    cout << "* Warung Legenda *\n";
    cout << "1. Lihat menu\n";
    cout << "2. Pesan menu\n";
    cout << "3. Cari menu\n";
    cout << "4. Sorting\n";
    cout << "5. Kembali ke menu utama\n";
    cout << "Pilih : "; cin >> pilih;
    switch (pilih)
    {
        case 1 : 
            while (pilih1 > 10 || pilih1 < 1){
                tampilkanMenu("Legenda");
                cout << "Pilih : "; cin >> pilih1;
            }
            Legenda();
            break;

        case 2 : 
            pesanMenu("Legenda");
            Legenda();
            break;

        case 3 :
            cariMenuDiWarung("Legenda");
            Legenda();
            break;
        case 4 :
            sorting("Legenda");
            Legenda();
            break;

        case 5 :
            menu();
            break;

        default : 
            cout << " Pilihan tidak valid!";
            break;
    }
    } while(pilih > 5 || pilih < 1 || pilih1 == 10);
}

void FoodKuy ()
{
    system("cls");
    do { 
    cout << "* Warung FoodKuy *\n";
    cout << "1. Lihat menu\n";
    cout << "2. Pesan menu\n";
    cout << "3. Cari menu\n";
    cout << "4. Sorting\n";
    cout << "5. Kembali ke menu utama\n";
    cout << "Pilih : "; cin >> pilih;
    switch ( pilih ) {
        case 1 :
        while (pilih1 > 10 || pilih1 < 1){
            tampilkanMenu("Foodkuy");
            cout << "Pilih : "; cin >> pilih1;
        }
        FoodKuy();
        break;
    
    case 2 : 
         pesanMenu("Foodkuy");
         FoodKuy();
         break;

    case 3 :
        cariMenuDiWarung("Foodkuy");
        FoodKuy();
        break;
    
    case 4 :
        sorting("Foodkuy");
        FoodKuy();
        break;

    case 5 :
        menu();
        break;

    default :
        cout << "Pilihan tidak valid!\n";
        break;
    }

} while ( pilih > 5 || pilih < 1 || pilih1 == 10);
} 

void Nusantara ()
{
    system("cls");
    do {
    cout << "* Warung Nusantara *\n";
    cout << "1. Lihat menu\n";
    cout << "2. Pesan Menu\n";
    cout << "3. Cari menu\n";
    cout << "4. Sorting\n";
    cout << "5. Kembali ke menu utama\n";
    cout << "Pilih : "; cin >> pilih;
    switch (pilih)
    {
        case 1 :
        while (pilih1 > 9 || pilih1 < 1) {
                tampilkanMenu("Nusantara");
                cout << "Pilih : "; cin >> pilih1;
            }
            Nusantara();
            break;

        case 2 : 
            pesanMenu("Nusantara");
            Nusantara();
            break;
    
        case 3 :
            cariMenuDiWarung("Nusantara");
            Nusantara();
            break;
        
        case 4 :
            sorting("Nusantara");
            Nusantara();
            break;

        case 5 :
            menu();
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }
    } while (pilih > 5 || pilih < 1 || pilih1 == 10);
}

void Gepriks()
{
    system("cls");
    do
    {
        cout << "* Warung Gepriks *\n";
        cout << "1. Lihat menu\n";
        cout << "2. Pesan Menu\n";
        cout << "3. Cari menu\n";
        cout << "4. Sorting\n";
        cout << "5. Kembali ke menu utama\n";
        cout << "Pilih : "; cin >> pilih;
        switch (pilih)
        {
        case 1 :
            while (pilih1 > 9 || pilih1 < 1) {
                tampilkanMenu("Gepriks");
                cout << "Pilih : "; cin >> pilih1;
            }
            Gepriks();
            break;

        case 2 : 
            pesanMenu("Gepriks");
            Gepriks();
            break;

        case 3 :
            cariMenuDiWarung("Gepriks");
            Gepriks();
            break;

        case 4 :
            sorting("Gepriks");
            Gepriks();
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilih > 4 || pilih < 1 || pilih1 == 10);
}

void cariMenu (const string& namaWarung)
{
    system ("cls");
    bool found = false;
    cout << " Masukan nama menu yang dicari : ";
    cin.ignore();
    getline(cin, carinama);
    cout << "\nMenu yang ditemukan : \n";
    for (int i = 0; i < max_Menu; i++)
    {
        if (toLowerCase(daftarMenu[i].namaWarung) == toLowerCase(namaWarung) &&
            toLowerCase(daftarMenu[i].nama) == toLowerCase(carinama))
        {
            cout << "Menu ditemukan di " << daftarMenu[i].namaWarung << ": "
                 << daftarMenu[i].nama << " - Rp" << daftarMenu[i].harga << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Menu tidak ditemukan di warung \n" << namaWarung << ".";
}

void menu ()
{
   do {
    system("cls");
    cout << " * Selamat datang di Kuliner Street Food ! * " << endl;
    cout << " 1. Makyus \n 2. Legenda \n 3. FoodKuy! \n 4. Nusantara\n";
    cout << " 5. Gepriks\n 6. Keluar\n";
    cout << " Pilih Warung : ";
    cin >> pilih;
    switch (pilih) {
    case 1 : 
        maknyus();
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
   
} while (( pilih > 5 || pilih < 1 ));
}

int main () {
    system("cls");
    menu();

return 0;
}
