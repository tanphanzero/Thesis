#ifndef _ROS_SERVICE_calibrate_gyroscope_h
#define _ROS_SERVICE_calibrate_gyroscope_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs_ext
{

static const char CALIBRATE_GYROSCOPE[] = "sensor_msgs_ext/calibrate_gyroscope";

  class calibrate_gyroscopeRequest : public ros::Msg
  {
    public:
      typedef uint32_t _averaging_period_type;
      _averaging_period_type averaging_period;

    calibrate_gyroscopeRequest():
      averaging_period(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->averaging_period >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->averaging_period >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->averaging_period >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->averaging_period >> (8 * 3)) & 0xFF;
      offset += sizeof(this->averaging_period);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->averaging_period =  ((uint32_t) (*(inbuffer + offset)));
      this->averaging_period |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->averaging_period |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->averaging_period |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->averaging_period);
     return offset;
    }

    virtual const char * getType() override { return CALIBRATE_GYROSCOPE; };
    virtual const char * getMD5() override { return "bf0a54849407c21e7e7bc0aef95791c7"; };

  };

  class calibrate_gyroscopeResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    calibrate_gyroscopeResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return CALIBRATE_GYROSCOPE; };
    virtual const char * getMD5() override { return "937c9679a518e3a18d831e57125ea522"; };

  };

  class calibrate_gyroscope {
    public:
    typedef calibrate_gyroscopeRequest Request;
    typedef calibrate_gyroscopeResponse Response;
  };

}
#endif
