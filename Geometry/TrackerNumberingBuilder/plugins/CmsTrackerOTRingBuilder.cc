#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerOTRingBuilder.h"
#include <stdint.h>
#include <vector>
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"
#include "Geometry/TrackerNumberingBuilder/plugins/CmsDetConstruction.h"
#include "Geometry/TrackerNumberingBuilder/plugins/TrackerStablePhiSort.h"
#include "boost/bind/bind.hpp"
#include "boost/bind/bind_template.hpp"

class DDFilteredView;

void CmsTrackerOTRingBuilder::buildComponent(DDFilteredView& fv, GeometricDet* g, std::string s){

  CmsDetConstruction theCmsDetConstruction;
  theCmsDetConstruction.buildComponent(fv,g,s);

}

void CmsTrackerOTRingBuilder::sortNS(DDFilteredView& fv, GeometricDet* det){

  GeometricDet::ConstGeometricDetContainer & comp = det->components();

  //increasing phi taking into account the sub-modules
  TrackerStablePhiSort(comp.begin(), comp.end(), ExtractPhiGluedModule());

  for(uint32_t i=0; i<comp.size();i++){
    det->component(i)->setGeographicalID(i+1);
  } 
 
}
