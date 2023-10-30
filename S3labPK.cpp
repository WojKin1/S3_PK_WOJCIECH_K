#include<iostream>

#define Zadanie2

/* Zmieniaj¹c ostatni¹ literê w poni¿szej instrukcji na D (dodatkowe), lub P (podstawowe)
*  wybierasz aktywne zadanie.
*
*  UWAGA: jeœli rozwi¹zanie zadañ wymaga podzia³u programu na pliki to dodaj je wszystkie do
*  projektu, ale przy ka¿dym zadaniu "includuj" tylko te, które jego dotycz¹.
*  Poni¿sze bloki dotycz¹ zadañ z zajeæ.
*/


#ifdef Zadanie1


#include <iostream>
#include <cmath>
using namespace std;
class Punkt
{
    double m_x;
    double m_y;

public:
    Punkt() : m_x(0.0), m_y(0.0) {} // Konstruktor domyœlny

    void setXY(double x, double y)
    {
        m_x = x;
        m_y = y;
    }
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    Punkt(double x, double y)
        : m_x(x), m_y(y)
    {}
};

class Kwadrat
{
    Punkt m_lewy_dolny, m_prawy_gorny;

public:
    void setRogi(Punkt ld, Punkt pg)
    {
        m_lewy_dolny = ld;
        m_prawy_gorny = pg;
    }
    Punkt getLewyDolny() const { return m_lewy_dolny; }
    Punkt getPrawyGorny() const { return m_prawy_gorny; }
    Kwadrat(Punkt ld, Punkt pg)
        : m_lewy_dolny(ld), m_prawy_gorny(pg)
    {}

    // Konstruktor konwersji formalnej
    Kwadrat(const Punkt& punkt)
    {
        double dx = -punkt.getX();
        double dy = -punkt.getY();

        Punkt lewyDol(punkt.getX() + dx, punkt.getY() + dy);
        Punkt prawaGora(punkt.getX() - dx, punkt.getY() - dy);

        m_lewy_dolny = lewyDol;
        m_prawy_gorny = prawaGora;
    }
};

int main()
{
    Punkt punktZrodlowy(2.0, 3.0);
    Kwadrat nowaWersjaK = punktZrodlowy; // U¿yj konwersji formalnej

    cout << "Kwadrat: Lewy Dolny: (" << nowaWersjaK.getLewyDolny().getX() << ", " << nowaWersjaK.getLewyDolny().getY() << ")";
    cout << " Prawy Gorny: (" << nowaWersjaK.getPrawyGorny().getX() << ", " << nowaWersjaK.getPrawyGorny().getY() << ")";

    return 0;
}


#endif


#ifdef Zadanie2

#include <iostream>
#include <cmath>
using namespace std;
class Punkt;

class wektor
{
    double m_dx;
    double m_dy;

public:
    void setDXY(double dx, double dy)
    {
        m_dx = dx;
        m_dy = dy;
    }
    double getDX() const { return m_dx; }
    double getDY() const { return m_dy; }
    double dlugosc() const { return sqrt(m_dx * m_dx + m_dy * m_dy); }
    wektor(double dx, double dy)
        : m_dx(dx), m_dy(dy)
    {}

    // wektor ---> punkt (nieformalna)
    Punkt naPunkt() const;
};

class Punkt
{
    double m_x;
    double m_y;

public:
    void setXY(double x, double y)
    {
        m_x = x;
        m_y = y;
    }
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    Punkt(double x, double y)

        : m_x(x), m_y(y)
    {}

    // z punkt na wektor (nieformalna)
    wektor naWektor() const;
    void przesunPunkt(const wektor& wektor, double n = 1.0);
};

// Definicje konwersji
Punkt wektor::naPunkt() const
{
    return Punkt(m_dx, m_dy);
}

wektor Punkt::naWektor() const
{
    return wektor(m_x, m_y);
}

// Przesuwa punkt o podana wielokrotnosc wektora.
// Argument "n" (opcjonalny) okresla, ile razy wielokrotnosc wektora zostanie zastosowana.

void Punkt::przesunPunkt(const wektor& wektor, double n)
{
    m_x += n * wektor.getDX();
    m_y += n * wektor.getDY();
}

int main()
{
    wektor wektor(2.0, 3.0);
    Punkt punkt(0.0, 0.0);

    Punkt wyn = wektor.naPunkt();
    cout << "Konwersja wektor na punkt: (" << wyn.getX() << ", " << wyn.getY() << ")"<<endl;

    punkt.przesunPunkt(wektor, 3.0); // przesuniecie o dlugosc wektora * 3
   cout << "przesuniety punkt: (" << punkt.getX() << ", " << punkt.getY() << ")"<<endl;

    return 0;
}


#endif

#ifdef Zadanie3

// TU UMIEŒÆ KOD ROZWIAZANIA ZADANIA AMBITNEGO

#endif

/*
	Poni¿sze bloki warunkowe dotycz¹ zadañ kolokwialnych.
	Oddaj¹c zadania z zajêæ, skasuj poni¿sze bloki.
	Oddaj¹c zadania z kolokwium skasuj powy¿sze bloki.
*/


#ifdef Blok1

// TU UMIEŒÆ KOD ROZWIAZANIA ZADANIA Z BLOKU 1

#endif

#ifdef Blok2

// TU UMIEŒÆ KOD ROZWIAZANIA ZADANIA Z BLOKU 2

#endif

#ifdef Blok3

// TU UMIEŒÆ KOD ROZWIAZANIA ZADANIA Z BLOKU 3

#endif

#ifdef Blok4

// TU UMIEŒÆ KOD ROZWIAZANIA ZADANIA Z BLOKU 4

#endif