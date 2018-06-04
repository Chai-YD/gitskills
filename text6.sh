#!/bin/bash
string="hello world"
echo ${string:1:4}
echo `expr index '$string' is`
