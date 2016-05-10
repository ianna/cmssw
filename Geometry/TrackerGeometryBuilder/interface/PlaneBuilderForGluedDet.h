#ifndef Geometry_TrackerGeometryBuilder_PlaneBuilderForGluedDet_H
#define Geometry_TrackerGeometryBuilder_PlaneBuilderForGluedDet_H

#include <utility>
#include <vector>
#include "DataFormats/GeometrySurface/interface/GloballyPositioned.h"
#include "DataFormats/GeometrySurface/interface/Plane.h"
#include "DataFormats/GeometrySurface/interface/ReferenceCounted.h"
#include "DataFormats/GeometrySurface/interface/Surface.h"
#include "DataFormats/GeometryVector/interface/GlobalVector.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"

class RectangularPlaneBounds;

/** Builds the minimal rectangular box that contains all input GeomDetUnits fully.
 */

class PlaneBuilderForGluedDet {
public:

  /// Warning, remember to assign this pointer to a ReferenceCountingPointer!
  /// Should be changed to return a ReferenceCountingPointer<BoundPlane>
  typedef ReferenceCountingPointer<Plane>  ResultType;

  ResultType plane( const std::vector<const GeomDetUnit*> & dets) const;

private:
  std::pair<RectangularPlaneBounds*, GlobalVector>
  computeRectBounds( const std::vector<const GeomDetUnit*> & dets, const Plane& plane) const;

  Surface::RotationType 
  computeRotation( const std::vector<const GeomDetUnit*> & dets, 
		   const Surface::PositionType& meanPos) const; 

};

#endif
