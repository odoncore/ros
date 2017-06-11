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
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/wonsik/catkin_ws/src/rosbridge_suite/rosbridge_server"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/wonsik/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/wonsik/catkin_ws/install/lib/python2.7/dist-packages:/home/wonsik/catkin_ws/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/wonsik/catkin_ws/build" \
    "/usr/bin/python" \
    "/home/wonsik/catkin_ws/src/rosbridge_suite/rosbridge_server/setup.py" \
    build --build-base "/home/wonsik/catkin_ws/build/rosbridge_suite/rosbridge_server" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/wonsik/catkin_ws/install" --install-scripts="/home/wonsik/catkin_ws/install/bin"
