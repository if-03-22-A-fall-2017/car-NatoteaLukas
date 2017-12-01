#include <stdio.h>
#include <stdlib.h>
#include "car.h"

struct  CarType {
  enum type type;
  enum color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool is_rented;
};

void print_cars();
void race();

static struct CarType AX = {AIXAM, RED, 16, 0.0, 0, false};
static struct CarType F1 = {FIAT_MULTIPLA, GREEN, 65, 0.0, 0, false};
static struct CarType F2 = {FIAT_MULTIPLA, BLUE, 65, 0.0, 0, false};
static struct CarType F3 = {FIAT_MULTIPLA, ORANGE, 65, 0.0, 0, false};
static struct CarType J1 = {JEEP, SILVER, 80, 0.0, 0, false};
static struct CarType J2 = {JEEP, BLACK, 80, 0.0, 0, false};

int main(int argc, char const *argv[]) {
  printf("Natotea Lukas :)!\n" );
  print_cars();
  race();
  return 0;
}
void race(){

}
void print_cars(){
  printf("Car: AX\nCar: F1\nCar: F2\nCar: F3\nCar: J1\nCar: J2\n");
}
