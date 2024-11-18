
#!/usr/bin/env python

'''
Welcome to the ArUco Marker Pose Estimator!

This program:
  - Estimates the pose of an ArUco Marker
'''

from __future__ import print_function  # Python 2/3 compatibility
import sys
import cv2  # Import the OpenCV library
import numpy as np  # Import Numpy library
from scipy.spatial.transform import Rotation as R
import math  # Math library

# Project: ArUco Marker Pose Estimator
# Date created: 12/21/2021
# Python version: 3.8

# Dictionary that was used to generate the ArUco marker
aruco_dictionary_name = "DICT_4X4_50"

# The different ArUco dictionaries built into the OpenCV library.
ARUCO_DICT = {
    "DICT_4X4_50": cv2.aruco.DICT_4X4_50,
    "DICT_4X4_100": cv2.aruco.DICT_4X4_100,
    "DICT_4X4_250": cv2.aruco.DICT_4X4_250,
    "DICT_4X4_1000": cv2.aruco.DICT_4X4_1000,
    "DICT_5X5_50": cv2.aruco.DICT_5X5_50,
    "DICT_5X5_100": cv2.aruco.DICT_5X5_100,
    "DICT_5X5_250": cv2.aruco.DICT_5X5_250,
    "DICT_5X5_1000": cv2.aruco.DICT_5X5_1000,
    "DICT_6X6_50": cv2.aruco.DICT_6X6_50,
    "DICT_6X6_100": cv2.aruco.DICT_6X6_100,
    "DICT_6X6_250": cv2.aruco.DICT_6X6_250,
    "DICT_6X6_1000": cv2.aruco.DICT_6X6_1000,
    "DICT_7X7_50": cv2.aruco.DICT_7X7_50,
    "DICT_7X7_100": cv2.aruco.DICT_7X7_100,
    "DICT_7X7_250": cv2.aruco.DICT_7X7_250,
    "DICT_7X7_1000": cv2.aruco.DICT_7X7_1000,
    "DICT_ARUCO_ORIGINAL": cv2.aruco.DICT_ARUCO_ORIGINAL
}

# Side length of the ArUco marker in meters
aruco_marker_side_length = 0.1#changed value here to suit the image I took from the website were the length was 100mm

# Calibration parameters yaml file
camera_calibration_parameters_filename = 'calibration_chessboard.yaml'
####################
def calculate_rectangle_area(coordinates):
    '''
    Description:    Function to calculate area or detected aruco

    Args:
        coordinates (list):     coordinates of detected aruco (4 set of (x,y) coordinates)

    Returns:
        area        (float):    area of detected aruco
        width       (float):    width of detected aruco
    '''

    ############ Function VARIABLES ############

    # You can remove these variables after reading the instructions. These are just for sample.

    area = None
    width = None

    ############ ADD YOUR CODE HERE ############

    for i in coordinates:
        width=coordinates[0]-coordinates[1]
        area=width**2

    # INSTRUCTIONS & HELP :
    #	->  Recevice coordiantes from 'detectMarkers' using cv2.aruco library
    #       and use these coordinates to calculate area and width of aruco detected.
    #	->  Extract values from input set of 4 (x,y) coordinates
    #       and formulate width and height of aruco detected to return 'area' and 'width'.

    ############################################

    return area[0]+area[1], width
##########################################
def euler_from_quaternion(x, y, z, w):
    """
    Convert a quaternion into euler angles (roll, pitch, yaw)
    roll is rotation around x in radians (counterclockwise)
    pitch is rotation around y in radians (counterclockwise)
    yaw is rotation around z in radians (counterclockwise)
    """
    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)

    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)

    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)

    return roll_x, pitch_y, yaw_z  # in radians


