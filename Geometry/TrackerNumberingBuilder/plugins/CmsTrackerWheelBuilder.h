#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerWheelBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerWheelBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which builds TEC wheels
 */
class CmsTrackerWheelBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
