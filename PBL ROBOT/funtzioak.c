#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sdlHasieratu.h"
#include "irudiak.h"
#include "kontrolak.h"
#include "funtzioak.h"
#include "dijkstra.h"

POSIZIOA saguPos;
SDL_Point points[36] = {
    {660, 30}
};

int hasiPrograma() {
    int itxi = 0, menu, ebentua;
    POSIZIOA saguPos;

    menu = irudiaSortu(MENU);
    irudiakMarraztu();
    SDL_RenderPresent(gRenderer);

    do {
        ebentua = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
    } while (ebentua != SAGU_BOTOIA_EZKERRA);

    if (ebentua == SAGU_BOTOIA_EZKERRA && saguPos.x > 250 && saguPos.x < 455 && saguPos.y>170 && saguPos.y < 195) {
        irudiaKendu(menu);
        pantailaGarbitu();
        barrua();
    }
    if (ebentua == SAGU_BOTOIA_EZKERRA && saguPos.x > 250 && saguPos.x < 455 && saguPos.y > 195 && saguPos.y < 220) {
        irudiaKendu(menu);
        pantailaGarbitu();
        terraza();
    }
    if (ebentua == SAGU_BOTOIA_EZKERRA && saguPos.x > 250 && saguPos.x < 455 && saguPos.y > 220 && saguPos.y < 245) {
        irudiaKendu(menu);
        pantailaGarbitu();
        itxi = -1;
    }

    return itxi;
}

void barrua() {
    MAHAIAK* burua = NULL;
    PERTSONAK* pertson = NULL;
    int itxi, fondoa, robot, per;
    char* str = { "matriz_barrualdea.txt" }, * mahaiak = { "robot_barrualdea.txt" }, *pertsona={"pertsona_barrualdea.txt"};
    V = 14, hasi = 0;

    irudiakJarri(&robot, &fondoa);
    matrizeaOsatu(str);
    mahaienPosizioa(&burua, mahaiak);
    pertsonenPosizioa(&pertson, pertsona);
    dijkstra();
    do {
        end = mahaiaItzuliBarruan();
    } while (end == 0);
    pertsonaKokatu(&per, pertson);
    marrak(burua, end);
    pantailaratu(burua, &robot, end);
    memoriaGarbitu(&burua, &pertson);
    itxi = bukaeraMezua();
    irudiakEzabatu(&per, &fondoa, &robot);
    pantailaGarbitu();
}

void terraza() {
    MAHAIAK* burua = NULL;
    PERTSONAK* pertson = NULL;
    int itxi, fondoa, robot, per;
    char* str_terraza = { "matriz_terraza.txt" }, * mahaiak_terraza = { "robot_terraza.txt" }, * str_barrualdea = { "matriz_barrualdea.txt" },
        * mahaiak_barrualdea = { "robot_barrualdea.txt" }, * pertsona = { "pertsona_terraza.txt" };
    V = 14, end = 13;

    irudiakJarri(&robot, &fondoa);
    matrizeaOsatu(str_barrualdea);
    mahaienPosizioa(&burua, mahaiak_barrualdea);
    dijkstra();
    marrak(burua, end);
    pantailaratu(burua, &robot, end);
    memoriaGarbitu(&burua, &pertson);
    
    V = 7, end = 0;
    irudiakJarri(&robot, &fondoa);
    matrizeaOsatu(str_terraza);
    mahaienPosizioa(&burua, mahaiak_terraza);
    pertsonenPosizioa(&pertson, pertsona);
    dijkstra();
    do {
        end = mahaiaItzuliTerraza();
    } while (end == 0);
    pertsonaKokatu(&per, pertson);
    marrak(burua, end);
    pantailaratu(burua, &robot, end);
    memoriaGarbitu(&burua, &pertson);
    itxi = bukaeraMezua();
    irudiakEzabatu(&per, &fondoa, &robot);
}

