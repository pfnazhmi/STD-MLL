#include "tourist.h"

void createTouristList(listTourist &L){
     /*{Membuat list turis yang bernilai nil}*/
    first(L) = nil;
};

adrTourist newElementTourist(infoTourist data){
     /*{Membuat sebuah element turis baru. jika alokasi berhasil, info dari elemen berisi data,
    next dari elemen berisi nil}*/
    adrTourist T = new elementTourist;
    info(T) = data;
    next(T) = nil;

    return T;
};

void addToLastT(listTourist &L, adrTourist T){
    /*{IS. Terdefinisi sebuah lsttTourist(L)kosong dan pointer T berisi alamat elementTourist
       FS. T ditambakan di list sebagai elemen terakhir }*/
    if(first(L)==nil){
        first(L) = T;
    }else{
        adrTourist Q;
        Q = first(L);
        while(next(Q)!=nil){
            Q = next(Q);
        }
        next(Q) = T;
    }
};

void showTourist(listTourist L){
    /*{IS. Terdefinisi listTourist L
        FS. menampilkan semua list turis jika ada}*/
    adrTourist T;
    T = first(L);
    infoTourist data;

    if(T==nil){
        cout<<"Tidak Ada Data"<<endl;
    }else{
        int i = 1;
        cout<<"--- Data Turis ---"<<endl;
        while(T!=nil){
            data = info(T);
            cout<<endl;
            cout<<"Data turis ke-"<<i<<endl;
            cout<< "Nama Pengunjung: "<<data.name<<endl;
            cout<< "Kode: "<<data.kode<<endl;
            cout<< "Status: "<<data.status<<endl;
            cout<< "Gender: "<<data.gender<<endl;
            i++;
            T = next(T);
        }
    }
};

void ShowInfoTourist(listTourist L){
    /*{IS. Terdefinisi listTourist L
        FS. menampilkan semua list turis jika ada}*/
    adrTourist T;
    T = first(L);
    infoTourist data;

    if(T==nil){
        cout<<"Tidak Ada Data"<<endl;
    }else{
        int i = 1;
        cout<<"--- Info Data Turis ---"<<endl;
        while(T!=nil){
            data = info(T);
            cout<<endl;
            cout<<"Data turis ke-"<<i<<endl;
            cout<< "Nama Pengunjung: "<<data.name<<endl;
            cout<< "Kode: "<<data.kode<<endl;
            i++;
            T = next(T);
        }
    }
};

adrTourist findElmTourist (listTourist L, int kodeTuris){
    /*{IS. Terdefinisi listTourist L berisi kode turis dan kode yang akan dicari.
        FS. menemukan element Tourist dengan kode Tourist, mengembalikan address element tourist}*/
    adrTourist pTour;
    pTour = first(L);
    while (pTour!=nil) {
        if(info(pTour).kode==kodeTuris){
            return pTour;
            break;
        }
        pTour=next(pTour);
    }
    return  nil;
};

infoTourist addMainTourist(infoTourist &dataTour){
    /*{Untuk memudahkan saat melakukan inputan di main program dan mengembalikan infoturist}*/
    cout<<"Name: ";
    cin>>dataTour.name;
    cout<<"Status: ";
    cin>>dataTour.status;
    cout<<"Gender: ";
    cin>>dataTour.gender;
    cout<<"Kode: ";
    cin>>dataTour.kode;
    cout<<endl;

    return dataTour;
};
