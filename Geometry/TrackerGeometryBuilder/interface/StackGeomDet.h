#ifndef Geometry_TrackerGeometryBuilder_StackGeomDet_H
#define Geometry_TrackerGeometryBuilder_StackGeomDet_H

#include <vector>
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/GeometrySurface/interface/Plane.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/CommonDetUnit/interface/TrackerGeomDet.h"

class StackGeomDet : public TrackerGeomDet{
public:

  StackGeomDet( BoundPlane* sp, const GeomDetUnit* lowerDet,  const GeomDetUnit* upperDet, const DetId stackDetId);
  
  virtual ~StackGeomDet();

  bool isLeaf() const override { return false;}
  virtual std::vector<const GeomDet*> components() const override;

  // Which subdetector
  virtual SubDetector subDetector() const override { return theLowerDet->subDetector(); };

  const GeomDetUnit* lowerDet() const { return theLowerDet; };
  const GeomDetUnit* upperDet() const { return theUpperDet; };

private:
  const GeomDetUnit* theLowerDet;
  const GeomDetUnit* theUpperDet;  
};

#endif
