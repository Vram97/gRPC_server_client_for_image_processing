#pragma once

#include <iostream>
#include <memory>
#include <string>


#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>

#include <opencv2/opencv.hpp>

#include "image_helper.h"
#include "image.grpc.pb.h"


class NLClientImpl final {
 public:

  /*
  * @brief: Constructor for NLClientImpl
  * @param 1: Shared pointer to the channel
  * @return: None
  */
  NLClientImpl(std::shared_ptr<grpc::Channel> channel)
      : stub_(NLImageService::NewStub(channel)) {channel_ = channel;}

  /*
  * @brief: Client-side implementation of sending request for MeanFilter
  * @param 1: Request image
  * @return: Response image
  */
  NLImage SendMeanFilter(const NLImage& request);

  /*
  * @brief: Client-side implementation of sending request for RotateImage
  * @param 1: Rotation request consisting of image and rotation angle
  * @return: Response image
  */  
  NLImage SendRotateImage(const NLImageRotateRequest& request);

  /*
  * @brief: Client-side implementation of sending a request to the server
  * @param 1: Path of the image
  * @param 2: Rotation string
  * @param 3: Boolean flag for mean filter
  * @param 4: Output path
  * @return: Response image
  */
  NLImage SendRequest(const std::string&  img_path, const std::string& rotate_str, bool mean, std::string output_path);

  /*
  * @brief: Checks the status of the server
  * @return: Status of the server
  */
  grpc::Status checkServerStatus();

 private:
  /*
  * @brief: Shared pointer to the channel
  */
  std::shared_ptr<grpc::Channel> channel_;
  
  /*
  * @brief: Stub for the client
  */
  std::unique_ptr<NLImageService::Stub> stub_;

  /*
  * @brief: Request image
  */
  NLImage request_mean;

  /*
  * @brief: Rotation request consisting of image and rotation angle
  */
  NLImageRotateRequest request_rotate;

  /*
  * @brief: Response image
  */
  NLImage response_;
};
