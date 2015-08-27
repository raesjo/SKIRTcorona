/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
//////////////////////////////////////////////////////////////////*/

#include "AdaptiveMesh.hpp"
#include "SolarFilamentDistribution.hpp"
#include "AdaptiveMeshFile.hpp"
#include "FatalError.hpp"
#include "FilePaths.hpp"
#include "Log.hpp"
#include "MeshDustComponent.hpp"
#include "NR.hpp"
#include "Random.hpp"
#include "DustMix.hpp"

using namespace std;

//////////////////////////////////////////////////////////////////////

SolarFilamentDistribution::SolarFilamentDistribution()
    : _meshfile(0), _densityUnits(0), _xmax(0), _ymax(0), _zmax(0), _densityIndex(0), _tempIndex(1), _mix(0), _mesh(0)
{
}

////////////////////////////////////////////////////////////////////

SolarFilamentDistribution::~SolarFilamentDistribution()
{
    delete _mesh;
}

//////////////////////////////////////////////////////////////////////

void SolarFilamentDistribution::setupSelfBefore()
{
    DustDistribution::setupSelfBefore();

    // verify property values
    //  if (_densityUnits <= 0) throw FATALERROR("Density units should be positive");
    if (_xmax <= 0 || _ymax <= 0 || _zmax <= 0) throw FATALERROR("Domain size should be positive");
    //if (_dcv.isEmpty()) throw FATALERROR("There are no dust components");

    QList<int> fieldIndices;
    fieldIndices << densityIndex() << tempIndex() << tempIndex()+1 << tempIndex()+2 << tempIndex()+3
                 << tempIndex()+4 << tempIndex()+5 << tempIndex()+6;

    _mesh = new AdaptiveMesh(_meshfile, fieldIndices, Box(-_xmax,-_ymax,-_zmax, _xmax,_ymax,_zmax));
    find<Log>()->info("Adaptive mesh data was successfully imported: " + QString::number(_mesh->Ncells()) + " cells.");
}

//////////////////////////////////////////////////////////////////////

/*
void SolarFilamentDistribution::setupSelfAfter()
{
    DustDistribution::setupSelfAfter();

    // make a list of the field indices needed by any of our components

  //  foreach (MeshDustComponent* dc, _dcv)
  //  {

  //  }

    // import the adaptive mesh


  //  // add a density field for each of our components, so that the mesh holds the total density
  //  foreach (MeshDustComponent* dc, _dcv)
  //  {
  //      _mesh->addDensityDistribution(dc->densityIndex(), dc->multiplierIndex(), dc->densityFraction());
  //  }

    // construct a vector with the normalized cumulative masses
    NR::cdf(_cumrhov, _mesh->Ncells(), [this](int i){return _mesh->density(i)*_mesh->volume(i);} );
}
*/
//////////////////////////////////////////////////////////////////////


void SolarFilamentDistribution::setAdaptiveMeshFile(AdaptiveMeshFile* value)
{
    if (_meshfile) delete _meshfile;
    _meshfile = value;
    if (_meshfile) _meshfile->setParent(this);
}

//////////////////////////////////////////////////////////////////////

AdaptiveMeshFile* SolarFilamentDistribution::adaptiveMeshFile() const
{
    return _meshfile;
}

//////////////////////////////////////////////////////////////////////

