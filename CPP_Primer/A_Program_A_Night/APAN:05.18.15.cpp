// DATE : 05/18/15
// FILE : APAN:05.18.15.cpp
// DESC : Use enumerations to simplfy definition for a group of related integral constants

#include <iostream>

// scoped enumerations
enum class bur : unsigned {Manhattan, Brooklyn, Staten_Island, Bronx, Queens};
enum struct city {Long_Beach, Albany, Tarrytown};

// unscoped enumeration
enum state : unsigned short {New_York, New_Jersey, Connecticut} region = New_York;

// forward declarations
int print(state);
city print(city);
bur print(bur);

int main()
{
    bur sub_region1 = bur::Manhattan;
    bur sub_region2;
    sub_region2 = bur::Staten_Island;

    city city1 = city::Long_Beach;
    city city2(city1);

// use constant expression enumerators in switch
    constexpr state arr[]{New_York, New_Jersey, Connecticut};
    state val;
    for(std::size_t i = 0; i < sizeof(arr)/sizeof(*arr); ++i){
        val = arr[i];
        switch(val){
            case Connecticut:
            {
                std::cout << print(Connecticut) << std::endl;
                break;
            }
            case New_Jersey:
            {
                std::cout << print(New_Jersey) << std::endl;
                break;
            }
            case New_York:
            {
                std::cout << print(New_York) << std::endl;
                break;
            }
            default:
            {
                std::cout << "Not a region in tri-state area." << std::endl;
                break;
            }
        }
    }
    return 0;
}

// Functions with enumerator parameter
int print(state region) { return region; }
city print(city region) { return region; }
bur print(bur region) { return region; }
