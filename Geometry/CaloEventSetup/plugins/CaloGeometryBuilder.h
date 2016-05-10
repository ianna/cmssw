// -*- C++ -*-
//
// Package:    CaloGeometryBuilder
// Class:      CaloGeometryBuilder
// 
/**\class CaloGeometryBuilder CaloGeometryBuilder.h tmp/CaloGeometryBuilder/interface/CaloGeometryBuilder.h

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
#include <string>
#include <vector>
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/ESProducer.h"

class CaloGeometry;
class CaloGeometryRecord;
class CaloSubdetectorGeometry;

namespace edm { class ParameterSet; }

class CaloGeometryBuilder : public edm::ESProducer 
{
   public:

      typedef std::shared_ptr<CaloGeometry> ReturnType;

      typedef edm::ESHandle<CaloSubdetectorGeometry> SubdType ;

      CaloGeometryBuilder( const edm::ParameterSet& iConfig ) ;

      virtual ~CaloGeometryBuilder() {} ;

      ReturnType produceAligned( const CaloGeometryRecord&  iRecord ) ;

   private:
      // ----------member data ---------------------------
      
      std::vector<std::string> theCaloList;
};

