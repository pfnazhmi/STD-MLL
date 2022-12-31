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

void deleteLastC(listCity &L, adrCity &C){
    /*{IS. L tidak kosong
        FS. ElementCity terakhir L sudah dihapus. elementCity yang dihapus disimpan pada C }*/
    adrCity Q;
    Q = first(L);

    while(next(next(Q))!=nil){
        Q = next(Q);
    }
    C = next(Q);
    next(Q) = nil;
    cout<<"Data berhasil dihapus"<<endl;
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
        cout<<"Data Kota"<<endl;
        while(C!=nil){
            cout<<endl;
            cout<<"Data kota ke-"<<i<<endl;
            data = info(C);
            cout<< "Nama Kota: "<<data.name<<endl;
            cout<< "Kode Kota: "<<data.code<<endl<<endl;
            cout<< "Jumlah destinasi: "<<data.totalDestination<<endl;
            C = next(C);
            i++;
        }
    }

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

void FindMinData(listCity Lcity){
   /*{ Dengan asumsi listCity tidak kosong. menampilkan jumlah turis paling sedikit pada data}*/
    adrCity pCity = first(Lcity);
    adrCity vMin=nil;
    int minVal = 10;
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
        }else if (minVal==i){
            dupvMin = dupvMin +", "+ info(pCity).name;
        }
        pCity = next(pCity);
    }
    cout<<"Kota dengan jumlah pengunjung paling sedikit adalah Kota " <<info(vMin).name<<dupvMin<<endl<<"dengan jumlah pengunjung sebanyak "<<minVal<<" Pengunjung"<<endl;
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


void ShowAllData(listCity Lcity){
    /*{Menampilkan seluruh data termasuk data turis yang mengunjungi suatu kota}*/
    adrCity pCity = first(Lcity);

    if (pCity==nil){
        cout<<"Tidak Ada Data"<<endl;
    }else{
        while(pCity!=nil){
            cout<<endl;
            cout<<"==========Kota "<<info(pCity).name<<"========="<<endl;
            cout<<"Kode Kota: "<<info(pCity).code<<endl;
            cout<<"Jumlah Destinasi: "<<info(pCity).code<<endl;
            adrRelasi pTour = first(child(pCity));
            if (pTour==nil){
                cout<<"Belum Ada Pengunjung"<<endl<<endl;
            }
            int j = 1;
            while(pTour!=nil){
                cout<<endl<<"---Turis "<<j<<"---"<<endl;
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
    cout<<"=====Panduan Aplikasi====="<<endl;
    cout<<"• User/pengguna dapat menambahkan data kota dengan mengetik angka 1"<<endl;
    cout<<"• User/pengguna dapat menambahkan data turis dengan mengetik angka 2"<<endl;
    cout<<"• User/pengguna dapat menambahkan data perjalanan turis dengan meng-inputkan \n   Nama turis, kode turis, nama kota dan kode kota"<<endl;
    cout<<"• Dengan mengetik angka 4 User/pengguna dapat menghapus data kota wisata sesuai keinginan user"<<endl;
    cout<<"• Dengan mengetik angka 5 User/pengguna dapat menampilkan data, kemudian tersedia juga ingin \n   menampilkan semua data, data kota saja ataupun data turis saja"<<endl;
    cout<<"• Dengan mengetik angka 6 User/pengguna dapat menampilkan data kota dengan pengunjung terbanyak"<<endl;
    cout<<"• Dengan mengetik angka 7 User/pengguna dapat menampilkan data kota dengan pengunjung paling sedikit"<<endl;
    cout<<"• Dengan mengetik angka 8 User/pengguna dapat menampilkan jumlah turis yang mengunjungi suatu kota wisata"<<endl;
    cout<<"• Dengan mengetik angka 9 User/pengguna dapat mencari ataupun mengecek apakah suatu data dari turis \n  ataupun kota wisata itu tersedia"<<endl;
    cout<<"• Jika User/pengguna butuh panduan aplikasi dapat mengetik 10"<<endl;
    cout<<"• Jika User/pengguna ingin keluar dari aplikasi dapat mengetik 10"<<endl;
}

int selectmenu(){
    /*{menampilkan daftar fitur yang tersedia pada program}*/
        cout << "-------- APLIKASI DATA KOTA WISATA JAWA BARAT --------" << endl<<endl;
        cout << "1.  Menambah data kota wisata" << endl;
        cout << "2.  Menambah data turis" << endl;
        cout << "3.  Menambah data perjalanan" << endl;
        cout << "4.  Menghapus data kota wisata" << endl;
        cout << "5.  Menampilkan data kota atau turis atau seluruhnya" << endl;
        cout << "6.  Menampilkan data kota dengan pengunjung terbanyak" << endl;
        cout << "7.  Menampilkan data kota dengan pengunjung paling sedikit" << endl;
        cout << "8.  Menampilkan jumlah turis yang mengunjungi suatu kota wisata" << endl;
        cout << "9.  Cari data turis atau kota" << endl;
        cout << "10. Bantuan" << endl;
        cout << "0.  Exit" << endl<<endl;
        cout << "----------------------"<<endl;
        cout << "Masukkan pilihan: ";
        int input = 0;
        cin >> input;
        return input;
};
