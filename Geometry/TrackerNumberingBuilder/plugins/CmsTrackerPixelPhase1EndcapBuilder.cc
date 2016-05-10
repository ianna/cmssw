#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerPixelPhase1EndcapBuilder.h"
#include <stdint.h>
#include <algorithm>
#include <vector>
#include "DetectorDescription/Core/interface/DDName.h"
#include "FWCore/MessageLogger/interface/ErrorObj.icc"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "Geometry/TrackerNumberingBuilder/interface/CmsTrackerStringToEnum.h"
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerPhase1DiskBuilder.h"
#include "Geometry/TrackerNumberingBuilder/plugins/ExtractStringFromDDD.h"

class DDFilteredView;

CmsTrackerPixelPhase1EndcapBuilder::CmsTrackerPixelPhase1EndcapBuilder()
{}

void
CmsTrackerPixelPhase1EndcapBuilder::buildComponent( DDFilteredView& fv, GeometricDet* g, std::string s )
{
  CmsTrackerPhase1DiskBuilder  theCmsTrackerPhase1DiskBuilder;   

  GeometricDet * subdet = new GeometricDet( &fv, theCmsTrackerStringToEnum.type( ExtractStringFromDDD::getString( s, &fv )));
  std::string subdet_name = subdet->name();
  switch( theCmsTrackerStringToEnum.type( ExtractStringFromDDD::getString( s, &fv )))
  {
  case GeometricDet::PixelPhase1Disk:    
    LogDebug("DiskNames") << "The name of the components is: " << subdet_name;
    theCmsTrackerPhase1DiskBuilder.build(fv,subdet,s);
    break;

  default:
    edm::LogError("CmsTrackerPixelPhase1EndcapBuilder")<<" ERROR - I was expecting a Disk... I got a "<<ExtractStringFromDDD::getString(s,&fv);
  }  
  
  g->addComponent(subdet);

}

void
CmsTrackerPixelPhase1EndcapBuilder::sortNS( DDFilteredView& fv, GeometricDet* det )
{
  GeometricDet::ConstGeometricDetContainer & comp = det->components();

  switch( comp.front()->type())
  {
  case GeometricDet::PixelPhase1Disk:
    std::sort( comp.begin(), comp.end(), LessModZ());
    break;
  default:
    edm::LogError( "CmsTrackerPixelPhase1EndcapBuilder" ) << "ERROR - wrong SubDet to sort..... " << det->components().front()->type(); 
  }
  
  for( uint32_t i = 0; i < comp.size(); i++ )
  {
    det->component(i)->setGeographicalID(i+1); // Every subdetector: Disk Number
  }
}

