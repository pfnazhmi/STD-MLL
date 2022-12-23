#include "city.h"
#include "tourist.h"

#include <iostream>

int main()
{
    listCity Lcity;
    listRelasi Lrelasi;
    listTourist Ltourist;

    adrCity adrC;
    adrRelasi adrR;
    adrTourist adrT;

    infoCity dataCity;
    infoTourist dataTourist;
    int i =1;
    int number;

    //CIty
    createCityList(Lcity);
    cout<<"input: ";
    cin>> number;
    cout<<endl;

    while(i<=number){
        cout<<"Data Kota Wisata ke-"<<i<<endl;
        addMainCity(dataCity);
        adrC = newElemetCity(dataCity);
        insertLastC(Lcity, adrC);
        i++;
    }

    //Tourist
    createTouristList(Ltourist);
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

    /*cout<<"Show City"<<endl;
    showCity(Lcity);
    cout<<endl<<"Show Tourist"<<endl;
    showTourist(Ltourist);*/

    ShowAllData(Lcity, Ltourist);

    return 0;
}
