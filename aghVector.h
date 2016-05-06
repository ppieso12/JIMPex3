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

    aghVector(){};

    virtual ~aghVector(){};





    virtual bool insert(int, T const&);

    virtual T& at(int) const;

    virtual int size(void) const;

    virtual bool remove(int);



};


#endif // AGHVECTOR_H_INCLUDED
