#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerDebugNavigator_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerDebugNavigator_H

#include <stdint.h>
#include <map>
#include <vector>
#include "Geometry/TrackerNumberingBuilder/interface/CmsTrackerStringToEnum.h"

class GeometricDet;
class GeometricDetExtra;

/**
 * This class travel recursively a GeometricDet and dumps the information about type
 */
class CmsTrackerDebugNavigator {
 public:
  CmsTrackerDebugNavigator (const std::vector<GeometricDetExtra> & );
  void  dump(const GeometricDet&, const std::vector<GeometricDetExtra> & );
 private:
  void iterate(const GeometricDet&,int, const std::vector<GeometricDetExtra> & );
  int numinstances[30];
  CmsTrackerStringToEnum _CmsTrackerStringToEnum;
  std::map<uint32_t, const GeometricDetExtra*> _helperMap; 
};

#endif
