#include <stdio.h>
#include "car.h"

#define AIXAM_MAX_ACCELERATION 1.0
#define AIXAM_MAX_SPEED 45
#define FIAT_MULTIPLA_MAX_ACCELERATION 2.26
#define FIAT_MULTIPLA_MAX_SPEED 170
#define JEEP_MAX_ACCELERATION 3.14
#define JEEP_MAX_SPEED 196

int round_up(double speed);

struct  CarImplementation {
  type type;
  color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool is_rented;
};

static struct CarImplementation AX  = {AIXAM, RED, 16, 0.0, 0, false};
static struct CarImplementation F1 = {FIAT_MULTIPLA, GREEN, 65, 0.0, 0, false};
static struct CarImplementation F2 = {FIAT_MULTIPLA, BLUE, 65, 0.0, 0, false};
static struct CarImplementation F3 = {FIAT_MULTIPLA, ORANGE, 65, 0.0, 0, false};
static struct CarImplementation J1 = {JEEP, SILVER, 80, 0.0, 0, false};
static struct CarImplementation J2 = {JEEP, BLACK, 80, 0.0, 0, false};

void init()
{
  AX.fill_level = 16;
  AX.acceleration_rate = 0.0;
  AX.speed = 0;
  AX.is_rented = false;

  F1.fill_level = 65;
  F1.acceleration_rate = 0.0;
  F1.speed = 0;
  F1.is_rented = false;

  F2.fill_level = 65;
  F2.acceleration_rate = 0.0;
  F2.speed = 0;
  F2.is_rented = false;

  F3F3.fill_level = 65;
  F3F3.acceleration_rate = 0.0;
  F3F3.speed = 0;
  F3F3.is_rented = false;

  J1.fill_level = 80;
  J1.acceleration_rate = 0.0;
  J1.speed = 0;
  J1.is_rented = false;

  J2.fill_level = 80;
  J2.acceleration_rate = 0.0;
  J2.speed = 0;
  J2.is_rented = false;

}

Car get_car(enum type type)
{
  Car car;
  if (type == AIXAM) {
    if (!AX.is_rented) {
      car = &AX;
      AX.is_rented = true;
    }
    else car = 0;
  }
  else if (type == FIAT_MULTIPLA) {
    if (!F1.is_rented) {
      car = &F1;
      F1.is_rented = true;
    }
    else if (!F2.is_rented) {
      car = &F2;
      F2.is_rented = true;
    }
    else if (!F3.is_rented) {
      car = &F3;
      F3.is_rented = true;
    }
    else car = 0;
  }
  else {
    if (!J1.is_rented) {
      car = &J1;
      J1.is_rented = true;
    }
    else if (!J2.is_rented) {
      car = &J2;
      J2.is_rented = true;
    }
    else car = 0;
  }
  return car;
}

enum color get_color(Car car)
{
  return car->color;
}

enum type get_type(Car car)
{
  return car->type;
}

double get_fill_level(Car car)
{
  return car->fill_level;
}

int get_speed(Car car)
{
  return round_up(car->speed);
}

double get_acceleration_rate(Car car)
{
  return car->acceleration_rate;
}

void set_acceleration_rate(Car car, double rate)
{
  if (rate < -8)
  {
    car->acceleration_rate = -8;
    return;
  }
  if (car->type == AIXAM)
  {
    if (rate > AIXAM_MAX_ACCELERATION) car->acceleration_rate = AIXAM_MAX_ACCELERATION;
    else car->acceleration_rate = rate;
    return;
  }
  if (car->type == FIAT_MULTIPLA)
  {
    if (rate > FIAT_MULTIPLA_MAX_ACCELERATION) car->acceleration_rate = FIAT_MULTIPLA_MAX_ACCELERATION;
    else car->acceleration_rate = rate;
    return;
  }
  if (car->type == JEEP)
  {
    if(rate > JEEP_MAX_ACCELERATION) car->acceleration_rate = JEEP_MAX_ACCELERATION;
    else car->acceleration_rate = rate;
    return;
  }
}

void accelerate(Car car)
{
  if (car->type == AIXAM)
  {
    if (car->speed + 3.6 * car->acceleration_rate <= AIXAM_MAX_SPEED)
    {
      car->speed += 3.6*car->acceleration_rate;
    }
    else car->speed = AIXAM_MAX_SPEED;
    return;
  }

  if (car->type == FIAT_MULTIPLA)
  {
    if (car->speed + 3.6 * car->acceleration_rate <= FIAT_MULTIPLA_MAX_SPEED)
    {
      car->speed += 3.6*car->acceleration_rate;
    }
    else car->speed = FIAT_MULTIPLA_MAX_SPEED;
    return;
  }
  if (car->type == JEEP)
  {
    if (car->speed + 3.6 * car->acceleration_rate <= JEEP_MAX_SPEED)
    {
      car->speed += 3.6*car->acceleration_rate;
    }
    else car->speed = JEEP_MAX_SPEED;
    return;
  }
}

int round_up(double speed)
{
  int final_speed = (speed + 0.5);
  return final_speed;
}
