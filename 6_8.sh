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


####################################
#多条件测试
####################################

#逻辑反
#!/bin/bash
#read mystring
#[ ! "X$mystring" == "Xhello" ]
#echo $?

#逻辑与
#!/bin/bash
##-a表示逻辑与
#printf "please enter data1:"
#read data1
#printf "please enter data2:"
#read data2
#[ $data1 -eq $data2 -a $data2 -eq 200 ]
#echo $?

#逻辑或
#!/bin/bash
#printf "please enter data1:"
#read data1
#printf "please enter data2:"
#read data2
#[ $data1 -eq 100 -o $data2 -eq 200 ]
#echo $?

#!/bin/bash
#if/then/elif/else/fi 若干条件判断命令
#if 、then 、elif、else、这几条命令可以实现分支控制（可嵌套使用）
#printf "please enter string:"
#read mystring
#if [ "V$mystring" == "Vhello" ]
#then
#    echo "get hello"
#fi

#如果两条命令在同一行，则使用；将其隔离开
#printf "please enter string:"
#read mystring
#if [ "V$mystring" == "Vhello" ];then
#    echo "get hello"
#fi

#条件嵌套
#printf "please enter random data:"
#read myint
#if [ $myint -lt 100 ];then
#    if [ $myint -eq 50 ];then
#        echo "data is eq 50"
#    elif [ $myint -lt 50 ];then
#        echo "data is lt 50"
#    else
#        echo "data is gt and lt 100 "
#    fi
#else 
#    echo "data is great than 100"
#fi

#if命令的参数组成一条子命令
#printf "please enter file name:"
#read filename
#if grep -Eq '222' "$filename";then #-E:使用扩展正则匹配；-q：使用安静模式匹配
#    echo "yes"
#else
#    echo "no"
#fi

#空代码块
#代码块中如果出现空代码块的时候，会报错
#printf "please enter data:"
#read data
#if [ $data -eq 100 ];then
#else
#    echo "AAAAAAAAAAAa"
#fi

#要解决以上问题，需要引入：
#：是一个特殊的命令，称为空命令，该命令不做任何事情，但是返回值永远为真
#printf "please enter data:"
#read data
#if [ $data -eq 100 ]; then
#    :    #这里也可以使用true/false命令代替
#else
#    echo "AAAAAAAAAAAAAAa"
#fi

#||和&&的使用
#||相当与if then
#&&相当与if not then
#测试1
#printf "please enter data:"
#read data
#[ $data -eq 100 ] && echo "yes"
#[ $data -eq 100 ] && {
#        echo "yes"
#    }

#测试2
#printf "please enter data:"
#read data
#[ $data -eq 100 ] && echo "yes1"
#[ $data -eq 100 ] || {
#        echo "yes2"
#    }

#case/esac case命令类似与C语言中switch/case语句。esac表示语句块的结束
#case $1 in
#    '[Ss]tart'| -s ) #此处的|表述等价
#    echo "start ... done"
#    ;;
#    'stop')
#    echo "stop ... done"
#    ;;
#    'restart')
#    echo "restart ... done"
#    ;;
#    *)  #在这里的*表示默认分支,注意此处的*不带单引号
#    echo "default"
#    ;;   #此处的;; 表示分支结束，相当与c中的break
#esac

######################################
#循环语句
######################################

#shell脚本中的for循环
#for ((i=0;i<=10;++i)) #其中（（））这个结构中，所有的运算和c是一样的
#do
#    echo "hello $i"
#done

#for i  in {1..10}
#do
#    echo "hello $i"
#done


#遍历字符
#for i in {a..z}
#do
#    echo "hello $i"
#done

#for i in {a..e} {1..5}  #注意此处两个区间中间有空格
#do
#    echo "hello $i"
#done

#for i in {a..e}{1..5}  #注意此处两个区间中间没有空格
#do  
#    echo "hello $i"
#done

#while循环
#i=0
#while [ $i -le 5 ]
#do 
#    echo "hello $i"
#    #((++i))
#    let ++i
#done

#until循环
#条件为假时，继续循环；条件为真时，结束循环
#i=0
#until [ $i -ge 5 ]
#do 
#    echo "hello $i"
#    let ++i
#done

#死循环
#for ((;;))
#do
#    echo "hello china"
#done

#while :
#do
#    echo "bit "
#done

#until false
#do
#    echo "world"
#done

############################################
#循环练习
############################################

