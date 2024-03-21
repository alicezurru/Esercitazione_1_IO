#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

double maps(double x){
    double y;
    //cambio di variabile
    double a=1;
    double b=5;
    double c=-1;
    double d=2;
    y=(d-c)/(b-a)*x+(d-(d-c)/(b-a)*b);
    return y;
}

int main()
{
    std::ifstream ifstr;
    ifstr.open("data.csv"); //apro il file
    if (ifstr.fail()){
        std::cerr<<"file input not found"<<std::endl;
        return 1;
    }
    //leggo e scrivo:
    double val=0;
    double mean=0;
    double sum=0;
    int cont=1;

    std::ofstream ofstr;
    ofstr.open("result.csv");
    if (ofstr.fail()){
        std::cerr<<"file output error"<<std::endl;
        return 2;
    }

    // riga iniziale
    ofstr<<"# N Mean\n";

    //numeri
    while(ifstr>>val){
        val=maps(val);
        sum +=val;
        mean=sum/cont;
        ofstr<<cont++<<" "<<std::scientific <<std::setprecision(16)<<mean<< "\n";

    }

    ifstr.close();
    ofstr.close();

    return 0;
}
