

width_aruco_list = []
    distance_from_rgb_list = []
    aruco_area_threshold  = 1500
    gray = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    aruco_dict  = aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
    detector_params = aruco.DetectorParameters()
    detector = aruco.ArucoDetector(aruco_dict,detector_params)
    marker_corner,ids,rejects = detector.detectMarkers(gray,detector_params)
    center_aruco_list = []
    marker_size = 0.15
    trash = []
    rvecs = []
    tvecs = []
    for id,corner in zip(ids,marker_corner):
        corner = np.reshape(corner,(4,2))
        area,width = calculate_rectangle_area(corner)
        if area<=aruco_area_threshold:
            top_right = np.ravel(corner[0])
            top_left = np.ravel(corner[1])
            bottom_right = np.ravel(corner[2])
            bottom_left = np.ravel(corner[3])
            p_one = (top_right+top_left)/2
            p_two = (bottom_right+bottom_left)/2
            center = (p_one+p_two)/2
            center = list(map(int,center))
            center_aruco_list.append(center)
            marker_points = np.array([[-marker_size / 2, marker_size / 2, 0],
                              [marker_size / 2, marker_size / 2, 0],
                              [marker_size / 2, -marker_size / 2, 0],
                              [-marker_size / 2, -marker_size / 2, 0]], dtype=np.float32)
            nada,R,t = cv2.solvePnP(marker_points,corner,cam_mat,dist_mat,False,cv2.SOLVEPNP_IPPE_SQUARE)
            rvecs.append(R)
            tvecs.append(t)
            for i in rvecs:X
                distance_from_rgb_list.append(i[2])