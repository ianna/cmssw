#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerStringBuilder.h"
#include <stdint.h>
#include <algorithm>
#include <vector>
#include "DataFormats/DetId/interface/DetId.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"
#include "Geometry/TrackerNumberingBuilder/plugins/CmsDetConstruction.h"

class DDFilteredView;

void CmsTrackerStringBuilder::buildComponent(DDFilteredView& fv, GeometricDet* g, std::string s){
  CmsDetConstruction theCmsDetConstruction;
  theCmsDetConstruction.buildComponent(fv,g,s);  
}

void CmsTrackerStringBuilder::sortNS(DDFilteredView& fv, GeometricDet* det){
  GeometricDet::ConstGeometricDetContainer& comp = det->components();

  std::stable_sort(comp.begin(),comp.end(),LessModZ()); 
  
  if(comp.size()){
    for(uint32_t i=0; i<comp.size();i++){
      det->component(i)->setGeographicalID(DetId(i+1));
    }
  }else{
       edm::LogError("CmsTrackerStringBuilder")<<"Where are the String's modules?";
  }
}


