#ifndef AGHCONTAINER_H_INCLUDED
#define AGHCONTAINER_H_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
class aghContainer
{
private:

public:

    /// \brief
    ///
    /// \param
    /// \return
    void append(T const&);

    bool insert(int, T const&);

    bool replace(int, T const&);

    T& at(int) const;

    int size(void) const;

    bool remove(int);





#endif // AGHCONTAINER_H_INCLUDED


