#include "ObradaRacuna.h"

int provjeraVrijednostiRacuna(double ukupnaCijena, double pdv, double ukupnoSaPdv, int brP, PODACI* proizvodi, char* fileName)
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



void obradiPodatke(PODACI** nizPodataka, PODACI* podaciSaRacuna, int brPodatakaSaRacuna)
{
    if(brPodataka == 0)
    {
        *nizPodataka = (PODACI*) malloc(sizeof(PODACI) * brPodatakaSaRacuna);
        for(int i = 0; i < brPodatakaSaRacuna; ++i)
            (*nizPodataka)[i] = podaciSaRacuna[i];
        brPodataka += brPodatakaSaRacuna;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brPodatakaSaRacuna; ++i)
        {
            for(int j = 0; j < brPodataka; ++j)
            {
                if(!strcmp((*nizPodataka)[j].naziv_proizvoda, podaciSaRacuna[i].naziv_proizvoda) &&
                   !strcmp(podaciSaRacuna[i].ime_kupca, (*nizPodataka)[j].ime_kupca) &&
                   podaciSaRacuna[i].cijena == (*nizPodataka)[j].cijena && podaciSaRacuna[i].mjesec == (*nizPodataka)[j].mjesec &&
                   podaciSaRacuna[i].godina == (*nizPodataka)[j].godina)
                {
                    (*nizPodataka)[j].kolicina += podaciSaRacuna[i].kolicina;
                    (*nizPodataka)[j].ukupno = (*nizPodataka)[j].kolicina * (*nizPodataka)[j].cijena;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                *nizPodataka = (PODACI*) realloc(*nizPodataka, sizeof(PODACI) * (brPodataka + 1));
                (*nizPodataka)[brPodataka] = podaciSaRacuna[i];
                brPodataka++;
            }
            flag = 0;
        }
    }

}

void dodajKupca(KUPAC** nizKupaca, char* ime)
{
    if(brK == 0)
    {
        *nizKupaca = (KUPAC*) malloc( sizeof(KUPAC));
        strcpy((*nizKupaca)[0].ime, ime);
        brK++;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brK; ++i)
            if(!strcmp((*nizKupaca)[i].ime, ime))
                flag = 1;
        if(flag == 0)
        {
            (*nizKupaca) = (KUPAC*) realloc(*nizKupaca, sizeof(KUPAC) * (brK + 1));
            strcpy((*nizKupaca)[brK].ime, ime);
            brK++;
        }
    }
}

void dodajMjesec(MJESEC** nizMj, int mj, int god)
{
    if(brM == 0)
    {
        *nizMj = (MJESEC*) malloc(sizeof(MJESEC));
        (*nizMj)[0].mjesec = mj;
        (*nizMj)[0].godina = god;
        brM++;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brM; ++i)
            if((*nizMj)[i].mjesec == mj && (*nizMj)[i].godina == god)
                flag = 1;
        if(flag == 0)
        {
            (*nizMj) = (MJESEC*) realloc(*nizMj, sizeof(MJESEC) * (brM + 1));
            (*nizMj)[brM].mjesec = mj;
            (*nizMj)[brM].godina = god;
            brM++;
        }
    }
}

void dodajProizvod(PROIZVOD** nizProizvida, char* naziv)
{
    if(brP == 0)
    {
        *nizProizvida = (PROIZVOD*) malloc( sizeof(PROIZVOD));
        strcpy((*nizProizvida)[0].naziv, naziv);
        brP++;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < brP; ++i)
            if(!strcmp((*nizProizvida)[i].naziv, naziv))
                flag = 1;
        if(flag == 0)
        {
            (*nizProizvida) = (PROIZVOD*) realloc(*nizProizvida, sizeof(PROIZVOD) * (brP + 1));
            strcpy((*nizProizvida)[brP].naziv, naziv);
            brP++;
        }
    }
}
