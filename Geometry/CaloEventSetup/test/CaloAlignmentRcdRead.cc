#include <memory>
#include <string>
#include <typeinfo>
#include <vector>
#include "CondFormats/Alignment/interface/AlignTransform.h"
#include "CondFormats/Alignment/interface/Alignments.h"
#include "CondFormats/AlignmentRecord/interface/EBAlignmentRcd.h"
#include "CondFormats/AlignmentRecord/interface/EEAlignmentRcd.h"
#include "CondFormats/AlignmentRecord/interface/ESAlignmentRcd.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/src/WorkerMaker.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescriptionFiller.h"
#include "Rtypeinfo.h"
#include "Utilities/General/interface/ClassName.h"

namespace edm { class Event; }
namespace edm { class EventSetup; }
namespace edm { class ParameterSet; }

class CaloAlignmentRcdRead : public edm::one::EDAnalyzer<>
{
public:

  explicit CaloAlignmentRcdRead( const edm::ParameterSet& /*iConfig*/ )
    :nEventCalls_(0) {}
  ~CaloAlignmentRcdRead() {}
  
  template<typename T>
  void dumpAlignments(const edm::EventSetup& evtSetup);

  void beginJob() override {}
  void analyze(edm::Event const& iEvent, edm::EventSetup const&) override;
  void endJob() override {}
  
private:

  unsigned int nEventCalls_;
};

template<typename T>
void CaloAlignmentRcdRead::dumpAlignments(const edm::EventSetup& evtSetup)
{
  edm::ESHandle<Alignments> alignments;
  evtSetup.get<T>().get(alignments);
  
  std::string recordName = Demangle(typeid(T).name())();

  LogDebug("CaloAlignmentRcdRead") << "Dumping alignments: " << recordName;

  for (std::vector<AlignTransform>::const_iterator i = alignments->m_align.begin();
       i != alignments->m_align.end();  
       ++i) {
    LogDebug("CaloAlignmentRcdRead") << "entry " << i->rawId() 
	      << " translation " << i->translation() 
	      << " angles " << i->rotation().eulerAngles();
  }
}

void CaloAlignmentRcdRead::analyze(const edm::Event& /*evt*/, const edm::EventSetup& evtSetup)
{
  if (nEventCalls_>0) {
    edm::LogWarning("CaloAlignmentRcdRead") << "Reading from DB to be done only once, "
	      << "set 'untracked PSet maxEvents = {untracked int32 input = 1}'.";

    return;
  }

  LogDebug("CaloAlignmentRcdRead") << "Reading from database in CaloAlignmentRcdRead::analyze...";
  
  dumpAlignments<EBAlignmentRcd>(evtSetup);
  dumpAlignments<EEAlignmentRcd>(evtSetup);
  dumpAlignments<ESAlignmentRcd>(evtSetup);

  LogDebug("CaloAlignmentRcdRead") << "done!";

  nEventCalls_++;
}

DEFINE_FWK_MODULE(CaloAlignmentRcdRead);
