#!/bin/bash
#for testing code that can be compiled and ran on an x86 machine

succsess=0
total=0
for i in tests/*.cpp 
do
    total=$((total+1))
    echo "\n"
    if g++ "$i" -I "$PWD/src" -o "$PWD/${i%.cpp}.test"; then
        if  (./"${i%.cpp}.test"); then
            succsess=$((succsess+1))
            echo "test succeeded"
        else
           echo "failed to run (ノಠ益ಠ)ノ彡┻━┻"
        fi
    else
        echo "failed to build (ㆆ _ ㆆ)"
    fi
done
echo "$succsess tests succeeded of $total"
if [ $succsess -eq $total ]; then
    echo '╰(✿´⌣`✿)╯♡'
else
    echo "ཀ ʖ̯ ཀ"
fi