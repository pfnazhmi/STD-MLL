#include "city.h"

void createCityList(listCity &L){
    /*{Membuat list kota yang bernilai nil}*/
    first(L) = nil;
};

adrCity newElementCity(infoCity data){
    /*{Membuat sebuah element kota baru. jika alokasi berhasil, info dari elemen berisi data,
    next dari elemen berisi nil}*/
    adrCity C = new elementCity;
    info(C) = data;
    next(C) = nil;
    createRelasi(child(C));

    return C;
};

void addToLastC(listCity &L, adrCity C){
    /*{IS. Terdefinisi sebuah List City(L)kosong dan pointer C berisi alamat elementCity
       FS. C ditambakan di list sebagai elemen terakhir }*/
    if(first(L)==nil){
        first(L) = C;
    }else{
        adrCity Q;
        Q = first(L);
        while(next(Q)!=nil){
            Q = next(Q);
        }
        next(Q) = C;
    }
};


void showCity(listCity L){
    /*{IS. Terdefinisi listCity L
        FS. menampilkan semua list kota jika ada}*/
    adrCity C;
    C = first(L);
    infoCity data;

    if(C==nil){
        cout<<"Tidak Ada Data"<<endl;
    }else{
        cout<<endl;
        int i = 1;
        cout<<"--- Data Kota Wisata ----"<<endl;
        while(C!=nil){
            cout<<endl;
            cout<<"Data kota ke-"<<i<<endl;
            data = info(C);
            cout<< "Nama Kota: "<<data.name<<endl;
            cout<< "Kode Kota: "<<data.code<<endl;
            cout<< "Jumlah destinasi: "<<data.totalDestination<<endl;
            C = next(C);
            i++;
        }
    }

};

adrRelasi findElmChild (listRelasi L, adrTourist rel){
    adrRelasi pRel;
        pRel = first(L);
        while (pRel!=nil) {
            if(info(pRel)== rel){
                return pRel;
                break;
            }
            pRel=next(pRel);
        }
        return  nil;
};


infoCity addMainCity(infoCity &dataCity){
    /*{untuk memudahkan saat melakukan inputan di main program dan mengembalikan nya }*/
    cout<<"Kota: ";
    cin>>dataCity.name;
    cout<<"Kode: ";
    cin>>dataCity.code;
    cout<<"Jumlah destinasi: ";
    cin>>dataCity.totalDestination;
    cout<<endl;

    return dataCity;
}

void createRelasi(listRelasi &L){
   /*{Membuat list relasi yang bernilai nil}*/
    first(L) = nil;
};

adrRelasi newElemenRelasi(adrTourist data){
    /*{Membuat element relasi baru yang berisi address turis sesuai parameter}*/
    adrRelasi R = new elementRelasi;
    info(R) = data;
    next(R) = nil;

    return R;
};

void addToLastR(listRelasi &L, adrRelasi R){
    /*{IS. Terdefinisi sebuah List Relasi(L)kosong dan pointer R berisi alamat elementRelasi
       FS. R ditambakan di list sebagai elemen terakhir }*/
    if(first(L)==nil){
        first(L) = R;
    }else{
        adrRelasi Q;
        Q = first(L);
        while(next(Q)!=nil){
            Q = next(Q);
        }
        next(Q) = R;
    }
};

adrCity findElmCity (listCity L, int kode){
    /*{IS. Terdefinisi listcity L berisi kode kota dan kode yang akan dicari.
        FS. menemukan element kota dengan kode kota, mengembalikan address element kota}*/
    adrCity pCity;
    pCity = first(L);
    while (pCity!=nil) {
        if(info(pCity).code== kode){
            return pCity;
            break;
        }
        pCity=next(pCity);
    }
    return  nil;
};

