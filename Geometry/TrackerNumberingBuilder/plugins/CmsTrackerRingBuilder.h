#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerRingBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerRingBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which constructs TID/TEC rings
 */
class CmsTrackerRingBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
