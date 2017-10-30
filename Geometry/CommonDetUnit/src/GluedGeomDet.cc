#include "Geometry/CommonDetUnit/interface/GluedGeomDet.h"

GluedGeomDet::GluedGeomDet( BoundPlane* sp, const std::shared_ptr< const GeomDet > monoDet,
			    const std::shared_ptr< const GeomDet > stereoDet, const DetId gluedDetId )
  : 
  TrackerGeomDet(sp),theMonoDet(monoDet),theStereoDet(stereoDet) {
  setDetId(gluedDetId);
}

GluedGeomDet::~GluedGeomDet()
{}

std::vector< std::shared_ptr< const GeomDet >> GluedGeomDet::components() const {
  return std::vector< std::shared_ptr< const GeomDet > >{theMonoDet,theStereoDet};
}
