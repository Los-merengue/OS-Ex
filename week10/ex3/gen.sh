#!/bin/bash

rm -f ex1.txt && for (( i=0; i<$1; i++ )); do echo $RANDOM >> ex1.txt; done
