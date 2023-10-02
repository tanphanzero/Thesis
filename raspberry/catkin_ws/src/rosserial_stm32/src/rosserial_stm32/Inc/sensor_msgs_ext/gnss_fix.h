#ifndef _ROS_sensor_msgs_ext_gnss_fix_h
#define _ROS_sensor_msgs_ext_gnss_fix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs_ext
{

  class gnss_fix : public ros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _mode_selection_type;
      _mode_selection_type mode_selection;
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef uint8_t _satellite_count_type;
      _satellite_count_type satellite_count;
      enum { TYPE_NO_FIX =  0 };
      enum { TYPE_FIX =  1 };
      enum { TYPE_DIFFERENTIAL =  2 };
      enum { TYPE_RTK_FIXED =  4 };
      enum { TYPE_RTK_FLOAT =  5 };
      enum { TYPE_DEAD_RECKONING =  6 };
      enum { MODE_SELECTION_MANUAL =  0 };
      enum { MODE_SELECTION_AUTOMATIC =  1 };
      enum { MODE_NONE =  0 };
      enum { MODE_2D =  1 };
      enum { MODE_3D =  2 };

    gnss_fix():
      type(0),
      mode_selection(0),
      mode(0),
      satellite_count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->mode_selection >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode_selection);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      *(outbuffer + offset + 0) = (this->satellite_count >> (8 * 0)) & 0xFF;
      offset += sizeof(this->satellite_count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->mode_selection =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode_selection);
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      this->satellite_count =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->satellite_count);
     return offset;
    }

    virtual const char * getType() override { return "sensor_msgs_ext/gnss_fix"; };
    virtual const char * getMD5() override { return "ac20d1087808fbd5ae6cee3e0e0bee4d"; };

  };

}
#endif
