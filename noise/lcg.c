#include "lcg.h"

struct lcg* lcg_new() {
    struct lcg* lcg = (struct lcg*)malloc(sizeof(struct lcg));
    lcg->x = 1;
    lcg->a = 1597334677;
    lcg->c = 1289706101;					 
}

void lcg_delete(struct lcg* lcg) {
    free(lcg);
}

static void lcg_update(struct lcg* lcg) {
    lcg->x = lcg->x * lcg->a + lcg->c;
}

// process
float lcg_get_float(struct lcg* lcg) {
    lcg_update(lcg);
    return (float)lcg->x / (float)0x7fffffff;
}

int lcg_get_int(struct lcg* lcg) {
    lcg_update(lcg);
    return (int)lcg->x;
}


// setters
void lcg_seed(struct lcg* lcg, int32_t x) {
    lcg->x = x;
}

void lcg_mul(struct lcg* lcg, int32_t a) {
    lcg->a = a;
}

void lcg_add(struct lcg* lcg, int32_t c) {
    lcg->c = c;
}

