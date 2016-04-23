/*
 * ndn-fw-cs-tag.cc
 *
 *  Created on: 2015年12月3日
 *      Author: zhuxd
 */

#include "ndn-fw-cs-tag.h"

namespace ns3 {
namespace ndn {

TypeId
FwCsTag::GetTypeId ()
{
  static TypeId tid = TypeId("ns3::ndn::FwCsTag")
    .SetParent<Tag>()
    .AddConstructor<FwCsTag>()
    ;
  return tid;
}

TypeId
FwCsTag::GetInstanceTypeId () const
{
  return FwCsTag::GetTypeId ();
}
/**/
uint32_t
FwCsTag::GetSerializedSize () const
{
  return sizeof(uint32_t);
}
/**/
void
FwCsTag::Serialize (TagBuffer i) const
{
  i.WriteU32 (csTag);
}

void
FwCsTag::Deserialize (TagBuffer i)
{
  csTag = i.ReadU32 ();
}

void
FwCsTag::Print (std::ostream &os) const
{
  os << csTag;
}

} // namespace ndn
} // namespace ns3





