#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "dirent.h"
#include "PrebacivanjeRacuna.h"

//Funckija vraca pokazivac na niz imena fajlova koji se nalaze u folderu "racuni"
//Ako ne uspije pronaci direktorijum, vraca NULL i ispisuje poruku.
//Kraj niza je oznacen sa '\0'
//Poziva se kao: char** files = scandirr();

char** scandirr();