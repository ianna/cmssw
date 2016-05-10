#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerRodBuilder.h"
#include <stdint.h>
#include <algorithm>
#include <vector>
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"
#include "Geometry/TrackerNumberingBuilder/plugins/CmsDetConstruction.h"

class DDFilteredView;

void CmsTrackerRodBuilder::buildComponent(DDFilteredView& fv, GeometricDet* g, std::string s){
  CmsDetConstruction theCmsDetConstruction;
  theCmsDetConstruction.buildComponent(fv,g,s);  
}

void CmsTrackerRodBuilder::sortNS(DDFilteredView& fv, GeometricDet* det){
  GeometricDet::ConstGeometricDetContainer & comp = det->components();

  std::stable_sort(comp.begin(),comp.end(),LessModZ()); 	

  for(uint32_t i=0; i<comp.size();i++){
    det->component(i)->setGeographicalID(i+1);
  }
    
  if (comp.empty() ){
   edm::LogError("CmsTrackerRodBuilder")<<"Where are the Rod's modules?";
  }
}
