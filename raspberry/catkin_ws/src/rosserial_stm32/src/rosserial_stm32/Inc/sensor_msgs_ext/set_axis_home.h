#ifndef _ROS_SERVICE_set_axis_home_h
#define _ROS_SERVICE_set_axis_home_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs_ext
{

static const char SET_AXIS_HOME[] = "sensor_msgs_ext/set_axis_home";

  class set_axis_homeRequest : public ros::Msg
  {
    public:

    set_axis_homeRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return SET_AXIS_HOME; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class set_axis_homeResponse : public ros::Msg
  {
    public:

    set_axis_homeResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return SET_AXIS_HOME; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class set_axis_home {
    public:
    typedef set_axis_homeRequest Request;
    typedef set_axis_homeResponse Response;
  };

}
#endif
