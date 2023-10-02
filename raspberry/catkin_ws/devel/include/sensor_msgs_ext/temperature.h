// Generated by gencpp from file sensor_msgs_ext/temperature.msg
// DO NOT EDIT!


#ifndef SENSOR_MSGS_EXT_MESSAGE_TEMPERATURE_H
#define SENSOR_MSGS_EXT_MESSAGE_TEMPERATURE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sensor_msgs_ext
{
template <class ContainerAllocator>
struct temperature_
{
  typedef temperature_<ContainerAllocator> Type;

  temperature_()
    : temperature(0.0)  {
    }
  temperature_(const ContainerAllocator& _alloc)
    : temperature(0.0)  {
  (void)_alloc;
    }



   typedef double _temperature_type;
  _temperature_type temperature;





  typedef boost::shared_ptr< ::sensor_msgs_ext::temperature_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sensor_msgs_ext::temperature_<ContainerAllocator> const> ConstPtr;

}; // struct temperature_

typedef ::sensor_msgs_ext::temperature_<std::allocator<void> > temperature;

typedef boost::shared_ptr< ::sensor_msgs_ext::temperature > temperaturePtr;
typedef boost::shared_ptr< ::sensor_msgs_ext::temperature const> temperatureConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sensor_msgs_ext::temperature_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sensor_msgs_ext::temperature_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sensor_msgs_ext::temperature_<ContainerAllocator1> & lhs, const ::sensor_msgs_ext::temperature_<ContainerAllocator2> & rhs)
{
  return lhs.temperature == rhs.temperature;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sensor_msgs_ext::temperature_<ContainerAllocator1> & lhs, const ::sensor_msgs_ext::temperature_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sensor_msgs_ext

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs_ext::temperature_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs_ext::temperature_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs_ext::temperature_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3d36f909fc0be819c991c4abdee75a2b";
  }

  static const char* value(const ::sensor_msgs_ext::temperature_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3d36f909fc0be819ULL;
  static const uint64_t static_value2 = 0xc991c4abdee75a2bULL;
};

template<class ContainerAllocator>
struct DataType< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs_ext/temperature";
  }

  static const char* value(const ::sensor_msgs_ext::temperature_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Indicates an instantaneous temperature reading.\n"
"\n"
"float64 temperature     # The measured temperature [C]\n"
;
  }

  static const char* value(const ::sensor_msgs_ext::temperature_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.temperature);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct temperature_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sensor_msgs_ext::temperature_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sensor_msgs_ext::temperature_<ContainerAllocator>& v)
  {
    s << indent << "temperature: ";
    Printer<double>::stream(s, indent + "  ", v.temperature);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENSOR_MSGS_EXT_MESSAGE_TEMPERATURE_H