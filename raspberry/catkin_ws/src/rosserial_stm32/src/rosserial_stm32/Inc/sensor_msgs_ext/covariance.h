#ifndef _ROS_sensor_msgs_ext_covariance_h
#define _ROS_sensor_msgs_ext_covariance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace sensor_msgs_ext
{

  class covariance : public ros::Msg
  {
    public:
      typedef uint32_t _dimensions_type;
      _dimensions_type dimensions;
      uint32_t covariance_length;
      typedef double _covariance_type;
      _covariance_type st_covariance;
      _covariance_type * covariance;

    covariance():
      dimensions(0),
      covariance_length(0), st_covariance(), covariance(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->dimensions >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dimensions >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dimensions >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dimensions >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dimensions);
      *(outbuffer + offset + 0) = (this->covariance_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->covariance_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->covariance_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->covariance_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->covariance_length);
      for( uint32_t i = 0; i < covariance_length; i++){
      union {
        double real;
        uint64_t base;
      } u_covariancei;
      u_covariancei.real = this->covariance[i];
      *(outbuffer + offset + 0) = (u_covariancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_covariancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_covariancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_covariancei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_covariancei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_covariancei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_covariancei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_covariancei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->dimensions =  ((uint32_t) (*(inbuffer + offset)));
      this->dimensions |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->dimensions |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->dimensions |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->dimensions);
      uint32_t covariance_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      covariance_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      covariance_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      covariance_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->covariance_length);
      if(covariance_lengthT > covariance_length)
        this->covariance = (double*)realloc(this->covariance, covariance_lengthT * sizeof(double));
      covariance_length = covariance_lengthT;
      for( uint32_t i = 0; i < covariance_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_covariance;
      u_st_covariance.base = 0;
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_covariance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_covariance = u_st_covariance.real;
      offset += sizeof(this->st_covariance);
        memcpy( &(this->covariance[i]), &(this->st_covariance), sizeof(double));
      }
     return offset;
    }

    virtual const char * getType() override { return "sensor_msgs_ext/covariance"; };
    virtual const char * getMD5() override { return "a8fe301b0f306d03958ddc38bec90d10"; };

  };

}
#endif
