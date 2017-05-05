#include "opencv/cv.h"
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>
//#include "lane_detector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

void threshold(int, void *);
int low_r=30, low_g=30, low_b=30;
int high_r=255, high_g=100, high_b=100;

Mat thresholds(Mat result)
{
	Mat result1(result.rows,result.cols,CV_8UC1,Scalar(255));
    namedWindow("Video Capture", WINDOW_NORMAL);
    namedWindow("Object Detection", WINDOW_NORMAL);
    //-- Trackbars to set thresholds for RGB values
    createTrackbar("Low R","Object Detection", &low_r, 255,threshold);
        //inRange(frame,Scalar(low_b,low_g,low_r), Scalar(high_b,high_g,high_r),frame_threshold);
        //-- Show the frames
      while((char)waitKey(1)!='q')
      {
        for(int i=0;i<result.rows;i++)
        {
        	for(int j=0;j<result.cols;j++)
        	{
        		if(result.at<uchar>(i,j)<low_r)
        			result1.at<uchar>(i,j)=0;
        		else
        			result1.at<uchar>(i,j)=255;
        	}
        }
        imshow("Video Capture",result);
        imshow("Object Detection",result1);
      }
    return result1;
}
void threshold(int, void *)
{
    low_r = min(high_r-1, low_r);
    setTrackbarPos("Low R","Object Detection", low_r);
}