int countTourist(listCity L, int fCityCode){
    /*{IS.Didefinisikan code kota fCityCode.
        FS. mengembalikan jumlah turis pada suatu kota dengan kode kota yang sesuai parameter}*/
    adrCity Pcity;

    Pcity = findElmCity(L, fCityCode);
    listRelasi lr = child(Pcity);

    adrRelasi pRel;
    int countTour = 0;
    pRel = first(lr);
    while(pRel!=nil){
        countTour++;
        pRel=next(pRel);
    }
    return countTour;
};


void FindMaxData(listCity Lcity){
    /*{ Dengan asumsi listCity tidak kosong. menampilkan jumlah turis terbanyak pada data}*/
    adrCity pCity = first(Lcity);
    adrCity vMax=nil;
    string dupvMax="";
    int maxVal = 0;
    int i;

    while(pCity!=nil){
        i=0;
        adrRelasi pTour = first(child(pCity));
        while(pTour!=nil){
            i++;
            pTour = next(pTour);
        }
        if (maxVal<i){
            maxVal = i;
            vMax = pCity;
        }else if (maxVal==i){
            dupvMax = dupvMax +", "+ info(pCity).name;
        }
        pCity = next(pCity);
    }
        cout<<"Kota dengan jumlah pengunjung terbanyak adalah Kota "<<info(vMax).name<<dupvMax<<endl<<"dengan jumlah pengunjung sebanyak "<<maxVal<<" Pengunjung"<<endl;
};

int cekElementFirst(listCity LC){
    int i =0;
    adrRelasi Prel = first(child(first(LC)));
    while(Prel!=nil){
        i++;
        Prel = next(Prel);
    }
    return i;
}

void FindMinData(listCity Lcity){
   /*{ Dengan asumsi listCity tidak kosong. menampilkan jumlah turis paling sedikit pada data}*/
    adrCity pCity = first(Lcity);
    adrCity vMin=nil;
    int minVal = cekElementFirst(Lcity);
    int i;
    string dupvMin="";

    while(pCity!=nil){
        i=0;
        adrRelasi pTour = first(child(pCity));
        while(pTour!=nil){
            i++;
            pTour = next(pTour);
        }
        if (minVal>i){
            minVal = i;
            vMin = pCity;
        }else if (minVal==i && pCity!=first(Lcity)){
            dupvMin = dupvMin +", "+ info(pCity).name;
        }
        pCity = next(pCity);
    }

    cout<<"Kota Wisata dengan jumlah pengunjung paling sedikit adalah Kota " <<info(vMin).name<<dupvMin<<endl<<"dengan jumlah pengunjung sebanyak "<<minVal<<" Pengunjung"<<endl;
};

void touristMostTrip(listCity LCity, listTourist LTour){
    adrCity pCity;
    adrRelasi pRel;
    adrTourist pKeep = nil;
    adrTourist pTour = first(LTour);
    string dupmax = "";
    int maxVal = 0;
    int num;

    while(pTour!=nil){
        num = 0;
        pCity = first(LCity);
        while (pCity!=nil) {
            pRel = findElmChild(child(pCity), pTour);
            if(pRel!=nil){
                num++;
            }
            pCity = next(pCity);
        }
        if(maxVal < num){
            maxVal = num;
            pKeep = pTour;
        }else if (maxVal==num){
            dupmax = dupmax +", "+ info(pTour).name;
        }
        pTour = next(pTour);
    }
    cout<<"Turis yang paling banyak mengunjungi kota wisata di Jawa Barat adalah "<<info(pKeep).name<<dupmax<<" sebanyak "<<maxVal<<endl;
};

void touristLeastTrip(listCity LCity, listTourist LTour){
    //ubah
    adrCity pCity;
    adrRelasi pRel;
    adrTourist pKeep = nil;
    adrTourist pTour = first(LTour);
    string dupmax = "";
    int maxVal = 999;
    int num;

    while(pTour!=nil){
        num = 0;
        pCity = first(LCity);
        while (pCity!=nil) {
            pRel = findElmChild(child(pCity), pTour);
            if(pRel!=nil){
                num++;
            }
            pCity = next(pCity);
        }
        if(maxVal > num){
            maxVal = num;
            pKeep = pTour;
        }else if (maxVal==num){
            dupmax = dupmax +", "+ info(pTour).name;
        }
        pTour = next(pTour);
    }
    cout<<"Turis yang paling sedikit mengunjungi kota di Jawa Barat adalah "<<info(pKeep).name<<dupmax<<" sebanyak "<<maxVal<<endl;
};


