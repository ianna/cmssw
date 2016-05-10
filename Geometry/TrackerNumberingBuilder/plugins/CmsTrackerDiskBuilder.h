#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerDiskBuilder_H
# define Geometry_TrackerNumberingBuilder_CmsTrackerDiskBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Class which contructs PixelForward/Disk.
 */
class CmsTrackerDiskBuilder : public CmsTrackerLevelBuilder
{
  
private:
  virtual void sortNS( DDFilteredView& , GeometricDet* );
  virtual void buildComponent( DDFilteredView& , GeometricDet*, std::string );

};

#endif
