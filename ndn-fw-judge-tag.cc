/*
 * ndn-fw-judge-tag.cc
 *
 *  Created on: 2015年12月3日
 *      Author: zhuxd
 */

#include "ndn-fw-judge-tag.h"

namespace ns3 {
namespace ndn {

TypeId
FwJudgeTag::GetTypeId ()
{
  static TypeId tid = TypeId("ns3::ndn::FwJudgeTag")
    .SetParent<Tag>()
    .AddConstructor<FwJudgeTag>()
    ;
  return tid;
}

TypeId
FwJudgeTag::GetInstanceTypeId () const
{
  return FwJudgeTag::GetTypeId ();
}
/**/
uint32_t
FwJudgeTag::GetSerializedSize () const
{
  return sizeof(uint32_t);
}
/**/
void
FwJudgeTag::Serialize (TagBuffer i) const
{
  i.WriteU32 (judgeTag);
}

void
FwJudgeTag::Deserialize (TagBuffer i)
{
  judgeTag = i.ReadU32 ();
}

void
FwJudgeTag::Print (std::ostream &os) const
{
  os << judgeTag;
}

} // namespace ndn
} // namespace ns3





