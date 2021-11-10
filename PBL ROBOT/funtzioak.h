#ifndef funtzioak
#define funtzioak

typedef struct Posizioa {
    int x;
    int y;
}POSIZIOA;

typedef struct Mahaiak {
    int x;
    int y;
    struct Mahaiak* ptrHurrengoa;
}MAHAIAK;

typedef struct Pertsona {
    int x;
    int y;
    struct Pertsona* ptrHurrengoa;
}PERTSONAK;

int** kostua, V, hasi, end;
int* distantzia, * gurasoak, * bisitatuta;

#define INF 999

int hasiPrograma();
void barrua();
void terraza();
int mahaiaItzuliBarruan();
int mahaiaItzuliTerraza();
void pantailaratu(MAHAIAK* buruMahai, int* robot, int end);
void memoriaErreserbatu();
void memoriaGarbitu(MAHAIAK** burua, PERTSONAK** buruaP);
void mahaienPosizioa(MAHAIAK** burua, char* mahaiak);
void pertsonenPosizioa(PERTSONAK** burua, char* pertsona);
void irudiakJarri(int* robot, int* fondoa);
void irudiakEzabatu(int* pertsona, int* fondoa, int* errobota);
void pertsonaKokatu(int* pertsona, PERTSONAK* burua);
void marrak(MAHAIAK* burua, int end);
void mugimendua(MAHAIAK* ptrAux, int* robot);
MAHAIAK* mahaiaAurkitu(MAHAIAK* buruMahai, int node);
POSIZIOA mugitu(POSIZIOA pos, MAHAIAK* ptrAux);
int bukaeraMezua();
POSIZIOA saguarenPosizioa();

#endif