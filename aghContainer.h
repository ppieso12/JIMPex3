/**
* \file aghContainer.h
* \author
* \date 08.05.16
* \version 1.0
* \brief Plik naglowkowy zwierajacy interfejs kontenera
*/
#ifndef AGHCONTAINER_H_INCLUDED
#define AGHCONTAINER_H_INCLUDED
// --------------------------------------------------------------
#include <iostream>
#include "aghException.h"
// --------------------------------------------------------------
using namespace std;
// --------------------------------------------------------------
template <typename U>
class aghVector;
// --------------------------------------------------------------
/**
* \class aghContainer
* \author
* \date 08.05.16
* \brief Klasa abstrakcyjna reprezentujaca interfejs kontenera
*/
template <typename T>
class aghContainer
{
private:

public:

    /// \brief Virtualny destruktor
    /// <done>
    virtual ~aghContainer(){};

    /////////////////
    //METODY BAZOWE//
    /////////////////

    /// \brief Metoda dodawania elementu do pojemnika
    /// <done>
    /// \param dodaj¹ca podany jako argument obiekt typu T do pojemnika
    void append(T const&);

    /// \brief podmienia obiekt typu T z obiektem na wybranym miejscu.
    /// <done>
    /// \return Zwraca true je¿eli podane miejsce podmiany jest prawid³owe, w przeciwnym wypadku zwraca false.
    bool replace(int, T const&);

    /// \brief usuwa wszystkie elementy pojemnika
    /// <done>
    void clear(void);

    /// \brief Metoda sprawdzaj¹ca czy pojemnik jest pusty:
    /// <done>
    /// \return zwraca true je¿eli pojemnik jest pusty, inaczej false.
    bool isEmpty(void);

    /// \brief Metoda wyszukuj¹ca element w pojemniku przez wartoœæ od zadanego momentu:
    /// <done>
    /// \return wyszukuje i zwraca indeks pierwszego elementu o wartoœci _value zaczynaj¹c od elementu _from. Je¿eli takiego elementu nie ma to zwraca -1.
    int indexOf(T const&, int) const;

    /// \brief  Metoda sprawdzaj¹ca czy dany element jest ju¿ w pojemniku:
    /// <done>
    /// \return zwraca true je¿eli element o wartoœci _value znajduje siê w pojemniku inaczej zwraca false. Wyszukiwanie rozpoczyna siê od elelmetnu _from.
    bool contains(T const&, int) const;

    /// \brief Metoda pomocnicza w przeszukiwaniu elementow w pojemniku przez wartoœæ od zadanego momentu:
    /// <done>
    /// \return wyszukuje i zwraca indeks pierwszego elementu o wartoœci _value zaczynaj¹c od elementu _from. Je¿eli takiego elementu nie ma to zwraca -1.
    int go_through_container(T const&, int) const;

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

    /// \brief Przeciazony operator przypisania
    /// <done>
    aghContainer & operator=(aghContainer & aghCt);

    /// \brief sprawdza czy zawartoœæ pojemników jest taka sama.
    /// <done>
    bool operator==(aghContainer<T> const& right);

    /// \brief sprawdza czy zawartoœæ pojemników jest ró¿na.
    /// <done>
    bool operator!=(aghContainer<T> const& right);

    /// \brief zwraca element o indeksie n.
    /// <done>
    T& operator[](int n) const throw(aghException);

    /// \brief dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator+=(aghContainer<T> const& right);

    /// \brief dodaje element do pojemnika i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator+=(T const& element);

    /// \brief dodaje element do pojemnika i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator<<(T const& element);

    /// \brief dopisuje wszystkie elementy z pojemnika right i zwraca referencje do this.
    /// <done>
    aghContainer<T>& operator<<(aghContainer<T> const& right);

    /// \brief wypisuje zawartoœæ pojemnika na strumieñ.
    /// <done>
    template <typename U> friend ostream& operator<<(ostream&, aghContainer<U> const&);

    /// \brief Metoda pomocnicza dodajaca element ze zwracaniem referencji
    /// <done>
    aghContainer<T>& addone(T const& element);

    /// \brief Metoda pomocnicza dodajaca wszystkie elementy ze zwracaniem referencji
    /// <done>
    aghContainer<T>& addall(aghContainer<T> const& right);

    /// \brief Metoda pomocnicza przy porownywaniu
    /// <done>
    bool is_the_same(aghContainer<T> const& right);

    ////////////////////////////////////////////////////////////////////////////////
    //METODY WIRTUALNE KTORYCH IMPLEMENTACJA ZOSTANIE ZAWARTA W KLASACH POCHODNYCH//
    ////////////////////////////////////////////////////////////////////////////////

    /// \brief wstawiaj¹ca obiekt typu T w wybrane miejsce.
    /// <clean>
    /// \return Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
    virtual bool insert(int, T const&) = 0;

