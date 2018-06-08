#!/bin/bash 
####################################
#测试整型
####################################
#read myint
#test $myint -eq 100
#退出码 
#echo $?

#read myint 
#[ $myint -ne 100 ]

#echo $?
#[ $myint -lt 100 ]
#echo $?
#
#[ $myint -gt 100 ]
#echo $?

#[ $myint -le 100  ]
#echo $?
#[ $myint -ge 100  ]
#echo $?

####################################
#测试字符串
####################################

#read mystring
#为了防止输入空字符串，导致语法错误，给==左右两边各加一个相同字符串
#[ "X$mystring" == "Xhello"  ]
#echo $?
#[ $mystring != "hello"  ]
#echo $?

#[ -z $mystring  ] #是否为空串
#echo $?
#[ -n $mystring  ] #是否为非空串
#echo $?


####################################
#测试文件
####################################

#[ -c /dev/tty ]
#echo $?
#[ -b /dev/sda ]
#echo $?
#[ -d / ]
#echo $?
#[ -f ./6_8.sh ]
#echo $?



