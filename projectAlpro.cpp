#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

const int max_Menu = 100;
string carinama; 
char awal;
int pilih; 
int pilih1;
int jumlahPesanan;
char confirm;
string namaMakanan = "", namaMinuman = "";
int hargaMakanan = 0, hargaMinuman = 0;
int jumlahMakanan = 0, jumlahMinuman = 0;

void menu();
void maknyus();
void Legenda();
void FoodKuy();
void Nusantara();
void Gepriks();
void konfirmasi(const string& namaWarung);

struct Menu 
{
    string nama;
    int harga;
    string namaWarung;
};

Menu daftarMenu[max_Menu] =
{
    {"Seblak", 120000, "Maknyus"},
    {"Mie Goreng", 70000, "Maknyus"},
    {"Bakso Bakar", 100000, "Maknyus"},
    {"Mie Ayam", 90000, "Maknyus"},
    {"Mie Pedas", 100000, "Maknyus"},
    {"Es Teh", 300000, "Maknyus"},
    {"Es Jeruk", 300000, "Maknyus"},
    {"Air Putih", 200000, "Maknyus"},

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

string toLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void tampilkanMenu(const string& namaWarung)
{
    cout << "======= Menu " << namaWarung << " =======" << endl;
    cout << "\nMakanan:\n";
    cout << left << setw(5) << "No." << setw(20) << "Nama Menu" << "Harga" << endl;
    int nomor = 1;
    for (int i = 0; i < max_Menu; i++) {
        if (daftarMenu[i].namaWarung == namaWarung && i % 8 < 5) { 
            cout << left << setw(5) << nomor << setw(20) << daftarMenu[i].nama
                 << "Rp " << daftarMenu[i].harga << endl;
            nomor++;
        }
    }
    cout << left << setw(5) << nomor << setw(20) << "Tidak pesan makanan\n";

    cout << "\nMinuman:\n";
    cout << left << setw(5) << "No." << setw(20) << "Nama Menu" << "Harga" << endl;
    int nomor2 = 1;
    for (int i = 0; i < max_Menu; i++) {
        if (daftarMenu[i].namaWarung == namaWarung && i % 8 >= 5 && i % 8 <= 7) { 
            cout << left << setw(5) << nomor2 << setw(20) << daftarMenu[i].nama
                 << "Rp " << daftarMenu[i].harga << endl;
            nomor2++;
        }
    }
    cout << left << setw(5) << nomor2 << setw(20) << "Tidak pesan minuman\n";
}

void pesanMenu(const string& namaWarung)
{
        tampilkanMenu(namaWarung);
        Menu makanan[5], minuman[3];
        int mknIdx = 0, mnmIdx = 0;

        for (int i = 0; i < max_Menu; i++) {
            if (daftarMenu[i].namaWarung == namaWarung) {
                if (i % 8 < 5 && mknIdx < 5)
                    makanan[mknIdx++] = daftarMenu[i];
                else if (i % 8 >= 5 && i % 8 <= 7 && mnmIdx < 3)
                    minuman[mnmIdx++] = daftarMenu[i];
            }
        }

        int pilihMakan = 0, pilihMinum = 0;

        while (pilihMakan < 1 || pilihMakan > mknIdx + 1) {
            cout << "\nPilih makanan (1-" << mknIdx + 1 << ") : ";
            cin >> pilihMakan;
        }

        if (pilihMakan == mknIdx + 1) {
            cout << "Anda tidak memesan makanan.\n";
            namaMakanan = "";
            hargaMakanan = jumlahMakanan = 0;
        } else {
            namaMakanan = makanan[pilihMakan - 1].nama;
            hargaMakanan = makanan[pilihMakan - 1].harga;
            cout << "Jumlah makanan : "; cin >> jumlahMakanan;
        }

        while (pilihMinum < 1 || pilihMinum > mnmIdx + 1) {
            cout << "\nPilih minuman (1-" << mnmIdx + 1 << ") : ";
            cin >> pilihMinum;
        }

        if (pilihMinum == mnmIdx + 1) {
            cout << "Anda tidak memesan minuman.\n";
            namaMinuman = "";
            hargaMinuman = jumlahMinuman = 0;
        } else {
            namaMinuman = minuman[pilihMinum - 1].nama;
            hargaMinuman = minuman[pilihMinum - 1].harga;
            cout << "Jumlah minuman : "; cin >> jumlahMinuman;
        }

        konfirmasi(namaWarung);
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
        else if (namaWarung == "Legenda")
            Legenda();
        else if (namaWarung == "Foodkuy")
            FoodKuy();
        else if (namaWarung == "Nusantara")
            Nusantara();
        else if (namaWarung == "Gepriks")
            Gepriks();
    else if (awal == 'n' || awal == 'N')
        menu();
}

void sorting(const string& namaWarung)
{   
    system("cls");
    do {
    cout << "======= Sorting Menu " << namaWarung << " =======\n";
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
            } else if (pilih > 2 || pilih < 1){
                cout << "Pilihan tidak valid\n";
            }

            if (perluTukar) {
                swap(menuWarung[j], menuWarung[j + 1]);
            }
        }
    }

    cout << "\n======= Menu " << namaWarung << " (Sudah urut) =======\n";
    cout << left << setw(30) << "Nama Menu" << "Harga\n";
    for (int i = 0; i < jumlah; i++)
    {
        cout << left << setw(30) << menuWarung[i].nama << "Rp" << menuWarung[i].harga << endl;
    }

    cout << "\nKembali ke menu awal (y/n)? : "; cin >> awal;
    if (awal == 'y' || awal == 'Y') {
        if (namaWarung == "Maknyus")
            maknyus();
        else if (namaWarung == "Legenda")
            Legenda();
        else if (namaWarung == "Foodkuy")
            FoodKuy();
        else if (namaWarung == "Nusantara")
            Nusantara();
        else if (namaWarung == "Gepriks")
            Gepriks();
    }
    else if (awal == 'n' || awal == 'N'){
        menu();
    }
} while (pilih > 2 || pilih < 1);
}

