#ifndef AGHVECTOR_H_INCLUDED
#define AGHVECTOR_H_INCLUDED
#include "aghContainer.h"
#include "aghException.h"

template <typename T>
class aghVector: public aghContainer<T>
{
private:

    T *tab_ptr;         ///<
    int total_length;   ///<
    int last_item;      ///<


public:

    /// \brief Konstruktor domyslny
    /// <done>
    aghVector();

    /// \brief Konstruktor parametrowy - tworzy Vector o zadanym rozmiarze
    /// <done>
    aghVector(int init_length);

    /// \brief Konstruktor kopiujacy
    /// <done>
    aghVector(aghContainer<T> &arg_obj);

    /// \brief Destruktor dla Vectora
    /// <done>
    virtual ~aghVector();

    /////////////////////
    //METODY POMOCNICZE//
    /////////////////////

    /// \brief Metoda pomocnicza alokujaca pamiec
    /// <done>
    void allocate_memory(int new_size);

    /// \brief Metoda pomocnicza zwalniajaca pamiec
    /// <done>
    void free_memory(void);

    //////////////////////////////////
    //METODY WIRTUALNE DLA AGHVECTOR//
    //////////////////////////////////

    /// \brief Metoda sprawdzajaca czy w okreslonym kontenerze znajduje sie wolny obszar w zaalokowanej pamieci
    /// <done>
    virtual bool is_free_space(void);

    /// \brief Metoda rozszerzajaca rozmiar kontenera o 50% (rozmiar rzutowany do int)
    /// <done>
    virtual void broaden_container_memory(void);

    /// \brief wstawiaj¹ca obiekt typu T w wybrane miejsce.
    /// <done>
    /// \return Zwraca true je¿eli podane miejsce wstawienia jest prawid³owe, w przeciwnym wypadku zwraca false.
    virtual bool insert(int, T const&);

    /// \brief Metoda zwracaj¹ca wartoœæ elementu
    /// <done>
    /// \return zwraca wartoœæ w pojemniku. Zak³adamy ¿e indeksowanie wartoœci rozpoczynamy od zera.
    virtual T& at(int) const throw(aghException);

    /// \brief Metoda zwracaj¹ca iloœæ elementów
    /// <done>
    /// \return zwraca iloœæ elementów w pojemniku
    virtual int size(void) const;

    /// \brief Metoda usuwaj¹ca wybrany element:
    /// <done>
    /// \return usuwa element na danym miejscu. Zwraca true je¿eli podane miejsce usuniêcia jest prawid³owe, w przeciwnym wypadku zwraca false
    virtual bool remove(int);

    /// \brief Metoda niszczaca kontener
    /// <done>
    virtual void kill_them_all(void);

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

    /// \brief Przeciazony operator przypisania
    ///
    aghVector & operator=(const aghVector<T> & aghVc);

};
template <typename T>
aghVector<T>::aghVector()
{
    this->allocate_memory(5);
    this->total_length = 5;
    this->last_item = 0;
}
template <typename T>
aghVector<T>::aghVector(int init_length)
{
    this->allocate_memory(init_length);
    this->total_length = init_length;
    this->last_item = 0;

}
template <typename T>
aghVector<T>::aghVector(aghContainer<T> &arg_obj)
{


    aghContainer<T> *base_ptr = &arg_obj;

    aghVector<T> *derived_ptr = dynamic_cast< aghVector<T> *>(base_ptr);

    this->allocate_memory(derived_ptr->total_length);
    this->total_length = derived_ptr->total_length;
    this->last_item = derived_ptr->last_item;

    for(int i = 0; i <= derived_ptr->last_item; i++)
    {
        this->tab_ptr[i] = derived_ptr->tab_ptr[i];
    }
}
template <typename T>
aghVector<T>::~aghVector()
{
    this->free_memory();
}
    /////////////////////
    //METODY POMOCNICZE//
    /////////////////////

template <typename T>
void aghVector<T>::allocate_memory(int new_size)
{
    this->tab_ptr = new T [new_size +1];
}
template <typename T>
void aghVector<T>::free_memory(void)
{
    delete []tab_ptr;
    tab_ptr = NULL;
    this->total_length = 0;
    this->last_item = 0;
}

    ///////////////////////////////
    //DEFINICJE METOD WIRTUALNYCH//
    ///////////////////////////////

template <typename T>
bool aghVector<T>::is_free_space(void)
{
    if(last_item < total_length)
    {
        return true;

    }else
    {
        return false;
    }
}
template <typename T>
void aghVector<T>::broaden_container_memory(void)
{
    int new_size = (int)(this->total_length * 1.5);

    T *bufor = new T [new_size + 1];

    int last_prev_element = this->last_item;

    for(int i = 0;i <= last_prev_element; i++)
    {
        bufor[i] = this->tab_ptr[i];
    }
    this->free_memory();
    this->allocate_memory(new_size);

    this->tab_ptr = bufor;

    this->total_length = new_size;
    this->last_item = last_prev_element;
}
template <typename T>
bool aghVector<T>::insert(int position, T const& item)
{
    if(position <= total_length)
    {
        this->tab_ptr[position] = item;
        return true;

    }else
    {
        return false;
    }
}
template <typename T>
T& aghVector<T>::at(int position) const throw(aghException)
{
    if(position > last_item)
    {
        throw aghException(0, "Index out of range", __FILE__, __LINE__);

    }else
    {
        return this->tab_ptr[position];
    }
}
template <typename T>
int aghVector<T>::size(void) const
{
    return this->last_item;
}
template <typename T>
bool aghVector<T>::remove(int position)
{
    if(position > last_item) return false;

    for(int i = position; i <= last_item - 1; i++)
    {
        this->tab_ptr[i] = this->tab_ptr[i+1];
    }
    this->last_item += -1;

    return true;
}
template <typename T>
void aghVector<T>::kill_them_all(void)
{
    this->free_memory();
}

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

template <typename T>
aghVector<T>& aghVector<T>::operator=(const aghVector<T> & aghVc)
{
    if(this == &aghVc) return *this;

    this->free_memory();

    this->allocate_memory(aghVc.total_length);

    this->total_length = aghVc.total_length;

    for(int i = 0; i <= last_item; i++)
    {
        this->tab_ptr[i] = aghVc.tab_ptr[i];
    }

    this->last_item = aghVc.last_item;

    return *this;
}



#endif // AGHVECTOR_H_INCLUDED
