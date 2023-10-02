#include <iostream>
#include "fuzzy.h"

Fuzzy_PI fuzzy(TRAPMF, MAX_MIN);

int main(void)
{
    float NB = -2, NM = -1.5, NS = -1, ZE = 0, PS = 1, PM = 1.5, PB = 2;

    float e_mf[5][4] = {
        {-2, -1, -0.5, -0.25},
        {-0.5, -0.25, -0.25, 0},
        {-0.25, 0, 0, 0.25},
        {0, 0.25, 0.25, 0.5},
        {0.25, 0.5, 1, 2}
    };
    float de_mf[5][4] = {
        {-2, -1, -0.75, -0.325},
        {-0.75, -0.325, -0.325, 0},
        {-0.325, 0, 0, 0.325},
        {0, 0.325, 0.325, 0.75},
        {0.325, 0.75, 1, 2}
    };
    float u_dkm[5][5] = {
        {NB, NB, NM, NS, ZE},
        {NB, NM, NS, ZE, PS},
        {NM, NS, ZE, PS, PM},
        {NS, ZE, PS, PM, PB},
        {ZE, PS, PM, PB, PB}        
    };
    
    fuzzy.set_membership_func(e_mf, de_mf);
    fuzzy.set_rule_matrix(u_dkm);

    fuzzy.update(-5, 9);

    std::cout << fuzzy.u_dk;
    return 0;
}