void SolarFilamentDistribution::setDensityUnits(double value)
{
    _densityUnits = value;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::densityUnits() const
{
    return _densityUnits;
}

//////////////////////////////////////////////////////////////////////


void SolarFilamentDistribution::setExtentX(double value)
{
    _xmax = value;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::extentX() const
{
    return _xmax;
}

//////////////////////////////////////////////////////////////////////

void SolarFilamentDistribution::setExtentY(double value)
{
    _ymax = value;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::extentY() const
{
    return _ymax;
}

//////////////////////////////////////////////////////////////////////

void SolarFilamentDistribution::setExtentZ(double value)
{
    _zmax = value;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::extentZ() const
{
    return _zmax;
}

//////////////////////////////////////////////////////////////////////

void SolarFilamentDistribution::setDensityIndex(int value)
{
    _densityIndex = value;
}

////////////////////////////////////////////////////////////////////

int SolarFilamentDistribution::densityIndex() const
{
    return _densityIndex;
}

//////////////////////////////////////////////////////////////////////

void SolarFilamentDistribution::setTempIndex(int value)
{
    _tempIndex = value;
}

////////////////////////////////////////////////////////////////////

int SolarFilamentDistribution::tempIndex() const
{
    return _tempIndex;
}

//////////////////////////////////////////////////////////////////////

void SolarFilamentDistribution::setMix(DustMix* value)
{
    if (_mix) delete _mix;
    _mix = value;
    if (_mix) _mix->setParent(this);
}

//////////////////////////////////////////////////////////////////////

DustMix* SolarFilamentDistribution::mix() const
{
    return _mix;
}

//////////////////////////////////////////////////////////////////////

int SolarFilamentDistribution::dimension() const
{
    return 3;
}

//////////////////////////////////////////////////////////////////////

int SolarFilamentDistribution::Ncomp() const
{
    return 1;
}

//////////////////////////////////////////////////////////////////////

DustMix* SolarFilamentDistribution::mix(int /*h*/) const
{
   return _mix;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::density(int /*h*/, Position bfr) const
{
    return density(bfr);
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::density(Position bfr) const
{
    int m = _mesh->cellIndex(bfr);
    return density(m);
}

//////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::density(int m) const
{


    double me = 9.10938291e-31;  //mass electron, kilogram
    double k = 4.13566751691e-15;  // planck constant, eV * second
    double h = 8.617332478e-5;  //boltzmann constant, eV/kelvin

    //reading in needed quantities to calculate which fraction of the material is in the correct energy state
     double rho = _mesh->value(_densityIndex, m+1);
     double px = _mesh->value(_tempIndex, m+1);
     double py = _mesh->value(_tempIndex+1, m+1);
     double pz = _mesh->value(_tempIndex+2, m+1);
     double energy = _mesh->value(_tempIndex+3, m+1);
     double Bx = _mesh->value(_tempIndex+4, m+1);
     double By = _mesh->value(_tempIndex+5, m+1);
     double Bz = _mesh->value(_tempIndex+6, m+1);

    //calculating pressure and temperature
     double pressure = (energy - ((px*px+py*py+pz*pz)/(2.0*rho)) - ((Bx*Bx+By*By+Bz*Bz)/2.0)) * (2.0/3.0);  //units erg cm^-3
     double temp = pressure/rho;  //units 10^6 Kelvin
     temp *= 1.0e6;  //units Kelvin



    // Calculating fractions (dimensionless)
     double sahafraction = (1.0/(1.2*rho*2.341668e-9)) * pow(((2.0*M_PI * me * k * temp)/(h*h)),3.0/2.0) * exp(-13.6/(k*temp));
     double boltzmannfraction = 4.0*exp(-10.2/(k*temp));

    //rho *= _densityUnits;
   // double adjusted_rho = rho * sahafraction * boltzmannfraction;

    //double adjusted_rho = rho * (1.0/(1.2*rho)) * pow(((2.0*M_PI * me * k * temp)/(h*h)),3.0/2.0) * exp(-13.6/(k*temp)); //saha
    //adjusted_rho *= 4.0*exp(-10.2/(k*temp));  //boltzmann

   // return adjusted_rho;
    return rho;

}

Position SolarFilamentDistribution::generatePosition() const
{
    Random* random = find<Random>();
    int m = NR::locate_clip(_cumrhov, random->uniform());
    return _mesh->randomPosition(random, m);
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::mass() const
{
    double mass = 0.0;

    for (int m=0; m<(_mesh->Ncells() -1); m++)
    {
        mass+= density(m);
    }
    return mass;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::SigmaX() const
{
    double sum = 0.0;
    for (int k=0; k< 10000; k++){
        sum += density(Position( -_xmax + k*(2.0*_xmax)/10000, 0, 0));
    }

    return sum;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::SigmaY() const
{
    double sum = 0.0;
    for (int k=0; k< 10000; k++){
        sum += density(Position(0, -_ymax + k*(2.0*_ymax)/10000, 0));
    }

    return sum;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::SigmaZ() const
{
    double sum = 0.0;
    for (int k=0; k< 10000; k++){
        sum += density(Position(0,0, -_zmax + k*(2.0*_zmax)/10000));
    }

    return sum;
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::testing(int /*h*/, Position bfr) const
{
    return testing(bfr);
}

//////////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::testing(Position bfr) const
{
    int m = _mesh->cellIndex(bfr);
    return testing (m);
}

//////////////////////////////////////////////////////////////////

double SolarFilamentDistribution::testing(int m) const
{



    //reading in needed quantities to calculate which fraction of the material is in the correct energy state
    double velocity_x = _mesh->value(_tempIndex, m+1);
    double velocity_y = _mesh->value(_tempIndex+1, m+1);
    double velocity_z = _mesh->value(_tempIndex+2, m+1);

    double velocity_total = sqrt(velocity_x*velocity_x+velocity_y*velocity_y+velocity_z*velocity_z);

    return velocity_total;

}

