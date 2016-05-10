#include <memory>
#include <string>
#include "DetectorDescription/Algorithm/interface/DDAlgorithmFactory.h"
#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescriptionFiller.h"
#include "FWCore/PluginManager/interface/PluginFactory.h"
#include "Geometry/EcalTestBeam/plugins/DDTBH4Algo.h"
#include "Geometry/EcalTestBeam/plugins/EcalTBGeometryBuilder.h"
#include "Geometry/EcalTestBeam/plugins/EcalTBHodoscopeGeometryEP.h"

DEFINE_EDM_PLUGIN (DDAlgorithmFactory, DDTBH4Algo, "TBH4:DDTBH4Algo");
DEFINE_FWK_EVENTSETUP_MODULE(EcalTBHodoscopeGeometryEP);
DEFINE_FWK_EVENTSETUP_MODULE(EcalTBGeometryBuilder);
