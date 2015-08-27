/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
//////////////////////////////////////////////////////////////////*/

#include <fstream>
#include "FatalError.hpp"
#include "FilePaths.hpp"
#include "HydrogenIonsDustMix.hpp"
#include "Log.hpp"
#include "Units.hpp"

using namespace std;

//////////////////////////////////////////////////////////////////////

HydrogenIonsDustMix::HydrogenIonsDustMix()
{
}

//////////////////////////////////////////////////////////////////////

void HydrogenIonsDustMix::setupSelfBefore()
{
    DustMix::setupSelfBefore();

    // create temporary vectors with the appropriate size.
    const int Nlambda = 1;
    Array lambdav(Nlambda);
    Array sigmaabsv(Nlambda);
    Array sigmascav(Nlambda);
    Array asymmparv(Nlambda);

    // data corresponding to the Lyman alpha line,
    // wavelength 121.567 nm = 1.21567e-7 m

    lambdav[0] = 1.21567e-7;
    sigmaabsv[0] = 0.0 ;
    sigmascav[0] = 3.31e-18;  // cross-section per hydrogen atom (in m2/#H)
    asymmparv[0] = 0.0 ;
    double mu = Units::massproton(); // dust mass per hydrogen atom (in kg/#H)


    // add a dust population with these properties
    addpopulation(mu,lambdav,sigmaabsv,sigmascav,asymmparv);
}

//////////////////////////////////////////////////////////////////////
