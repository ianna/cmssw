#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerPanelBuilder.h"
#include <stdint.h>
#include <algorithm>
#include <vector>
#include "FWCore/MessageLogger/interface/ErrorObj.icc"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "Geometry/TrackerNumberingBuilder/interface/CmsTrackerStringToEnum.h"
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"
#include "Geometry/TrackerNumberingBuilder/plugins/CmsDetConstruction.h"
#include "Geometry/TrackerNumberingBuilder/plugins/ExtractStringFromDDD.h"

class DDFilteredView;

void CmsTrackerPanelBuilder::buildComponent(DDFilteredView& fv, GeometricDet* g, std::string s){

  CmsDetConstruction theCmsDetConstruction;
  switch (theCmsTrackerStringToEnum.type(ExtractStringFromDDD::getString(s,&fv))){
  case GeometricDet::DetUnit:
           theCmsDetConstruction.buildComponent(fv,g,s);
    break;
  default:
    edm::LogError("CmsTrackerPanelBuilder")<<" ERROR - I was expecting a Plaq, I got a "<<ExtractStringFromDDD::getString(s,&fv);
    ;
  }  
}

void CmsTrackerPanelBuilder::sortNS(DDFilteredView& fv, GeometricDet* det){
 GeometricDet::ConstGeometricDetContainer & comp = det->components();

 if (comp.front()->type()==GeometricDet::DetUnit) 
   std::sort(comp.begin(),comp.end(),LessR()); 
 else
   edm::LogError("CmsTrackerPanelBuilder")<<"ERROR - wrong SubDet to sort..... "<<det->components().front()->type(); 

  for(uint32_t i=0; i<comp.size();i++){
    det->component(i)->setGeographicalID(i+1);
  } 
 
}
