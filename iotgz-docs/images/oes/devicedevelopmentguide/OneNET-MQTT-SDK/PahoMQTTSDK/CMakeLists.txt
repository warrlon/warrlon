#*******************************************************************************
#  Copyright (c) 2017 IBM Corp.
#
#  All rights reserved. This program and the accompanying materials
#  are made available under the terms of the Eclipse Public License v1.0
#  and Eclipse Distribution License v1.0 which accompany this distribution.
#
#  The Eclipse Public License is available at
#     http://www.eclipse.org/legal/epl-v10.html
#  and the Eclipse Distribution License is available at
#    http://www.eclipse.org/org/documents/edl-v10.php.
#
#  Contributors:
#     Ian Craggs - initial version
#*******************************************************************************/

# MQTTPacket Library
file(GLOB SOURCES "*.c" "Driver/mbedtls/src/*.c" "Driver/linux/*.c" "MQTTPacket/*.c" )
include_directories("Driver/include/mbedtls/" "Driver/include/")
add_library(paho-mqtt-sdk STATIC ${SOURCES})
ADD_SUBDIRECTORY(samples)

