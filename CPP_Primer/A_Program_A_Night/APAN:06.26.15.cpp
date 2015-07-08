// DATE : 06/26/15
// FILE : APAN:06.26.15
// DESC : Use dynamic memory with smart pointers
//  1) Shared pointer part II

#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main()
{
// Create shared pointers
    int *ip = new int(7);
    std::shared_ptr<std::string> ssp0;
    std::shared_ptr<int> isp0 = std::make_shared<int>(77), isp1(isp0);
    std::shared_ptr<std::string> ssp1(new std::string("new string"));
    std::shared_ptr<int> isp2(ip);
    double *dp = new double(5.54);
    std::default_delete<double> dd;
    std::unique_ptr<double> dup(dp);
    //std::shared_ptr<double> cdup(dup);
    std::default_delete<float> d;
    float *fp0 = new float(3.4);
    float *fp1 = new float(3.4);
    std::default_delete<float> d1;
    std::shared_ptr<float> fsp0(fp0, d);
    std::shared_ptr<float> fsp1(fp1);
    //std::shared_ptr<float> fsp2(fsp1, d1);

// Additional hared pointer operations
    isp0.reset();
    std::string *sp = new std::string("string pointer");
    ssp1.reset(sp);
    int * ip1 = new int(5);
    std::default_delete<int> id1;
    isp2.reset(ip1, id1);

    return 0;
}
