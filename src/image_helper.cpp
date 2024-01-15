/********************************************************
* Description: Helper functions for image processing
* Author: Shivaram Srikanth
* Email: ssrikanth@wpi.edu
* Date: 12-18-2023
********************************************************/


#include "image_helper.h"

// Mapping of rotations (Initialized here since non literal types cannot be initialized at compile time)
std::unordered_map<NLImageRotateRequest_Rotation,int>ImageHelper::rot_to_cv = {{NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_NINETY_DEG, cv::ROTATE_90_COUNTERCLOCKWISE}, {NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_ONE_EIGHTY_DEG,cv::ROTATE_180}, {NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_TWO_SEVENTY_DEG, cv::ROTATE_90_CLOCKWISE }};
std::unordered_map<std::string, NLImageRotateRequest_Rotation> ImageHelper::valid_rot = {{"NONE", NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_NONE}, {"NINETY_DEG", NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_NINETY_DEG}, {"ONE_EIGHTY_DEG", NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_ONE_EIGHTY_DEG}, {"TWO_SEVENTY_DEG", NLImageRotateRequest_Rotation::NLImageRotateRequest_Rotation_TWO_SEVENTY_DEG}};

NLImage ImageHelper::CreateNLImage(const std::string &image_path)
{
    cv::Mat image = cv::imread(image_path, cv::IMREAD_UNCHANGED);

    if (image.empty())
    {
        std::cerr << "Could not read the image: " << image_path << std::endl;
        return NLImage();
    }
    else
    {
        return CreateNLImageFromCV(image);
    }
}

NLImage ImageHelper::CreateNLImageFromCV(const cv::Mat &img)
{
    NLImage image;
    // Set NLImage properties
    image.set_height(img.rows);
    image.set_width(img.cols);
    image.set_color((img.channels()==1)?false:true);
    image.set_data(img.data, img.total() * img.elemSize());
    return image;
}

bool ImageHelper::checkValidNLImage(const NLImage &img)
{
    if (img.height() > 0 && img.width() > 0 && img.data().length() > 0)
    {
        return true;
    }

    return false;
}

NLImageRotateRequest ImageHelper::CreateNLImageRotateRequest(const NLImage &img, const std::string &rotate_str)
{
    NLImageRotateRequest NLRotate_req;
    NLRotate_req.set_allocated_image(new NLImage(img));
    NLRotate_req.set_rotation(valid_rot[rotate_str]); //NLImageRotateRequest::NONE; valid_rot[rotate_str]
    return NLRotate_req;
}

cv::Mat ImageHelper::NLImageToMat(const NLImage &img)
{
    cv::Mat image(img.height(), img.width(), (img.color()) ? CV_8UC3 : CV_8UC1, (void *)img.data().c_str());
    return image;
}

const std::string ImageHelper::getOutputPath(const std::string &image_path, const std::string &rotate_str, bool &mean,std::string output_path)
{   if(output_path[output_path.length()-1]!='/'){
        output_path+="/";
    }

    std::string image_name = image_path.substr(image_path.find_last_of("/\\") + 1);
    output_path += image_name.substr(0, image_name.find_last_of(".")) + "_";
    std::string ext=image_name.substr(image_name.find_last_of(".")+1);
    if (mean)
    {
        output_path += "mean_";
    }
    if (rotate_str != "NOT_SET")
    {
        output_path += rotate_str + "_";
    }

    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);

    output_path+=std::to_string(tm.tm_year + 1900) + '-' + std::to_string(tm.tm_mon + 1) + '-' + std::to_string(tm.tm_mday) + '-' + std::to_string(tm.tm_hour) + '-' + std::to_string(tm.tm_min) + '-' + std::to_string(tm.tm_sec) + '.' + ext;

    return output_path;
}

void ImageHelper::SaveNLImage(const NLImage &img, const std::string &output_path)
{
    cv::Mat image = NLImageToMat(img);
    

    try {
        // Attempt to write the image to the specified file path
        cv::imwrite(output_path, image);
        std::cout << "Image saved successfully to " << output_path << std::endl;
    } catch (const cv::Exception& ex) {
        // Handling OpenCV exceptions
        std::cout << "Error occurred while saving the image to " << output_path << std::endl;
        std::cerr << "OpenCV error: " << ex.what() << std::endl;
    }
}


