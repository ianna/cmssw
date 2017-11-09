#ifndef Geometry_TrackerGeometryBuilder_StackGeomDet_H
#define Geometry_TrackerGeometryBuilder_StackGeomDet_H

#include "Geometry/CommonDetUnit/interface/TrackerGeomDet.h"
#include "DataFormats/DetId/interface/DetId.h"

class StackGeomDet : public TrackerGeomDet {
public:

  StackGeomDet( BoundPlane* sp, const GeomDet* lowerDet,  const GeomDet* upperDet, const DetId stackDetId);
  
  ~StackGeomDet() override;

  bool isLeaf() const override { return false;}
  std::vector< const GeomDet* > components() const override;

  // Which subdetector
  SubDetector subDetector() const override { return theLowerDet->subDetector(); };

  const GeomDet* lowerDet() const { return theLowerDet; };
  const GeomDet* upperDet() const { return theUpperDet; };

private:
  const GeomDet* theLowerDet;
  const GeomDet* theUpperDet;  
};

#endif
