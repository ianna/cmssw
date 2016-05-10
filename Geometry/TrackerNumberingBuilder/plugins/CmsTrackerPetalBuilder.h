#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerPetalBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerPetalBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which constructs TEC petals
 */
class CmsTrackerPetalBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
