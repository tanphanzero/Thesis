#ifndef _ROS_SERVICE_get_proximity_configuration_h
#define _ROS_SERVICE_get_proximity_configuration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs_ext
{

static const char GET_PROXIMITY_CONFIGURATION[] = "sensor_msgs_ext/get_proximity_configuration";

  class get_proximity_configurationRequest : public ros::Msg
  {
    public:

    get_proximity_configurationRequest()
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

    virtual const char * getType() override { return GET_PROXIMITY_CONFIGURATION; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_proximity_configurationResponse : public ros::Msg
  {
    public:
      typedef uint8_t _radiation_type_type;
      _radiation_type_type radiation_type;
      typedef float _min_range_type;
      _min_range_type min_range;
      typedef float _max_range_type;
      _max_range_type max_range;
      typedef float _field_of_view_type;
      _field_of_view_type field_of_view;
      enum { RADIATION_TYPE_UNSPECIFIED = 255 };
      enum { RADIATION_TYPE_ULTRASOUND = 0 };
      enum { RADIATION_TYPE_INFRARED = 1 };
      enum { RADIATION_TYPE_RADAR = 2 };

    get_proximity_configurationResponse():
      radiation_type(0),
      min_range(0),
      max_range(0),
      field_of_view(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->radiation_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->radiation_type);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.real = this->min_range;
      *(outbuffer + offset + 0) = (u_min_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.real = this->max_range;
      *(outbuffer + offset + 0) = (u_max_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_range);
      union {
        float real;
        uint32_t base;
      } u_field_of_view;
      u_field_of_view.real = this->field_of_view;
      *(outbuffer + offset + 0) = (u_field_of_view.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_field_of_view.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_field_of_view.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_field_of_view.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->field_of_view);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->radiation_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->radiation_type);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.base = 0;
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_range = u_min_range.real;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.base = 0;
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_range = u_max_range.real;
      offset += sizeof(this->max_range);
      union {
        float real;
        uint32_t base;
      } u_field_of_view;
      u_field_of_view.base = 0;
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->field_of_view = u_field_of_view.real;
      offset += sizeof(this->field_of_view);
     return offset;
    }

    virtual const char * getType() override { return GET_PROXIMITY_CONFIGURATION; };
    virtual const char * getMD5() override { return "bc6aa8c1ba0744c7248467a89aa5b3e1"; };

  };

  class get_proximity_configuration {
    public:
    typedef get_proximity_configurationRequest Request;
    typedef get_proximity_configurationResponse Response;
  };

}
#endif
