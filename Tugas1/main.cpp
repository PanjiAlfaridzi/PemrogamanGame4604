#include <iostream>
using namespace std;

int stokk(int a, int b, int c) {
    cout << "Inventory:" << endl;
    cout << "Stok Herb = " << a << endl;
    cout << "Stok HP Potion = " << b << endl;
    cout << "Stok Mana Potion = " << c << endl;

    return 0;
}

int useHerb(int a, int b, int c){
    int totalHP;
    int jmlpotion, totalStok;
    totalHP = 0;
    cout << "Berapa Herb yang ingin Anda gunakan?" << endl;
    cin >> jmlpotion;
    cout << endl;
    totalHP = a + b * jmlpotion;
    cout << "HP bertambah sebanyak: " << jmlpotion * b << endl;
    cout << "Total HP: " << totalHP << endl;
    totalStok = c - jmlpotion;
    cout << "Sisa stok: " << totalStok << endl;

    return 0;
}

int useHPPotion(int a, int b, int c) {
    int totalHP;
    int jmlpotion, totalStok;
    totalHP = 0;
    cout << "Berapa HP Potion yang ingin Anda gunakan?" << endl;
    cin >> jmlpotion;
    cout << endl;
    totalHP = a + b * jmlpotion;
    cout << "HP bertambah sebanyak: " << jmlpotion * b << endl;
    cout << "Total HP: " << totalHP << endl;
    totalStok = c - jmlpotion;
    cout << "Sisa stok: " << totalStok << endl;

    return 0;
}

int useManaPotion(int a, int b, int c){
    int totalMana;
    int jmlpotion, totalStok;
    totalMana = 0;
    cout << "Berapa Mana Potion yang ingin Anda gunakan?" << endl;
    cin >> jmlpotion;
    cout << endl;
    totalMana = a + b * jmlpotion;
    cout << "Mana bertambah sebanyak: " << jmlpotion * b << endl;
    cout << "Total Mana: " << totalMana << endl;
    totalStok = c - jmlpotion;
    cout << "Sisa stok: " << totalStok << endl;

    return 0;
}

int changeSword(int a, int b, int c) {
    int swords[3] = {10, 20, 30};
    b = 0;
    int dmg = swords[b];
        if (a >= 0 && a < 3) {
            dmg = swords[a];
            b = a;
            cout << "Anda mengganti pedang ke nomor " << a << ". DMG sekarang adalah " << dmg + c << endl;
        } else {
            cout << "Nomor pedang tidak valid." << endl;
        }
        return 0;
}

int main() {
    int herbs, mana_potion, hp_potion;
    int hp, mana, damage, stok, equippedsword;
    int pilih;

    int stokherb = 10;
    int stokHP = 10;
    int stokMana = 10;

    herbs = 10;
    hp_potion = 50;
    mana_potion = 50;

    cout << "Input status karakter:" << endl;
    cout << "HP: ";
    cin >> hp;
    cout << "Mana: ";
    cin >> mana;
    cout << "Damage: ";
    cin >> damage;
    cout << endl;

    cout << "Tampilan status:" << endl;
    cout << "HP: " << hp << endl;
    cout << "Mana: " << mana << endl;
    cout << "Damage: " << damage << endl;
    cout << "Equipped Sword: " << equippedsword << endl;
    cout << endl;

    stokk(stokherb, stokHP, stokMana);

    while (true) {
    cout << endl;
    cout << "1. Use Herbs" << endl;
    cout << "2. Use HP Potion" << endl;
    cout << "3. Use Mana Potion" << endl;
    cout << "4. Ganti Sword" << endl;
    cout << "5. Exit" << endl;
    cout << "Pilihan ke (1-4): ";
    cin >> pilih;
    cout << endl;

    // Kode belum lengkap, silakan lengkapi sesuai kebutuhan
    switch(pilih){
        case 1:
            useHerb(hp, herbs, stokherb);

            break;
        case 2:
            useHPPotion(hp, hp_potion, stokHP);

            break;
        case 3:
            useManaPotion(mana, mana_potion, stokMana);

            break;
        case 4:
            int swordNumber;
            cout << "Masukkan nomor pedang (0-2): ";
            cin >> swordNumber;
            changeSword(swordNumber, equippedsword, damage);

            break;
        case 5:
            cout << "Keluar dari program." << endl;
            return 0;
        default:
            cout << "pilihan salah" << endl;
        }
    }
}
