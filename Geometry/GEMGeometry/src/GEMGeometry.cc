/** Implementation of the Model for GEM Geometry
 *
 *  \author M. Maggi - INFN Bari
 */

#include "Geometry/GEMGeometry/interface/GEMGeometry.h"
#include "Geometry/CommonDetUnit/interface/GeomDet.h"

GEMGeometry::GEMGeometry() {}

GEMGeometry::~GEMGeometry() {}  

const GEMGeometry::DetTypeContainer&
GEMGeometry::detTypes() const {
  return theEtaPartitionTypes;
}

const GEMGeometry::DetContainer&
GEMGeometry::detUnits() const {
  return theEtaPartitions;
}

const GEMGeometry::DetContainer&
GEMGeometry::dets() const {
  return theDets;
}

const GEMGeometry::DetIdContainer&
GEMGeometry::detUnitIds() const {
  return theEtaPartitionIds;
}

const GEMGeometry::DetIdContainer&
GEMGeometry::detIds() const {
  return theDetIds;
}

const std::shared_ptr< const GeomDet >
GEMGeometry::idToDetUnit( DetId id ) const {
  return idToDet( id );
}

const std::shared_ptr< const GeomDet >
GEMGeometry::idToDet( DetId id ) const {
  mapIdToDet::const_iterator i = theMap.find(id);
  return (i != theMap.end()) ? i->second : nullptr;
}

const std::vector< std::shared_ptr< const GEMRegion > >&
GEMGeometry::regions() const {
  return allRegions;
}

const std::vector< std::shared_ptr< const GEMStation > >&
GEMGeometry::stations() const {
  return allStations;
}

const std::vector< std::shared_ptr< const GEMRing > >&
GEMGeometry::rings() const {
  return allRings;
}

const std::vector< std::shared_ptr< const GEMSuperChamber > >&
GEMGeometry::superChambers() const {
  return allSuperChambers;
}

const std::vector< std::shared_ptr< const GEMChamber > >&
GEMGeometry::chambers() const {
  return allChambers;
}

const std::vector< std::shared_ptr< const GEMEtaPartition > >&
GEMGeometry::etaPartitions() const{
  return allEtaPartitions;
}

const std::shared_ptr< const GEMRegion >
GEMGeometry::region( int re ) const {
  for (auto region : allRegions) {
    if (re != region->region()) continue;
    return region;
  }
  return nullptr;
}

const std::shared_ptr< const GEMStation >
GEMGeometry::station( int re, int st ) const { 
  for (auto station : allStations) {
    if (re != station->region() || st != station->station()) continue;
    return station;
  }
  return nullptr;
}

const std::shared_ptr< const GEMRing >
GEMGeometry::ring(int re, int st, int ri) const {
  for (auto ring : allRings) {
    if (re != ring->region() || st != ring->station() || ri != ring->ring()) continue;	
    return ring;
  }
  return nullptr;
}

const std::shared_ptr< const GEMSuperChamber >
GEMGeometry::superChamber( GEMDetId id ) const {
  return std::static_pointer_cast< const GEMSuperChamber >( idToDet( id.superChamberId()));
}

const std::shared_ptr< const GEMChamber >
GEMGeometry::chamber( GEMDetId id ) const { 
  return std::static_pointer_cast< const GEMChamber >( idToDet( id.chamberId()));
}

const std::shared_ptr< const GEMEtaPartition >
GEMGeometry::etaPartition( GEMDetId id ) const {
  return std::static_pointer_cast< const GEMEtaPartition >( idToDetUnit( id ));
}

void
GEMGeometry::add( std::shared_ptr< const GEMRegion > region ) {
  allRegions.emplace_back( region );
}

void
GEMGeometry::add( std::shared_ptr< const GEMStation > station ) {
  allStations.emplace_back( station );
}

void
GEMGeometry::add( std::shared_ptr< const GEMRing > ring ) {
  allRings.emplace_back(ring);
}

void
GEMGeometry::add( std::shared_ptr< const GEMSuperChamber > superChamber ) {
  allSuperChambers.emplace_back(superChamber);
  theDets.emplace_back(superChamber);
  theDetIds.emplace_back(superChamber->geographicalId());
  theMap.insert(std::pair<DetId, std::shared_ptr< const GeomDet > >
  		(superChamber->geographicalId(),superChamber));
}

void
GEMGeometry::add( std::shared_ptr< const GEMEtaPartition > etaPartition ) {
  theDets.emplace_back(etaPartition);
  allEtaPartitions.emplace_back(etaPartition);
  theEtaPartitions.emplace_back(etaPartition);
  theEtaPartitionIds.emplace_back(etaPartition->geographicalId());
  theDetIds.emplace_back(etaPartition->geographicalId());
  theEtaPartitionTypes.emplace_back(&etaPartition->type());
  theMap.insert(std::pair<DetId, std::shared_ptr< const GeomDet > >
		(etaPartition->geographicalId(),etaPartition));
}

void
GEMGeometry::add( std::shared_ptr< const GEMChamber > chamber ) {
  allChambers.emplace_back(chamber);
  theDets.emplace_back(chamber);
  theDetIds.emplace_back(chamber->geographicalId());
  theMap.insert(std::pair<DetId, std::shared_ptr< const GeomDet > >
		(chamber->geographicalId(),chamber));
}
