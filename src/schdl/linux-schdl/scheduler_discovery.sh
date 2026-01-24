#!/bin/bash

# This script discovers and displays the Linux scheduler source code
# and explains why Linux uses CFS instead of classic scheduling algorithms.

echo "Installing linux-source package (if not already installed)..."
sudo apt install -y linux-source

echo
echo "Changing to /usr/src directory..."
cd /usr/src || exit 1

echo
echo "Contents of /usr/src:"
ls

echo
echo "Extracting Linux kernel source..."
cd linux-source-5.15.0 || exit 1
sudo tar -xjf linux-source-5.15.0.tar.bz2

echo
echo "Entering Linux kernel source directory..."
cd linux-source-5.15.0 || exit 1

echo
echo "Kernel main directory contents:"
ls

echo
echo "Entering kernel directory..."
cd kernel || exit 1

echo
echo "Kernel subdirectories:"
ls

echo
echo "Entering scheduler directory..."
cd sched || exit 1

echo
echo "Scheduler source files:"
ls

echo
echo "-------------------------------------------------------------"
echo "Linux uses the Completely Fair Scheduler (CFS) as its default scheduler."
echo "The scheduler source code is located at:"
echo "/usr/src/linux-source-5.15.0/kernel/sched/fair.c"
echo
echo "Why doesn't Linux use FCFS, SJF or RR directly?"
echo "Classic algorithms like FCFS, SJF and RR are mainly educational."
echo "They work well in simple or theoretical scenarios but do not scale"
echo "well in real systems with many processes and dynamic workloads."
echo
echo "Linux uses CFS to provide a better balance between fairness,"
echo "performance and system responsiveness."
echo "-------------------------------------------------------------"
echo
echo "Showing part of the real Linux scheduler source code (fair.c):"
echo "-------------------------------------------------------------"

sed -n '1,120p' fair.c
