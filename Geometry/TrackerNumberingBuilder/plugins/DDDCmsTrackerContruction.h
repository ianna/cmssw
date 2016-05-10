#ifndef Geometry_TrackerNumberingBuilder_DDDCmsTrackerContruction_H
# define Geometry_TrackerNumberingBuilder_DDDCmsTrackerContruction_H

#include <string>
#include <vector>
#include "Geometry/TrackerNumberingBuilder/interface/CmsTrackerStringToEnum.h"

class DDCompactView;
class GeometricDet;

/**
 * High level class to build a tracker. It will only build subdets,
 * then call subdet builders
 */

class DDDCmsTrackerContruction
{
public:
  DDDCmsTrackerContruction( void );
  const GeometricDet* construct( const DDCompactView* cpv, std::vector<int> detidShifts);
  
protected:

  std::string attribute;  
  CmsTrackerStringToEnum theCmsTrackerStringToEnum;
};

#endif
