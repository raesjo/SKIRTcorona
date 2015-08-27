/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
//////////////////////////////////////////////////////////////////*/

#ifndef SOLARFILAMENTDISTRIBUTION_HPP
#define SOLARFILAMENTDISTRIBUTION_HPP


#include "Array.hpp"
#include "DustDistribution.hpp"
class AdaptiveMeshFile;
class AdaptiveMesh;

////////////////////////////////////////////////////////////////////

/** The SolarFilamentDistribution class represents the plasma structure of a solar filament.
    The data file must be of MPIAMRVAC format, so please ignore the ASCII file option.
    Since the adaptive mesh data format does not specify
    the size of the domain, this information must be provided as properties of this class. The
    domain size is assumed to be symmetrical relative to the origin. Only 1 component is needed for
    this structure, hence this class only works with one. */
class SolarFilamentDistribution : public DustDistribution
{
    Q_OBJECT
    Q_CLASSINFO("Title", "Solar filament distribution imported from an adaptive mesh data file")

    Q_CLASSINFO("Property", "adaptiveMeshFile")
    Q_CLASSINFO("Title", "the adaptive mesh data file")
    Q_CLASSINFO("Default", "AdaptiveMeshAsciiFile")

    Q_CLASSINFO("Property", "densityUnits")
    Q_CLASSINFO("Title", "the units in which the file specifies density values")
    Q_CLASSINFO("Quantity", "massvolumedensity")
    Q_CLASSINFO("MinValue", "0")
    Q_CLASSINFO("Default", "1 Msun/pc3")

    Q_CLASSINFO("Property", "extentX")
    Q_CLASSINFO("Title", "the outer radius of the domain in the x direction")
    Q_CLASSINFO("Quantity", "length")
    Q_CLASSINFO("MinValue", "0")

    Q_CLASSINFO("Property", "extentY")
    Q_CLASSINFO("Title", "the outer radius of the domain in the y direction")
    Q_CLASSINFO("Quantity", "length")
    Q_CLASSINFO("MinValue", "0")

    Q_CLASSINFO("Property", "extentZ")
    Q_CLASSINFO("Title", "the outer radius of the domain in the z direction")
    Q_CLASSINFO("Quantity", "length")
    Q_CLASSINFO("MinValue", "0")

    Q_CLASSINFO("Property", "densityIndex")
    Q_CLASSINFO("Title", "the index of the column defining the density distribution")
    Q_CLASSINFO("MinValue", "0")
    Q_CLASSINFO("MaxValue", "99")
    Q_CLASSINFO("Default", "0")

    Q_CLASSINFO("Property", "tempIndex")
    Q_CLASSINFO("Title", "the index of the column defining the momentum in the x direction")
    Q_CLASSINFO("MinValue", "0")
    Q_CLASSINFO("MaxValue", "99")
    Q_CLASSINFO("Default", "1")

    Q_CLASSINFO("Property", "mix")
    Q_CLASSINFO("Title", "the dust mixture for the dust component")
    Q_CLASSINFO("Default", "InterstellarDustMix")

    //============= Construction - Setup - Destruction =============

public:
    /** The default constructor */
    Q_INVOKABLE SolarFilamentDistribution();

    /** The destructor deletes the data structures allocated during setup. */
    ~SolarFilamentDistribution();

protected:
    /** This function verifies the property values and imports the adaptive mesh data. */
    virtual void setupSelfBefore();

    //======== Setters & Getters for Discoverable Attributes =======

public:
    /** Sets the file containing the adaptive mesh data that defines this dust distribution. */
    Q_INVOKABLE void setAdaptiveMeshFile(AdaptiveMeshFile* value);

    /** Returns the file containing the adaptive mesh data that defines this dust distribution. */
    Q_INVOKABLE AdaptiveMeshFile* adaptiveMeshFile() const;

    /** Sets the units in which the file specifies density values. */
    Q_INVOKABLE void setDensityUnits(double value);

    /** Returns the units in which the file specifies density values. */
    Q_INVOKABLE double densityUnits() const;

    /** Sets the outer radius of the domain in the X direction. The total size of the domain in
        this direction is twice as large. */
    Q_INVOKABLE void setExtentX(double value);

    /** Returns the outer radius of the domain in the X direction. */
    Q_INVOKABLE double extentX() const;

    /** Sets the outer radius of the domain in the Y direction. The total size of the domain in
        this direction is twice as large. */
    Q_INVOKABLE void setExtentY(double value);

    /** Returns the outer radius of the domain in the Y direction. */
    Q_INVOKABLE double extentY() const;

    /** Sets the outer radius of the domain in the Z direction. The total size of the domain in
        this direction is twice as large. */
    Q_INVOKABLE void setExtentZ(double value);

