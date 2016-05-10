#ifndef GEOMETRY_ECALEVENTSETUP_ECALTBHODOSCOPEGEOMETRYEPEP_H
#define GEOMETRY_ECALEVENTSETUP_ECALTBHODOSCOPEGEOMETRYEPEP_H 1

#include <memory>
#include "FWCore/Framework/interface/ESProducer.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"

class EcalTBHodoscopeGeometryLoaderFromDDD;
class IdealGeometryRecord;

namespace edm { class ParameterSet; }

class EcalTBHodoscopeGeometryEP : public edm::ESProducer {
 public:
  EcalTBHodoscopeGeometryEP(const edm::ParameterSet&);
  ~EcalTBHodoscopeGeometryEP();
  
  typedef std::unique_ptr<CaloSubdetectorGeometry> ReturnType;
  
  ReturnType produce(const IdealGeometryRecord&);

 private:

  // ----------member data ---------------------------
  EcalTBHodoscopeGeometryLoaderFromDDD* loader_;
};



#endif