#求1～100的求和，用shell脚本编写
#i=1
#sum=0
#while [ $i -le 100 ]
#do
#    let sum+=i
#    let i++
#done
#echo $sum

#打出类似1+2+..+100 =5050这种结果
#i=1
#sum=0
#echostr=''
#while [ $i -le 100 ]
#do
#    let sum+=i
#    if [ -z "$echostr" ];then
#        echostr=$i
#    else
#        echostr=$echostr'+'$i
#    fi
#    let i++
#done
#echo $echostr=$sum

#位置参数和特殊变量
#echo "\$0-> $0"
#echo "\$1-> $1"
#echo "\$2-> $2"
#echo "\$#-> $#"
#echo "\$@-> $@"
#echo "\$?-> $?"

#shift位置参数，可以用shift命令左移
#echo "\$0-> $0"
#echo "\$1-> $1"
#echo "\$2-> $2"
#echo "\$#-> $#"
#echo "\$@-> $@"
#echo "\$?-> $?"
#shift 2
#echo "shift 2"
#echo "\$0-> $0"
#echo "\$1-> $1"
#echo "\$2-> $2"
#echo "\$#-> $#"
#echo "\$@-> $@"
#echo "\$?-> $?"

#遍历命令行参数
#方法一
#for i in $@
#do
#    echo $i
#done

#方法二
#while [ $# -ne 0 ]
#do
#    echo $1
#    shift 1
#done
    
###########################################
#函数
###########################################

#function myfun(){
#        echo "i am function"
#    }
#myfun

#函数传参
#function fun(){
#        echo $0
#        echo $1
#        echo $2
#        echo $3
#        echo $#
#        echo $@
#        echo "i am function"
#    }
#
#fun arg1 arg2 arg3  #事实表明，$0并不会作为函数参数

#函数返回值
#函数中可以用return命令返回，如果return后面跟一个数字则表示函数的ExitStatus
#function fun(){
#        echo "exec some code"
#        return 123
#    }
#fun
#echo $?

#echo方式函数的返回值
#function fun(){
#        echo "success"
#    }
#ret=$(fun)
#echo $ret

###################################
#shell脚本中的调试选项
###################################

#-n：读一遍脚本中的命令但是不执行，用来检查脚本中的语法错误
#-v：一边执行脚本，一边将执行过的脚本打印到标准错误输出
#-x：提供跟踪执行信息，将执行的每一条命令和结果依次打印出来

#set -x和set +x分别表示开启和禁用-x参数，这样可以对脚本中的某一段进行跟踪
#for i in {1..10}
#do
#    set -x
#    echo "hello $i"
#    set +x
#done

#数组
#数组中可以存储多个值，bash shell只是支持一维数组（不支持多维数组），
#初始化时不需要定义数组的大小
#arr=(1 2 3 3.14 5 6)
#echo "0: ${arr[0]}"
#echo "1: ${arr[1]}"
#echo "2: ${arr[2]}"
#echo "3: ${arr[3]}"
#echo "4: ${arr[4]}"
#echo "5: ${arr[5]}"

#获取数组中的所有元素
#arr=(1 2 3 3.14 5 6)
#echo ${arr[@]}
#echo ${arr[*]}

#求数组的长度
#arr=(1 2 3 4 5 6)
#echo ${#arr[*]}
#echo ${#arr[@]}

#shell输出重定向
#for i in {1..10}
#do
#    echo "hello bit$i">file
#done

#shell追加重定向
#for i in {1..10}
#do
#    echo "hello bit$i">>file
#done

#输入重定性
#while read line
#do 
#    echo $line
#done< file

#产生一个随机数
#echo $RANDOM #0~32767(2^15)

###########################################
#开始练习
###########################################

#利用shell编写进度条
#i=0
#bar=''
#
#while [ $i -le 100 ]
#do
#    printf "[%d%%][%s]\r" "$i" "$bar"
#    let ++i
#    bar=${bar}'#'
#    sleep 0.1
#done

#传入至少3个数字参数到脚本file，并计算出最大、最小，平均值。
#保留两位小数
# 3 4 5 6 min:3 max:6 avg:4.50
if [$# -lt 3 ];then
    echo "参数太少"
    exit 1
fi
max=$1
min=$1
sum=0
for i in $@
do
    [ $i -gt $max ] && max=$i
    [ $i -lt $min ] && min=$i
    let sum=$sum+$i
done
echo "min = $min"
echo "max = $max"
arg=`echo "ibase=10;scale=2;$sum/$#"|bc`
echo $arg













