//DATE: 11/28/14
//ASSIGNMENT: Project 7
//FILE: table2.cpp
//DESC: Implementation of table class

template <class RecordType> table<RecordType>::table( ) : total_records(0)
{
//Set all hdata elements to NULL
    for(unsigned i = 0; i < TABLE_SIZE; ++i)
        hdata[i] = 0;
}

template <class RecordType> table<RecordType>::table(const table& source) : total_records(source.total_records)
{
//Set all hdata elements to NULL
//Iterate through all table elements
    for(unsigned i = 0; i != TABLE_SIZE; ++i){
        hdata[i] = 0;

//Check if a given index has been used
        if(source.hdata[i]){

//Create head and tail pointers to copy source.hdata into hdata
            node<RecordType> *tail;
            list_copy(source.hdata[i], hdata[i], tail);
        }
    }
}

template <class RecordType> table<RecordType>::~table( )
{
//Iterate through all table elements
    for(unsigned i = 0; i != TABLE_SIZE; ++i){

//Check if a given index has been used
        if(hdata[i]){
            list_clear(hdata[i]);
        }
    }
}

template <class RecordType> std::size_t table<RecordType>::hash(long key) const
{
//Read key
    std::stringstream ss;
    ss << key;

//Get last four digits of key
    std::string sloc_num;
    ss >> sloc_num;
    sloc_num = sloc_num.substr(sloc_num.length() - 4, 3);
    int iloc_num = atoi(sloc_num.c_str());

//hash(key) returns digits 7 through 9, e.g 123-456-7891 => 789 is the index
    return iloc_num;
}

// MODIFICATION MEMBER FUNCTIONS //
template <class RecordType> void table<RecordType>::insert(const RecordType& entry)
{
//Get array index
    size_t index = hash(entry.phone);

//Check if list is empty
    if(hdata[index]){

//Get position of last node in list
        size_t pos = list_length(hdata[index]);

//Get pointer to last node
        node<RecordType> *prev = list_locate(hdata[index], pos);

//Insert entry onto end of list
        list_insert(prev, entry);
    }
    else{

//Insert entry onto beginning of list
        list_head_insert(hdata[index], entry);
    }
//Update total_records
    ++total_records;
}

template <class RecordType> void table<RecordType>::remove(long key)
{
//Call hash to find index
    size_t index = hash(key);

//Check if list is empty
    if(hdata[index]){

//Check if first node is the one to remove
        if(hdata[index]->data().phone == key){
            list_head_remove(hdata[index]);

//Update total records and pointer value
            --total_records;
            if(!list_length(hdata[index]))
                hdata[index] = 0;
        }
        else{
//Variable to hold element preceeding element to remove
            node<RecordType> *prev = hdata[index];

//Iterate through list to find element to remove
            while(prev->link() && ((prev->link())->data()).phone != key){
                prev = prev->link();
            }
//If prev isn't the last node remove element
            if(prev->link())
                list_remove(prev);
//Update total records
            --total_records;
        }
    }
}

template <class RecordType> void table<RecordType>::operator=(const table& source)
{
//Check for self assignment
    if(this == &source)
        return;

//Check if table is empty
    if(total_records){

//Delete data in this table
//Iterate through all table elements
        for(unsigned i = 0; i != TABLE_SIZE; ++i){

//Check if a given index has been used
            if(hdata[i]){
                list_clear(hdata[i]);
            }
        }
    }
//Memeberwise copy argument data
    total_records = source.total_records;

//Deep copy source.hdata
//Iterate through all table elements
    for(unsigned i = 0; i != TABLE_SIZE; ++i){

//Check if a given index has been used
        if(source.hdata[i]){

//Create tail pointer to copy source.hdata into hdata
            node<RecordType> *tail;
            list_copy(source.hdata[i], hdata[i], tail);
        }
    }
}

// CONSTANT MEMBER FUNCTIONS
template <class RecordType> void table<RecordType>::find(long key, bool& found, RecordType& result) const
{
//Set found to false
    found = false;

//Call hash to find index
    size_t index = hash(key);

//Check if list is empty
    if(hdata[index]){
//Variable to hold element sought
        node<RecordType> *sought = hdata[index];

//Iterate through list to find element sought
        while(sought){
            if(sought->data().phone == key){
                found = true;
                result = sought->data();
                return;
            }
            sought = sought->link();
        }
    }
}

template <class RecordType> bool table<RecordType>::is_present(long key) const
{
//Call hash to find index
    size_t index = hash(key);

//Check if list is empty
    if(hdata[index]){

//Variable to hold element to find
        node<RecordType> *sought = hdata[index];

//Check if sought is in first node
        if(sought->data().phone == key)
            return true;
        else{

//Iterate through list to find element
            while(sought->link()){
                if(sought->data().phone == key)
                       return true;
                sought = sought->link();
                }
        return false;
        }
    }
    else
        return false;
}

template <class RecordType> std::ostream& operator<<(std::ostream &out, const table<RecordType> &obj)
{
//Check if table is empty
    if(obj.size()){

//Iterate through all table elements
        for(unsigned i = 0; i != TABLE_SIZE; ++i){

//Check if a given index has been used
            if(obj.hdata[i]){
                node<RecordType> *node_ptr = obj.hdata[i];

//Continue while the last node hasn't been reached
                while(node_ptr->link()){
                    std::cout << node_ptr->data() << std::endl;
                    node_ptr = node_ptr->link();
                }
//Print last node
                std::cout << node_ptr->data() << std::endl;
                    node_ptr = node_ptr->link();
            }
        }
    }
    return out;
}
