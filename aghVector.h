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

    /// \brief wstawiaj�ca obiekt typu T w wybrane miejsce.
    ///
    /// \return Zwraca true je�eli podane miejsce wstawienia jest prawid�owe, w przeciwnym wypadku zwraca false.
    virtual bool insert(int, T const&) = 0;


    /// \brief Metoda zwracaj�ca warto�� elementu
    ///
    /// \return zwraca warto�� w pojemniku. Zak�adamy �e indeksowanie warto�ci rozpoczynamy od zera.
    virtual T& at(int) const = 0;


    /// \brief Metoda zwracaj�ca ilo�� element�w
    ///
    /// \return zwraca ilo�� element�w w pojemniku
    virtual int size(void) const = 0;


    /// \brief Metoda usuwaj�ca wybrany element:
    ///
    /// \return usuwa element na danym miejscu. Zwraca true je�eli podane miejsce usuni�cia jest prawid�owe, w przeciwnym wypadku zwraca false
    virtual bool remove(int) = 0;





};


#endif // AGHVECTOR_H_INCLUDED