void deleteCity(listCity &L,string namaKota,int kode){
    /*{IS.Terdefinisi listCity tidak kosong.
        FS. menghapus element kota dengan kode kota yang sesuai dengan paremeter}*/

    adrCity P = findElmCity(L, kode);
    adrCity prec = first(L);

    if (P==first(L)){
        first(L)=next(P);
        next(P)=nil;
    }else{
        while (next(prec)!=P){
            prec = next(prec);
        }
        next(prec)=next(P);
        next(P)=nil;
    }
    cout<<"Data berhasil dihapus"<<endl;
}

void deleteTourist(listCity &Lcity, listTourist &Ltour,int kodeK, int kodeT){
    adrCity delCity = findElmCity(Lcity, kodeK);
    adrTourist delTour = findElmTourist(Ltour, kodeT);
    adrRelasi delRel = findElmChild(child(delCity),delTour);
    adrRelasi pDel= first(child(delCity));

    if(delRel == pDel){
        first(child(delCity))=next(delRel);
        next(delRel)=nil;
    }else if (delRel != pDel && delRel != nil){
        while (next(pDel)!=delRel) {
            pDel = next(pDel);
        }
        next(pDel) = next(delRel);
        next(delRel) = nil;
    }
    cout<<"Data Berhasil di hapus"<<endl;
}

void showTouristInCity(listCity LCity, listTourist LTour, int kode){
    adrTourist cekTour = findElmTourist(LTour, kode);
    adrCity Pcity = first(LCity);
    adrRelasi cekRel = nil;
    cout<<endl<<"--- Riwayat Kunjungan Turis "<<info(cekTour).name<<" ---"<<endl;
    while(Pcity!=nil){
        cekRel = findElmChild(child(Pcity), cekTour);
        if (cekRel!=nil){
            cout<<info(Pcity).name<<endl;
        }
        Pcity = next(Pcity);
    }
};

void ShowAllData(listCity Lcity){
    /*{Menampilkan seluruh data termasuk data turis yang mengunjungi suatu kota}*/
    adrCity pCity = first(Lcity);

    if (pCity==nil){
        cout<<"Tidak Ada Data"<<endl;
    }else{
        while(pCity!=nil){
            cout<<endl;
            cout<<"---------- Kota Wisata di "<<info(pCity).name<<" ----------"<<endl;
            cout<<"Kode Kota: "<<info(pCity).code<<endl;
            cout<<"Jumlah Destinasi: "<<info(pCity).code<<endl;
            adrRelasi pTour = first(child(pCity));
            if (pTour==nil){
                cout<<"Belum Ada Pengunjung"<<endl<<endl;
            }
            int j = 1;
            while(pTour!=nil){
                cout<<endl<<"--- Turis "<<j<<" ---"<<endl;
                cout<<"Nama: "<<info(info(pTour)).name<<endl;
                cout<<"Kode: "<<info(info(pTour)).kode<<endl;
                cout<<"Status: "<<info(info(pTour)).status<<endl;
                cout<<"Gender: "<<info(info(pTour)).gender<<endl;
                pTour = next(pTour);
                j++;
            }
            pCity = next(pCity);
        }
    }
};


void addForTrip(string &namaKota,int &kodeKota, string &namaTourist, int &kodeTourist){
    /*{Untuk memudahkan saat melakukan inputan di main program dan mengembalikan kodekota serta kode turis}*/
    cout<<"Nama Turis: ";
    cin>>namaTourist;
    cout<<"Kode Turis: ";
    cin>>kodeTourist;
    cout<<"Nama Kota: ";
    cin>>namaKota;
    cout<<"Kode Kota Tujuan: ";
    cin>>kodeKota;
    cout<<endl;
}

