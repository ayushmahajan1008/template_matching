#include "opencv/cv.h"
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>
//#include "lane_detector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

Mat makeroad(Mat img,Mat result,int size)
{
	Mat temp(img.rows,img.cols,CV_8UC1,Scalar(0));
	int i,j,k,l;
	cout<<"a"<<endl;
	for(i=0;i<result.rows;i++)
	{
		cout<<"b"<<endl;
		for(j=0;j<result.cols;j++)
		{
			cout<<"c"<<endl;
			if(result.at<uchar>(i,j)<1)
			{
				for(k=i;k<i+size;k++)
				{
					for(l=j;l<j+size;l++)
					{
						if(k>=0 && k<img.rows && l>=0 && l<img.cols)
						{
							temp.at<uchar>(k,l)=img.at<uchar>(k,l);
						}
						cout<<"d"<<endl;
						
					}
				}
			}
		}
	}
	cout<<"e"<<endl;

	return temp;
}