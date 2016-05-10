#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerOTRingBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerOTRingBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which contructs PixelForward Panels. 
 */
class CmsTrackerOTRingBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
