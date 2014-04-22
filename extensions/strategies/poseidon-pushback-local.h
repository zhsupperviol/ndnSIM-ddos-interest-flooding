#ifndef POSEIDON_PUSHBACK_LOCAL_H
#define POSEIDON_PUSHBACK_LOCAL_H

#include <ns3/event-id.h>

#include "stats.h"

namespace ns3 {
namespace ndn {
namespace fw {

    /**
 * \ingroup ndn
 * \brief Poseidon-Pushback-Local-Strategy based on article: "Poseidon: Mitigating Interest Flooding DDoS Attacks in Named Data Networking"
 */
template<class Parent>
class PoseidonPushbackLocal :
    public Stats<Parent>
{
private:
  typedef Stats<Parent> super;

public:
 
  static TypeId
  GetTypeId ();

  PoseidonPushbackLocal ()
  {
  }

  static std::string
  GetLogName ();
  
  virtual void
  OnInterest (Ptr<Face> face,
              Ptr<Interest> interest);

  virtual void
  OnData (Ptr<Face> inFace,
            Ptr<Data> data);
    
  virtual void
  AddFace (Ptr<Face> face);
  
private:

  int
  IdToIndex (uint32_t id);

  uint32_t
  IntervalpSize (int index);

  uint32_t
  IntervaloSize (int index);

  virtual void
  OutputPitSize ();

  virtual void
  OutputSatisfied ();
  
  virtual void
  OutputData ();

  void
  AnnounceLimits ();

protected:

  virtual void
  DoDispose ();
 
  virtual void
  NotifyNewAggregate ();
   
private:

  static LogComponent g_log;

  uint32_t m_virtualPayloadSize;

	bool first = true, firstAnn = true, limitedFace[50], firstTime[50],firstMeasureData[50], firstMeasureInterest[50], measureData[50], measureInterests[50];

	double startInterest, startData, ConsumerInterests, ConsumerData;

    	int cIterator = 0, interestInt1[50],interestInt2[50], dataInt1[50], dataInt2[50], pSizeInt1[50], pSizeInt2[50];

	int incomeData[50], incomeInterest[50], incomeDataRouter, dropIt[50];

	uint32_t  pSizeL, omegaSize, scale = 2, omegaThreshold[50], peThreshold[50], FaceID[50];
};


} // namespace fw
} // namespace ndn
} // namespace ns3

#endif // POSEIDON_PUSHBACK_LOCAL_H
