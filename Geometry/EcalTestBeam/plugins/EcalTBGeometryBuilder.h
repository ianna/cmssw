// -*- C++ -*-
//
// Package:    EcalTBGeometryBuilder
// Class:      EcalTBGeometryBuilder
// 
/**\class EcalTBGeometryBuilder EcalTBGeometryBuilder.h tmp/EcalTBGeometryBuilder/interface/EcalTBGeometryBuilder.h

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Jeremiah Mans
//         Created:  Mon Oct  3 11:35:27 CDT 2005
//
//

#include <memory>
#include "FWCore/Framework/interface/ESProducer.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"

class IdealGeometryRecord;

namespace edm { class ParameterSet; }

class EcalTBGeometryBuilder : public edm::ESProducer {
   public:
  EcalTBGeometryBuilder(const edm::ParameterSet&);
  ~EcalTBGeometryBuilder();

  typedef std::unique_ptr<CaloGeometry> ReturnType;

  ReturnType produce(const IdealGeometryRecord&);
private:
      // ----------member data ---------------------------
};

