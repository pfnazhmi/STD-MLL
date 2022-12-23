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
    string name,country;
};

typedef City infoCity;
typedef struct elementCity *adrCity;

typedef struct elementRelasi *adrRelasi;

struct listRelasi{
     adrRelasi first;
};

struct elementCity{
    infoCity info;
    adrCity next;
    listRelasi child;
};
struct elementRelasi{
    adrRelasi next;
    adrTourist info;
};

struct listCity{
     adrCity first;
};


void createCityList(listCity &L);
adrCity newElemetCity(infoCity data);
void insertLastC(listCity &L, adrCity T);
void deleteLastC(listCity &L, adrCity &T);
void showCity(listCity L);
infoCity addMainCity(infoCity &dataCity);

void createRelasi(listRelasi &L);
adrRelasi newElemenRelasi(adrTourist data);
void insertLastR(listRelasi &L, adrRelasi R);
void deleteLastR(listRelasi &L, adrRelasi &R);
void showRelasi(listRelasi L);

int selectmenu();
int countTourist(listCity L, string fCityName, string fCityCountry);
adrRelasi findElmChild (listRelasi L, adrTourist rel);
adrCity findElmCity (listCity L, infoCity cit);
void ShowAllData(listCity Lcity, listTourist Ltour);
void FindMaxData(listCity Lcity);
void FindMinData(listCity Lcity);

#endif // CITY_H_INCLUDED
