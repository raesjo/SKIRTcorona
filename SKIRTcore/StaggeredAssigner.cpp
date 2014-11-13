/*//////////////////////////////////////////////////////////////////
////       SKIRT -- an advanced radiative transfer code         ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#include "PeerToPeerCommunicator.hpp"
#include "StaggeredAssigner.hpp"

////////////////////////////////////////////////////////////////////

StaggeredAssigner::StaggeredAssigner()
{
}

////////////////////////////////////////////////////////////////////

void StaggeredAssigner::assign(size_t size)
{
    _comm = find<PeerToPeerCommunicator>();

    for (size_t i = 0; i < size; i++)
    {
        if (i % _comm->getSize() == _comm->getRank()) _nvalues++;
    }
}

////////////////////////////////////////////////////////////////////

size_t StaggeredAssigner::absoluteIndex(size_t relativeIndex)
{
    size_t absoluteIndex = _comm->getRank() + relativeIndex * _comm->getSize();
    return absoluteIndex;
}

////////////////////////////////////////////////////////////////////

int StaggeredAssigner::rankForIndex(size_t index) const
{
    return (index % _comm->getSize());
}

////////////////////////////////////////////////////////////////////

bool StaggeredAssigner::parallel() const
{
    return true;
}

////////////////////////////////////////////////////////////////////