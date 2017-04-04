//
// Created by bodzbarb on 28.03.17.
//

#ifndef JIMP_EXERCISES_RODZINA_H
#define JIMP_EXERCISES_RODZINA_H

#include "string"
#include "iostream"

class Rodzic {
public:
    Rodzic(std::string imie_rodzica, std::string nazwisko_rodzica, int wiek_rodzica) {
        imie=imie_rodzica;
        nazwisko=nazwisko_rodzica;
        wiek=wiek_rodzica;
        Dzieciak=new Dziecko("Ania",nazwisko_rodzica,9,"Szkoła Podstawowa nr 2");
    }
    void przepiszDoInnejSzkoly(std::string nowa_szkola) {
        Dzieciak->szkola=nowa_szkola;
        std::cout<<Dzieciak->szkola;
    }
private:
    std::string imie;
    std::string nazwisko;
    int wiek;
    Dziecko *Dzieciak;
};

class Dziecko {
public:
    Dziecko(std::string imie_dziecka, std::string nazwisko_dziecka, int wiek_dziecka, std::string szkola_dziecka) {
        imie=imie_dziecka;
        nazwisko=nazwisko_dziecka;
        wiek=wiek_dziecka;
        szkola=szkola_dziecka;
    }
    friend class Rodzic;
private:
    std::string imie;
    std::string nazwisko;
    int wiek;
    std::string szkola;
};

#endif //JIMP_EXERCISES_RODZINA_H
