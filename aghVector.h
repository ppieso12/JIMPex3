#ifndef AGHVECTOR_H_INCLUDED
#define AGHVECTOR_H_INCLUDED
#include "aghContainer.h"
#include "aghException.h"

template <typename T>
class aghVector: public aghContainer<T>
{
private:

    T *tab;
    unsigned int Total_length;
    unsigned int Tail;


public:

    aghVector();

    virtual ~aghVector();


    //////////////////////////////////
    //METODY WIRTUALNE DLA AGHVECTOR//
    //////////////////////////////////

    /// \brief Metoda sprawdzajaca czy w okreslonym kontenerze znajduje sie wolny obszar w zaalokowanej pamieci
    ///
    virtual bool is_free_space(void) = 0;

    /// \brief Metoda rozszerzajaca rozmiar kontenera
    ///
    virtual void broaden_container_memory(void) = 0;

    /// \brief wstawiaj¹ca obiekt typu T w wybrane miejsce.
    ///
    /// \return Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
    virtual bool insert(int, T const&) = 0;


    /// \brief Metoda zwracaj¹ca wartoœæ elementu
    ///
    /// \return zwraca wartoœæ w pojemniku. Zak³adamy ¿e indeksowanie wartoœci rozpoczynamy od zera.
    virtual T& at(int) const = 0;


    /// \brief Metoda zwracaj¹ca iloœæ elementów
    ///
    /// \return zwraca iloœæ elementów w pojemniku
    virtual int size(void) const = 0;


    /// \brief Metoda usuwaj¹ca wybrany element:
    ///
    /// \return usuwa element na danym miejscu. Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false
    virtual bool remove(int) = 0;





};


#endif // AGHVECTOR_H_INCLUDED
