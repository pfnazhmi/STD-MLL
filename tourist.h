#ifndef TOURIST_H_INCLUDED
#define TOURIST_H_INCLUDED


#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
#define nil NULL

struct Tourist{
    string name;
    string age;
};

typedef Tourist infoTourist;
typedef struct elementTourist *adrTourist;

struct elementTourist{
    infoTourist info;
    adrTourist next;
};

struct listTourist{
     adrTourist first;
};

void createTouristList(listTourist &L);
adrTourist newElemenTourist(infoTourist data);
void insertLastT(listTourist &L, adrTourist C);
void deleteLastT(listTourist &L, adrTourist &C);
void showTourist(listTourist L);
adrTourist findElmTourist (listTourist L, infoTourist x);
infoTourist addMainTourist(infoTourist &dataTour);

#endif // TOURIST_H_INCLUDED
