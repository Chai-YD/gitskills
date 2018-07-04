#!/bin/bash

#工具

#1.sort
#sort -u 7_4_m
sort -n 7_4_m
按整数排序
sort 7_4_m | uniq -c | sort -rn | head -1
海量数据出现次数查询
sort file1 file2 | uniq -d 交集
sort file1 file2 | uniq  并集
