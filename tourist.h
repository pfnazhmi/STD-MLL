#ifndef TOURIST_H_INCLUDED
#define TOURIST_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define next(P) P->next
#define info(P) P->info
#define nil NULL

struct Tourist{
    string name,status;
    char gender;
    int kode;
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
adrTourist newElementTourist(infoTourist data);
void addToLastT(listTourist &L, adrTourist T);
void showTourist(listTourist L);
adrTourist findElmTourist (listTourist L, int kodeTuris);
infoTourist addMainTourist(infoTourist &dataTour);
void ShowInfoTourist(listTourist L);

#endif // TOURIST_H_INCLUDED
