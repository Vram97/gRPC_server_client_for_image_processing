#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <opencv2/opencv.hpp>

#include "image_helper.h"
#include "image.grpc.pb.h"

class NLServerImpl final : public NLImageService::Service {
    public:

        /*
        *@breif: Constructor for NLServerImpl
        *@return: None
        */
        NLServerImpl(const std::string& server_name, const std::string& port_name);

        /*
        *@breif: Server-side implementation of MeanFilter
        *@param 1: Server context
        *@param 2: Request image
        *@param 3: Response image (Passed by reference)
        *@return: Status of the operation
        */
        grpc::Status MeanFilter(grpc::ServerContext* context,
                            const NLImage* request,
                            NLImage* response) override;

        /*
        *@breif: Server-side implementation of RotateImage
        *@param 1: Server context
        *@param 2: Rotation request consisting of image and rotation angle
        *@param 3: Response image (Passed by reference)
        *@return: Status of the operation
        */
        grpc::Status RotateImage(grpc::ServerContext* context, 
                                const NLImageRotateRequest* request, 
                                NLImage* response) override;
        /*
        *@breif: Starts the server
        *@return: None
        */
        void RunServer();

    private:
        /*
        *@breif: Address of the server
        */
         std::string server_address; 

};