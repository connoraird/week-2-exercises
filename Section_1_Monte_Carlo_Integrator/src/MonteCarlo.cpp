#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <random>

bool InsideUnitSphere(double x, double y, double z)
{
    return ((x*x + y*y + z*z) <= 1);
}

double IntegrateMonteCarlo3D(int n_points, double min, double max, int seed, std::function<bool(double, double, double)> callBack)
{
    int count = 0;
    // N.B. std::pow with integer arguments can be less efficient than
    // writing the multiplication explicitly, so be careful about using it
    // inside loops for example!
    double VolCube = std::pow((max - min), 3);

    //set up random number generator here
    // construct a trivial random generator engine from a time-based seed:
    std::mt19937 rng_mt(seed);
    std::uniform_real_distribution<double> uniform_dist(-1.0, 1.0);
    auto generate_random_number = std::bind(uniform_dist, rng_mt);

    for(int i = 0; i < n_points; i++)
    {
        //generate random points here
        double x = generate_random_number();
        double y = generate_random_number();
        double z = generate_random_number();
        if(callBack(x, y, z)) count++;
    }

    return static_cast<double>(count) / n_points * VolCube;
}


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: missing seed" << std::endl;
        std::cout << "Usage: " << argv[0] << " <seed>" << std::endl;
        return 1;
    }

    int N_points = 10000;
    int seed = std::stoi(argv[1]);
    
    double UnitSphereVol = IntegrateMonteCarlo3D(N_points, -1.0, 1.0, seed, InsideUnitSphere);

    std::cout << "Volume estimate of sphere using " << N_points << " points = " << UnitSphereVol << std::endl;
}