int mahaiaItzuliBarruan() {
    
    int i, mahai = 0;
    
    do {
        i = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
    } while (i != SAGU_BOTOIA_EZKERRA);

    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 470) && (saguPos.x < 535) && (saguPos.y > 23) && (saguPos.y < 88)) mahai = 1;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 344) && (saguPos.y > 23) && (saguPos.y < 88)) mahai = 2;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 408) && (saguPos.y > 215) && (saguPos.y < 280)) mahai = 3;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 345) && (saguPos.y > 344) && (saguPos.y < 407)) mahai = 4;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 275) && (saguPos.x < 345) && (saguPos.y > 472) && (saguPos.y < 536)) mahai = 5;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 408) && (saguPos.x < 536) && (saguPos.y > 472) && (saguPos.y < 536)) mahai = 6;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 666) && (saguPos.x < 730) && (saguPos.y > 408) && (saguPos.y < 472)) mahai = 7;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 666) && (saguPos.x < 730) && (saguPos.y > 218) && (saguPos.y < 280)) mahai = 8;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 536) && (saguPos.x < 664) && (saguPos.y > 344) && (saguPos.y < 408)) mahai = 9;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 408) && (saguPos.x < 472) && (saguPos.y > 280) && (saguPos.y < 344)) mahai = 10;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 472) && (saguPos.x < 536) && (saguPos.y > 152) && (saguPos.y < 216)) mahai = 11;

    return mahai;
}

int mahaiaItzuliTerraza() {
    int i, mahai = 0;

    do {
        i = ebentuaJasoGertatuBada();
        saguPos = saguarenPosizioa();
    } while (i != SAGU_BOTOIA_EZKERRA);

    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 489) && (saguPos.x < 645) && (saguPos.y > 0) && (saguPos.y < 138)) mahai = 1;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 188) && (saguPos.x < 327) && (saguPos.y > 0) && (saguPos.y < 138)) mahai = 2;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 188) && (saguPos.x < 327) && (saguPos.y > 200) && (saguPos.y < 353)) mahai = 3;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 199) && (saguPos.x < 345) && (saguPos.y > 400) && (saguPos.y < 544)) mahai = 4;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 510) && (saguPos.x < 658) && (saguPos.y > 400) && (saguPos.y < 547)) mahai = 5;
    if ((i == SAGU_BOTOIA_EZKERRA) && (saguPos.x > 505) && (saguPos.x < 647) && (saguPos.y > 200) && (saguPos.y < 353)) mahai = 6;

    return mahai;
}

void mahaienPosizioa(MAHAIAK** burua, char* mahaiak) {
    FILE* fp;
    MAHAIAK* ptrAux;

    fp = fopen(mahaiak, "r");
    if (fp != NULL) {
        do {
            ptrAux = (MAHAIAK*)malloc(sizeof(MAHAIAK));
            if (ptrAux != NULL) {
                fscanf(fp, "%d %d", &ptrAux->x, &ptrAux->y);
                ptrAux->ptrHurrengoa = NULL;
                if (*burua == NULL) {
                    *burua = ptrAux;
                }
                else {
                    ptrAux->ptrHurrengoa = *burua;
                    *burua = ptrAux;
                }
            }
        } while (!feof(fp));
    }
}

void pertsonenPosizioa(PERTSONAK** burua, char* pertsona) {
    FILE* fp;
    PERTSONAK* ptrAux;

    fp = fopen(pertsona, "r");
    if (fp != NULL) {
        do {
            ptrAux = (PERTSONAK*)malloc(sizeof(PERTSONAK));
            if (ptrAux != NULL) {
                fscanf(fp, "%d %d", &ptrAux->x, &ptrAux->y);
                ptrAux->ptrHurrengoa = NULL;
                if (*burua == NULL) {
                    *burua = ptrAux;
                }
                else {
                    ptrAux->ptrHurrengoa = *burua;
                    *burua = ptrAux;
                }
            }
        } while (!feof(fp));
    }
}

void memoriaErreserbatu() {

    kostua = (int**)malloc(sizeof(int*) * V);
    if (kostua != NULL) {
        for (int i = 0; i < V; i++) {
            *(kostua + i) = (int*)malloc(sizeof(int) * V);
        }
    }
    bisitatuta = (int*)malloc(sizeof(int) * V);
    gurasoak = (int*)malloc(sizeof(int) * V);
    distantzia = (int*)malloc(sizeof(int) * V);
}

