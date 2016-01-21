#!/bin/bash
g++ bag2mp4.cpp -o bag2mp4 -L/opt/ros/indigo/lib   -lrosbag_storage -lrostime -lcpp_common -lroscpp -Wl,-rpath,/opt/ros/indigo/lib -lroscpp_serialization `pkg-config --libs opencv` -std=c++11
