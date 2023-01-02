#include "city.h"
#include "tourist.h"

#include <iostream>

int main(){
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
    int kodeC,kodeT;
    string tampil,hapus;
    string namaKota, namaTourist;

    createCityList(Lcity);
    createTouristList(Ltourist);

    //data bawaan kota
    dataCity.name = "Bogor";
    dataCity.code = 3201;
    dataCity.totalDestination = 11;
    adrC = newElementCity(dataCity);
    addToLastC(Lcity, adrC);

    dataCity.name = "Sukabumi";
    dataCity.code = 3202;
    dataCity.totalDestination = 11;
    adrC = newElementCity(dataCity);
    addToLastC(Lcity, adrC);

    dataCity.name = "Cianjur";
    dataCity.code = 3203;
    dataCity.totalDestination = 11;
    adrC = newElementCity(dataCity);
    addToLastC(Lcity, adrC);

    dataCity.name = "Bandung";
    dataCity.code = 3204;
    dataCity.totalDestination = 11;
    adrC = newElementCity(dataCity);
    addToLastC(Lcity, adrC);

    //data bawaan turis
    dataTourist.name = "James";
    dataTourist.status = "WNA";
    dataTourist.gender = 'L';
    dataTourist.kode = 1010;
    adrT = newElementTourist(dataTourist);
    addToLastT(Ltourist, adrT);

    dataTourist.name = "Risa";
    dataTourist.status = "WNI";
    dataTourist.gender = 'P';
    dataTourist.kode = 1121;
    adrT = newElementTourist(dataTourist);
    addToLastT(Ltourist, adrT);

    dataTourist.name = "Paijo";
    dataTourist.status = "WNI";
    dataTourist.gender = 'L';
    dataTourist.kode = 1122;
    adrT = newElementTourist(dataTourist);
    addToLastT(Ltourist, adrT);

    dataTourist.name = "Mary";
    dataTourist.status = "WNA";
    dataTourist.gender = 'P';
    dataTourist.kode = 1211;
    adrT = newElementTourist(dataTourist);
    addToLastT(Ltourist, adrT);

    //data relasi perjalanan
    adrC = findElmCity(Lcity, 3201);
    adrT = findElmTourist(Ltourist, 1010);
    adrR = newElemenRelasi(adrT);
    addToLastR(child(adrC),adrR);
    adrT = findElmTourist(Ltourist, 1121);
    adrR = newElemenRelasi(adrT);
    addToLastR(child(adrC),adrR);

    adrC = findElmCity(Lcity, 3202);
    adrT = findElmTourist(Ltourist, 1121);
    adrR = newElemenRelasi(adrT);
    addToLastR(child(adrC),adrR);
    adrT = findElmTourist(Ltourist, 1211);
    adrR = newElemenRelasi(adrT);
    addToLastR(child(adrC),adrR);
    adrT = findElmTourist(Ltourist, 1122);
    adrR = newElemenRelasi(adrT);
    addToLastR(child(adrC),adrR);

    adrC = findElmCity(Lcity, 3204);
    adrT = findElmTourist(Ltourist, 1211);
    adrR = newElemenRelasi(adrT);
    addToLastR(child(adrC),adrR);

    //menu
    pilihan = selectMenu();

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
                    adrC = newElementCity(dataCity);
                    addToLastC(Lcity, adrC);
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
                    adrT = newElementTourist(dataTourist);
                    addToLastT(Ltourist, adrT);
                    i++;
                }
                break;
            }
            case 3:{
                i=1;
                cout<<"Input jumlah data perjalanan: ";
                cin>> number;
                cout<<endl;
                while(i<=number){
                    cout<<"Data Perjalanan ke-"<<i<<endl;
                    addForTrip(namaKota, kodeC, namaTourist, kodeT);
                    adrC = findElmCity(Lcity, kodeC);
                    adrT = findElmTourist(Ltourist, kodeT);
                    adrR = newElemenRelasi(adrT);
                    addToLastR(child(adrC),adrR );
                    i++;
                }
                break;
            }
            case 4:{
                cout<<"Menghapus Data pada:"<<endl;
                cout<<"a. Hapus Data Kota Wisata"<<endl;
                cout<<"b. Hapus Data Turis di kota tertentu"<<endl;
                cout<<"Masukan Pilihan: ";
                cin>>hapus;
                cout<<endl;
                if (hapus == "a" || hapus == "A"){
                    cout<<"Masukkan data kota yang ingin dihapus : "<<endl;
                    cout<<"Nama Kota Wisata: ";
                    cin>>namaKota;
                    cout<<"Kode Kota : ";
                    cin>>kodeC;
                    deleteCity(Lcity,namaKota,kodeC);
                }else if(hapus == "b" || hapus == "B"){
                    cout<<"Masukkan data turis yang ingin dihapus di kota tertentu"<<endl;
                    cout<<"Nama Kota Wisata: ";
                    cin>>namaKota;
                    cout<<"Kode Kota: ";
                    cin>>kodeC;
                    cout<<"Nama Turis: ";
                    cin>>namaTourist;
                    cout<<"Kode Turis : ";
                    cin>>kodeT;
                    deleteTourist(Lcity, Ltourist, kodeC,  kodeT);
                }
                break;
            }
            case 5:{
                cout<<"Tampilkan Data Pada: "<<endl;
                cout<<"a. Menampilkan Data Kota Wisata dengan pengunjung nya"<<endl;
                cout<<"b. Menampilkan Data Turis"<<endl;
                cout<<"c. Menampilkan Data Kota Wisata"<<endl;
                cout<<"d. Menampilkan Riwayat Perjalanan Turis"<<endl<<endl;
                cout<<"Masukan Pilihan: ";
                cin>>tampil;
                cout<<endl;

                if(tampil == "a" || tampil == "A"){
                    ShowAllData(Lcity);
                }else if (tampil == "b" || tampil == "B"){
                    showTourist(Ltourist);
                }else if (tampil == "c" || tampil == "C"){
                    showCity(Lcity);
                }else if(tampil == "d" || tampil == "D"){
                    ShowInfoTourist(Ltourist);
                    cout<<endl;
                    cout<<"Masukan Nama Turis: ";
                    cin>>namaTourist;
                    cout<<"Masukan Kode Turis: ";
                    cin>>kodeT;
                    showTouristInCity(Lcity,Ltourist, kodeT);
                }
                break;
            }
            case 6:{
                cout<<"Cari Data Paling Banyak pada: "<<endl;
                cout<<"a. Data Kota Wisata yang paling banyak dikunjungi oleh turis"<<endl;
                cout<<"b. Data Turis yang paling banyak mengunjungi kota wisata "<<endl<<endl;
                cout<<"Masukan pilihan: ";
                cin>> tampil;
                if(tampil == "a" || tampil == "A"){
                    FindMaxData(Lcity);
                }else if (tampil == "b" || tampil == "B"){
                    touristMostTrip(Lcity,Ltourist);
                }
                break;
            }
            case 7:{
                cout<<"Cari Data Paling Sedikit pada: "<<endl;
                cout<<"a. Data Kota Wisata yang paling sedikit dikunjungi oleh turis"<<endl;
                cout<<"b. Data Turis yang paling sedikit mengunjungi kota wisata"<<endl<<endl;
                cout<<"Masukan pilihan: ";
                cin>> tampil;
                if(tampil == "a" || tampil == "A"){
                    FindMinData(Lcity);
                }else if (tampil == "b" || tampil == "B"){
                    touristLeastTrip(Lcity,Ltourist);
                }
                break;
            }
            case 8:{
                cout<<"Masukan Nama Kota Wisata: ";
                cin>>namaKota;
                cout<<"Masukan kode kota: ";
                cin>>kodeC;
                cout<<"Terdapat "<<countTourist(Lcity, kodeC)<<" pengunjung pada kota "<<namaKota<<endl;
                break;
            }
            case 9:{
                adrC = nil;
                adrT = nil;
                cout<<"Tampilkan pencarian pada: "<<endl;
                cout<<"a. Kota Wisata"<<endl;
                cout<<"b. Turis "<<endl;
                cout<<"Masukan Pilihan: ";
                cin>>tampil;
                cout<<endl;
                if (tampil == "a" || tampil == "A"){
                    cout<<"Masukan Nama Kota Wisata: ";
                    cin>>namaKota;
                    cout<<"Masukan kode Kota Wisata: ";
                    cin>>kodeC;
                    adrC = findElmCity(Lcity, kodeC);
                }else if (tampil == "b" || tampil == "B"){
                    cout<<"Masukan Nama turis: ";
                    cin>> namaTourist;
                    cout<<"Masukan kode turis: ";
                    cin>>kodeT;
                    adrT = findElmTourist(Ltourist, kodeT);
                }
                if (adrC!=nil){
                    cout<<endl<<"--- Data Ditemukan ---"<<endl<<endl;
                    cout<< "Nama Kota Wisata: "<<info(adrC).name<<endl;
                    cout<< "Kode Kota: "<<info(adrC).code<<endl;
                    cout<< "Jumlah destinasi: "<<info(adrC).totalDestination<<endl;
                }else if (adrT!=nil){
                    cout<<endl<<"--- Data Ditemukan ---"<<endl<<endl;
                    cout<< "Nama Pengunjung: "<<info(adrT).name<<endl;
                    cout<< "Kode: "<<info(adrT).kode<<endl;
                    cout<< "Status: "<<info(adrT).status<<endl;
                    cout<< "Gender: "<<info(adrT).gender<<endl;
                }else{
                    cout<<"Data Tidak Ditemukan"<<endl;
                }
                break;
            }
            case 10:
                helpPanduan();
                break;
            default:{
                cout<<"Masukan berupa angka 0-10"<<endl;
                break;
            }
            }
            cout << endl<< "Kembali ke menu utama? (Y/N): ";
            cin >> kembali;

            if (kembali == 'Y' || kembali == 'y'){
                cout << endl;
                pilihan = selectMenu();
            }
            else if (kembali == 'N' || kembali == 'n'){
                pilihan = 0;
            }
            else{
                cout << endl<< "Kembali ke menu utama? (Y/N): ";
                cin >> kembali;
            }
        }
        cout << endl<< "ANDA TELAH KELUAR DARI PROGRAM"<<endl;
        return 0;
}

