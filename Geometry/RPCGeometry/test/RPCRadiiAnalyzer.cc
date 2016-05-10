/** Derived from DTRadiiAnalyzer by Nicola Amapane
 *
 *  \author M. Maggi - INFN Bari
 */

#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/Framework/interface/EventSetup.h>
#include <FWCore/Framework/interface/MakerMacros.h>
#include <FWCore/Framework/interface/one/EDAnalyzer.h>
#include <Geometry/Records/interface/MuonGeometryRecord.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometryVector/interface/Phi.h"
#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "FWCore/Framework/src/WorkerMaker.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescriptionFiller.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"
#include "Geometry/CommonDetUnit/interface/TrackingGeometry.h"
#include "Geometry/RPCGeometry/interface/RPCChamber.h"
#include "Geometry/RPCGeometry/interface/RPCGeomServ.h"
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/RPCGeometry/interface/RPCRoll.h"
#include "Geometry/RPCGeometry/interface/RPCRollSpecs.h"

namespace edm { class Event; }
namespace edm { class ParameterSet; }

using namespace std;

class RPCRadiiAnalyzer : public edm::one::EDAnalyzer<> {

 public: 
  RPCRadiiAnalyzer( const edm::ParameterSet& pset);

  ~RPCRadiiAnalyzer();

  void beginJob() override {}
  void analyze(edm::Event const& iEvent, edm::EventSetup const&) override;
  void endJob() override {}
 
  const std::string& myName() { return myName_;}

 private: 

  const int dashedLineWidth_;
  const std::string dashedLine_;
  const std::string myName_;
  std::ofstream ofos;
};

RPCRadiiAnalyzer::RPCRadiiAnalyzer( const edm::ParameterSet& /*iConfig*/ )
  : dashedLineWidth_(104), dashedLine_( std::string(dashedLineWidth_, '-') ), 
    myName_( "RPCRadiiAnalyzer" ) 
{ 
  ofos.open("MytestOutput.out"); 
  std::cout <<"======================== Opening output file"<< std::endl;
}


RPCRadiiAnalyzer::~RPCRadiiAnalyzer() 
{
  ofos.close();
  std::cout <<"======================== Closing output file"<< std::endl;
}

void
RPCRadiiAnalyzer::analyze( const edm::Event& /*iEvent*/, const edm::EventSetup& iSetup )
{
  edm::ESHandle<RPCGeometry> pDD;
  iSetup.get<MuonGeometryRecord>().get( pDD );     

  std::cout << myName() << ": Analyzer..." << std::endl;
  std::cout << "start " << dashedLine_ << std::endl;


  std::cout << " Geometry node for RPCGeom is  " << &(*pDD) << std::endl;   
  cout << " I have "<<pDD->detTypes().size()    << " detTypes" << endl;
  cout << " I have "<<pDD->detUnits().size()    << " detUnits" << endl;
  cout << " I have "<<pDD->dets().size()        << " dets" << endl;
  cout << " I have "<<pDD->rolls().size()       << " rolls" << endl;
  cout << " I have "<<pDD->chambers().size()    << " chambers" << endl;
  
  std::cout << myName() << ": Begin iteration over geometry..." << std::endl;
  std::cout << "iter " << dashedLine_ << std::endl;
  
  const double dPi = 3.14159265358;
  const double radToDeg = 180. / dPi; //@@ Where to get pi from?
  
  
  for(TrackingGeometry::DetContainer::const_iterator it = pDD->dets().begin(); it != pDD->dets().end(); it++){

//      //----------------------- RPCCHAMBER TEST -------------------------------------------------------

    if( dynamic_cast< const RPCChamber* >( *it ) != 0 ){
      const RPCChamber* ch = dynamic_cast< const RPCChamber* >( *it ); 
      
      
      //RPCDetId detId=ch->id();
      
      std::vector< const RPCRoll*> rolls = (ch->rolls());
      for(std::vector<const RPCRoll*>::iterator r = rolls.begin();
	  r != rolls.end(); ++r){
	
	if((*r)->id().region() == -1 &&
	   (*r)->id().station() > 0)// &&
	   //	   (*r)->id().ring() == 2)
	  {
	    //	    std::cout<<"RPCDetId = "<<(*r)->id()<<std::endl;
	    RPCGeomServ geosvc((*r)->id()); 
	    LocalPoint centre(0.,0.,0.);
	    GlobalPoint gc = (*r)->toGlobal(centre);
	    double phic = double(gc.phi())*radToDeg;
	    double radii = double(gc.perp());
	    std::cout <<geosvc.name()<<" phi="<<phic
		      <<" r="<<radii
		      <<" detName "<<(*r)->specs()->detName()
		      <<" s="<<(*r)->id().sector()<<" subs="<<(*r)->id().subsector()
		      <<std::endl;
	  }
      }
       
       
    }
  }
    std::cout << dashedLine_ << " end" << std::endl;
}

//define this as a plug-in
#include <FWCore/Framework/interface/MakerMacros.h>
DEFINE_FWK_MODULE(RPCRadiiAnalyzer); 
