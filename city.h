#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include <iostream>
using namespace std;
#include "tourist.h"

#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#define nil NULL

struct City{
    string name;
    int code,totalDestination;
};

typedef City infoCity;
typedef struct elementCity *adrCity;
typedef struct elementRelasi *adrRelasi;

struct listRelasi{
     adrRelasi first;
};

struct elementCity{
    infoCity info;
    listRelasi child;
    adrCity next;
};

struct listCity{
     adrCity first;
};

struct elementRelasi{
    adrRelasi next;
    adrTourist info;
};

//City
void createCityList(listCity &L);
adrCity newElementCity(infoCity data);
void addToLastC(listCity &L, adrCity T);
void deleteLastC(listCity &L, adrCity &T);
void showCity(listCity L);
adrRelasi findElmChild (listRelasi L, adrTourist rel);
adrCity findElmCity (listCity L, int kode);
void deleteCity(listCity &L,string namaKota,int kode);

//Relasi
void createRelasi(listRelasi &L);
adrRelasi newElemenRelasi(adrTourist data);
void addToLastR(listRelasi &L, adrRelasi R);
void deleteLastR(listRelasi &L, adrRelasi &R);
void showRelasi(listRelasi L);

//fitur
int countTourist(listCity L, int fCityCode);
void ShowAllData(listCity Lcity);
void FindMaxData(listCity Lcity);
void FindMinData(listCity Lcity);
void addForTrip(string &namaKota,int &kodeKota, string &namaTourist, int &kodeTourist);
infoCity addMainCity(infoCity &dataCity);
void showTouristInCity(listCity L)

//menu
int selectmenu();
void helpPanduan();

#endif // CITY_H_INCLUDED
