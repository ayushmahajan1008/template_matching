#include "opencv/cv.h"
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>
//#include "lane_detector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "template.hpp"
#include "make_template.hpp"
#include "make_road.hpp"
//#include "trackbar.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat img=imread("transform.jpg",0);
	Mat temp=maketemplate(img,163,8,25);
	/*Mat temp(25,25,CV_8UC1,Scalar(100));
	int i,j;
	for(i=174;i<=198;i++)
	{
		for(j=159;j<=183;j++)
		{
			temp.at<uchar>(i-174,j-159)=img.at<uchar>(i,j);
		}
	}
*/
	//int match[img.rows][img.cols];
    //int temp_avg,img_avg;
    Mat result=templatematch(img,temp);
    cout<<"road"<<endl;
    Mat road=makeroad(img,result,25);
    cout<<"afterroad"<<endl;
   // namedWindow("road",WINDOW_AUTOSIZE);
    //imshow("road",road);
   /* for(i=0;i<result.rows;i++)
    {
    	for(j=0;j<result.cols;j++)
    	{
    		if(result.at<uchar>(i,j)>20)
    			result.at<uchar>
    	}
    }*/
    //Mat result1=thresholds(result);
    imwrite("/home/ayush1008/ayush_opencv/lanes/r.jpg",result);
    namedWindow("result",WINDOW_AUTOSIZE);
    imshow("result",result);

    /*int th=1,i,j,k,l;
    createTrackbar("threshold",result,&th,255);
    while(1)
    {
		for(i=0;i<result.rows;i++)
			{
				cout<<"b"<<endl;
				for(j=0;j<result.cols;j++)
				{
					cout<<"c"<<endl;
					if(result.at<uchar>(i,j)<th)
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
						result.at<uchar>(i,j)=0;
					else result.at<uchar>(i,j)=255;

				}
			}
			imshow("result",result);
			waitKey(50);

			int q;
			cin>>q;
			if(q==27)
				break;

    }
*/

	namedWindow("template",WINDOW_AUTOSIZE);
	imshow("template",temp);
	namedWindow("transform",WINDOW_AUTOSIZE);
	imshow("transform",img);
	
	waitKey(0);

	return 0;
}