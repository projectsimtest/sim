/*
 * ndn-fw-get-type-tag.h
 *
 *  Created on: 2015年12月6日
 *      Author: zhuxd
 */

#ifndef NDN_FW_GET_TYPE_TAG_H_
#define NDN_FW_GET_TYPE_TAG_H_

#include "ns3/tag.h"

namespace ns3 {
namespace ndn {

/**
 * @brief Packet tag that is used to track hop count for Interest-Data pairs
 */
class FwGetTypeTag : public Tag
{
public:
  static TypeId
  GetTypeId (void);

  /**
   * @brief Default constructor
   * 数据包发送时将c_copyTag置为2，使第一个接收到数据包的节点可以缓存该数据包
   */
  FwGetTypeTag () : getTypeTag (1) { };

  /**
   * @brief Destructor
   */
  ~FwGetTypeTag () { }

  /**
   * @brief Increment hop count
   * 第一个接收到数据包的节点缓存数据后，调用Increment()，目的是到达cunsumer之前的节点(除第一个节点)不缓存该数据
   */
  void
  Decrement () { getTypeTag --; }
  

  /**
   * @brief Get value of hop count
   */
  int
  Get () const { return getTypeTag; }

  void
  Set(int type) {getTypeTag = type;}

  ////////////////////////////////////////////////////////
  // from ObjectBase
  ////////////////////////////////////////////////////////
  virtual TypeId
  GetInstanceTypeId () const;

  ////////////////////////////////////////////////////////
  // from Tag
  ////////////////////////////////////////////////////////
/**/
  virtual uint32_t
  GetSerializedSize () const;

  virtual void
  Serialize (TagBuffer i) const;

  virtual void
  Deserialize (TagBuffer i);

  virtual void
  Print (std::ostream &os) const;

private:
  //节点用来判断是否缓存内容的变量，true节点将数据缓存，false则不缓存数据
  int getTypeTag;
};

} // namespace ndn
} // namespace ns3



#endif /* NDN_FW_JUDGE_TAG_H_ */

