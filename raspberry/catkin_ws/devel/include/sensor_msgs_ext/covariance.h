// Generated by gencpp from file sensor_msgs_ext/covariance.msg
// DO NOT EDIT!


#ifndef SENSOR_MSGS_EXT_MESSAGE_COVARIANCE_H
#define SENSOR_MSGS_EXT_MESSAGE_COVARIANCE_H


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
struct covariance_
{
  typedef covariance_<ContainerAllocator> Type;

  covariance_()
    : dimensions(0)
    , covariance()  {
    }
  covariance_(const ContainerAllocator& _alloc)
    : dimensions(0)
    , covariance(_alloc)  {
  (void)_alloc;
    }



   typedef uint32_t _dimensions_type;
  _dimensions_type dimensions;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _covariance_type;
  _covariance_type covariance;





  typedef boost::shared_ptr< ::sensor_msgs_ext::covariance_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sensor_msgs_ext::covariance_<ContainerAllocator> const> ConstPtr;

}; // struct covariance_

typedef ::sensor_msgs_ext::covariance_<std::allocator<void> > covariance;

typedef boost::shared_ptr< ::sensor_msgs_ext::covariance > covariancePtr;
typedef boost::shared_ptr< ::sensor_msgs_ext::covariance const> covarianceConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sensor_msgs_ext::covariance_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sensor_msgs_ext::covariance_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sensor_msgs_ext::covariance_<ContainerAllocator1> & lhs, const ::sensor_msgs_ext::covariance_<ContainerAllocator2> & rhs)
{
  return lhs.dimensions == rhs.dimensions &&
    lhs.covariance == rhs.covariance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sensor_msgs_ext::covariance_<ContainerAllocator1> & lhs, const ::sensor_msgs_ext::covariance_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sensor_msgs_ext

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sensor_msgs_ext::covariance_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sensor_msgs_ext::covariance_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sensor_msgs_ext::covariance_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a8fe301b0f306d03958ddc38bec90d10";
  }

  static const char* value(const ::sensor_msgs_ext::covariance_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa8fe301b0f306d03ULL;
  static const uint64_t static_value2 = 0x958ddc38bec90d10ULL;
};

template<class ContainerAllocator>
struct DataType< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sensor_msgs_ext/covariance";
  }

  static const char* value(const ::sensor_msgs_ext::covariance_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# The covariance matrix for a sensor measurement.\n"
"\n"
"uint32 dimensions           # The number of independent measurements represented by the covariance matrix.\n"
"float64[] covariance        # The covariance matrix in row-major order.\n"
;
  }

  static const char* value(const ::sensor_msgs_ext::covariance_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dimensions);
      stream.next(m.covariance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct covariance_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sensor_msgs_ext::covariance_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sensor_msgs_ext::covariance_<ContainerAllocator>& v)
  {
    s << indent << "dimensions: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.dimensions);
    s << indent << "covariance[]" << std::endl;
    for (size_t i = 0; i < v.covariance.size(); ++i)
    {
      s << indent << "  covariance[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.covariance[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENSOR_MSGS_EXT_MESSAGE_COVARIANCE_H
