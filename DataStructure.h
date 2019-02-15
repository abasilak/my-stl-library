#ifndef __DATASTRUCTURE_H__
#define __DATASTRUCTURE_H__

#include "Utils.h"

template<typename T>
class DataStructure {

public:
    virtual ~DataStructure() { };
       
    virtual void    Traverse(void)                const = 0;
    virtual bool    Empty(void)                   const = 0;
    virtual T       Access(size_t index)          const = 0;
    virtual T       Front(void)                   const = 0;
    virtual T       Back(void)                    const = 0;
    virtual int     Search(T value)               const = 0;
    virtual void    Delete(size_t index)                = 0;
    virtual void    Insert(T value, size_t index)       = 0;
    virtual void    Clear(void)                         = 0;
};

#endif