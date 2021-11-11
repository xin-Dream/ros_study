#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/dream/001-data/003-ROS/ros_study/Burberry_ws/src/ros_arduino_bridge/ros_arduino_python"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/dream/001-data/003-ROS/ros_study/Burberry_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/dream/001-data/003-ROS/ros_study/Burberry_ws/install/lib/python2.7/dist-packages:/home/dream/001-data/003-ROS/ros_study/Burberry_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/dream/001-data/003-ROS/ros_study/Burberry_ws/build" \
    "/usr/bin/python2" \
    "/home/dream/001-data/003-ROS/ros_study/Burberry_ws/src/ros_arduino_bridge/ros_arduino_python/setup.py" \
     \
    build --build-base "/home/dream/001-data/003-ROS/ros_study/Burberry_ws/build/ros_arduino_bridge/ros_arduino_python" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/dream/001-data/003-ROS/ros_study/Burberry_ws/install" --install-scripts="/home/dream/001-data/003-ROS/ros_study/Burberry_ws/install/bin"