void maknyus ()
{   
    do
    {
        system("cls");
        cout << "------------------\n";
        cout << "| Warung Maknyus |\n";
        cout << "------------------\n";
        cout << "1. Lihat menu\n";
        cout << "2. Pesan Menu\n";
        cout << "3. Cari menu\n";
        cout << "4. Sorting\n";
        cout << "5. Kembali ke menu utama\nPilih : ";
        cin >> pilih;
        switch (pilih)
        {
            case 1:
                tampilkanMenu("Maknyus");
                cout << "\nKembali ke menu awal (y/n)? : "; cin >> awal;
                if (awal == 'n' || awal == 'N')
                    menu();
                break;

            case 2 : 
                pesanMenu("Maknyus");
                break;

            case 3:
                cariMenuDiWarung("Maknyus");
                break;
            
            case 4 :
                sorting("Maknyus");
                break;

            case 5:
                menu();
                break;

            default : 
                cout << " Pilihan tidak valid!\n";
                break;
        
        }
    } while (pilih > 5 || pilih < 1 || awal == 'y' || awal == 'Y');
}

void Legenda ()
{
    do
    {
        system("cls");
        cout << "------------------\n";
        cout << "| Warung Legenda |\n";
        cout << "------------------\n";
        cout << "1. Lihat menu\n";
        cout << "2. Pesan menu\n";
        cout << "3. Cari menu\n";
        cout << "4. Sorting\n";
        cout << "5. Kembali ke menu utama\n";
        cout << "Pilih : "; cin >> pilih;
        switch (pilih)
        {
            case 1 : 
                tampilkanMenu("Legenda");
                cout << "\nKembali ke menu awal (y/n)? : "; cin >> awal;
                if (awal == 'n' || awal == 'N')
                    menu();
                break;

            case 2 : 
                pesanMenu("Legenda");
                break;

            case 3 :
                cariMenuDiWarung("Legenda");
                break;

            case 4 :
                sorting("Legenda");
                break;

            case 5 :
                menu();
                break;

            default : 
                cout << " Pilihan tidak valid!";
                break;
        }
    } while (pilih > 5 || pilih < 1 || awal == 'y' || awal == 'Y');
}

void FoodKuy ()
{
    do
    { 
        system("cls");
        cout << "------------------\n";
        cout << "| Warung FoodKuy |\n";
        cout << "------------------\n";
        cout << "1. Lihat menu\n";
        cout << "2. Pesan menu\n";
        cout << "3. Cari menu\n";
        cout << "4. Sorting\n";
        cout << "5. Kembali ke menu utama\n";
        cout << "Pilih : "; cin >> pilih;
        switch ( pilih )
        {
            case 1 :
            tampilkanMenu("Foodkuy");
            cout << "\nKembali ke menu awal (y/n)? : "; cin >> awal;
                if (awal == 'n' || awal == 'N')
                    menu();
            break;
        
            case 2 : 
            pesanMenu("Foodkuy");
            break;

            case 3 :
            cariMenuDiWarung("Foodkuy");
            break;
        
            case 4 :
            sorting("Foodkuy");
            break;

            case 5 :
            menu();
            break;

            default :
            cout << "Pilihan tidak valid!\n";
            break;
        }

    } while ( pilih > 5 || pilih < 1 || awal == 'y' || awal == 'Y');
} 

