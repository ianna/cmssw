#ifndef Geometry_TrackerNumberingBuilder_TrackerShapeToBounds_H
#define Geometry_TrackerNumberingBuilder_TrackerShapeToBounds_H

#include <vector>
#include "DetectorDescription/Core/interface/DDSolidShapes.h"

class Bounds;

/**
 * Converts DDSolid volumes to Bounds
 */
class TrackerShapeToBounds {
public:
  /**
   *buildBounds() return the Bounds.
   */
  Bounds* buildBounds( const DDSolidShape &,const std::vector<double>&) const;
 private:

  Bounds* buildBox(const std::vector<double> &) const;
  Bounds* buildTrap(const std::vector<double> &) const;
  Bounds* buildOpen(const std::vector<double> &) const;

};

#endif
