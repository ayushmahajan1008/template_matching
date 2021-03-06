#include "opencv/cv.h"
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>
//#include "lane_detector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;

/// Global Variables
//Mat img; Mat templ; Mat result;
//char* image_window = "Source Image";
//char* result_window = "Result window";

//int match_method;
//int max_Trackbar = 5;

/// Function Headers
Mat MatchingMethod( int, void* ,Mat,Mat);

/** @function main */
Mat templatematch(Mat img,Mat templ)
{
  /// Load image and template
  //img = imread( argv[1], 1 );
  //templ = imread( argv[2], 1 );

  /// Create windows
  //namedWindow( image_window, CV_WINDOW_AUTOSIZE );
  //namedWindow( result_window, CV_WINDOW_AUTOSIZE );

  /// Create Trackbar
  //char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
  //createTrackbar( trackbar_label, image_window, &match_method, max_Trackbar, MatchingMethod );

  Mat reslt=MatchingMethod( 0, 0 ,img,templ);

  //waitKey(0);
  return reslt;
}

/**
 * @function MatchingMethod
 * @brief Trackbar callback
 */
Mat MatchingMethod( int, void* ,Mat img,Mat templ)
{
  /// Source image to display
  Mat img_display,result;
  img.copyTo( img_display );

  /// Create the result matrix
  int result_cols =  img.cols - templ.cols + 1;
  int result_rows = img.rows - templ.rows + 1;

  result.create( result_rows, result_cols, CV_8UC1 );

  /// Do the Matching and Normalize
  matchTemplate( img, templ, result, 0 );
  normalize( result, result, 0, 1, NORM_MINMAX, -1, Mat() );

  /// Localizing the best match with minMaxLoc
  //double minVal; double maxVal; Point minLoc; Point maxLoc;
  //Point matchLoc;

  //minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );

  /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
 /* if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
    { matchLoc = minLoc; }
  else
    { matchLoc = maxLoc; }

  /// Show me what you got
  rectangle( img_display, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );
  rectangle( result, matchLoc, Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), Scalar::all(0), 2, 8, 0 );

  //imshow( image_window, img_display );
  //imshow( result_window, result );
*/
  return result;
}