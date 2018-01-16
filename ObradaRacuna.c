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

void obradiProizode(int brPrSaRacuna, PROIZVOD** nizProizvoda, PROIZVOD* proizvodiSaRacuna)
{
    int i = 0;
    if(brP == 0)
    {
        *nizProizvoda = (PROIZVOD*) malloc(sizeof(PROIZVOD));
        (*nizProizvoda)[brP] = proizvodiSaRacuna[0];
        brP++;
        i++;
    }
    int flag = 0;
    for(i; i < brPrSaRacuna; ++i)
    {
        for(int j = 0; j < brP; ++j)
        {
            if(!strcmp((*nizProizvoda)[j].naziv , proizvodiSaRacuna[i].naziv) && (*nizProizvoda)[j].cijena == proizvodiSaRacuna[i].cijena)
            {
                (*nizProizvoda)[j].kolicina += proizvodiSaRacuna[i].kolicina;
                (*nizProizvoda)[j].ukupno += proizvodiSaRacuna[i].cijena * proizvodiSaRacuna[i].kolicina;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            *nizProizvoda = (PROIZVOD*) realloc(*nizProizvoda, sizeof(PROIZVOD)* (brP + 1));
            (*nizProizvoda)[brP] = proizvodiSaRacuna[i];
            brP++;
        }
        flag = 0;

    }
    /*for(int i = 0; i < brP; ++i)
    {
    printf("\n%s", (*nizProizvoda)[i].naziv);
    printf("\n%d", (*nizProizvoda)[i].kolicina);
    printf("\n%lf", (*nizProizvoda)[i].cijena);
    printf("\n%lf", (*nizProizvoda)[i].ukupno);
    }*/
}

int obradiProizode_pomocna(int brPrZaUnos, PROIZVOD** nizProizvoda, PROIZVOD* proizvodiSaRacuna, int brP)
{
    int i = 0, n = 0;
    if(brP == 0)
    {
        *nizProizvoda = (PROIZVOD*) malloc(sizeof(PROIZVOD));
        (*nizProizvoda)[brP] = proizvodiSaRacuna[0];
        brP++;
        n++;
        i++;
    }
    int flag = 0;
    for(i; i < brPrZaUnos; ++i)
    {
        for(int j = 0; j < brP; ++j)
        {
            if(!strcmp((*nizProizvoda)[j].naziv , proizvodiSaRacuna[i].naziv) && (*nizProizvoda)[j].cijena == proizvodiSaRacuna[i].cijena)
            {
                (*nizProizvoda)[j].kolicina += proizvodiSaRacuna[i].kolicina;
                (*nizProizvoda)[j].ukupno += proizvodiSaRacuna[i].cijena * proizvodiSaRacuna[i].kolicina;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            *nizProizvoda = (PROIZVOD*) realloc(*nizProizvoda, sizeof(PROIZVOD)* (brP + 1));
            (*nizProizvoda)[brP] = proizvodiSaRacuna[i];
            n++;
            brP++;
        }
        flag = 0;
    }
    return n;
}


void obradiKupca(KUPAC kupac, KUPAC** nizKupaca)
{
    if(brK == 0)
    {
        *nizKupaca = (KUPAC*) malloc(sizeof(KUPAC));
        strcpy((*nizKupaca)[0].ime, kupac.ime);
        (*nizKupaca)[0].kupljeniProizvodi = (PROIZVOD*) malloc(sizeof(PROIZVOD)*kupac.br);
        for(int i = 0; i < kupac.br; ++i)
            (*nizKupaca)[0].kupljeniProizvodi[i] = kupac.kupljeniProizvodi[i];
        (*nizKupaca)[0].br = kupac.br;
        brK++;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brK; ++i)
            if(!strcmp(kupac.ime, (*nizKupaca)[i].ime))
            {
                int n = obradiProizode_pomocna(kupac.br, &((*nizKupaca)[i].kupljeniProizvodi), kupac.kupljeniProizvodi, (*nizKupaca)[i].br);
                (*nizKupaca)[i].br += n;
                flag = 1;
                break;
            }
        if(flag == 0)
        {
            *nizKupaca = (KUPAC*) realloc(*nizKupaca, sizeof(KUPAC)*(brK + 1));
            strcpy((*nizKupaca)[brK].ime, kupac.ime);
            (*nizKupaca)[brK].kupljeniProizvodi = (PROIZVOD*) malloc(sizeof(PROIZVOD)*brP);
            (*nizKupaca)[brK].br = kupac.br;
            for(int i = 0; i < brP; ++i)
                (*nizKupaca)[brK].kupljeniProizvodi[i] = kupac.kupljeniProizvodi[i];
            brK++;
        }
    }
   /* printf("\nkupci");
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

    }*/
}

void obradiMjesec(int mj, int god, MJESEC** nizMjeseci, PROIZVOD* proizvodiSaRacuna, int brPr)
{
    if(brM == 0)
    {
        *nizMjeseci = (MJESEC*) malloc(sizeof(MJESEC));
        (*nizMjeseci)[0].mjesec = mj;
        (*nizMjeseci)[0].godina = god;
        (*nizMjeseci)[0].br = brP;
        (*nizMjeseci)[0].ukupnaProdaja = (PROIZVOD*) malloc(sizeof(PROIZVOD) * (*nizMjeseci)[0].br);
        for(int i = 0; i < (*nizMjeseci)[0].br; ++i)
            (*nizMjeseci)[0].ukupnaProdaja[i] = proizvodiSaRacuna[i];
        brM++;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brM; ++i)
            if((*nizMjeseci)[i].mjesec == mj && (*nizMjeseci)[i].godina == god)
            {
                int n = obradiProizode_pomocna(brPr, &((*nizMjeseci)[i].ukupnaProdaja), proizvodiSaRacuna, (*nizMjeseci)[i].br);
                (*nizMjeseci)[i].br += n;
                flag = 1;
                break;
            }
        if(flag == 0)
        {
            *nizMjeseci = (MJESEC*) realloc(*nizMjeseci, sizeof(MJESEC)* (brM + 1));
            (*nizMjeseci)[brM].mjesec = mj;
            (*nizMjeseci)[brM].godina = god;
            (*nizMjeseci)[brM].br = brPr;
            (*nizMjeseci)[brM].ukupnaProdaja = (PROIZVOD*) malloc(sizeof(PROIZVOD) * brPr);
            for(int i = 0; i < (*nizMjeseci)[brM].br; ++i)
                (*nizMjeseci)[brM].ukupnaProdaja[i] = proizvodiSaRacuna[i];
            brM++;
        }
    }


}
