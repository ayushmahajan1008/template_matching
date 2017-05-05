#include "opencv/cv.h"
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>
//#include "lane_detector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

Mat maketemplate(Mat img,int row,int cols,int size)
{
	Mat result(size,size,CV_8UC1,Scalar(0));
	int i,j;
	for(i=row;i<row+size;i++)
	{
		for(j=cols;j<cols+size;j++)
		{
			result.at<uchar>(i-row,j-cols)=img.at<uchar>(i,j);
		}
	}

	return result;

}