#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerLayerBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerLayerBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which contructs TIB/TOB layers
 */
class CmsTrackerLayerBuilder : public CmsTrackerLevelBuilder {
  
 private:
  virtual void sortNS(DDFilteredView& , GeometricDet*);
  virtual void buildComponent(DDFilteredView& , GeometricDet*, std::string);

};

#endif
