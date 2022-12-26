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
    string name, code;
    int totalDestination;
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
adrCity newElemetCity(infoCity data);
void insertLastC(listCity &L, adrCity T);
void deleteLastC(listCity &L, adrCity &T);
void showCity(listCity L);
adrRelasi findElmChild (listRelasi L, adrTourist rel);

//Relasi
void createRelasi(listRelasi &L);
adrRelasi newElemenRelasi(adrTourist data);
void insertLastR(listRelasi &L, adrRelasi R);
void deleteLastR(listRelasi &L, adrRelasi &R);
void showRelasi(listRelasi L);
adrCity findElmCity (listCity L, infoCity cit);

int countTourist(listCity L, string fCityname, string fCitycountry);
void ShowAllData(listCity Lcity);
void FindMaxData(listCity Lcity);
void FindMinData(listCity Lcity);
void deleteCity(listCity &L, infoCity iCity);
infoCity addMainCity(infoCity &dataCity);
void addForFind(infoCity &fCity, infoTourist &fTourist);
//menu
int selectmenu();

#endif // CITY_H_INCLUDED