void memoriaGarbitu(MAHAIAK** burua, PERTSONAK** buruaP) {
    MAHAIAK* ptrAux, *aurrekoa;
    PERTSONAK* ptrAuxP, *aurrekoaP;
    for (int i = 0; i < V; i++) {
        free(kostua[i]);
    }
    free(kostua);
    free(gurasoak);
    free(bisitatuta);
    free(distantzia);
    ptrAux = *burua;
    while (ptrAux != NULL) {
        aurrekoa = ptrAux;
        ptrAux = ptrAux->ptrHurrengoa;
        free(aurrekoa);
    }
    *burua = NULL;
    ptrAuxP = *buruaP;
    while (ptrAuxP != NULL) {
        aurrekoaP = ptrAuxP;
        ptrAuxP = ptrAuxP->ptrHurrengoa;
        free(aurrekoaP);
    }
    *buruaP = NULL;
}

void pertsonaKokatu(int* pertsona, PERTSONAK* burua) {
    int kont = V - 1;
    PERTSONAK* ptrAux;

    ptrAux = burua;

    while (ptrAux != NULL && kont > end) {
        ptrAux = ptrAux->ptrHurrengoa;
        kont--;
    }

    if (ptrAux != NULL) {
        *pertsona = irudiaSortu(PERTSONA);
        irudiaMugitu(*pertsona, ptrAux->x, ptrAux->y);
        irudiakMarraztu();
        SDL_RenderPresent(gRenderer);
    }
}

void marrak(MAHAIAK* burua, int end) {
    int i = 0, n = end;
    MAHAIAK* ptrAux = NULL;

    while (n != 0) {
        ptrAux = mahaiaAurkitu(burua, n);
        if (ptrAux != NULL) {
            points[i].x = ptrAux->x + 30;
            points[i].y = ptrAux->y + 30;
            i++;
        }
        n = *(gurasoak + n);
    }
    points[i].x = 690;
    points[i].y = 60;
    i++;
    if (V == 14)
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    else
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawLines(gRenderer, points, i);
    SDL_RenderPresent(gRenderer);
    Sleep(2000);
}

void pantailaratu(MAHAIAK* buruMahai, int* robot, int end) {
    MAHAIAK* ptrAuxM;

    if (end != 0) {
        pantailaratu(buruMahai, robot, *(gurasoak + end));
    }
    ptrAuxM = mahaiaAurkitu(buruMahai, end);
    mugimendua(ptrAuxM, robot);
}

MAHAIAK* mahaiaAurkitu(MAHAIAK* buruMahai, int node) {
    MAHAIAK* ptrAux = buruMahai;
    int kont = V - 1;

    while (kont > node && ptrAux != NULL) {
        ptrAux = ptrAux->ptrHurrengoa;
        kont--;
    }

    return ptrAux;
}

void mugimendua(MAHAIAK* ptrAux, int* robot) {
    static int aurrekoX = 0, aurrekoY = 0;
    POSIZIOA pos;

    if (ptrAux == NULL) {
        aurrekoX = 660;
        aurrekoY = 30;
    }
    pos.x = aurrekoX;
    pos.y = aurrekoY;
    
    if (ptrAux != NULL) {
        while (pos.x != ptrAux->x || pos.y != ptrAux->y) {
            pos = mugitu(pos, ptrAux);
            irudiaMugitu(*robot, pos.x, pos.y);
            irudiakMarraztu();
            SDL_RenderPresent(gRenderer);
        }
    }
    aurrekoX = pos.x;
    aurrekoY = pos.y;
}

POSIZIOA mugitu(POSIZIOA pos, MAHAIAK* ptrAux) {
    if (pos.x > ptrAux->x) {
        pos.x -= 1;
    }
    if (pos.x < ptrAux->x) {
        pos.x += 1;
    }
    if (pos.y > ptrAux->y) {
        pos.y -= 1;
    }
    if (pos.y < ptrAux->y) {
        pos.y += 1;
    }

    return pos;
}

int bukaeraMezua() {
    int ebentua;

    SDL_RenderPresent(gRenderer);
    SDL_Delay(2000);
    textuaDesgaitu();
    if (V == 14)
        textuaIdatzi(30, 165, "Sakatu ESC ateratzeko");
    else
        textuaIdatzi(335, 540, "Sakatu ESC ateratzeko");
    SDL_RenderPresent(gRenderer);

    do {
        ebentua = ebentuaJasoGertatuBada();
    } while (ebentua != TECLA_ESCAPE);

    return ebentua;
}

POSIZIOA saguarenPosizioa() { return saguPos; }