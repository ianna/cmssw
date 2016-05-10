#ifndef Geometry_TrackerGeometryBuilder_GluedGeomDet_H
#define Geometry_TrackerGeometryBuilder_GluedGeomDet_H

#include <vector>
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/GeometrySurface/interface/Plane.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/CommonDetUnit/interface/TrackerGeomDet.h"

class GluedGeomDet final : public TrackerGeomDet {
public:

  GluedGeomDet( BoundPlane* sp, const GeomDetUnit* monoDet,  const GeomDetUnit* stereoDet, const DetId gluedDetId);
  
  virtual ~GluedGeomDet();

  bool isLeaf() const override { return false;}
  virtual std::vector<const GeomDet*> components() const override;

  // Which subdetector
  virtual SubDetector subDetector() const override {return theMonoDet->subDetector();}

  const GeomDetUnit* monoDet() const { return theMonoDet;}
  const GeomDetUnit* stereoDet() const { return theStereoDet;}

private:
  const GeomDetUnit* theMonoDet;
  const GeomDetUnit* theStereoDet;  
};

#endif
