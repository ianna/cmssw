#ifndef Geometry_TrackerNumberingBuilder_CondDBCmsTrackerConstruction_H
#define Geometry_TrackerNumberingBuilder_CondDBCmsTrackerConstruction_H

class GeometricDet;
class PGeometricDet;

/**
 * High level class to build a tracker. It will only build subdets,
 * then call subdet builders
 */

class CondDBCmsTrackerConstruction {
 public:
  CondDBCmsTrackerConstruction();
  const GeometricDet* construct( const PGeometricDet& pgd );
  //  void constructSubDet( const PGeometricDet& pgd, const std::string & s );
  
 protected:

  //  std::string attribute_;  
  //  CmsTrackerStringToEnum theCmsTrackerStringToEnum;

};

#endif
