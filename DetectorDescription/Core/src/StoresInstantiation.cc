#include "DetectorDescription/Core/interface/DDRotationMatrix.h"
#include "DetectorDescription/Core/interface/DDReadMapType.h"
#include "DetectorDescription/Core/interface/Singleton.h"
#include "DetectorDescription/Core/interface/Singleton.icc"
#include "DetectorDescription/Core/interface/Store.h"
#include "DetectorDescription/Core/interface/DDAxes.h"
#include "DetectorDescription/Core/interface/DDName.h"
#include "DetectorDescription/Core/interface/DDRoot.h"
#include "DetectorDescription/Core/src/Division.h"
#include "DetectorDescription/Core/src/LogicalPart.h"
#include "DetectorDescription/Core/src/Material.h"
#include "DetectorDescription/Core/src/Solid.h"
#include "DetectorDescription/Core/src/Specific.h"
#include "DetectorDescription/Core/interface/ClhepEvaluator.h"
#include <map>
#include <string>
#include <utility>
#include <vector>

template class DDI::Singleton<AxesNames>;
template class DDI::Singleton<ClhepEvaluator>;
template class DDI::Singleton<DDRoot>;
template class DDI::Singleton<DDI::Store<DDName, std::vector<std::string>* > >;
template class DDI::Singleton<DDI::Store<DDName, std::string* > >;
template class DDI::Singleton<DDI::Store<DDName, DDI::Material*> >;
template class DDI::Singleton<DDI::Store<DDName, ReadMapType<double>* > >;
template class DDI::Singleton<DDI::Store<DDName, std::vector<double>* > >;
template class DDI::Singleton<DDI::Store<DDName, DDI::Specific*> >;
template class DDI::Singleton<DDI::Store<DDName, DDI::LogicalPart*> >;
template class DDI::Singleton<DDI::Store<DDName, DDI::Solid*> >;
template class DDI::Singleton<DDI::Store<DDName, double*> >;
template class DDI::Singleton<DDI::Store<DDName, DDRotationMatrix*> >;
template class DDI::Singleton<DDI::Store<DDName, DDI::Division*, DDI::Division*> >;
template class DDI::Singleton<std::map<std::pair<std::string, std::string>, int> >;
template class DDI::Singleton<std::map<std::string, std::vector<DDName> > >;
template class DDI::Singleton<std::vector<std::map<std::pair<std::string, std::string>, int>::const_iterator >  >;
namespace DDI {

  template<>
  Store<DDName,DDRotationMatrix* >::prep_type 
  Store<DDName,DDRotationMatrix* >::create(const name_type & n)
  {
    prep_type tmp = 0;
    auto result = reg_.insert(std::make_pair(n,tmp));
    if (result.second) {
      if (readOnly_) throw cms::Exception("DetectorDescriptionStore")<<" Store has been locked.  Illegal attempt to add " << n << " to a global store."; 
      // ELSE     
      result.first->second = new Rep_type(n, new DDRotationMatrix);
    }
    return result.first->second;    
  }
  
  template<>
  Store<DDName,DDRotationMatrix* >::prep_type 
  Store<DDName,DDRotationMatrix* >::create(const name_type & n, 
							   pimpl_type p)
  {			
    if (readOnly_) throw cms::Exception("DetectorDescriptionStore")<<" Store has been locked.  Illegal attempt to add " << n << " to a global store."; 
    // ELSE     
    prep_type tmp = 0;
    auto result = reg_.insert(std::make_pair(n,tmp));
    if (!result.second) {
      result.first->second->second = p;
    }
    else {
      result.first->second = new Rep_type(n,p);
    }
    return result.first->second;
  }
}
