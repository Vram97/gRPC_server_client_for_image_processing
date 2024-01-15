/*************************************************************************************************
* Description: This file contains the implementation of the server
               which provides the image processing services. 
               The server is implemented using gRPC. 
               The server provides two services:
               1. MeanFilter: This service applies a mean filter to the image
               2. RotateImage: This service rotates the image by 90, 180 or 270 degrees
               The server is implemented using the NLServerImpl class which
               inherits from the NLImageService::Service class. 
               The server is started by calling the RunServer() function of the NLServerImpl class.

* Author: Shivaram Srikanth
* Email:  ssrikanth@wpi.edu
* Date: 12-18-2023
****************************************************************************************************/

#include "image_server.h"

// Specifying default values for CLI arguments
ABSL_FLAG(std::string, port, "5051", "Port number"); 
ABSL_FLAG(std::string, host, "0.0.0.0", "Host name"); 

NLServerImpl::NLServerImpl(const std::string &server_name, const std::string &port_name){
    this->server_address=server_name+":"+port_name;
}

void NLServerImpl::RunServer() {

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;

  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(this->server_address, grpc::InsecureServerCredentials());

  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(this);

  // Finally assemble the server.
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << this->server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

grpc::Status NLServerImpl::MeanFilter(grpc::ServerContext *context,
                                      const NLImage *request,
                                      NLImage *response)
{   /* For this operation, I found that opencv's blur function
       already takes care of the filtration and also handles the 
       pixels which don't have full-neighbors.                   */

    if(!ImageHelper::checkValidNLImage(*request)){
        std::cerr<<"Invalid image"<<std::endl;
        return grpc::Status::CANCELLED;
    }

    cv::Mat img_cv=ImageHelper::NLImageToMat(*request);

    // Applying mean filter
    cv::blur(img_cv, img_cv, cv::Size(3, 3));
    
    // Converting back to NLImage
    *response=ImageHelper::CreateNLImageFromCV(img_cv);

    return grpc::Status::OK;
}

grpc::Status NLServerImpl::RotateImage(grpc::ServerContext* context, 
                            const NLImageRotateRequest* request, 
                            NLImage* response)
{   
    if(!ImageHelper::checkValidNLImage(request->image())){
        std::cerr<<"Invalid image"<<std::endl;
        return grpc::Status::CANCELLED;
    }
    // If rotation is NONE, return the image as it is
    if(request->rotation()==NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_NONE){
        *response=request->image();
        return grpc::Status::OK;
    }


    cv::Mat img_cv=ImageHelper::NLImageToMat(request->image());

    // Applying rotation
    cv::rotate(img_cv, img_cv, ImageHelper::rot_to_cv[request->rotation()]);

    // Converting back to NLImage
    *response=ImageHelper::CreateNLImageFromCV(img_cv);

    return grpc::Status::OK;
}

int main(int argc, char** argv){
    // Parsing CLI arguments
    absl::ParseCommandLine(argc, argv);

    // Parsing all CLI arguments
    std::string port_num=absl::GetFlag(FLAGS_port);
    std::string host_name=absl::GetFlag(FLAGS_host);

    NLServerImpl server(host_name,port_num); // Creating server object
    server.RunServer();  // Starting the server

    return 0;
}