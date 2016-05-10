#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerStringBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerStringBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which constructs TIB strings
 */
class CmsTrackerStringBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
