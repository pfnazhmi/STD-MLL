#include "city.h"

void createCityList(listCity &L){
    first(L) = nil;
};

adrCity newElemetCity(infoCity data){
    adrCity C = new elementCity;
    info(C).name = data.name;
    info(C).country = data.country;
    next(C) = nil;
    createRelasi(child(C));

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
};

void showCity(listCity L){
    adrCity C;
    C = first(L);
    infoCity data;

    while(C!=nil){
        data = info(C);
        cout<< "Nama Kota: "<<data.name<<endl;
        cout<< "Dari Negara: "<<data.country<<endl;
        cout<<endl;
        C = next(C);
    }
};

infoCity addMainCity(infoCity &dataCity){
    cout<<"City: ";
    cin>>dataCity.name;
    cout<<"Country: ";
    cin>>dataCity.country;
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

void showRelasi(listRelasi L){
    adrRelasi R;
    R = first(L);

    while(R!=nil){
        cout<<"show relasi"<<info(R)<<endl;
        R = next(R);
    }
};

adrCity findElmCity (listCity L, infoCity cit){
    adrCity pCity;
    pCity = first(L);
    while (pCity!=nil) {
        if(info(pCity).name== cit.name && info(pCity).country==cit.country){
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

int countTourist(listCity L, string fCityName, string fCityCountry){
    adrCity c;
    infoCity fcit;
    fcit.name = fCityName;
    fcit.country = fCityCountry;
    c = findElmCity(L, fcit);
    listRelasi lr = child(c);
    adrRelasi p;
    int countTour = 0;
    p = first(lr);
    while(p!=nil){
        countTour++;
        p=next(p);
    }

    return countTour;

};

int selectmenu(){
    cout << "======MENU======" << endl;
        cout << "1. Menambah data kota wisata" << endl;
        cout << "2. Menambah data turis" << endl;
        cout << "3. Menambah data perjalanan" << endl;
        cout << "4. Menghapus data kota wisata" << endl;
        cout << "5. Menampilkan data kota atau turis" << endl;
        cout << "6. Menampilkan data kota dengan pengunjung terbanyak" << endl;
        cout << "7. Menampilkan data kota dengan pengunjung paling sedikit" << endl;
        cout << "0. Exit" << endl;
        cout << "Masukkan menu : ";
        int input = 0;
        cin >> input;
        return input;
};

void ShowAllData(listCity Lcity, listTourist Ltour){
    adrCity pCity = first(Lcity);

    while(pCity!=nil){
        cout<<"==========City========="<<endl;
        cout<<"Name: "<<info(pCity).name<<endl;
        cout<<"Country: "<<info(pCity).country<<endl;
        adrRelasi pTour = first(child(pCity));
        while(pTour!=nil){
            cout<<"==========Touris========="<<endl;
            cout<<"Name: "<<info(info(pTour)).name<<endl;
            cout<<"Age: "<<info(info(pTour)).age<<endl;
            pTour = next(pTour);
        }
        pCity = next(pCity);
    }
};

void FindMaxData(listCity Lcity){
    adrCity pCity = first(Lcity);
    adrCity vMax;
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
        }
        pCity = next(pCity);
    }

};

void FindMinData(listCity Lcity){
    adrCity pCity = first(Lcity);
    adrCity vMin;
    int minVal = 0;
    int i;

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
};
