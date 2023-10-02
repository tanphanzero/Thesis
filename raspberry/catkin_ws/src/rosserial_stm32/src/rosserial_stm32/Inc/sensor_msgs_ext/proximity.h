#ifndef _ROS_sensor_msgs_ext_proximity_h
#define _ROS_sensor_msgs_ext_proximity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs_ext
{

  class proximity : public ros::Msg
  {
    public:
      typedef bool _proximity_type;
      _proximity_type proximity;

    proximity():
      proximity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_proximity;
      u_proximity.real = this->proximity;
      *(outbuffer + offset + 0) = (u_proximity.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->proximity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_proximity;
      u_proximity.base = 0;
      u_proximity.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->proximity = u_proximity.real;
      offset += sizeof(this->proximity);
     return offset;
    }

    virtual const char * getType() override { return "sensor_msgs_ext/proximity"; };
    virtual const char * getMD5() override { return "87ce68baa8581bc2125ed1ea8e240a58"; };

  };

}
#endif
