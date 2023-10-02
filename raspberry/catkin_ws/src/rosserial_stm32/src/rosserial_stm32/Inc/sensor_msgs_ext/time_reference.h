#ifndef _ROS_sensor_msgs_ext_time_reference_h
#define _ROS_sensor_msgs_ext_time_reference_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace sensor_msgs_ext
{

  class time_reference : public ros::Msg
  {
    public:
      typedef ros::Time _utc_time_type;
      _utc_time_type utc_time;

    time_reference():
      utc_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->utc_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->utc_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->utc_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->utc_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->utc_time.sec);
      *(outbuffer + offset + 0) = (this->utc_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->utc_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->utc_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->utc_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->utc_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->utc_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->utc_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->utc_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->utc_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->utc_time.sec);
      this->utc_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->utc_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->utc_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->utc_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->utc_time.nsec);
     return offset;
    }

    virtual const char * getType() override { return "sensor_msgs_ext/time_reference"; };
    virtual const char * getMD5() override { return "3fec41e35208cc454786888579a04bcb"; };

  };

}
#endif
