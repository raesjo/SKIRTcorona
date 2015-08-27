/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#include "DustDistribution.hpp"

using namespace std;

//////////////////////////////////////////////////////////////////////

DustDistribution::DustDistribution()
{
}

//////////////////////////////////////////////////////////////////////

int DustDistribution::indexformix(const DustMix* dustmix)
{
    int n = Ncomp();
    for (int h = 0; h<n; h++)
    {
        if (dustmix == mix(h)) return h;
    }
    return -1;
}

//////////////////////////////////////////////////////////////////////


double DustDistribution::gasTemperature(int h, Position bfr) const{
    return 0.0;
}


double DustDistribution::gasTemperature(Position bfr) const{
    return 0.0;
}

///////////////////////////////////////////////////////////////////////

double DustDistribution::bulkVelocityX(int h, Position bfr) const{
    return 0.0;
}


double DustDistribution::bulkVelocityX(Position bfr) const{
    return 0.0;
}

///////////////////////////////////////////////////////////////////////

double DustDistribution::bulkVelocityY(int h, Position bfr) const{
    return 0.0;
}


double DustDistribution::bulkVelocityY(Position bfr) const{
    return 0.0;
}

///////////////////////////////////////////////////////////////////////

double DustDistribution::bulkVelocityZ(int h, Position bfr) const{
    return 0.0;
}


double DustDistribution::bulkVelocityZ(Position bfr) const{
    return 0.0;
}