void Nusantara ()
{
    do
    {
        system("cls");
        cout << "--------------------\n";
        cout << "| Warung Nusantara |\n";
        cout << "--------------------\n";
        cout << "1. Lihat menu\n";
        cout << "2. Pesan Menu\n";
        cout << "3. Cari menu\n";
        cout << "4. Sorting\n";
        cout << "5. Kembali ke menu utama\n";
        cout << "Pilih : "; cin >> pilih;
        switch (pilih)
        {
            case 1 :
                tampilkanMenu("Nusantara");
                cout << "\nKembali ke menu awal (y/n)? : "; cin >> awal;
                if (awal == 'n' || awal == 'N')
                    menu();
                break;

            case 2 : 
                pesanMenu("Nusantara");
                break;
        
            case 3 :
                cariMenuDiWarung("Nusantara");
                break;
            
            case 4 :
                sorting("Nusantara");
                break;

            case 5 :
                menu();
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilih > 5 || pilih < 1 || awal == 'y' || awal == 'Y');
}

void Gepriks()
{
    do
    {
        system("cls");
        cout << "------------------\n";
        cout << "| Warung Gepriks |\n";
        cout << "------------------\n";
        cout << "1. Lihat menu\n";
        cout << "2. Pesan Menu\n";
        cout << "3. Cari menu\n";
        cout << "4. Sorting\n";
        cout << "5. Kembali ke menu utama\n";
        cout << "Pilih : "; cin >> pilih;
        switch (pilih)
        {
            case 1 :
            tampilkanMenu("Gepriks");
            cout << "\nKembali ke menu awal (y/n)? : "; cin >> awal;
                if (awal == 'n' || awal == 'N')
                    menu();
            break;

            case 2 : 
            pesanMenu("Gepriks");
            break;

            case 3 :
            cariMenuDiWarung("Gepriks");
            break;

            case 4 :
            sorting("Gepriks");
            break;

            case 5 :
            menu();
            break;

            default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilih > 5 || pilih < 1 || awal == 'Y' || awal == 'y');
}

void konfirmasi(const string& namaWarung)
{
    int totalHarga = (hargaMakanan * jumlahMakanan) + (hargaMinuman * jumlahMinuman);
    cout << "\n========= Konfirmasi Pesanan =========\n";
    cout << "Warung: " << namaWarung << endl;
    if (!namaMakanan.empty()) {
        cout << "- Makanan : " << namaMakanan 
             << " x" << jumlahMakanan 
             << " = Rp " << hargaMakanan * jumlahMakanan << endl;
    } else {
        cout << "- Makanan : Tidak dipesan\n";
    }

    if (!namaMinuman.empty()) {
        cout << "- Minuman : " << namaMinuman 
             << " x" << jumlahMinuman 
             << " = Rp " << hargaMinuman * jumlahMinuman << endl;
    } else {
        cout << "- Minuman : Tidak dipesan\n";
    }

    cout << "--------------------------------------\n";
    cout << "Total Bayar: Rp " << totalHarga << endl;
    cout << "======================================\n";

    cout << "Apakah pesanan sudah benar (y/n)? : "; cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        ofstream file("pesanan.txt", ios::app);
        if (file.is_open())
        {
            file << "Warung : " << namaWarung << endl;
            if (!namaMakanan.empty()) {
                file << "- Makanan : " << namaMakanan 
                     << " x" << jumlahMakanan 
                     << " = Rp " << hargaMakanan * jumlahMakanan << endl;
            } else {
                file << "- Makanan : Tidak dipesan\n";
            }

            if (!namaMinuman.empty()) {
                file << "- Minuman : " << namaMinuman 
                     << " x" << jumlahMinuman 
                     << " = Rp " << hargaMinuman * jumlahMinuman << endl;
            } else {
                file << "- Minuman : Tidak dipesan\n";
            }

            file << "Total Bayar : Rp " << totalHarga << endl;
            file << "--------------------------------------\n";
            file.close();
            cout << "\n[Pesanan telah disimpan ke file 'pesanan.txt']\n";
        } else {
            cout << "\n[Gagal membuka file!]\n";
        }
    } else {
        cout << "\nSilakan periksa kembali pesanan Anda\n";
    }

    cout << "\nKembali ke menu awal (y/n)? : "; cin >> awal;
    if (awal == 'y' || awal == 'Y')
        if (namaWarung == "Maknyus")
            maknyus();
        else if (namaWarung == "Legenda")
            Legenda();
        else if (namaWarung == "Foodkuy")
            FoodKuy();
        else if (namaWarung == "Nusantara")
            Nusantara();
        else if (namaWarung == "Gepriks")
            Gepriks();
    else if (awal == 'n' || awal == 'N')
        menu();

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
    
    cout << "\n\nKembali ke menu awal (y/n)? : "; cin >> awal;
    if (awal == 'y' || awal == 'Y')
        if (namaWarung == "Maknyus")
            maknyus();
        else if (namaWarung == "Legenda")
            Legenda();
        else if (namaWarung == "Foodkuy")
            FoodKuy();
        else if (namaWarung == "Nusantara")
            Nusantara();
        else if (namaWarung == "Gepriks")
            Gepriks();
    else if (awal == 'n' || awal == 'N')
        menu();
}

void menu ()
{
    do
    {
    system("cls");
    cout << " ===========================================\n";
    cout << " | Selamat datang di Kuliner Street Food ! |" << endl;
    cout << " ===========================================\n";
    cout << " 1. Maknyus \n 2. Legenda \n 3. FoodKuy! \n 4. Nusantara\n";
    cout << " 5. Gepriks\n 6. Keluar\n";
    cout << " Pilih Warung : ";
    cin >> pilih;
    switch (pilih)
    {
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
} while (( pilih > 6 || pilih < 1 || awal == 'n' || awal == 'N'));
}

int main ()
{
    Menu* daftarMenu = new Menu[max_Menu];
    system("cls");
    menu();
    return 0;
}
