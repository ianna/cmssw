#include "TrackerParametersESModule.h"
#include <iostream>
#include <string>
#include "CondFormats/GeometryObjects/interface/PTrackerParameters.h"
#include "FWCore/Framework/interface/ESTransientHandle.h"
#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescriptionFiller.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/Records/interface/PTrackerParametersRcd.h"
#include "Geometry/TrackerGeometryBuilder/interface/TrackerParametersFromDD.h"

class DDCompactView;

namespace edm { class ParameterSet; }

TrackerParametersESModule::TrackerParametersESModule( const edm::ParameterSet& )
{
  edm::LogInfo("TRACKER") << "TrackerParametersESModule::TrackerParametersESModule";

  setWhatProduced(this);
}

TrackerParametersESModule::~TrackerParametersESModule()
{ 
}

void
TrackerParametersESModule::fillDescriptions( edm::ConfigurationDescriptions & descriptions ) 
{
  edm::ParameterSetDescription desc;
  descriptions.add( "trackerParameters", desc );
}

TrackerParametersESModule::ReturnType
TrackerParametersESModule::produce( const PTrackerParametersRcd& iRecord )
{
  //edm::LogInfo("TrackerParametersESModule")
  std::cout <<  "TrackerParametersESModule::produce(const PTrackerParametersRcd& iRecord)" << std::endl;
  edm::ESTransientHandle<DDCompactView> cpv;
  iRecord.getRecord<IdealGeometryRecord>().get( cpv );
    
  PTrackerParameters* ptp = new PTrackerParameters();
  TrackerParametersFromDD builder;
  builder.build( &(*cpv), *ptp );

  return ReturnType( ptp ) ;
}

DEFINE_FWK_EVENTSETUP_MODULE( TrackerParametersESModule);
