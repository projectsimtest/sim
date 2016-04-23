/*
 * ndn-fw-get-type-tag.cc
 *
 *  Created on: 2015年12月6日
 *      Author: zhuxd
 */

#include "ndn-fw-get-type-tag.h"

namespace ns3 {
namespace ndn {

TypeId
FwGetTypeTag::GetTypeId ()
{
  static TypeId tid = TypeId("ns3::ndn::FwGetTypeTag")
    .SetParent<Tag>()
    .AddConstructor<FwGetTypeTag>()
    ;
  return tid;
}

TypeId
FwGetTypeTag::GetInstanceTypeId () const
{
  return FwGetTypeTag::GetTypeId ();
}
/**/
uint32_t
FwGetTypeTag::GetSerializedSize () const
{
  return sizeof(uint32_t);
}
/**/
void
FwGetTypeTag::Serialize (TagBuffer i) const
{
  i.WriteU32 (getTypeTag);
}

void
FwGetTypeTag::Deserialize (TagBuffer i)
{
  getTypeTag = i.ReadU32 ();
}

void
FwGetTypeTag::Print (std::ostream &os) const
{
  os << getTypeTag;
}

} // namespace ndn
} // namespace ns3





