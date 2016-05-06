#ifndef AGHCONTAINER_H_INCLUDED
#define AGHCONTAINER_H_INCLUDED

#include <iostream>
#include "aghException.h"

using namespace std;

template <typename T>
class aghContainer
{
private:

public:

    aghContainer(){};

    virtual ~aghContainer(){};

    /////////////////
    //METODY BAZOWE//
    /////////////////

    /// \brief Metoda dodawania elementu do pojemnika
    ///
    /// \param dodaj¹ca podany jako argument obiekt typu T do pojemnika
    void append(T const&);

    /// \brief podmienia obiekt typu T z obiektem na wybranym miejscu.
    ///
    /// \return Zwraca true je¿eli podane miejsce podmiany jest prawid³owe, w przeciwnym wypadku zwraca false.
    bool replace(int, T const&);

    /// \brief usuwa wszystkie elementy pojemnika
    ///
    void clear(void);

    /// \brief Metoda sprawdzaj¹ca czy pojemnik jest pusty:
    ///
    /// \return zwraca true je¿eli pojemnik jest pusty, inaczej false.
    bool isEmpty(void);

    /// \brief Metoda wyszukuj¹ca element w pojemniku przez wartoœæ od zadanego momentu:
    ///
    /// \return wyszukuje i zwraca indeks pierwszego elementu o wartoœci _value zaczynaj¹c od elementu _from. Je¿eli takiego elementu nie ma to zwraca -1.
    int indexOf(T const&, int) const;

    /// \brief  Metoda sprawdzaj¹ca czy dany element jest ju¿ w pojemniku:
    ///
    /// \return zwraca true je¿eli element o wartoœci _value znajduje siê w pojemniku inaczej zwraca false. Wyszukiwanie rozpoczyna siê od elelmetnu _from.
    bool contains(T const&, int) const;

    /// \brief Metoda pomocnicza w przeszukiwaniu elementow w pojemniku przez wartoœæ od zadanego momentu:
    ///
    /// \return wyszukuje i zwraca indeks pierwszego elementu o wartoœci _value zaczynaj¹c od elementu _from. Je¿eli takiego elementu nie ma to zwraca -1.
    int go_through_container(T const&, int) const;

    /// \brief Metoda niszczaca kontener
    ///
    void kill_them_all(void){this->~aghContainer();};


    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

    /// \brief Przeciazony operator przypisania
    ///
    aghContainer & operator=(const aghContainer & aghCt);

    /// \brief sprawdza czy zawartoœæ pojemników jest taka sama.
    ///
    bool operator==(aghContainer<T> const& right);

    /// \brief sprawdza czy zawartoœæ pojemników jest ró¿na.
    ///
    bool operator!=(aghContainer<T> const& right);

    /// \brief zwraca element o indeksie n.
    /// <done>
    T& operator[](int n) const throw(aghException);

    /// \brief dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    ///
    aghContainer<T>& operator+=(aghContainer<T> const& right);

    /// \brief dodaje element do pojemnika i zwraca referencje do this.
    ///
    aghContainer<T>& operator+=(T const& element);

    /// \brief dodaje element do pojemnika i zwraca referencje do this.
    ///
    aghContainer<T>& operator<<(T const& element);

    /// \brief dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    ///
    aghContainer<T>& operator<<(aghContainer<T> const& right);

    /// \brief wypisuje zawartoœæ pojemnika na strumieñ.
    ///
    template <typename U> friend ostream& operator<<(ostream&, aghContainer<U> const& right);

    ////////////////////////////////////////////////////////////////////////////////
    //METODY WIRTUALNE KTORYCH IMPLEMENTACJA ZOSTANIE ZAWARTA W KLASACH POCHODNYCH//
    ////////////////////////////////////////////////////////////////////////////////

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
    /////////////////
    //METODY BAZOWE//
    /////////////////

template <typename T>
void aghContainer<T>::append(T const &item)
{
    int Container_Size = this->size();

    if(this->is_free_space())
    {
        this->insert(Container_Size + 1, item);

    }else
    {
        this->broaden_container_memory();
        this->insert(Container_Size + 1, item);
    }
}
template <typename T>
bool aghContainer<T>::replace(int Chosen_position, T const &item)
{
    int Container_Size = this->size();

    if(Chosen_position <= Container_Size)
    {
        this->insert(Chosen_position, item);
        return true;

    }else
    {
        return false;
    }
}
template <typename T>
void aghContainer<T>::clear(void)
{
    int Container_Size = this->size();

    for(int i = Container_Size; i >= 0; i--)
    {
        this->remove(i);
    }
}
template <typename T>
bool aghContainer<T>::isEmpty(void)
{
    int Container_Size = this->size();

    if(Container_Size == 0)
    {
        return true;

    }else
    {
        return false;
    }
}
template <typename T>
int aghContainer<T>::go_through_container(T const& _value, int _from = 0) const
{
    int Container_Size = this->size();

    for(int i = _from; i <= Container_Size; i++)
    {
        T tmp_value = this->at(i);

        if(tmp_value == _value)
        {
            return i;
        }
    }

    return -1;
}

template <typename T>
int aghContainer<T>::indexOf(T const& _value, int _from = 0) const
{
    return this->go_through_container(_value, _from);
}
template <typename T>
bool aghContainer<T>::contains(T const& _value, int _from = 0) const
{
    int tell_me_sth = this->go_through_container(_value, _from);

    if(tell_me_sth >= 0)
    {
        return true;

    }else
    {
        return false;
    }
}

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

template <typename T>
T& aghContainer<T>::operator[](int n) const throw(aghException)
{
    int Container_Size = this->size();

    if(Container_Size < n) throw aghException(0, "Index out of range", __FILE__, __LINE__);

    return this->at(n);
}

template <typename T>
aghContainer<T> & aghContainer<T>::operator=(const aghContainer<T> & aghCt)
{
    if(this == &aghCt) return *this;

    this->kill_them_all();



    return *this;
}
/*template <typename T>
ostream& aghContainer<T> operator<<(ostream& os, aghContainer<T> const& right)
{
    int Container_Size = right.size();

    for(int i = 0; i < Container_Size; i++)
    {
        os << i << "." << right.at(i) << endl;
    }

    return os;
}*/





#endif // AGHCONTAINER_H_INCLUDED


