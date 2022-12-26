#include "city.h"
#include "tourist.h"

#include <iostream>

int main()
{
    listCity Lcity;
    listTourist Ltourist;

    adrCity adrC;
    adrTourist adrT;
    adrRelasi adrR;

    infoCity dataCity;
    infoTourist dataTourist;
    int number;
    int i;
    char kembali;

    int pilihan;
    string tampil,hapus;

    createCityList(Lcity);
    createTouristList(Ltourist);

    pilihan = selectmenu();

    while (pilihan != 0){
        switch (pilihan){
            case 1:{
                i =1;
                cout<<"input jumlah kota: ";
                cin>> number;
                cout<<endl;

                while(i<=number){
                    cout<<"Input Data Kota Wisata ke-"<<i<<endl;
                    addMainCity(dataCity);
                    adrC = newElemetCity(dataCity);
                    insertLastC(Lcity, adrC);
                    i++;
                }
                break;
            }
            case 2:{
                i=1;
                cout<<"input jumlah data turis: ";
                cin>> number;
                cout<<endl;

                while(i<=number){
                    cout<<"Data Turis ke-"<<i<<endl;
                    addMainTourist(dataTourist);
                    adrT = newElemenTourist(dataTourist);
                    insertLastT(Ltourist, adrT);
                    i++;
                }
                break;
            }
            case 3:{
                i=1;
                cout<<"input jumlah data perjalanan: ";
                cin>> number;
                cout<<endl;
                infoCity cit;
                infoTourist tou;

                while(i<=number){
                    cout<<"Data Perjalanan ke-"<<i<<endl;
                    addForFind(cit,tou);
                    adrC = findElmCity(Lcity, cit);
                    adrT = findElmTourist(Ltourist, tou);
                    adrR = newElemenRelasi(adrT);
                    insertLastR(child(adrC),adrR );
                    i++;
                }
                break;
            }
            case 4:{
                cout<<"Mau hapus data kota yang mana ? (cari/akhir)";
                cin>>hapus;
                if (hapus=="cari"){
                    cout<<"Masukkan data kota yang ingin dihapus : "<<endl;
                    cout<<"Nama Kota: ";
                    cin>>dataCity.name;
                    cout<<"Code : ";
                    cin>>dataCity.code;
                    cout<<"Total Destinasi : ";
                    cin>>dataCity.totalDestination;
                    deleteCity(Lcity, dataCity);
                }else if (hapus=="akhir"){
                    deleteLastC(Lcity, adrC);
                }
                break;
            }
            case 5:{
                cout<<"semua / turis / kota :";
                cin>>tampil;

                if(tampil == "semua" || tampil == "Semua"){
                    ShowAllData(Lcity);
                }else if (tampil == "turis" || tampil == "Turis"){
                    showTourist(Ltourist);
                }else if (tampil == "kota" || tampil == "Kota"){
                    showCity(Lcity);
                }
                break;
            }
            case 6:{
                FindMaxData(Lcity);
                break;
            }
            case 7:{
                FindMinData(Lcity);
                break;
            }
            case 8:{
                adrC = first(Lcity);
                showRelasi(child(adrC));
            }
            }
            cout << endl<< "Kembali ke menu utama? (Y/N): ";
            cin >> kembali;

            if (kembali == 'Y' || kembali == 'y'){
                cout << endl;
                pilihan = selectmenu();
            }
            else if (kembali == 'N' || kembali == 'n'){
                pilihan = 0;
            }
        }
        cout << endl<< "ANDA TELAH KELUAR DARI PROGRAM"<<endl;
    return 0;
}
