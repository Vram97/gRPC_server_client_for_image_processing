#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "image.grpc.pb.h"

#include <chrono>
#include <ctime>

class ImageHelper
{   public: 

    /*
    * @brief: Creates NLImage from image path
    * @param 1: Path of the image
    * @return: NLImage object
    */
    static NLImage CreateNLImage(const std::string &image_path);

    /*
    * @brief: Creates NLImage from cv::Mat
    * @param 1: cv::Mat object
    */
    static NLImage CreateNLImageFromCV(const cv::Mat &img);

    /*
    * @brief: Checks if NLImage is valid
    * @param 1: NLImage object
    * @return: Boolean flag (Success or failure)
    */
    static bool checkValidNLImage(const NLImage &img);

    /*
    * @brief: Creates NLImageRotateRequest from NLImage and rotation string
    * @param 1: NLImage object
    * @param 2: Rotation string
    * @return: NLImageRotateRequest object
    */
    static NLImageRotateRequest CreateNLImageRotateRequest(const NLImage &img, const std::string &rotate_str);

    /*
    * @brief: Converts NLImage to cv::Mat
    * @param 1: NLImage object
    * @return: cv::Mat object
    */
    static cv::Mat NLImageToMat(const NLImage &img);

    /*
    * @brief: Returns output path for the image
    * @param 1: Path of the image
    * @param 2: Rotation string
    * @param 3: Boolean flag for mean filter
    * @return: Output path
    */
    static const std::string getOutputPath(const std::string &image_path, const std::string &rotate_str, bool& mean,std::string output_path);

    /*
    * @brief: Saves NLImage to output path
    * @param 1: NLImage object
    * @param 2: Output path
    * @return: None
    */
    static void SaveNLImage(const NLImage &img, const std::string &output_path);

    /*
    * @brief: Map of available rotations to their corresponding OpenCV rotation codes
    */
    static std::unordered_map<NLImageRotateRequest_Rotation,int> rot_to_cv;

    /*
    * @brief: Map of available rotations to their corresponding NLImageRotateRequest_Rotation enum
    */
    static std::unordered_map<std::string, NLImageRotateRequest_Rotation> valid_rot;
};