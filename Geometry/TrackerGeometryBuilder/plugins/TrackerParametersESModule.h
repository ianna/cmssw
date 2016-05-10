#ifndef Geometry_TrackerGeometryBuilder_TrackerParametersESModule_H
#define Geometry_TrackerGeometryBuilder_TrackerParametersESModule_H

#include <memory>
#include "FWCore/Framework/interface/ESProducer.h"

class PTrackerParameters;
class PTrackerParametersRcd;

namespace edm { class ConfigurationDescriptions; }
namespace edm { class ParameterSet; }

class  TrackerParametersESModule: public edm::ESProducer
{
 public:
  TrackerParametersESModule( const edm::ParameterSet & );
  ~TrackerParametersESModule( void );

  typedef std::shared_ptr<PTrackerParameters> ReturnType;

  static void fillDescriptions( edm::ConfigurationDescriptions & );
  
  ReturnType produce( const PTrackerParametersRcd & );
};

#endif
