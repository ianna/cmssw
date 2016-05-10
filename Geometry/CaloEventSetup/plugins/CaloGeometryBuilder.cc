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

#include "Geometry/CaloEventSetup/plugins/CaloGeometryBuilder.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "DataFormats/HcalDetId/interface/HcalCastorDetId.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"
#include "DataFormats/HcalDetId/interface/HcalZDCDetId.h"
#include "FWCore/MessageLogger/interface/ErrorObj.icc"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/EcalAlgo/interface/EcalBarrelGeometry.h"
#include "Geometry/EcalAlgo/interface/EcalEndcapGeometry.h"
#include "Geometry/EcalAlgo/interface/EcalPreshowerGeometry.h"
#include "Geometry/ForwardGeometry/interface/CastorGeometry.h"
#include "Geometry/ForwardGeometry/interface/ZdcGeometry.h"
#include "Geometry/HcalTowerAlgo/interface/CaloTowerGeometry.h"
#include "Geometry/HcalTowerAlgo/interface/HcalGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/Records/interface/CaloTowerGeometryRecord.h"
#include "Geometry/Records/interface/CastorGeometryRecord.h"
#include "Geometry/Records/interface/EcalBarrelGeometryRecord.h"
#include "Geometry/Records/interface/EcalEndcapGeometryRecord.h"
#include "Geometry/Records/interface/EcalPreshowerGeometryRecord.h"
#include "Geometry/Records/interface/HcalGeometryRecord.h"
#include "Geometry/Records/interface/ZDCGeometryRecord.h"

class CaloSubdetectorGeometry;

namespace edm { class ParameterSet; }

CaloGeometryBuilder::CaloGeometryBuilder( const edm::ParameterSet& iConfig )
{
   //the following line is needed to tell the framework what
   // data is being produced
   setWhatProduced( this, 
		    &CaloGeometryBuilder::produceAligned );

   //now do what ever other initialization is needed
   
   theCaloList = iConfig.getParameter< std::vector<std::string> >("SelectedCalos");
   if ( theCaloList.size() == 0 ) throw cms::Exception("Configuration") 
      << "No calorimeter specified for geometry, aborting";
}

// ------------ method called to produce the data  ------------

CaloGeometryBuilder::ReturnType
CaloGeometryBuilder::produceAligned( const CaloGeometryRecord& iRecord )
{
   edm::ESHandle< CaloSubdetectorGeometry > pG;

   ReturnType pCalo ( new CaloGeometry() ) ;

   // loop on selected calorimeters

   for ( std::vector<std::string>::const_iterator ite ( theCaloList.begin() ) ;
	 ite != theCaloList.end(); ++ite ) 
   {
      // look for HCAL parts
      // assume 'HCAL' for all of HCAL.  
      if ( (*ite) == HcalGeometry::producerTag() ) 
      {
	 edm::LogInfo("CaloGeometryBuilder") << "Building HCAL reconstruction geometry";

	 iRecord.getRecord< HcalGeometryRecord >().get( HcalGeometry::producerTag(), pG );  
	 pCalo->setSubdetGeometry( DetId::Hcal, HcalBarrel , pG.product() );
	 pCalo->setSubdetGeometry( DetId::Hcal, HcalEndcap , pG.product() );
	 pCalo->setSubdetGeometry( DetId::Hcal, HcalOuter  , pG.product() );
	 pCalo->setSubdetGeometry( DetId::Hcal, HcalForward, pG.product() );
      }
      else if ( (*ite) == ZdcGeometry::producerTag() ) 
      {
	 edm::LogInfo("CaloGeometryBuilder") << "Building ZDC reconstruction geometry";
	 iRecord.getRecord< ZDCGeometryRecord >().get( ZdcGeometry::producerTag(), pG ); 
	 pCalo->setSubdetGeometry( DetId::Calo, HcalZDCDetId::SubdetectorId,pG.product());
      }
      else if ( (*ite) == CastorGeometry::producerTag() ) 
      {
	 edm::LogInfo("CaloGeometryBuilder") << "Building CASTOR reconstruction geometry";
	 iRecord.getRecord< CastorGeometryRecord >().get( CastorGeometry::producerTag(), pG ); 
	 pCalo->setSubdetGeometry( DetId::Calo, HcalCastorDetId::SubdetectorId,pG.product());
      }
      // look for Ecal Barrel
      else if ( (*ite) == EcalBarrelGeometry::producerTag() ) 
      {
	 edm::LogInfo("CaloGeometryBuilder") << "Building EcalBarrel reconstruction geometry";
	 iRecord.getRecord<EcalBarrelGeometryRecord>().get( EcalBarrelGeometry::producerTag(), pG ); 
	 pCalo->setSubdetGeometry(DetId::Ecal,EcalBarrel,pG.product());
      }
      // look for Ecal Endcap
      else if ( (*ite) == EcalEndcapGeometry::producerTag() ) 
      {
	 edm::LogInfo("CaloGeometryBuilder") << "Building EcalEndcap reconstruction geometry";
	 iRecord.getRecord<EcalEndcapGeometryRecord>().get( EcalEndcapGeometry::producerTag(), pG ); 
	 pCalo->setSubdetGeometry(DetId::Ecal,EcalEndcap,pG.product());
      }
      // look for Ecal Preshower
      else if ( (*ite) == EcalPreshowerGeometry::producerTag() ) 
      {
	 edm::LogInfo("CaloGeometryBuilder") << "Building EcalPreshower reconstruction geometry";
	 iRecord.getRecord<EcalPreshowerGeometryRecord>().get(EcalPreshowerGeometry::producerTag(), pG); 
	 pCalo->setSubdetGeometry(DetId::Ecal,EcalPreshower,pG.product());
      }
      // look for TOWER parts
      else if ( (*ite) == CaloTowerGeometry::producerTag() ) 
      {
	 edm::LogInfo("CaloGeometryBuilder") << "Building TOWER reconstruction geometry";
	 iRecord.getRecord<CaloTowerGeometryRecord>().get(CaloTowerGeometry::producerTag(),pG);
	 pCalo->setSubdetGeometry(DetId::Calo,1,pG.product());
      }
      else 
      {
	 edm::LogWarning("CaloGeometryBuilder") 
	    << "Reconstrcution geometry requested for a not implemented sub-detector: " 
	    << (*ite); 
      }
   }
   return pCalo ;
}
