#include "ObradaRacuna.h"

int provjeraVrijednostiRacuna(double ukupnaCijena, double pdv, double ukupnoSaPdv, int brP, PROIZVOD* proizvodi, char* fileName)
{
    if(ukupnoSaPdv != pdv + ukupnaCijena)
    {
        printf("greska");
        return 0;
    }
    else
    {
        double uk = 0;
        for(int i = 0; i < brP; ++i)
            if(proizvodi[i].cijena * proizvodi[i].kolicina != proizvodi[i].ukupno)
                {
                    printf("greska1");
                    return 0;
                }
            else
                uk += proizvodi[i].cijena * proizvodi[i].kolicina;

        if(uk != ukupnaCijena)
        {
            printf("greska2");
            return 0;

        }
    }

} //GDJE GOD SE ISPISUJE GRESKA POTREBNO JE PREBACITI FAJL U FOLDER SA NEOGOVARAJUCIM!

void obradiProizode(int br, PROIZVOD** nizProizvoda, PROIZVOD* proizvodiSaRacuna)
{
    int brP = sizeof(*nizProizvoda) / sizeof(PROIZVOD);
    int i = 0;
    if(brP == 0)
    {
        *nizProizvoda = (PROIZVOD*) malloc(sizeof(PROIZVOD));
        (*nizProizvoda)[brP] = proizvodiSaRacuna[0];
        brP++;
        i++;
    }

    for(i; i < br; ++i)
    {
        for(int j = 0; j < brP; ++j)
        {
            if(!strcmp((*nizProizvoda)[j].naziv , proizvodiSaRacuna[i].naziv) && (*nizProizvoda)[j].cijena == proizvodiSaRacuna[i].cijena)
            {
                (*nizProizvoda)[j].kolicina += proizvodiSaRacuna[i].kolicina;
                (*nizProizvoda)[j].ukupno += proizvodiSaRacuna[i].cijena * proizvodiSaRacuna[i].kolicina;
                break;
            }
            else
            {
                *nizProizvoda = (PROIZVOD*) realloc(*nizProizvoda, sizeof(PROIZVOD)* (brP + 1));
                (*nizProizvoda)[brP] = proizvodiSaRacuna[i];
                brP++;
                break;
            }
        }

    }
    for(int i = 0; i < brP; ++i)
    {
    printf("\n%s", (*nizProizvoda)[i].naziv);
    printf("\n%d", (*nizProizvoda)[i].kolicina);
    printf("\n%lf", (*nizProizvoda)[i].cijena);
    printf("\n%lf", (*nizProizvoda)[i].ukupno);
    }
}

void obradiKupca(KUPAC kupac, KUPAC** nizKupaca, int brP)
{
    int brK = sizeof(*nizKupaca) / sizeof(KUPAC);
    //printf("\n\n%d\n\n" , brK);
    if(brK == 0)
    {
        *nizKupaca = (KUPAC*) malloc(sizeof(KUPAC));
        strcpy((*nizKupaca)[0].ime, kupac.ime);
        (*nizKupaca)[0].kupljeniProizvodi = (PROIZVOD*) malloc(sizeof(PROIZVOD)*brP);
        for(int i = 0; i < brP; ++i)
            (*nizKupaca)[0].kupljeniProizvodi[i] = kupac.kupljeniProizvodi[i];
        brK++;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brK; ++i)
            if(!strcmp(kupac.ime, (*nizKupaca)[i].ime))
            {
                obradiProizode(brP, &((*nizKupaca)[i].kupljeniProizvodi), kupac.kupljeniProizvodi);
                brK++;
                flag = 1;
                break;
            }
        if(flag == 0)
        {
            *nizKupaca = (KUPAC*) realloc(*nizKupaca, sizeof(KUPAC)*(brK + 1));
            strcpy((*nizKupaca)[brK].ime, kupac.ime);
            (*nizKupaca)[brK].kupljeniProizvodi = (PROIZVOD*) malloc(sizeof(PROIZVOD)*brP);
            for(int i = 0; i < brP; ++i)
                (*nizKupaca)[brK].kupljeniProizvodi[i] = kupac.kupljeniProizvodi[i];
            brK++;
        }

    }
    printf("\nkupci");
    for(int j = 0; j < brK; ++j)
    {
        printf("\n%s", (*nizKupaca)[j].ime);
        for(int i = 0; i < brP; ++i)
    {
        printf("\n%s", (*nizKupaca)[j].kupljeniProizvodi[i].naziv);
        printf("\n%d", (*nizKupaca)[j].kupljeniProizvodi[i].kolicina);
        printf("\n%lf", (*nizKupaca)[j].kupljeniProizvodi[i].cijena);
        printf("\n%lf", (*nizKupaca)[j].kupljeniProizvodi[i].ukupno);
    }

    }
}

