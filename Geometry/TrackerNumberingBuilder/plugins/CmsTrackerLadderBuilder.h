#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerLadderBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerLadderBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which builds Pixel Ladders
 */
class CmsTrackerLadderBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
