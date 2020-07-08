#!/bin/bash -xe

CURRENT_DIR=`dirname $0`
cd ${CURRENT_DIR}
CURRENT_DIR=`pwd`

cd ${CURRENT_DIR}

qmlscene \
-I ./bin/ \
index.qml
