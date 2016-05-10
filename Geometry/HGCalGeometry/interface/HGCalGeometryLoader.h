#ifndef GeometryHGCalGeometryHGCalGeometryLoader_h
#define GeometryHGCalGeometryHGCalGeometryLoader_h

#include <vector>
#include "DataFormats/DetId/interface/DetId.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"

class HGCalGeometry;
class HGCalTopology;

namespace HepGeom { class Transform3D; }

class HGCalGeometryLoader {

public:
  typedef CaloCellGeometry::CCGFloat CCGFloat;
  typedef std::vector<float> ParmVec;

  HGCalGeometryLoader ();
  ~HGCalGeometryLoader ();

  HGCalGeometry* build(const HGCalTopology& );

private:
  void buildGeom(const ParmVec&, const HepGeom::Transform3D&, const DetId&,
		 HGCalGeometry*);

};

#endif
