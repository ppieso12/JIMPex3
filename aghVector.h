#ifndef AGHVECTOR_H_INCLUDED
#define AGHVECTOR_H_INCLUDED
#include "aghContainer.h"
#include "aghException.h"

template <typename T>
class aghVector: public aghContainer<T>
{
private:

    T **tab_ptr;         ///< wskaznik do wskaznikow dla elementow typu T
    int total_length;   ///< calkowity rozmiar zaalokowanej pamieci
    int last_item;      ///< index ostatniego poprawnego elementu
    int Size;           ///< ilosc elementow w vectorze


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

    /// \brief Metoda sprawdzajaca czy w okreslonym kontenerze znajduje sie wolny obszar w zaalokowanej pamieci
    /// <done>
    bool is_free_space(void);

    /// \brief Metoda rozszerzajaca rozmiar kontenera o 50% (rozmiar rzutowany do int)
    /// <done>
    void broaden_container_memory(void);
    void broaden_container_memory(int new_size);

    /// \brief Metoda rozszerzajaca rozmiar kontenera o 50% (rozmiar rzutowany do int)
    /// <done>
    int last_elem_pos(void);

    //////////////////////////////////
    //METODY WIRTUALNE DLA AGHVECTOR//
    //////////////////////////////////

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

    /// \brief Metoda Zwracajaca index ostatniego elementu
    /// <done>
    virtual int last_index(void) const;

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
    this->Size = 0;
    this->total_length = 5;
    this->last_item = -1;
}
template <typename T>
aghVector<T>::aghVector(int init_length)
{
    this->allocate_memory(init_length);
    this->Size = 0;
    this->total_length = init_length;
    this->last_item = -1;

}
template <typename T>
aghVector<T>::aghVector(aghContainer<T> &arg_obj)
{
    aghContainer<T> *base_ptr = &arg_obj;

    aghVector<T> *derived_ptr = dynamic_cast< aghVector<T> *>(base_ptr);

    this->allocate_memory(derived_ptr->total_length);
    this->Size = derived_ptr->Size;
    this->total_length = derived_ptr->total_length;
    this->last_item = derived_ptr->last_item;

    for(int i = 0; i <= derived_ptr->last_item; i++)
    {
        T *item = new T;
        *item = *(derived_ptr->tab_ptr[i]);
        this->tab_ptr[i] = item;
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
    this->tab_ptr = new T *[new_size +1];
    for(int i = 0; i <= new_size; i++)
    {
        this->tab_ptr[i] = NULL;
    }
}
template <typename T>
void aghVector<T>::free_memory(void)
{
    for(int i = 0; i <= this->last_item; i++)
    {
        if(this->tab_ptr[i] != NULL) delete[] tab_ptr[i];
    }
    delete []tab_ptr;
    tab_ptr = NULL;
    this->total_length = 0;
    this->Size = 0;
    this->last_item = -1;
    cout << "Usuniety" << endl;
}
template <typename T>
int aghVector<T>::last_elem_pos(void)
{
    int index;
    for(int i = 0; i <= this->total_length; i++)
    {
        if(this->tab_ptr[i] != NULL)
        {
            index = i;
        }
    }
    return index;
}



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
    //cout<< "test!!!default"<< endl;
    int new_size = (int)(this->total_length * 1.5);

    T **bufor = new T * [new_size + 1];

    int last_prev_element = this->last_item;
    int prev_Size = this->Size;

    for(int i = 0;i <= last_prev_element; i++)
    {
        T *item = new T;
        *item = *(this->tab_ptr[i]);
        bufor[i] = item;
    }
    for(int i = last_prev_element + 1;i <= new_size; i++)
    {
        bufor[i] = NULL;
    }
    this->free_memory();
    this->allocate_memory(new_size);

    this->tab_ptr = bufor;

    this->total_length = new_size;
    this->Size = prev_Size;
    this->last_item = last_prev_element;
}
template <typename T>
void aghVector<T>::broaden_container_memory(int new_size)
{
    //cout<< "test!!!param"<< endl;
    T **bufor = new T * [new_size + 1];

    int last_prev_element = this->last_item;
    int prev_Size = this->Size;

    for(int i = 0;i <= last_prev_element; i++)
    {
        T *item = new T;
        *item = *(this->tab_ptr[i]);
        bufor[i] = item;
    }
    for(int i = last_prev_element + 1;i <= new_size; i++)
    {
        bufor[i] = NULL;
    }
    this->free_memory();
    this->allocate_memory(new_size);

    this->tab_ptr = bufor;

    this->total_length = new_size;
    this->Size = prev_Size;
    this->last_item = last_prev_element;
}

    ///////////////////////////////
    //DEFINICJE METOD WIRTUALNYCH//
    ///////////////////////////////

template <typename T>
bool aghVector<T>::insert(int position, T const& item)
{
    if(this->total_length < position) this->broaden_container_memory();  //Czy zaalokowano miejsce na wskazniki

        if(this->tab_ptr[position] == NULL)  //puste miejsce
        {
            T *itemptr = new T;
            *itemptr = item;
            this->tab_ptr[position] = itemptr;
            this->last_item = this->last_elem_pos();
            this->Size++;
        }else
        {
            if(this->last_item + 1 > total_length) this->broaden_container_memory();

            for(int i = this->last_item; i>= position; i--)
            {

                this->tab_ptr[i + 1] = this->tab_ptr[i];
            }

            T *itemptr = new T;
            *itemptr = item;
            this->tab_ptr[position] = itemptr;
            this->last_item++;
            this->Size++;
        }
}
template <typename T>
T& aghVector<T>::at(int position) const throw(aghException)
{
    if(position > last_item)
    {
        throw aghException(0, "Index refers to undefined element", __FILE__, __LINE__);

    }else
    {
        return *(this->tab_ptr[position]);
    }
}
template <typename T>
int aghVector<T>::size(void) const
{
    return this->Size;
}
template <typename T>
bool aghVector<T>::remove(int position)
{/*
    if(position > last_item) return false;

    for(int i = position; i <= last_item - 1; i++)
    {
        this->tab_ptr[i] = this->tab_ptr[i+1];
    }
    //DOPRACOWAC
    this->last_item--;
    this->Size--;

    return true;*/
}
template <typename T>
void aghVector<T>::kill_them_all(void)
{
    this->free_memory();
}
template <typename T>
int aghVector<T>::last_index(void) const
{
    return this->last_item;
}

    //////////////////////////
    //PRZELADOWANE OPERATORY//
    //////////////////////////

template <typename T>
aghVector<T>& aghVector<T>::operator=(const aghVector<T> & aghVc)
{/*
    if(this == &aghVc) return *this;

    this->free_memory();

    this->allocate_memory(aghVc.total_length);

    this->total_length = aghVc.total_length;
    this->Size = aghVc.Size;

    for(int i = 0; i <= last_item; i++)
    {
        this->tab_ptr[i] = aghVc.tab_ptr[i];
    }

    this->last_item = aghVc.last_item;

    return *this;*/
}



#endif // AGHVECTOR_H_INCLUDED
