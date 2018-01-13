#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "dirent.h"

//Funckija vraca pokazivac na niz imena fajlova koji se nalaze u folderu "racuni"
//Ako ne uspije pronaci direktorijum, vraca NULL i ispisuje poruku.
//Kraj niza je oznacen sa '\0'

char** scandirr();