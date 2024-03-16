#pragma once
#include "../vector3d/vector3d.h"
class Signal {
public:
    Signal(double _power, Vector3d _coordinates,
           Vector3d _direction) : power(_power),
        coordinates(_coordinates), direction(_direction) {

    }
    double getPower() const { return power;}
    Vector3d getCoordinates() const { return coordinates; }
    Vector3d getDirection() const { return direction; }

    void setPower(double _power) { power = _power};

private:


    double power; // In KW
    Vector3d coordinates; // Current
    Vector3d direction; //should be normalized

    //I guess we'll need it later:

    /*double frequency; // In KGz
    double sampleRate; // In Gz
    double pulseRepetitionFrequence; // In Gz
    int pulseInStack; // dimensionless
    int pulseDuration; // secs */ 
};
