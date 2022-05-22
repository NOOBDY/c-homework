#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SINGLE_INPUT_GATE_VALUE(TYPE) TYPE(*gate_value)(TYPE)
#define DOUBLE_INPUT_GATE_VALUE(TYPE) TYPE(*gate_value)(TYPE, TYPE)

typedef struct _SingleInputGate {
    SINGLE_INPUT_GATE_VALUE(int);
    void (*delete)(struct _SingleInputGate *);
} SingleInputGate;

typedef struct _DoubleInputGate {
    DOUBLE_INPUT_GATE_VALUE(int);
    void (*delete)(struct _DoubleInputGate *);
} DoubleInputGate;


typedef struct _GateNOT {
    SINGLE_INPUT_GATE_VALUE(int);
    void (*delete)(struct _GateNOT *);
} GateNOT;

typedef struct _GateEMPTY {
    SINGLE_INPUT_GATE_VALUE(int);
    void (*delete)(struct _GateEMPTY *);
} GateEMPTY;


typedef struct _GateAND {
    DOUBLE_INPUT_GATE_VALUE(int);
    void (*delete)(struct _GateAND *);
} GateAND;

typedef struct _GateOR{
    DOUBLE_INPUT_GATE_VALUE(int);
    void (*delete)(struct _GateOR *);
} GateOR;

typedef struct _GateXOR {
    DOUBLE_INPUT_GATE_VALUE(int);
    void (*delete)(struct _GateXOR *);
} GateXOR;


int gate_NOT_value(int a) {
    return !a;
}

void gate_NOT_delete(GateNOT *g) {
    free(g);
}

SingleInputGate *gate_NOT_new() {
    GateNOT *g = malloc(sizeof(GateNOT));
    g->gate_value = gate_NOT_value;
    g->delete = gate_NOT_delete;
    return (SingleInputGate *)g;
}

int gate_EMPTY_value(int a) {
    return a;
}

void gate_EMPTY_delete(GateEMPTY *g) {
    free(g);
}

SingleInputGate *gate_EMPTY_new() {
    GateEMPTY *g = malloc(sizeof(GateEMPTY));
    g->gate_value = gate_EMPTY_value;
    g->delete = gate_EMPTY_delete;
    return (SingleInputGate *)g;
}


int gate_AND_value(int a, int b) {
    return a & b;
}

void gate_AND_delete(GateAND *g) {
    free(g);
}

DoubleInputGate *gate_AND_new() {
    GateAND *g = malloc(sizeof(GateAND));
    g->gate_value = gate_AND_value;
    g->delete = gate_AND_delete;
    return (DoubleInputGate *)g;
}

int gate_OR_value(int a, int b) {
    return a | b;
}

void gate_OR_delete(GateOR *g) {
    free(g);
}

DoubleInputGate *gate_OR_new() {
    GateOR *g = malloc(sizeof(GateOR));
    g->gate_value = gate_OR_value;
    g->delete = gate_OR_delete;
    return (DoubleInputGate *)g;
}

int gate_XOR_value(int a, int b) {
    return a ^ b;
}

void gate_XOR_delete(GateXOR *g) {
    free(g);
}

DoubleInputGate *gate_XOR_new() {
    GateXOR *g = malloc(sizeof(GateXOR));
    g->gate_value = gate_XOR_value;
    g->delete = gate_XOR_delete;
    return (DoubleInputGate *)g;
}

int main() {
    int i, m1, m2, m3, o1, o2, o3, input[4];
    char g;
    void *gates[6];

    for (i = 0; i < 4; i++) {
        scanf("%d", &input[i]);
        getchar();
    }

    for (i = 0; i < 6; i++) {
        g = getchar();
        getchar();

        switch (g) {
            case 'N':
                gates[i] = gate_NOT_new();
                break;

            case 'E':
                gates[i] = gate_EMPTY_new();
                break;

            case 'A':
                gates[i] = gate_AND_new();
                break;

            case 'O':
                gates[i] = gate_OR_new();
                break;

            case 'X':
                gates[i] = gate_XOR_new();
                break;
        }
    }

    m1 = ((DoubleInputGate *)gates[0])->gate_value(input[0], input[1]);
    o1 = ((SingleInputGate *)gates[1])->gate_value(m1);

    m2 = ((DoubleInputGate *)gates[2])->gate_value(m1, input[2]);
    o2 = ((DoubleInputGate *)gates[3])->gate_value(o1, m2);

    m3 = ((DoubleInputGate *)gates[4])->gate_value(m2, input[3]);
    o3 = ((DoubleInputGate *)gates[5])->gate_value(o2, m3);

    ((DoubleInputGate *)gates[0])->delete(gates[0]);
    ((SingleInputGate *)gates[1])->delete(gates[1]);
    ((DoubleInputGate *)gates[2])->delete(gates[2]);
    ((DoubleInputGate *)gates[3])->delete(gates[3]);
    ((DoubleInputGate *)gates[4])->delete(gates[4]);
    ((DoubleInputGate *)gates[5])->delete(gates[5]);

    printf("%d,%d,%d\n", o1, o2, o3);

    return 0;
}
