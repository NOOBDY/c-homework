#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TransportationText(TYPE) char name[20]; \
double speed;                                   \
double distance;                                \
int (*price)(struct TYPE*);                     \
double (*time)(struct TYPE*)

typedef struct {
    char *name;
    int price;
    double time;
} base_t;

typedef struct car_s {
    int oilPrice;
    int parkPrice;
    int tolls;
    TransportationText(car_s);
} car_t;

typedef struct bicycle_s {
    int rent;
    TransportationText(bicycle_s);
} bicycle_t;

typedef struct bus_s {
    int base;
    int extra;
    TransportationText(bus_s);
} bus_t;

typedef struct scooter_s {
    int oilPrice;
    TransportationText(scooter_s);
} scooter_t;

int CarPrice(car_t* obj){
    return (obj->oilPrice * 10 + obj->tolls) * (int)((obj->distance + 50) / 100) + obj->parkPrice;
}

double CarTime(car_t* obj){
    return obj->distance / obj->speed;
}

void CarCreate(car_t *obj) {
    strcpy(obj->name, "Car");
    obj->speed = 100;
    obj->price = CarPrice;
    obj->time = CarTime;
}

int BicyclePrice(bicycle_t *obj) {
    return obj->rent;
}

double BicycleTime(bicycle_t *obj) {
    return obj->distance / obj->speed;
}

void BicycleCreate(bicycle_t *obj) {
    strcpy(obj->name, "Bike");
    obj->speed = 20;
    obj->price = BicyclePrice;
    obj->time = BicycleTime;
}

int BusPrice(bus_t *obj) {
    return obj->base + obj->extra * (int)(obj->distance > 100 ? (obj->distance - 100 + 49) / 50 : 0);
}

double BusTime(bus_t *obj) {
    return obj->distance / obj->speed;
}

void BusCreate(bus_t *obj) {
    strcpy(obj->name, "Intercity Bus");
    obj->speed = 75;
    obj->price = BusPrice;
    obj->time = BusTime;
}

int ScooterPrice(scooter_t *obj) {
    return (obj->oilPrice * 4) * (int)((obj->distance + 50) / 100);
}

double ScooterTime(scooter_t *obj) {
    return obj->distance / obj->speed;
}

void ScooterCreate(scooter_t *obj) {
    strcpy(obj->name, "Scooter");
    obj->speed = 50;
    obj->price = ScooterPrice;
    obj->time = ScooterTime;
}

int cmp(const void *a, const void *b) {
    if (((base_t *)a)->time > ((base_t *)b)->time)
        return 1;

    if (((base_t *)a)->time < ((base_t *)b)->time)
        return -1;

    return 0;
}

int main() {
    int i, distance, budget;
    base_t base[4];
    car_t car;
    bicycle_t bicycle;
    bus_t bus;
    scooter_t scooter;

    scanf("%d", &distance);
    scanf("%d", &budget);
    getchar();

    CarCreate(&car);
    car.distance = distance;
    scanf("%d", &car.oilPrice);
    scanf("%d", &car.parkPrice);
    scanf("%d", &car.tolls);
    getchar();

    BicycleCreate(&bicycle);
    bicycle.distance = distance;
    scanf("%d", &bicycle.rent);
    getchar();

    BusCreate(&bus);
    bus.distance = distance;
    scanf("%d", &bus.base);
    scanf("%d", &bus.extra);
    getchar();

    ScooterCreate(&scooter);
    scooter.distance = distance;
    scanf("%d", &scooter.oilPrice);
    getchar();

    base[0].name = car.name;
    base[0].price = car.price(&car);
    base[0].time = car.time(&car);

    base[1].name = bicycle.name;
    base[1].price = bicycle.price(&bicycle);
    base[1].time = bicycle.time(&bicycle);

    base[2].name = bus.name;
    base[2].price = bus.price(&bus);
    base[2].time = bus.time(&bus);

    base[3].name = scooter.name;
    base[3].price = scooter.price(&scooter);
    base[3].time = scooter.time(&scooter);

    qsort(base, 4, sizeof(base_t), cmp);

    for (i = 0; i < 4; i++) {
        if (base[i].price <= budget) {
            printf("%s\n", base[i].name);
            printf("%d\n", base[i].price);
            printf("%.2lf\n", base[i].time);
            return 0;
        }
    }

    printf("No Transportation\n");
    return 0;
}
