#include <iostream>

#define N_e    5
#define N_de   5

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef enum {
    MAX_MIN,
    MAX_PROD,
} composition_t;

typedef enum {
    TRIMF, TRAPMF, GAUSSMF
} mf_t;

class Fuzzy_PI{
    public:
    float u_dk;
    private:
    mf_t mf_type;
    composition_t composition;
    float (*e_mf_params)[4], (*de_mf_params)[4];
    float Rule_matrix[N_e][N_de];
    
    public:
    Fuzzy_PI (mf_t _mf_type, composition_t _composition);
    void set_membership_func(float _e_mf[N_e][4], float _de_mf[N_de][4]);
    void set_rule_matrix(float u_dkm[N_e][N_de];
    void update(float error, float d_error);

    private:
    float trimf(float x, float a, float b, float c);
    float trapmf(float x, float a, float b, float c, float d);
    float gaussmf(float x, float mu, float sigma);
    float mf(mf_t mf_type, float x, float *params);
};
