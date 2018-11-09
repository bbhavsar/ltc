/*
 * The area of a circle is defined as πr^2.
 * Estimate π to 3 decimal places using a Monte Carlo method.
 *
 * Hint: The basic equation of a circle is x2 + y2 = r2.
 *
 */

#include "common.hh"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

double generate_random() {
  return (double)rand() / RAND_MAX;
}

bool is_point_in_circle(double x, double y) {
  return x*x + y*y <= 1.0;
}

double pi() {
  srand(time(NULL));

  int num_in_circle = 0;
  const int total_points = INT_MAX;
  for (int i = 0; i < total_points; i++) {
    double x = generate_random();
    double y = generate_random();
    if (is_point_in_circle(x,y)) {
      num_in_circle++;
    }
  }
  return (double) num_in_circle / total_points * 4.0;
}


int main() {

  cout << pi() << endl;

  return 0;
}

