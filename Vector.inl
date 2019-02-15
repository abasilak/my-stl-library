
template<typename T>
const int Vector<T>::DEFAULT_VECTOR_SIZE = 2;

template<typename T>
const int Vector<T>::MAX_VECTOR_SIZE = ULONG_MAX;

template<typename T>
Vector<T>::Vector(void)
{
    m_size     = 0;
    m_capacity = DEFAULT_VECTOR_SIZE;
    m_data     = new T[m_capacity];
}

template<typename T>
Vector<T>::Vector(size_t capacity)
{
    Reserve(capacity);
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v)
{
    m_size     = v.GetSize();
    m_capacity = v.GetCapacity();
    m_data     = new T[m_capacity];
    
    for(size_t i = 0; i < m_size; i++) {
        m_data[i] = v[i];
    }
}

template<typename T>
void
Vector<T>::Swap(Vector<T>& v)
{
    if(this == &v) { // self-assignment guard
        return;
    }

    if(m_size != v.GetSize()) {
        assert(0);
        return;
    }

    T      tmp_data;
    size_t i = 0;
    for (auto it = v.Begin(); it != v.End(); it++, i++) {
        tmp_data  = m_data[i];
        m_data[i] = *it;
        *it       = tmp_data;
    }
}

template<typename T>
Vector<T>&
Vector<T>::operator=(const Vector<T>& v)
{
    if(this == &v) { // self-assignment guard
        return *this;
    }

    this->Clear();

    m_size     = v.GetSize();
    m_capacity = v.GetCapacity();
    m_data     = new T[m_capacity];
    
    for(size_t i = 0; i < m_size; i++) {
        m_data[i] = v[i];
    }

    return *this;
}

template<typename T>
Vector<T>::~Vector(void)
{
    m_size     = 0;
    m_capacity = 0;
    safe_array_delete(m_data);
}

template<typename T>
bool
Vector<T>::Empty() const
{
    return m_size == 0;
}

template<typename T>
T
Vector<T>::Access(size_t index) const
{
    return (index < m_size) ? m_data[index] : -1;
}

template<typename T>
T
Vector<T>::Front(void) const
{
    return !Empty() ? m_data[0] : -1;
}

template<typename T>
T
Vector<T>::Back(void) const
{
    return !Empty() ? m_data[m_size-1] : -1;
}

template<typename T>
int
Vector<T>::Search(T value) const
{
    size_t i;
    for(i = 0; i < m_size; i++) {
        if(m_data[i] == value) {
            break;
        }
    }

    return i == m_size ? -1 : i;
}

template<typename T>
void
Vector<T>::Insert(T value, size_t index)
{
    if(index >= m_size+1) {
        assert(0);
        return;
    }

    if(m_size == m_capacity) {
        Resize(m_capacity*2);
    }

    for(size_t i = m_size; i > index; --i) {
        m_data[i] = m_data[i-1];
    }

    m_data[index] = value;
    m_size++;
}

template<typename T>
void
Vector<T>::Delete(size_t index)
{
    if(Empty()) {
        return;
    }

    if(index >= m_size) {
        assert(0);
        return;
    }

    for(size_t i = index; i < m_size; i++) {
        m_data[i] = m_data[i+1];
    }

    m_size--;
    if(m_size == m_capacity/4) {
        Resize(m_capacity/2);
    }
}

template<typename T>
void
Vector<T>::PushBack(T value)
{
    if(m_size == m_capacity) {
        Resize(m_capacity*2);
    }

    m_data[m_size] = value;
    m_size++;
}

template<typename T>
void
Vector<T>::PopBack(void)
{
    if(Empty()) {
        return;
    }

    m_size--;
    if(m_size == m_capacity/4) {
        Resize(m_capacity/2);
    }
}

template<typename T>
void
Vector<T>::Resize(size_t capacity)
{
    assert (capacity < MAX_VECTOR_SIZE);

    m_capacity  = capacity;
    T *data     = new T[m_capacity];
    
    for(size_t i = 0; i < m_size; i++) {
        data[i] = m_data[i];
    }

    safe_array_delete(m_data);
    m_data = data;
}

template<typename T>
void
Vector<T>::Reserve(size_t capacity)
{
    if(m_capacity) {
        safe_array_delete(m_data);
    }

    m_size     = 0;
    m_capacity = power_of_two(capacity) ? capacity : std::pow(DEFAULT_VECTOR_SIZE, (int)log2(capacity)+1);
   
    assert (m_capacity < MAX_VECTOR_SIZE);
    m_data     = new T[m_capacity];
}

template<typename T>
void
Vector<T>::Clear()
{
    while(!Empty()) {
        PopBack();
    }
}

template<typename T>
void
Vector<T>::Traverse() const
{
    std::cout << "Vector" << std::endl;
    
    // for(size_t i = 0; i < m_size; i++) {
    //     std::cout << i << ": " << m_data[i] << std::endl;
    // }

    size_t i = 0;
    for (auto it = Begin(); it != End(); it++, i++) 
        std::cout << i << ": " << *it << std::endl;
}