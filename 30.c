#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

typedef struct shape_s {
    double (*perim)(const struct shape_s);
    double (*area)(const struct shape_s);
    void (*delete)(struct shape_s *);
} shape_t;


typedef struct circle_s {
    double (*perim)(const struct circle_s);
    double (*area)(const struct circle_s);
    double radius;
    void (*delete)(struct circle_s *);
} circle_t;

typedef struct rect_s {
    double (*perim)(const struct rect_s);
    double (*area)(const struct rect_s);
    double height, width;
    void (*delete)(struct rect_s *);
} rect_t;

typedef struct square_s {
    double (*perim)(const struct square_s);
    double (*area)(const struct square_s);
    double edge;
    void (*delete)(struct square_s *);
} square_t;

typedef struct tri_s {
    double (*perim)(const struct tri_s);
    double (*area)(const struct tri_s);
    double edges[3];
    void (*delete)(struct tri_s *);
} tri_t;


double circle_perim(const circle_t c) {
    return 2.0 * PI * c.radius;
}

double circle_area(const circle_t c) {
    return PI * c.radius * c.radius;
}

void circle_delete(circle_t *c) {
    free(c);
}

shape_t *circle_new() {
    circle_t *c = malloc(sizeof(circle_t));

    scanf("%lf", &c->radius);

    c->perim = circle_perim;
    c->area = circle_area;
    c->delete = circle_delete;

    return (shape_t *)c;
}

double rect_perim(const rect_t r) {
    return 2 * (r.height + r.width);
}

double rect_area(const rect_t r) {
    return r.height * r.width;
}

void rect_delete(rect_t *r) {
    free(r);
}

shape_t *rect_new() {
    rect_t *r = malloc(sizeof(rect_t));

    scanf("%lf", &r->height);
    scanf("%lf", &r->width);

    r->perim = rect_perim;
    r->area = rect_area;
    r->delete = rect_delete;

    return (shape_t *)r;
}

double square_perim(const square_t s) {
    return 4 * s.edge;
}

double square_area(const square_t s) {
    return s.edge * s.edge;
}

void square_delete(square_t *s) {
    free(s);
}

shape_t *square_new() {
    square_t *s = malloc(sizeof(square_t));

    scanf("%lf", &s->edge);

    s->perim = square_perim;
    s->area = square_area;
    s->delete = square_delete;

    return (shape_t *)s;
}

double tri_perim(const tri_t t) {
    return t.edges[0] + t.edges[1] + t.edges[2];
}

double tri_area(const tri_t t) {
    double s = tri_perim(t) / 2;
    return sqrt(s * (s - t.edges[0]) * (s - t.edges[1]) * (s - t.edges[2]));
}

void tri_delete(tri_t *t) {
    free(t);
}

shape_t *tri_new() {
    tri_t *t = malloc(sizeof(tri_t));

    scanf("%lf", &t->edges[0]);
    scanf("%lf", &t->edges[1]);
    scanf("%lf", &t->edges[2]);

    t->perim = tri_perim;
    t->area = tri_area;
    t->delete = tri_delete;

    return (shape_t *)t;
}

int main() {
    int i, count;
    char type;
    double perim, area;
    double perim_sum = 0, area_sum = 0;
    shape_t *shape;

    scanf("%d", &count);
    getchar();

    for (i = 0; i < count; i++) {
        type = getchar();
        getchar();

        switch (type) {
            case 'C':
                shape = circle_new();
                perim = ((circle_t *)shape)->perim(*(circle_t *)shape);
                area = ((circle_t *)shape)->area(*(circle_t *)shape);
                ((circle_t *)shape)->delete((circle_t *)shape);
                break;

            case 'R':
                shape = rect_new();
                perim = ((rect_t *)shape)->perim(*(rect_t *)shape);
                area = ((rect_t *)shape)->area(*(rect_t *)shape);
                ((rect_t *)shape)->delete((rect_t *)shape);
                break;

            case 'S':
                shape = square_new();
                perim = ((square_t *)shape)->perim(*(square_t *)shape);
                area = ((square_t *)shape)->area(*(square_t *)shape);
                ((square_t *)shape)->delete((square_t *)shape);
                break;

            case 'T':
                shape = tri_new();
                perim = ((tri_t *)shape)->perim(*(tri_t *)shape);
                area = ((tri_t *)shape)->area(*(tri_t *)shape);
                ((tri_t *)shape)->delete((tri_t *)shape);
                break;
        }

        printf("%.2lf %.2lf\n", perim, area);

        perim_sum += perim;
        area_sum += area;

        getchar();
    }

    printf("%.2lf %.2lf\n", perim_sum, area_sum);

    return 0;
}