    /// \brief Metoda zwracaj¹ca wartoœæ elementu
    /// <clean>
    /// \return zwraca wartoœæ w pojemniku. Zak³adamy ¿e indeksowanie wartoœci rozpoczynamy od zera.
    virtual T& at(int) const = 0;

    /// \brief Metoda zwracaj¹ca iloœæ elementów
    /// <clean>
    /// \return zwraca iloœæ elementów w pojemniku
    virtual int size(void) const = 0;

    /// \brief Metoda usuwaj¹ca wybrany element:
    /// <clean>
    /// \return usuwa element na danym miejscu. Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false
    virtual bool remove(int) = 0;

    /// \brief Metoda niszczaca kontener
    /// <clean>
    virtual void kill_them_all(void) = 0;

    /// \brief Metoda Zwracajaca index ostatniego elementu
    /// <clean>
    virtual int last_index(void) const = 0;

    /// \brief Metoda Zwracajaca index ostatniego zaalkowanego elementu
    /// <clean>
    virtual int last_toal_index(void) const = 0;
};
// --------------------------------------------------------------
    /////////////////
    //METODY BAZOWE//
    /////////////////
// --------------------------------------------------------------
template <typename T>
void aghContainer<T>::append(T const &item)
{
    int last_item = this->last_index();
    this->insert(last_item + 1, item);
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::replace(int Chosen_position, T const &item)
{
    int Container_Length_Mem = this->last_total_index();

    if(Chosen_position <= Container_Length_Mem)
    {
        this->insert(Chosen_position, item);
        return true;

    }else
    {
        return false;
    }
}
// --------------------------------------------------------------
template <typename T>
void aghContainer<T>::clear(void)
{
    int Container_Length = this->last_index();

    for(int i = Container_Length; i >= 0; i--)
    {
        this->remove(i);
    }
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::isEmpty(void)
{
    int Container_Size = this->size();

    bool logic_value = (Container_Size == 0);

    return logic_value;
}
// --------------------------------------------------------------
template <typename T>
int aghContainer<T>::go_through_container(T const& _value, int _from = 0) const
{
    int Container_Length = this->last_index();

    for(int i = _from; i <= Container_Length; i++)
    {
        T tmp_value = this->at(i);

        if(tmp_value == _value)
        {
            return i;
        }
    }

    return -1;
}
// --------------------------------------------------------------
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
// --------------------------------------------------------------
    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::is_the_same(aghContainer<T> const& right)
{
    bool Sizes;
    bool Last_Positions;

    int Container_Size = this->size();
    int Container_Right_Size = right.size();
    int Last_Pos = this->last_index();
    int Last_Right_Pos = right.last_index();

    Sizes = (Container_Size == Container_Right_Size);
    Last_Positions = (Last_Pos == Last_Right_Pos);

    if(Sizes&&Last_Positions)
    {
        for(int i = 0; i < Container_Right_Size; i++)
        {
            if(this->at(i) != right.at(i))
            {
                return false;
            }
        }

    }else
    {
        return false;
    }

    return true;
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{
    return this->is_the_same(right);
}
// --------------------------------------------------------------
template <typename T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
    return !(this->is_the_same(right));
}
// --------------------------------------------------------------
template <typename T>
T& aghContainer<T>::operator[](int n) const throw(aghException)
{
    int Container_length = this->last_index();

    if(Container_length < n) throw aghException(0, "Index out of range", __FILE__, __LINE__);

    return this->at(n);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T> & aghContainer<T>::operator=(aghContainer<T> &aghCt)
{
    /*NIE MAM LEPSZEGO POMYSLU*/
    if(this == &aghCt) return *this;

    //DLA ARGUMENTU aghCt
    aghContainer<T> *base_ptr = &aghCt;

    aghVector<T> *derived_ptr_argVc = dynamic_cast< aghVector<T> *>(base_ptr); //rzutowanie w dol hierarchii

    //DLA *this
    aghContainer<T> *base_ptr_this = this;

    aghVector<T> *derived_ptr_this = dynamic_cast< aghVector<T> *>(base_ptr_this); //rzutowanie w dol hierarchii

    *derived_ptr_this = *derived_ptr_argVc;

    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::addone(T const& element)
{
    this->append(element);

    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::addall(aghContainer<T> const& right)
{
    int Container_Right_Size = right.last_index();

    for(int i = 0; i <= Container_Right_Size; i++)
    {
        this->append(right.at(i));
    }

    return *this;
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{
    return this->addall(right);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element)
{
    return this->addone(element);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element)
{
    return this->addone(element);
}
// --------------------------------------------------------------
template <typename T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right)
{
    return this->addall(right);
}
// --------------------------------------------------------------
template <typename T>
ostream& operator<<(ostream& os, aghContainer<T> const& right)
{
    int last_elem = right.last_index();

    if(last_elem < 0)
    {
        os << "EMPTY" << endl;
    }

    for(int i = 0; i <= last_elem; i++)
    {
        os << i + 1 << "." << right.at(i) << endl;
    }

    return os;
}
#endif // AGHCONTAINER_H_INCLUDED