void helpPanduan(){
    /*{Menampilkan panduan aplikasi}*/
    cout<<endl;
        cout<<"-------------------- Panduan Aplikasi --------------------"<<endl<<endl;
        cout<<"• User/pengguna dapat menambahkan data kota wisata dengan mengetik angka 1"<<endl<<endl;
        cout<<"• User/pengguna dapat menambahkan data turis dengan mengetik angka 2"<<endl<<endl;
        cout<<"• User/pengguna dapat menambahkan data perjalanan turis dengan meng-inputkan \n  Nama turis, kode turis, nama kota dan kode kota"<<endl<<endl;
        cout<<"• Dengan mengetik angka 4, User/pengguna dapat menghapus data,\n  kemudian disediakan pilihan data apa yanng ingin user hapus, misal:\n  a.Hapus Data Kota Wisata \n  b. Hapus Data Turis di kota tertentu"<<endl<<endl;
        cout<<"• Dengan mengetik angka 5, User/pengguna dapat menampilkan data,\n  kemudian disediakan pilihan data mana yang ingin ditampilkan, misal:\n  a. Menampilkan Data Kota Wisata dengan pengunjung nya\n  b. Menampilkan Data Turis\n  c. Menampilkan Data Kota Wisata\n  d. Menampilkan Riwayat Perjalanan Turis"<<endl<<endl;
        cout<<"• Dengan mengetik angka 6, User/pengguna dapat menampilkan data paling banyak,\n  kemudian disediakan pilihan data mana yang ingin ditampilkan, misal:\n  a.Data Kota Wisata yang paling banyak dikunjungi oleh turis\n  b.Data Turis yang paling banyak mengunjungi kota wisata "<<endl<<endl;
        cout<<"• Dengan mengetik angka 7 ,User/pengguna dapat menampilkan data paling sedikit,\n  kemudian disediakan pilihan data mana yang ingin ditampilkan, misal:\n  a.Data Kota Wisata yang paling sedikit dikunjungi oleh turis\n  b.Data Turis yang paling sedikit mengunjungi kota wisata"<<endl<<endl;
        cout<<"• Dengan mengetik angka 8, User/pengguna dapat menampilkan\n  jumlah turis yang mengunjungi suatu kota wisata"<<endl<<endl;
        cout<<"• Dengan mengetik angka 9, User/pengguna dapat mencari\n  ataupun mengecek apakah suatu data dari turis ataupun kota wisata itu tersedia"<<endl<<endl;
        cout<<"• Jika User/pengguna butuh panduan aplikasi, user dapat mengetik 10"<<endl<<endl;
        cout<<"• Jika User/pengguna ingin keluar dari aplikasi dapat mengetik 0"<<endl;
    }

int selectMenu(){
    /*{menampilkan daftar fitur yang tersedia pada program}*/
        cout << "-------- APLIKASI DATA KOTA WISATA JAWA BARAT --------" << endl<<endl;
        cout << "1.  Menambah data kota wisata" << endl;
        cout << "2.  Menambah data turis" << endl;
        cout << "3.  Menambah data perjalanan" << endl;
        cout << "4.  Menghapus data" << endl;
        cout << "5.  Menampilkan data" << endl;
        cout << "6.  Menampilkan data paling banyak" << endl;
        cout << "7.  Menampilkan data paling sedikit" << endl;
        cout << "8.  Menampilkan jumlah turis yang mengunjungi suatu kota wisata" << endl;
        cout << "9.  Mencari data turis atau kota" << endl;
        cout << "10. Bantuan" << endl;
        cout << "0.  Exit" << endl<<endl;
        cout <<"Masukan berupa angka 0-10"<<endl;
        cout << "----------------------"<<endl;
        cout << "Masukkan pilihan: ";
        int input = 0;
        cin >> input;
        return input;
};