    /** Returns the outer radius of the domain in the Z direction. */
    Q_INVOKABLE double extentZ() const;

    /** Sets the index of the column in the data file that defines the density distribution.
        The geometry will be normalized anyway after importing the probability
        distribution, so the probability distribution in the data file does not have to be
        normalized, and the units of the values in the data file are irrelevant. */
    Q_INVOKABLE void setDensityIndex(int value);

    /** Returns the index of the column in the data file that defines the density distribution
        for this geometry. */
    Q_INVOKABLE int densityIndex() const;

    /** Sets the index of the column in the data file that defines the first quantity needed
        for calculating the temperature. These are momentum (for all 3 spatial directions), total energy
        and magnetic field strength (in all 3 spatial directions). */
    Q_INVOKABLE void setTempIndex(int value);

    /** Returns the index of the column in the data file that defines the first quantity for
        calculating the temperature. */
    Q_INVOKABLE int tempIndex() const;

    /** This function sets the dust mixture of the dust component. */
    Q_INVOKABLE void setMix(DustMix* value);

   /** This function returns the dust mixture of the dust component. */
    Q_INVOKABLE DustMix* mix() const;

    //======================== Other Functions =======================

public:
    /** This function returns the dimension of the dust distribution, which for this class is
        always 3 since there are no symmetries in the geometry. */
    int dimension() const;

    /** This function returns the number of dust components that are involved in the dust
        distribution. For a solarfilament distribution, we only use a single component, so this
        value is set at 1.*/
    int Ncomp() const;

    /** This function returns a pointer to the dust mixture corresponding to the \f$h\f$'th dust
        component. */
    DustMix* mix(int h) const;

    /** This function returns the mass density \f$\rho_h({\bf{r}})\f$ of the \f$h\f$'th component
        of the dust distribution at the position \f${\bf{r}}\f$. */
    double density(int h, Position bfr) const;

    /** This function returns the total mass density \f$\rho({\bf{r}})\f$ of the dust distribution
        at the position \f${\bf{r}}\f$. This function simply calculates what the mesh cell is of
        the position and uses the density function described below.*/
    double density(Position bfr) const;

    /** This function returns the total mass density \f$\rho({\bf{r}})\f$ of the mesh cell m. The
        MPI AMRVAC file contains the total density, which should be adjusted to only the density that
        is in the correct energy state for the photon absorption (currently only working with H-alpha).
        This can be done using the exitation law of boltzman and the ionisation law of Saha, which both
        need the temperature. This quantity can be calculated from momentum, magnetic field strength and
        total energy.*/
    double density(int m) const;

    /** This function generates a random position from the dust distribution. It randomly chooses a
        mesh cell from the normalized cumulative density distribution constructed during the setup
        phase. Then a position is determined randomly within the cell boundaries. */
    Position generatePosition() const;

    /** This function returns the total dust mass of the dust distribution. For the solarfilament
        distribution, it just sums the density over all the mesh cells. */
    double mass() const;

    /** This function returns the X-axis surface density of the dust distribution, defined as the
        mass density integrated along the entire X-axis, \f[ \Sigma_X =
        \int_{-\infty}^\infty \rho(x,0,0)\, {\text{d}}x.\f]  */
    double SigmaX() const;

    /** This function returns the Y-axis surface density of the dust distribution, defined as the
        mass density integrated along the entire X-axis, \f[ \Sigma_Y =
        \int_{-\infty}^\infty \rho(0,y,0)\, {\text{d}}y.\f] */
    double SigmaY() const;

    /** This function returns the Z-axis surface density of the dust distribution, defined as the
        mass density integrated along the entire Z-axis, \f[ \Sigma_Z =
        \int_{-\infty}^\infty \rho(0,0,z)\, {\text{d}}z.\f] */
    double SigmaZ() const;

    /** This function returns the total velocity as a scalar of the \f$h\f$'th component
        of the dust distribution at the position \f${\bf{r}}\f$. */
    double testing(int h, Position bfr) const;

    /** This function returns the total velocity as a scalar of the dust distribution
        at the position \f${\bf{r}}\f$. This function simply calculates what the mesh cell is of
        the position and uses the density function described below.*/
    double testing(Position bfr) const;

    /** This function returns the total velocity as a scalar of the mesh cell m. */
    double testing(int m) const;



    //======================== Data Members ========================

private:
    // discoverable attributes
    AdaptiveMeshFile* _meshfile;
    double _densityUnits;
    double _xmax;
    double _ymax;
    double _zmax;
    double _densityIndex;
    double _tempIndex;
    DustMix* _mix;

    // other data members
    AdaptiveMesh* _mesh;
    Array _cumrhov;
};

////////////////////////////////////////////////////////////////////

#endif // SOLARFILAMENTDISTRIBUTION_HPP
