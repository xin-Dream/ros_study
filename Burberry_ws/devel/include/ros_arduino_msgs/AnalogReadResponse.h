// Generated by gencpp from file ros_arduino_msgs/AnalogReadResponse.msg
// DO NOT EDIT!


#ifndef ROS_ARDUINO_MSGS_MESSAGE_ANALOGREADRESPONSE_H
#define ROS_ARDUINO_MSGS_MESSAGE_ANALOGREADRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_arduino_msgs
{
template <class ContainerAllocator>
struct AnalogReadResponse_
{
  typedef AnalogReadResponse_<ContainerAllocator> Type;

  AnalogReadResponse_()
    : value(0)  {
    }
  AnalogReadResponse_(const ContainerAllocator& _alloc)
    : value(0)  {
  (void)_alloc;
    }



   typedef uint16_t _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> const> ConstPtr;

}; // struct AnalogReadResponse_

typedef ::ros_arduino_msgs::AnalogReadResponse_<std::allocator<void> > AnalogReadResponse;

typedef boost::shared_ptr< ::ros_arduino_msgs::AnalogReadResponse > AnalogReadResponsePtr;
typedef boost::shared_ptr< ::ros_arduino_msgs::AnalogReadResponse const> AnalogReadResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator1> & lhs, const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator2> & rhs)
{
  return lhs.value == rhs.value;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator1> & lhs, const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_arduino_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6e68bf91459258a84dab807f5c768df7";
  }

  static const char* value(const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6e68bf91459258a8ULL;
  static const uint64_t static_value2 = 0x4dab807f5c768df7ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_arduino_msgs/AnalogReadResponse";
  }

  static const char* value(const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint16 value\n"
"\n"
;
  }

  static const char* value(const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AnalogReadResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_arduino_msgs::AnalogReadResponse_<ContainerAllocator>& v)
  {
    s << indent << "value: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_ARDUINO_MSGS_MESSAGE_ANALOGREADRESPONSE_H
