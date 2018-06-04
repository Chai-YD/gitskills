#!/bin/bash
readonly mystring="hello"
echo "$mystring"
unset mystring
echo "$mystring"
