#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "DataStructure.h"

template<typename T>
class Vector : public DataStructure<T> {

private:
   
    T              *m_data;
    size_t          m_size;
    size_t          m_capacity;

    void            Resize(size_t capacity);

public:

    Vector();
    Vector(size_t capacity);
    Vector(const Vector& v);
    ~Vector();

    static const int    DEFAULT_VECTOR_SIZE;
    static const int    MAX_VECTOR_SIZE;

    typedef T          *iterator;
    typedef const T    *const_iterator;

    virtual void        Traverse(void)                      const override;
    virtual bool        Empty(void)                         const override;
    virtual T           Access(size_t index)                const override;
    virtual T           Front(void)                         const override;
    virtual T           Back(void)                          const override;
    virtual int         Search(T value)                     const override;
    virtual void        Insert(T value, size_t index)             override;
    virtual void        Delete(size_t index)                      override;
    virtual void        Clear(void)                               override;
            void        Reserve(size_t capacity);
            void        PushBack(T value);
            void        PopBack(void);
            void        Swap(Vector& v);

            Vector&     operator=(const Vector& v);
    inline  T           operator[](int i)   const                    { return m_data[i];       }

    inline  iterator    Begin(void)         const                    { return m_data;          }
    inline  iterator    End(void)           const                    { return m_data + m_size; }

    inline  size_t      GetSize(void)       const                    { return m_size;          }
    inline  T*          GetData(void)       const                    { return m_data;          }
    inline  size_t      GetMaxSize(void)    const                    { return MAX_VECTOR_SIZE; }
    inline  size_t      GetCapacity(void)   const                    { return m_capacity;      }
};

#include "Vector.inl"

#endif