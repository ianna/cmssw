#include <memory>
#include <string>
#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescriptionFiller.h"
#include "Geometry/ForwardGeometry/plugins/CastorHardcodeGeometryEP.h"
#include "Geometry/ForwardGeometry/plugins/ZdcHardcodeGeometryEP.h"

//define this as a plug-in
DEFINE_FWK_EVENTSETUP_MODULE(CastorHardcodeGeometryEP);
DEFINE_FWK_EVENTSETUP_MODULE(ZdcHardcodeGeometryEP);
