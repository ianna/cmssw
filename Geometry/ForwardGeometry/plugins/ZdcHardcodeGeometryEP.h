#ifndef Geometry_ForwardGeometry_ZdcHardcodeGeometryEP_H
#define Geometry_ForwardGeometry_ZdcHardcodeGeometryEP_H 1

#include <memory>
#include "FWCore/Framework/interface/ESProducer.h"
#include "Geometry/ForwardGeometry/interface/ZdcTopology.h"

class CaloSubdetectorGeometry;
class ZDCGeometryRecord;
class ZdcHardcodeGeometryLoader;

namespace edm { class ParameterSet; }


class ZdcHardcodeGeometryEP : public edm::ESProducer 
{
   public:
      ZdcHardcodeGeometryEP(const edm::ParameterSet&);
      ~ZdcHardcodeGeometryEP();

      typedef std::shared_ptr<CaloSubdetectorGeometry> ReturnType;

      ReturnType produce( const ZDCGeometryRecord&   ) ;

   private:

      // ----------member data ---------------------------

      ZdcHardcodeGeometryLoader* m_loader ;

      ZdcTopology m_topology ;

      bool m_applyAlignment ;
};



#endif
