#ifndef DETECTOR_DESCRIPTION_DD_FILTERED_VIEW_H
#define DETECTOR_DESCRIPTION_DD_FILTERED_VIEW_H

// -*- C++ -*-
//
// Package:    DetectorDescription/DDFilteredView
// Class:      DDFilteredView
// 
/**\class DDFilteredView

 Description: Filtered View of a Tree

 Implementation:
     Filter criteria is defined in XML
*/
//
// Original Author:  Ianna Osborne
//         Created:  Wed, 30 Jan 2019 09:24:30 GMT
//
//
#include "DetectorDescription/DDCMS/interface/DDExpandedNode.h"

#include <vector>

namespace cms {

  class DDDetector;

  using Volume = dd4hep::Volume;
  using PlacedVolume = dd4hep::PlacedVolume;
    
  struct DDFilteredView {
    
    struct ExpandedNodes {
      std::vector<double> tags;
      std::vector<double> offsets;
      std::vector<int> copyNos;
    } nodes;
    
    DDFilteredView(const DDDetector*, const Volume);

    const PlacedVolume volume() const;
    
    //! The absolute translation of the current node
    const Double_t* trans() const;
    
    //! The absolute rotation of the current node
    const Double_t* rot() const;

    //! User specific data
    void mergedSpecifics(DDSpecParRefs const&);
    
    //! set the current node to the first child
    bool firstChild();

    //! set the current node to the first sibling
    bool firstSibling();

    //! set the current node to the next sibling
    bool nextSibling();

    //! set the current node to the next sub sibling
    bool subSibling();
    
    //! set the current node to the parent node ...
    bool parent();

    //! set current node to the next node in the filtered tree
    bool next(int);

    //! set current node to the child node in the filtered tree
    void down();

    //! set current node to the parent node in the filtered tree
    void up();
   
    //! pop current node
    void unCheckNode();

    //! extract shape parameters
    std::vector<double> extractParameters() const;

  private:

    bool accepted(std::string_view, std::string_view) const;
    bool accepted(std::vector<std::string_view> const&, std::string_view) const;
    std::vector<std::string_view> paths(const char*) const;
    bool addPath(std::string_view, TGeoNode* const);
    bool addNode(TGeoNode* const);
    void filter(DDSpecParRefs&, std::string_view, std::string_view) const;
    std::vector<std::string_view> vPathsTo(const DDSpecPar&, unsigned int) const;
    std::vector<std::string_view> tails(const std::vector<std::string_view>& fullPath) const;

    const DDSpecParRegistry* registry_;
    
    bool isRegex(std::string_view) const;
    int contains(std::string_view, std::string_view) const;
    std::string_view realTopName(std::string_view input) const;
    int copyNo(std::string_view input) const;
    std::string_view noCopyNo(std::string_view input) const;
    std::string_view noNamespace(std::string_view input) const;
    std::vector<std::string_view> split(std::string_view, const char*) const;
    bool acceptRegex(std::string_view, std::string_view) const;
    
    std::vector<std::string_view> topNodes_;
    std::vector<std::string_view> nextNodes_;
    std::vector<std::string_view> afterNextNodes_;
    std::vector<std::string_view> nextAfterNextNodes_;

    TGeoNode *node_ = nullptr;
    std::vector<TGeoIterator> it_;
  };
}

#endif
