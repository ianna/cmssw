#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerPixelPhase1EndcapBuilder_H
# define Geometry_TrackerNumberingBuilder_CmsTrackerPixelPhase1EndcapBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which builds the pixel phase 1 endcap
 */
class CmsTrackerPixelPhase1EndcapBuilder : public CmsTrackerLevelBuilder
{
public:
  CmsTrackerPixelPhase1EndcapBuilder();
  
private:
  virtual void sortNS( DDFilteredView& , GeometricDet* );
  virtual void buildComponent( DDFilteredView& , GeometricDet*, std::string );
};

#endif
