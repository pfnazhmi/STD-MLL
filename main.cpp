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
                cout<<"Hapus data kota(cari/akhir)";
                cin>>hapus;
                if (hapus=="cari"){
                    cout<<"Masukkan data kota yang ingin dihapus : "<<endl;
                    cout<<"Nama Kota: ";
                    cin>>namaKota;
                    cout<<"Kode Kota : ";
                    cin>>kodeC;
                    deleteCity(Lcity,namaKota,kodeC);
                }else if (hapus=="akhir"){
                    deleteLastC(Lcity, adrC);
                }
                break;
            }
            case 5:{
                cout<<"Tampilkan Data(semua / turis / kota): ";
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
                cout<<"Masukan kode kota: ";
                cin>>kodeC;
                cout<<"Terdapat "<<countTourist(Lcity, kodeC)<<" pengunjung"<<endl;
                break;
            }
            case 9:{
                adrC = nil;
                adrT = nil;
                cout<<"Tampilkan pencarian(kota / turis): ";
                cin>>tampil;
                if (tampil == "kota"){
                    cout<<"masukan kode kota: ";
                    cin>>kodeC;
                    adrC = findElmCity(Lcity, kodeC);
                }else if (tampil == "turis"){
                    cout<<"masukan kode turis: ";
                    cin>>kodeT;
                    adrT = findElmTourist(Ltourist, kodeT);
                }
                if (adrC!=nil){
                    cout<<"Data Ditemukan"<<endl<<endl;
                    cout<< "Nama Kota: "<<info(adrC).name<<endl;
                    cout<< "Kode Kota: "<<info(adrC).code<<endl;
                    cout<< "Jumlah destinasi: "<<info(adrC).totalDestination<<endl;
                }else if (adrT!=nil){
                    cout<<"Data Ditemukan"<<endl<<endl;
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
                pilihan = selectmenu();
            }
            else if (kembali == 'N' || kembali == 'n'){
                pilihan = 0;
            }
            //else{
               // cout << endl<< "Kembali ke menu utama? (Y/N): ";
                //cin >> kembali;
            //}
        }
        cout << endl<< "ANDA TELAH KELUAR DARI PROGRAM"<<endl;
        return 0;
}

