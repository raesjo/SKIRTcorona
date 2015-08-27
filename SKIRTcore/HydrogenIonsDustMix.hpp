/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
//////////////////////////////////////////////////////////////////*/

#ifndef HYDROGENIONSDUSTMIX_HPP
#define HYDROGENIONSDUSTMIX_HPP

#include "DustMix.hpp"

////////////////////////////////////////////////////////////////////

/** The HydrogenIonsDustMix represents the properties of hydrogen ions, thus representing
    solar plasma in solar filaments.
*/
class HydrogenIonsDustMix : public DustMix
{
    Q_OBJECT
    Q_CLASSINFO("Title", "a configuration of hydrogen ions")

    //============= Construction - Setup - Destruction =============

public:
    /** The default constructor. */
    Q_INVOKABLE HydrogenIonsDustMix();

protected:
    /** This function reads the optical properties */
    void setupSelfBefore();
};

////////////////////////////////////////////////////////////////////

#endif // HYDROGENIONSDUSTMIX_HPP
