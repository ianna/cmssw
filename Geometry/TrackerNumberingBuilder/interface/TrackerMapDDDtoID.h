#ifndef TrackerMapDDDtoID_H
#define TrackerMapDDDtoID_H

#include <stdint.h>
#include <map>
#include <vector>
#include "Geometry/TrackerNumberingBuilder/interface/GeometricDet.h"

class TrackerMapDDDtoID {
 public:

  typedef GeometricDet::nav_type nav_type;
  typedef std::map<nav_type,uint32_t> MapType;
  typedef std::map<uint32_t,nav_type> RevMapType;

  TrackerMapDDDtoID(const GeometricDet* iDet);
  ~TrackerMapDDDtoID(){clear();}

  //! calculate the id of a given node
  unsigned int id(const nav_type &) const;

  nav_type const & navType(uint32_t) const;

  std::vector<nav_type> const & allNavTypes() const;
  void clear();
 private:
  void buildAll(const GeometricDet*);
  void buildAllStep2(const GeometricDet*);

  std::vector<nav_type> navVec;
  MapType path2id_;
  RevMapType revpath2id_;
};

//typedef Singleton<TrackerMapDDDtoID> TkMapDDDtoID;

#endif
