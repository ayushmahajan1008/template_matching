#include "opencv/cv.h"
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>
//#include "lane_detector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat img=imread("/home/ayush1008/ayush_opencv/images/62.jpg",0);
	Mat result(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			int value=0;
			for(int k=i-1;k<=i+1;k++)
			{
				for(int l=j-1;l<=j+1;l++)
				{
					if(l==j-1)
						value=value+img.at<uchar>(k,l);
					else if(l==j)
						value=value+0*img.at<uchar>(k,l);
					else if(l==j+1)
						value=value+(-1)*img.at<uchar>(k,l);
				}
			}
			value=value/3;
			if(value<=0)
				value=(-1)*value;
			result.at<uchar>(i,j)=value;
		}
	}

	//Canny( result, result, 50, 200, 3 );

	namedWindow("result",WINDOW_AUTOSIZE);
	imshow("result",result);
	namedWindow("resul",WINDOW_AUTOSIZE);
	imshow("resul",img);
	//imwrite("/home/ayush1008/ayush_opencv/images/resultcurvedlane.jpg",result);
	waitKey(0);
	return 0;


}