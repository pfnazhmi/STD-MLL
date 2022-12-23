#include "tourist.h"

void createTouristList(listTourist &L){
    first(L) = nil;
};

adrTourist newElemenTourist(infoTourist data){
    adrTourist T = new elementTourist;
    info(T).name = data.name;
    info(T).age = data.age;
    next(T) = nil;

    return T;
};

void insertLastT(listTourist &L, adrTourist T){
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

void deleteLastT(listTourist &L, adrTourist &T){
    adrTourist Q;
    Q = first(L);

    while(next(next(Q))!= nil){
        Q = next(Q);
    }
    T = next(Q);
    next(Q) = nil;
};

void showTourist(listTourist L){
    adrTourist T;
    T = first(L);
    infoTourist data;

    while(T!=nil){
        data = info(T);
        cout<< "Nama Pengunjung: "<<data.name<<endl;
        cout<< "Umur Pengunjung: "<<data.age<<endl;
        T = next(T);
    }
};

adrTourist findElmTourist (listTourist L, infoTourist x){
    adrTourist pTour;
    pTour = first(L);
    while (pTour!=nil) {
        if(info(pTour).name== x.name && info(pTour).age== x.age){
            return pTour;
            break;
        }
        pTour=next(pTour);
    }
    return  nil;
};

infoTourist addMainTourist(infoTourist &dataTour){
    cout<<"Name: ";
    cin>>dataTour.name;
    cout<<"Age: ";
    cin>>dataTour.age;
    cout<<endl;

    return dataTour;
};
