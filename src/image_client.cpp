/***********************************************
*  Client Implementation for the Image Client
*  Author: Shivaram Srikanth
*  Email: ssrikanth@wpi.edu
*  Date: 12-18-2020
************************************************/

#include "image_client.h"

// Specifying default values for CLI arguments
ABSL_FLAG(std::string, port, "5051", "Port number"); 
ABSL_FLAG(std::string, host, "0.0.0.0", "Host name"); 
ABSL_FLAG(bool, mean, false, "Mean filter");
ABSL_FLAG(std::string, rotate, "NOT_SET", "Rotation angle");
ABSL_FLAG(std::string, input, "./data/image.jpg", "Input image path");
ABSL_FLAG(std::string, output, "./data/", "Output image path");


NLImage NLClientImpl::SendMeanFilter(const NLImage& request){
    std::cout<<"Sending request to server for Mean Filtering..."<<std::endl;
    grpc::ClientContext context;
    NLImage response_;
    grpc::Status status = this->stub_->MeanFilter(&context, request, &response_);
    if (status.ok()) {
        std::cout<<"Received Filtered Image"<<std::endl;
        return response_;
    } else {
        std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        return response_;
    }
}

NLImage NLClientImpl::SendRotateImage(const NLImageRotateRequest& request){
    std::cout<<"Sending request to server for Rotation..."<<std::endl;
    grpc::ClientContext context;
    NLImage response_;
    grpc::Status status = this->stub_->RotateImage(&context, request, &response_);
    if (status.ok()) {
        std::cout<<"Received Rotated Image"<<std::endl;
        return response_;
    } else {
        std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        return response_;
    }
}

NLImage NLClientImpl::SendRequest(const std::string &img_path, const std::string &rotate_str, bool mean,std::string output_path)
{        
    this->request_mean= ImageHelper::CreateNLImage(img_path);

    //Check if image is valid
    if(!ImageHelper::checkValidNLImage(this->request_mean)){
        std::cerr<<"Invalid image. Please check the path."<<std::endl;
        return this->response_;
    }
    else{
        std::cout<<"NLImage created successfully"<<std::endl;
    }

    if(mean){
        this->response_ = this->SendMeanFilter(this->request_mean);
        this->request_mean= this->response_;
    }
    else{
        std::cout<<"No mean filter requested. Skipping mean filter."<<std::endl;
    }

    if(ImageHelper::valid_rot.find(rotate_str)!=ImageHelper::valid_rot.end()){
        this->request_rotate=ImageHelper::CreateNLImageRotateRequest(this->request_mean, rotate_str);
        this->response_ = this->SendRotateImage(this->request_rotate);
    }
    else if(rotate_str!="NOT_SET"){
        std::cout<<"Invalid rotation angle. Please choose from: NONE, NINETY_DEG, ONE_EIGHTY_DEG, TWO_SEVENTY_DEG"<<std::endl;
        return NLImage();
    }
    else{
        std::cout<<"No rotation requested. Skipping rotation."<<std::endl;
    }

    if(!ImageHelper::checkValidNLImage(this->response_)){
        std::cerr<<"Invalid image"<<std::endl;
        return this->response_;
    }

    output_path = ImageHelper::getOutputPath(img_path, rotate_str, mean, output_path);

    ImageHelper::SaveNLImage(this->response_, output_path);

    return this->response_;
}

grpc::Status NLClientImpl::checkServerStatus()
{   
    // Check if the channel is connected
    if (this->channel_->WaitForConnected(std::chrono::system_clock::now() + std::chrono::seconds(2))) {
        std::cout << "Connected to the server!" << std::endl;
        // Return status ok
        return grpc::Status::OK;

    } else {
        std::cerr << "Failed to connect to the server." << std::endl;
        // Return status cancelled
        return grpc::Status(grpc::StatusCode::CANCELLED, "Failed to connect to the server.");
    }
}

int main(int argc, char** argv){
    absl::ParseCommandLine(argc, argv);

    // Parsing all CLI arguments
    std::string port_num=absl::GetFlag(FLAGS_port);
    std::string host_name=absl::GetFlag(FLAGS_host);
    std::string rotate_str=absl::GetFlag(FLAGS_rotate);
    std::string image_path=absl::GetFlag(FLAGS_input);
    std::string output_path=absl::GetFlag(FLAGS_output);
    bool mean=absl::GetFlag(FLAGS_mean);

    // Creating a channel to connect to the server
    std::string server_address = host_name+":"+port_num;

    // Creating client object
    NLClientImpl client(grpc::CreateChannel(
      server_address, grpc::InsecureChannelCredentials()));

    // Checking the status of the server
    if(!client.checkServerStatus().ok()){
        std::cerr<<"Please verify host and port name"<<std::endl;
        return 0;
    }

    // Sending the request
    NLImage response = client.SendRequest(image_path, rotate_str, mean, output_path);

    return 0;

}