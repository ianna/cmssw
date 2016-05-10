#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerRodBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerRodBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which constructs TOB rods
 */
class CmsTrackerRodBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
