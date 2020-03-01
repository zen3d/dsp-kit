#include <stdint.h>

// linear congruential generator
struct lcg {
    int32_t x; // state
    int32_t a; // multiplier
    int32_t c; // offset        
};

//--- lifecycle
extern struct lcg* lcg_new();
extern void lcg_delete(struct lcg* lcg);

//--- process

extern float lcg_get_float(struct lcg* lcg);
extern int lcg_get_int(struct lcg* lcg);

//--- setters

// set 
extern void lcg_seed(struct lcg* lcg, int32_t x);
extern void lcg_mul(struct lcg* lcg, int32_t a);
extern void lcg_add(struct lcg* lcg, int32_t c);
