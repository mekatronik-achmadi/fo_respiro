#!/bin/bash

if [ ! -f /usr/bin/doxygen ]; then
    echo "doxygen not found"
    exit
fi

if [ ! -f /usr/bin/dot ]; then
	echo "graphviz not found"
    exit
fi

if [ -d doxydoc ]; then
	echo "doxydoc exist and may not empty"
    exit
fi

if [ -z "${1}" ];then
	echo "specify project name"
	exit
fi

#######################

echo "starting build documents"
doxygen -g doxyconf > /dev/null

#######################

sed -i "s#PROJECT_NAME           = \"My Project\"#PROJECT_NAME           = \"$1\"#g" doxyconf
sed -i "s#OUTPUT_DIRECTORY       =#OUTPUT_DIRECTORY       = ./doxydoc#g" doxyconf
sed -i "s#OPTIMIZE_OUTPUT_FOR_C  = NO#OPTIMIZE_OUTPUT_FOR_C  = YES#g" doxyconf
# sed -i "s#INPUT                  =#INPUT                  = ./#g" doxyconf

sed -i "s#EXTRACT_ALL            = NO#EXTRACT_ALL            = YES#g" doxyconf
sed -i "s#EXTRACT_PRIVATE        = NO#EXTRACT_PRIVATE        = YES#g" doxyconf
sed -i "s#EXTRACT_STATIC         = NO#EXTRACT_STATIC         = YES#g" doxyconf

sed -i "s#HAVE_DOT               = NO#HAVE_DOT               = YES#g" doxyconf
sed -i "s#CALL_GRAPH             = NO#CALL_GRAPH             = YES#g" doxyconf
sed -i "s#CALLER_GRAPH           = NO#CALLER_GRAPH           = YES#g" doxyconf

sed -i "s#GENERATE_LATEX         = YES#GENERATE_LATEX         = NO#g" doxyconf

#######################

doxygen doxyconf
ln -sf html/index.html doxydoc/index.html
rm -f doxyconf
rm -f doxyconf.bak

echo "build documents completed"


