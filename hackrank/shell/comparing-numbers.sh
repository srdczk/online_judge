declare x
declare y

read x
read y

if [[ ${x} -eq ${y} ]]
then
    echo 'X is equal to Y'
elif [[ ${x} > ${y} ]]
then
    echo 'X is greater than Y'
else
    echo 'X is less than Y'
fi
