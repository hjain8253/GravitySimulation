# GravitySimulation
Gravity simulation using a spherical harmonic geopotential model (EMG2008)

g++ -g -std=c++11 -o satellite_simulation main.cpp Execute.cpp Order.cpp Degree.cpp Legendre.cpp

Note*
Results are unexpected due to the large volitility in the higher order Legendre polynomial coefficients.
The values need to be normalized before they are used in the gravity potential + acceleration calculations. 
