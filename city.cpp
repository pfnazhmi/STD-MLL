#include "city.h"

void createCityList(listCity &L){
    first(L) = nil;
};

adrCity newElemetCity(infoCity data){
    adrCity C = new elementCity;
    info(C) = data;
    next(C) = nil;

    return C;
};

void insertLastC(listCity &L, adrCity C){
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
    adrCity C;
    C = first(L);
    infoCity data;

    cout<<endl;
    int i = 1;
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
};

infoCity addMainCity(infoCity &dataCity){
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
    first(L) = nil;
};

adrRelasi newElemenRelasi(adrTourist data){
    adrRelasi R = new elementRelasi;
    info(R) = data;
    next(R) = nil;

    return R;
};

void insertLastR(listRelasi &L, adrRelasi R){
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

void deleteLastR(listRelasi &L, adrRelasi &R){
    adrRelasi Q;
    Q = first(L);

    while(next(next(Q))!= nil){
        Q = next(Q);
    }
    R = next(Q);
    next(Q) = nil;
};

adrCity findElmCity (listCity L, infoCity cit){
    adrCity pCity;
    pCity = first(L);
    while (pCity!=nil) {
        if(info(pCity).name== cit.name && info(pCity).code==cit.code && info(pCity).totalDestination == cit.totalDestination){
            return pCity;
            break;
        }
        pCity=next(pCity);
    }
    return  nil;
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

int countTourist(listCity L, string fCityname, string fCityCode, int fCityTotal){
    adrCity Pcity;
    infoCity fCity;

    fCity.name=fCityname;
    fCity.code=fCityCode;
    fCity.totalDestination=fCityTotal;
    Pcity = findElmCity(L, fCity);
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
    adrCity pCity = first(Lcity);
    adrCity vMax=nil;
    int maxVal = 0;
    int i = 0;

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
        }
        pCity = next(pCity);
    }

    cout<<"Kota dengan jumlah pengunjung terbanyak adalah Kota "<<info(vMax).name<<endl<<"dengan jumlah pengunjung sebanyak "<<maxVal<<" Pengunjung"<<endl;
};

void FindMinData(listCity Lcity){
    adrCity pCity = first(Lcity);
    adrCity vMin=nil;
    int minVal = 10;
    int i = 0;

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
        }
        pCity = next(pCity);
    }
    cout<<"Kota dengan jumlah pengunjung paling sedikit adalah Kota " <<info(vMin).name<<endl<<"dengan jumlah pengunjung sebanyak "<<minVal<<" Pengunjung"<<endl;
};

void deleteCity(listCity &L, infoCity iCity){
    adrCity prec = first(L);

    while(prec!=nil){
        if(info(next(prec)).name == iCity.name && info(next(prec)).code == iCity.code && info(next(prec)).totalDestination == iCity.totalDestination){
            break;
        }
        prec = next(prec);
    }
    if(prec!=nil){
        adrCity P = next(prec);
        next(prec) = next(P);
        next(P) = nil;
        free(P);
    }

    cout<<"Data berhasil dihapus"<<endl;
}


void ShowAllData(listCity Lcity){
    adrCity pCity = first(Lcity);

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
            cout<<"Status: "<<info(info(pTour)).status<<endl;
            cout<<"Gender: "<<info(info(pTour)).gender<<endl;
            pTour = next(pTour);
            j++;
        }
        pCity = next(pCity);
    }
};

void showRelasi(listRelasi L){
    adrRelasi R;
    R = first(L);

    while(R!=nil){
        cout<<"show relasi"<<info(R)<<endl;
        R = next(R);
    }
};


void addForFind(infoCity &fCity, infoTourist &fTourist){
    cout<<"Nama Turis :";
    cin>>fTourist.name;
    cout<<"Status Turis :";
    cin>>fTourist.status;
    cout<<"Gender Turis :";
    cin>>fTourist.gender;
    cout<<"Kota Tujuan :";
    cin>>fCity.name;
    cout<<"Kode Kota :";
    cin>>fCity.code;
    cout<<"Jumlah Destinasi :";
    cin>>fCity.totalDestination;
    cout<<endl;
}

int selectmenu(){
    cout << "======MENU======" << endl;
        cout << "1. Menambah data kota wisata" << endl;
        cout << "2. Menambah data turis" << endl;
        cout << "3. Menambah data perjalanan" << endl;
        cout << "4. Menghapus data kota wisata" << endl;
        cout << "5. Menampilkan data kota atau turis atau seluruhnya(MLL)" << endl;
        cout << "6. Menampilkan data kota dengan pengunjung terbanyak" << endl;
        cout << "7. Menampilkan data kota dengan pengunjung paling sedikit" << endl;
        cout << "0. Exit" << endl;
        cout << "Masukkan menu : ";
        int input = 0;
        cin >> input;
        return input;
};
