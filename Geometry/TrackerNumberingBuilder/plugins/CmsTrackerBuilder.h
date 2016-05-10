#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerBuilder_H
# define Geometry_TrackerNumberingBuilder_CmsTrackerBuilder_H

#include <string>
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerLevelBuilder.h"

class DDFilteredView;
class GeometricDet;

/**
 * Abstract Class to construct a Level in the hierarchy
 */
class CmsTrackerBuilder : public CmsTrackerLevelBuilder
{
public:
  CmsTrackerBuilder();

private:

  virtual void sortNS( DDFilteredView& , GeometricDet* );
  virtual void buildComponent( DDFilteredView& , GeometricDet*, std::string );
};

#endif