/*void obradiMjesec(int mj, int god, MJESEC** mjeseci, KUPAC kupac)
{
    int brM = sizeof(*mjeseci) / sizeof(MJESEC);
    int brP = sizeof(kupac.kupljeniProizvodi) / sizeof(PROIZVOD);
    if(brM == 0)
    {
        *mjeseci = (MJESEC*) realloc(*mjeseci, sizeof(MJESEC));
        (*mjeseci)[0].mjesec = mj;
        (*mjeseci)[0].godina = god;
        (*mjeseci)[0].ukupnaProdaja = (KUPAC*) malloc(sizeof(KUPAC));
        (*mjeseci)[0].ukupnaProdaja[0].kupljeniProizvodi = (PROIZVOD*) malloc(sizeof(PROIZVOD)*brP);
        for(int i = 0; i < brP; ++i)
        {
            (*mjeseci)[0].ukupnaProdaja[0].kupljeniProizvodi[i] = kupac.kupljeniProizvodi[i];
        }
        brM++;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brM; ++i)
            if((*mjeseci)[i].mjesec == mj && (*mjeseci)[i].godina == god)
            {
                (*mjeseci)[i].ukupnaProdaja = NULL;
                obradiKupca(kupac, &((*mjeseci)[i].ukupnaProdaja), brP);
                brM++;
                flag = 1;
                break;
            }
        if(flag == 0)
        {
            *mjeseci = (MJESEC*) realloc(*mjeseci, sizeof(MJESEC)*(brM + 1));
            (*mjeseci)[brM].mjesec = mj;
            (*mjeseci)[brM].godina = god;
            (*mjeseci)[brM].ukupnaProdaja = (KUPAC*) malloc(sizeof(KUPAC));
            (*mjeseci)[brM].ukupnaProdaja[brM].kupljeniProizvodi = (PROIZVOD*) malloc(sizeof(PROIZVOD)*brP);
            for(int i = 0; i < brP; ++i)
            {
                (*mjeseci)[brM].ukupnaProdaja[brM].kupljeniProizvodi[i] = kupac.kupljeniProizvodi[i];
            }
            brM++;
        }
    }

    for(int k = 0; k < brM; ++k)
    {
        printf("\nmj %d, god %d", (*mjeseci)[k].mjesec, (*mjeseci)[k].godina);
        for(int j = 0; j < 1; ++j)
        {
            printf("\n%s", (*mjeseci)[k].ukupnaProdaja[j].ime);
            for(int i = 0; i < brP; ++i)
            {
                printf("\n%s", (*mjeseci)[k].ukupnaProdaja[j].kupljeniProizvodi[i].naziv);
                printf("\n%d", (*mjeseci)[k].ukupnaProdaja[j].kupljeniProizvodi[i].kolicina);
                printf("\n%lf", (*mjeseci)[k].ukupnaProdaja[j].kupljeniProizvodi[i].cijena);
                printf("\n%lf", (*mjeseci)[k].ukupnaProdaja[j].kupljeniProizvodi[i].ukupno);
            }
        }
    }


}
*/
