#include <vector>


#ifndef PERLINNOISE_H
#define PERLINNOISE_H


class PerlinNoise {

  // The permutation references vector
  std::vector<int> permutations;

public:
  // Constructor
  PerlinNoise();

  // Overloaded constructor that generates permutations from a seed value
  PerlinNoise(unsigned int seed);

  // Get a noise value. For 2d images, z can have any value
  double noise(double x, double y, double z);

private:
  double face(double t);
  double lerp(double t, double a, double b);
  double grad(int hash, double x, double y, double z);
}


#endif
