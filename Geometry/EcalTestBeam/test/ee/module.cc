#include <memory>
#include <string>
#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescriptionFiller.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "Geometry/EcalAlgo/interface/EcalEndcapGeometry.h"
#include "Geometry/EcalTestBeam/test/ee/CaloGeometryEPtest.h"

template class CaloGeometryEPtest< EcalEndcapGeometry    > ;

typedef CaloGeometryEPtest< EcalEndcapGeometry > testEcalEndcapGeometryEP ;
DEFINE_FWK_EVENTSETUP_MODULE(testEcalEndcapGeometryEP);
