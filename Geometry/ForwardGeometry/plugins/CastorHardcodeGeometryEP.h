#ifndef Geometry_ForwardGeometry_CastorHardcodeGeometryEP_H
#define Geometry_ForwardGeometry_CastorHardcodeGeometryEP_H 1

#include <memory>
#include "FWCore/Framework/interface/ESProducer.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"

class CastorGeometryRecord;
class CastorHardcodeGeometryLoader;

namespace edm { class ParameterSet; }

class CastorHardcodeGeometryEP : public edm::ESProducer {
   public:
      CastorHardcodeGeometryEP(const edm::ParameterSet&);
      ~CastorHardcodeGeometryEP();

      typedef std::unique_ptr<CaloSubdetectorGeometry> ReturnType;

      ReturnType produce(const CastorGeometryRecord&);
private:
      // ----------member data ---------------------------
  CastorHardcodeGeometryLoader* loader_;
};



#endif
