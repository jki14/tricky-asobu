#!/bin/bash

X='X'
Y='Y'
E=''

if [ ! -z "${X:-}" ] && [ ! -z "${Y:-}" ]; then
    echo 'X & Y'
fi

if [ ! -z "${X:-}" ] && [ ! -z "${Z:-}" ]; then
    echo 'X & Z'
fi

if [ ! -z "${Z:-}" ] && [ ! -z "${Y:-}" ]; then
    echo 'Z & Y'
fi

if [ ! -z "${Z:-}" ] && [ ! -z "${A:-}" ]; then
    echo 'Z & A'
fi

if [ ! -z "${E:-e}" ] && [ ! -z "${X:-}" ]; then
    echo 'E & X'
fi
