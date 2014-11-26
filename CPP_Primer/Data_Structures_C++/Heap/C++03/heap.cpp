//DATE: 11/23/14
//ASSIGNMENT: Project 6
//FILE: heap.cpp
//DESC: Implementation of heap class

template<class T> Heap<T>::Heap(int max)
{
  maxItems = max;
  items = new T[max];
  length = 0;
}

template<class T> Heap<T>::~Heap()
{
  delete [] items;
}

template<class T> Heap<T>::Heap(const Heap<T> &obj)
{
    maxItems = obj.maxItems;
    length = obj.length;
    items = new T[maxItems];

    for(size_t i = 0; i != length; ++i)
        items[i] = obj.items[i];
}

template<class T> Heap<T>& Heap<T>::operator=(Heap<T> obj)
{
    swap(*this, obj);
    return *this;
}

template<class T> void Heap<T>::remove(T &item)
{
    if(IsEmpty())
        throw emptypq("There are no elements in the heap.");

//Swap all elements starting from root to last element
//Loop through array
    for(unsigned i = 0; i < length - 1; ++i){
        std::swap(items[i], items[i + 1]);
    }
    T tmp;

//Set removed element to default initialized object
    item = items[length - 1];
    items[length - 1] = tmp;

//Reduce length by 1
    --length;
}

//Template specialization for Patient object
template<class T> void Heap<T>::add(T newItem)
{
//Check if there is space for the new item
    if(IsFull())
        throw fullpq("The heap is full.");

//Add the new item to first unused positon in the heap
    items[length] = newItem;
    ++length;

    if(length > 1){
//Move item to proper position to maintain heap structure
    for(unsigned i = length - 1; i > 0 && (items[i - 1] < newItem); --i)
        std::swap(items[i - 1], items[i]);
    }
}

template<> void Heap<Patient>::add(Patient newItem)
{
//Check if there is space for the new item
    if(IsFull())
        throw fullpq("The heap is full.");

//Add the new item to first unused positon in the heap
    items[length] = newItem;
    ++length;

    if(length > 1){
//Move item to proper position to maintain heap structure
    for(unsigned i = length - 1; i > 0 && (items[i - 1] < newItem); --i)
        std::swap(items[i - 1], items[i]);
    }
}

template<class T> bool Heap<T>::IsFull() const
{
    return length == maxItems;
}

template<class T> bool Heap<T>::IsEmpty() const
{
    return length == 0;
}

template <class T> void swap(Heap<T> &heap1, Heap<T> &heap2)
{
    using std::swap;
    swap(heap1.items, heap2.items);
    swap(heap1.length, heap2.length);
    swap(heap1.maxItems, heap2.maxItems);
/*
    int itmp(0);
    T *ptmp(0);

//Swap pointers to dynamic arrays
    ptmp = heap1.items;
    heap1.items = heap2.items;
    heap2.items = ptmp;

//Swap lengths
    itmp = heap1.length;
    heap1.length = heap2.length;
    heap2.length = itmp;

//Swap maxItems
    itmp = heap1.maxItems;
    heap1.maxItems = heap2.maxItems;
    heap2.maxItems = itmp;
    */
}

template <class T> std::ostream& operator<<(std::ostream &out, const Heap<T> &obj)
{
    T *pos = obj.items;
    out << obj.maxItems << " " << obj.length << std::endl;
    while((pos)++ < (obj.items + obj.length)){
       out << *pos << " " << std::endl;
    }
    return out;
}

template <> std::ostream& operator<<(std::ostream &out, const Heap<Patient> &obj)
{
    Patient *pos = obj.items;
    out << obj.maxItems << " " << obj.length << std::endl;
    for(unsigned i = 0; i < obj.length; ++i){
            out << obj.items[i].get_name() << " " << obj.items[i].get_malady() << " " << obj.items[i].get_priority() << std::endl;
    }
    return out;
}
