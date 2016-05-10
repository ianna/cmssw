#ifndef Geometry_TrackerNumberingBuilder_TrackerGeometricDetESModule_H
#define Geometry_TrackerNumberingBuilder_TrackerGeometricDetESModule_H

#include <memory>
#include "FWCore/Framework/interface/ESProducer.h"

class GeometricDet;
class IdealGeometryRecord;

namespace edm { class ConfigurationDescriptions; }
namespace edm { class ParameterSet; }

class TrackerGeometricDetESModule : public edm::ESProducer
{
public:
  TrackerGeometricDetESModule( const edm::ParameterSet & p );
  virtual ~TrackerGeometricDetESModule( void ); 
  std::unique_ptr<GeometricDet> produce( const IdealGeometryRecord & );

  static void fillDescriptions( edm::ConfigurationDescriptions & descriptions );
  
private:
  bool fromDDD_;
};

#endif




