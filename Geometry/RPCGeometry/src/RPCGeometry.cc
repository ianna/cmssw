/** Implementation of the Model for RPC Geometry
 *
 *  \author M. Maggi - INFN Bari
 */

#include <Geometry/RPCGeometry/interface/RPCGeometry.h>
#include <Geometry/CommonDetUnit/interface/GeomDet.h>
#include "FWCore/MessageLogger/interface/MessageLogger.h"

RPCGeometry::RPCGeometry(){}


RPCGeometry::~RPCGeometry()
{}  

const RPCGeometry::DetTypeContainer&  RPCGeometry::detTypes() const{
  return theRollTypes;
}

const RPCGeometry::DetContainer& RPCGeometry::detUnits() const{
  return theRolls;
}

const RPCGeometry::DetContainer& RPCGeometry::dets() const{
  return theDets;
}
  
const RPCGeometry::DetIdContainer& RPCGeometry::detUnitIds() const{
  return theRollIds;
}

const RPCGeometry::DetIdContainer& RPCGeometry::detIds() const{
  return theDetIds;
}

const std::shared_ptr< const GeomDet >
RPCGeometry::idToDetUnit( DetId id ) const{
  return std::static_pointer_cast< const GeomDet >( idToDet( id ));
}

const std::shared_ptr< const GeomDet >
RPCGeometry::idToDet( DetId id ) const{
  mapIdToDet::const_iterator i = theMap.find(id);
  if (i != theMap.end())
    return i->second;

  LogDebug("RPCGeometry")<<"Invalid DetID: no GeomDet associated "<< RPCDetId(id);

  return nullptr;   
}

const std::vector< std::shared_ptr< const RPCChamber >>&
RPCGeometry::chambers() const {
  return allChambers;
}

const std::vector< std::shared_ptr< const RPCRoll >>&
RPCGeometry::rolls() const{
  return allRolls;
}

const std::shared_ptr< const RPCChamber >
RPCGeometry::chamber( RPCDetId id ) const{
  return std::static_pointer_cast< const RPCChamber >( idToDet( id.chamberId()));
}

const std::shared_ptr< const RPCRoll >
RPCGeometry::roll(RPCDetId id) const{
  return std::static_pointer_cast< const RPCRoll >( idToDetUnit( id ));
}

void
RPCGeometry::add( std::shared_ptr< const RPCRoll > roll ) {
  theDets.emplace_back(roll);
  allRolls.emplace_back(roll);
  theRolls.emplace_back(roll);
  theRollIds.emplace_back(roll->geographicalId());
  theDetIds.emplace_back(roll->geographicalId());
  theRollTypes.emplace_back(&roll->type());
  theMap.insert(std::pair<DetId, std::shared_ptr< const GeomDet > >
		(roll->geographicalId(),roll));
}

void
RPCGeometry::add( std::shared_ptr< const RPCChamber > chamber ) {
  allChambers.emplace_back(chamber);
  theDets.emplace_back(chamber);
  theDetIds.emplace_back(chamber->geographicalId());
  theMap.insert(std::pair<DetId, std::shared_ptr< const GeomDet > >
		(chamber->geographicalId(),chamber));
}
