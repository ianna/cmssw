// -*- C++ -*-
//
// Package:    RPCGEO2
// Class:      RPCGEO2
// 
/**\class RPCGEO2 RPCGEO2.cc rpcgeo/RPCGEO2/src/RPCGEO2.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  pts/91
//         Created:  Wed Sep 26 17:08:29 CEST 2007
//
//

#include <DataFormats/MuonDetId/interface/RPCDetId.h>
#include <Geometry/RPCGeometry/interface/RPCGeomServ.h>
#include <Geometry/RPCGeometry/interface/RPCGeometry.h>
#include <Geometry/Records/interface/MuonGeometryRecord.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "DataFormats/GeometrySurface/interface/Plane.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/src/WorkerMaker.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescriptionFiller.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/CommonDetUnit/interface/TrackingGeometry.h"
#include "Geometry/RPCGeometry/interface/RPCChamber.h"
#include "Geometry/RPCGeometry/interface/RPCRoll.h"

namespace edm { class Event; }
namespace edm { class ParameterSet; }

class RPCGEO2 : public edm::one::EDAnalyzer<>
{
public:
  explicit RPCGEO2(const edm::ParameterSet&);
  ~RPCGEO2();

  void beginJob() override {}
  void analyze(edm::Event const& iEvent, edm::EventSetup const&) override;
  void endJob() override {}
};

RPCGEO2::RPCGEO2(const edm::ParameterSet& /*iConfig*/){
}

RPCGEO2::~RPCGEO2()
{}

// ------------ method called to for each event  ------------
void
RPCGEO2::analyze(const edm::Event& /*iEvent*/, const edm::EventSetup& iSetup)
{
   using namespace edm;

   std::cout <<" Getting the RPC Geometry"<<std::endl;
   edm::ESHandle<RPCGeometry> rpcGeo;
   iSetup.get<MuonGeometryRecord>().get(rpcGeo);

   for (TrackingGeometry::DetContainer::const_iterator it=rpcGeo->dets().begin();it<rpcGeo->dets().end();it++){
     if( dynamic_cast< const RPCChamber* >( *it ) != 0 ){
       const RPCChamber* ch = dynamic_cast< const RPCChamber* >( *it ); 
       std::vector< const RPCRoll*> roles = (ch->rolls());
       
       for(std::vector<const RPCRoll*>::const_iterator r = roles.begin();r != roles.end(); ++r){
	 RPCDetId rpcId = (*r)->id();
	 RPCGeomServ rpcsrv(rpcId);
	 if (rpcId.region()==0){ 
	   const BoundPlane & RPCSurface = (*r)->surface();
	   GlobalPoint CenterPointRollGlobal = RPCSurface.toGlobal(LocalPoint(0,0,0));
	   std::cout<<rpcsrv.name()<<" "<<CenterPointRollGlobal.x()<<" "<<CenterPointRollGlobal.y()<<" "<<CenterPointRollGlobal.z()<<std::endl;
	   GlobalPoint i = RPCSurface.toGlobal(LocalPoint(1,0,0));
	   GlobalPoint j = RPCSurface.toGlobal(LocalPoint(0,1,0));
	   std::cout<<" i "<<i.x()<<" "<<i.y()<<" "<<i.z()<<std::endl;
	   std::cout<<" j "<<j.x()<<" "<<j.y()<<" "<<j.z()<<std::endl;

	 }else{
	   const BoundPlane & RPCSurface = (*r)->surface();
	   GlobalPoint CenterPointRollGlobal = RPCSurface.toGlobal(LocalPoint(0,0,0));
	   std::cout<<rpcsrv.name()<<" "<<CenterPointRollGlobal.x()<<" "<<CenterPointRollGlobal.y()<<" "<<CenterPointRollGlobal.z()<<std::endl;
	 }
       }
     }
   }
}

//define this as a plug-in
DEFINE_FWK_MODULE(RPCGEO2);
