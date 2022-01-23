#!/bin/bash

for i in {0..6}; do
    cat image_send.cpp | sed -e "s/chatter/chatter_$i/g" >> image_send$i.cpp
done