def main():
    '''
    Description:    Function to perform aruco detection and return each detail of aruco detected
                    such as marker ID, distance, angle, width, center point location, etc.

    Args:
        image                   (Image):    Input image frame received from respective camera topic

    Returns:
        center_aruco_list       (list):     Center points of all aruco markers detected
        distance_from_rgb_list  (list):     Distance value of each aruco markers detected from RGB camera
        angle_aruco_list        (list):     Angle of all pose estimated for aruco marker
        width_aruco_list        (list):     Width of all detected aruco markers
        ids                     (list):     List of all aruco marker IDs detected in a single frame
    '''

    ############ Function VARIABLES ############

    # ->  You can remove these variables if needed. These are just for suggestions to let you get started

    # Use this variable as a threshold value to detect aruco markers of certain size.
    # Ex: avoid markers/boxes placed far away from arm's reach position
    aruco_area_threshold = 8000

    # The camera matrix is defined as per camera info loaded from the plugin used.
    # You may get this from /camer_info topic when camera is spawned in gazebo.
    # Make sure you verify this matrix once if there are calibration issues.
    cam_mat = np.array([[931.1829833984375, 0.0, 640.0], [0.0, 931.1829833984375, 360.0], [0.0, 0.0, 1.0]])

    # The distortion matrix is currently set to 0.
    # We will be using it during Stage 2 hardware as Intel Realsense Camera provides these camera info.
    dist_mat = np.array([0.0, 0.0, 0.0, 0.0, 0.0])

    camera_calibration_parameters_filename = 'calibration_chessboard.yaml'
    # Load the camera parameters from the saved file
    cv_file = cv2.FileStorage(
        camera_calibration_parameters_filename, cv2.FILE_STORAGE_READ)
    cam_mat = cv_file.getNode('K').mat()
    dist_mat = cv_file.getNode('D').mat()
    cv_file.release()
    # We are using 150x150 aruco marker size
    size_of_aruco_m = 0.15

    # You can remove these variables after reading the instructions. These are just for sample.
    center_aruco_list = []
    distance_from_rgb_list = []
    angle_aruco_list = []
    width_aruco_list = []
    ids = []

    ############ ADD YOUR CODE HERE ############
    aruco_dict = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)  # ->  Use these aruco parameters-
    #       ->  Dictionary: 4x4_50 (4x4 only until 50 aruco IDs)
    aruco_params = cv2.aruco.DetectorParameters()
    detector = cv2.aruco.ArucoDetector(aruco_dict, aruco_params)
    # INSTRUCTIONS & HELP :
    cap = cv2.VideoCapture(0)
    while(True):
        ret, image = cap.read()
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        # Detect ArUco markers in the video frame
        (corners, marker_ids, rejected) = detector.detectMarkers(image)  # changes here too
          # ->  Convert input BGR image to GRAYSCALE for aruco detection


        #   ->  Detect aruco marker in the image and store 'corners' and 'ids'
        #       ->  HINT: Handle cases for empty markers detection.
        (corners, marker_ids, rejected) = detector.detectMarkers(gray)

        if marker_ids is not None:
            nids = []
            ncorners_list = []
            #   ->  Draw detected marker on the image frame which will be shown later
            # Get the rotation and translation vectors

            #   ->  Loop over each marker ID detected in frame and calculate area using function defined above (calculate_rectangle_area(coordinates))
            for id, corner in zip(marker_ids, corners):
                pfcorner = corner
                print(corner)
                print(id)
                corner = corner.reshape(4, 2)
                area, width = calculate_rectangle_area(corner)
                print(area)
                if (area >= aruco_area_threshold):
                    nids.append(list(id))
                    ncorners_list.append(list(pfcorner))
            cv2.aruco.drawDetectedMarkers(image, np.array(ncorners_list), np.array(nids))
            rvecs, tvecs, obj_points = cv2.aruco.estimatePoseSingleMarkers(
                np.array(ncorners_list),
                size_of_aruco_m,
                cam_mat,
                dist_mat)
            for i, marker_id in enumerate(nids):
                # Store the translation (i.e. position) information
                transform_translation_x = tvecs[i][0][0]
                transform_translation_y = tvecs[i][0][1]
                transform_translation_z = tvecs[i][0][2]

                # Store the rotation information
                rotation_matrix = np.eye(4)
                rotation_matrix[0:3, 0:3] = cv2.Rodrigues(np.array(rvecs[i][0]))[0]
                r = R.from_matrix(rotation_matrix[0:3, 0:3])
                quat = r.as_quat()

                # Quaternion format
                transform_rotation_x = quat[0]
                transform_rotation_y = quat[1]
                transform_rotation_z = quat[2]
                transform_rotation_w = quat[3]

                # Euler angle format in radians
                roll_x, pitch_y, yaw_z = euler_from_quaternion(transform_rotation_x,
                                                               transform_rotation_y,
                                                               transform_rotation_z,
                                                               transform_rotation_w)

                roll_x = math.degrees(roll_x)
                pitch_y = math.degrees(pitch_y)
                yaw_z = math.degrees(yaw_z)
                print("transform_translation_x: {}".format(transform_translation_x))
                print("transform_translation_y: {}".format(transform_translation_y))
                print("transform_translation_z: {}".format(transform_translation_z))
                print("roll_x: {}".format(roll_x))
                print("pitch_y: {}".format(pitch_y))
                print("yaw_z: {}".format(yaw_z))
                print()

                #   ->  Remove tags which are far away from arm's reach positon based on some threshold defined

                #   ->  Calculate center points aruco list using math and distance from RGB camera using pose estimation of aruco marker
                #       ->  HINT: You may use numpy for center points and 'estimatePoseSingleMarkers' from cv2 aruco library for pose estimation

                #   ->  Draw frame axes from coordinates received using pose estimation
                #       ->  HINT: You may use 'cv2.drawFrameAxes'
                cv2.drawFrameAxes(image, cam_mat, dist_mat, rvecs[i], tvecs[i], 0.05)
    ############################################
        cv2.imshow('frame', image)

        # If "q" is pressed on the keyboard,
        # exit this loop
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

        #return center_aruco_list, distance_from_rgb_list, angle_aruco_list, width_aruco_list, ids
        # Display the resulting frame
        cv2.imshow('frame', image)

        # If "q" is pressed on the keyboard,
        # exit this loop

    cap.release()
    cv2.destroyAllWindows()
    # Close down t


if __name__ == '__main__':
    print(__doc__)
    main()